#include "restestmod.h"
#include <QDebug>
#include <QMutex>
#include <QSerialPortInfo>
#include "logclass.h"

#include <array>

//#define _tr(str) QString::fromLocal8Bit(str);

ResTestmod::ResTestmod(QObject *parent)
	: QThread(parent)
{

	//m_serialPortName = _tr("COM5");
	QStringList m_serialPortNameList;

	for each (const QSerialPortInfo & info in QSerialPortInfo::availablePorts())
	{
		m_serialPortNameList << info.portName();
		qDebug() << _tr("����:")  << info.portName();
	}
	m_serialPort->setBaudRate(QSerialPort::Baud115200, QSerialPort::AllDirections);//���ò����ʺͶ�д����
	m_serialPort->setDataBits(QSerialPort::Data8);      //����λΪ8λ
	m_serialPort->setFlowControl(QSerialPort::NoFlowControl);//��������
	m_serialPort->setParity(QSerialPort::NoParity); //��У��λ
	m_serialPort->setStopBits(QSerialPort::OneStop); //һλֹͣλ
	//m_serialPort->setReadBufferSize(193);
	connect(this, SIGNAL(readHotResDone()), this, SLOT(on_readHotResDone()));
	connect(this, SIGNAL(readResDone()), this, SLOT(on_readResDone()));
	connect(this, SIGNAL(getRealyStausDone()), this, SLOT(on_getRealyStausDone()));
	connect(&timer, SIGNAL(timeout()), this, SLOT(on_timeout()));
	connect(&m_testHotResTimer, SIGNAL(timeout()), this, SLOT(on_testHotResTimer_timeout()));
	connect(&m_testResTimer, SIGNAL(timeout()), this, SLOT(on_testResTimer_timeout()));
	connect(&m_min_maxTestTimer, SIGNAL(timeout()), this, SLOT(on_min_maxTestTimer_timeout()));
	for (int i = 0; i < 24; i++)
	{
		m_relayStatus[i] = 0x00;
	}
}

ResTestmod::~ResTestmod()
{
	readStop();
	m_serialPort->close();
}

int ResTestmod::connectMod()
{
	m_serialPort->setPortName(m_serialPortName);
	if (!m_serialPort->open(QIODevice::ReadWrite))
	{
		qDebug() << _tr("���ģ��:")<<id<<_tr("����:")<<m_serialPortName << _tr("��ʧ��!");
		logClass::add_Data_to_log(_tr("���ģ��:") .append(id) .append( _tr("����:")) .append(m_serialPortName ).append( _tr("��ʧ��!")));
		return -1;
	}
	hotMod(m_relayStatus);
	msleep(5);
	testResMod();
	timer.start(5000);
	return 0;
}

void ResTestmod::setPortName(QString portName)
{
	
	m_serialPortName = portName;
}

void ResTestmod::on_readHotResDone()
{
	refreshHotResWidget();
}

void ResTestmod::on_readResDone()
{
	refreshResWidget();
}

void ResTestmod::setHotRelay()
{
}


void ResTestmod::readStart()
{
	threadRead_en = true;
	this->start();
}

void ResTestmod::readStop()
{
	threadRead_en = false;
	this->wait();
}

void ResTestmod::hotMod(uchar* relayStatus)
{
	QByteArray temp;
	temp.append(0x2b);
	temp.append(0xff);
	for (int i = 0; i < 24; i++)
	{
		temp.append(relayStatus[i]);
	}
	temp.append(0x0a);
	m_serialPort->write(temp);
	m_ctrlPanel->setHotButtonState((bool*)relayStatus);
}

void ResTestmod::testResMod()
{
	QByteArray temp;
	temp.append(0x2b);
	temp.append(0xbb);
	for (int i = 0; i < 24; i++)
	{
		temp.append(0xff);
	}
	temp.append(0x0a);
	m_serialPort->write(temp);
}

void ResTestmod::testHotresMod()
{
	QByteArray temp;
	temp.append(0x2b);
	temp.append(0xaa);
	for (int i = 0; i < 24; i++)
	{
		temp.append(' ');
	}
	temp.append(0x0a);
	m_serialPort->write(temp);
}

