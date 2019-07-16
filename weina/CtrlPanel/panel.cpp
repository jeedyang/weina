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
	ui.labelResValue->setText(QString::number(res));
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

void Panel::setHotVoltage(double volt)
{
	ui.labelHotVolValue->setText(QString::number(volt));
}

void Panel::setHotVolDipEnabled(bool en)
{
	ui.labelHotVol->setEnabled(en);
	ui.labelHotVolValue->setEnabled(en);
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
	ui.labelHotVolValue->setText(_tr("------"));

}

void Panel::onButtonClicked(bool checked)
{
	if (checked)
	{
		ui.pushButton->setText(_tr("���ȿ�"));		
	}
	else
	{
		ui.pushButton->setText(_tr("���ȹ�"));
	}
	emit buttonClicked(id, checked);
}