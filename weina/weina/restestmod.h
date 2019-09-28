#pragma once

#include <QObject>
#include "plcstation.h"
#include <QSerialPort>
#include <QThread>
#include <QTimer>
#include "classbase.h"
#include <array>
#include "Analyze.h"

class ResTestmod : public QThread
{
	Q_OBJECT

public:
	ResTestmod(QObject *parent);
	~ResTestmod();

	int connectMod();
	
	void setPortName(QString portName);
	void setHotRelay();
	void testStart();
	void readStart();
	void readStop();
	void hotMod(uchar* relayStatus);
	void testResMod();
	void testHotresMod();
	void getRealyStaus();
	void setCtrlPanelWidget(CtrlPanelBase* widget);
public:
	int hotRes[24];
	int res[24];
	int minRes[24];
	int maxRes[24];
	int result[24];
	double maxminOdds[24];
	TestParameters paramete;

	//
	//int testHotresTime=5000;
	//int testTime = 10000;
	//int min_maxTestTime = 5000;
	//array<int,29> minResScope;
	//array<int, 29> maxResScope;
	int id=0;
private:
	void refreshHotResWidget();
	void refreshResWidget();
	void run();
	//uchar m_setRelayStatus[24];
	uchar m_relayStatus[24];
	bool threadRead_en=false;
	QString m_serialPortName;
	QSerialPort* m_serialPort = new QSerialPort();
	CtrlPanelBase* m_ctrlPanel;
	//////////////
	QTimer timer;
	QTimer m_testHotResTimer;
	QTimer m_testResTimer;
	QTimer m_min_maxTestTimer;
	/////////
	bool getMin_MaxRes = false;
	//±£´æ½á¹û
	std::array<double, 24> m_min;
	std::array<double, 24> m_max;
	std::array<double, 24> m_odds;
	std::array<double, 24> m_lastRes;
	std::array<HeaterResult, 24> m_heater;
	std::array<int, 24> m_classes;
private slots:
	void on_readHotResDone();
	void on_readResDone();
	void on_getRealyStausDone();
	void on_HotButtonCilcked(int id, bool checked);
	void on_timeout();
	void on_testHotResTimer_timeout();
	void on_testResTimer_timeout();
	void on_min_maxTestTimer_timeout();
signals:
	void getRealyStausDone();
	void readHotResDone();
	void readResDone();
	void testDone(int);
};
