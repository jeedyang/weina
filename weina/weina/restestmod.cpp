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
	QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(on_timeout()));
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
}

void ResTestmod::tsetResMod()
{
	QByteArray temp;
	temp.append(0x2b);
	temp.append(0xff);
	for (int i = 0; i < 24; i++)
	{
		temp.append(0xff);
	}
	temp.append(0x0a);
	m_serialPort->write(temp);
}

void ResTestmod::tsetHotresMod()
{
	QByteArray temp;
	temp.append(0x2b);
	temp.append(0xff);
	for (int i = 0; i < 24; i++)
	{
		temp.append(0xff);
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
		qDebug() << dataBuffer.size();
		for (int i = 0; i < 24; i++)
		{
			qDebug() << hotRes[i];
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