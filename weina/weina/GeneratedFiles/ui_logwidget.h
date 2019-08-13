/********************************************************************************
** Form generated from reading UI file 'logwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGWIDGET_H
#define UI_LOGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogWidget
{
public:
    QGridLayout *gridLayout;
    QTextEdit *textEdit_details;
    QListView *listView_date;
    QListView *listView_month;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *LogWidget)
    {
        if (LogWidget->objectName().isEmpty())
            LogWidget->setObjectName(QString::fromUtf8("LogWidget"));
        LogWidget->resize(931, 550);
        LogWidget->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	\n"
"	font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        gridLayout = new QGridLayout(LogWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textEdit_details = new QTextEdit(LogWidget);
        textEdit_details->setObjectName(QString::fromUtf8("textEdit_details"));

        gridLayout->addWidget(textEdit_details, 1, 2, 1, 1);

        listView_date = new QListView(LogWidget);
        listView_date->setObjectName(QString::fromUtf8("listView_date"));

        gridLayout->addWidget(listView_date, 1, 1, 1, 1);

        listView_month = new QListView(LogWidget);
        listView_month->setObjectName(QString::fromUtf8("listView_month"));

        gridLayout->addWidget(listView_month, 1, 0, 1, 1);

        label = new QLabel(LogWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(LogWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_3 = new QLabel(LogWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 2, 1, 1);


        retranslateUi(LogWidget);

        QMetaObject::connectSlotsByName(LogWidget);
    } // setupUi

    void retranslateUi(QWidget *LogWidget)
    {
        LogWidget->setWindowTitle(QApplication::translate("LogWidget", "LogWidget", nullptr));
        label->setText(QApplication::translate("LogWidget", "\346\234\210\344\273\275:", nullptr));
        label_2->setText(QApplication::translate("LogWidget", "\346\227\245\346\234\237:", nullptr));
        label_3->setText(QApplication::translate("LogWidget", "\345\206\205\345\256\271:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LogWidget: public Ui_LogWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGWIDGET_H
