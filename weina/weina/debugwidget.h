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
	QMap<int, QPushButton*> m_btnMap_M;
	QMap<int, QAbstractSpinBox*> m_spinBoxMap_DB;
	QMap<int, QPushButton*> m_btnMap_Q;
	QMap<int, QLabel*> m_labMap_I;
public slots:
	void showDialog();
	void on_servoButtonClicked(bool checked);
	void on_servoButtonPressed();
	void on_servoButtonReleased();
	void on_spinEditingFinished();
	void on_cylinderButtonClicked();
	void on_ioMapButtonClicked(bool checked);
	void on_timeout();
};
