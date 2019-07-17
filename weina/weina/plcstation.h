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
	bool buffer_M[40];
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

class PlcStation : public QObject ,public TS7Client
{
	Q_OBJECT

public:
	PlcStation(QObject *parent);
	~PlcStation();
	int connect();
	int disconnect();
	int pollingStart();
	int pollingStop();
private:
	static void threadPolling(PlcStation *plc,TS7DataItem* items, PlcData* plcdata);
	PlcDataBuffer m_plcDataBuffer;
	TS7DataItem m_s7Dataitems[4];
};
static PlcData plcData;

static PlcStation* plcStation=nullptr;

static PlcStation* getPlcInstance()
{
	if (plcStation == nullptr)
	{
		plcStation = new PlcStation(nullptr);
	}
	return plcStation;
}

NAMESPACE_END