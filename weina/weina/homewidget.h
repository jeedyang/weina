#pragma once

#include <QWidget>
#include "ui_homewidget.h"
#include "classbase.h"

class HomeWidget : public QWidget
{
	Q_OBJECT

public:
	HomeWidget(QWidget *parent = Q_NULLPTR);
	~HomeWidget();

private:
	Ui::HomeWidget ui;
	CtrlPanelBase* m_panel_widget;
};
