#include "setupwidget.h"
#include <QDebug>
#include <QDir>

#define _tr(str) QString::fromLocal8Bit(str)


SetupWidget::SetupWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
	hide();
	//初始化电阻检测模块参数列表
	ui.tableWidget_classPam->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableWidget_classPam->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectItems);
	ui.tableWidget_classPam->setColumnCount(3);
	ui.tableWidget_classPam->setRowCount(29);
	ui.tableWidget_classPam->setColumnWidth(1, 200);
	ui.tableWidget_classPam->setColumnWidth(2, 200);
	QStringList testHeader;
	testHeader.append(_tr("启用"));
	testHeader.append(_tr("最小值"));
	testHeader.append(_tr("最大值"));
	ui.tableWidget_classPam->setHorizontalHeaderLabels(testHeader);

	for (int i = 0; i < 29; i++)
	{
		QCheckBox* checkbox = new QCheckBox();
		checkbox->setObjectName(_tr("checkbox_%1").arg(QString::number(i)));
		checkbox->setText(_tr(""));
		ui.tableWidget_classPam->setCellWidget(i, 0, checkbox);
		this->m_checkboxList.append(checkbox);
	}
	for (int i = 0; i < 29; i++)
	{
		QSpinBox* spinbox = new QSpinBox();
		spinbox->setMaximum(999999999);
		spinbox->setObjectName(_tr("spinboxMin_%1").arg(QString::number(i)));
		ui.tableWidget_classPam->setCellWidget(i, 1, spinbox);
		this->m_spinboxMinList.append(spinbox);
	}
	for (int i = 0; i < 29; i++)
	{
		QSpinBox* spinbox = new QSpinBox();
		spinbox->setMaximum(999999999);
		spinbox->setObjectName(_tr("spinboxMax_%1").arg(QString::number(i)));
		ui.tableWidget_classPam->setCellWidget(i, 2, spinbox);
		this->m_spinboxMaxList.append(spinbox);
	}
	//初始化定位参数设置列表
	QStringList locationPamName;
	locationPamName.append(_tr("1号吸嘴料槽1坐标X"));
	locationPamName.append(_tr("1号吸嘴料槽1坐标Y"));
	locationPamName.append(_tr("1号板第一行位置X"));
	locationPamName.append(_tr("1号板第一行位置Y"));
	locationPamName.append(_tr("2号板第一行位置X"));
	locationPamName.append(_tr("2号板第一行位置Y"));
	locationPamName.append(_tr("3号板第一行位置X"));
	locationPamName.append(_tr("3号板第一行位置Y"));
	locationPamName.append(_tr("4号板第一行位置X"));
	locationPamName.append(_tr("4号板第一行位置Y"));
	locationPamName.append(_tr("吸嘴气缸间距"));
	locationPamName.append(_tr("料板纵间距"));
	locationPamName.append(_tr("1号吸嘴料盒1位置X"));
	locationPamName.append(_tr("1号吸嘴料盒1位置Y"));
	
	QStringList locationHeader;
	locationHeader.append(_tr("参数"));
	locationHeader.append(_tr("值"));
	ui.tableWidget_locationPam->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableWidget_locationPam->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectItems);
	ui.tableWidget_locationPam->setColumnCount(2);
	ui.tableWidget_locationPam->setHorizontalHeaderLabels(locationHeader);
	ui.tableWidget_locationPam->setRowCount(locationPamCount);
	ui.tableWidget_locationPam->setColumnWidth(0, 200);
	ui.tableWidget_locationPam->setColumnWidth(1, 200);
	for (int i = 0; i < locationPamCount; i++)
	{
		QLabel* label = new QLabel();
		label->setText(locationPamName[i]);
		ui.tableWidget_locationPam->setCellWidget(i, 0, label);
	}
	for (int i = 0; i < locationPamCount; i++)
	{
		QDoubleSpinBox* dspinBox = new QDoubleSpinBox();
		dspinBox->setMinimum(-9999.999);
		dspinBox->setMaximum(9999.999);
		dspinBox->setObjectName(_tr("db%1").arg(QString::number(140000+i*4)));
		//dspinBox->setText(locationPamName[i]);
		ui.tableWidget_locationPam->setCellWidget(i, 1, dspinBox);
		m_dspinboxLicationPamList.append(dspinBox);
	}
	QObject::connect(ui.pushButton_save, SIGNAL(clicked(bool)),this, SLOT(on_pushButton_saveClicked(bool)));

	//初始化检测参数设置列表
	QStringList testPamName;
	testPamName.append(_tr("最小加热电阻阻值"));
	testPamName.append(_tr("最大加热电阻阻值"));
	testPamName.append(_tr("检测加热电阻时间"));
	testPamName.append(_tr("加热时间"));
	testPamName.append(_tr("判断最大/小值开始时间"));
	testPamName.append(_tr("最大/小值比值MAX"));
	QStringList testPamHeader;
	testPamHeader.append(_tr("参数"));
	testPamHeader.append(_tr("值"));
	ui.tableWidget_testPam->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableWidget_testPam->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectItems);
	ui.tableWidget_testPam->setColumnCount(2);
	ui.tableWidget_testPam->setHorizontalHeaderLabels(testPamHeader);
	ui.tableWidget_testPam->setRowCount(testPamName.size());
	ui.tableWidget_testPam->setColumnWidth(0, 200);
	ui.tableWidget_testPam->setColumnWidth(1, 200);
	for (int i = 0; i < testPamName.size(); i++)
	{
		QLabel* label = new QLabel();
		label->setText(testPamName[i]);
		ui.tableWidget_testPam->setCellWidget(i, 0, label);
		if (testPamName[i]== _tr("最大/小值比值MAX"))
		{
			QDoubleSpinBox* dspinBox = new QDoubleSpinBox();
			dspinBox->setMinimum(-9999.999);
			dspinBox->setMaximum(9999.999);
			dspinBox->setObjectName(_tr("dspinboxTestPam_%1").arg(QString::number(i)));
			ui.tableWidget_testPam->setCellWidget(i, 1, dspinBox);
			m_dspinboxMax_minOdds = dspinBox;
		}
		else
		{
			QSpinBox* spinbox = new QSpinBox();
			spinbox->setMaximum(999999999);
			spinbox->setObjectName(_tr("spinboxTestPam_%1").arg(QString::number(i)));
			ui.tableWidget_testPam->setCellWidget(i, 1, spinbox);
			m_spinboxtestPamList.append(spinbox);
		}

		
	}

	


	widgetShow();
	

	QString path = QDir::currentPath();
	path.append(_tr("/setup.xml"));
	QByteArray ba = path.toLatin1();
	m_xmlpath = ba.data();
}

