#include "classselectdialog.h"
#include "plcstation.h"
#include <QMessageBox>

ClassSelectDialog::ClassSelectDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->setWindowTitle(_tr("ѡ����"));
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
	int boardStatus_1 = plc->getValue(_tr("1�Ű�״̬")).toInt();
	int boardStatus_2 = plc->getValue(_tr("2�Ű�״̬")).toInt();
	int boardStatus_3 = plc->getValue(_tr("3�Ű�״̬")).toInt();
	int boardStatus_4 = plc->getValue(_tr("4�Ű�״̬")).toInt();
	array<int, 4> boardStatusPlc = { boardStatus_1, boardStatus_2, boardStatus_3, boardStatus_4 };
	if (boardStatusPlc[id]!=3)
	{
		for (int i = 0; i < 24; i++)
		{
			plc->writeInt(AreaDB, 21 + id, i, 0);
		}
		QMessageBox::information(this, _tr("��ʾ��"), _tr("�ð��ϴ�δ�����ɣ����в�Ʒ������NG����"), QMessageBox::Ok);
	}
	this->close();
	//plc->setValue(_tr("����ָ��"), (id + 1) * 10 + 2);
	plc->writeInt(AreaDB,16,24,id);
	plc->writeBool(AreaM,1,20,6,true);
	plc->writeBool(AreaM, 1, 22, 3, true);
}
