#pragma once

#include <QWidget>
#include "ui_setupwidget.h"
#include <QCheckBox>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QList>
#include <array>
#include <QButtonGroup>
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
	void refreshClassWidget();
	void refreshTestPamWidget();
	void refreshLocationWidget();
	void refreshOtherPamWidget();
	void refreshSkipWidget();
	QList<QCheckBox*> m_checkboxList;
	QList<QSpinBox*> m_spinboxMinList;
	QList<QSpinBox*> m_spinboxMaxList;
	QList<QDoubleSpinBox*> m_dspinboxLicationPamList;
	QList<QSpinBox*> m_spinboxtestPamList;
	QList<QSpinBox*> m_spinboxOtherPamList;
	QDoubleSpinBox* m_dspinboxMax_minOdds;
private:
	Ui::SetupWidget ui;
	TestParameters m_parameters;
	int locationPamCount = 14;
	void loadPamsFromXml();
	void setTestModsPam();
	void setPams2xml();
	void initSkipWidget();
	///
	char* m_xmlpath;
	std::array<QButtonGroup*,4> btn_groups;

private slots:
	void on_pushButton_saveClicked(bool checked);
	void skipButtonClicked(int index);
};
