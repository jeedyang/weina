#pragma once

#include <QWidget>
#include <QFileSystemModel>
#include "ui_reportwidget.h"

class ReportWidget : public QWidget
{
	Q_OBJECT

public:
	ReportWidget(QWidget *parent = Q_NULLPTR);
	~ReportWidget();

private:
	Ui::ReportWidget ui;
	QFileSystemModel *model;
private slots:
	void openReportFile(QModelIndex index);
};