SetupWidget::~SetupWidget()
{
}

void SetupWidget::widgetShow()
{
	auto mainctrl = MainCtrl::Instance();
	loadPamsFromXml();
	setTestModsPam();
	refreshClassWidget();
	refreshLocationWidget();
	refreshTestPamWidget();
	//mainctrl->testStart(0);
}

void SetupWidget::refreshClassWidget()
{
	for (int i = 0; i < 29; i++)
	{
		m_checkboxList[i]->setChecked(m_parameters.enabled[i]);
		m_spinboxMinList[i]->setValue(m_parameters.minResScope[i]);
		m_spinboxMaxList[i]->setValue(m_parameters.maxResScope[i]);
	}

}

void SetupWidget::refreshTestPamWidget()
{
	m_spinboxtestPamList[0]->setValue(m_parameters.minHotRes);
	m_spinboxtestPamList[1]->setValue(m_parameters.maxHotRes);
	m_spinboxtestPamList[2]->setValue(m_parameters.testHotresTime);
	m_spinboxtestPamList[3]->setValue(m_parameters.testTime);
	m_spinboxtestPamList[4]->setValue(m_parameters.min_maxTestTime);
	m_dspinboxMax_minOdds->setValue(m_parameters.max_minOdds);
}

void SetupWidget::refreshLocationWidget()
{
	auto plc = PLC::PlcStation::Instance();
	for (int i = 0; i < locationPamCount; i++)
	{
		QString objName = m_dspinboxLicationPamList[i]->objectName();
		objName.remove(0,2);
		QVariant val= plc->getValue(objName.toInt());
		m_dspinboxLicationPamList[i]->setValue(val.toDouble());
	}
}

