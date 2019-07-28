#pragma once

#include <QWidget>
#include "ui_setupwidget.h"
#include <QCheckBox>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QList>
#include "pugixml/pugixml.hpp"
#include "mainctrl.h"
#include "classbase.h"
#include "plcstation.h"

class SetupWidget : public QWidget
{
	Q_OBJECT

public:
	SetupWidget(QWidget *parent = Q_NULLPTR);
	~SetupWidget();
	void widgetShow();
	void refreshTestWidget();
	void refreshLocationWidget();
	QList<QCheckBox*> m_checkboxList;
	QList<QSpinBox*> m_spinboxMinList;
	QList<QSpinBox*> m_spinboxMaxList;
	QList<QDoubleSpinBox*> m_dspinboxLicationPamList;
private:
	Ui::SetupWidget ui;
	TestParameters m_parameters;
	int locationPamCount = 14;
	void loadPamsFromXml();
	void setTestModsPam();
private slots:
	void on_pushButton_saveClicked(bool checked);
};
