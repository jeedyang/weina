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
public slots:
	void showDialog();
};
