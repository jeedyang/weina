#include "setupwidget.h"
#include <QDebug>
#include <QDir>
#include <QGridLayout>

#define _tr(str) QString::fromLocal8Bit(str)


SetupWidget::SetupWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initSkipWidget();
	setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
	hide();
	//��ʼ��������ģ������б�
	ui.tableWidget_classPam->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableWidget_classPam->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectItems);
	ui.tableWidget_classPam->setColumnCount(4);
	ui.tableWidget_classPam->setRowCount(29);
	ui.tableWidget_classPam->setColumnWidth(1, 200);
	ui.tableWidget_classPam->setColumnWidth(2, 200);
	QStringList testHeader;
	testHeader.append(_tr("����"));
	testHeader.append(_tr("��Сֵ"));
	testHeader.append(_tr("���ֵ"));
	testHeader.append(_tr("��λ"));

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
	for (int i = 0; i < 29; i++)
	{
		QLabel* label = new QLabel();
		label->setText(_tr("ǧŷ"));
		ui.tableWidget_classPam->setCellWidget(i, 3, label);
	}
	//��ʼ����λ���������б�
	QStringList locationPamName;
	locationPamName.append(_tr("1�������ϲ�1����X"));
	locationPamName.append(_tr("1�������ϲ�1����Y"));
	locationPamName.append(_tr("1�Ű��һ��λ��X"));
	locationPamName.append(_tr("1�Ű��һ��λ��Y"));
	locationPamName.append(_tr("2�Ű��һ��λ��X"));
	locationPamName.append(_tr("2�Ű��һ��λ��Y"));
	locationPamName.append(_tr("3�Ű��һ��λ��X"));
	locationPamName.append(_tr("3�Ű��һ��λ��Y"));
	locationPamName.append(_tr("4�Ű��һ��λ��X"));
	locationPamName.append(_tr("4�Ű��һ��λ��Y"));
	locationPamName.append(_tr("�������׼��"));
	locationPamName.append(_tr("�ϰ��ݼ��"));
	locationPamName.append(_tr("1�������Ϻ�1λ��X"));
	locationPamName.append(_tr("1�������Ϻ�1λ��Y"));
	
	QStringList locationHeader;
	locationHeader.append(_tr("����"));
	locationHeader.append(_tr("ֵ"));
	locationHeader.append(_tr("��λ"));
	ui.tableWidget_locationPam->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableWidget_locationPam->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectItems);
	ui.tableWidget_locationPam->setColumnCount(3);
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
	for (int i = 0; i < locationPamCount; i++)
	{
		QLabel* label = new QLabel();
		label->setText(_tr("mm"));
		ui.tableWidget_locationPam->setCellWidget(i, 2, label);
	}
	QObject::connect(ui.pushButton_save, SIGNAL(clicked(bool)),this, SLOT(on_pushButton_saveClicked(bool)));

	//��ʼ�������������б�
	QStringList testPamName;
	testPamName.append(_tr("��С���ȵ�����ֵ"));
	testPamName.append(_tr("�����ȵ�����ֵ"));
	testPamName.append(_tr("�����ȵ���ʱ��"));
	testPamName.append(_tr("����ʱ��"));
	testPamName.append(_tr("�ж����/Сֵ��ʼʱ��"));
	testPamName.append(_tr("���/Сֵ��ֵMAX"));
	QStringList testPamHeader;
	testPamHeader.append(_tr("����"));
	testPamHeader.append(_tr("ֵ"));
	testPamHeader.append(_tr("��λ"));
	ui.tableWidget_testPam->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableWidget_testPam->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectItems);
	ui.tableWidget_testPam->setColumnCount(3);
	ui.tableWidget_testPam->setHorizontalHeaderLabels(testPamHeader);
	ui.tableWidget_testPam->setRowCount(testPamName.size());
	ui.tableWidget_testPam->setColumnWidth(0, 200);
	ui.tableWidget_testPam->setColumnWidth(1, 200);
	for (int i = 0; i < testPamName.size(); i++)
	{
		QLabel* label = new QLabel();
		label->setText(testPamName[i]);
		ui.tableWidget_testPam->setCellWidget(i, 0, label);
		if (testPamName[i]== _tr("���/Сֵ��ֵMAX"))
		{
			QDoubleSpinBox* dspinBox = new QDoubleSpinBox();
			dspinBox->setMinimum(0.000);
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
	QLabel* label0 = new QLabel();
	label0->setText(_tr("ŷķ"));
	QLabel* label1 = new QLabel();
	label1->setText(_tr("ŷķ"));
	QLabel* label2 = new QLabel();
	label2->setText(_tr("��"));
	QLabel* label3 = new QLabel();
	label3->setText(_tr("��"));
	QLabel* label4 = new QLabel();
	label4->setText(_tr("��"));
	QLabel* label5 = new QLabel();
	label5->setText(_tr("��ֵ"));
	ui.tableWidget_testPam->setCellWidget(0, 2, label0);
	ui.tableWidget_testPam->setCellWidget(1, 2, label1);
	ui.tableWidget_testPam->setCellWidget(2, 2, label2);
	ui.tableWidget_testPam->setCellWidget(3, 2, label3);
	ui.tableWidget_testPam->setCellWidget(4, 2, label4);
	ui.tableWidget_testPam->setCellWidget(5, 2, label5);

	//��ʼ���������������б�
	QStringList otherPamName;
	otherPamName.append(_tr("������ⴵ���ӳ�"));
	QStringList otherPamHeader;
	otherPamHeader.append(_tr("����"));
	otherPamHeader.append(_tr("ֵ"));
	ui.tableWidget_otherPam->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableWidget_otherPam->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectItems);
	ui.tableWidget_otherPam->setColumnCount(2);
	ui.tableWidget_otherPam->setHorizontalHeaderLabels(otherPamHeader);
	ui.tableWidget_otherPam->setRowCount(otherPamName.size());
	ui.tableWidget_otherPam->setColumnWidth(0, 200);
	ui.tableWidget_otherPam->setColumnWidth(1, 200);
	for (int i = 0; i < otherPamName.size(); i++)
	{
		QLabel* label = new QLabel();
		label->setText(otherPamName[i]);
		ui.tableWidget_otherPam->setCellWidget(i, 0, label);

		QSpinBox* spinbox = new QSpinBox();
		spinbox->setMaximum(999999999);
		spinbox->setObjectName(_tr("db%1").arg(QString::number(330000 + i * 4)));
		ui.tableWidget_otherPam->setCellWidget(i, 1, spinbox);
		m_spinboxOtherPamList.append(spinbox);
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
	refreshOtherPamWidget();
	refreshSkipWidget();
	//mainctrl->testStart(0);
}

void SetupWidget::refreshClassWidget()
{
	for (int i = 0; i < 29; i++)
	{
		m_checkboxList[i]->setChecked(m_parameters.enabled[i]);
		//�������ŷģ,��ʾ����ǧŷ
		m_spinboxMinList[i]->setValue(m_parameters.minResScope[i]/1000);
		m_spinboxMaxList[i]->setValue(m_parameters.maxResScope[i]/1000);
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

void SetupWidget::refreshOtherPamWidget()
{
	auto plc = PLC::PlcStation::Instance();
	for (int i = 0; i < m_spinboxOtherPamList.size(); i++)
	{
		QString objName = m_spinboxOtherPamList[i]->objectName();
		objName.remove(0, 2);
		QVariant val = plc->getValue(objName.toInt());
		m_spinboxOtherPamList[i]->setValue(val.toInt());
	}
}

void SetupWidget::refreshSkipWidget()
{
	auto plc = PLC::PlcStation::Instance();
	unsigned char buffer[12];
	plc->readBlockAsByte(AreaDB,40,0,12,buffer);
	unsigned char board0[3];
	unsigned char board1[3];
	unsigned char board2[3];
	unsigned char board3[3];
	memcpy(board0, buffer,3);
	memcpy(board1, buffer+3, 3);
	memcpy(board2, buffer+6, 3);
	memcpy(board3, buffer+9, 3);
	for (int i = 0; i < 3; i++)
	{
		bool result;
		for (int j = 0; j < 8; j++)
		{
			result = board0[i] & (0x01 << j);
			btn_groups[0]->button(i * 8 + j)->setChecked(result);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		bool result;
		for (int j = 0; j < 8; j++)
		{
			result = board1[i] & (0x01 << j);
			btn_groups[1]->button(i * 8 + j)->setChecked(result);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		bool result;
		for (int j = 0; j < 8; j++)
		{
			result = board2[i] & (0x01 << j);
			btn_groups[2]->button(i * 8 + j)->setChecked(result);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		bool result;
		for (int j = 0; j < 8; j++)
		{
			result = board3[i] & (0x01 << j);
			btn_groups[3]->button(i * 8 + j)->setChecked(result);
		}
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
		qDebug() << _tr("xml�ļ�����ʧ��!") << "Load result: " << result.description();

	}
	else
	{
		xml_node classes = doc.first_child();
		//��ӡxml��Ϣ
		//for (xml_node classPam = classes.first_child(); classPam; classPam = classPam.next_sibling())
		//{
		//	for (xml_attribute attr = classPam.first_attribute(); attr; attr = attr.next_attribute())
		//	{
		//		qDebug() << " " << attr.name() << "=" << attr.value();
		//	}

		//}
		qDebug() << _tr("xml�ļ����سɹ�!");
		//��ȡ�ֵ�����
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
		///
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
		m_parameters.max_minOdds = QString(max_minOdds.value()).toDouble();
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
		qDebug() << _tr("xml�ļ�����ʧ��!") << "Load result: " << result.description();
		return;
	}
	xml_node classifyPams = doc.child("classifyPam");
	int i = 0;
	for ( xml_node classify= classifyPams.first_child(); classify;classify= classify.next_sibling())
	{
		if (i > 28)
			break;
		xml_attribute status = classify.attribute("status");
		xml_attribute minResistance = classify.attribute("minResistance");
		xml_attribute maxResistance = classify.attribute("maxResistance");
		status.set_value(m_checkboxList[i]->isChecked());
		//���õ���ǧŷ,Ҫ����Ϊŷķ *1000
		minResistance.set_value(m_spinboxMinList[i]->value()*1000);
		maxResistance.set_value(m_spinboxMaxList[i]->value()*1000);
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

void SetupWidget::initSkipWidget()
{
	for (int j = 0; j < 4; j++)
	{
		btn_groups[j] = new QButtonGroup;
		btn_groups[j]->setExclusive(false);
		btn_groups[j]->setObjectName(QString("btn_group%1").number(j));
		QWidget* widget = new QWidget(ui.tabWidget_skip);
		QGridLayout* layout = new QGridLayout(widget);
		for (int i = 0; i < 24; i++)
		{
			QPushButton* button = new QPushButton(widget);
			button->setText(QString("#%1").number(i));
			button->setCheckable(true);
			btn_groups[j]->addButton(button,i);
			layout->addWidget(button, i / 4, i % 4);
		}
		ui.tabWidget_skip->widget(j)->setLayout(layout);
		connect(btn_groups[j], SIGNAL(buttonClicked(int)), this, SLOT(skipButtonClicked(int)));
	}
}

void SetupWidget::skipButtonClicked(int index)
{
	QObject* sender = QObject::sender();
	QButtonGroup* group = qobject_cast<QButtonGroup*>(sender);
	auto plc = PLC::PlcStation::Instance();
	QAbstractButton* button = group->button(index);
	int board_num = sender->objectName().right(1).toInt();
	int a=board_num * 24 +index;
	plc->writeBool(AreaDB, 40, a / 8, a % 8, button->isChecked());
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

	if (pageID == 3)
	{
		auto plc = PLC::PlcStation::Instance();
		for (int i = 0; i < m_spinboxOtherPamList.size(); i++)
		{
			QString objName = m_spinboxOtherPamList[i]->objectName();
			objName.remove(0, 2);
			plc->setValue(objName.toInt(), m_spinboxOtherPamList[i]->value());
		}
	}
}

