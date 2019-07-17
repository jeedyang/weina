#include "debugwidget.h"
#include "plcstation.h"
#include <QDebug>

#define _tr(str) QString::fromLocal8Bit(str)

DebugWidget::DebugWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
	hide();
	QList<QPushButton*> btnList;
	btnList =ui.tabWidget->widget(0)->findChildren<QPushButton*>();
	for (int i = 0; i < btnList.size(); i++)
	{
		QString name = btnList[i]->objectName();
		QPushButton* btn = qobject_cast<QPushButton*>(btnList[i]);
		if (btn)
			QObject::connect(btn,SIGNAL(clicked(bool)),this,SLOT(on_servoButtonClicked(bool)));
	}
}

DebugWidget::~DebugWidget()
{
}

void DebugWidget::showDialog()
{
	//this->setModal(true);
	this->show();
}

void DebugWidget::on_servoButtonClicked(bool checked)
{
	auto plc = PLC::getPlcInstance();
	QPushButton* btn = (QPushButton*)sender();
	if (btn)
	{
		
		int addr = 0;
		QString objname = btn->objectName();
		if (objname == _tr("pushButton_xJog_l"))			// M 10.4	X轴点动左移
			addr = 10 * 8 + 4;
		else if (objname == _tr("pushButton_xJog_r"))		// M 10.5	X轴点动右移
			addr = 10 * 8 + 5;
		else if (objname == _tr("pushButton_yJog_up"))		// M 10.6	Y轴点动上移
			addr = 10 * 8 + 6;
		else if (objname == _tr("pushButton_yJog_done"))	// M 10.7	Y轴点动下移
			addr = 10 * 8 + 7;
		else if (objname == _tr("pushButton_xGoto"))		// M 11.0	X轴绝对定位开始
			addr = 11 * 8 + 0;
		else if (objname == _tr("pushButton_yGoto"))		// M 11.1	Y轴绝对定位开始
			addr = 11 * 8 + 1;
		else if (objname == _tr("pushButton_xHome"))		// M 10.0	X轴回原点
			addr = 10 * 8 + 0;
		else if (objname == _tr("pushButton_yHome"))		// M 10.1	Y轴回原点
			addr = 10 * 8 + 1;
		else if (objname == _tr("pushButton_xRest"))		// M 10.2	X轴复位
			addr = 10 * 8 + 2;
		else if (objname == _tr("pushButton_yRest"))		// M 10.3	Y轴复位
			addr = 10 * 8 + 3;
		else
			return;
		
		int a=plc->WriteArea(S7AreaMK, 0,addr,1 ,S7WLByte, on);
		qDebug() << objname << " Clicked ! PLC return:" << a;
	}
}