#include "debugwidget.h"
#include <QDebug>

#define _tr(str) QString::fromLocal8Bit(str)

DebugWidget::DebugWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
	hide();
	QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(on_timeout()));

	//添加所有I label到Map中
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
	//添加所有DB label到Map中
	QList<QLabel*> labdbList = ui.tabWidget->findChildren<QLabel*>();
	for (int i = 0; i < labdbList.size(); i++)
	{
		auto objName = labdbList[i]->objectName();
		QString typeStr = objName.mid(0,2);
		if (typeStr == _tr("db"))
		{
			objName.remove(0, 2);
			m_labMap_DB[objName.toInt()] = labdbList[i];
		}
	}
	//添加所有的按钮到Map中,分M和Q
	QList<QPushButton*> btnList = ui.tabWidget->findChildren<QPushButton*>();
	for (int i = 0; i < btnList.size(); i++)
	{
		auto objName = btnList[i]->objectName();
		auto addrStr= btnList[i]->objectName().remove(0, 1);
		if (objName[0] == _tr("q"))
		{
			m_btnMap_Q[addrStr.toInt()] = btnList[i];
		}
		else if(objName[0] == _tr("m"))
		{
			m_btnMap_M[addrStr.toInt()] = btnList[i];
		}
	}
	//添加所有编辑框到Map中
	QList<QAbstractSpinBox*> spinBoxList = ui.tabWidget->findChildren<QAbstractSpinBox*>();
	for (int i = 0; i < spinBoxList.size(); i++)
	{
		QString objName = spinBoxList[i]->objectName();
		QString typeName = objName.mid(0, 2);
		if (typeName == _tr("db"))
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

	QMap<int, QPushButton*>::iterator it_M;
	for (it_M = m_btnMap_M.begin(); it_M != m_btnMap_M.end(); it_M++)
	{
		auto objName = m_btnMap_M[it_M.key()]->objectName();
		if (objName == "m84" || objName == "m85" || objName == "m86" || objName == "m87")
		{
			QObject::connect(m_btnMap_M[it_M.key()], SIGNAL(pressed()), this, SLOT(on_mButtonPressed()));
			QObject::connect(m_btnMap_M[it_M.key()], SIGNAL(released()), this, SLOT(on_mButtonReleased()));
		}
		else
		{
			m_btnMap_M[it_M.key()]->setCheckable(true);
			QObject::connect(m_btnMap_M[it_M.key()], SIGNAL(clicked(bool)), this, SLOT(on_mButtonClicked(bool)));
		}
	}
}

DebugWidget::~DebugWidget()
{
}

void DebugWidget::refreshSpinBox()
{
	auto plc = PLC::PlcStation::Instance();
	QMap<int, QAbstractSpinBox*>::iterator it;

	for (it = m_spinBoxMap_DB.begin(); it != m_spinBoxMap_DB.end(); it++)
	{
		QString objStr = m_spinBoxMap_DB[it.key()]->objectName();
		plcMemoryAddr addr = objStr.remove(0, 2).toInt();
		QVariant val = plc->getValue(addr);
		if (m_spinBoxMap_DB[it.key()]->inherits("QDoubleSpinBox"))
		{
			auto spinBox = (QDoubleSpinBox*)m_spinBoxMap_DB[it.key()];
			spinBox->setValue(val.toDouble());
		}
		else if (m_spinBoxMap_DB[it.key()]->inherits("QSpinBox"))
		{
			auto spinBox = (QSpinBox*)m_spinBoxMap_DB[it.key()];
			spinBox->setValue(val.toInt());
		}
	}
}

void DebugWidget::refreshServoWidget()
{
	auto plc = PLC::PlcStation::Instance();
	QMap<int, QLabel*>::iterator it_DB;
	for (it_DB = m_labMap_DB.begin(); it_DB != m_labMap_DB.end(); it_DB++)
	{
		QString objStr= m_labMap_DB[it_DB.key()]->objectName();
		plcMemoryAddr addr = objStr.remove(0, 2).toInt();
		QVariant val= plc->getValue(addr);
		if (val.type()==QVariant::Type::Double|| val.type() == 38)
		{
			m_labMap_DB[it_DB.key()]->setText(QString::number(val.toDouble()));
		}
		else if (val.type() == QVariant::Type::Int)
		{
			m_labMap_DB[it_DB.key()]->setText(QString::number(val.toInt()));
		}
		else
		{
			qErrOut() << _tr("未知类型!")<<val;
		}
	}

}

void DebugWidget::refreshMbuttonWidget()
{
	auto plc = PLC::PlcStation::Instance();
	QMap<int, QPushButton*>::iterator it_M;
	for (it_M = m_btnMap_M.begin(); it_M != m_btnMap_M.end(); it_M++)
	{
		m_btnMap_M[it_M.key()]->setChecked(plc->plcData.M[it_M.key()]);
	}
}

