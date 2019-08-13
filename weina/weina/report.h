#pragma once

#include <QObject>
#include <QTableWidget>

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

class Report : public QObject
{
	Q_OBJECT

	DEFINE_SINGLETON(Report)

public:
	//Report(QObject *parent); 
	void setTabWidget(QTableWidget* tableWidget);
	QTableWidget* getTabWidget();
	void appendResult2Widget(int id, QList<int> numList);
public slots:
	void save2excel();
	void clearTabWidget();
private:
	QTableWidget* m_tableWidget=nullptr;
	
	//~Report();
};
