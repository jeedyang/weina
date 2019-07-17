#include "homewidget.h"
#include <QDebug>
#include <QLibrary>

HomeWidget::HomeWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	QLibrary lib("CtrlPanel.dll");
	typedef CtrlPanelBase* (*pFunc)(int, QWidget*);
	pFunc func = (pFunc)lib.resolve("createInstance");
	if (!func) {
		qDebug() << "error";
	}
	else
	{
		m_panel_widget = func(1, ui.widget_panel);
		QObject::connect(m_panel_widget, SIGNAL(hotButtonClicked(int, bool)), this, SLOT(onHotButtonCilcked(int, bool)));
		int resArry[24] = {};
		for (int i = 0; i < 24; i++)
		{
			resArry[i] = i * 1000000;
		}
		m_panel_widget->setRes(resArry);
		m_panel_widget->setHotResDipEnabled(false);
		m_panel_widget->showMaximized();
		m_panelLaylot.addWidget(m_panel_widget);
		ui.widget_panel->setLayout(&m_panelLaylot);
	}

}

HomeWidget::~HomeWidget()
{
}
