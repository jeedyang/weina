#include "logwidget.h"
#include <QTableView>
#include <QStandardItemModel>
#include <qstringlistmodel.h>
#include "logclass.h"
#include <QDir>
#include <QDebug>

#define _tr(str) QString::fromLocal8Bit(str)

LogWidget::LogWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	logClass::log_init();
	logClass::add_Data_to_log(_tr("进入系统。"));
	QObject::connect(ui.listView_month,SIGNAL(clicked(QModelIndex)),this,SLOT(on_listView_monthClicked(QModelIndex)));
	QObject::connect(ui.listView_date, SIGNAL(clicked(QModelIndex)), this, SLOT(on_listView_dateClicked(QModelIndex)));
	QStringListModel* model = new QStringListModel(logClass::MMData);
	ui.listView_month->setModel(model);
}

LogWidget::~LogWidget()
{
}

void LogWidget::on_listView_monthClicked(QModelIndex index)
{
	QString temp;
	temp = index.data().toString();
	QStringList loglist;
	loglist = logClass::indexfolder(temp);

	QStringListModel* model = new QStringListModel(loglist);
	ui.listView_date->setModel(model);
}

void LogWidget::on_listView_dateClicked(QModelIndex index)
{
	QString temp;
	temp = index.data().toString();
	QString path = QDir::currentPath() + "/log/" + temp.mid(0, 7) + "/" + temp + ".log";
	QFile log(path);
	if (!log.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		qDebug() << "open log error";
	}
	QTextStream stream(&log);
	ui.textEdit_details->setText(stream.readAll());
	log.close();
	QApplication::restoreOverrideCursor();
}
