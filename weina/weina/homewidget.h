#pragma once

#include <QWidget>
#include <QButtonGroup>
#include "ui_homewidget.h"
#include "classbase.h"
#include "restestmod.h"

class HomeWidget : public QWidget
{
	Q_OBJECT

public:
	HomeWidget(QWidget *parent = Q_NULLPTR);
	~HomeWidget();

private:
	Ui::HomeWidget ui;
	QGridLayout* m_panelLaylot[4];
	CtrlPanelBase* m_panel_widget[4];
	ResTestmod* resModArry[4];
	QStringList m_serialPortNameList;
	QButtonGroup m_btnGroup;
private slots:
	void on_btnGroupToggled(QAbstractButton* button, bool checked);
};
