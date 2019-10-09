#pragma once

#include <QWidget>
#include <QtCharts>
QT_CHARTS_USE_NAMESPACE

#include "ui_analyzeform.h"
#include <array>
#include <qtmaterialtabs.h>
#include <QLabel>
#include <qtmaterialdialog.h>
#include <QTableView>

typedef enum _HeaterResult
{
	Short,
	Open,
	Normal
}HeaterResult;


class AnalyzeForm : public QWidget
{
	Q_OBJECT

public:
	AnalyzeForm(QWidget *parent = Q_NULLPTR);
	~AnalyzeForm();
	void setTestResult(std::array<int, 24> result);
	void setHotResResult(std::array<HeaterResult, 24> result);
	void setID(int id);
	void setDetailReulst(std::array<double, 24> min,
		std::array<double, 24> max,
		std::array<double, 24> odds,
		std::array<double, 24> lastRes,
		std::array<HeaterResult, 24> heater,
		std::array<int, 24>);
private:
	Ui::AnalyzeForm ui;
	QtMaterialTabs *m_tabs;
	void initHeaterChartView();
	void initTestChartView();
	void initTableView();
	QChartView* m_chartView_heater;
	QChartView* m_chartView_test;
	QList<QBarSet*> m_barSetList_heater;
	QList<QBarSet*> m_barSetList_test;
	int m_heaterStatusList[24][3];
	int m_testClassesList[24][30];
	int m_resultHistory[24];//连续不合格记录PLC的M22.0为ON报警
	int m_id=0;
	QLabel *m_valueLabel;
signals:
	void continuousNG(int stationIndex);
private slots:
	void on_tab_currentChanged(int id);
	void on_mouse_hovered(bool status, int index);
	void on_continuousNG(int );
};