void ResTestmod::getRealyStaus()
{
	QByteArray temp;
	temp.append(0x2b);
	temp.append('-');
	for (int i = 0; i < 24; i++)
	{
		temp.append(0xff);
	}
	temp.append(0x0a);
	m_serialPort->write(temp);
}

void ResTestmod::setCtrlPanelWidget(CtrlPanelBase* widget)
{
	m_ctrlPanel = widget;
}

void ResTestmod::run()
{
	QMutex mu;
	QByteArray dataBuffer;
	msleep(100);
	while (threadRead_en)
	{
		msleep(5);
		
		if (m_serialPort->waitForReadyRead(800))
		{
			msleep(50);
			mu.lock();
			dataBuffer = m_serialPort->readAll();
			mu.unlock();
			//if (dataBuffer[dataBuffer.size()] == '\n')
			if (1)
			{
				if (dataBuffer[0] == '+' & dataBuffer.size() == 98)
				{
					mu.lock();
					memcpy(res, dataBuffer.data() + 1, 96);
					mu.unlock();
					emit(this->readResDone());
				}
				if (dataBuffer[0] == '!' & dataBuffer.size() == 194)
				{
					mu.lock();
					memcpy(res, dataBuffer.data() + 1, 96);
					memcpy(hotRes, dataBuffer.data() + 1 + 96, 96);
					mu.unlock();
					emit(this->readHotResDone());
					emit(this->readResDone());
				}
				if (dataBuffer[0] == '-' & dataBuffer.size() == 26 )
				{
					mu.lock();
					memcpy(m_relayStatus, dataBuffer.data() + 1, 24);
					mu.unlock();
					emit(this->getRealyStausDone());
				}
			}
		}
		mu.lock();
		if (getMin_MaxRes)//��ȡ�����С����,�ڵ�ʱ��֮��
		{
			for (int i = 0; i < 24; i++)
			{
				if (res[i] < minRes[i])
					minRes[i] = res[i];
				if (res[i] > maxRes[i])
					maxRes[i] = res[i];
			}
		}
		
		//qDebug() << dataBuffer.size();
		//for (int i = 0; i < 24; i++)
		//{
		//	//qDebug() << hotRes[i];
		//}
		mu.unlock();
	}
}

void ResTestmod::refreshHotResWidget()
{
	m_ctrlPanel->setHotRes(hotRes);
}

void ResTestmod::refreshResWidget()
{
	m_ctrlPanel->setRes(res);
}

void ResTestmod::on_HotButtonCilcked(int id, bool checked)
{
	m_relayStatus[id] = checked;
	hotMod(m_relayStatus);
	qDebug() << m_ctrlPanel ->getID()<< _tr("���Ȱ�ť") << id << _tr("����!״̬") << checked;
}

void ResTestmod::on_getRealyStausDone()
{
	m_ctrlPanel->setHotButtonState((bool*)m_relayStatus);
}

void ResTestmod::on_timeout()
{
	getRealyStaus();
}

void ResTestmod::testStart()
{
	getMin_MaxRes = false;
	for (int i = 0; i < 24; i++)
	{
		minRes[i] = 999999999;
		maxRes[i] = 0;
	}

	this->testHotresMod();//�����ȵ���
	m_testHotResTimer.start(paramete.testHotresTime*1000);
	qDebug()<< _tr("ģ��:%1  :").arg(id)<< _tr("��⿪ʼ.............................") ;
	qDebug() << _tr("ģ��:%1  :").arg(id) << _tr("�����ȵ��迪ʼ") ;
}

