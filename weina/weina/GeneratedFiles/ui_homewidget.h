/********************************************************************************
** Form generated from reading UI file 'homewidgetnlbLqX.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef HOMEWIDGETNLBLQX_H
#define HOMEWIDGETNLBLQX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomeWidget
{
public:
    QGridLayout *gridLayout;
    QWidget *widget_ctrl;
    QHBoxLayout *horizontalLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *page_0;
    QWidget *page_1;
    QWidget *page_2;
    QWidget *page_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QPushButton *pushButton_save;
    QWidget *widget_modbtn;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_mod0;
    QPushButton *pushButton_mod1;
    QPushButton *pushButton_mod2;
    QPushButton *pushButton_mod3;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *HomeWidget)
    {
        if (HomeWidget->objectName().isEmpty())
            HomeWidget->setObjectName(QString::fromUtf8("HomeWidget"));
        HomeWidget->resize(980, 621);
        gridLayout = new QGridLayout(HomeWidget);
        gridLayout->setSpacing(3);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(4, 4, 4, 4);
        widget_ctrl = new QWidget(HomeWidget);
        widget_ctrl->setObjectName(QString::fromUtf8("widget_ctrl"));
        horizontalLayout_2 = new QHBoxLayout(widget_ctrl);
        horizontalLayout_2->setSpacing(3);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(4, 4, 4, 4);
        stackedWidget = new QStackedWidget(widget_ctrl);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page_0 = new QWidget();
        page_0->setObjectName(QString::fromUtf8("page_0"));
        stackedWidget->addWidget(page_0);
        page_1 = new QWidget();
        page_1->setObjectName(QString::fromUtf8("page_1"));
        stackedWidget->addWidget(page_1);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        stackedWidget->addWidget(page_3);

        horizontalLayout_2->addWidget(stackedWidget);

        widget = new QWidget(widget_ctrl);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textBrowser = new QTextBrowser(widget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        pushButton_save = new QPushButton(widget);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));

        verticalLayout->addWidget(pushButton_save);


        horizontalLayout_2->addWidget(widget);


        gridLayout->addWidget(widget_ctrl, 1, 0, 1, 1);

        widget_modbtn = new QWidget(HomeWidget);
        widget_modbtn->setObjectName(QString::fromUtf8("widget_modbtn"));
        horizontalLayout = new QHBoxLayout(widget_modbtn);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_mod0 = new QPushButton(widget_modbtn);
        pushButton_mod0->setObjectName(QString::fromUtf8("pushButton_mod0"));
        pushButton_mod0->setCheckable(true);
        pushButton_mod0->setChecked(true);

        horizontalLayout->addWidget(pushButton_mod0);

        pushButton_mod1 = new QPushButton(widget_modbtn);
        pushButton_mod1->setObjectName(QString::fromUtf8("pushButton_mod1"));
        pushButton_mod1->setCheckable(true);

        horizontalLayout->addWidget(pushButton_mod1);

        pushButton_mod2 = new QPushButton(widget_modbtn);
        pushButton_mod2->setObjectName(QString::fromUtf8("pushButton_mod2"));
        pushButton_mod2->setCheckable(true);

        horizontalLayout->addWidget(pushButton_mod2);

        pushButton_mod3 = new QPushButton(widget_modbtn);
        pushButton_mod3->setObjectName(QString::fromUtf8("pushButton_mod3"));
        pushButton_mod3->setCheckable(true);

        horizontalLayout->addWidget(pushButton_mod3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addWidget(widget_modbtn, 0, 0, 1, 1);


        retranslateUi(HomeWidget);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(HomeWidget);
    } // setupUi

    void retranslateUi(QWidget *HomeWidget)
    {
        HomeWidget->setWindowTitle(QCoreApplication::translate("HomeWidget", "HomeWidget", nullptr));
        pushButton_save->setText(QCoreApplication::translate("HomeWidget", "PushButton", nullptr));
        pushButton_mod0->setText(QCoreApplication::translate("HomeWidget", "\346\250\241\345\235\2271", nullptr));
        pushButton_mod1->setText(QCoreApplication::translate("HomeWidget", "\346\250\241\345\235\2272", nullptr));
        pushButton_mod2->setText(QCoreApplication::translate("HomeWidget", "\346\250\241\345\235\2273", nullptr));
        pushButton_mod3->setText(QCoreApplication::translate("HomeWidget", "\346\250\241\345\235\2274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HomeWidget: public Ui_HomeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // HOMEWIDGETNLBLQX_H
