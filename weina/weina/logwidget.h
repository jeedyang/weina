#pragma once

#include <QWidget>
#include "ui_logwidget.h"

class LogWidget : public QWidget
{
	Q_OBJECT

public:
	LogWidget(QWidget *parent = Q_NULLPTR);
	~LogWidget();

private:
	Ui::LogWidget ui;
private slots:
	void on_listView_monthClicked(QModelIndex index);
	void on_listView_dateClicked(QModelIndex index);
};
