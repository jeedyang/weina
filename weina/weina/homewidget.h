#pragma once

#include <QWidget>
#include <QButtonGroup>
#include "ui_homewidget.h"
#include "classbase.h"
#include "restestmod.h"
#include "mainctrl.h"

class QCheckBox;

class HomeWidget : public QWidget
{
	Q_OBJECT

public:
	HomeWidget(QWidget *parent = Q_NULLPTR);
	~HomeWidget();
	QCheckBox *checkBox_hotRes;
private:
	Ui::HomeWidget ui;
	QGridLayout* m_panelLaylot[4];
	CtrlPanelBase* m_panel_widget[4];
	ResTestmod* resModArry[4];
	QStringList m_serialPortNameList;
	QButtonGroup m_btnGroup;
	 
	//MainCtrl mainCtrl;
private slots:
	void on_btnGroupToggled(QAbstractButton* button, bool checked);
	void on_checkBox_resTestClicked(bool);
	void on_pushButton_analyzeClicked();
};
