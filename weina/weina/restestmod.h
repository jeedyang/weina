#pragma once

#include <QObject>
#include "plcstation.h"
#include <QSerialPort>
#include <QThread>
#include <QTimer>
#include "classbase.h"


class ResTestmod : public QThread
{
	Q_OBJECT

public:
	ResTestmod(QObject *parent);
	~ResTestmod();

	int connectMod();
	void setPortName(QString portName);
	void setHotRelay();
	void readStart();
	void readStop();
	void hotMod(uchar* relayStatus);
	void tsetResMod();
	void tsetHotresMod();
	void getRealyStaus();
	void setCtrlPanelWidget(CtrlPanelBase* widget);
public:
	int hotRes[24];
	int res[24];
	uchar m_relayStatus[24];

private:
	void refreshHotResWidget();
	void refreshResWidget();
	void run();
	bool threadRead_en=false;
	QString m_serialPortName;
	QSerialPort* m_serialPort = new QSerialPort();
	CtrlPanelBase* m_ctrlPanel;
	QTimer timer;
private slots:
	void on_readHotResDone();
	void on_readResDone();
	void on_getRealyStausDone();
	void on_HotButtonCilcked(int id, bool checked);
	void on_timeout();
signals:
	void getRealyStausDone();
	void readHotResDone();
	void readResDone();
	
};
