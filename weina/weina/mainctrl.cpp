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
	qDebug() << _tr("检测结束,板号:") << id;
	for (int i = 0; i < 24; i++)
	{
		qDebug() << _tr("检测结果 # %1:").arg(i) << m_testMods[id]->result[i]<<_tr("最小值 :")<< m_testMods[id]->minRes[i] << _tr("最大值 :") << m_testMods[id]->maxRes[i];

	}
	
}

void MainCtrl::on_logicTimeOut()
{
}
