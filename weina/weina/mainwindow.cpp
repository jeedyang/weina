#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	initForm();
	QObject::connect(&m_btnGroup,SIGNAL(buttonToggled(QAbstractButton * , bool )),this,SLOT(on_btnGroupToggled(QAbstractButton*, bool)));
}

void MainWindow::on_btnGroupToggled(QAbstractButton* button, bool checked)
{
	for (int i = 0; i < m_btnGroup.buttons().size(); i++)
	{
		QAbstractButton* btn= m_btnGroup.buttons()[i];
		if (btn!=button)
		{
			button->setChecked(false);
		}	
	}
	int id = m_btnGroup.id(button);
	switch (id)
	{
	case 0:
		showWidget(ui.widget_main,m_debug_widget);
		break;
	case 1:
		showWidget(ui.widget_main, m_setup_widget);
		break;
	case 2:
		showWidget(ui.widget_main, m_debug_widget);
		break;
	default:
		break;
	}
}

void MainWindow::initForm()
{
	m_btnGroup.addButton(ui.pushButton_main,0);
	m_btnGroup.addButton(ui.pushButton_setup, 1);
	m_btnGroup.addButton(ui.pushButton_debug, 2);
}

void MainWindow::showWidget(QWidget* parent, QWidget* children)
{
	QObjectList widgetList = ui.widget_main->children();
	QLayoutItem* child;
	while ((child = m_hLayout->takeAt(0)) != 0)
	{
		//setParent为NULL，防止删除之后界面不消失
		if (child->widget())
		{
			child->widget()->setParent(NULL);
			child->widget()->hide();
		}

		delete child;
	}
	m_hLayout->addWidget(children, 0);
	children->setParent(parent);
	children->show();
	ui.widget_main->setLayout(m_hLayout);
}
