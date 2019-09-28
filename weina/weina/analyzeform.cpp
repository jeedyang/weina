#include "analyzeform.h"
#include <QPoint>
#include <qtmaterialflatbutton.h>
#include "plcstation.h"

#define _tr(str) QString::fromLocal8Bit(str)

AnalyzeForm::AnalyzeForm(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_tabs=qobject_cast<QtMaterialTabs*>(ui.widget_tab);
	initTableView();
	initHeaterChartView();
	initTestChartView();
	m_tabs->addTab(_tr("加热丝分布"));
	m_tabs->addTab(_tr("档位分布"));
	m_tabs->addTab(_tr("分档情况"));
	m_valueLabel = new QLabel(this);
	m_valueLabel->hide();
	m_valueLabel->setMinimumWidth(160);
	m_valueLabel->setStyleSheet("QLabel{color: rgb(255, 0, 0)}");
	m_valueLabel->setStyleSheet("QLabel{font: 12pt}");
	m_valueLabel->setStyleSheet("QLabel{background:rgb(0, 255, 0)}");
	connect(m_tabs,SIGNAL(currentChanged(int)),this,SLOT(on_tab_currentChanged(int)));
	connect(this, SIGNAL(continuousNG(int)), this, SLOT(on_continuousNG(int)));
	ui.stackedWidget->setCurrentIndex(0);
	for (int i = 0; i < 24; i++)
	{
		m_resultHistory[i] = 0;
	}
	///
	//std::array<HeaterResult, 24> a;
	//std::array<int, 24> c;
	//for (int i = 0; i < 24; i++)
	//{
	//	a[i] = HeaterResult::Normal;
	//}

	//setHotResResult(a);
	//for (int i = 0; i < 24; i++)
	//{
	//	c[i] = 5;
	//}
	//setTestResult(c);
	//setTestResult(c);
	//for (int i = 0; i < 24; i++)
	//{
	//	c[i] = 6;
	//}

	//setTestResult(c);
	//for (int i = 0; i < 24; i++)
	//{
	//	c[i] = 0;
	//}
	//setTestResult(c);
	//for (int i = 0; i < 24; i++)
	//{
	//	c[i] = i;
	//}
	//setTestResult(c);
	
}

AnalyzeForm::~AnalyzeForm()
{

}



void AnalyzeForm::setTestResult(std::array<int,24> result)
{
	if (result.size()>24)
	{
		return;
	}
	for (int i = 0; i < 24; i++)
	{
		if (result[i] > 29)
		{
			return;
		}
		m_testClassesList[i][result[i]]++;
	}
	if (m_barSetList_test.size() != 30)
	{
		return;
	}
	for (int i = 0; i < 24; i++)
	{
		for (int a = 0; a < 30; a++)
		{
			m_barSetList_test[a]->replace(i, m_testClassesList[i][a]);
		}
	}
	for (int i = 0; i < 24; i++)
	{
		if (m_testClassesList[i]==0)
		{
			m_resultHistory[i]++;
		}
		if (m_resultHistory[i]>=3)//如果连续三次不合格
		{
			emit(this->continuousNG(i));
		}
	}

}

void AnalyzeForm::setHotResResult(std::array<HeaterResult, 24> result)
{
	if (result.size() > 24)
	{
		return;
	}
	for (int i = 0; i < 24; i++)
	{
		if (result[i] > 2)
		{
			return;
		}
		m_heaterStatusList[i][result[i]]++;
	}
	if (m_barSetList_heater.size()!=3)
	{
		return;
	}
	for (int i = 0; i < 24; i++)
	{
		for (int a = 0; a < 3; a++)
		{
			m_barSetList_heater[a]->replace(i, m_heaterStatusList[i][a]);
		}
	}
}

void AnalyzeForm::setID(int id)
{
	m_id = id;
	ui.label_id->setText(QString("ID%1").arg(id));
}

