#pragma once

#include <QObject>
#include <QVariant>
#include "plclib/ButterflyS7.h"

#define NAMESPACE_START(a) namespace a{
#define NAMESPACE_END }
#define USING_NAMESPACE(b) using namespace b


NAMESPACE_START(PLC)



typedef struct _PlcDataBuffer
{
	const int byteNumI=5;
	const int byteNumQ=5;
	const int byteNumM=5;
	const int byteNumDB=40;
	uchar* buffer_I;
	uchar* buffer_Q;
	uchar* buffer_M;
	uchar* buffer_DB;

	void mallocBuffer()
	{
		buffer_I = (uchar*)malloc(byteNumI);
		buffer_Q = (uchar*)malloc(byteNumQ);
		buffer_M = (uchar*)malloc(byteNumM);
		buffer_DB = (uchar*)malloc(byteNumDB);
	}
	void freeBuffer()
	{
		free(buffer_I);
		free(buffer_Q);
		free(buffer_M);
		free(buffer_DB);
	}
}PlcDataBuffer;

typedef struct _PlcData
{
	bool I[4][8];
	bool Q[4][8];
	bool M[40];
	struct LocationPam
	{
		float nozzle_x;
		float nozzle_y;
		float tray1_x;
		float tray1_y;
		float tray2_x;
		float tray2_y;
		float tray3_x;
		float tray3_y;
		float tray4_x;
		float tray4_y;
		float nozzle_space;
		float tray_space;
	};
	struct Timers
	{
		int hot_time;
	};
}PlcData;

class PlcStation : public QObject
{
	Q_OBJECT

public:
	PlcStation(QObject *parent);
	~PlcStation();
	int connect();
	int disconnect();
	int writeBool(int area,int dbNum,int byteNum,int bitNum,bool value);
	int writeFloat(int area, int dbNum, int byteNum, float value);
	int readBlockAsByte(int area,int dbNum,int byteNum,int length,unsigned char* pucValue);	

	int pollingStart();
	int pollingStop();
	PlcData plcData;
private:
	static void threadPolling(PlcStation *plc);
	PlcDataBuffer m_plcDataBuffer;
	PlcHandle m_plcHandle;
};

static PlcStation* plcStation=nullptr;

static void bytes2float(const uchar in[4], float& out);
static void bytes2int(const uchar in[4], int& out);
static void bytes2short(const uchar in[2], short& out);
static void bytes2boolArry(const uchar in, int byteNum, const bool* out);
static void bytesReversal(uchar* a, const int n);

static PlcStation* getPlcInstance()
{
	if (plcStation == nullptr)
	{
		plcStation = new PlcStation(nullptr);
	}
	return plcStation;
}

NAMESPACE_END