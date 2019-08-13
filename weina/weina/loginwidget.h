#pragma once

#include <QWidget>
#include <QMouseEvent>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QKeyEvent>
#include "ui_loginwidget.h"
#include "alltype.h"
#include "mainwindow.h"

class LoginWidget : public QWidget
{
	Q_OBJECT

public:
	LoginWidget( QWidget *parent = Q_NULLPTR);
	~LoginWidget();
	UserInfo userInfo;
private:
	Ui::LoginWidget ui;
	
	void dbInit();
	int login();
	UserType getUserType(QString name);
	/*********************************************************/
	//声明三个鼠标事件函数
	void mouseReleaseEvent(QMouseEvent* event);
	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	void keyPressEvent(QKeyEvent* event);
	//鼠标是否按下属性
	bool m_bPressed = false;
	//按下后当前鼠标位置属性
	QPoint m_point;
	//testWidget.cpp中重写三个函数实现拖动
	MainWindow* w;
	/*********************************************************/
	QSqlDatabase db;
private slots:
	void on_pushbutton_loginClicked();
};
