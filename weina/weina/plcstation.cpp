#include "plcstation.h"
#include <thread>
#include <iostream>
#include <mutex>
#include <bitset>


USING_NAMESPACE(std);
USING_NAMESPACE(PLC);
USING_NAMESPACE(ButterflyS7);

PlcStation::PlcStation(QObject *parent)
	: QObject(parent)
	
{
	m_plcHandle = CreatePlc();
}

PlcStation::~PlcStation()
{
	disconnect();
}

int PlcStation::connect()
{
	uchar ipdr[4] = { 127,0,0,1 };
	return ConnectPlc(m_plcHandle, ipdr,0,1);
}

int PlcStation::disconnect()
{
	return DisconnectPlc(m_plcHandle);
}

int PlcStation::writeBool(int area, int dbNum, int byteNum, int bitNum, bool value)
{
	return WriteBool(m_plcHandle,area,dbNum,byteNum,bitNum,value);
}

int PlcStation::writeFloat(int area, int dbNum, int byteNum, float value)
{
	return WriteFloat(m_plcHandle,area,dbNum,byteNum,value);
}

int PlcStation::readBlockAsByte(int area, int dbNum, int byteNum, int length, unsigned char* pucValue)
{
	return 0;
}

int PlcStation::pollingStart()
{
	std::thread t(PlcStation::threadPolling,this,&plcData);
	t.detach();
	return 0;
}

int PlcStation::pollingStop()
{
	return 0;
}

void PlcStation::threadPolling(PlcStation* plc)
{
	mutex mu;  
	PlcDataBuffer buffer;
	buffer.mallocBuffer();
	while (true)
	{
		mu.lock();
		int a = plc->readBlockAsByte(AreaI,1,0,buffer.byteNumI,buffer.buffer_I);
		a = plc->readBlockAsByte(AreaQ, 1, 0, buffer.byteNumQ, buffer.buffer_Q);
		a = plc->readBlockAsByte(AreaM, 1, 0, buffer.byteNumM, buffer.buffer_M);
		a = plc->readBlockAsByte(AreaDB, 1, 0, buffer.byteNumDB, buffer.buffer_DB);



		mu.unlock();
		//cout << "thread runing! PLC return:" << a << endl;
	}
	buffer.freeBuffer();
}

void bytes2float(const uchar in[4], float& out)
{
	memcpy(&out, in, 4);
}

void bytes2int(const uchar in[4], int& out)
{
	memcpy(&out, in, 4);
}

void bytes2short(const uchar in[2], short& out)
{
	memcpy(&out, in, 2);
}

void bytes2boolArry(const uchar in, int byteNum, bool* out)
{
	bitset<8> bits(in);
	for (int i = 0; i < 8; i++)
	{
		out[i] = bits[i];
	}
}

void bytesReversal(uchar* a, const int n)
{
	int i = 0;
	unsigned char temp;
	for (i = 0; i < n / 2; i++) {
		temp = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = temp;
	}
}
