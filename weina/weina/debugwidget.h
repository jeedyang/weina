#pragma once

#include <QWidget>
#include "ui_debugwidget.h"

class DebugWidget : public QWidget
{
	Q_OBJECT

public:
	DebugWidget(QWidget *parent = Q_NULLPTR);
	~DebugWidget();

private:
	Ui::DebugWidget ui;
	uchar on[4] = { 0xff,0xff,0xff,0xff };
public slots:
	void showDialog();
	void on_servoButtonClicked(bool checked);
};
