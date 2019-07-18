/********************************************************************************
** Form generated from reading UI file 'homewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEWIDGET_H
#define UI_HOMEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomeWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget_panel;
    QWidget *widget_ctrl;
    QLabel *label;

    void setupUi(QWidget *HomeWidget)
    {
        if (HomeWidget->objectName().isEmpty())
            HomeWidget->setObjectName(QString::fromUtf8("HomeWidget"));
        HomeWidget->resize(968, 637);
        horizontalLayout = new QHBoxLayout(HomeWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget_panel = new QWidget(HomeWidget);
        widget_panel->setObjectName(QString::fromUtf8("widget_panel"));

        horizontalLayout->addWidget(widget_panel);

        widget_ctrl = new QWidget(HomeWidget);
        widget_ctrl->setObjectName(QString::fromUtf8("widget_ctrl"));
        label = new QLabel(widget_ctrl);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 350, 54, 12));

        horizontalLayout->addWidget(widget_ctrl);


        retranslateUi(HomeWidget);

        QMetaObject::connectSlotsByName(HomeWidget);
    } // setupUi

    void retranslateUi(QWidget *HomeWidget)
    {
        HomeWidget->setWindowTitle(QCoreApplication::translate("HomeWidget", "HomeWidget", nullptr));
        label->setText(QCoreApplication::translate("HomeWidget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HomeWidget: public Ui_HomeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEWIDGET_H
