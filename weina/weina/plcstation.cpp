#include "plcstation.h"
#include <thread>
#include <iostream>
#include <mutex>
#include <QMutex>


using namespace PLC;
using namespace ButterflyS7;

IMPLEMENT_SINGLETON(PlcStation)

PlcStation::PlcStation()
{
	m_plcHandle = CreatePlc();
}

PlcStation::~PlcStation()
{
	disconnect();
}

int PlcStation::connect()
{
	uchar ipdr[4] = {192,168,2,1};
	return ConnectPlc(m_plcHandle, ipdr,0,1);
}

int PlcStation::disconnect()
{
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

void PlcStation::run()
{
	//sleep(3);
	QMutex mu;
	PlcDataBuffer buffer;
	while (threadExitCode == PLC_THREAD_ON)
	{
		int a;
		if (threadExitCode == PLC_THREAD_ON)
			a = ReadBlockAsByte(m_plcHandle,AreaI, 0, 0, buffer.buffer_I.size(), buffer.buffer_I.data());
		if (threadExitCode == PLC_THREAD_ON)
			a = ReadBlockAsByte(m_plcHandle, AreaQ, 0, 0, buffer.buffer_Q.size(), buffer.buffer_Q.data());
		if (threadExitCode == PLC_THREAD_ON)
			a =	ReadBlockAsByte(m_plcHandle, AreaM, 0, 0, buffer.buffer_M.size(), buffer.buffer_M.data());
		if (threadExitCode == PLC_THREAD_ON)
			a = ReadBlockAsByte(m_plcHandle, AreaDB, 1, 0, buffer.buffer_DB.size(), buffer.buffer_DB.data());
		mu.lock();
		if (threadExitCode == PLC_THREAD_ON)
		{
			bytes2float(&buffer.buffer_DB[0],plcData.ServoPam.runSpeed_X);
			bytes2float(&buffer.buffer_DB[4], plcData.ServoPam.jogSpeed_X);
			bytes2float(&buffer.buffer_DB[8], plcData.ServoPam.currentPos_X);
			bytes2float(&buffer.buffer_DB[12], plcData.ServoPam.remainDistance_X);
			bytes2float(&buffer.buffer_DB[16], plcData.ServoPam.locationSet_X);
			bytes2float(&buffer.buffer_DB[20], plcData.ServoPam.runSpeed_Y);
			bytes2float(&buffer.buffer_DB[24], plcData.ServoPam.jogSpeed_Y);
			bytes2float(&buffer.buffer_DB[28], plcData.ServoPam.currentPos_Y);
			bytes2float(&buffer.buffer_DB[32], plcData.ServoPam.remainDistance_Y);
			bytes2float(&buffer.buffer_DB[36], plcData.ServoPam.locationSet_Y);
		}
		if (threadExitCode == PLC_THREAD_ON)
		{
			bytes2boolArry(buffer.buffer_I.data(), buffer.buffer_I.size(), plcData.I);
			bytes2boolArry(buffer.buffer_Q.data(), buffer.buffer_Q.size(), plcData.Q);
			bytes2boolArry(buffer.buffer_M.data(), buffer.buffer_M.size(), plcData.M);
		}

		mu.unlock();
		//cout << "thread runing! PLC return:" << a << endl;
	}
}
