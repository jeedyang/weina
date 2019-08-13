#pragma once

#include <QtWidgets/QMainWindow>
#include <QButtonGroup>
#include "ui_mainwindow.h"
#include "debugwidget.h"
#include "homewidget.h"
#include "setupwidget.h"
#include "logwidget.h"
#include "classbase.h"
#include <QLibrary>
#include "plcstation.h"
#include "restestmod.h"
#include "reportwidget.h"
#include "userwidget.h"
#include "alltype.h"


class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	void setUsetInfo(UserInfo info);
private:
	void initForm();
	void showWidget(QWidget* parent,QWidget* children);
private slots:
	void on_btnGroupWidgetClicked(QAbstractButton* button);
	void on_btnGroupCtrlToggled(QAbstractButton* button, bool checked);
private:
	Ui::MainWindowClass ui;
	/********************************************************************/
	QButtonGroup m_btnGroupWidget;
	QButtonGroup m_btnGroupCtrl;
	HomeWidget* m_home_widget;
	DebugWidget* m_debug_widget;
	SetupWidget *m_setup_widget;
	LogWidget* m_log_widget;
	ReportWidget* m_report_widget;
	UserWidget* m_user_widget;
	/********************************************************************/
	QVBoxLayout *m_hLayout=new QVBoxLayout();
	UserInfo m_userInfo;
};
