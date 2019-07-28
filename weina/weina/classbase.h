#pragma once
#include <QWidget>
#include <QObject>
#include <array>

using namespace std;

class CtrlPanelBase: public QWidget
{
public:
	CtrlPanelBase(QWidget* parent = Q_NULLPTR)
		: QWidget(parent)
	{
	}
	virtual ~CtrlPanelBase()
	{
	}
	virtual void setID(int id)=0;
	virtual int getID()=0;
	virtual void setRes(int*  resArray)=0;
	virtual void setHotRes(int* resArray)=0;
	virtual void setHotButtonState(bool* stateArray)=0;
	virtual void getHotButtonState(bool* stateArray)=0;
	virtual void setHotResDipEnabled(bool en)=0;
	virtual void setResDipEnabled(bool en)=0;
	virtual void setHotButtonEnabled(bool en)=0;
};

typedef struct _TestParameters
{
	int minHotRes = 50;
	int maxHotRes = 150;
	int testHotresTime = 5000;
	int testTime = 10000;
	int min_maxTestTime = 5000;
	array<bool, 29> enabled;
	array<int, 29> minResScope;
	array<int, 29> maxResScope;
}TestParameters;