void DebugWidget::refreshIOmapWidget()
{
	auto plc = PLC::PlcStation::Instance();
	QMap<int, QPushButton*>::iterator it_Q;
	for (it_Q = m_btnMap_Q.begin(); it_Q != m_btnMap_Q.end(); it_Q++)
	{
		m_btnMap_Q[it_Q.key()]->setChecked(plc->plcData.Q[it_Q.key()]);
	}

	QMap<int, QLabel*>::iterator it_I;
	for (it_I = m_labMap_I.begin(); it_I != m_labMap_I.end(); it_I++)
	{
		if (plc->plcData.I[it_I.key()])
		{
			m_labMap_I[it_I.key()]->setPixmap(QPixmap(":/png/res/png/led_on.png"));
		}
		else
		{
			m_labMap_I[it_I.key()]->setPixmap(QPixmap(":/png/res/png/led_off.png"));
		}
	}
	
}

void DebugWidget::widgetShow()
{
	//this->setModal(true);
	this->show();
	refreshSpinBox();
	timer.start(100);
}

void DebugWidget::widgetHide()
{
	timer.stop();
}

void DebugWidget::on_mButtonClicked(bool checked)
{
	auto plc = PLC::PlcStation::Instance();
	QPushButton* btn = (QPushButton*)sender();
	auto addrStr = btn->objectName().remove(0, 1);
	int addr = addrStr.toInt();
	int byteNum = addr / 8;
	int bitNum = addr % 8;

	int a = plc->writeBool(AreaM,0,byteNum,bitNum, checked);
	qDebug() << btn->objectName() << _tr(" 点击 ! PLC return:") << a;
	if (a) {
		array<char, 120> text;
		plc->errorText(a, text.data(), text.size());
		qDebug() << text.data();
	}
}

void DebugWidget::on_mButtonPressed()
{
	auto plc = PLC::PlcStation::Instance();
	QPushButton* btn = (QPushButton*)sender();
	auto addrStr = btn->objectName().remove(0, 1);
	int addr = addrStr.toInt();
	int byteNum = addr / 8;
	int bitNum = addr % 8;

	int a = plc->writeBool(AreaM, 0, byteNum, bitNum, true);
	qDebug() << btn->objectName() << _tr(" 按下 ! PLC return:") << a;
	if (a) {
		array<char, 120> text;
		plc->errorText(a, text.data(), text.size());
		qDebug() << text.data();
	}
}

void DebugWidget::on_mButtonReleased()
{
	auto plc = PLC::PlcStation::Instance();
	QPushButton* btn = (QPushButton*)sender();
	auto addrStr = btn->objectName().remove(0, 1);
	int addr = addrStr.toInt();
	int byteNum = addr / 8;
	int bitNum = addr % 8;

	int a = plc->writeBool(AreaM, 0, byteNum, bitNum, false);
	qDebug() << btn->objectName() << _tr(" 松开 ! PLC return:") << a;
	if (a) {
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
			qErrOut() << _tr("错误:未在m_spinBoxMap_DB中发现") << spinBox->objectName();
			return;
		}
		plcMemoryAddr addr = spinBox->objectName().remove(0, 2).toInt();
		auto val = spinBox->value();
		int a=plc->setValue(addr, val);
		if (a)
		{
			array<char, 120> text;
			plc->errorText(a, text.data(), text.size());
			qDebug() << text.data();
		}
	}
	else if(senderBox->inherits("QSpinBox"))
	{
		auto spinBox = (QSpinBox*)senderBox;
		auto key = m_spinBoxMap_DB.key(spinBox, -1);
		if (key == -1)
		{
			qErrOut() << _tr("错误:未在m_spinBoxMap_DB中发现") << spinBox->objectName();
			return;
		}
		plcMemoryAddr addr = spinBox->objectName().remove(0, 2).toInt();
		auto val = spinBox->value();
		int a = plc->setValue(addr, val);
		if (a)
		{
			array<char, 120> text;
			plc->errorText(a, text.data(), text.size());
			qDebug() << text.data();
		}
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
	//auto plc = PLC::PlcStation::Instance();
	//qDebug() << plc->setValue(_tr("X轴运行速度"),11.11);
	//qDebug() << plc->setValue(_tr("X轴点动速度"),22.22);
	//qDebug() << plc->setValue(_tr("X轴当前位置"),33.33);
	//qDebug() << plc->setValue(_tr("X轴剩余距离"),44.44);
	//qDebug() << plc->setValue(_tr("X轴位置设置"),55.55);
	//qDebug() << plc->setValue(plc->toEntireAddr(13,0), 11111);
	//qDebug() << plc->setValue(plc->toEntireAddr(13, 4), 22222);
	//qDebug() << plc->setValue(plc->toEntireAddr(13, 8), 33333);
	//qDebug() << plc->setValue(plc->toEntireAddr(13, 12), 44444);
	//qDebug() << plc->setValue(plc->toEntireAddr(13, 16), 55555);
	//qDebug() << plc->getValue(_tr("X轴运行速度"));
	//qDebug() << plc->getValue(_tr("X轴点动速度"));
	//qDebug() << plc->getValue(_tr("X轴当前位置"));
	//qDebug() << plc->getValue(_tr("X轴剩余距离"));
	//qDebug() << plc->getValue(_tr("X轴位置设置"));

	
	if (!isHidden())
	{
		int index = ui.tabWidget->currentIndex();
		if (index == 0) {
			refreshMbuttonWidget();
			refreshServoWidget();
		}
		else if (index == 1) {
			refreshMbuttonWidget();
		}
		else if (index == 2) {
			refreshIOmapWidget();
		}
	}
}

