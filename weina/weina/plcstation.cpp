#include "plcstation.h"

USING_NAMESPACE(PLC);

PlcStation::PlcStation(QObject *parent)
	: QObject(parent)
{
	m_s7dataItem_I.Area = S7AreaPE;
	m_s7dataItem_I.WordLen = S7WLBit;
	m_s7dataItem_I.DBNumber = 0;
	m_s7dataItem_I.Start = 0;
	m_s7dataItem_I.Amount = 40;
	m_s7dataItem_I.pdata = m_plcBuffer.buffer_I;

	m_s7dataItem_I.Area = S7AreaPA;
	m_s7dataItem_I.WordLen = S7WLBit;
	m_s7dataItem_I.DBNumber = 0;
	m_s7dataItem_I.Start = 0;
	m_s7dataItem_I.Amount = 40;
	m_s7dataItem_I.pdata = m_plcBuffer.buffer_I;

	m_s7dataItem_I.Area = S7AreaMK;
	m_s7dataItem_I.WordLen = S7WLBit;
	m_s7dataItem_I.DBNumber = 0;
	m_s7dataItem_I.Start = 0;
	m_s7dataItem_I.Amount = 40;
	m_s7dataItem_I.pdata = m_plcBuffer.buffer_I;

	m_s7dataItem_I.Area = S7AreaDB;
	m_s7dataItem_I.WordLen = S7WLByte;
	m_s7dataItem_I.DBNumber = 1;
	m_s7dataItem_I.Start = 0;
	m_s7dataItem_I.Amount = 40;
	m_s7dataItem_I.pdata = m_plcBuffer.buffer_I;
}

PlcStation::~PlcStation()
{
	disConnect();
}

int PlcStation::connect()
{
	return m_s7client.ConnectTo("127.0.0.1",0,0);
}

int PlcStation::disConnect()
{
	return m_s7client.Disconnect();
}

int PlcStation::pollingStart()
{
	return 0;
}

int PlcStation::pollingStop()
{
	return 0;
}
