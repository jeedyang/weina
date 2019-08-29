#include "restestmod.h"
#include <QDebug>
#include <QMutex>
#include <QSerialPortInfo>
#include "logclass.h"

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
		mu.lock();
		if (m_serialPort->waitForReadyRead(800))
		{
			msleep(50);
			dataBuffer = m_serialPort->readAll();
			
			if (dataBuffer[dataBuffer.size()] == '\n')
			{
				if (dataBuffer[0] == '+' & dataBuffer.size() == 98)
				{
					memcpy(res, dataBuffer.data() + 1, 96);
					emit(this->readResDone());
				}
				if (dataBuffer[0] == '!' & dataBuffer.size() == 194)
				{
					memcpy(res, dataBuffer.data() + 1, 96);
					memcpy(hotRes, dataBuffer.data() + 1 + 96, 96);
					emit(this->readHotResDone());
					emit(this->readResDone());
				}
				if (dataBuffer[0] == '-' & dataBuffer.size() == 26 )
				{
					memcpy(m_relayStatus, dataBuffer.data() + 1, 24);
					emit(this->getRealyStausDone());
				}
			}
		}

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
	for (int i = 0; i < 24; i++)
	{
		if (hotRes[i]<paramete.minHotRes|| hotRes[i]>paramete.maxHotRes)
		{
			m_relayStatus[i] = 0;
		}
		else
		{
			m_relayStatus[i] = 1;
		}
		
	}
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
	//��ȫ�����ò��ϸ�
	for (int i = 0; i < 24; i++)
	{
		result[i] = 0;
	}
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
	//�ж������Сֵ��ֵ
	for (int i = 0; i < 24; i++)
	{
		maxminOdds[i] = maxRes[i] / minRes[i];
		if (maxminOdds[i] >paramete.max_minOdds)
		{
			result[i] = 0;
		}
	}
	//������ȼ̵���û��,ֱ�Ӳ��ϸ�
	for (int i = 0; i < 24; i++)
	{
		if (m_relayStatus[i]==0x00)
		{
			result[i] = 0;
		}
	}
	//������,�ر����м̵���
	for (int i = 0; i < 24; i++)
	{
		m_relayStatus[i] = 0x00;

	}
	hotMod(m_relayStatus);
	emit(this->testDone(id));
	testResMod();
}

