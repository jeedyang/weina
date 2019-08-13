/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <userwidget.h>
#include "debugwidget.h"
#include "homewidget.h"
#include "logwidget.h"
#include "reportwidget.h"
#include "setupwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_title;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_close;
    QWidget *widget_frame;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget_main;
    HomeWidget *main_widget;
    SetupWidget *setup_widget;
    DebugWidget *debug_widget;
    LogWidget *log_widget;
    ReportWidget *report_widget;
    UserWidget *user_widget;
    QWidget *widget_menu;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_home;
    QPushButton *pushButton_setup;
    QPushButton *pushButton_debug;
    QPushButton *pushButton_log;
    QPushButton *pushButton_report;
    QPushButton *pushButton_user;
    QPushButton *pushButton_min;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_pause;
    QPushButton *pushButton_start;

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
        widget_title->setMinimumSize(QSize(0, 80));
        widget_title->setMaximumSize(QSize(16777215, 80));
        widget_title->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_2 = new QHBoxLayout(widget_title);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 3, 0);
        label_2 = new QLabel(widget_title);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 10pt \"\346\245\267\344\275\223\";"));

        horizontalLayout_2->addWidget(label_2);

        label = new QLabel(widget_title);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 24pt \"\346\245\267\344\275\223\";"));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer = new QSpacerItem(917, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_close = new QPushButton(widget_title);
        pushButton_close->setObjectName(QString::fromUtf8("pushButton_close"));
        pushButton_close->setMinimumSize(QSize(75, 75));
        pushButton_close->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{  \n"
"	\n"
"	border-image: url(:/png/res/png/exit.png);\n"
"}\n"
"\n"
"QPushButton::hover\n"
"{\n"
"    border-image: url(:/png/res/png/exit.png);\n"
"}\n"
"QPushButton::pressed\n"
"{\n"
"    border-image: url(:/png/res/png/exit.png);\n"
"}\n"
"QPushButton::checked \n"
"{\n"
"	border-image: url(:/png/res/png/exit.png);\n"
"}"));
        pushButton_close->setIconSize(QSize(80, 80));

        horizontalLayout_2->addWidget(pushButton_close);


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
        log_widget = new LogWidget();
        log_widget->setObjectName(QString::fromUtf8("log_widget"));
        stackedWidget_main->addWidget(log_widget);
        report_widget = new ReportWidget();
        report_widget->setObjectName(QString::fromUtf8("report_widget"));
        stackedWidget_main->addWidget(report_widget);
        user_widget = new UserWidget();
        user_widget->setObjectName(QString::fromUtf8("user_widget"));
        stackedWidget_main->addWidget(user_widget);

        horizontalLayout->addWidget(stackedWidget_main);

        widget_menu = new QWidget(widget_frame);
        widget_menu->setObjectName(QString::fromUtf8("widget_menu"));
        widget_menu->setMinimumSize(QSize(100, 0));
        widget_menu->setMaximumSize(QSize(100, 16777215));
        widget_menu->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{  \n"
"	\n"
"	font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(widget_menu);
        verticalLayout_2->setSpacing(4);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(3, 30, 3, 12);
        pushButton_home = new QPushButton(widget_menu);
        pushButton_home->setObjectName(QString::fromUtf8("pushButton_home"));
        pushButton_home->setMinimumSize(QSize(0, 60));
        pushButton_home->setStyleSheet(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/png/res/png/516585.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_home->setIcon(icon);
        pushButton_home->setCheckable(true);
        pushButton_home->setChecked(true);

        verticalLayout_2->addWidget(pushButton_home);

        pushButton_setup = new QPushButton(widget_menu);
        pushButton_setup->setObjectName(QString::fromUtf8("pushButton_setup"));
        pushButton_setup->setMinimumSize(QSize(0, 60));
        pushButton_setup->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/png/res/png/522191.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_setup->setIcon(icon1);
        pushButton_setup->setCheckable(true);

        verticalLayout_2->addWidget(pushButton_setup);

        pushButton_debug = new QPushButton(widget_menu);
        pushButton_debug->setObjectName(QString::fromUtf8("pushButton_debug"));
        pushButton_debug->setMinimumSize(QSize(0, 60));
        pushButton_debug->setStyleSheet(QString::fromUtf8(""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/png/res/png/debug.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_debug->setIcon(icon2);
        pushButton_debug->setCheckable(true);

        verticalLayout_2->addWidget(pushButton_debug);

        pushButton_log = new QPushButton(widget_menu);
        pushButton_log->setObjectName(QString::fromUtf8("pushButton_log"));
        pushButton_log->setMinimumSize(QSize(0, 60));
        pushButton_log->setStyleSheet(QString::fromUtf8(""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/png/res/png/516587.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_log->setIcon(icon3);
        pushButton_log->setCheckable(true);

        verticalLayout_2->addWidget(pushButton_log);

        pushButton_report = new QPushButton(widget_menu);
        pushButton_report->setObjectName(QString::fromUtf8("pushButton_report"));
        pushButton_report->setMinimumSize(QSize(0, 60));
        pushButton_report->setStyleSheet(QString::fromUtf8(""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/png/res/png/report.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_report->setIcon(icon4);
        pushButton_report->setCheckable(true);

        verticalLayout_2->addWidget(pushButton_report);

        pushButton_user = new QPushButton(widget_menu);
        pushButton_user->setObjectName(QString::fromUtf8("pushButton_user"));
        pushButton_user->setMinimumSize(QSize(0, 60));
        pushButton_user->setStyleSheet(QString::fromUtf8(""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/png/res/png/user.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_user->setIcon(icon5);
        pushButton_user->setCheckable(true);

        verticalLayout_2->addWidget(pushButton_user);

        pushButton_min = new QPushButton(widget_menu);
        pushButton_min->setObjectName(QString::fromUtf8("pushButton_min"));
        pushButton_min->setMinimumSize(QSize(0, 60));
        pushButton_min->setStyleSheet(QString::fromUtf8(""));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/png/res/png/516591.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_min->setIcon(icon6);
        pushButton_min->setCheckable(false);

        verticalLayout_2->addWidget(pushButton_min);

        verticalSpacer = new QSpacerItem(20, 297, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        pushButton_pause = new QPushButton(widget_menu);
        pushButton_pause->setObjectName(QString::fromUtf8("pushButton_pause"));
        pushButton_pause->setMinimumSize(QSize(0, 60));
        pushButton_pause->setStyleSheet(QString::fromUtf8(""));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/png/res/png/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon7.addFile(QString::fromUtf8(":/png/res/png/restart.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_pause->setIcon(icon7);
        pushButton_pause->setCheckable(true);

        verticalLayout_2->addWidget(pushButton_pause);

        pushButton_start = new QPushButton(widget_menu);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));
        pushButton_start->setMinimumSize(QSize(0, 60));
        pushButton_start->setStyleSheet(QString::fromUtf8(""));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/png/res/png/start.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon8.addFile(QString::fromUtf8(":/png/res/png/stop.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_start->setIcon(icon8);
        pushButton_start->setCheckable(true);

        verticalLayout_2->addWidget(pushButton_start);


        horizontalLayout->addWidget(widget_menu);


        verticalLayout->addWidget(widget_frame);

        MainWindowClass->setCentralWidget(centralWidget);

        retranslateUi(MainWindowClass);

        stackedWidget_main->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", nullptr));
        label_2->setText(QApplication::translate("MainWindowClass", "\345\220\210\350\202\245\347\221\236\346\234\227\350\207\252\345\212\250\345\214\226\350\256\276\345\244\207\346\234\211\351\231\220\345\205\254\345\217\270", nullptr));
        label->setText(QApplication::translate("MainWindowClass", "\344\274\240\346\204\237\345\231\250\350\207\252\345\212\250\347\255\233\351\200\211\346\234\272", nullptr));
        pushButton_close->setText(QString());
        pushButton_home->setText(QApplication::translate("MainWindowClass", "\344\270\273\347\225\214\351\235\242", nullptr));
        pushButton_setup->setText(QApplication::translate("MainWindowClass", "\350\256\276\347\275\256", nullptr));
        pushButton_debug->setText(QApplication::translate("MainWindowClass", "\350\260\203\350\257\225", nullptr));
        pushButton_log->setText(QApplication::translate("MainWindowClass", "\346\227\245\345\277\227", nullptr));
        pushButton_report->setText(QApplication::translate("MainWindowClass", "\346\212\245\350\241\250", nullptr));
        pushButton_user->setText(QApplication::translate("MainWindowClass", "\347\224\250\346\210\267", nullptr));
        pushButton_min->setText(QApplication::translate("MainWindowClass", "\346\234\200\345\260\217\345\214\226", nullptr));
        pushButton_pause->setText(QApplication::translate("MainWindowClass", "\346\232\202\345\201\234", nullptr));
        pushButton_start->setText(QApplication::translate("MainWindowClass", "\345\220\257\345\212\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
