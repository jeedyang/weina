#include "reportwidget.h"
#include <Windows.h>

#define _wtr(str) QString(str).toStdWString().c_str()
#define _tr(str) QString::fromLocal8Bit(str)

ReportWidget::ReportWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	model = new QFileSystemModel(this); //QFileSystemModel�ṩ�����̣߳��Ƽ�ʹ��
	//model->setRootPath(QDir::currentPath()); //���ø�Ŀ¼
	QString path = QDir::currentPath() + "/report";
	model->setRootPath(path); //���ø�Ŀ¼
	ui.treeView->setModel(model); //��������ģ��
	ui.treeView->setRootIndex(model->index(QDir::currentPath() + "/report"));
	//�ź���۹�����treeView����ʱ����Ŀ¼����ΪlistView��tableView�ĸ��ڵ�
	connect(ui.treeView, SIGNAL(clicked(QModelIndex)),this, SLOT(openReportFile(QModelIndex)));
	//connect(ui->treeView, SIGNAL(clicked(QModelIndex)),
	//	ui->tableView, SLOT(setRootIndex(QModelIndex)));
}

ReportWidget::~ReportWidget()
{
}

void ReportWidget::openReportFile(QModelIndex index)
{
	QString fileFullName =model->filePath(index);
	//QString fileName= model->fileName(index);
	//QString fileFullName = filePath.append(fileName);
	QString typrName = fileFullName.right(5);
	if (typrName!=_tr(".xlsx"))
	{
		return;
	}
	system(fileFullName.toLocal8Bit().data());
	//ShellExecute(NULL, _wtr("open"), _wtr("E:/Work/weina/V2/�����嵥.xls"), NULL, NULL, SW_SHOWNORMAL);
}
