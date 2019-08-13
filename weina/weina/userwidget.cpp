#include "userwidget.h"
#include <QMessageBox>
#include <QDebug>
#include <QFormLayout>
#include <QLineEdit>
#include <QDialogButtonBox>

#define _tr(str) QString::fromLocal8Bit(str)

UserWidget::UserWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//tableInit();
	QObject::connect(ui.pushButton_deleteUser,SIGNAL(clicked()),this,SLOT(on_pushButton_deleteClicked()));
	QObject::connect(ui.pushButton_addUser, SIGNAL(clicked()), this, SLOT(on_pushButton_addClicked()));
	QObject::connect(ui.pushButton_changePwd, SIGNAL(clicked()), this, SLOT(on_pushButton_changeClicked()));
	QObject::connect(ui.pushButton_addAdmin, SIGNAL(clicked()), this, SLOT(on_pushButton_addADminClicked()));

	db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("Database.db");
	if (!db.open()) {
		QMessageBox::warning(this, _tr("����"), _tr("�����ݿ�ʧ�ܣ�"));
		return;
	}
	refreshTable();
}

UserWidget::~UserWidget()
{
}

void UserWidget::showWidget()
{
	refreshTable();
	if (m_userInfo.type==UserType::general)
	{
		ui.pushButton_addUser->setEnabled(false);
		ui.pushButton_deleteUser->setEnabled(false);
		ui.pushButton_addAdmin->setEnabled(false);
	}
	ui.label_userName->setText(m_userInfo.userName);
	if (m_userInfo.type == UserType::general)
	{
		ui.label_userType->setText(_tr("��ͨ�û�"));
	}
	if (m_userInfo.type == UserType::admin)
	{
		ui.label_userType->setText(_tr("����Ա"));
	}
	if (m_userInfo.type == UserType::superAdmin)
	{
		ui.label_userType->setText(_tr("��������Ա"));
	}
}

void UserWidget::hideWidget()
{
}

UserTable UserWidget::getUserlist()
{
	QStringList userNameList;
	QStringList userIDList;
	QStringList userTypeList;


	db = QSqlDatabase::addDatabase("QSQLITE", "usersql");
	db.setDatabaseName("Database.db");
	if (QSqlDatabase::contains("usersql")) {
		db = QSqlDatabase::database("usersql");
	}
	else {
		db = QSqlDatabase::addDatabase("QSQLITE", "usersql");
	}
	if (!db.open()) {
		QMessageBox::warning(this, _tr("����"), _tr("�����ݿ�ʧ�ܣ�"));
		return UserTable();
	}

	QSqlQuery query(db);
	if (m_userInfo.type==UserType::general)
	{
		query.exec(_tr("SELECT ���� FROM user WHERE �û����� = '%1'").arg(_tr("��ͨ�û�")));
	}
	else if (m_userInfo.type == UserType::admin)
	{
		query.exec(_tr("SELECT ���� FROM user WHERE �û����� = '%1' OR �û����� = '%2'").arg(_tr("��ͨ�û�")).arg(_tr("����Ա")));
	}
	else if (m_userInfo.type == UserType::superAdmin)
	{
		query.exec(_tr("SELECT ���� FROM user"));
	}
	else
	{
		return UserTable();
	}
	while (query.next()) {
		QString user = query.value(0).toString();
		userNameList.append(user);
	}
	qDebug() << userNameList;


	if (m_userInfo.type == UserType::general)
	{
		query.exec(_tr("SELECT ID FROM user WHERE �û����� = '%1'").arg(_tr("��ͨ�û�")));
	}
	else if (m_userInfo.type == UserType::admin)
	{
		query.exec(_tr("SELECT ID FROM user WHERE �û����� = '%1' OR �û����� = '%2'").arg(_tr("��ͨ�û�")).arg(_tr("����Ա")));
	}
	else if (m_userInfo.type == UserType::superAdmin)
	{
		query.exec(_tr("SELECT ID FROM user"));
	}
	while (query.next()) {
		QString id = query.value(0).toString();
		userIDList.append(id);
	}

	if (m_userInfo.type == UserType::general)
	{
		query.exec(_tr("SELECT �û����� FROM user WHERE �û����� = '%1'").arg(_tr("��ͨ�û�")));
	}
	else if (m_userInfo.type == UserType::admin)
	{
		query.exec(_tr("SELECT �û����� FROM user WHERE �û����� = '%1' OR �û����� = '%2'").arg(_tr("��ͨ�û�")).arg(_tr("����Ա")));
	}
	else if (m_userInfo.type == UserType::superAdmin)
	{
		query.exec(_tr("SELECT �û����� FROM user"));
	}
	while (query.next()) {
		QString type = query.value(0).toString();
		userTypeList.append(type);
	}

	UserTable userTab;
	userTab.userNameList = userNameList;
	userTab.userIDList = userIDList;
	userTab.userTypeList = userTypeList;
	db.close();
	return userTab;
}

