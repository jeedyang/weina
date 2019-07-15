#include "debugwidget.h"

DebugWidget::DebugWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

DebugWidget::~DebugWidget()
{
}

void DebugWidget::showDialog()
{
	//this->setModal(true);
	this->show();
}