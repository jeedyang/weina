#include "mainwindow.h"
#include <QDebug>
#include "plcstation.h"
#include "mainctrl.h"

#define START 1
#define PAUSE 1
#define STOP 0
#define CONTINUS 0

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	initForm();
	QObject::connect(&m_btnGroupWidget,SIGNAL(buttonToggled(QAbstractButton * , bool )),this,SLOT(on_btnGroupWidgetToggled(QAbstractButton*, bool)));
	QObject::connect(&m_btnGroupCtrl,SIGNAL(buttonToggled(QAbstractButton * , bool )),this,SLOT(on_btnGroupCtrlToggled(QAbstractButton*, bool)));
	auto plc = PLC::PlcStation::Instance();
	int a=plc->connect();
	qDebug() << a;
	if (a == 0)
	{
		plc->pollingStart();
	}
	m_setup_widget = qobject_cast<SetupWidget*>(ui.stackedWidget_main->widget(1));
	m_debug_widget = qobject_cast<DebugWidget*>(ui.stackedWidget_main->widget(2));
	m_home_widget = qobject_cast<HomeWidget*>(ui.stackedWidget_main->widget(0));




}

void MainWindow::on_btnGroupWidgetToggled(QAbstractButton* button, bool checked)
{
	
	for (int i = 0; i < m_btnGroupWidget.buttons().size(); i++)
	{
		QAbstractButton* btn= m_btnGroupWidget.buttons()[i];
		if (btn!=button)
		{
			button->setChecked(false);
		}	
	}
	int id = m_btnGroupWidget.id(button);
	
	switch (id)
	{
	case 0:
		//showWidget(ui.widget_main, m_panel_widget);
		ui.stackedWidget_main->setCurrentIndex(id);
		m_debug_widget->widgetHide();
		break;
	case 1:
		//showWidget(ui.widget_main, m_setup_widget);
		ui.stackedWidget_main->setCurrentIndex(id);
		m_setup_widget->widgetShow();
		m_debug_widget->widgetHide();
		break;
	case 2:
		ui.stackedWidget_main->setCurrentIndex(id);
		m_debug_widget->widgetShow();
		break;
	default:
		break;
	}

}

void MainWindow::initForm()
{
	m_btnGroupWidget.addButton(ui.pushButton_home,0);
	m_btnGroupWidget.addButton(ui.pushButton_setup, 1);
	m_btnGroupWidget.addButton(ui.pushButton_debug, 2);
	m_btnGroupCtrl.setExclusive(false);
	m_btnGroupCtrl.addButton(ui.pushButton_start,0);
	m_btnGroupCtrl.addButton(ui.pushButton_pause, 1);
	//showWidget(ui.stackedWidget_main->widget(0), m_panel_widget);
}

void MainWindow::showWidget(QWidget* parent, QWidget* children)
{
	//QObjectList widgetList = ui.widget_main->children();
	//QLayoutItem* child;
	//while ((child = m_hLayout->takeAt(0)) != 0)
	//{
	//	if (child->widget())
	//	{
	//		child->widget()->setParent(NULL);
	//		child->widget()->hide();
	//	}

	//	delete child;
	//}
	//m_hLayout->addWidget(children, 0);
	//children->setParent(parent);
	//children->move(10,10);
	//children->show();
	//ui.widget_main->setLayout(m_hLayout);
}

void MainWindow::on_btnGroupCtrlToggled(QAbstractButton* button, bool checked)
{
	auto mainctrl = MainCtrl::Instance();
	auto plc = PLC::PlcStation::Instance();
	if (button->objectName() == _tr("pushButton_start"))
	{
		if (button->isChecked())
		{
			plc->setValue(_tr("Æô¶¯_Í£Ö¹"), START);
			mainctrl->start();
		}
		else
		{
			plc->setValue(_tr("Æô¶¯_Í£Ö¹"), STOP);
			mainctrl->stop();
		}
	}
	if (button->objectName() == _tr("pushButton_pause"))
	{
		if (button->isChecked())
		{
			plc->setValue(_tr("ÔÝÍ£_¼ÌÐø"), PAUSE);
		}
		else
		{
			plc->setValue(_tr("ÔÝÍ£_¼ÌÐø"), CONTINUS);
		}
	}
}