void ResTestmod::on_testHotResTimer_timeout()
{
	
	m_testHotResTimer.stop();
	m_testResTimer.start(paramete.testTime*1000);//������
	m_min_maxTestTimer.start(paramete.min_maxTestTime*1000);
	std::array<HeaterResult,24> heaterResult;
	m_heater = heaterResult;
	for (int i = 0; i < 24; i++)
	{
		if (hotRes[i] < paramete.minHotRes)
		{
			heaterResult[i]=HeaterResult::Short;
		}
		else if(hotRes[i] > paramete.maxHotRes)
		{
			heaterResult[i] = HeaterResult::Open;
		}
		else
		{
			heaterResult[i] = HeaterResult::Normal;
		}
		if (hotRes[i]<paramete.minHotRes|| hotRes[i]>paramete.maxHotRes)
		{
			m_relayStatus[i] = 0;
		}
		else
		{
			m_relayStatus[i] = 1;
		}
		
	}
	auto analyze = Analyze::Instance();
	analyze->setHotResResult(id,heaterResult);
	hotMod(m_relayStatus);
	qDebug() << _tr("ģ��:%1  :").arg(id) << _tr("�����ȵ������") ;
	qDebug() << _tr("ģ��:%1  :").arg(id) << _tr("���ȿ�ʼ");
}

void ResTestmod::on_min_maxTestTimer_timeout()
{
	qDebug() << _tr("ģ��:%1  :").arg(id) << _tr("��ȡ�����Сֵ��ʼ");
	m_min_maxTestTimer.stop();
	getMin_MaxRes = true;//��ȡ�����С����
}

void ResTestmod::on_testResTimer_timeout()
{
	qDebug() << _tr("ģ��:%1  :").arg(id) << _tr("������----------------------------------");
	m_testResTimer.stop();
	getMin_MaxRes = false;
	qDebug() << _tr("ģ��:%1  :").arg(id) << _tr("step1 done...");
	//��ȫ�����ò��ϸ�
	for (int i = 0; i < 24; i++)
	{
		result[i] = 0;
	}
	qDebug() << _tr("ģ��:%1  :").arg(id) << _tr("step2 done...");
	for (int i = 0; i < 24; i++)
	{
		for (int a = 0; a < 29; a++)
		{
			if (paramete.enabled[a]) //��������������ж�
			{
				if (res[i] >= paramete.minResScope[a] & res[i] <= paramete.maxResScope[a])
				{
					result[i] = a + 1; //�ֵ����Ϊ����+1,0��Ϊ���ϸ�.
				}
			}
		}
	}
	qDebug() << _tr("ģ��:%1  :").arg(id) << _tr("step3 done...");
	//�ж������Сֵ��ֵ
	for (int i = 0; i < 24; i++)
	{


		qDebug() <<_tr("t1:")<<i;
		maxminOdds[i] = 1.0000 * maxRes[i] / minRes[i];
		qDebug() << _tr("t2:") << i;
		if (maxminOdds[i] >paramete.max_minOdds)
		{
			result[i] = 0;
		}

	}
	qDebug() << _tr("ģ��:%1  :").arg(id) << _tr("step4 done...");
	//������ȼ̵���û��,ֱ�Ӳ��ϸ�
	for (int i = 0; i < 24; i++)
	{
		if (m_relayStatus[i]==0x00)
		{
			result[i] = 0;
		}
	}
	qDebug() << _tr("ģ��:%1  :").arg(id) << _tr("step5 done...");
	std::array<int, 24> lastres;
	//������,�ر����м̵���
	for (int i = 0; i < 24; i++)
	{
		m_relayStatus[i] = 0x00;
		lastres[i] = res[i];
	}
	
	std::array<int,24> testResult;
	
	for (int i = 0; i < 24; i++)
	{
		testResult[i]=result[i];
	}

	for (int i = 0; i < 24; i++)
	{
		//չʾ���û�������
		m_min[i] = 1.0000 * minRes[i] / 1000;
		m_max[i] = 1.0000 * maxRes[i] / 1000;
		m_odds[i] = maxminOdds[i];
		m_lastRes[i] = 1.0000 * lastres[i] / 1000;
		m_classes = testResult;
	}
	auto analyze = Analyze::Instance();
	analyze->setTestResult(id, testResult);


	qDebug() << _tr("ģ��:%1  :").arg(id) << _tr("step6 done...");
	hotMod(m_relayStatus);
	qDebug() << _tr("ģ��:%1  :").arg(id) << _tr("step7 done...");
	emit(this->testDone(id));
	testResMod();
	qDebug() << _tr("ģ��:%1  :").arg(id) << _tr("stepDone...");
}