void SetupWidget::loadPamsFromXml()
{
	auto mainctrl = MainCtrl::Instance();
	using namespace pugi;
	xml_document doc;
	QString path = QDir::currentPath();
	path.append(_tr("/setup.xml"));
	char* ch;
	QByteArray ba = path.toLatin1();
	ch = ba.data();
	//pugi::xml_parse_result result = doc.load_file(ch, parse_declaration|| parse_pi|| parse_doctype,pugi::xml_encoding::encoding_utf8);
	xml_parse_result result = doc.load_file(ch);
	if (!result)
	{
		qDebug() << _tr("xml文件加载失败!") << "Load result: " << result.description();

	}
	else
	{
		xml_node classes = doc.first_child();
		//打印xml信息
		//for (xml_node classPam = classes.first_child(); classPam; classPam = classPam.next_sibling())
		//{
		//	for (xml_attribute attr = classPam.first_attribute(); attr; attr = attr.next_attribute())
		//	{
		//		qDebug() << " " << attr.name() << "=" << attr.value();
		//	}

		//}
		qDebug() << _tr("xml文件加载成功!");
		for (int i = 0; i < 29; i++)
		{
			QString str = _tr("class");
			str.append(QString::number(i));
			char* className;
			QByteArray ba = str.toLatin1();
			className = ba.data();
			xml_node classes = doc.first_child();
			xml_node classPam = classes.child(className);
			xml_attribute statusPam = classPam.attribute("status");
			xml_attribute minResistancePam = classPam.attribute("minResistance");
			xml_attribute maxResistancePam = classPam.attribute("maxResistance");
			if (_tr(statusPam.value()) == _tr("true"))
			{
				m_parameters.enabled[i] = true;
			}
			else
			{
				m_parameters.enabled[i] = false;
			}
			m_parameters.minResScope[i] = QString(minResistancePam.value()).toInt();
			m_parameters.maxResScope[i] = QString(maxResistancePam.value()).toInt();
			//qDebug() << statusPam.value()<< minResistancePam.value()<< maxResistancePam.value();
		}

		xml_node root = doc.first_child();
		xml_node testPam = root.child("testPams");
		xml_attribute minHotRes = testPam.attribute("minHotRes");
		xml_attribute maxHotRes = testPam.attribute("maxHotRes");
		xml_attribute testHotresTime = testPam.attribute("testHotresTime");
		xml_attribute testTime = testPam.attribute("testTime");
		xml_attribute min_maxTestTime = testPam.attribute("min_maxTestTime");
		xml_attribute max_minOdds= testPam.attribute("max_minOdds");
		m_parameters.minHotRes = QString( minHotRes.value()).toInt();
		m_parameters.maxHotRes = QString(maxHotRes.value()).toInt();
		m_parameters.testHotresTime = QString(testHotresTime.value()).toInt();
		m_parameters.testTime = QString(testTime.value()).toInt();
		m_parameters.min_maxTestTime = QString(min_maxTestTime.value()).toInt();
		m_parameters.max_minOdds = QString(max_minOdds.value()).toFloat();
	}
}

void SetupWidget::setTestModsPam()
{
	auto mainctrl = MainCtrl::Instance();
	for (int i = 0; i < 4; i++)
	{
		mainctrl->getModules(i)->paramete = m_parameters;
	}
}

