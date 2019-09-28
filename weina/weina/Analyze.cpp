#include "Analyze.h"

IMPLEMENT_SINGLETON(Analyze)

Analyze::Analyze(QObject* parent)
	:QObject(parent)
{
	for (int i = 0; i < 4; i++)
	{
		m_formList.append(new AnalyzeForm());
		m_formList[i]->setID(i);
	}
}

Analyze::~Analyze()
{
}

void Analyze::setTestResult(int id, std::array<int, 24> result)
{
	if (id>3||id<0)
	{
		return;
	}
	m_formList[id]->setTestResult(result);
}

void Analyze::setHotResResult(int id, std::array<HeaterResult, 24> result)
{
	if (id > 3 || id < 0)
	{
		return;
	}
	m_formList[id]->setHotResResult(result);
}

void Analyze::showAnalyzeForm(int id)
{
	if (id > 3 || id < 0)
	{
		return;
	}
	m_formList[id]->showFullScreen();
}

void Analyze::setDetailReulst(int id, std::array<double, 24> min, std::array<double, 24> max, std::array<double, 24> odds, std::array<double, 24> lastRes, std::array<HeaterResult, 24> heater, std::array<int, 24> classes)
{
	m_formList[id]->setDetailReulst(min,max,odds,lastRes,heater,classes);
}
