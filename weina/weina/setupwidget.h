#pragma once

#include <QWidget>
#include "ui_setupwidget.h"
#include <QCheckBox>

class SetupWidget : public QWidget
{
	Q_OBJECT

public:
	SetupWidget(QWidget *parent = Q_NULLPTR);
	~SetupWidget();

private:
	Ui::SetupWidget ui;
};
