/********************************************************************************
** Form generated from reading UI file 'homewidgetaHqJYF.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef HOMEWIDGETAHQJYF_H
#define HOMEWIDGETAHQJYF_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomeWidget
{
public:
    QGridLayout *gridLayout;
    QWidget *widget_ctrl;
    QHBoxLayout *horizontalLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *page_0;
    QWidget *page_1;
    QWidget *page_3;
    QWidget *page_4;
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_mod0;
    QPushButton *pushButton_mod1;
    QPushButton *pushButton_mod2;
    QPushButton *pushButton_mod3;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *HomeWidget)
    {
        if (HomeWidget->objectName().isEmpty())
            HomeWidget->setObjectName(QString::fromUtf8("HomeWidget"));
        HomeWidget->resize(968, 637);
        gridLayout = new QGridLayout(HomeWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget_ctrl = new QWidget(HomeWidget);
        widget_ctrl->setObjectName(QString::fromUtf8("widget_ctrl"));
        horizontalLayout_2 = new QHBoxLayout(widget_ctrl);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        stackedWidget = new QStackedWidget(widget_ctrl);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page_0 = new QWidget();
        page_0->setObjectName(QString::fromUtf8("page_0"));
        stackedWidget->addWidget(page_0);
        page_1 = new QWidget();
        page_1->setObjectName(QString::fromUtf8("page_1"));
        stackedWidget->addWidget(page_1);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        stackedWidget->addWidget(page_4);

        horizontalLayout_2->addWidget(stackedWidget);

        label = new QLabel(widget_ctrl);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);


        gridLayout->addWidget(widget_ctrl, 1, 0, 1, 1);

        widget = new QWidget(HomeWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_mod0 = new QPushButton(widget);
        pushButton_mod0->setObjectName(QString::fromUtf8("pushButton_mod0"));

        horizontalLayout->addWidget(pushButton_mod0);

        pushButton_mod1 = new QPushButton(widget);
        pushButton_mod1->setObjectName(QString::fromUtf8("pushButton_mod1"));

        horizontalLayout->addWidget(pushButton_mod1);

        pushButton_mod2 = new QPushButton(widget);
        pushButton_mod2->setObjectName(QString::fromUtf8("pushButton_mod2"));

        horizontalLayout->addWidget(pushButton_mod2);

        pushButton_mod3 = new QPushButton(widget);
        pushButton_mod3->setObjectName(QString::fromUtf8("pushButton_mod3"));

        horizontalLayout->addWidget(pushButton_mod3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(HomeWidget);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(HomeWidget);
    } // setupUi

    void retranslateUi(QWidget *HomeWidget)
    {
        HomeWidget->setWindowTitle(QApplication::translate("HomeWidget", "HomeWidget", nullptr));
        label->setText(QApplication::translate("HomeWidget", "TextLabel", nullptr));
        pushButton_mod0->setText(QApplication::translate("HomeWidget", "\346\250\241\345\235\2271", nullptr));
        pushButton_mod1->setText(QApplication::translate("HomeWidget", "\346\250\241\345\235\2272", nullptr));
        pushButton_mod2->setText(QApplication::translate("HomeWidget", "\346\250\241\345\235\2273", nullptr));
        pushButton_mod3->setText(QApplication::translate("HomeWidget", "\346\250\241\345\235\2274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HomeWidget: public Ui_HomeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // HOMEWIDGETAHQJYF_H
