#pragma once

#include <QObject>
#include <QList>
#include "analyzeform.h"
#include <array>

#define DEFINE_SINGLETON(cls) \
 private:\
 static std::auto_ptr<cls> m_pInstance;\
 protected:\
	cls(QObject *parent = Q_NULLPTR);\
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



class Analyze : public QObject
{
	Q_OBJECT

	DEFINE_SINGLETON(Analyze)
public:
	//Analyze(QObject *parent);
	//~Analyze();
	void setTestResult(int id, std::array<int,24> result);
	void setHotResResult(int id, std::array<HeaterResult,24> result);
	void showAnalyzeForm(int id);
	void setDetailReulst(int id, std::array<double, 24> min,
		std::array<double, 24> max,
		std::array<double, 24> odds,
		std::array<double, 24> lastRes,
		std::array<HeaterResult, 24> heater,
		std::array<int, 24> classes);
private:
	QList<AnalyzeForm*> m_formList;
};
