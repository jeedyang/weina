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
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetupWidget
{
public:
    QLabel *label;

    void setupUi(QWidget *SetupWidget)
    {
        if (SetupWidget->objectName().isEmpty())
            SetupWidget->setObjectName(QString::fromUtf8("SetupWidget"));
        SetupWidget->resize(917, 559);
        label = new QLabel(SetupWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(260, 210, 54, 12));

        retranslateUi(SetupWidget);

        QMetaObject::connectSlotsByName(SetupWidget);
    } // setupUi

    void retranslateUi(QWidget *SetupWidget)
    {
        SetupWidget->setWindowTitle(QCoreApplication::translate("SetupWidget", "SetupWidget", nullptr));
        label->setText(QCoreApplication::translate("SetupWidget", "\350\256\276\347\275\256\347\225\214\351\235\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SetupWidget: public Ui_SetupWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETUPWIDGET_H
