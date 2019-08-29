/********************************************************************************
** Form generated from reading UI file 'homewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEWIDGET_H
#define UI_HOMEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
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
    QTableWidget *tableWidget;
    QPushButton *pushButton_clearTable;
    QPushButton *pushButton_saveToExcel;
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
        tableWidget = new QTableWidget(widget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        pushButton_clearTable = new QPushButton(widget);
        pushButton_clearTable->setObjectName(QString::fromUtf8("pushButton_clearTable"));

        verticalLayout->addWidget(pushButton_clearTable);

        pushButton_saveToExcel = new QPushButton(widget);
        pushButton_saveToExcel->setObjectName(QString::fromUtf8("pushButton_saveToExcel"));

        verticalLayout->addWidget(pushButton_saveToExcel);


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
        HomeWidget->setWindowTitle(QApplication::translate("HomeWidget", "HomeWidget", nullptr));
        pushButton_clearTable->setText(QApplication::translate("HomeWidget", "\346\270\205\351\231\244\350\241\250\346\240\274", nullptr));
        pushButton_saveToExcel->setText(QApplication::translate("HomeWidget", "\344\277\235\345\255\230\350\207\263Excel", nullptr));
        pushButton_mod0->setText(QApplication::translate("HomeWidget", "\346\250\241\345\235\2270", nullptr));
        pushButton_mod1->setText(QApplication::translate("HomeWidget", "\346\250\241\345\235\2271", nullptr));
        pushButton_mod2->setText(QApplication::translate("HomeWidget", "\346\250\241\345\235\2272", nullptr));
        pushButton_mod3->setText(QApplication::translate("HomeWidget", "\346\250\241\345\235\2273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HomeWidget: public Ui_HomeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEWIDGET_H
