#pragma once

#include "ctrlpanel_global.h"
#include "../weina/classbase.h"
#include "ui_widget.h"
#include "panel.h"
#include <Qlist>
#include <QGridLayout>

class CtrlPanel:public CtrlPanelBase
{
	Q_OBJECT
public:
	CtrlPanel(int ID , QWidget* parent = Q_NULLPTR);	
	~CtrlPanel();
	void setRes(int* resArray);
	void setHotRes(int* resArray);
	void setHotButtonState(bool* stateArray);
	void getHotButtonState(bool* stateArray);
	void setHotResDipEnabled(bool en);
	void setResDipEnabled(bool en);
	void setHotButtonEnabled(bool en);
public slots:
	void onPanelHotButtonClicked(int id, bool checked);
private:
	void initForm();
private:
	Ui::Form ui;
	QList<Panel*> panelList;
	QGridLayout panelLayout;
signals:
	void hotButtonClicked(int, bool);
};

CTRLPANEL_API CtrlPanel* createInstance(int ID, QWidget* parent);
