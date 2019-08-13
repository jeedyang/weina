/********************************************************************************
** Form generated from reading UI file 'userwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERWIDGET_H
#define UI_USERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserWidget
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_current;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *label_userName;
    QLabel *label_3;
    QLabel *label_userType;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QTableView *tableView_user;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_addUser;
    QPushButton *pushButton_changePwd;
    QPushButton *pushButton_deleteUser;
    QPushButton *pushButton_addAdmin;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *UserWidget)
    {
        if (UserWidget->objectName().isEmpty())
            UserWidget->setObjectName(QString::fromUtf8("UserWidget"));
        UserWidget->resize(904, 707);
        UserWidget->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	\n"
"	font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"QWidget#widget_current\n"
"{\n"
"	\n"
"	\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        gridLayout = new QGridLayout(UserWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget = new QWidget(UserWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(800, 600));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget_current = new QWidget(widget);
        widget_current->setObjectName(QString::fromUtf8("widget_current"));
        horizontalLayout_2 = new QHBoxLayout(widget_current);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(widget_current);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        label_userName = new QLabel(widget_current);
        label_userName->setObjectName(QString::fromUtf8("label_userName"));

        horizontalLayout_2->addWidget(label_userName);

        label_3 = new QLabel(widget_current);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        label_userType = new QLabel(widget_current);
        label_userType->setObjectName(QString::fromUtf8("label_userType"));

        horizontalLayout_2->addWidget(label_userType);


        verticalLayout_2->addWidget(widget_current);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, -1, 0, -1);
        tableView_user = new QTableView(widget_3);
        tableView_user->setObjectName(QString::fromUtf8("tableView_user"));

        horizontalLayout->addWidget(tableView_user);

        groupBox = new QGroupBox(widget_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(15);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_addUser = new QPushButton(groupBox);
        pushButton_addUser->setObjectName(QString::fromUtf8("pushButton_addUser"));

        verticalLayout->addWidget(pushButton_addUser);

        pushButton_changePwd = new QPushButton(groupBox);
        pushButton_changePwd->setObjectName(QString::fromUtf8("pushButton_changePwd"));

        verticalLayout->addWidget(pushButton_changePwd);

        pushButton_deleteUser = new QPushButton(groupBox);
        pushButton_deleteUser->setObjectName(QString::fromUtf8("pushButton_deleteUser"));

        verticalLayout->addWidget(pushButton_deleteUser);

        pushButton_addAdmin = new QPushButton(groupBox);
        pushButton_addAdmin->setObjectName(QString::fromUtf8("pushButton_addAdmin"));

        verticalLayout->addWidget(pushButton_addAdmin);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout->addWidget(groupBox);


        verticalLayout_2->addWidget(widget_3);


        gridLayout->addWidget(widget, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(72, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 75, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);


        retranslateUi(UserWidget);

        QMetaObject::connectSlotsByName(UserWidget);
    } // setupUi

    void retranslateUi(QWidget *UserWidget)
    {
        UserWidget->setWindowTitle(QApplication::translate("UserWidget", "UserWidget", nullptr));
        label->setText(QApplication::translate("UserWidget", "\345\275\223\345\211\215\347\224\250\346\210\267:", nullptr));
        label_userName->setText(QApplication::translate("UserWidget", "user", nullptr));
        label_3->setText(QApplication::translate("UserWidget", "\347\261\273\345\236\213:", nullptr));
        label_userType->setText(QApplication::translate("UserWidget", "type", nullptr));
        groupBox->setTitle(QApplication::translate("UserWidget", "\346\223\215\344\275\234", nullptr));
        pushButton_addUser->setText(QApplication::translate("UserWidget", "\346\267\273\345\212\240\347\224\250\346\210\267", nullptr));
        pushButton_changePwd->setText(QApplication::translate("UserWidget", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        pushButton_deleteUser->setText(QApplication::translate("UserWidget", "\345\210\240\351\231\244\347\224\250\346\210\267", nullptr));
        pushButton_addAdmin->setText(QApplication::translate("UserWidget", "\346\267\273\345\212\240\347\256\241\347\220\206\345\221\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserWidget: public Ui_UserWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWIDGET_H
