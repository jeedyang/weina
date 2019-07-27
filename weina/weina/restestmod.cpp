#include "restestmod.h"
#include <QDebug>
#include <QMutex>
#include <QSerialPortInfo>

//#define _tr(str) QString::fromLocal8Bit(str);

ResTestmod::ResTestmod(QObject *parent)
	: QThread(parent)
{

	//m_serialPortName = _tr("COM5");
	QStringList m_serialPortNameList;

	for each (const QSerialPortInfo & info in QSerialPortInfo::availablePorts())
	{
		m_serialPortNameList << info.portName();
		qDebug() << "serialPortName:" << info.portName();
	}
	m_serialPort->setBaudRate(QSerialPort::Baud115200, QSerialPort::AllDirections);//设置波特率和读写方向
	m_serialPort->setDataBits(QSerialPort::Data8);      //数据位为8位
	m_serialPort->setFlowControl(QSerialPort::NoFlowControl);//无流控制
	m_serialPort->setParity(QSerialPort::NoParity); //无校验位
	m_serialPort->setStopBits(QSerialPort::OneStop); //一位停止位
	//m_serialPort->setReadBufferSize(193);
	connect(this, SIGNAL(readHotResDone()), this, SLOT(on_readHotResDone()));
	connect(this, SIGNAL(readResDone()), this, SLOT(on_readResDone()));
	connect(this, SIGNAL(getRealyStausDone()), this, SLOT(on_getRealyStausDone()));
	connect(&timer, SIGNAL(timeout()), this, SLOT(on_timeout()));
	connect(&m_testHotResTimer, SIGNAL(timeout()), this, SLOT(on_testHotResTimer_timeout()));
	connect(&m_testResTimer, SIGNAL(timeout()), this, SLOT(on_testResTimer_timeout()));
	connect(&m_min_maxTestTimer, SIGNAL(timeout()), this, SLOT(on_min_maxTestTimer_timeout()));
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
		qDebug() << m_serialPortName << "打开失败!";
		return -1;
	}
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
	while (threadRead_en)
	{

		if (m_serialPort->waitForReadyRead(800))
		{
			msleep(50);
			
			dataBuffer = m_serialPort->readAll();
			
			if (dataBuffer[0] =='+' & dataBuffer.size()==98)
			{
				if (mu.tryLock());
				memcpy(res, dataBuffer.data() + 1, 96);
				mu.unlock();
				emit(this->readResDone());
			}
			if (dataBuffer[0] == '!' & dataBuffer.size() == 194)
			{
				if (mu.tryLock());
				memcpy(res, dataBuffer.data() + 1, 96);
				memcpy(hotRes, dataBuffer.data() + 1 + 96, 96);
				mu.unlock();
				emit(this->readHotResDone());
				emit(this->readResDone());
			}
			if (dataBuffer[0] == '-' & dataBuffer.size() == 26)
			{
				if (mu.tryLock());
				memcpy(m_relayStatus, dataBuffer.data() + 1, 24);
				mu.unlock();
				emit(this->getRealyStausDone());
			}
		}

		if (getMin_MaxRes)
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
		for (int i = 0; i < 24; i++)
		{
			//qDebug() << hotRes[i];
		}
		
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
	qDebug() << m_ctrlPanel ->getID()<< _tr("加热按钮") << id << _tr("按下!状态") << checked;
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

	this->testHotresMod();//检测加热电阻
	m_testHotResTimer.start(testHotresTime);
	qDebug()<< _tr("检测开始") << id ;
	qDebug() << _tr("检测加热电阻开始") << id;
}

void ResTestmod::on_testHotResTimer_timeout()
{
	
	m_testHotResTimer.stop();
	m_testResTimer.start(testTime);//检测电阻
	m_min_maxTestTimer.start(min_maxTestTime);
	for (int i = 0; i < 24; i++)
	{
		if (hotRes[i]<minHotRes|| hotRes[i]>maxHotRes)
		{
			m_setRelayStatus[i] = 0;
		}
		else
		{
			m_setRelayStatus[i] = 1;
		}
		
	}
	hotMod(m_setRelayStatus);
	qDebug() << _tr("检测加热电阻结束") << id;
	qDebug() << _tr("加热开始") << id;
}

void ResTestmod::on_min_maxTestTimer_timeout()
{
	qDebug() << _tr("获取最大最小值开始") << id;
	m_min_maxTestTimer.stop();
	getMin_MaxRes = true;//获取最大最小电阻
}

void ResTestmod::on_testResTimer_timeout()
{
	qDebug() << _tr("检测结束") << id;
	m_testResTimer.stop();
	getMin_MaxRes = false;
	for (int i = 0; i < 24; i++)
	{
		for (int a = 0; a < 29; a++)
		{
			if (res[i]>=minResScope[a] & res[i]<=maxResScope[a])
			{
				result[i] = a;
			}
			else
			{
				result[i] = 29;
			}
		}
	}
	emit(this->testDone(id));
	testResMod();
}

