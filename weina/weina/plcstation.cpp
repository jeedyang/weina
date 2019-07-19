#include "plcstation.h"
#include <thread>
#include <iostream>
#include <mutex>
#include <QMutex>
#include <QDebug>



using namespace PLC;
using namespace ButterflyS7;

IMPLEMENT_SINGLETON(PlcStation)

PlcStation::PlcStation()
{
	m_plcHandle = CreatePlc();
	plcData.buffer_DB[1] = *(new dbBuffer);
	plcData.Define_float_DB[toEntireAddr(1, 0)] = _tr("X轴运行速度");
	plcData.Define_float_DB[toEntireAddr(1, 4)] = _tr("X轴点动速度");
	plcData.Define_float_DB[toEntireAddr(1, 8)] = _tr("X轴当前位置");
	plcData.Define_float_DB[toEntireAddr(1, 12)] = _tr("X轴剩余距离");
	plcData.Define_float_DB[toEntireAddr(1, 16)] = _tr("X轴位置设置");
	plcData.Define_float_DB[toEntireAddr(1, 20)] = _tr("Y轴运行速度");
	plcData.Define_float_DB[toEntireAddr(1, 24)] = _tr("Y轴点动速度");
	plcData.Define_float_DB[toEntireAddr(1, 28)] = _tr("Y轴当前位置");
	plcData.Define_float_DB[toEntireAddr(1, 32)] = _tr("Y轴剩余距离");
	plcData.Define_float_DB[toEntireAddr(1, 36)] = _tr("Y轴位置设置");

	//plcData.DB_int_Map[entireAddr(10, 0)] = _tr("X轴运行速度");
	//plcData.DB_int_Map[entireAddr(10, 4)] = _tr("X轴点动速度");
	//plcData.DB_int_Map[entireAddr(10, 8)] = _tr("X轴当前位置");
	//plcData.DB_int_Map[entireAddr(10, 12)] = _tr("X轴剩余距离");
	//plcData.DB_int_Map[entireAddr(10, 16)] = _tr("X轴位置设置");
	//plcData.DB_int_Map[entireAddr(10, 20)] = _tr("Y轴运行速度");
	//plcData.DB_int_Map[entireAddr(10, 24)] = _tr("Y轴点动速度");
	//plcData.DB_int_Map[entireAddr(10, 28)] = _tr("Y轴当前位置");
	//plcData.DB_int_Map[entireAddr(10, 32)] = _tr("Y轴剩余距离");
	//plcData.DB_int_Map[entireAddr(10, 36)] = _tr("Y轴位置设置");

}

PlcStation::~PlcStation()
{
	disconnect();
}

int PlcStation::connect()
{
	uchar ipdr[4] = {192,168,2,1};
	int a= ConnectPlc(m_plcHandle, ipdr, 0, 1);
	isconnect = true;
	return a;
}

int PlcStation::disconnect()
{
	isconnect = false;
	if (this->isRunning()|| threadExitCode==PLC_THREAD_ON)
	{
		waitThreadExit();
		int a = DisconnectPlc(m_plcHandle);
	}
	return DisconnectPlc(m_plcHandle);

}

int PlcStation::writeBool(int area, int dbNum, int byteNum, int bitNum, bool value)
{
	if (this->isRunning() || threadExitCode == PLC_THREAD_ON)
	{
		waitThreadExit();
		int a = WriteBool(m_plcHandle, area, dbNum, byteNum, bitNum, value);
		pollingStart();
		return a;
	}
	return  WriteBool(m_plcHandle, area, dbNum, byteNum, bitNum, value);

}

int PlcStation::writeInt(int area, int dbNum, int byteNum, int value)
{
	if (this->isRunning() || threadExitCode == PLC_THREAD_ON)
	{
		waitThreadExit();
		int a = WriteDInt(m_plcHandle, area, dbNum, byteNum, value);
		pollingStart();
		return a;
	}
	return  WriteDInt(m_plcHandle, area, dbNum, byteNum, value);
	
}

int PlcStation::writeFloat(int area, int dbNum, int byteNum, float value)
{
	if (this->isRunning() || threadExitCode == PLC_THREAD_ON)
	{
		waitThreadExit();
		int a = WriteFloat(m_plcHandle, area, dbNum, byteNum, value);
		pollingStart();
		return a;
	}
	return  WriteFloat(m_plcHandle, area, dbNum, byteNum, value);

}

