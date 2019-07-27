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
	void testStart(int num);				//��⿪ʼ
	void classifyStart(int num);			//���࿪ʼ
	void arrangeStart(int num);				//�Ű忪ʼ
private:
	QTimer m_logicTimer;
	uchar arrangeEndStatus[4];				//�Ű������־
	uchar classifyEndStatus[4];				//���Ͻ�����ʶ
	QList<ResTestmod*> m_testMods;			//���ģ�����

private slots:
	void on_logicTimeOut();
	void on_testDone(int id);
};
