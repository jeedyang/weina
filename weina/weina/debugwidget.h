#pragma once

#include <QWidget>
#include "ui_debugwidget.h"
#include <QTimer>

class DebugWidget : public QWidget
{
	Q_OBJECT

public:
	DebugWidget(QWidget *parent = Q_NULLPTR);
	~DebugWidget();

private:
	void refreshServoWidget();
	void refreshCylinderWidget();
	void refreshIOmapWidget();
	Ui::DebugWidget ui;
	QTimer timer;
public slots:
	void showDialog();
	void on_servoButtonClicked(bool checked);
	void on_servoDspEditingFinished();
	void on_timout();
};
