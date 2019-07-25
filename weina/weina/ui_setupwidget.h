/********************************************************************************
** Form generated from reading UI file 'setupwidgetMlzQIZ.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SETUPWIDGETMLZQIZ_H
#define SETUPWIDGETMLZQIZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
    QTableWidget *tableWidget_testPam;
    QWidget *tab_3;
    QGridLayout *gridLayout_9;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_2;

    void setupUi(QWidget *SetupWidget)
    {
        if (SetupWidget->objectName().isEmpty())
            SetupWidget->setObjectName(QString::fromUtf8("SetupWidget"));
        SetupWidget->resize(880, 492);
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
"    font-size:12px;\n"
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
        tableWidget_testPam = new QTableWidget(tab);
        tableWidget_testPam->setObjectName(QString::fromUtf8("tableWidget_testPam"));

        gridLayout_2->addWidget(tableWidget_testPam, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_9 = new QGridLayout(tab_3);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalLayout_2 = new QHBoxLayout(tab_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(SetupWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SetupWidget);
    } // setupUi

    void retranslateUi(QWidget *SetupWidget)
    {
        SetupWidget->setWindowTitle(QApplication::translate("SetupWidget", "SetupWidget", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("SetupWidget", "\346\243\200\346\265\213\345\217\202\346\225\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("SetupWidget", "\345\256\232\344\275\215\345\217\202\346\225\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("SetupWidget", "\345\205\266\344\273\226\345\217\202\346\225\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SetupWidget: public Ui_SetupWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SETUPWIDGETMLZQIZ_H
