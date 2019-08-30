#include "homewidget.h"
#include <QDebug>
#include <QLibrary>
#include "report.h"


HomeWidget::HomeWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_serialPortNameList.append(_tr("COM13"));
	m_serialPortNameList.append(_tr("COM14"));
	m_serialPortNameList.append(_tr("COM15"));
	m_serialPortNameList.append(_tr("COM16"));
	QLibrary lib("CtrlPanel.dll");
	typedef CtrlPanelBase* (*pFunc)(int, QWidget*);
	pFunc func = (pFunc)lib.resolve("createInstance");
	if (!func) {
		qDebug() << "error";
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			m_panel_widget[i] = func(1, this);

			m_panel_widget[i]->setID(i);

			m_panelLaylot[i] = new QGridLayout();
			m_panelLaylot[i]->addWidget(m_panel_widget[i]);
			ui.stackedWidget->widget(i)->setLayout(m_panelLaylot[i]);

			int a;
			resModArry[i] = new ResTestmod(this);
			resModArry[i]->id = i;
			resModArry[i]->setCtrlPanelWidget(m_panel_widget[i]);
			resModArry[i]->setPortName(m_serialPortNameList[i]);
			a = resModArry[i]->connectMod();
			if (!a)
			{
				resModArry[i]->readStart();
				//resModArry[i]->getRealyStaus();
			}
			QObject::connect(m_panel_widget[i], SIGNAL(hotButtonClicked(int, bool)), resModArry[i], SLOT(on_HotButtonCilcked(int, bool)));

		}

	}

	m_btnGroup.addButton(ui.pushButton_mod0, 0);
	m_btnGroup.addButton(ui.pushButton_mod1, 1);
	m_btnGroup.addButton(ui.pushButton_mod2, 2);
	m_btnGroup.addButton(ui.pushButton_mod3, 3);

	QObject::connect(&m_btnGroup, SIGNAL(buttonToggled(QAbstractButton*, bool)), this, SLOT(on_btnGroupToggled(QAbstractButton*, bool)));
	ui.stackedWidget->setCurrentIndex(0);

	auto mainctrl = MainCtrl::Instance();
	mainctrl->setModules(resModArry);

	for (int i = 0; i < 4; i++)
	{
		QObject::connect(resModArry[i], SIGNAL(testDone(int)), mainctrl, SLOT(on_testDone(int)));

	}
	//初始化统计表格
	QStringList classHeader;
	classHeader.append(_tr("板号"));
	classHeader.append(_tr("不合格数量"));
	classHeader.append(_tr("1档数量"));
	classHeader.append(_tr("2档数量"));
	classHeader.append(_tr("3档数量"));
	classHeader.append(_tr("4档数量"));
	classHeader.append(_tr("5档数量"));
	classHeader.append(_tr("6档数量"));
	classHeader.append(_tr("7档数量"));
	classHeader.append(_tr("8档数量"));
	classHeader.append(_tr("9档数量"));
	classHeader.append(_tr("10档数量"));
	classHeader.append(_tr("11档数量"));
	classHeader.append(_tr("12档数量"));
	classHeader.append(_tr("13档数量"));
	classHeader.append(_tr("14档数量"));
	classHeader.append(_tr("15档数量"));
	classHeader.append(_tr("16档数量"));
	classHeader.append(_tr("17档数量"));
	classHeader.append(_tr("18档数量"));
	classHeader.append(_tr("19档数量"));
	classHeader.append(_tr("20档数量"));
	classHeader.append(_tr("21档数量"));
	classHeader.append(_tr("22档数量"));
	classHeader.append(_tr("23档数量"));
	classHeader.append(_tr("24档数量"));
	classHeader.append(_tr("25档数量"));
	classHeader.append(_tr("26档数量"));
	classHeader.append(_tr("27档数量"));
	classHeader.append(_tr("28档数量"));
	classHeader.append(_tr("29档数量"));
	ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectItems);
	ui.tableWidget->setColumnCount(classHeader.size());
	ui.tableWidget->setHorizontalHeaderLabels(classHeader);
	///
	//for (int i = 0; i < classHeader.size(); i++)
	//{
	//	ui.tableWidget->setColumnWidth(0, 50);
	//}
	//ui.tableWidget->insertRow(0);
	//ui.tableWidget->setItem(0, 0, new QTableWidgetItem(_tr("0")));
	//ui.tableWidget->insertRow(0);
	//ui.tableWidget->setItem(0, 0, new QTableWidgetItem(_tr("1")));
	//ui.tableWidget->insertRow(0);
	//ui.tableWidget->setItem(0, 0, new QTableWidgetItem(_tr("2")));
	///
	auto report = Report::Instance();
	report->setTabWidget(ui.tableWidget);
	QObject::connect(ui.pushButton_clearTable, SIGNAL(pressed()), report, SLOT(clearTabWidget()));
	QObject::connect(ui.pushButton_saveToExcel, SIGNAL(pressed()), report, SLOT(save2excel()));
}

HomeWidget::~HomeWidget()
{
}


void HomeWidget::on_btnGroupToggled(QAbstractButton* button, bool checked)
{
	for (int i = 0; i < m_btnGroup.buttons().size(); i++)
	{
		QAbstractButton* btn = m_btnGroup.buttons()[i];
		if (btn != button)
		{
			button->setChecked(false);
		}
	}
	int id = m_btnGroup.id(button);
	ui.stackedWidget->setCurrentIndex(id);
	switch (id)
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	default:
		break;
	}
}