void SetupWidget::setPams2xml()
{
	using namespace pugi;

	QString path = QDir::currentPath();
	path.append(_tr("/setup.xml"));
	char* xmlPath;
	QByteArray ba = path.toLatin1();
	xmlPath = ba.data();

	xml_document doc;
	xml_parse_result result = doc.load_file(xmlPath);
	if (!result)
	{
		qDebug() << _tr("xml文件加载失败!") << "Load result: " << result.description();
		return;
	}
	xml_node classifyPams = doc.child("classifyPam");
	int i = 0;
	for ( xml_node classify= classifyPams.first_child(); classify;classify= classify.next_sibling())
	{
		if (i > 23)
			break;
		xml_attribute status = classify.attribute("status");
		xml_attribute minResistance = classify.attribute("minResistance");
		xml_attribute maxResistance = classify.attribute("maxResistance");
		status.set_value(m_checkboxList[i]->isChecked());
		minResistance.set_value(m_spinboxMinList[i]->value());
		maxResistance.set_value(m_spinboxMaxList[i]->value());
		i++;
	}

	xml_node testPams = classifyPams.child("testPams");
	xml_attribute minHotRes = testPams.attribute("minHotRes");
	xml_attribute maxHotRes = testPams.attribute("maxHotRes");
	xml_attribute testHotresTime = testPams.attribute("testHotresTime");
	xml_attribute testTime = testPams.attribute("testTime");
	xml_attribute min_maxTestTime = testPams.attribute("min_maxTestTime");
	xml_attribute max_minOdds = testPams.attribute("max_minOdds");
	minHotRes.set_value(m_spinboxtestPamList[0]->value());
	maxHotRes.set_value(m_spinboxtestPamList[1]->value());
	testHotresTime.set_value(m_spinboxtestPamList[2]->value());
	testTime.set_value(m_spinboxtestPamList[3]->value());
	min_maxTestTime.set_value(m_spinboxtestPamList[4]->value());
	max_minOdds.set_value(m_dspinboxMax_minOdds->value());
	doc.save_file(xmlPath);
}

void SetupWidget::on_pushButton_saveClicked(bool checked)
{
	
	using namespace pugi;
	int pageID = ui.tabWidget->currentIndex();
	if (pageID==0|| pageID == 1)
		setPams2xml();
	//{
	//	pugi::xml_document doc;
	//	pugi::xml_node decl = doc.prepend_child(pugi::node_declaration);
	//	decl.append_attribute("version") = "1.0";
	//	decl.append_attribute("encoding") = "UTF-8";
	//	pugi::xml_node node = doc.append_child("classifyPam");
	//	pugi::xml_node descr = node.append_child("description");
	//	descr.append_child(pugi::node_pcdata).set_value("Simple node");
	//	for (int i = 0; i < 29; i++)
	//	{
	//		QString str = _tr("class");
	//		str.append(QString::number(i));
	//		char* ch;
	//		QByteArray ba = str.toLatin1();
	//		ch = ba.data();

	//		pugi::xml_node param = node.insert_child_before(ch, descr);

	//		// add attributes to param node
	//		param.append_attribute("status") = m_checkboxList[i]->isChecked();
	//		param.append_attribute("minResistance") = m_spinboxMinList[i]->value();
	//		param.append_attribute("maxResistance") = m_spinboxMaxList[i]->value();
	//	}
	//	QString path = QDir::currentPath();
	//	path.append(_tr("/setup.xml"));
	//	qDebug() << path;
	//	char* ch;
	//	QByteArray ba = path.toLatin1();
	//	ch = ba.data();
	//	doc.save_file(ch);
	//	loadPamsFromXml();
	//	setTestModsPam();
	//}



	if (pageID == 2)
	{
		auto plc = PLC::PlcStation::Instance();
		for (int i = 0; i < locationPamCount; i++)
		{
			QString objName = m_dspinboxLicationPamList[i]->objectName();
			objName.remove(0, 2);
			plc->setValue(objName.toInt(), m_dspinboxLicationPamList[i]->value());
		}
	}
}

