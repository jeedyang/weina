#pragma once

#include <QDialog>
#include <QButtonGroup>
#include "ui_classselectdialog.h"
#include <array>

using namespace std;

class ClassSelectDialog : public QDialog
{
	Q_OBJECT

public:
	ClassSelectDialog(QWidget *parent = Q_NULLPTR);
	~ClassSelectDialog();
	
private slots:
	void onClassButtonClicked(int id);

private:
	Ui::ClassSelectDialog ui;
	QButtonGroup* m_btnGroup;
};
