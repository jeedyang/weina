#include "report.h"

#define _tr(str) QString::fromLocal8Bit(str)

IMPLEMENT_SINGLETON(Report)

Report::Report()
{
}

int Report::save2excel()
{
	if (m_tableWidget == nullptr)
		return 0;
	return 0;
}

void Report::setTabWidget(QTableWidget* tableWidget)
{
	m_tableWidget = tableWidget;
}

QTableWidget* Report::getTabWidget()
{
	return m_tableWidget;
}

void Report::clearTabWidget()
{
	if (m_tableWidget==nullptr)
		return;
	//m_tableWidget->clear(); 
	m_tableWidget->clearContents();
	m_tableWidget->setRowCount(0);
}

void Report::appendResult2Widget(int id,QList<int> numList)
{
	if (m_tableWidget == nullptr)
		return;
	m_tableWidget->insertRow(0);
	m_tableWidget->setItem(0, 0, new QTableWidgetItem(QString::number(id)));
	for (int i = 0; i < numList.size(); i++)
	{
		m_tableWidget->setItem(0, i + 1, new QTableWidgetItem(QString::number(numList[i])));
	}
}

Report::~Report()
{
}
