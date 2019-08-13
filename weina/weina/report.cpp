#include "report.h"
#include "include/xlnt/xlnt.hpp"
#include <QDateTime>
#include <QDir>
#include <QMessageBox>

#define _wtr(str) QString(str).toStdWString().c_str()
#define _tr(str) QString::fromLocal8Bit(str)

IMPLEMENT_SINGLETON(Report)

Report::Report()
{
}

void Report::save2excel()
{
	if (m_tableWidget == nullptr)
		return;

	xlnt::workbook wbook;
	xlnt::worksheet wsheet = wbook.active_sheet();
	wsheet.title("test");
	wsheet.cell("A1").value(_tr("板号").toStdString());
	wsheet.cell("B1").value(_tr("不合格数量").toStdString());
	for (int i = 0; i < 29; i++)
	{
		wsheet.cell(i+3,1).value(_tr("%1档数量").arg(i+1).toStdString());
	}
	
	wsheet.title(_tr("分类结果").toStdString());

	
	for (int i = 0; i < m_tableWidget->rowCount(); i++)
	{
		for (int j = 0; j < m_tableWidget->columnCount(); j++)
		{
			
			if (m_tableWidget->item(i, j) == NULL)
			{
				break;
			}
			QString dataStr = m_tableWidget->item(i, j)->text();
			wsheet.cell(j+1, i + 2).value(dataStr.toInt());
		}
	}

	QDateTime datetime;
	QString path = QDir::currentPath() + "/report/" + datetime.currentDateTime().toString("yyyy-MM");
	QDir dir(path);
	if (!dir.exists())
	{
		dir.mkdir(path);
	}

	QString fileName= path.append(_tr("/报表")).append(datetime.currentDateTime().toString(_tr("MM_dd_hh_mm_ss"))).append(_tr(".xlsx"));
	wbook.save(fileName.toStdString());
	QMessageBox::information(NULL,_tr("提示"),_tr("报表导出成功!导出至:").append(fileName));
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
