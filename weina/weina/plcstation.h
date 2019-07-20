#pragma once

#include <QObject>
#include <QVariant>
#include "plclib/ButterflyS7.h"
#include <array>
#include <bitset>
#include <QThread>

#define _tr(str) QString::fromLocal8Bit(str)
#define qErrOut() qDebug()<<_tr("����һ������:���ļ�:\n")<<__FILE__<<_tr("\n����:")<<__FUNCTION__<<_tr("\n��:")<<__LINE__<<"\n"

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

typedef  int plcMemoryAddr;
typedef  std::array<uchar, 40> dbBuffer;

typedef struct _PlcData
{
	std::array<bool, 40> I;
	std::array<bool, 40> Q;
	std::array<bool, 160> M;

	QMap<plcMemoryAddr, QString> Define_float_DB;
	QMap<plcMemoryAddr, QString> Define_int_DB;
	QMap<plcMemoryAddr, QString> Define_short_DB;



	QMap<int, dbBuffer> buffer_DB;

}PlcData;

NAMESPACE_START(PLC)

#define PLC_THREAD_ON 0x00FF
#define PLC_THREAD_EIXT 0x0000

typedef struct _PlcDataBuffer
{
	std::array<uchar, 5> I;
	std::array<uchar, 5> Q;
	std::array<uchar, 20> M;

}PlcDataBuffer;


class PlcStation : public QThread
{
	Q_OBJECT

	DEFINE_SINGLETON(PlcStation)

public:
	int connect();
	int disconnect();
	int writeBool(int area,int dbNum,int byteNum,int bitNum,bool value);
	int writeInt(int area, int dbNum, int byteNum, int value);
	int writeFloat(int area, int dbNum, int byteNum, float value);
	int readBlockAsByte(int area,int dbNum,int byteNum,int length,unsigned char* pucValue);	
	int errorText(int errorCode,char* text,int textLen);
	//��ʼ��ѯ
	void pollingStart();
	//ֹͣ��ѯ
	void pollingStop();
	//�ȴ��߳��˳�
	void waitThreadExit();
	//����״̬
	bool isConnect();
	//DB�ϳɵ�����ַ
	int toEntireAddr(int dbNum,int startNum );
	//������ַת��DB�ż���ʼ��ַ
	void toDbAddr(int in_EntireAddr, int &out_dbNum, int & out_startNum);
	//��ȡdbֵ
	QVariant getValue(QString defineName);
	QVariant getValue(plcMemoryAddr plcAddr);
	//����dbֵ
	int setValue(QString defineName, QVariant value);
	int setValue(plcMemoryAddr plcAddr, QVariant value);
	//ͨ����ַ��ȡ��������
	QString findDefineName(plcMemoryAddr plcAddr,QVariant::Type &valType, QString&defaultReturn);
	//ͨ��������ַ
	plcMemoryAddr findPlcAddr(QString defineName, QVariant::Type &valType, plcMemoryAddr& defaultReturn);
	PlcData plcData;
private:
	bool isconnect=false;
	void run();
	int threadExitCode = 0;
	PlcDataBuffer m_plcDataBuffer;
	PlcHandle m_plcHandle;
};


NAMESPACE_END

static void bytesReversal(uchar* a, int n);
static void bytes2float(uchar in[4], float& out);
static void bytes2int(uchar in[4], int& out);
static void bytes2short(uchar in[2], short& out);
static void bytes2boolArry(uchar* in, int byteNum, bool* out);

