#pragma once
#include <QWidget>
#include <QObject>

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

	virtual void setRes(int*  resArray)=0;
	virtual void setHotRes(int* resArray)=0;
	virtual void setHotButtonState(bool* stateArray)=0;
	virtual void getHotButtonState(bool* stateArray)=0;
	virtual void setHotResDipEnabled(bool en)=0;
	virtual void setResDipEnabled(bool en)=0;
	virtual void setHotButtonEnabled(bool en)=0;
};

