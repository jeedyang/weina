#include "plcstation.h"
#include <thread>
#include <iostream>
#include <mutex>
#include <QMutex>
#include <QDebug>
#include <QMessageBox>
#include "logclass.h"

using namespace PLC;
using namespace ButterflyS7;

IMPLEMENT_SINGLETON(PlcStation)

PlcStation::PlcStation()
{
	m_plcHandle = CreatePlc();
	plcData.buffer_DB[13] = *(new dbBuffer);
	plcData.buffer_DB[14] = *(new dbBuffer);
	plcData.buffer_DB[26] = *(new dbBuffer);
	plcData.buffer_DB[33] = *(new dbBuffer);
	plcData.Define_float_DB[toEntireAddr(13, 0)] = _tr("X�������ٶ�");
	plcData.Define_float_DB[toEntireAddr(13, 4)] = _tr("X��㶯�ٶ�");
	plcData.Define_float_DB[toEntireAddr(13, 8)] = _tr("X�ᵱǰλ��");
	plcData.Define_float_DB[toEntireAddr(13, 12)] = _tr("X��ʣ�����");
	plcData.Define_float_DB[toEntireAddr(13, 16)] = _tr("X��λ������");
	plcData.Define_float_DB[toEntireAddr(13, 20)] = _tr("Y�������ٶ�");
	plcData.Define_float_DB[toEntireAddr(13, 24)] = _tr("Y��㶯�ٶ�");
	plcData.Define_float_DB[toEntireAddr(13, 28)] = _tr("Y�ᵱǰλ��");
	plcData.Define_float_DB[toEntireAddr(13, 32)] = _tr("Y��ʣ�����");
	plcData.Define_float_DB[toEntireAddr(13, 36)] = _tr("Y��λ������");

	plcData.Define_int_DB[toEntireAddr(13, 40)] = _tr("X��ErrorID");
	plcData.Define_int_DB[toEntireAddr(13, 44)] = _tr("X��ErrorInfo");
	plcData.Define_int_DB[toEntireAddr(13, 48)] = _tr("Y��ErrorID");
	plcData.Define_int_DB[toEntireAddr(13, 52)] = _tr("Y��ErrorInfo");

	plcData.Define_float_DB[toEntireAddr(14, 0)] = _tr("1�������ϲ�1����X");
	plcData.Define_float_DB[toEntireAddr(14, 4)] = _tr("1�������ϲ�1����Y");
	plcData.Define_float_DB[toEntireAddr(14, 8)] = _tr("1�Ű��һ��λ��X");
	plcData.Define_float_DB[toEntireAddr(14, 12)] = _tr("1�Ű��һ��λ��Y");
	plcData.Define_float_DB[toEntireAddr(14, 16)] = _tr("2�Ű��һ��λ��X");
	plcData.Define_float_DB[toEntireAddr(14, 20)] = _tr("2�Ű��һ��λ��Y");
	plcData.Define_float_DB[toEntireAddr(14, 24)] = _tr("3�Ű��һ��λ��X");
	plcData.Define_float_DB[toEntireAddr(14, 28)] = _tr("3�Ű��һ��λ��Y");
	plcData.Define_float_DB[toEntireAddr(14, 32)] = _tr("4�Ű��һ��λ��X");
	plcData.Define_float_DB[toEntireAddr(14, 36)] = _tr("4�Ű��һ��λ��Y");
	plcData.Define_float_DB[toEntireAddr(14, 40)] = _tr("�������׼��");
	plcData.Define_float_DB[toEntireAddr(14, 44)] = _tr("�ϰ��ݼ��");
	plcData.Define_float_DB[toEntireAddr(14, 48)] = _tr("1�������Ϻ�1λ��X");
	plcData.Define_float_DB[toEntireAddr(14, 52)] = _tr("1�������Ϻ�1λ��Y");

	plcData.Define_int_DB[toEntireAddr(26, 0)] = _tr("����_ֹͣ");
	plcData.Define_int_DB[toEntireAddr(26, 4)] = _tr("��ͣ_����");
	plcData.Define_int_DB[toEntireAddr(26, 8)] = _tr("����ָ��");
	plcData.Define_int_DB[toEntireAddr(26, 12)] = _tr("1�Ű�״̬");
	plcData.Define_int_DB[toEntireAddr(26, 16)] = _tr("2�Ű�״̬");
	plcData.Define_int_DB[toEntireAddr(26, 20)] = _tr("3�Ű�״̬");
	plcData.Define_int_DB[toEntireAddr(26, 24)] = _tr("4�Ű�״̬");
	plcData.Define_int_DB[toEntireAddr(26, 28)] = _tr("��������״̬");
	plcData.Define_int_DB[toEntireAddr(26, 32)] = _tr("������Ϣ");

	plcData.Define_int_DB[toEntireAddr(33, 0)] = _tr("������ⴵ���ӳ�");
}