int PlcStation::readBlockAsByte(int area, int dbNum, int byteNum, int length, unsigned char* pucValue)
{
	if (this->isRunning() || threadExitCode == PLC_THREAD_ON)
	{
		waitThreadExit();
		int a = ReadBlockAsByte(m_plcHandle, area, dbNum, byteNum, length, pucValue);
		pollingStart();
		return a;
	}
	return  ReadBlockAsByte(m_plcHandle, area, dbNum, byteNum, length, pucValue);

}

int PlcStation::errorText(int errorCode, char* text, int textLen)
{
	return ErrorText(errorCode,text,textLen);
}

void PlcStation::pollingStart()
{
	threadExitCode = PLC_THREAD_ON;
	this->start();
}

void PlcStation::pollingStop()
{
	threadExitCode = PLC_THREAD_EIXT;
}

void PlcStation::waitThreadExit()
{
	pollingStop();
	this->wait();
}

bool PlcStation::isConnect()
{
	return isconnect;
}

int PlcStation::toEntireAddr(int dbNum, int startNum)
{
	return dbNum*10000+ startNum;
}

void PlcStation::toDBaddr(int in_EntireAddr,int &out_dbNum,int &out_startNum )
{
	out_dbNum = in_EntireAddr / 10000;
	out_startNum = in_EntireAddr % 10000;
}

void PlcStation::run()
{
	//sleep(3);
	QMutex mu;
	PlcDataBuffer buffer;
	while (threadExitCode == PLC_THREAD_ON)
	{
		int a;
		if (threadExitCode == PLC_THREAD_ON)
			a = ReadBlockAsByte(m_plcHandle,AreaI, 0, 0, buffer.I.size(), buffer.I.data());
		if (threadExitCode == PLC_THREAD_ON)
			a = ReadBlockAsByte(m_plcHandle, AreaQ, 0, 0, buffer.Q.size(), buffer.Q.data());
		if (threadExitCode == PLC_THREAD_ON)
			a =	ReadBlockAsByte(m_plcHandle, AreaM, 0, 0, buffer.M.size(), buffer.M.data());
		mu.lock();
		if (threadExitCode == PLC_THREAD_ON)
		{
			auto dbnumList= plcData.buffer_DB.keys();
			for (int i = 0; i < dbnumList.size(); i++)
			{
				a = ReadBlockAsByte(m_plcHandle, AreaDB, dbnumList[i], 0, plcData.buffer_DB[dbnumList[i]].size(), plcData.buffer_DB[dbnumList[i]].data());
				if (a)
				{
					array<char, 120> text;
					errorText(a, text.data(), text.size());
					qDebug() << text.data();
				}
			}
			
		}
			
		if (threadExitCode == PLC_THREAD_ON)
		{
			bytes2boolArry(buffer.I.data(), buffer.I.size(), plcData.I.data());
			bytes2boolArry(buffer.Q.data(), buffer.Q.size(), plcData.Q.data());
			bytes2boolArry(buffer.M.data(), buffer.M.size(), plcData.M.data());
		}

		mu.unlock();
		//cout << "thread runing! PLC return:" << a << endl;
	}
}

QVariant PlcStation::getValue(QString defineName)
{	
	int dbnum;
	int startnum;
	plcMemoryAddr addr = plcData.Define_float_DB.key(defineName, -1);
	if (addr!=-1)
	{
		toDBaddr(addr, dbnum, startnum);
		float val;
		dbBuffer dbbuf = plcData.buffer_DB[dbnum];
		bytes2float(&dbbuf[startnum], val);
		return QVariant(val);
	}
	addr = plcData.Define_int_DB.key(defineName, -1);
	if (addr != -1)
	{
		toDBaddr(addr, dbnum, startnum);
		int val;
		dbBuffer dbbuf = plcData.buffer_DB[dbnum];
		bytes2int(&dbbuf[startnum], val);
		return QVariant(val);
	}
	addr = plcData.Define_short_DB.key(defineName, -1);
	if (addr != -1)
	{
		toDBaddr(addr, dbnum, startnum);
		short val;
		dbBuffer dbbuf = plcData.buffer_DB[dbnum];
		bytes2short(&dbbuf[startnum], val);
		return QVariant(val);
	}
	qErrOut() << _tr("未找到名称为:") << defineName << _tr("的地址.");
	return QVariant();
}

