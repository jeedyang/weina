#pragma once

#include <QtWidgets/QMainWindow>
#include <QButtonGroup>
#include "ui_mainwindow.h"
#include "debugwidget.h"
#include "setupwidget.h"
#include "classbase.h"
#include <QLibrary>
#include "plcstation.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);

private:
	void initForm();
	void showWidget(QWidget* parent,QWidget* children);
private slots:
	void on_btnGroupToggled(QAbstractButton* button, bool checked);

private:
	Ui::MainWindowClass ui;
	QButtonGroup m_btnGroup;
	PLC::PlcStation* plc;
	//DebugWidget *m_debug_widget=new DebugWidget(ui.widget_main);
	//SetupWidget *m_setup_widget=new SetupWidget(ui.widget_main);
	QVBoxLayout *m_hLayout=new QVBoxLayout();
	CtrlPanelBase* m_panel_widget;
};
