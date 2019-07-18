/********************************************************************************
** Form generated from reading UI file 'mainwindowFcSfAc.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOWFCSFAC_H
#define MAINWINDOWFCSFAC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <homewidget.h>
#include "debugwidget.h"
#include "setupwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_title;
    QWidget *widget_frame;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget_main;
    HomeWidget *main_widget;
    SetupWidget *setup_widget;
    DebugWidget *debug_widget;
    QWidget *page_3;
    QWidget *page_4;
    QWidget *widget_menu;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_home;
    QPushButton *pushButton_setup;
    QPushButton *pushButton_debug;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
        MainWindowClass->resize(1024, 768);
        MainWindowClass->setMinimumSize(QSize(1024, 768));
        MainWindowClass->setMaximumSize(QSize(1024, 768));
        MainWindowClass->setStyleSheet(QString::fromUtf8(""));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8("QWidget #widget_title, #stackedWidget_main, #widget_menu\n"
"{\n"
"	border-style:solid;\n"
"	border-radius:2px;\n"
"	border-color:#00BB9E;\n"
"	border-width:2px 2px 2px 2px;\n"
"	background-color: rgb(246, 255, 221);\n"
"}\n"
"\n"
"QPushButton #pushButton_home\n"
"{\n"
"	border-style:solid;\n"
"	border-radius:5px;\n"
"	border-color:#00BB9E;\n"
"	border-width:2px 2px 2px 2px;\n"
"	background-color: rgb(246, 255, 221);\n"
"}"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(4);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_title = new QWidget(centralWidget);
        widget_title->setObjectName(QString::fromUtf8("widget_title"));
        widget_title->setMinimumSize(QSize(0, 100));
        widget_title->setMaximumSize(QSize(16777215, 100));
        widget_title->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(widget_title);

        widget_frame = new QWidget(centralWidget);
        widget_frame->setObjectName(QString::fromUtf8("widget_frame"));
        widget_frame->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(widget_frame);
        horizontalLayout->setSpacing(4);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget_main = new QStackedWidget(widget_frame);
        stackedWidget_main->setObjectName(QString::fromUtf8("stackedWidget_main"));
        stackedWidget_main->setStyleSheet(QString::fromUtf8(""));
        main_widget = new HomeWidget();
        main_widget->setObjectName(QString::fromUtf8("main_widget"));
        stackedWidget_main->addWidget(main_widget);
        setup_widget = new SetupWidget();
        setup_widget->setObjectName(QString::fromUtf8("setup_widget"));
        stackedWidget_main->addWidget(setup_widget);
        debug_widget = new DebugWidget();
        debug_widget->setObjectName(QString::fromUtf8("debug_widget"));
        stackedWidget_main->addWidget(debug_widget);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        stackedWidget_main->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        stackedWidget_main->addWidget(page_4);

        horizontalLayout->addWidget(stackedWidget_main);

        widget_menu = new QWidget(widget_frame);
        widget_menu->setObjectName(QString::fromUtf8("widget_menu"));
        widget_menu->setMinimumSize(QSize(120, 0));
        widget_menu->setMaximumSize(QSize(120, 16777215));
        widget_menu->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(widget_menu);
        verticalLayout_2->setSpacing(4);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(3, 30, 3, 12);
        pushButton_home = new QPushButton(widget_menu);
        pushButton_home->setObjectName(QString::fromUtf8("pushButton_home"));
        pushButton_home->setMinimumSize(QSize(0, 60));
        pushButton_home->setStyleSheet(QString::fromUtf8(""));
        pushButton_home->setCheckable(true);

        verticalLayout_2->addWidget(pushButton_home);

        pushButton_setup = new QPushButton(widget_menu);
        pushButton_setup->setObjectName(QString::fromUtf8("pushButton_setup"));
        pushButton_setup->setMinimumSize(QSize(0, 60));
        pushButton_setup->setStyleSheet(QString::fromUtf8(""));
        pushButton_setup->setCheckable(true);

        verticalLayout_2->addWidget(pushButton_setup);

        pushButton_debug = new QPushButton(widget_menu);
        pushButton_debug->setObjectName(QString::fromUtf8("pushButton_debug"));
        pushButton_debug->setMinimumSize(QSize(0, 60));
        pushButton_debug->setStyleSheet(QString::fromUtf8(""));
        pushButton_debug->setCheckable(true);

        verticalLayout_2->addWidget(pushButton_debug);

        verticalSpacer = new QSpacerItem(20, 297, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addWidget(widget_menu);


        verticalLayout->addWidget(widget_frame);

        MainWindowClass->setCentralWidget(centralWidget);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", nullptr));
        pushButton_home->setText(QApplication::translate("MainWindowClass", "\344\270\273\347\225\214\351\235\242", nullptr));
        pushButton_setup->setText(QApplication::translate("MainWindowClass", "\350\256\276\347\275\256", nullptr));
        pushButton_debug->setText(QApplication::translate("MainWindowClass", "\350\260\203\350\257\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOWFCSFAC_H
