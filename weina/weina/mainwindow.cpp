#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	initForm();
	QObject::connect(&m_btnGroup,SIGNAL(buttonToggled(QAbstractButton * , bool )),this,SLOT(on_btnGroupToggled(QAbstractButton*, bool)));

	auto plc = PLC::PlcStation::Instance();
	int a=plc->connect();
	qDebug() << a;
	if (a == 0)
	{
		plc->writeBool(AreaQ,0,0,0,true);
		plc->writeBool(AreaQ, 0, 0, 3, true);
		plc->writeBool(AreaQ, 0, 0, 7, true);
		plc->pollingStart();
	}
	m_setup_widget = qobject_cast<SetupWidget*>(ui.stackedWidget_main->widget(1));
	m_debug_widget = qobject_cast<DebugWidget*>(ui.stackedWidget_main->widget(2));
	m_home_widget = qobject_cast<HomeWidget*>(ui.stackedWidget_main->widget(0));

}

void MainWindow::on_btnGroupToggled(QAbstractButton* button, bool checked)
{
	for (int i = 0; i < m_btnGroup.buttons().size(); i++)
	{
		QAbstractButton* btn= m_btnGroup.buttons()[i];
		if (btn!=button)
		{
			button->setChecked(false);
		}	
	}
	int id = m_btnGroup.id(button);
	ui.stackedWidget_main->setCurrentIndex(id);
	switch (id)
	{
	case 0:
		//showWidget(ui.widget_main, m_panel_widget);
		m_debug_widget->widgetHide();
		break;
	case 1:
		//showWidget(ui.widget_main, m_setup_widget);
		m_debug_widget->widgetHide();
		break;
	case 2:
		m_debug_widget->widgetShow();
		break;
	default:
		break;
	}
}

void MainWindow::initForm()
{
	m_btnGroup.addButton(ui.pushButton_home,0);
	m_btnGroup.addButton(ui.pushButton_setup, 1);
	m_btnGroup.addButton(ui.pushButton_debug, 2);

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
