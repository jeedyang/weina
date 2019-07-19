#pragma once

#include <QWidget>
#include "ui_debugwidget.h"
#include <QTimer>
#include "plcstation.h"

class DebugWidget : public QWidget
{
	Q_OBJECT

public:
	DebugWidget(QWidget *parent = Q_NULLPTR);
	~DebugWidget();

private:
	void refreshServoWidget();
	void refreshMbuttonWidget();
	void refreshIOmapWidget();
	Ui::DebugWidget ui;
	QTimer timer;
	PlcData m_lastPlcdata;
	QMap<int, QPushButton*> m_btnMap_M;
	QMap<int, QAbstractSpinBox*> m_spinBoxMap_DB;
	QMap<int, QPushButton*> m_btnMap_Q;
	QMap<int, QLabel*> m_labMap_I;
	QMap<int, QLabel*> m_labMap_DB;
public slots:
	void showDialog();
	void on_mButtonClicked(bool checked);
	void on_mButtonPressed();
	void on_mButtonReleased();
	void on_spinEditingFinished();
	void on_ioMapButtonClicked(bool checked);
	void on_timeout();
};
