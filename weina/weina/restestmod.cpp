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
		qDebug() << _tr("发现:")  << info.portName();
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
		qDebug() << _tr("检测模块:")<<id<<_tr("串口:")<<m_serialPortName << _tr("打开失败!");
		logClass::add_Data_to_log(_tr("检测模块:") .append(id) .append( _tr("串口:")) .append(m_serialPortName ).append( _tr("打开失败!")));
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

		if (getMin_MaxRes)//获取最大最小电阻,在到时间之后
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
	m_testHotResTimer.start(paramete.testHotresTime*1000);
	qDebug()<< _tr("模块:%1  :").arg(id)<< _tr("检测开始.............................") ;
	qDebug() << _tr("模块:%1  :").arg(id) << _tr("检测加热电阻开始") ;
}


void ResTestmod::on_testHotResTimer_timeout()
{
	
	m_testHotResTimer.stop();
	m_testResTimer.start(paramete.testTime*1000);//检测电阻
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
	qDebug() << _tr("模块:%1  :").arg(id) << _tr("检测加热电阻结束") ;
	qDebug() << _tr("模块:%1  :").arg(id) << _tr("加热开始");
}

void ResTestmod::on_min_maxTestTimer_timeout()
{
	qDebug() << _tr("模块:%1  :").arg(id) << _tr("获取最大最小值开始");
	m_min_maxTestTimer.stop();
	getMin_MaxRes = true;//获取最大最小电阻
}

void ResTestmod::on_testResTimer_timeout()
{
	qDebug() << _tr("模块:%1  :").arg(id) << _tr("检测结束----------------------------------");
	m_testResTimer.stop();
	getMin_MaxRes = false;
	//先全部设置不合格
	for (int i = 0; i < 24; i++)
	{
		result[i] = 0;
	}
	for (int i = 0; i < 24; i++)
	{
		for (int a = 0; a < 29; a++)
		{
			if (paramete.enabled[a]) //参数启用则进行判断
			{
				if (res[i] >= paramete.minResScope[a] & res[i] <= paramete.maxResScope[a])
				{
					result[i] = a + 1; //分档结果为索引+1,0档为不合格.
				}
			}
		}
	}
	//判断最大最小值比值
	for (int i = 0; i < 24; i++)
	{
		maxminOdds[i] = maxRes[i] / minRes[i];
		if (maxminOdds[i] >paramete.max_minOdds)
		{
			result[i] = 0;
		}
	}
	//如果加热继电器没开,直接不合格
	for (int i = 0; i < 24; i++)
	{
		if (m_relayStatus[i]==0x00)
		{
			result[i] = 0;
		}
	}
	//检测结束,关闭所有继电器
	for (int i = 0; i < 24; i++)
	{
		m_relayStatus[i] = 0x00;

	}
	hotMod(m_relayStatus);
	emit(this->testDone(id));
	testResMod();
}

