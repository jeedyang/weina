#include "classselectdialog.h"
#include "plcstation.h"
#include <QMessageBox>

ClassSelectDialog::ClassSelectDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->setWindowTitle(_tr("Ñ¡Ôñ°åºÅ"));
	m_btnGroup = new QButtonGroup();
	m_btnGroup->addButton(ui.pushButton_class0,0);
	m_btnGroup->addButton(ui.pushButton_class1, 1);
	m_btnGroup->addButton(ui.pushButton_class2, 2);
	m_btnGroup->addButton(ui.pushButton_class3, 3);

	connect(m_btnGroup, SIGNAL(buttonClicked(int)),this,SLOT(onClassButtonClicked(int)));
}

ClassSelectDialog::~ClassSelectDialog()
{
}

void ClassSelectDialog::onClassButtonClicked(int id)
{
	auto plc = PLC::PlcStation::Instance();
	int boardStatus_1 = plc->getValue(_tr("1ºÅ°å×´Ì¬")).toInt();
	int boardStatus_2 = plc->getValue(_tr("2ºÅ°å×´Ì¬")).toInt();
	int boardStatus_3 = plc->getValue(_tr("3ºÅ°å×´Ì¬")).toInt();
	int boardStatus_4 = plc->getValue(_tr("4ºÅ°å×´Ì¬")).toInt();
	array<int, 4> boardStatusPlc = { boardStatus_1, boardStatus_2, boardStatus_3, boardStatus_4 };
	if (boardStatusPlc[id]!=3)
	{
		for (int i = 0; i < 24; i++)
		{
			plc->writeInt(AreaDB, 21 + id, i, 0);
		}
		QMessageBox::information(this, _tr("ÌáÊ¾£¡"), _tr("¸Ã°åÉÏ´ÎÎ´¼ì²âÍê³É£¬ËùÓÐ²úÆ·½«·ÖÖÁNGµµ£¡"), QMessageBox::Ok);
	}
	this->close();
	//plc->setValue(_tr("¿ØÖÆÖ¸Áî"), (id + 1) * 10 + 2);
	plc->writeInt(AreaDB,16,24,id);
	plc->writeBool(AreaM,1,20,6,true);
	plc->writeBool(AreaM, 1, 22, 3, true);
}
