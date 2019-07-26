#include "homewidget.h"
#include <QDebug>
#include <QLibrary>

HomeWidget::HomeWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_serialPortNameList.append(_tr("COM5"));
	m_serialPortNameList.append(_tr("COM6"));
	m_serialPortNameList.append(_tr("COM7"));
	m_serialPortNameList.append(_tr("COM8"));
	QLibrary lib("CtrlPanel.dll");
	typedef CtrlPanelBase* (*pFunc)(int, QWidget*);
	pFunc func = (pFunc)lib.resolve("createInstance");
	if (!func) {
		qDebug() << "error";
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			m_panel_widget[i] = func(1, this);
			//int resArry[24] = {};
			//for (int i = 0; i < 24; i++)
			//{
			//	resArry[i] = i * 1000000;
			//}
			//m_panel_widget[i]->setRes(resArry);
			//m_panel_widget[i]->setHotResDipEnabled(false);
			//m_panel_widget[i]->showMaximized();

			m_panel_widget[i]->setID(i);

			m_panelLaylot[i] = new QGridLayout();
			m_panelLaylot[i]->addWidget(m_panel_widget[i]);
			ui.stackedWidget->widget(i)->setLayout(m_panelLaylot[i]);

			int a;
			resModArry[i] = new ResTestmod(this);
			resModArry[i]->setCtrlPanelWidget(m_panel_widget[i]);
			resModArry[i]->setPortName(m_serialPortNameList[i]);
			a = resModArry[i]->connectMod();
			if (!a)
			{
				resModArry[i]->readStart();
				//resModArry[i]->getRealyStaus();
			}
			QObject::connect(m_panel_widget[i], SIGNAL(hotButtonClicked(int, bool)), resModArry[i], SLOT(on_HotButtonCilcked(int, bool)));

		}

	}

	m_btnGroup.addButton(ui.pushButton_mod0, 0);
	m_btnGroup.addButton(ui.pushButton_mod1, 1);
	m_btnGroup.addButton(ui.pushButton_mod2, 2);
	m_btnGroup.addButton(ui.pushButton_mod3, 3);

	QObject::connect(&m_btnGroup, SIGNAL(buttonToggled(QAbstractButton*, bool)), this, SLOT(on_btnGroupToggled(QAbstractButton*, bool)));
	ui.stackedWidget->setCurrentIndex(0);

}

HomeWidget::~HomeWidget()
{
}


void HomeWidget::on_btnGroupToggled(QAbstractButton* button, bool checked)
{
	for (int i = 0; i < m_btnGroup.buttons().size(); i++)
	{
		QAbstractButton* btn = m_btnGroup.buttons()[i];
		if (btn != button)
		{
			button->setChecked(false);
		}
	}
	int id = m_btnGroup.id(button);
	ui.stackedWidget->setCurrentIndex(id);
	switch (id)
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	default:
		break;
	}
}