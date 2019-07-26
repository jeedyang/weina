#include "panel.h"

Panel::Panel(int ID, QWidget* parent)
	: id(ID)
	,QWidget(parent)
{
	ui.setupUi(this);
	initForm();

}

Panel::~Panel()
{
}

void Panel::setRes(int res)
{
	float f = res / 1000.00;
	ui.labelResValue->setText(QString("%1").arg(f));
}

void Panel::setHotRes(int res)
{
	ui.labelHotResValue->setText(QString::number(res));
}

void Panel::setHotButtonState(bool state)
{
	ui.pushButton->setChecked(state);
}

void Panel::getHotButtonState(bool& state)
{
	state = ui.pushButton->isChecked();
}


void Panel::setHotResDipEnabled(bool en)
{
	ui.labelHotRes->setEnabled(en);
	ui.labelHotResValue->setEnabled(en);
}

void Panel::setResDipEnabled(bool en)
{
	ui.labelRes->setEnabled(en);
	ui.labelResValue->setEnabled(en);
}

void Panel::setHotButtonEnabled(bool en)
{
	ui.pushButton->setEnabled(en);
}

void Panel::initForm()
{
	QObject::connect(ui.pushButton,SIGNAL(clicked(bool)),this,SLOT(onButtonClicked(bool)));
	ui.labelResValue->setText(_tr("------"));
	ui.labelHotResValue->setText(_tr("------"));
}

void Panel::onButtonClicked(bool checked)
{
	if (checked)
	{
		ui.pushButton->setText(_tr("加热开"));		
	}
	else
	{
		ui.pushButton->setText(_tr("加热关"));
	}
	emit buttonClicked(id, checked);
}