#pragma once

#include <QObject>
#include <QList>
#include "plcstation.h"
#include "restestmod.h"
#include <QTimer>
#include "classbase.h"

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

class MainCtrl : public QObject
{
	Q_OBJECT

	DEFINE_SINGLETON(MainCtrl)

public:
	//MainCtrl(QObject *parent = nullptr);
	//~MainCtrl();

	void setModules(ResTestmod** mods);
	ResTestmod* getModules(int id );
	void start();
	void stop();
	void testStart(int id);				//检测开始
	void classifyStart(int num);			//分类开始
	void arrangeStart(int num);				//排板开始
private:
	QTimer m_logicTimer;
	uchar arrangeEndStatus[4];				//排板结束标志
	uchar classifyEndStatus[4];				//分料结束标识
	QList<ResTestmod*> m_testMods;			//检测模块对象
	bool m_testStatus[4] = {false,false ,false ,false };
	array <int, 4> boardStatus;
private slots:
	void on_logicTimeOut();
	void on_testDone(int id);
};
