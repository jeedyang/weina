#include "ctrlpanel.h"
#include <QDebug>

CtrlPanel::CtrlPanel(int ID, QWidget* parent)
	:CtrlPanelBase(parent)
{
	ui.setupUi(this);
	initForm();
}

CtrlPanel::~CtrlPanel()
{
	qDebug()<<_tr("CtrlPanelÎö¹¹º¯ÊýÖ´ÐÐ.");
}

void CtrlPanel::setRes(int* resArray)
{
	for (int i = 0; i < 24; i++)
	{
		panelList[i]->setRes(resArray[i]);
	}
}

void CtrlPanel::setHotRes(int* resArray)
{
	for (int i = 0; i < 24; i++)
	{
		panelList[i]->setHotRes(resArray[i]);
	}
}

void CtrlPanel::setHotButtonState(bool* stateArray)
{
	for (int i = 0; i < 24; i++)
	{
		panelList[i]->setHotButtonState(stateArray[i]);
	}
}

void CtrlPanel::getHotButtonState(bool* stateArray)
{
	for (int i = 0; i < 24; i++)
	{
		panelList[i]->getHotButtonState(stateArray[i]);
	}
}

void CtrlPanel::setHotVoltage(double* voltArray)
{
	for (int i = 0; i < 24; i++)
	{
		panelList[i]->setHotVoltage(voltArray[i]);
	}
}

void CtrlPanel::setHotVolDipEnabled(bool en)
{
	for (int i = 0; i < 24; i++)
	{
		panelList[i]->setHotVolDipEnabled(en);
	}
}

void CtrlPanel::setHotResDipEnabled(bool en)
{
	for (int i = 0; i < 24; i++)
	{
		panelList[i]->setHotResDipEnabled(en);
	}
}

void CtrlPanel::setResDipEnabled(bool en)
{
	for (int i = 0; i < 24; i++)
	{
		panelList[i]->setResDipEnabled(en);
	}
}

void CtrlPanel::setHotButtonEnabled(bool en)
{
	for (int i = 0; i < 24; i++)
	{
		panelList[i]->setHotButtonEnabled(en);
	}
}

void CtrlPanel::initForm()
{
	//setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
	//hide();
	for (int i = 0; i < 24; i++)
	{
		Panel* p = new Panel(i,this);
		QObject::connect(p,SIGNAL(buttonClicked(int, bool)),this,SLOT(onPanelHotButtonClicked(int,bool)));
		panelLayout.addWidget(p, i / 4, i % 4);
		panelList.append(p);
	}
	ui.widget->setLayout(&panelLayout);

	panelLayout.setMargin(2);
	panelLayout.setSpacing(2);
}

void CtrlPanel::onPanelHotButtonClicked(int id, bool checked)
{
	
	emit hotButtonClicked(id,checked);
}

CTRLPANEL_API CtrlPanel* createInstance(int ID, QWidget* parent)
{
	return new CtrlPanel(ID,parent);
}

