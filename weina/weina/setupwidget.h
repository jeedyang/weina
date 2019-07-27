#pragma once

#include <QWidget>
#include "ui_setupwidget.h"
#include <QCheckBox>
#include <QSpinBox>
#include <QList>
#include "pugixml/pugixml.hpp"
#include "classbase.h"

class SetupWidget : public QWidget
{
	Q_OBJECT

public:
	SetupWidget(QWidget *parent = Q_NULLPTR);
	~SetupWidget();
	void widgetShow();
	QList<QCheckBox*> m_checkboxList;
	QList<QSpinBox*> m_spinboxMinList;
	QList<QSpinBox*> m_spinboxMaxList;
private:
	Ui::SetupWidget ui;
private slots:
	void on_pushButton_saveClicked(bool checked);
};
