/********************************************************************************
** Form generated from reading UI file 'analyzeform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANALYZEFORM_H
#define UI_ANALYZEFORM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qchartview.h>
#include <qtmaterialtabs.h>

QT_BEGIN_NAMESPACE

class Ui_AnalyzeForm
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_title;
    QHBoxLayout *horizontalLayout;
    QLabel *label_id;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QtMaterialTabs *widget_tab;
    QStackedWidget *stackedWidget;
    QChartView *page;
    QChartView *page_2;
    QWidget *page_3;
    QGridLayout *gridLayout;
    QTableView *tableView;

    void setupUi(QWidget *AnalyzeForm)
    {
        if (AnalyzeForm->objectName().isEmpty())
            AnalyzeForm->setObjectName(QString::fromUtf8("AnalyzeForm"));
        AnalyzeForm->resize(767, 512);
        AnalyzeForm->setStyleSheet(QString::fromUtf8("QWidget#widget_title\n"
"{\n"
"	background-color: rgb(50, 50, 50);\n"
"\n"
"}"));
        verticalLayout = new QVBoxLayout(AnalyzeForm);
        verticalLayout->setSpacing(4);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_title = new QWidget(AnalyzeForm);
        widget_title->setObjectName(QString::fromUtf8("widget_title"));
        widget_title->setMinimumSize(QSize(0, 33));
        widget_title->setMaximumSize(QSize(16777215, 33));
        horizontalLayout = new QHBoxLayout(widget_title);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, 0, -1);
        label_id = new QLabel(widget_title);
        label_id->setObjectName(QString::fromUtf8("label_id"));
        label_id->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout->addWidget(label_id);

        horizontalSpacer = new QSpacerItem(714, 19, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(widget_title);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(32, 32));
        pushButton->setMaximumSize(QSize(32, 32));
        pushButton->setSizeIncrement(QSize(0, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/png/res/png/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addWidget(widget_title);

        widget_tab = new QtMaterialTabs(AnalyzeForm);
        widget_tab->setObjectName(QString::fromUtf8("widget_tab"));
        widget_tab->setMinimumSize(QSize(0, 50));
        widget_tab->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        verticalLayout->addWidget(widget_tab);

        stackedWidget = new QStackedWidget(AnalyzeForm);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QChartView();
        page->setObjectName(QString::fromUtf8("page"));
        stackedWidget->addWidget(page);
        page_2 = new QChartView();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        gridLayout = new QGridLayout(page_3);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView = new QTableView(page_3);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);

        stackedWidget->addWidget(page_3);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(AnalyzeForm);
        QObject::connect(pushButton, SIGNAL(clicked()), AnalyzeForm, SLOT(close()));

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(AnalyzeForm);
    } // setupUi

    void retranslateUi(QWidget *AnalyzeForm)
    {
        AnalyzeForm->setWindowTitle(QApplication::translate("AnalyzeForm", "AnalyzeForm", nullptr));
        label_id->setText(QApplication::translate("AnalyzeForm", "TextLabel", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AnalyzeForm: public Ui_AnalyzeForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANALYZEFORM_H
