#pragma once

#include <QObject>
#include <QList>
#include "plcstation.h"
#include "restestmod.h"
#include <QTimer>

class MainCtrl : public QObject
{
	Q_OBJECT

public:
	MainCtrl(QObject *parent = nullptr);
	~MainCtrl();

	void setModules(ResTestmod** mods);
	void start();
	void testStart(int num);				//检测开始
	void classifyStart(int num);			//分类开始
	void arrangeStart(int num);				//排板开始
private:
	QTimer m_logicTimer;
	uchar arrangeEndStatus[4];				//排板结束标志
	uchar classifyEndStatus[4];				//分料结束标识
	QList<ResTestmod*> m_testMods;			//检测模块对象

private slots:
	void on_logicTimeOut();
	void on_testDone(int id);
};
