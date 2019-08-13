#include "logclass.h"
#include <QDebug>
#include <QDateTime>

QStringList logClass::logTimeData;
QStringList logClass::MMData;

logClass::logClass()
{
}

logClass::~logClass()
{
}

void logClass::add_Data_to_log(QString logData)
{
	QDateTime datetime;
	QString path = QDir::currentPath() + "/log/" + datetime.currentDateTime().toString("yyyy-MM")+"/"+ datetime.currentDateTime().toString("yyyy-MM-dd")+".log";
	QFile log(path);
	if (!log.open(QIODevice::WriteOnly | QIODevice::Append| QIODevice::Text))
	{
		qDebug() << "open log error";
	}
	QTextStream stream(&log);
	//char* str = logData.toLocal8Bit().data();
	//char* str = logData.toStdString;
	QByteArray logtime = datetime.currentDateTime().toString("MM-dd hh:mm:ss").toLocal8Bit();
	stream << datetime.currentDateTime().toString("MM-dd hh:mm:ss")<<":"<<"" << logData<<endl ;
	log.close();
}

QStringList logClass::indexfolder(QString logfolder)
{
	QString path = QDir::currentPath() + "/log/" + logfolder;
	QDir dir(path);
	QStringList filters;
	filters << QString("*.log");
	dir.setFilter(QDir::Files | QDir::NoSymLinks); //设置类型过滤器，只为文件格式
	dir.setNameFilters(filters);  //设置文件名称过滤器，只为filters格式
	QStringList string_list;
	for (int i = 0; i< dir.count(); i++)
	{
		QString strtemp;
		QString file_name = dir[i];  //文件名称
		file_name = file_name.mid(0, file_name.size() - 4);
		string_list.append(file_name);
	}
	return string_list;
}

void logClass::Get_MMData()
{
	QString path = QDir::currentPath() + "/log/";
	QDir dir(path);
	QStringList folder;
	QFileInfoList folder_list = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
	QString strtemp;
	for (int i=0; i != folder_list.size(); i++)
	{
		strtemp = folder_list.at(i).absoluteFilePath();
		
		strtemp = strtemp.mid(strtemp.size()-7, strtemp.size());
		folder.append(strtemp);
	}
	MMData = folder;
}

void logClass::log_init()
{
	Get_MMData();

	QDateTime datetime;
	QString path = QDir::currentPath() + "/log/" + datetime.currentDateTime().toString("yyyy-MM");
	QDir dir(path);
	if (!dir.exists())
	{
		dir.mkdir(path);
	}



	QStringList filters;
	filters << QString("*.log");
	dir.setFilter(QDir::Files | QDir::NoSymLinks); //设置类型过滤器，只为文件格式
	dir.setNameFilters(filters);  //设置文件名称过滤器，只为filters格式
	QStringList string_list;

	QString today = datetime.currentDateTime().toString("yyyy-MM-dd");
	bool temp = true;
	//qDebug()<<datetime.currentDateTime().toString("yyyy-MM-dd");
	for (int i = 0; i< dir.count(); i++)
	{

		QString strtemp;
		QString file_name = dir[i];  //文件名称
		qDebug() << dir[i];
		file_name = file_name.mid(0, file_name.size()-4 );
		string_list.append(file_name);
		if (dir[i] == today+".log")
		{
			temp = false;
		}

	}
	if (temp)
	{
		QFile logfile(path + "/" + today + ".log");
		logfile.open(QIODevice::ReadWrite | QIODevice::Text);
		logfile.close();
		logTimeData.append(today);
	}
	logTimeData = string_list;
	
}

