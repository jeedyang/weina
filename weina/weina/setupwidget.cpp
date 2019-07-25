#include "setupwidget.h"


#define _tr(str) QString::fromLocal8Bit(str)


SetupWidget::SetupWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
	hide();
	ui.tableWidget_testPam->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableWidget_testPam->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectItems);
	ui.tableWidget_testPam->setColumnCount(3);
	ui.tableWidget_testPam->setRowCount(29);
	ui.tableWidget_testPam->setColumnWidth(1, 200);
	ui.tableWidget_testPam->setColumnWidth(2, 200);
	QStringList header;
	header.append(_tr("启用"));
	header.append(_tr("最小值"));
	header.append(_tr("最大值"));
	ui.tableWidget_testPam->setHorizontalHeaderLabels(header);

	for (int i = 0; i < 29; i++)
	{
		QCheckBox* checkbox = new QCheckBox();
		checkbox->setObjectName(_tr("checkbox_%1").arg(QString::number(i)));
		checkbox->setText(_tr(""));
		ui.tableWidget_testPam->setCellWidget(i, 0, checkbox);
	}
}

SetupWidget::~SetupWidget()
{
}
