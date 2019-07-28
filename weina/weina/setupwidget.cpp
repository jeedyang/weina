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
	ui.tableWidget_testPam->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableWidget_testPam->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectItems);
	ui.tableWidget_testPam->setColumnCount(3);
	ui.tableWidget_testPam->setRowCount(29);
	ui.tableWidget_testPam->setColumnWidth(1, 200);
	ui.tableWidget_testPam->setColumnWidth(2, 200);
	QStringList testHeader;
	testHeader.append(_tr("启用"));
	testHeader.append(_tr("最小值"));
	testHeader.append(_tr("最大值"));
	ui.tableWidget_testPam->setHorizontalHeaderLabels(testHeader);

	for (int i = 0; i < 29; i++)
	{
		QCheckBox* checkbox = new QCheckBox();
		checkbox->setObjectName(_tr("checkbox_%1").arg(QString::number(i)));
		checkbox->setText(_tr(""));
		ui.tableWidget_testPam->setCellWidget(i, 0, checkbox);
		this->m_checkboxList.append(checkbox);
	}
	for (int i = 0; i < 29; i++)
	{
		QSpinBox* spinbox = new QSpinBox();
		spinbox->setMaximum(999999999);
		spinbox->setObjectName(_tr("spinboxMin_%1").arg(QString::number(i)));
		ui.tableWidget_testPam->setCellWidget(i, 1, spinbox);
		this->m_spinboxMinList.append(spinbox);
	}
	for (int i = 0; i < 29; i++)
	{
		QSpinBox* spinbox = new QSpinBox();
		spinbox->setMaximum(999999999);
		spinbox->setObjectName(_tr("spinboxMax_%1").arg(QString::number(i)));
		ui.tableWidget_testPam->setCellWidget(i, 2, spinbox);
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
	ui.tableWidget_locationPam->setHorizontalHeaderLabels(locationHeader);
	ui.tableWidget_locationPam->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableWidget_locationPam->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectItems);
	ui.tableWidget_locationPam->setColumnCount(2);
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
	widgetShow();
	
}

SetupWidget::~SetupWidget()
{
}

void SetupWidget::widgetShow()
{
	auto mainctrl = MainCtrl::Instance();
	loadPamsFromXml();
	refreshTestWidget();
	setTestModsPam();
	refreshLocationWidget();
	//mainctrl->testStart(0);
}

void SetupWidget::refreshTestWidget()
{
	for (int i = 0; i < 29; i++)
	{
		m_checkboxList[i]->setChecked(m_parameters.enabled[i]);
		m_spinboxMinList[i]->setValue(m_parameters.minResScope[i]);
		m_spinboxMaxList[i]->setValue(m_parameters.maxResScope[i]);
	}

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
		for (xml_node classPam = classes.first_child(); classPam; classPam = classPam.next_sibling())
		{
			for (xml_attribute attr = classPam.first_attribute(); attr; attr = attr.next_attribute())
			{
				qDebug() << " " << attr.name() << "=" << attr.value();
			}

		}
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

void SetupWidget::on_pushButton_saveClicked(bool checked)
{
	using namespace pugi;
	int pageID = ui.tabWidget->currentIndex();
	if (pageID==0)
	{
		pugi::xml_document doc;
		pugi::xml_node decl = doc.prepend_child(pugi::node_declaration);
		decl.append_attribute("version") = "1.0";
		decl.append_attribute("encoding") = "UTF-8";
		pugi::xml_node node = doc.append_child("classifyPam");
		pugi::xml_node descr = node.append_child("description");
		descr.append_child(pugi::node_pcdata).set_value("Simple node");
		for (int i = 0; i < 29; i++)
		{
			QString str = _tr("class");
			str.append(QString::number(i));
			char* ch;
			QByteArray ba = str.toLatin1();
			ch = ba.data();

			pugi::xml_node param = node.insert_child_before(ch, descr);

			// add attributes to param node
			param.append_attribute("status") = m_checkboxList[i]->isChecked();
			param.append_attribute("minResistance") = m_spinboxMinList[i]->value();
			param.append_attribute("maxResistance") = m_spinboxMaxList[i]->value();
		}
		QString path = QDir::currentPath();
		path.append(_tr("/setup.xml"));
		qDebug() << path;
		char* ch;
		QByteArray ba = path.toLatin1();
		ch = ba.data();
		doc.save_file(ch);
		loadPamsFromXml();
		setTestModsPam();
	}
	if (pageID == 1)
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