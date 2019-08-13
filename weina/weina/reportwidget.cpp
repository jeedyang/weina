#include "reportwidget.h"
#include <Windows.h>

#define _wtr(str) QString(str).toStdWString().c_str()
#define _tr(str) QString::fromLocal8Bit(str)

ReportWidget::ReportWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	model = new QFileSystemModel(this); //QFileSystemModel提供单独线程，推荐使用
	//model->setRootPath(QDir::currentPath()); //设置根目录
	QString path = QDir::currentPath() + "/report";
	model->setRootPath(path); //设置根目录
	ui.treeView->setModel(model); //设置数据模型
	ui.treeView->setRootIndex(model->index(QDir::currentPath() + "/report"));
	//信号与槽关联，treeView单击时，其目录设置为listView和tableView的根节点
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
	//ShellExecute(NULL, _wtr("open"), _wtr("E:/Work/weina/V2/电气清单.xls"), NULL, NULL, SW_SHOWNORMAL);
}
