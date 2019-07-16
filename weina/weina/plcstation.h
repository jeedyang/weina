#pragma once

#include <QObject>
#include <QVariant>
#include "snap7/snap7.h"

#define NAMESPACE_START(a) namespace a{
#define NAMESPACE_END }
#define USING_NAMESPACE(b) using namespace b

NAMESPACE_START(PLC)

typedef struct _PlcDataBuffer
{
	bool buffer_I[40];
	bool buffer_Q[40];
	uchar buffer_M[40];
	uchar buffer_DB[40];
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
	int disConnect();
	int pollingStart();
	int pollingStop();
	const TS7Client* getS7Client(){
		return &m_s7client;
	}
private:
	TS7Client m_s7client;
	TS7DataItem m_s7dataItem_I;
	TS7DataItem m_s7dataItem_Q;
	TS7DataItem m_s7dataItem_M;
	TS7DataItem m_s7dataItem_DB;
	PlcDataBuffer m_plcBuffer;

};

static PlcStation* plcStation=nullptr;

static PlcStation* createPlcInstance()
{
	if (plcStation == nullptr)
	{
		plcStation = new PlcStation(nullptr);
	}
	return plcStation;
}

NAMESPACE_END