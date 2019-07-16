/********************************************************************************
** Form generated from reading UI file 'panel.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANEL_H
#define UI_PANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Panel
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_1;
    QLabel *labelResValue;
    QLabel *labelRes;
    QLabel *labelHotVolValue;
    QLabel *label_3;
    QLabel *labelHotVol;
    QLabel *label_2;
    QLabel *labelHotRes;
    QLabel *labelHotResValue;
    QPushButton *pushButton;

    void setupUi(QWidget *Panel)
    {
        if (Panel->objectName().isEmpty())
            Panel->setObjectName(QString::fromUtf8("Panel"));
        Panel->resize(177, 101);
        Panel->setStyleSheet(QString::fromUtf8("QWidget#Panel\n"
"{\n"
"	border-style:solid;\n"
"	border-radius:5px;\n"
"	border-color:#00BB9E;\n"
"	border-width:2px 2px 2px 2px;\n"
"	background-color: rgb(246, 255, 221);\n"
"}\n"
"\n"
"QLabel#labelRes,#labelResValue,#label_1\n"
"{\n"
"	font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QLabel#labelHotRes,#labelHotResValue,#label_2\n"
"{\n"
"	font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QLabel#labelHotVol,#labelHotVolValue,#label_3\n"
"{\n"
"	\n"
"	font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"\n"
"QPushButton\n"
"{\n"
"	border-radius:4px;\n"
"	margin:1px 1px 2px 1px;\n"
"	font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	background-color: rgb(85, 170, 255);\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	\n"
"	background-color: rgb(0, 170, 255);\n"
"\n"
"}\n"
"QPushButton:checked\n"
"{\n"
"	\n"
"	background-color: rgb(255, 85, 0);\n"
"}\n"
"QPushButton::pressed\n"
"{\n"
"	\n"
"	background-color: "
                        "rgb(255, 85, 0);\n"
"}"));
        verticalLayout = new QVBoxLayout(Panel);
        verticalLayout->setSpacing(2);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(3, 3, 3, 3);
        widget = new QWidget(Panel);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(6);
        gridLayout->setVerticalSpacing(3);
        gridLayout->setContentsMargins(2, 2, 2, 2);
        label_1 = new QLabel(widget);
        label_1->setObjectName(QString::fromUtf8("label_1"));

        gridLayout->addWidget(label_1, 0, 2, 1, 1);

        labelResValue = new QLabel(widget);
        labelResValue->setObjectName(QString::fromUtf8("labelResValue"));

        gridLayout->addWidget(labelResValue, 0, 1, 1, 1);

        labelRes = new QLabel(widget);
        labelRes->setObjectName(QString::fromUtf8("labelRes"));

        gridLayout->addWidget(labelRes, 0, 0, 1, 1);

        labelHotVolValue = new QLabel(widget);
        labelHotVolValue->setObjectName(QString::fromUtf8("labelHotVolValue"));

        gridLayout->addWidget(labelHotVolValue, 2, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 2, 1, 1);

        labelHotVol = new QLabel(widget);
        labelHotVol->setObjectName(QString::fromUtf8("labelHotVol"));

        gridLayout->addWidget(labelHotVol, 2, 0, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 2, 1, 1);

        labelHotRes = new QLabel(widget);
        labelHotRes->setObjectName(QString::fromUtf8("labelHotRes"));

        gridLayout->addWidget(labelHotRes, 1, 0, 1, 1);

        labelHotResValue = new QLabel(widget);
        labelHotResValue->setObjectName(QString::fromUtf8("labelHotResValue"));

        gridLayout->addWidget(labelHotResValue, 1, 1, 1, 1);


        verticalLayout->addWidget(widget);

        pushButton = new QPushButton(Panel);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setCheckable(true);

        verticalLayout->addWidget(pushButton);


        retranslateUi(Panel);

        QMetaObject::connectSlotsByName(Panel);
    } // setupUi

    void retranslateUi(QWidget *Panel)
    {
        Panel->setWindowTitle(QCoreApplication::translate("Panel", "Panel", nullptr));
        label_1->setText(QCoreApplication::translate("Panel", "\316\251", nullptr));
        labelResValue->setText(QCoreApplication::translate("Panel", "TextLabel", nullptr));
        labelRes->setText(QCoreApplication::translate("Panel", "\347\224\265\351\230\273:", nullptr));
        labelHotVolValue->setText(QCoreApplication::translate("Panel", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("Panel", "V", nullptr));
        labelHotVol->setText(QCoreApplication::translate("Panel", "\345\212\240\347\203\255\347\224\265\345\216\213:", nullptr));
        label_2->setText(QCoreApplication::translate("Panel", "\316\251", nullptr));
        labelHotRes->setText(QCoreApplication::translate("Panel", "\345\212\240\347\203\255\347\224\265\351\230\273:", nullptr));
        labelHotResValue->setText(QCoreApplication::translate("Panel", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("Panel", "\345\212\240\347\203\255\345\205\263", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Panel: public Ui_Panel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANEL_H