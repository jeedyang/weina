/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widgetTitle;
    QWidget *widget;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(729, 472);
        Form->setStyleSheet(QString::fromUtf8("QWidget#widget,#widgetTitle\n"
"{\n"
"	border-style:solid;\n"
"	border-radius:5px;\n"
"	border-color:#00BB9E;\n"
"	border-width:2px 2px 2px 2px;\n"
"	background-color: rgb(246, 255, 221);\n"
"}"));
        verticalLayout = new QVBoxLayout(Form);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widgetTitle = new QWidget(Form);
        widgetTitle->setObjectName(QString::fromUtf8("widgetTitle"));

        verticalLayout->addWidget(widgetTitle);

        widget = new QWidget(Form);
        widget->setObjectName(QString::fromUtf8("widget"));

        verticalLayout->addWidget(widget);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H