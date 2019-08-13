#include "mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include "plcstation.h"
#include "mainctrl.h"
#include "logclass.h"

#define START 1
#define PAUSE 1
#define STOP 0
#define CONTINUS 0

#define _wtr(str) QString(str).toStdWString().c_str()




MainWindow::MainWindow( QWidget *parent)
	: QMainWindow(parent)

{
	ui.setupUi(this);
	this->setWindowTitle(_tr("�������Զ�ɸѡϵͳ"));
	//system("E:/Work/weina/V2/�����嵥.xls");
	//ShellExecute(NULL, _wtr("open"), _wtr("E:/Work/weina/V2/�����嵥.xls"), NULL, NULL, SW_SHOWNORMAL);

	initForm();
	QObject::connect(&m_btnGroupWidget,SIGNAL(buttonClicked(QAbstractButton * )),this,SLOT(on_btnGroupWidgetClicked(QAbstractButton*)));
	QObject::connect(&m_btnGroupCtrl,SIGNAL(buttonToggled(QAbstractButton * , bool )),this,SLOT(on_btnGroupCtrlToggled(QAbstractButton*, bool)));
	auto plc = PLC::PlcStation::Instance();
	int a=plc->connect();
	qDebug() << a;
	if (a == 0)
	{
		plc->pollingStart();
	}
	else
	{
		logClass::add_Data_to_log(_tr("PLC����ʧ�ܡ�"));
		QMessageBox::warning(this, _tr("����"), _tr("PLC����ʧ�ܣ�"));
	}
	m_home_widget = qobject_cast<HomeWidget*>(ui.stackedWidget_main->widget(0));
	m_setup_widget = qobject_cast<SetupWidget*>(ui.stackedWidget_main->widget(1));
	m_debug_widget = qobject_cast<DebugWidget*>(ui.stackedWidget_main->widget(2));
	m_log_widget = qobject_cast<LogWidget*>(ui.stackedWidget_main->widget(3));
	m_report_widget = qobject_cast<ReportWidget*>(ui.stackedWidget_main->widget(4));
	m_user_widget = qobject_cast<UserWidget*>(ui.stackedWidget_main->widget(5));
}

void MainWindow::on_btnGroupWidgetClicked(QAbstractButton* button)
{
	if (button->objectName()==_tr("pushButton_close"))
	{
		QMessageBox msgbox;
		msgbox.setText(_tr("��ȷ��Ҫ�˳���"));
		//msgbox.setInformativeText(QString::fromLocal8Bit("�˳���δ��������ݽ������١�"));
		QPushButton* oktButton = msgbox.addButton(QMessageBox::Ok);
		oktButton->setText(_tr("ȷ��"));
		QPushButton* CancelButton = msgbox.addButton(QMessageBox::Cancel);
		CancelButton->setText(_tr("ȡ��"));
		msgbox.exec();

		if (msgbox.clickedButton() == oktButton) {
			this->close();
		}
		else if (msgbox.clickedButton() == CancelButton) {
			msgbox.close();
		}
		return;
	}
	if (button->objectName()==_tr("pushButton_min"))
	{
		this->showMinimized();
		//button->setChecked(false);
		return;
	}
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
		logClass::add_Data_to_log(_tr("���������档"));
		break;
	case 1:
		//showWidget(ui.widget_main, m_setup_widget);
		ui.stackedWidget_main->setCurrentIndex(id);
		m_setup_widget->widgetShow();
		m_debug_widget->widgetHide();
		logClass::add_Data_to_log(_tr("�������ý��档"));
		break;
	case 2:
		ui.stackedWidget_main->setCurrentIndex(id);
		m_debug_widget->widgetShow();
		logClass::add_Data_to_log(_tr("������Խ��档"));
		break;
	case 3:
		ui.stackedWidget_main->setCurrentIndex(id);
		m_debug_widget->widgetHide();
		logClass::add_Data_to_log(_tr("������־���档"));
		break;
	case 4:
		ui.stackedWidget_main->setCurrentIndex(id);
		m_debug_widget->widgetHide();
		logClass::add_Data_to_log(_tr("���뱨����档"));
		break;
	case 5:
		ui.stackedWidget_main->setCurrentIndex(id);
		m_debug_widget->widgetHide();
		m_user_widget->showWidget();
		logClass::add_Data_to_log(_tr("�����û�������档"));
		break;
	default:
		break;
	}

}

void MainWindow::setUsetInfo(UserInfo info)
{
	m_userInfo = info;
	m_user_widget->setUserInfo(m_userInfo);
	if (m_userInfo.type==UserType::general)
	{
		ui.pushButton_debug->setEnabled(false);
	}
}

void MainWindow::initForm()
{
	m_btnGroupWidget.addButton(ui.pushButton_home,0);
	m_btnGroupWidget.addButton(ui.pushButton_setup, 1);
	m_btnGroupWidget.addButton(ui.pushButton_debug, 2);
	m_btnGroupWidget.addButton(ui.pushButton_log, 3);
	m_btnGroupWidget.addButton(ui.pushButton_report, 4);
	m_btnGroupWidget.addButton(ui.pushButton_user, 5);

	m_btnGroupWidget.addButton(ui.pushButton_min,8);
	m_btnGroupWidget.addButton(ui.pushButton_close,9);
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
			plc->setValue(_tr("����_ֹͣ"), START);
			mainctrl->start();
			button->setText(_tr("ֹͣ"));
			logClass::add_Data_to_log(_tr("�豸������"));
			if (m_userInfo.type == UserType::admin|| m_userInfo.type == UserType::general)
			{
				ui.pushButton_debug->setEnabled(false);
				ui.pushButton_setup->setEnabled(false);
			}
		}
		else
		{
			plc->setValue(_tr("����_ֹͣ"), STOP);
			mainctrl->stop();
			button->setText(_tr("����"));
			logClass::add_Data_to_log(_tr("�豸ֹͣ��"));
			if (m_userInfo.type == UserType::admin)
			{
				ui.pushButton_debug->setEnabled(true);
				ui.pushButton_setup->setEnabled(true);
			}
			else if (m_userInfo.type == UserType::general)
			{
				ui.pushButton_setup->setEnabled(true);
			}
		}
	}
	if (button->objectName() == _tr("pushButton_pause"))
	{
		if (button->isChecked())
		{
			plc->setValue(_tr("��ͣ_����"), PAUSE);
			button->setText(_tr("����"));
			logClass::add_Data_to_log(_tr("�豸��ͣ��"));
		}
		else
		{
			plc->setValue(_tr("��ͣ_����"), CONTINUS);
			button->setText(_tr("��ͣ"));
			logClass::add_Data_to_log(_tr("�豸������"));
		}
	}
}
