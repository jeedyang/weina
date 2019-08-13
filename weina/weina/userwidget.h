#pragma once

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include "ui_userwidget.h"
#include "alltype.h"

typedef	struct _UserTable
{
	QStringList userIDList;
	QStringList userNameList;
	QStringList userTypeList;
}UserTable;

class UserWidget : public QWidget
{
	Q_OBJECT

public:
	UserWidget(QWidget *parent = Q_NULLPTR);
	~UserWidget();
	void setUserInfo(UserInfo info)
	{
		m_userInfo = info;
	}
	void showWidget();
	void hideWidget();

private:
	Ui::UserWidget ui;
	UserTable getUserlist();
	QSqlDatabase db;
	void tableInit();
	void refreshTable();
	void addUser(UserType usertype);
	UserInfo m_userInfo;
	QSqlTableModel* model;
private slots:
	void on_pushButton_deleteClicked();
	void on_pushButton_addClicked();
	void on_pushButton_changeClicked();
	void on_pushButton_addADminClicked();
};
