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
	QList<QPushButton*> btnServoList;
	QList<QPushButton*> btnCylinderList;
	QList<QDoubleSpinBox*> dspboxList;
	QList<QPushButton*> btnIoMapList;
	btnServoList =ui.tabWidget->widget(0)->findChildren<QPushButton*>();
	dspboxList = ui.tabWidget->widget(0)->findChildren<QDoubleSpinBox*>();
	btnCylinderList= ui.tabWidget->widget(1)->findChildren<QPushButton*>();
	btnIoMapList = ui.tabWidget->widget(2)->findChildren<QPushButton*>();
	for (int i = 0; i < btnServoList.size(); i++)
	{
		QString name = btnServoList[i]->objectName();
		QPushButton* btn = qobject_cast<QPushButton*>(btnServoList[i]);
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

	for (int i = 0; i < btnCylinderList.size(); i++)
	{
		QObject::connect(btnCylinderList[i], SIGNAL(clicked()), this, SLOT(on_cylinderButtonClicked()));
	}

	QList<QLabel*> labList = ui.tabWidget->findChildren<QLabel*>();
	for (int i = 0; i < labList.size(); i++)
	{
		auto objName = labList[i]->objectName();
		if (objName[0] == _tr("i"))
		{
			objName.remove(0,1);
			m_labMap_I[objName.toInt()] = labList[i];
		}
	}

	QList<QPushButton*> btnList = ui.tabWidget->findChildren<QPushButton*>();
	for (int i = 0; i < btnList.size(); i++)
	{
		auto objName = btnList[i]->objectName();
		if (objName[0] == _tr("q"))
		{
			objName.remove(0, 1);
			m_btnMap_Q[objName.toInt()] = btnList[i];
		}
		else if(objName[0] == _tr("m"))
		{
			objName.remove(0, 1);
			m_btnMap_M[objName.toInt()] = btnList[i];
		}
	}

	QList<QAbstractSpinBox*> spinBoxList = ui.tabWidget->findChildren<QAbstractSpinBox*>();
	for (int i = 0; i < spinBoxList.size(); i++)
	{
		auto objName = spinBoxList[i]->objectName();
		if (objName[0] == _tr("db"))
		{
			objName.remove(0, 2);
			m_spinBoxMap_DB[objName.toInt()] = spinBoxList[i];
			QObject::connect(spinBoxList[i], SIGNAL(editingFinished()), this, SLOT(on_spinEditingFinished()));
		}
	}

	QMap<int, QLabel*>::iterator it_I;
	for (it_I = m_labMap_I.begin(); it_I != m_labMap_I.end();it_I++)
	{
		m_labMap_I[it_I.key()]->setMaximumSize(34, 32);
		m_labMap_I[it_I.key()]->setMinimumSize(34, 32);
		m_labMap_I[it_I.key()]->setScaledContents(true);
	}

	QMap<int, QPushButton*>::iterator it_Q;
	for (it_Q = m_btnMap_Q.begin(); it_Q != m_btnMap_Q.end(); it_Q++)
	{
		m_btnMap_Q[it_Q.key()]->setMaximumSize(80, 32);
		m_btnMap_Q[it_Q.key()]->setMinimumSize(80, 32);
		QObject::connect(m_btnMap_Q[it_Q.key()], SIGNAL(clicked(bool)), this, SLOT(on_ioMapButtonClicked(bool)));
	}

	//QList<QLabel*> labList_I = ui.groupBox_I->findChildren<QLabel*>();
	//for (int i = 0; i < labList_I.size(); i++)
	//{
	//	auto objName = labList_I[i]->objectName();
	//	if (objName[0]==_tr("i"))
	//	{
	//		labList_I[i]->setMaximumSize(34, 32);
	//		labList_I[i]->setMinimumSize(34, 32);
	//		labList_I[i]->setScaledContents(true);
	//	}		
	//}

	//QList<QPushButton*> btnList_Q = ui.groupBox_Q->findChildren<QPushButton*>();
	//for (int i = 0; i < btnList_Q.size(); i++)
	//{
	//	auto objName = btnList_Q[i]->objectName();
	//	if (objName[0] == _tr("q"))
	//	{
	//		btnList_Q[i]->setMaximumSize(80, 32);
	//		btnList_Q[i]->setMinimumSize(80, 32);
	//	}
	//}

	timer.start(400);
	qCritical() << "666";
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
	auto plc = PLC::PlcStation::Instance();
	for (int i = 0; i < plc->plcData.Q.size(); i++)
	{
		QString btnName = "q";
		btnName.append(QString::number(i));
		//qDebug() << btnName;
		QPushButton* btnQ = ui.tabWidget->widget(2)->findChild<QPushButton*>(btnName);
		if (btnQ)
		{
			//qDebug() << btnQ->objectName();
			btnQ->setChecked(plc->plcData.Q[i]);
		}	
	}

	for (int i = 0; i < plc->plcData.I.size(); i++)
	{
		QString labName = "i";
		labName.append(QString::number(i));
		//qDebug() << labName;
		QLabel* labI = ui.tabWidget->widget(2)->findChild<QLabel*>(labName);
		if (labI)
		{
			//qDebug() << labI->objectName();
			if (plc->plcData.I[i])
			{
				labI->setPixmap(QPixmap(":/png/res/png/led_on.png"));
			}
			else
			{
				labI->setPixmap(QPixmap(":/png/res/png/led_off.png"));
			}
		}
	}


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

void DebugWidget::on_spinEditingFinished()
{
	auto plc = PLC::PlcStation::Instance();
	QAbstractSpinBox* senderBox = (QAbstractSpinBox*)sender();

	if (senderBox->inherits("QDoubleSpinBox"))
	{
		auto spinBox = (QDoubleSpinBox*)senderBox;
		auto key= m_spinBoxMap_DB.key(spinBox,-1);
		if (key == -1)
		{

		}
	}
	else if(senderBox->inherits("QSpinBox"))
	{
		auto spinBox = (QSpinBox*)senderBox;
	}


	QString objname = senderBox->objectName();
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
	//int a=plc->writeFloat(AreaDB,1, byteNum, senderBox->value());
	//qDebug() << objname << " EditingFinished ! PLC return:" << a;
	array<char, 120> text;
	//plc->errorText(a,text.data(),text.size());
	qDebug() << text.data();
}

void DebugWidget::on_cylinderButtonClicked()
{
	auto plc = PLC::PlcStation::Instance();
	QPushButton* btn = (QPushButton*)sender();
	if (btn)
	{
		int byteNum = 0;
		int bitNum = 0;
		QString objname = btn->objectName();
		QRegExp rx(tr("[^m_]"));
		int pos(0);
		QStringList strList;
		while ((pos = rx.indexIn(objname, pos)) != -1)
		{
			strList.push_back(rx.capturedTexts().at(0));
			pos += rx.matchedLength();
		}
		
		QString byteStr="";
		for (int i = 0; i < strList.size()-1; i++)
		{
			byteStr.append(strList[i]);
		}
		byteNum = byteStr.toInt();
		bitNum = strList.last().toInt();
		int a = plc->writeBool(AreaM, 0, byteNum, bitNum, true);
		qDebug() << __FUNCTION__ <<__FILE__<<__LINE__<< objname << _tr(" ! PLC return:") << a;
		array<char, 120> text;
		plc->errorText(a, text.data(), text.size());
		qDebug() << text.data();
	}
}

void DebugWidget::on_ioMapButtonClicked(bool checked)
{
	auto plc = PLC::PlcStation::Instance();
	QPushButton* btn = (QPushButton*)sender();
	if (btn)
	{
		int byteNum = 0;
		int bitNum = 0;
		QString objname = btn->objectName();
		QRegExp rx(tr("[^q]"));
		int pos(0);
		QStringList strList;
		while ((pos = rx.indexIn(objname, pos)) != -1)
		{
			strList.push_back(rx.capturedTexts().at(0));
			pos += rx.matchedLength();
		}

		QString addrStr = "";
		int addrNum=800;
		for (int i = 0; i < strList.size(); i++)
		{
			addrStr.append(strList[i]);
		}
		addrNum = addrStr.toInt();

		byteNum = addrNum / 8;
		bitNum = addrNum%8;
		int a = plc->writeBool(AreaQ, 0, byteNum, bitNum, checked);
		qDebug() << __FUNCTION__ << __FILE__ << __LINE__ << objname << _tr(" ! PLC return:") << a;
		array<char, 120> text;
		plc->errorText(a, text.data(), text.size());
		qDebug() << text.data();
	}
}

void DebugWidget::on_timeout()
{
	auto plc = PLC::PlcStation::Instance();
	qDebug() << plc->getValue(_tr("X轴运行速度"));
	qDebug() << plc->getValue(_tr("X轴点动速度"));
	qDebug() << plc->getValue(_tr("X轴当前位置"));
	qDebug() << plc->getValue(_tr("X轴剩余距离"));
	qDebug() << plc->getValue(_tr("X轴位置设置"));
	int index= ui.tabWidget->currentIndex();
	if (index==0){
		
	}
	else if(index == 1){
		 
	}
	else if (index == 2) {
		refreshIOmapWidget();
	}
}