void AnalyzeForm::initHeaterChartView()
{
	for (int i = 0; i < 24; i++)
	{
		for (int a = 0; a < 3; a++)
		{
			m_heaterStatusList[i][a] = 0;
		}
	}
	QHorizontalPercentBarSeries* series = new QHorizontalPercentBarSeries();
	QChart* chart = new QChart();
	QBarSet* set1 = new QBarSet(QString("Close"));
	QBarSet* set2 = new QBarSet(QString("Open"));
	QBarSet* set3 = new QBarSet(QString("Normal"));
	connect(set1, SIGNAL(hovered(bool, int)), this, SLOT(on_mouse_hovered(bool, int)));
	connect(set2, SIGNAL(hovered(bool, int)), this, SLOT(on_mouse_hovered(bool, int)));
	connect(set3, SIGNAL(hovered(bool, int)), this, SLOT(on_mouse_hovered(bool, int)));
	for (int i = 0; i < 24; i++)
	{
		*set1<<0;
		*set2<<0;
		*set3<<0;
	}
	m_barSetList_heater.append(set1);
	m_barSetList_heater.append(set2);
	m_barSetList_heater.append(set3);
	series->append(set1);
	series->append(set2);
	series->append(set3);
	chart->addSeries(series);
	chart->setTitle(_tr("这里展示了各工位短路,断路,正常的分布情况"));
	chart->setAnimationOptions(QChart::SeriesAnimations);
	//![4]
	QStringList categories;
	for (int i = 0; i < 24; i++)
	{
		categories.append(QString("station%1").arg(i));
	}
	
	QBarCategoryAxis* axisY = new QBarCategoryAxis();
	axisY->append(categories);
	chart->addAxis(axisY, Qt::AlignLeft);
	series->attachAxis(axisY);
	QValueAxis* axisX = new QValueAxis();
	chart->addAxis(axisX, Qt::AlignBottom);
	series->attachAxis(axisX);
	//![4]

	//![5]
	chart->legend()->setVisible(true);
	chart->legend()->setAlignment(Qt::AlignBottom);
	m_chartView_heater= qobject_cast<QChartView*>(ui.stackedWidget->widget(0));
	m_chartView_heater->setChart(chart);
	m_chartView_heater->setRenderHint(QPainter::Antialiasing);
}

void AnalyzeForm::initTestChartView()
{
	for (int i = 0; i < 24; i++)
	{
		for (int a = 0; a < 30; a++)
		{
			m_testClassesList[i][a] = 0;
		}
	}
	QHorizontalPercentBarSeries* series = new QHorizontalPercentBarSeries();
	QChart* chart = new QChart();

	for (int i = 0; i < 30; i++)
	{
		QBarSet *set =new QBarSet(QString("c%1").arg(i));
		for (int j = 0; j < 24; j++)
		{
			*set << 0;
		}
		m_barSetList_test.append(set);
		series->append(set);
		connect(set, SIGNAL(hovered(bool, int)), this, SLOT(on_mouse_hovered(bool, int)));
	}
	chart->addSeries(series);
	chart->setTitle(_tr("这里展示了各工位分档结果分布情况"));
	chart->setAnimationOptions(QChart::SeriesAnimations);
	//![4]
	QStringList categories;
	for (int i = 0; i < 24; i++)
	{
		categories.append(QString("station%1").arg(i));
	}

	QBarCategoryAxis* axisY = new QBarCategoryAxis();
	axisY->append(categories);
	chart->addAxis(axisY, Qt::AlignLeft);
	series->attachAxis(axisY);
	QValueAxis* axisX = new QValueAxis();
	chart->addAxis(axisX, Qt::AlignBottom);
	series->attachAxis(axisX);
	//![4]

	//![5]
	chart->legend()->setVisible(true);
	chart->legend()->setAlignment(Qt::AlignBottom);
	m_chartView_test = qobject_cast<QChartView*>(ui.stackedWidget->widget(1));
	m_chartView_test->setChart(chart);
	m_chartView_test->setRenderHint(QPainter::Antialiasing);
}

