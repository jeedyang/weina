#pragma once

#include <QtWidgets/QMainWindow>
#include <QButtonGroup>
#include "ui_mainwindow.h"
#include "debugwidget.h"
#include "homewidget.h"
#include "setupwidget.h"
#include "classbase.h"
#include <QLibrary>
#include "plcstation.h"
#include "restestmod.h"

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
	HomeWidget* m_home_widget;
	DebugWidget* m_debug_widget;
	SetupWidget *m_setup_widget;
	QVBoxLayout *m_hLayout=new QVBoxLayout();

};
