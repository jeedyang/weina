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
	//������������¼�����
	void mouseReleaseEvent(QMouseEvent* event);
	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	void keyPressEvent(QKeyEvent* event);
	//����Ƿ�������
	bool m_bPressed = false;
	//���º�ǰ���λ������
	QPoint m_point;
	//testWidget.cpp����д��������ʵ���϶�
	MainWindow* w;
	/*********************************************************/
	QSqlDatabase db;
private slots:
	void on_pushbutton_loginClicked();
};
