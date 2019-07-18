#pragma once

#include <QObject>
#include <QVariant>
#include "plclib/ButterflyS7.h"
#include <array>
#include <bitset>
#include <QThread>

#define DEFINE_SINGLETON(cls) \
 private:\
 static std::auto_ptr<cls> m_pInstance;\
 protected:\
	cls();\
 public:\
  ~cls();\
  static cls* Instance(){\
  if(!m_pInstance.get()){\
  m_pInstance = std::auto_ptr<cls>(new cls());\
  }\
  return m_pInstance.get();\
 }

#define IMPLEMENT_SINGLETON(cls) \
std::auto_ptr<cls> cls::m_pInstance(NULL);

#define NAMESPACE_START(a) namespace a{
#define NAMESPACE_END }

using namespace std;

NAMESPACE_START(PLC)

#define PLC_THREAD_ON 0x00FF
#define PLC_THREAD_EIXT 0x0000

typedef struct _PlcDataBuffer
{
	std::array<uchar, 5> buffer_I;
	std::array<uchar, 5> buffer_Q;
	std::array<uchar, 5> buffer_M;
	std::array<uchar, 49> buffer_DB;

}PlcDataBuffer;

typedef struct _PlcData
{
	bool I[128];
	bool Q[128];
	bool M[128];
	struct _ServoPam
	{
		float runSpeed_X;			//X轴运行速度
		float jogSpeed_X;			//X轴点动速度
		float currentPos_X;			//X轴当前位置
		float remainDistance_X;		//X轴剩余距离
		float locationSet_X;		//X轴位置设置
		float runSpeed_Y;			//Y轴运行速度
		float jogSpeed_Y;			//Y轴点动速度
		float currentPos_Y;			//Y轴当前位置
		float remainDistance_Y;		//Y轴剩余距离
		float locationSet_Y;		//Y轴位置设置
	}ServoPam;
	struct _PosPam
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
	}PosPam;
	struct _Timers
	{
		int hot_time;
	}Timers;

}PlcData;



class PlcStation : public QThread
{
	Q_OBJECT

	DEFINE_SINGLETON(PlcStation)

public:
	int connect();
	int disconnect();
	int writeBool(int area,int dbNum,int byteNum,int bitNum,bool value);
	int writeFloat(int area, int dbNum, int byteNum, float value);
	int readBlockAsByte(int area,int dbNum,int byteNum,int length,unsigned char* pucValue);	
	int errorText(int errorCode,char* text,int textLen);
	void pollingStart();
	void pollingStop();
	void waitThreadExit();
	PlcData plcData;
private:
	void run();
	int threadExitCode = 0;
	PlcDataBuffer m_plcDataBuffer;
	PlcHandle m_plcHandle;
};


NAMESPACE_END

static void bytesReversal(uchar* a, int n)
{
	int i = 0;
	unsigned char temp;
	for (i = 0; i < n / 2; i++) {
		temp = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = temp;
	}
}

static void bytes2float(uchar in[4], float& out)
{
	bytesReversal(in,4);
	memcpy(&out, in, 4);
}

static void bytes2int(uchar in[4], int& out)
{
	memcpy(&out, in, 4);
}

static void bytes2short(uchar in[2], short& out)
{
	memcpy(&out, in, 2);
}

static void bytes2boolArry(uchar* in, int byteNum, bool* out)
{
	for (int i = 0; i < byteNum; i++)
	{
		bitset<8> bits(in[i]);
		for (int a = 0; a < 8; a++)
		{
			out[i * 8 + a] = bits[a];
		}
	}
}




