#include "debugwidget.h"

DebugWidget::DebugWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
	hide();
}

DebugWidget::~DebugWidget()
{
}

void DebugWidget::showDialog()
{
	//this->setModal(true);
	this->show();
}