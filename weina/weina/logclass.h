#pragma once

#include <QObject>
#include <QFile>
#include <QDir>


class logClass : public QObject
{
	Q_OBJECT

public:
	logClass();
	~logClass();
	static void add_Data_to_log(QString logData);
	static QStringList indexfolder(QString path);
	static void log_init();
	static QStringList logTimeData;
	static QStringList MMData;

private:
	static void Get_MMData();
};