void AnalyzeForm::initTableView()
{
	QStringList header;
	header.append(_tr("编号"));
	header.append(_tr("最小电阻值"));
	header.append(_tr("最大电阻值"));
	header.append(_tr("最大/小比值"));
	header.append(_tr("最后一次电阻值"));
	header.append(_tr("加热丝状态"));
	header.append(_tr("分档结果"));
	QStandardItemModel* model = new QStandardItemModel();
	//QStringList header = QObject::trUtf8("最小电阻值,最大电阻值,最大/小比值,最后一次电阻值,加热丝状态,分档结果").simplified().split(",");
	model->setHorizontalHeaderLabels(header);
	model->setColumnCount(header.size());
	model->setRowCount(24);
	ui.tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableView->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectItems);
	ui.tableView->setModel(model);
		for (int i = 0; i < 7; i++)
		{
			for (int a = 0; a < 24; a++)
			{
				//model->setItem(a,i, new QStandardItem("666"));
				auto index = model->index(a, 0);
				model->setData(index,a, Qt::EditRole);
			}
		}
}

void AnalyzeForm::setDetailReulst(std::array<double, 24> min,
	std::array<double, 24> max,
	std::array<double, 24> odds,
	std::array<double, 24> lastRes,
	std::array<HeaterResult, 24> heater,
	std::array<int, 24> classes)
{
	auto model = ui.tableView->model();
	for (int i = 0; i < 24; i++)
	{
		auto index=model->index(i, 0);
		model->setData(index,  i, Qt::EditRole);
		index = model->index(i, 1);
		model->setData(index,min[i], Qt::EditRole);
		index = model->index(i, 2);
		model->setData(index,  max[i], Qt::EditRole);
		index = model->index(i, 3);
		model->setData(index,  odds[i], Qt::EditRole);
		index = model->index(i, 4);
		model->setData(index,  lastRes[i], Qt::EditRole);
		index = model->index(i, 5);
		if (heater[i]==HeaterResult::Normal)
		{
			model->setData(index, _tr("正常"), Qt::EditRole);
		}
		else if(heater[i] == HeaterResult::Open)
		{
			model->setData(index, _tr("断路"), Qt::EditRole);
		}
		else if (heater[i] == HeaterResult::Short)
		{
			model->setData(index, _tr("短路"), Qt::EditRole);
		}
		index = model->index(i, 6);
		model->setData(index,  classes[i], Qt::EditRole);
	}
}

void AnalyzeForm::on_tab_currentChanged(int id)
{
	ui.stackedWidget->setCurrentIndex(id);

}

void AnalyzeForm::on_mouse_hovered(bool status, int index)
{
	QBarSet* set = (QBarSet*)sender();
	if (status)
	{
		
		m_valueLabel->setText(set->label().append( QString::asprintf("-Count:%1.0f", set->at(index))));	
		QPoint curPos = mapFromGlobal(QCursor::pos());
		m_valueLabel->move(curPos.x() - m_valueLabel->width() / 2, curPos.y() - m_valueLabel->height() * 1.5);//移动数值
		m_valueLabel->show();

	}
	else
	{
		m_valueLabel->hide();
	}
}

void AnalyzeForm::on_continuousNG(int stationIndex)
{
	auto plc = PLC::PlcStation::Instance();
	plc->writeBool(AreaM, 1, 14, 4, true);
	QMessageBox msgbox;
	msgbox.setText(_tr("板号:%1 工位:%2,连续3次不合格!您可以在档位分布图表中查看详情.").arg(m_id).arg(stationIndex));
	//msgbox.setInformativeText(QString::fromLocal8Bit("退出后未保存的数据将被销毁。"));
	QPushButton* oktButton = msgbox.addButton(QMessageBox::Ok);
	oktButton->setText(_tr("确定并复位报警!"));
	msgbox.exec();
	if (msgbox.clickedButton() == oktButton) {
		plc->writeBool(AreaM, 1, 14, 4, false);
		for (int i = 0; i < 24; i++)
		{
			m_resultHistory[i] = 0;
		}
	}
}
