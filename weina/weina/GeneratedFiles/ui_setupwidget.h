/********************************************************************************
** Form generated from reading UI file 'setupwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETUPWIDGET_H
#define UI_SETUPWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetupWidget
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QTableWidget *tableWidget_classPam;
    QWidget *tab_4;
    QHBoxLayout *horizontalLayout_3;
    QTableWidget *tableWidget_testPam;
    QWidget *tab_3;
    QGridLayout *gridLayout_9;
    QTableWidget *tableWidget_locationPam;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_save;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *SetupWidget)
    {
        if (SetupWidget->objectName().isEmpty())
            SetupWidget->setObjectName(QString::fromUtf8("SetupWidget"));
        SetupWidget->resize(982, 730);
        gridLayout = new QGridLayout(SetupWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(SetupWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8("QPushButton {  \n"
"    font-size:20px;\n"
"    border-radius:2px;\n"
"    color:rgba(51,51,51,1);\n"
"    background:qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgba(242,242,242,1), stop:1 rgba(255,255,255,1));\n"
"    border:1px solid rgba(221,221,221,1);\n"
"}\n"
"QPushButton\n"
"{\n"
"	background-color: rgb(224, 239, 212);\n"
"\n"
"	border-color: rgb(124, 124, 124);\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"    background-color:rgb(255, 227, 197);\n"
"}\n"
"QPushButton::pressed\n"
"{\n"
"    background-color:rgb(255, 110, 94);\n"
"}\n"
"QPushButton::checked \n"
"{\n"
"	background-color: rgb(255, 110, 94);\n"
"}"));
        tabWidget->setUsesScrollButtons(true);
        tabWidget->setTabBarAutoHide(true);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tableWidget_classPam = new QTableWidget(tab);
        tableWidget_classPam->setObjectName(QString::fromUtf8("tableWidget_classPam"));

        gridLayout_2->addWidget(tableWidget_classPam, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        horizontalLayout_3 = new QHBoxLayout(tab_4);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        tableWidget_testPam = new QTableWidget(tab_4);
        tableWidget_testPam->setObjectName(QString::fromUtf8("tableWidget_testPam"));

        horizontalLayout_3->addWidget(tableWidget_testPam);

        tabWidget->addTab(tab_4, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_9 = new QGridLayout(tab_3);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        tableWidget_locationPam = new QTableWidget(tab_3);
        tableWidget_locationPam->setObjectName(QString::fromUtf8("tableWidget_locationPam"));

        gridLayout_9->addWidget(tableWidget_locationPam, 0, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalLayout_2 = new QHBoxLayout(tab_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        widget = new QWidget(SetupWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 50));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, 0);
        pushButton_save = new QPushButton(widget);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));
        pushButton_save->setMinimumSize(QSize(120, 50));

        horizontalLayout->addWidget(pushButton_save);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addWidget(widget, 1, 0, 1, 1);


        retranslateUi(SetupWidget);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(SetupWidget);
    } // setupUi

    void retranslateUi(QWidget *SetupWidget)
    {
        SetupWidget->setWindowTitle(QCoreApplication::translate("SetupWidget", "SetupWidget", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("SetupWidget", "\345\210\206\346\241\243\345\217\202\346\225\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("SetupWidget", "\346\243\200\346\265\213\345\217\202\346\225\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("SetupWidget", "\345\256\232\344\275\215\345\217\202\346\225\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("SetupWidget", "\345\205\266\344\273\226\345\217\202\346\225\260", nullptr));
        pushButton_save->setText(QCoreApplication::translate("SetupWidget", "\344\277\235\345\255\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SetupWidget: public Ui_SetupWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETUPWIDGET_H
