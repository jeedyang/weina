/********************************************************************************
** Form generated from reading UI file 'panelXQ1392.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef PANELXQ1392_H
#define PANELXQ1392_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
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
    QLabel *label_2;
    QLabel *labelHotRes;
    QLabel *labelHotResValue;
    QLabel *labelHotVol;
    QLabel *label_3;
    QLabel *labelHotVolValue;
    QPushButton *pushButton;

    void setupUi(QWidget *Panel)
    {
        if (Panel->objectName().isEmpty())
            Panel->setObjectName(QStringLiteral("Panel"));
        Panel->resize(181, 105);
        Panel->setStyleSheet(QString::fromUtf8("QLabel#labelRes,#labelResValue,#label_1\n"
"{\n"
"	font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QLabel#labelHotRes,#labelHotResValue,#label_2\n"
"{\n"
"	\n"
"	font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QLabel#labelHotVol,#labelHotVolValue,#label_3\n"
"{\n"
"	\n"
"	font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
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
"	background-color: rgb(255, 85, 0);\n"
"}"));
        verticalLayout = new QVBoxLayout(Panel);
        verticalLayout->setSpacing(2);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(3, 3, 3, 3);
        widget = new QWidget(Panel);
        widget->setObjectName(QStringLiteral("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(6);
        gridLayout->setVerticalSpacing(3);
        gridLayout->setContentsMargins(2, 2, 2, 2);
        label_1 = new QLabel(widget);
        label_1->setObjectName(QStringLiteral("label_1"));

        gridLayout->addWidget(label_1, 0, 2, 1, 1);

        labelResValue = new QLabel(widget);
        labelResValue->setObjectName(QStringLiteral("labelResValue"));

        gridLayout->addWidget(labelResValue, 0, 1, 1, 1);

        labelRes = new QLabel(widget);
        labelRes->setObjectName(QStringLiteral("labelRes"));

        gridLayout->addWidget(labelRes, 0, 0, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 2, 1, 1);

        labelHotRes = new QLabel(widget);
        labelHotRes->setObjectName(QStringLiteral("labelHotRes"));

        gridLayout->addWidget(labelHotRes, 1, 0, 1, 1);

        labelHotResValue = new QLabel(widget);
        labelHotResValue->setObjectName(QStringLiteral("labelHotResValue"));

        gridLayout->addWidget(labelHotResValue, 1, 1, 1, 1);

        labelHotVol = new QLabel(widget);
        labelHotVol->setObjectName(QStringLiteral("labelHotVol"));

        gridLayout->addWidget(labelHotVol, 2, 0, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 2, 1, 1);

        labelHotVolValue = new QLabel(widget);
        labelHotVolValue->setObjectName(QStringLiteral("labelHotVolValue"));

        gridLayout->addWidget(labelHotVolValue, 2, 1, 1, 1);


        verticalLayout->addWidget(widget);

        pushButton = new QPushButton(Panel);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setCheckable(true);

        verticalLayout->addWidget(pushButton);


        retranslateUi(Panel);

        QMetaObject::connectSlotsByName(Panel);
    } // setupUi

    void retranslateUi(QWidget *Panel)
    {
        Panel->setWindowTitle(QApplication::translate("Panel", "Panel", Q_NULLPTR));
        label_1->setText(QApplication::translate("Panel", "\316\251", Q_NULLPTR));
        labelResValue->setText(QApplication::translate("Panel", "TextLabel", Q_NULLPTR));
        labelRes->setText(QApplication::translate("Panel", "\347\224\265\351\230\273:", Q_NULLPTR));
        label_2->setText(QApplication::translate("Panel", "\316\251", Q_NULLPTR));
        labelHotRes->setText(QApplication::translate("Panel", "\345\212\240\347\203\255\347\224\265\351\230\273:", Q_NULLPTR));
        labelHotResValue->setText(QApplication::translate("Panel", "TextLabel", Q_NULLPTR));
        labelHotVol->setText(QApplication::translate("Panel", "\345\212\240\347\203\255\347\224\265\345\216\213:", Q_NULLPTR));
        label_3->setText(QApplication::translate("Panel", "V", Q_NULLPTR));
        labelHotVolValue->setText(QApplication::translate("Panel", "TextLabel", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Panel", "\345\212\240\347\203\255\345\205\263", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Panel: public Ui_Panel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PANELXQ1392_H
