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
	void testStart(int id);				//��⿪ʼ
	void classifyStart(int num);			//���࿪ʼ
	void arrangeStart(int num);				//�Ű忪ʼ
private:
	QTimer m_logicTimer;
	uchar arrangeEndStatus[4];				//�Ű������־
	uchar classifyEndStatus[4];				//���Ͻ�����ʶ
	QList<ResTestmod*> m_testMods;			//���ģ�����
	bool m_testStatus[4] = {false,false ,false ,false };
	array <int, 4> boardStatus;
private slots:
	void on_logicTimeOut();
	void on_testDone(int id);
};
