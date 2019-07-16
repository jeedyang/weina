/********************************************************************************
** Form generated from reading UI file 'widgetxF1392.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef WIDGETXF1392_H
#define WIDGETXF1392_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
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
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(729, 472);
        Form->setStyleSheet(QLatin1String("QWidget#widget,#widgetTitle\n"
"{\n"
"	border-style:solid;\n"
"	border-radius:5px;\n"
"	border-color:#00BB9E;\n"
"	border-width:2px 2px 2px 2px;\n"
"	background-color: rgb(246, 255, 221);\n"
"}"));
        verticalLayout = new QVBoxLayout(Form);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widgetTitle = new QWidget(Form);
        widgetTitle->setObjectName(QStringLiteral("widgetTitle"));

        verticalLayout->addWidget(widgetTitle);

        widget = new QWidget(Form);
        widget->setObjectName(QStringLiteral("widget"));

        verticalLayout->addWidget(widget);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // WIDGETXF1392_H