void UserWidget::tableInit()
{
	//ui.tableView_user->setColumnCount(3);
	//QStringList tableHeader;
	//tableHeader.append(_tr("ID"));
	//tableHeader.append(_tr("�û���"));
	//tableHeader.append(_tr("�û�����"));
	//ui.tableView_user->setHorizontalHeaderLabels(tableHeader);
	//ui.tableView_user->setColumnWidth(0,800/3-20);
	//ui.tableView_user->setColumnWidth(1, 800 / 3-20);
	//ui.tableView_user->setColumnWidth(2, 800 / 3-20);
	//ui.tableView_user->setEditTriggers(QAbstractItemView::NoEditTriggers);
	//ui.tableView_user->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
}

void UserWidget::refreshTable()
{
	model = new QSqlTableModel(this);//���������ʵ����
	model->setTable("user");
	model->select();
	//model->setEditStrategy(QSqlTableModel::OnManualSubmit);
	model->setEditStrategy(QSqlTableModel::OnFieldChange);//����Ϊ�Զ�����DB
	ui.tableView_user->setModel(model);
	ui.tableView_user->setSelectionBehavior(QAbstractItemView::SelectRows);//����Ϊ����ѡ
	ui.tableView_user->setColumnHidden(model->fieldIndex(_tr("����")), true);
	ui.tableView_user->setColumnWidth(0, 800 / 3 - 20);
	ui.tableView_user->setColumnWidth(1, 800 / 3 - 20);
	ui.tableView_user->setColumnWidth(3, 800 / 3 - 20);
	ui.tableView_user->setEditTriggers(QAbstractItemView::NoEditTriggers);
	//UserTable userTable;
	//userTable = getUserlist();
	//ui.tableView_user->setRowCount(userTable.userIDList.size());
	//for (int i = 0; i < userTable.userIDList.size(); i++)
	//{
	//	ui.tableView_user->setItem(i,0, new QTableWidgetItem(userTable.userIDList[i]));
	//}
	//for (int i = 0; i < userTable.userNameList.size(); i++)
	//{
	//	ui.tableView_user->setItem(i, 1, new QTableWidgetItem(userTable.userNameList[i]));
	//}
	//for (int i = 0; i < userTable.userTypeList.size(); i++)
	//{
	//	ui.tableView_user->setItem(i, 2, new QTableWidgetItem(userTable.userTypeList[i]));
	//}
}

void UserWidget::addUser(UserType usertype)
{
	QDialog dialog(this);
	//dialog.setWindowFlags(Qt::FramelessWindowHint | windowFlags());
	dialog.setBaseSize(QSize(800,400));
	QFormLayout form(&dialog);
	form.addRow(new QLabel("User input:"));
	// Value1
	QString value1 = QString("Name: ");
	QLineEdit* username = new QLineEdit(&dialog);
	form.addRow(value1, username);
	// Value2
	QString value2 = QString("Pwssword: ");
	QLineEdit* pwd = new QLineEdit(&dialog);
	pwd->setEchoMode(QLineEdit::Password);
	form.addRow(value2, pwd);
	// Value3
	QString value3 = QString("Confirm Password: ");
	QLineEdit* pwdagain = new QLineEdit(&dialog);
	pwdagain->setEchoMode(QLineEdit::Password);
	form.addRow(value3, pwdagain);
	// Add Cancel and OK button
	QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
		Qt::Horizontal, &dialog);
	form.addRow(&buttonBox);
	QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
	QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

	// Process when OK button is clicked
	if (dialog.exec() == QDialog::Accepted) {
		// Do something here
		if (username->text() == "" || pwd->text() == "" || pwdagain->text() == "")
		{
			QMessageBox::warning(this, _tr("����"), _tr("�û���������Ϊ�գ�"));
			return;
		}
		if (pwd->text() != pwdagain->text())
		{
			QMessageBox::warning(this, _tr("����"), _tr("������������벻һ�£�"));
			return;
		}
		if (!db.open())
			QMessageBox::warning(this, _tr("����"), _tr("�����ݿ���ִ���"));
		QSqlQuery q(db);
		QString sql;
		if (usertype==UserType::admin)
		{
			sql = _tr("INSERT INTO user(����,����,�û�����) VALUES('%1', '%2','����Ա')").arg(username->text()).arg(pwd->text());
		}		
		else if (usertype == UserType::general)
		{
			sql = _tr("INSERT INTO user(����,����,�û�����) VALUES('%1', '%2','��ͨ�û�')").arg(username->text()).arg(pwd->text());
		}

		if (!q.exec(sql))
		{
			QMessageBox::warning(this, _tr("����"), _tr("����û�����"));
			db.close();
			return;
		}
		refreshTable();
		db.close();
	}
}

void UserWidget::on_pushButton_addClicked()
{
	addUser(UserType::general);
}

void UserWidget::on_pushButton_addADminClicked()
{
	addUser(UserType::admin);
}

