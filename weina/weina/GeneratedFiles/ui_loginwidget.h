/********************************************************************************
** Form generated from reading UI file 'loginwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIDGET_H
#define UI_LOGINWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWidget
{
public:
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QWidget *widget_2;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *comboBox_user;
    QLabel *label_2;
    QLineEdit *lineEdit_password;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_login;
    QPushButton *pushButton_exit;

    void setupUi(QWidget *LoginWidget)
    {
        if (LoginWidget->objectName().isEmpty())
            LoginWidget->setObjectName(QString::fromUtf8("LoginWidget"));
        LoginWidget->resize(638, 297);
        LoginWidget->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QWidget#LoginWidget\n"
"{\n"
"	border-style:solid;\n"
"	border-radius:5px;\n"
"	border-color: rgb(102, 102, 102);;\n"
"	border-width:1px 1px 1px 1px;\n"
"	\n"
"	background-color: qlineargradient(spread:pad, x1:0.873134, y1:1, x2:0.48, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"}\n"
"QWidget#widget_4 \n"
"{\n"
"	\n"
"	background-color: rgb(50, 50, 50);\n"
"\n"
"}\n"
"QWidget#widget_5 ,#widget\n"
"{\n"
"	\n"
"	\n"
"	background-color: rgb(255, 255, 255);\n"
"\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(LoginWidget);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(1, 1, 1, 1);
        widget_4 = new QWidget(LoginWidget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        verticalLayout_2 = new QVBoxLayout(widget_4);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_5);

        label_3 = new QLabel(widget_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 24pt \"\346\226\260\345\256\213\344\275\223\";\n"
"color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(label_3);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        label_4 = new QLabel(widget_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 8pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(label_4);

        label_5 = new QLabel(widget_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font: 8pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(label_5);


        horizontalLayout_3->addWidget(widget_4);

        widget_5 = new QWidget(LoginWidget);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setMaximumSize(QSize(300, 16777215));
        verticalLayout = new QVBoxLayout(widget_5);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 10);
        widget = new QWidget(widget_5);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 32));
        widget->setMaximumSize(QSize(16777215, 32));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(7);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(258, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(32, 32));
        pushButton->setMaximumSize(QSize(32, 32));
        pushButton->setSizeIncrement(QSize(0, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/png/res/png/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(widget_5);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        formLayout = new QFormLayout(widget_2);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        comboBox_user = new QComboBox(widget_2);
        comboBox_user->setObjectName(QString::fromUtf8("comboBox_user"));

        formLayout->setWidget(1, QFormLayout::FieldRole, comboBox_user);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_2);

        lineEdit_password = new QLineEdit(widget_2);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_password);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(0, QFormLayout::FieldRole, verticalSpacer);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(2, QFormLayout::FieldRole, verticalSpacer_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(4, QFormLayout::FieldRole, verticalSpacer_3);


        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(widget_5);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_login = new QPushButton(widget_3);
        pushButton_login->setObjectName(QString::fromUtf8("pushButton_login"));

        horizontalLayout->addWidget(pushButton_login);

        pushButton_exit = new QPushButton(widget_3);
        pushButton_exit->setObjectName(QString::fromUtf8("pushButton_exit"));

        horizontalLayout->addWidget(pushButton_exit);


        verticalLayout->addWidget(widget_3);


        horizontalLayout_3->addWidget(widget_5);


        retranslateUi(LoginWidget);
        QObject::connect(pushButton, SIGNAL(clicked()), LoginWidget, SLOT(close()));
        QObject::connect(pushButton_exit, SIGNAL(clicked()), LoginWidget, SLOT(close()));

        QMetaObject::connectSlotsByName(LoginWidget);
    } // setupUi

    void retranslateUi(QWidget *LoginWidget)
    {
        LoginWidget->setWindowTitle(QApplication::translate("LoginWidget", "LoginWidget", nullptr));
        label_3->setText(QApplication::translate("LoginWidget", "\347\231\273\345\275\225\347\263\273\347\273\237", nullptr));
        label_4->setText(QApplication::translate("LoginWidget", "\345\220\210\350\202\245\347\221\236\346\234\227\350\207\252\345\212\250\345\214\226\350\256\276\345\244\207\346\234\211\351\231\220\345\205\254\345\217\270", nullptr));
        label_5->setText(QApplication::translate("LoginWidget", "Tel:0551-65373157", nullptr));
        pushButton->setText(QString());
        label->setText(QApplication::translate("LoginWidget", "\347\224\250\346\210\267:", nullptr));
        label_2->setText(QApplication::translate("LoginWidget", "\345\257\206\347\240\201:", nullptr));
        pushButton_login->setText(QApplication::translate("LoginWidget", "\347\231\273\345\275\225", nullptr));
        pushButton_exit->setText(QApplication::translate("LoginWidget", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWidget: public Ui_LoginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIDGET_H