PlcStation::~PlcStation()
{
	disconnect();
}

int PlcStation::connect()
{
	uchar ipdr[4] = {192,168,2,1};
	//uchar ipdr[4] = { 127,0,0,1 };
	int a= ConnectPlc(m_plcHandle, ipdr, 0, 0);
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

int PlcStation::writeBlockAsByte(int area, int dbNum, int byteNum, int length, unsigned char* pucValue)
{
	if (this->isRunning() || threadExitCode == PLC_THREAD_ON)
	{
		waitThreadExit();
		int a = ReadBlockAsByte(m_plcHandle, area, dbNum, byteNum, length, pucValue);
		pollingStart();
		return a;
	}
	return  WriteBlockAsByte(m_plcHandle, area, dbNum, byteNum, length, pucValue);
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

void PlcStation::toDbAddr(int in_EntireAddr,int &out_dbNum,int &out_startNum )
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
		
		try
		{
			int a;
			if (threadExitCode == PLC_THREAD_ON)
				a = ReadBlockAsByte(m_plcHandle, AreaI, 0, 0, buffer.I.size(), buffer.I.data());
			if (a)
				throw a;
			if (threadExitCode == PLC_THREAD_ON)
				a = ReadBlockAsByte(m_plcHandle, AreaQ, 0, 0, buffer.Q.size(), buffer.Q.data());
			if (a)
				throw a;
			if (threadExitCode == PLC_THREAD_ON)
				a = ReadBlockAsByte(m_plcHandle, AreaM, 0, 0, buffer.M.size(), buffer.M.data());
			if (a)
				throw a;
			mu.lock();
			if (threadExitCode == PLC_THREAD_ON)
			{
				auto dbnumList = plcData.buffer_DB.keys();
				for (int i = 0; i < dbnumList.size(); i++)
				{
					a = ReadBlockAsByte(m_plcHandle, AreaDB, dbnumList[i], 0, plcData.buffer_DB[dbnumList[i]].size(), plcData.buffer_DB[dbnumList[i]].data());
					if (a)
						throw a;
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
		}
		//catch (const std::exception&)
		//{

		//}
		catch (const int e)
		{
			array<char, 120> text;
			errorText(e, text.data(), text.size());
			QMessageBox::warning(NULL,_tr("����!"),_tr("PLCͨѶ�߳��쳣!����:").append(e).append(_tr("����:").append(text.data())));
			logClass::add_Data_to_log(_tr("PLCͨѶ�߳��쳣!����:").append(e).append(_tr("����:").append(text.data())));
			mu.unlock();
		}

		mu.unlock();
		//cout << "thread runing! PLC return:" << a << endl;
	}
}

QVariant PlcStation::getValue(QString defineName)
{	
	int dbnum;
	int startnum;
	plcMemoryAddr addr = 0xffffffff;
	QVariant::Type type;
	addr = this->findPlcAddr(defineName, type, addr);
	if (addr == 0xffffffff)
		return -1;
	toDbAddr(addr, dbnum, startnum);

	if (type==QVariant::Int)
	{
		int val;
		dbBuffer dbbuf = plcData.buffer_DB[dbnum];
		bytes2int(&dbbuf[startnum], val);
		return QVariant(val);
	}
	else if(type == QVariant::Double)
	{
		float val;
		dbBuffer dbbuf = plcData.buffer_DB[dbnum];
		bytes2float(&dbbuf[startnum], val);
		return QVariant(val);
	}
	qErrOut() << defineName << _tr("��δ֪������:");
	return QVariant();
}

QVariant PlcStation::getValue(plcMemoryAddr plcAddr)
{
	int dbnum;
	int startnum;
	toDbAddr(plcAddr, dbnum, startnum);
	QString defineName = _tr("δ�ҵ��õ�ַ�ķ���");
	QVariant::Type type;
	defineName = this->findDefineName(plcAddr, type, defineName);
	if (defineName == _tr("δ�ҵ��õ�ַ�ķ���"))
		return -1;

	if (type == QVariant::Int)
	{
		int val;
		dbBuffer dbbuf = plcData.buffer_DB[dbnum];
		bytes2int(&dbbuf[startnum], val);
		return QVariant(val);
	}
	else if (type == QVariant::Double)
	{
		float val;
		dbBuffer dbbuf = plcData.buffer_DB[dbnum];
		bytes2float(&dbbuf[startnum], val);
		return QVariant(val);
	}
	qErrOut() << _tr("δ�ҵ���ַΪ:") << plcAddr << _tr("�ķ���.");
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
	toDbAddr(addr,dbnum,startnum);
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
	QString defineName = _tr("δ�ҵ��õ�ַ�ķ���");
	QVariant::Type type;
	defineName = this->findDefineName(plcAddr, type, defineName);
	if (defineName == _tr("δ�ҵ��õ�ַ�ķ���"))
		return -1;
	toDbAddr(plcAddr, dbnum, startnum);
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
		return plcData.Define_int_DB[plcAddr];;
	}
	if (plcData.Define_short_DB.contains(plcAddr))
	{
		valType = QVariant::Type::Int;
		return plcData.Define_int_DB[plcAddr];
	}
	qErrOut() << _tr("δ�ҵ���ַΪ:") << plcAddr << _tr("�Ķ���.");
	return defaultReturn;
}

plcMemoryAddr PlcStation::findPlcAddr(QString defineName, QVariant::Type& valType, plcMemoryAddr& defaultReturn)
{
	QList<plcMemoryAddr> ketList = plcData.Define_float_DB.keys(defineName);
	if (ketList.size()>1)
	{
		qErrOut() << _tr("�ҵ��������Ϊ:") << defineName << _tr("�ĵ�ַ.");
		return defaultReturn;
	}
	else if (ketList.size() == 1)
	{
		valType=QVariant::Type::Double;
		return ketList[0];
	}
	ketList = plcData.Define_int_DB.keys(defineName);
	if (ketList.size() > 1)
	{
		qErrOut() << _tr("�ҵ��������Ϊ:") << defineName << _tr("�ĵ�ַ.");
		return defaultReturn;
	}
	else if(ketList.size() == 1)
	{
		valType = QVariant::Type::Int;
		return ketList[0];
	}
	ketList = plcData.Define_short_DB.keys(defineName);
	if (ketList.size() > 1)
	{
		qErrOut() << _tr("�ҵ��������Ϊ:") << defineName << _tr("�ĵ�ַ.");
		return defaultReturn;
	}
	else if (ketList.size() == 1)
	{
		valType = QVariant::Type::Int;
		return ketList[0];
	}
	qErrOut() << _tr("δ�ҵ�����Ϊ:") << defineName << _tr("�ĵ�ַ.");
	return defaultReturn;	
}

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
	bytesReversal(in, 4);
	memcpy(&out, in, 4);
}

static void bytes2int(uchar in[4], int& out)
{
	bytesReversal(in, 4);
	memcpy(&out, in, 4);
}

static void bytes2short(uchar in[2], short& out)
{
	bytesReversal(in, 2);
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

