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
		QMessageBox::warning(this, _tr("����"), _tr("�û���������������������룡"));
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
	if (event->button() == Qt::LeftButton)//�ж�����Ƿ���
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
		move(event->pos() - m_point + pos());//�ƶ���ǰ����
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
		QMessageBox::warning(this, _tr("����"), _tr("�����ݿ�ʧ�ܣ�"));
		return;
	}
	QStringList userList;
	QSqlQuery query(db);
	query.exec(_tr("SELECT ���� FROM user"));
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
	query.prepare(_tr("SELECT ���� FROM user WHERE ���� = '%1'").arg(ui.comboBox_user->currentText()));
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
	query.prepare(_tr("SELECT �û����� FROM user WHERE ���� = '%1'").arg(name));
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
	if (_tr("��ͨ�û�") == userType)
	{
		return UserType::general;
	}
	if (_tr("����Ա") == userType)
	{
		return UserType::admin;
	}
	if (_tr("��������Ա") == userType)
	{
		return UserType::superAdmin;
	}
	return UserType::general;
}