QVariant PlcStation::getValue(plcMemoryAddr plcAddr)
{
	
	int dbnum;
	int startnum;
	toDBaddr(plcAddr, dbnum, startnum);
	if (plcData.Define_float_DB.contains(plcAddr))
	{
		float val;
		dbBuffer dbbuf = plcData.buffer_DB[dbnum];
		bytes2float(&dbbuf[startnum], val);
		return QVariant(val);
	}
	if (plcData.Define_int_DB.contains(plcAddr))
	{
		int val;
		dbBuffer dbbuf = plcData.buffer_DB[dbnum];
		bytes2int(&dbbuf[startnum], val);
		return QVariant(val);
	}
	if (plcData.Define_int_DB.contains(plcAddr))
	{
		short val;
		dbBuffer dbbuf = plcData.buffer_DB[dbnum];
		bytes2short(&dbbuf[startnum], val);
		return QVariant(val);
	}
	qErrOut() << _tr("未找到地址为:") << plcAddr << _tr("的定义.");
	return QVariant();
}

int PlcStation::setValue(QString defineName, QVariant value)
{
	int dbnum;
	int startnum;
	plcMemoryAddr addr=0xffffffff;
	QVariant::Type type;
	addr=this->findPlcAddr(defineName, type, addr);
	if (addr== 0xffffffff)
		return -1;

	switch (type)
	{
	case QVariant::Int:
		return this->writeInt(AreaDB, dbnum, startnum, value.toInt());
		break;
	case QVariant::Double:
		return this->writeFloat(AreaDB, dbnum, startnum, value.toFloat());
		break;
	}
	return -1;
}

int PlcStation::setValue(plcMemoryAddr plcAddr, QVariant value)
{
	int dbnum;
	int startnum;
	QString defineName = "";
	QVariant::Type type;
	defineName = this->findDefineName(plcAddr, type, defineName);
	if (defineName == "")
		return -1;

	switch (type)
	{
	case QVariant::Int:
		return this->writeInt(AreaDB, dbnum, startnum, value.toInt());
		break;
	case QVariant::Double:
		return this->writeFloat(AreaDB, dbnum, startnum, value.toFloat());
		break;
	}
	return -1;
}

QString PlcStation::findDefineName(plcMemoryAddr plcAddr, QVariant::Type& valType, QString& defaultReturn)
{
	if (plcData.Define_float_DB.contains(plcAddr))
	{
		valType = QVariant::Type::Double;
		return plcData.Define_float_DB[plcAddr];
	}
	if (plcData.Define_int_DB.contains(plcAddr))
	{
		valType = QVariant::Type::Int;
		return plcData.Define_float_DB[plcAddr];;
	}
	if (plcData.Define_short_DB.contains(plcAddr))
	{
		valType = QVariant::Type::Int;
		return plcData.Define_float_DB[plcAddr];
	}
	qErrOut() << _tr("未找到地址为:") << plcAddr << _tr("的定义.");
	return defaultReturn;
}
plcMemoryAddr PlcStation::findPlcAddr(QString defineName, QVariant::Type& valType, plcMemoryAddr& defaultReturn)
{
	QList<plcMemoryAddr> ketList = plcData.Define_float_DB.keys(defineName);
	if (ketList.size()>1)
	{
		qErrOut() << _tr("找到多个名称为:") << defineName << _tr("的地址.");
		return defaultReturn;
	}
	else
	{
		valType=QVariant::Type::Double;
		return ketList[0];
	}
	QList<plcMemoryAddr> ketList = plcData.Define_int_DB.keys(defineName);
	if (ketList.size() > 1)
	{
		qErrOut() << _tr("找到多个名称为:") << defineName << _tr("的地址.");
		return defaultReturn;
	}
	else
	{
		valType = QVariant::Type::Int;
		return ketList[0];
	}
	QList<plcMemoryAddr> ketList = plcData.Define_short_DB.keys(defineName);
	if (ketList.size() > 1)
	{
		qErrOut() << _tr("找到多个名称为:") << defineName << _tr("的地址.");
		return defaultReturn;
	}
	else
	{
		valType = QVariant::Type::Int;
		return ketList[0];
	}
	qErrOut() << _tr("未找到名称为:") << defineName << _tr("的地址.");
	return defaultReturn;	
}