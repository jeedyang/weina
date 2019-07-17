#include "plcstation.h"
#include <thread>
#include <iostream>
#include <mutex>

USING_NAMESPACE(std);
USING_NAMESPACE(PLC);

PlcStation::PlcStation(QObject *parent)
	: QObject(parent)
	
{
	m_s7Dataitems[0].Area = S7AreaPE;
	m_s7Dataitems[0].WordLen = S7WLBit;
	m_s7Dataitems[0].DBNumber = 0;
	m_s7Dataitems[0].Start = 0;
	m_s7Dataitems[0].Amount = 40;
	m_s7Dataitems[0].pdata = m_plcDataBuffer.buffer_I;

	m_s7Dataitems[1].Area = S7AreaPA;
	m_s7Dataitems[1].WordLen = S7WLBit;
	m_s7Dataitems[1].DBNumber = 0;
	m_s7Dataitems[1].Start = 0;
	m_s7Dataitems[1].Amount = 40;
	m_s7Dataitems[1].pdata = m_plcDataBuffer.buffer_Q;

	m_s7Dataitems[2].Area = S7AreaMK;
	m_s7Dataitems[2].WordLen = S7WLBit;
	m_s7Dataitems[2].DBNumber = 0;
	m_s7Dataitems[2].Start = 0;
	m_s7Dataitems[2].Amount = 40;
	m_s7Dataitems[2].pdata = m_plcDataBuffer.buffer_M;

	m_s7Dataitems[3].Area = S7AreaDB;
	m_s7Dataitems[3].WordLen = S7WLByte;
	m_s7Dataitems[3].DBNumber = 1;
	m_s7Dataitems[3].Start = 0;
	m_s7Dataitems[3].Amount = 40;
	m_s7Dataitems[3].pdata = m_plcDataBuffer.buffer_DB;
}

PlcStation::~PlcStation()
{
	Disconnect();
}

int PlcStation::connect()
{
	return ConnectTo("127.0.0.1",0,0);
}

int PlcStation::disconnect()
{
	return Disconnect();
}

int PlcStation::pollingStart()
{
	std::thread t(PlcStation::threadPolling,this,m_s7Dataitems,&plcData);
	t.detach();
	return 0;
}

int PlcStation::pollingStop()
{
	return 0;
}

void PlcStation::threadPolling(PlcStation* plc,TS7DataItem* items,PlcData* plcdata)
{
	mutex mu;  
	while (true)
	{
		mu.lock();
		int a= plc->ReadMultiVars(&items[3], 1);
		mu.unlock();
		cout << "thread runing! PLC return:" << a << endl;
	}
}