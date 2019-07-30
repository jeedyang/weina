#include "mainctrl.h"
#include <QDebug>
#include <array>

IMPLEMENT_SINGLETON(MainCtrl)

#define notRelay			0			//δ����
#define waitArrange			1			//���Ű�
#define arrangeing			11			//���Ű�
#define waitTest			2			//�����
#define testing				22			//�����
#define testend				222			//�����
#define waitClassify		3			//������
#define classifying			33			//������
#define motioning			4			//��������������

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
	//1�Ű�12,2�Ű�22,3�Ű�32,4�Ű�42
	plc->setValue(_tr("����ָ��"), (num + 1) * 10 + 2);
}

void MainCtrl::arrangeStart(int num)
{
	auto plc = PLC::PlcStation::Instance();
	//1�Ű�11,2�Ű�21,3�Ű�31,4�Ű�41
	plc->setValue(_tr("����ָ��"),(num+1)*10+1);
}

void MainCtrl::testStart(int id)
{
	auto plc = PLC::PlcStation::Instance();
	if (id == 0)
	{
		plc->setValue(_tr("1�Ű�״̬"), testing);
	}
	if (id == 1)
	{
		plc->setValue(_tr("2�Ű�״̬"), testing);
	}
	if (id == 2)
	{
		plc->setValue(_tr("3�Ű�״̬"), testing);
	}
	if (id == 3)
	{
		plc->setValue(_tr("4�Ű�״̬"), testing);
	}
	m_testMods[id]->testStart();
	m_testStatus[id] = true;
}




void MainCtrl::on_testDone(int id)
{
	m_testStatus[id] = false;
	qDebug() << _tr("������,���:") << id;
	for (int i = 0; i < 24; i++)
	{
		//qDebug() << _tr("����� # %1:").arg(i) << m_testMods[id]->result[i]<<_tr("��Сֵ :")<< m_testMods[id]->minRes[i] << _tr("���ֵ :") << m_testMods[id]->maxRes[i];

	}
	auto plc = PLC::PlcStation::Instance();
	boardStatus[id] = waitClassify;
	if (id==0)
	{
		plc->setValue(_tr("1�Ű�״̬"), testend);
		for (int i = 0; i < 24; i++)
		{
			plc->writeInt(AreaDB,21,i*4, m_testMods[id]->result[i]);
		}
		
		//m_testMods[id]->result;
	}
	if (id == 1)
	{
		plc->setValue(_tr("2�Ű�״̬"), testend);
		for (int i = 0; i < 24; i++)
		{
			plc->writeInt(AreaDB, 22, i * 4, m_testMods[id]->result[i]);
		}

	}
	if (id == 2)
	{
		plc->setValue(_tr("3�Ű�״̬"), testend);
		for (int i = 0; i < 24; i++)
		{
			plc->writeInt(AreaDB, 23, i * 4, m_testMods[id]->result[i]);
		}

	}
	if (id == 3)
	{
		plc->setValue(_tr("4�Ű�״̬"), testend);
		for (int i = 0; i < 24; i++)
		{
			plc->writeInt(AreaDB, 24, i * 4, m_testMods[id]->result[i]);
		}

	}
	
}


void MainCtrl::on_logicTimeOut()
{
	auto plc = PLC::PlcStation::Instance();
	int machineStatus = plc->getValue(_tr("����_ֹͣ")).toInt();
	int motionStatus=plc->getValue(_tr("��������״̬")).toInt();
	if (machineStatus==0)
	{
		stop();
		return;
	}
	int boardStatus_1 = plc->getValue(_tr("1�Ű�״̬")).toInt();
	int boardStatus_2 = plc->getValue(_tr("2�Ű�״̬")).toInt();
	int boardStatus_3 = plc->getValue(_tr("3�Ű�״̬")).toInt();
	int boardStatus_4 = plc->getValue(_tr("4�Ű�״̬")).toInt();
	array<int, 4> boardStatusPlc = { boardStatus_1, boardStatus_2, boardStatus_3, boardStatus_4 };

	if (boardStatusPlc[0] == notRelay || boardStatusPlc[1] == notRelay || boardStatusPlc[2] == notRelay || boardStatusPlc[3] == notRelay)
	{
		qDebug() << _tr("�豸δ����!");
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
				qDebug() << _tr("%1�Ű��⿪ʼ!").arg(i);
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
				qDebug() << _tr("%1�Ű��Ű忪ʼ!").arg(i);
				return;
		}

	}

	for (int i = 0; i < 4; i++)
	{
		if (boardStatusPlc[i] == waitClassify & m_classifyNum==i)
		{
			classifyStart(i);
			qDebug() << _tr("%1�Ű���Ͽ�ʼ!").arg(i);
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
