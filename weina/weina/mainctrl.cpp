#include "mainctrl.h"
#include <QDebug>

MainCtrl::MainCtrl(QObject *parent)
	: QObject(parent)
{
	connect(&m_logicTimer, SIGNAL(timeout()), this, SLOT(on_logicTimeOut()));
	
}

MainCtrl::~MainCtrl()
{
}

void MainCtrl::setModules(ResTestmod** mods)
{
	for (int i = 0; i < 4; i++)
	{
		m_testMods.append(mods[i]);
	}
}

void MainCtrl::start()
{
}

void MainCtrl::classifyStart(int num)
{
}

void MainCtrl::arrangeStart(int num)
{
}

void MainCtrl::testStart(int num)
{
	m_testMods[num]->testStart();
}

void MainCtrl::on_testDone(int id)
{
	qDebug() << _tr("������,���:") << id;
	for (int i = 0; i < 24; i++)
	{
		qDebug() << _tr("����� # %1:").arg(i) << m_testMods[id]->result[i]<<_tr("��Сֵ :")<< m_testMods[id]->minRes[i] << _tr("���ֵ :") << m_testMods[id]->maxRes[i];

	}
	
}

void MainCtrl::on_logicTimeOut()
{
}
