#include "loginwidget.h"
#include <QMessageBox>

#include <QDebug>

LoginWidget::LoginWidget( QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | windowFlags());
	w = new MainWindow();
	QObject::connect(ui.pushButton_login,SIGNAL(clicked()),this,SLOT(on_pushbutton_loginClicked()));

	dbInit();
}

LoginWidget::~LoginWidget()
{
	delete w;
}

void LoginWidget::on_pushbutton_loginClicked()
{

	if (login())
	{
		QMessageBox::warning(this, _tr("错误"), _tr("用户密码输出错误，请重新输入！"));
		return;
	}
	userInfo.userName = ui.comboBox_user->currentText();
	userInfo.type = getUserType(userInfo.userName);
	userInfo.password = ui.lineEdit_password->text();

	w->setUsetInfo(userInfo);
	this->hide();
	QSqlDatabase::removeDatabase("mysqlite");
	w->showFullScreen();
	
}



void LoginWidget::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)//判断左键是否按下
	{
		m_bPressed = true;
		m_point = event->pos();
	}
}

void LoginWidget::mouseReleaseEvent(QMouseEvent* event)
{
	Q_UNUSED(event);
	m_bPressed = false;
}

void LoginWidget::mouseMoveEvent(QMouseEvent* event)
{
	if (m_bPressed)
		move(event->pos() - m_point + pos());//移动当前窗口
}


void LoginWidget::keyPressEvent(QKeyEvent* event)
{
	if (event->key() == Qt::Key_Return||event->key() == Qt::Key_Enter)
	{
		on_pushbutton_loginClicked();
		return;
	}

	QWidget::keyPressEvent(event);
}

void LoginWidget::dbInit()
{
	
	db = QSqlDatabase::addDatabase("QSQLITE", "mysqlite");
	db.setDatabaseName("Database.db");
	if (QSqlDatabase::contains("mysqlite")) {
		db = QSqlDatabase::database("mysqlite");
	}
	else {
		db = QSqlDatabase::addDatabase("QSQLITE", "mysqlite");
	}
	if (!db.open()) {
		QMessageBox::warning(this, _tr("错误"), _tr("打开数据库失败！"));
		return;
	}
	QStringList userList;
	QSqlQuery query(db);
	query.exec(_tr("SELECT 名称 FROM user"));
	while (query.next()) {
		QString user = query.value(0).toString();
		userList.append(user);
	}
	for (int i = userList.size() - 1; i >= 0; i--)
	{
		ui.comboBox_user->addItem(userList[i]);
	}

	qDebug() << userList;
	db.close();
}

int LoginWidget::login()
{
	db.open();
	QSqlQuery query(db);
	query.prepare(_tr("SELECT 密码 FROM user WHERE 名称 = '%1'").arg(ui.comboBox_user->currentText()));
	QString userPwd;
	if (!query.exec())
	{
		qDebug() << query.lastError();
	}
	else
	{
		while (query.next()) {
			userPwd = query.value(0).toString();
		}
	}
	//qDebug() << "pwd=" << userPwd;
	db.close();
	if (ui.lineEdit_password->text() == userPwd)
	{
		return 0;
	}
	return -1;
}

UserType LoginWidget::getUserType(QString name)
{
	db.open();
	QSqlQuery query(db);
	query.prepare(_tr("SELECT 用户类型 FROM user WHERE 名称 = '%1'").arg(name));
	QString userType;
	if (!query.exec())
	{
		qDebug() << query.lastError();
	}
	else
	{
		while (query.next()) {
			userType = query.value(0).toString();
		}
	}
	qDebug() << "userType=" << userType;
	db.close();
	if (_tr("普通用户") == userType)
	{
		return UserType::general;
	}
	if (_tr("管理员") == userType)
	{
		return UserType::admin;
	}
	if (_tr("超级管理员") == userType)
	{
		return UserType::superAdmin;
	}
	return UserType::general;
}
