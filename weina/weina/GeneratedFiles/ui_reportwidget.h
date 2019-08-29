/********************************************************************************
** Form generated from reading UI file 'reportwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTWIDGET_H
#define UI_REPORTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReportWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QTreeView *treeView;

    void setupUi(QWidget *ReportWidget)
    {
        if (ReportWidget->objectName().isEmpty())
            ReportWidget->setObjectName(QString::fromUtf8("ReportWidget"));
        ReportWidget->resize(578, 462);
        horizontalLayout = new QHBoxLayout(ReportWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        treeView = new QTreeView(ReportWidget);
        treeView->setObjectName(QString::fromUtf8("treeView"));

        horizontalLayout->addWidget(treeView);


        retranslateUi(ReportWidget);

        QMetaObject::connectSlotsByName(ReportWidget);
    } // setupUi

    void retranslateUi(QWidget *ReportWidget)
    {
        ReportWidget->setWindowTitle(QApplication::translate("ReportWidget", "ReportWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReportWidget: public Ui_ReportWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTWIDGET_H
