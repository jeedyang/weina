#pragma once

#include <QWidget>
#include "ui_panel.h"

#define _tr(str) QString::fromLocal8Bit(str)

class Panel : public QWidget
{
	Q_OBJECT

public:
	Panel(int ID,QWidget *parent = Q_NULLPTR);
	~Panel();

	void setRes(int res);
	void setHotRes(int res);
	void setHotButtonState(bool state);
	void getHotButtonState(bool& state);
	void setHotVoltage(double volt);
	void setHotVolDipEnabled(bool en);
	void setHotResDipEnabled(bool en);
	void setResDipEnabled(bool en);
	void setHotButtonEnabled(bool en);


public slots:
	void onButtonClicked(bool checked);

signals:
	void buttonClicked(int,bool);

private:
	void initForm();

private:
	Ui::Panel ui;
	int id;
};
