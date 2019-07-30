#include "mainctrl.h"
#include <QDebug>
#include <array>

IMPLEMENT_SINGLETON(MainCtrl)

#define notRelay			0			//Î´¾ÍÐ÷
#define waitArrange			1			//´ýÅÅ°å
#define arrangeing			11			//´ýÅÅ°å
#define waitTest			2			//´ý¼ì²â
#define testing				22			//´ý¼ì²â
#define testend				222			//´ý¼ì²â
#define waitClassify		3			//´ý·ÖÁÏ
#define classifying			33			//´ý·ÖÁÏ
#define motioning			4			//ÓÐÆäËû¶¯×÷½øÐÐ

MainCtrl::MainCtrl()
{
	connect(&m_logicTimer, SIGNAL(timeout()), this, SLOT(on_logicTimeOut()));
	
}

MainCtrl::~MainCtrl()
{
}

void MainCtrl::setModules(ResTestmod** mods)
{
	for (int i = 0; i < 4; i++)
	{
		m_testMods.append(mods[i]);
	}
}

ResTestmod* MainCtrl::getModules(int id)
{
	return m_testMods[id];
}

void MainCtrl::start()
{
	m_logicTimer.start(1000);
}

void MainCtrl::stop()
{
	m_logicTimer.stop();
}

void MainCtrl::classifyStart(int num)
{
	auto plc = PLC::PlcStation::Instance();
	//1ºÅ°å12,2ºÅ°å22,3ºÅ°å32,4ºÅ°å42
	plc->setValue(_tr("¿ØÖÆÖ¸Áî"), (num + 1) * 10 + 2);
}

void MainCtrl::arrangeStart(int num)
{
	auto plc = PLC::PlcStation::Instance();
	//1ºÅ°å11,2ºÅ°å21,3ºÅ°å31,4ºÅ°å41
	plc->setValue(_tr("¿ØÖÆÖ¸Áî"),(num+1)*10+1);
}

void MainCtrl::testStart(int id)
{
	auto plc = PLC::PlcStation::Instance();
	if (id == 0)
	{
		plc->setValue(_tr("1ºÅ°å×´Ì¬"), testing);
	}
	if (id == 1)
	{
		plc->setValue(_tr("2ºÅ°å×´Ì¬"), testing);
	}
	if (id == 2)
	{
		plc->setValue(_tr("3ºÅ°å×´Ì¬"), testing);
	}
	if (id == 3)
	{
		plc->setValue(_tr("4ºÅ°å×´Ì¬"), testing);
	}
	m_testMods[id]->testStart();
	m_testStatus[id] = true;
}




void MainCtrl::on_testDone(int id)
{
	m_testStatus[id] = false;
	qDebug() << _tr("¼ì²â½áÊø,°åºÅ:") << id;
	for (int i = 0; i < 24; i++)
	{
		//qDebug() << _tr("¼ì²â½á¹û # %1:").arg(i) << m_testMods[id]->result[i]<<_tr("×îÐ¡Öµ :")<< m_testMods[id]->minRes[i] << _tr("×î´óÖµ :") << m_testMods[id]->maxRes[i];

	}
	auto plc = PLC::PlcStation::Instance();
	boardStatus[id] = waitClassify;
	if (id==0)
	{
		plc->setValue(_tr("1ºÅ°å×´Ì¬"), testend);
		for (int i = 0; i < 24; i++)
		{
			plc->writeInt(AreaDB,21,i*4, m_testMods[id]->result[i]);
		}
		
		//m_testMods[id]->result;
	}
	if (id == 1)
	{
		plc->setValue(_tr("2ºÅ°å×´Ì¬"), testend);
		for (int i = 0; i < 24; i++)
		{
			plc->writeInt(AreaDB, 22, i * 4, m_testMods[id]->result[i]);
		}

	}
	if (id == 2)
	{
		plc->setValue(_tr("3ºÅ°å×´Ì¬"), testend);
		for (int i = 0; i < 24; i++)
		{
			plc->writeInt(AreaDB, 23, i * 4, m_testMods[id]->result[i]);
		}

	}
	if (id == 3)
	{
		plc->setValue(_tr("4ºÅ°å×´Ì¬"), testend);
		for (int i = 0; i < 24; i++)
		{
			plc->writeInt(AreaDB, 24, i * 4, m_testMods[id]->result[i]);
		}

	}
	
}


void MainCtrl::on_logicTimeOut()
{
	auto plc = PLC::PlcStation::Instance();
	int machineStatus = plc->getValue(_tr("Æô¶¯_Í£Ö¹")).toInt();
	int motionStatus=plc->getValue(_tr("¶¯×÷½øÐÐ×´Ì¬")).toInt();
	if (machineStatus==0)
	{
		stop();
		return;
	}
	int boardStatus_1 = plc->getValue(_tr("1ºÅ°å×´Ì¬")).toInt();
	int boardStatus_2 = plc->getValue(_tr("2ºÅ°å×´Ì¬")).toInt();
	int boardStatus_3 = plc->getValue(_tr("3ºÅ°å×´Ì¬")).toInt();
	int boardStatus_4 = plc->getValue(_tr("4ºÅ°å×´Ì¬")).toInt();
	array<int, 4> boardStatusPlc = { boardStatus_1, boardStatus_2, boardStatus_3, boardStatus_4 };

	if (boardStatusPlc[0] == notRelay || boardStatusPlc[1] == notRelay || boardStatusPlc[2] == notRelay || boardStatusPlc[3] == notRelay)
	{
		qDebug() << _tr("Éè±¸Î´¾ÍÐ÷!");
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (boardStatusPlc[i] == waitTest)
		{
			if (!m_testStatus[i])
			{
				m_testStatus[i] = true;
				testStart(i);
				qDebug() << _tr("%1ºÅ°å¼ì²â¿ªÊ¼!").arg(i);
			}
		}
	}
	if (motionStatus == motioning)
	{
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (boardStatusPlc[i] == waitArrange)
		{
				arrangeStart(i);
				qDebug() << _tr("%1ºÅ°åÅÅ°å¿ªÊ¼!").arg(i);
				return;
		}

	}

	for (int i = 0; i < 4; i++)
	{
		if (boardStatusPlc[i] == waitClassify & m_classifyNum==i)
		{
			classifyStart(i);
			qDebug() << _tr("%1ºÅ°å·ÖÁÏ¿ªÊ¼!").arg(i);
			m_testStatus[i] = false;
			m_classifyNum++;
			if (m_classifyNum>=4)
			{
				m_classifyNum = 0;
			}
			return;
		}
	}

}
