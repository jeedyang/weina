/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widgetTitle;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_modID;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(630, 522);
        Form->setStyleSheet(QString::fromUtf8("QWidget#widget,#widgetTitle\n"
"{\n"
"	border-style:solid;\n"
"	border-radius:5px;\n"
"	border-color:#00BB9E;\n"
"	border-width:2px 2px 2px 2px;\n"
"	background-color: rgb(246, 255, 221);\n"
"}\n"
"QLabel#label,#label_modID\n"
"{\n"
"	\n"
"	\n"
"	font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        verticalLayout = new QVBoxLayout(Form);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widgetTitle = new QWidget(Form);
        widgetTitle->setObjectName(QString::fromUtf8("widgetTitle"));
        horizontalLayout = new QHBoxLayout(widgetTitle);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widgetTitle);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        label_modID = new QLabel(widgetTitle);
        label_modID->setObjectName(QString::fromUtf8("label_modID"));

        horizontalLayout->addWidget(label_modID);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(widgetTitle);

        widget = new QWidget(Form);
        widget->setObjectName(QString::fromUtf8("widget"));

        verticalLayout->addWidget(widget);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", nullptr));
        label->setText(QApplication::translate("Form", "\346\250\241\345\235\227ID:", nullptr));
        label_modID->setText(QApplication::translate("Form", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