void UserWidget::on_pushButton_changeClicked()
{
	QTableView* m_pTableView = ui.tableView_user;
	QModelIndexList selected = m_pTableView->selectionModel()->selectedRows();
	QList<int> rows;
	foreach(const QModelIndex & index, selected)
	{
		rows.append(index.row());
	}
	if (rows.size()==0)
	{
		return;
	}
	QAbstractItemModel* model = ui.tableView_user->model();
	QModelIndex index = model->index(rows[0], 1);//ѡ���е�2�е�����,����
	QVariant data = model->data(index);
	if (data.toString()!=m_userInfo.userName&m_userInfo.type==UserType::general)
	{
		QMessageBox::warning(this, _tr("����"), _tr("����Ȩ�޸ĸ��û������룡"));
		return;
	}

	QDialog dialog(this);
	QFormLayout form(&dialog);
	form.addRow(new QLabel("User input:"));
	// Value1
	QString value1 = QString("Old Pwssword: ");
	QLineEdit* oldpwd = new QLineEdit(&dialog);
	oldpwd->setEchoMode(QLineEdit::Password);
	form.addRow(value1, oldpwd);
	// Value2
	QString value2 = QString("New Pwssword: ");
	QLineEdit* newpwd = new QLineEdit(&dialog);
	newpwd->setEchoMode(QLineEdit::Password);
	form.addRow(value2, newpwd);
	// Value3
	QString value3 = QString("Confirm New Pwssword: ");
	QLineEdit* newpwdagain = new QLineEdit(&dialog);
	newpwdagain->setEchoMode(QLineEdit::Password);
	form.addRow(value3, newpwdagain);
	// Add Cancel and OK button
	QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
		Qt::Horizontal, &dialog);
	form.addRow(&buttonBox);
	QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
	QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

	// Process when OK button is clicked
	if (dialog.exec() == QDialog::Accepted) {
		QString userpwd;

		if (!db.open())
			QMessageBox::warning(this, _tr("����"), _tr("�����ݿ���ִ���"));
		QSqlQuery q(db);
		if (!q.exec(_tr("SELECT ���� FROM user WHERE ���� = '%1'").arg(data.toString())))
		{
			QMessageBox::warning(this, _tr("����"), _tr("���ݿ����"));
			db.close();
			return;
		}
		else
		{
			while (q.next()) {
				userpwd = q.value(0).toString();
			}
		}
		db.close();
		qDebug() << _tr("��������룺") << oldpwd->text() << _tr("ԭ���룺") << userpwd << _tr("�û���") << data;
		if (oldpwd->text() == "" || newpwd->text() == "" || newpwdagain->text() == "")
		{
			QMessageBox::warning(this, _tr("����"), _tr("����Ϊ�գ�"));
			return;
		}
		if (oldpwd->text() != userpwd)
		{
			QMessageBox::warning(this, _tr("����"), _tr("ԭ���벻��ȷ��"));
			return;
		}
		if (newpwd->text() != newpwdagain->text())
		{
			QMessageBox::warning(this, _tr("����"), _tr("������������벻��ȷ��"));
			return;
		}
		if (!db.open()) {
			QMessageBox::warning(this, _tr("����"), _tr("�����ݿ���ִ���"));
			db.close();
			return;
		}
		if (!q.exec(_tr("UPDATE user SET ���� = '%1' WHERE ���� = '%2'").arg(newpwd->text()).arg(data.toString())))
		{
			QMessageBox::warning(this, _tr("����"), _tr("���ݿ����"));
			db.close();
			return;
		}
		QMessageBox::warning(this, _tr("����"), _tr("�û� '%1'�������޸ĳɹ���").arg(data.toString()));
	}
}

void UserWidget::on_pushButton_deleteClicked()
{
	QModelIndexList selected = ui.tableView_user->selectionModel()->selectedRows();
	QList<int> rows;
	foreach(const QModelIndex & index, selected)
	{
		rows.append(index.row());
	}

	if (rows.size() < 1)
	{
		QMessageBox::warning(this, _tr("����"), _tr("��ѡ��Ҫɾ�����û���"));
		return;
	}
	if (rows.size() > 1)
	{
		QMessageBox::warning(this, _tr("����"), _tr("������ͬʱɾ������û���"));
		return;
	}
	QAbstractItemModel* model = ui.tableView_user->model();
	QModelIndex index = model->index(rows[0], 1);//ѡ���е�2�е�����,����
	QVariant data = model->data(index);
	if (data.toString()==m_userInfo.userName)
	{
		QMessageBox::warning(this, _tr("����"), _tr("������ɾ���Լ���"));
		return;
	}
	QMessageBox msgBox;
	msgBox.setText(_tr("ȷ�����Ĳ�����"));
	msgBox.setInformativeText(_tr("��ȷ��Ҫɾ�����û���?"));
	msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	msgBox.setDefaultButton(QMessageBox::Cancel);
	int ret = msgBox.exec();
	if (ret!=QMessageBox::Ok)
	{
		return;
	}

	if (!db.open()) {
		QMessageBox::warning(this, _tr("����"), _tr("�����ݿ�ʧ�ܣ�"));
		return ;
	}
	QSqlQuery query(db);
	query.exec(_tr("DELETE FROM user WHERE ���� = '%1'").arg(data.toString()));
	db.close();
	refreshTable();
}
