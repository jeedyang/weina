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
	QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(on_timeout()));
	QList<QPushButton*> btnList;
	QList<QDoubleSpinBox*> dspboxList;
	btnList =ui.tabWidget->widget(0)->findChildren<QPushButton*>();
	dspboxList = ui.tabWidget->widget(0)->findChildren<QDoubleSpinBox*>();
	
	for (int i = 0; i < btnList.size(); i++)
	{
		QString name = btnList[i]->objectName();
		QPushButton* btn = qobject_cast<QPushButton*>(btnList[i]);
		if (name=="pushButton_xJog_l"|| name == "pushButton_xJog_r" || name == "pushButton_yJog_up" || name == "pushButton_yJog_done")
		{
			QObject::connect(btn, SIGNAL(pressed()), this, SLOT(on_servoButtonPressed()));
			QObject::connect(btn, SIGNAL(released()), this, SLOT(on_servoButtonReleased()));
		}
		else
		{
			QObject::connect(btn, SIGNAL(clicked(bool)), this, SLOT(on_servoButtonClicked(bool)));
		}
			
	}
	for (int i = 0; i < dspboxList.size(); i++)
	{
		QString name = dspboxList[i]->objectName();
		QObject::connect(dspboxList[i], SIGNAL(editingFinished()), this, SLOT(on_servoDspEditingFinished()));
	}
}

DebugWidget::~DebugWidget()
{
}

void DebugWidget::refreshServoWidget()
{
	
}

void DebugWidget::refreshCylinderWidget()
{
}

void DebugWidget::refreshIOmapWidget()
{
}

void DebugWidget::showDialog()
{
	//this->setModal(true);
	this->show();
	timer.start(100);
}

void DebugWidget::on_servoButtonClicked(bool checked)
{
	auto plc = PLC::PlcStation::Instance();
	QPushButton* btn = (QPushButton*)sender();
	if (btn)
	{		
		int byteNum = 0;
		int bitNum = 0;
		QString objname = btn->objectName();
		if (objname == _tr("pushButton_xGoto")) {
			byteNum = 11;
			bitNum = 0;
		}		// M 11.0	X轴绝对定位开始
		else if (objname == _tr("pushButton_yGoto")) {
			byteNum = 11;
			bitNum = 1;
		}		// M 11.1	Y轴绝对定位开始
		else if (objname == _tr("pushButton_xHome")) {
			byteNum = 10;
			bitNum = 0;
		}		// M 10.0	X轴回原点
		else if (objname == _tr("pushButton_yHome")) {
			byteNum = 10;
			bitNum = 1;
		}		// M 10.1	Y轴回原点
		else if (objname == _tr("pushButton_xRest")) {
			byteNum = 10;
			bitNum = 2;
		}		// M 10.2	X轴复位
		else if (objname == _tr("pushButton_yRest")) {
			byteNum = 10;
			bitNum = 3;
		}		// M 10.3	Y轴复位
		else
			return;
		int a = plc->writeBool(AreaM,0,byteNum,bitNum,true);
		qDebug() << objname << _tr(" 点击 ! PLC return:") << a;
		array<char, 120> text;
		plc->errorText(a, text.data(), text.size());
		qDebug() << text.data();
	}
}

void DebugWidget::on_servoButtonPressed()
{
	auto plc = PLC::PlcStation::Instance();
	QPushButton* btn = (QPushButton*)sender();
	if (btn)
	{
		int byteNum = 0;
		int bitNum = 0;
		QString objname = btn->objectName();
		if (objname == _tr("pushButton_xJog_l")) {
			byteNum = 10;
			bitNum = 4;
		}			// M 10.4	X轴点动左移
		else if (objname == _tr("pushButton_xJog_r")) {
			byteNum = 10;
			bitNum = 5;
		}		// M 10.5	X轴点动右移
		else if (objname == _tr("pushButton_yJog_up")) {
			byteNum = 10;
			bitNum = 6;
		}		// M 10.6	Y轴点动上移
		else if (objname == _tr("pushButton_yJog_done")) {
			byteNum = 10;
			bitNum = 7;
		}	// M 10.7	Y轴点动下移
		else
			return;
		int a = plc->writeBool(AreaM, 0, byteNum, bitNum, true);
		qDebug() << objname << _tr(" 按下 ! PLC return:") << a;
		array<char, 120> text;
		plc->errorText(a, text.data(), text.size());
		qDebug() << text.data();
	}
}

void DebugWidget::on_servoButtonReleased()
{
	auto plc = PLC::PlcStation::Instance();
	QPushButton* btn = (QPushButton*)sender();
	if (btn)
	{
		int byteNum = 0;
		int bitNum = 0;
		QString objname = btn->objectName();
		if (objname == _tr("pushButton_xJog_l")) {
			byteNum = 10;
			bitNum = 4;
		}			// M 10.4	X轴点动左移
		else if (objname == _tr("pushButton_xJog_r")) {
			byteNum = 10;
			bitNum = 5;
		}		// M 10.5	X轴点动右移
		else if (objname == _tr("pushButton_yJog_up")) {
			byteNum = 10;
			bitNum = 6;
		}		// M 10.6	Y轴点动上移
		else if (objname == _tr("pushButton_yJog_done")) {
			byteNum = 10;
			bitNum = 7;
		}	// M 10.7	Y轴点动下移
		else
			return;
		int a = plc->writeBool(AreaM, 0, byteNum, bitNum, false);
		qDebug() << objname << _tr(" 松开 ! PLC return:") << a;		
		array<char, 120> text;
		plc->errorText(a, text.data(), text.size());
		qDebug() << text.data();
	}
}

void DebugWidget::on_servoDspEditingFinished()
{
	auto plc = PLC::PlcStation::Instance();
	QDoubleSpinBox* dspBox = (QDoubleSpinBox*)sender();
	QString objname = dspBox->objectName();
	int byteNum = 0;
	if (objname == _tr("doubleSpinBox_xJog_speed")) {		// 
		byteNum = 0;
	}
	else if (objname == _tr("doubleSpinBox_xJog_speed")) {
		byteNum = 0;
	}
	else if (objname == _tr("doubleSpinBox_yJog_speed")) {
		byteNum = 0;
	}
	else if (objname == _tr("doubleSpinBox_xPos_set")) {
		byteNum = 0;
	}
	else if (objname == _tr("doubleSpinBox_yPos_set")) {
		byteNum = 0;
	}
	else
		return;
	int a=plc->writeFloat(AreaDB,1, byteNum,dspBox->value());
	qDebug() << objname << " EditingFinished ! PLC return:" << a;
	array<char, 120> text;
	plc->errorText(a,text.data(),text.size());
	qDebug() << text.data();
}

void DebugWidget::on_timeout()
{
	int index= ui.tabWidget->currentIndex();
	if (index==0){
		
	}
	else if(index == 1){
		 
	}
	else if (index == 2) {

	}
}

