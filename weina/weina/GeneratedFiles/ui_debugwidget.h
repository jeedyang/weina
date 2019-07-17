/********************************************************************************
** Form generated from reading UI file 'debugwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEBUGWIDGET_H
#define UI_DEBUGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DebugWidget
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_4;
    QPushButton *btnXaxisHome;
    QPushButton *btnXaxisReset;
    QPushButton *btnYaxisHome;
    QPushButton *btnYaxisReset;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_5;
    QPushButton *btnXaxisGoto;
    QPushButton *btnYaxisGoto;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_2;
    QLabel *label;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *labXaxisLocationOdd;
    QLabel *label_2;
    QLabel *labYaxisLocationOdd;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_2;
    QGridLayout *gridLayout_3;
    QPushButton *btnYaxisUp;
    QPushButton *btnXaxisR;
    QPushButton *btnYaxisDown;
    QPushButton *btnXaxisL;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_15;
    QDoubleSpinBox *doubleSpinBox_3;
    QLabel *label_16;
    QSpacerItem *verticalSpacer;
    QLabel *label_8;
    QTimeEdit *timeEdit;
    QLabel *label_17;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_6;
    QLabel *label_13;
    QLabel *label_7;
    QLabel *label_10;
    QLabel *label_6;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_4;
    QLabel *label_9;
    QWidget *tab_3;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_4;
    QGridLayout *gridLayout_7;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_8;
    QLabel *label_48;
    QLabel *label_45;
    QLabel *i2_0;
    QLabel *label_44;
    QLabel *label_47;
    QLabel *label_50;
    QLabel *label_51;
    QLabel *label_52;
    QLabel *label_53;
    QLabel *i2_1;
    QLabel *i2_2;
    QLabel *i2_3;
    QLabel *i2_5;
    QLabel *label_54;
    QLabel *i2_6;
    QLabel *i2_4;
    QLabel *i2_7;
    QLabel *label_49;
    QLabel *i0_6;
    QLabel *i1_5;
    QLabel *i1_6;
    QLabel *i1_4;
    QLabel *i1_7;
    QLabel *i0_7;
    QLabel *i0_1;
    QLabel *i0_2;
    QLabel *i0_3;
    QLabel *i0_4;
    QLabel *i0_5;
    QLabel *label_46;
    QLabel *label_56;
    QLabel *label_57;
    QLabel *label_66;
    QLabel *label_67;
    QLabel *label_68;
    QLabel *label_69;
    QLabel *label_70;
    QLabel *label_72;
    QLabel *label_73;
    QLabel *label_74;
    QLabel *label_75;
    QLabel *label_55;
    QLabel *i0_0;
    QLabel *i1_2;
    QLabel *i1_3;
    QLabel *i1_1;
    QLabel *i1_0;
    QLabel *label_71;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_10;
    QPushButton *q2_0;
    QPushButton *q0_0;
    QPushButton *q1_0;
    QPushButton *q0_6;
    QPushButton *q1_6;
    QPushButton *q2_7;
    QPushButton *q1_7;
    QPushButton *q0_1;
    QPushButton *q0_7;
    QPushButton *q0_2;
    QPushButton *q0_3;
    QPushButton *q0_4;
    QPushButton *q0_5;
    QPushButton *q1_1;
    QPushButton *q1_2;
    QPushButton *q1_3;
    QPushButton *q1_4;
    QPushButton *q1_5;
    QPushButton *q2_1;
    QPushButton *q2_2;
    QPushButton *q2_3;
    QPushButton *q2_4;
    QPushButton *q2_5;
    QPushButton *q2_6;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *DebugWidget)
    {
        if (DebugWidget->objectName().isEmpty())
            DebugWidget->setObjectName(QString::fromUtf8("DebugWidget"));
        DebugWidget->resize(973, 576);
        gridLayout = new QGridLayout(DebugWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        tabWidget = new QTabWidget(DebugWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        tabWidget->setFont(font);
        tabWidget->setTabPosition(QTabWidget::West);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setFont(font);
        gridLayout_4 = new QGridLayout(groupBox_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        btnXaxisHome = new QPushButton(groupBox_2);
        btnXaxisHome->setObjectName(QString::fromUtf8("btnXaxisHome"));
        btnXaxisHome->setMinimumSize(QSize(120, 50));
        btnXaxisHome->setMaximumSize(QSize(120, 50));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        btnXaxisHome->setFont(font1);
        btnXaxisHome->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	background-color: rgb(108, 191, 230);\n"
"    border-radius: 11px 11px ;\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"    background-color: rgb(56, 135, 188);\n"
"}\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: rgb(144, 48, 0)\n"
"}\n"
"QPushButton::checked \n"
"{\n"
"    \n"
"	\n"
"	background-color: rgb(204, 0, 20);\n"
"}"));

        gridLayout_4->addWidget(btnXaxisHome, 0, 0, 1, 1);

        btnXaxisReset = new QPushButton(groupBox_2);
        btnXaxisReset->setObjectName(QString::fromUtf8("btnXaxisReset"));
        btnXaxisReset->setMinimumSize(QSize(120, 50));
        btnXaxisReset->setMaximumSize(QSize(120, 50));
        btnXaxisReset->setFont(font1);
        btnXaxisReset->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	background-color: rgb(108, 191, 230);\n"
"    border-radius: 11px 11px ;\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"    background-color: rgb(56, 135, 188);\n"
"}\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: rgb(144, 48, 0)\n"
"}\n"
"QPushButton::checked \n"
"{\n"
"    \n"
"	\n"
"	background-color: rgb(204, 0, 20);\n"
"}"));

        gridLayout_4->addWidget(btnXaxisReset, 0, 1, 1, 1);

        btnYaxisHome = new QPushButton(groupBox_2);
        btnYaxisHome->setObjectName(QString::fromUtf8("btnYaxisHome"));
        btnYaxisHome->setMinimumSize(QSize(120, 50));
        btnYaxisHome->setMaximumSize(QSize(120, 50));
        btnYaxisHome->setFont(font1);
        btnYaxisHome->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	background-color: rgb(108, 191, 230);\n"
"    border-radius: 11px 11px ;\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"    background-color: rgb(56, 135, 188);\n"
"}\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: rgb(144, 48, 0)\n"
"}\n"
"QPushButton::checked \n"
"{\n"
"    \n"
"	\n"
"	background-color: rgb(204, 0, 20);\n"
"}"));

        gridLayout_4->addWidget(btnYaxisHome, 1, 0, 1, 1);

        btnYaxisReset = new QPushButton(groupBox_2);
        btnYaxisReset->setObjectName(QString::fromUtf8("btnYaxisReset"));
        btnYaxisReset->setMinimumSize(QSize(120, 50));
        btnYaxisReset->setMaximumSize(QSize(120, 50));
        btnYaxisReset->setFont(font1);
        btnYaxisReset->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	background-color: rgb(108, 191, 230);\n"
"    border-radius: 11px 11px ;\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"    background-color: rgb(56, 135, 188);\n"
"}\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: rgb(144, 48, 0)\n"
"}\n"
"QPushButton::checked \n"
"{\n"
"    \n"
"	\n"
"	background-color: rgb(204, 0, 20);\n"
"}"));

        gridLayout_4->addWidget(btnYaxisReset, 1, 1, 1, 1);


        gridLayout_2->addWidget(groupBox_2, 0, 1, 1, 1);

        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(11);
        font2.setBold(false);
        font2.setWeight(50);
        groupBox_3->setFont(font2);
        gridLayout_5 = new QGridLayout(groupBox_3);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        btnXaxisGoto = new QPushButton(groupBox_3);
        btnXaxisGoto->setObjectName(QString::fromUtf8("btnXaxisGoto"));
        btnXaxisGoto->setMinimumSize(QSize(120, 40));
        btnXaxisGoto->setMaximumSize(QSize(120, 40));
        btnXaxisGoto->setFont(font1);
        btnXaxisGoto->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	background-color: rgb(108, 191, 230);\n"
"    border-radius: 11px 11px ;\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"    background-color: rgb(56, 135, 188);\n"
"}\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: rgb(144, 48, 0)\n"
"}\n"
"QPushButton::checked \n"
"{\n"
"    \n"
"	\n"
"	background-color: rgb(204, 0, 20);\n"
"}"));

        gridLayout_5->addWidget(btnXaxisGoto, 0, 2, 1, 1);

        btnYaxisGoto = new QPushButton(groupBox_3);
        btnYaxisGoto->setObjectName(QString::fromUtf8("btnYaxisGoto"));
        btnYaxisGoto->setMinimumSize(QSize(120, 40));
        btnYaxisGoto->setMaximumSize(QSize(120, 40));
        btnYaxisGoto->setFont(font1);
        btnYaxisGoto->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	background-color: rgb(108, 191, 230);\n"
"    border-radius: 11px 11px ;\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"    background-color: rgb(56, 135, 188);\n"
"}\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: rgb(144, 48, 0)\n"
"}\n"
"QPushButton::checked \n"
"{\n"
"    \n"
"	\n"
"	background-color: rgb(204, 0, 20);\n"
"}"));

        gridLayout_5->addWidget(btnYaxisGoto, 2, 2, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(groupBox_3);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));

        gridLayout_5->addWidget(doubleSpinBox, 0, 1, 1, 1);

        doubleSpinBox_2 = new QDoubleSpinBox(groupBox_3);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));

        gridLayout_5->addWidget(doubleSpinBox_2, 2, 1, 1, 1);

        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(100, 16777215));

        gridLayout_5->addWidget(label, 0, 0, 1, 1);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMaximumSize(QSize(16777215, 20));
        QFont font3;
        font3.setPointSize(8);
        label_5->setFont(font3);

        gridLayout_5->addWidget(label_5, 3, 1, 1, 1);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(16777215, 20));
        label_3->setFont(font3);

        gridLayout_5->addWidget(label_3, 1, 1, 1, 1);

        labXaxisLocationOdd = new QLabel(groupBox_3);
        labXaxisLocationOdd->setObjectName(QString::fromUtf8("labXaxisLocationOdd"));
        labXaxisLocationOdd->setMaximumSize(QSize(16777215, 30));

        gridLayout_5->addWidget(labXaxisLocationOdd, 1, 2, 1, 1);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_5->addWidget(label_2, 2, 0, 1, 1);

        labYaxisLocationOdd = new QLabel(groupBox_3);
        labYaxisLocationOdd->setObjectName(QString::fromUtf8("labYaxisLocationOdd"));

        gridLayout_5->addWidget(labYaxisLocationOdd, 3, 2, 1, 1);


        gridLayout_2->addWidget(groupBox_3, 1, 0, 1, 1);

        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setFont(font2);
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget_2 = new QWidget(groupBox);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 127);"));
        gridLayout_3 = new QGridLayout(widget_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        btnYaxisUp = new QPushButton(widget_2);
        btnYaxisUp->setObjectName(QString::fromUtf8("btnYaxisUp"));
        btnYaxisUp->setMinimumSize(QSize(100, 50));
        btnYaxisUp->setMaximumSize(QSize(100, 50));
        btnYaxisUp->setFont(font1);
        btnYaxisUp->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	background-color: rgb(108, 191, 230);\n"
"    border-radius: 11px 11px ;\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"    \n"
"	background-color: rgb(56, 135, 188);\n"
"}\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: rgb(144, 48, 0)\n"
"}\n"
"QPushButton::checked \n"
"{\n"
"    \n"
"	\n"
"	background-color: rgb(204, 0, 20);\n"
"}"));

        gridLayout_3->addWidget(btnYaxisUp, 1, 1, 1, 1);

        btnXaxisR = new QPushButton(widget_2);
        btnXaxisR->setObjectName(QString::fromUtf8("btnXaxisR"));
        btnXaxisR->setMinimumSize(QSize(100, 50));
        btnXaxisR->setMaximumSize(QSize(100, 50));
        btnXaxisR->setFont(font1);
        btnXaxisR->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	background-color: rgb(108, 191, 230);\n"
"    border-radius: 11px 11px ;\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"    background-color: rgb(56, 135, 188);\n"
"}\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: rgb(144, 48, 0)\n"
"}\n"
"QPushButton::checked \n"
"{\n"
"    \n"
"	\n"
"	background-color: rgb(204, 0, 20);\n"
"}"));

        gridLayout_3->addWidget(btnXaxisR, 2, 0, 1, 1);

        btnYaxisDown = new QPushButton(widget_2);
        btnYaxisDown->setObjectName(QString::fromUtf8("btnYaxisDown"));
        btnYaxisDown->setMinimumSize(QSize(100, 50));
        btnYaxisDown->setMaximumSize(QSize(120, 50));
        btnYaxisDown->setFont(font1);
        btnYaxisDown->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	background-color: rgb(108, 191, 230);\n"
"    border-radius: 11px 11px ;\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"    background-color: rgb(56, 135, 188);\n"
"}\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: rgb(144, 48, 0)\n"
"}\n"
"QPushButton::checked \n"
"{\n"
"    \n"
"	\n"
"	background-color: rgb(204, 0, 20);\n"
"}"));

        gridLayout_3->addWidget(btnYaxisDown, 3, 1, 1, 1);

        btnXaxisL = new QPushButton(widget_2);
        btnXaxisL->setObjectName(QString::fromUtf8("btnXaxisL"));
        btnXaxisL->setMinimumSize(QSize(100, 50));
        btnXaxisL->setMaximumSize(QSize(100, 50));
        btnXaxisL->setFont(font1);
        btnXaxisL->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	background-color: rgb(108, 191, 230);\n"
"    border-radius: 11px 11px ;\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"    background-color: rgb(56, 135, 188);\n"
"}\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: rgb(144, 48, 0)\n"
"}\n"
"QPushButton::checked \n"
"{\n"
"    \n"
"	\n"
"	background-color: rgb(204, 0, 20);\n"
"}"));

        gridLayout_3->addWidget(btnXaxisL, 2, 2, 1, 1);


        horizontalLayout->addWidget(widget_2);

        widget = new QWidget(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMaximumSize(QSize(130, 16777215));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_15 = new QLabel(widget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        QFont font4;
        font4.setPointSize(10);
        label_15->setFont(font4);

        verticalLayout->addWidget(label_15);

        doubleSpinBox_3 = new QDoubleSpinBox(widget);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));

        verticalLayout->addWidget(doubleSpinBox_3);

        label_16 = new QLabel(widget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFont(font3);

        verticalLayout->addWidget(label_16);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_8 = new QLabel(widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font4);

        verticalLayout->addWidget(label_8);

        timeEdit = new QTimeEdit(widget);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));

        verticalLayout->addWidget(timeEdit);

        label_17 = new QLabel(widget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setFont(font3);

        verticalLayout->addWidget(label_17);


        horizontalLayout->addWidget(widget);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setFont(font);
        gridLayout_6 = new QGridLayout(groupBox_4);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_13 = new QLabel(groupBox_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_6->addWidget(label_13, 3, 3, 1, 1);

        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_6->addWidget(label_7, 3, 0, 1, 1);

        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_6->addWidget(label_10, 0, 3, 1, 1);

        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_6->addWidget(label_6, 0, 1, 1, 1);

        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_6->addWidget(label_11, 3, 1, 1, 1);

        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_6->addWidget(label_12, 3, 2, 1, 1);

        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_6->addWidget(label_4, 0, 0, 1, 1);

        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_6->addWidget(label_9, 0, 2, 1, 1);


        gridLayout_2->addWidget(groupBox_4, 1, 1, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalLayout_2 = new QHBoxLayout(tab_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        widget_4 = new QWidget(tab_2);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        gridLayout_7 = new QGridLayout(widget_4);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        groupBox_5 = new QGroupBox(widget_4);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_8 = new QGridLayout(groupBox_5);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label_48 = new QLabel(groupBox_5);
        label_48->setObjectName(QString::fromUtf8("label_48"));
        label_48->setMaximumSize(QSize(90, 16777215));
        QFont font5;
        font5.setPointSize(9);
        label_48->setFont(font5);
        label_48->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_48, 4, 0, 1, 1);

        label_45 = new QLabel(groupBox_5);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setMaximumSize(QSize(90, 16777215));
        label_45->setFont(font5);
        label_45->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_45, 0, 0, 1, 1);

        i2_0 = new QLabel(groupBox_5);
        i2_0->setObjectName(QString::fromUtf8("i2_0"));
        i2_0->setMinimumSize(QSize(40, 38));
        i2_0->setMaximumSize(QSize(40, 38));
        i2_0->setPixmap(QPixmap(QString::fromUtf8(":/icon/res/png/led_off.png")));
        i2_0->setScaledContents(true);

        gridLayout_8->addWidget(i2_0, 0, 5, 1, 1);

        label_44 = new QLabel(groupBox_5);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setMaximumSize(QSize(90, 16777215));
        label_44->setFont(font5);
        label_44->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_44, 2, 0, 1, 1);

        label_47 = new QLabel(groupBox_5);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setMaximumSize(QSize(90, 16777215));
        label_47->setFont(font5);
        label_47->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_47, 3, 0, 1, 1);

        label_50 = new QLabel(groupBox_5);
        label_50->setObjectName(QString::fromUtf8("label_50"));
        label_50->setMaximumSize(QSize(90, 16777215));
        label_50->setFont(font5);
        label_50->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_50, 6, 0, 1, 1);

        label_51 = new QLabel(groupBox_5);
        label_51->setObjectName(QString::fromUtf8("label_51"));
        label_51->setMaximumSize(QSize(90, 16777215));
        label_51->setFont(font5);
        label_51->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_51, 7, 0, 1, 1);

        label_52 = new QLabel(groupBox_5);
        label_52->setObjectName(QString::fromUtf8("label_52"));
        label_52->setMaximumSize(QSize(90, 16777215));
        label_52->setFont(font5);
        label_52->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_52, 1, 2, 1, 1);

        label_53 = new QLabel(groupBox_5);
        label_53->setObjectName(QString::fromUtf8("label_53"));
        label_53->setMaximumSize(QSize(90, 16777215));
        label_53->setFont(font5);
        label_53->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_53, 1, 4, 1, 1);

        i2_1 = new QLabel(groupBox_5);
        i2_1->setObjectName(QString::fromUtf8("i2_1"));
        i2_1->setMinimumSize(QSize(40, 38));
        i2_1->setMaximumSize(QSize(40, 38));
        i2_1->setPixmap(QPixmap(QString::fromUtf8(":/icon/res/png/led_off.png")));
        i2_1->setScaledContents(true);

        gridLayout_8->addWidget(i2_1, 1, 5, 1, 1);

        i2_2 = new QLabel(groupBox_5);
        i2_2->setObjectName(QString::fromUtf8("i2_2"));
        i2_2->setMinimumSize(QSize(40, 38));
        i2_2->setMaximumSize(QSize(40, 38));
        i2_2->setPixmap(QPixmap(QString::fromUtf8(":/icon/res/png/led_off.png")));
        i2_2->setScaledContents(true);

        gridLayout_8->addWidget(i2_2, 2, 5, 1, 1);

        i2_3 = new QLabel(groupBox_5);
        i2_3->setObjectName(QString::fromUtf8("i2_3"));
        i2_3->setMinimumSize(QSize(40, 38));
        i2_3->setMaximumSize(QSize(40, 38));
        i2_3->setPixmap(QPixmap(QString::fromUtf8(":/icon/res/png/led_off.png")));
        i2_3->setScaledContents(true);

        gridLayout_8->addWidget(i2_3, 3, 5, 1, 1);

        i2_5 = new QLabel(groupBox_5);
        i2_5->setObjectName(QString::fromUtf8("i2_5"));
        i2_5->setMinimumSize(QSize(40, 38));
        i2_5->setMaximumSize(QSize(40, 38));
        i2_5->setPixmap(QPixmap(QString::fromUtf8(":/icon/res/png/led_off.png")));
        i2_5->setScaledContents(true);

        gridLayout_8->addWidget(i2_5, 5, 5, 1, 1);

        label_54 = new QLabel(groupBox_5);
        label_54->setObjectName(QString::fromUtf8("label_54"));
        label_54->setMaximumSize(QSize(90, 16777215));
        label_54->setFont(font5);
        label_54->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_54, 0, 2, 1, 1);

        i2_6 = new QLabel(groupBox_5);
        i2_6->setObjectName(QString::fromUtf8("i2_6"));
        i2_6->setMinimumSize(QSize(40, 38));
        i2_6->setMaximumSize(QSize(40, 38));
        i2_6->setPixmap(QPixmap(QString::fromUtf8(":/icon/res/png/led_off.png")));
        i2_6->setScaledContents(true);

        gridLayout_8->addWidget(i2_6, 6, 5, 1, 1);

        i2_4 = new QLabel(groupBox_5);
        i2_4->setObjectName(QString::fromUtf8("i2_4"));
        i2_4->setMinimumSize(QSize(40, 38));
        i2_4->setMaximumSize(QSize(40, 38));
        i2_4->setPixmap(QPixmap(QString::fromUtf8(":/icon/res/png/led_off.png")));
        i2_4->setScaledContents(true);

        gridLayout_8->addWidget(i2_4, 4, 5, 1, 1);

        i2_7 = new QLabel(groupBox_5);
        i2_7->setObjectName(QString::fromUtf8("i2_7"));
        i2_7->setMinimumSize(QSize(40, 38));
        i2_7->setMaximumSize(QSize(40, 38));
        i2_7->setPixmap(QPixmap(QString::fromUtf8(":/icon/res/png/led_off.png")));
        i2_7->setScaledContents(true);

        gridLayout_8->addWidget(i2_7, 7, 5, 1, 1);

        label_49 = new QLabel(groupBox_5);
        label_49->setObjectName(QString::fromUtf8("label_49"));
        label_49->setMaximumSize(QSize(90, 16777215));
        label_49->setFont(font5);
        label_49->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_49, 5, 0, 1, 1);

        i0_6 = new QLabel(groupBox_5);
        i0_6->setObjectName(QString::fromUtf8("i0_6"));
        i0_6->setMinimumSize(QSize(40, 38));
        i0_6->setMaximumSize(QSize(40, 38));
        i0_6->setPixmap(QPixmap(QString::fromUtf8(":/icon/res/png/led_off.png")));
        i0_6->setScaledContents(true);

        gridLayout_8->addWidget(i0_6, 6, 1, 1, 1);

        i1_5 = new QLabel(groupBox_5);
        i1_5->setObjectName(QString::fromUtf8("i1_5"));
        i1_5->setMinimumSize(QSize(40, 38));
        i1_5->setMaximumSize(QSize(40, 38));
        i1_5->setPixmap(QPixmap(QString::fromUtf8(":/icon/res/png/led_off.png")));
        i1_5->setScaledContents(true);

        gridLayout_8->addWidget(i1_5, 5, 3, 1, 1);

        i1_6 = new QLabel(groupBox_5);
        i1_6->setObjectName(QString::fromUtf8("i1_6"));
        i1_6->setMinimumSize(QSize(40, 38));
        i1_6->setMaximumSize(QSize(40, 38));
        i1_6->setPixmap(QPixmap(QString::fromUtf8(":/icon/res/png/led_off.png")));
        i1_6->setScaledContents(true);

        gridLayout_8->addWidget(i1_6, 6, 3, 1, 1);

        i1_4 = new QLabel(groupBox_5);
        i1_4->setObjectName(QString::fromUtf8("i1_4"));
        i1_4->setMinimumSize(QSize(40, 38));
        i1_4->setMaximumSize(QSize(40, 38));
        i1_4->setPixmap(QPixmap(QString::fromUtf8(":/icon/res/png/led_off.png")));
        i1_4->setScaledContents(true);

        gridLayout_8->addWidget(i1_4, 4, 3, 1, 1);

        i1_7 = new QLabel(groupBox_5);
        i1_7->setObjectName(QString::fromUtf8("i1_7"));
        i1_7->setMinimumSize(QSize(40, 38));
        i1_7->setMaximumSize(QSize(40, 38));
        i1_7->setPixmap(QPixmap(QString::fromUtf8(":/icon/res/png/led_off.png")));
        i1_7->setScaledContents(true);

        gridLayout_8->addWidget(i1_7, 7, 3, 1, 1);

        i0_7 = new QLabel(groupBox_5);
        i0_7->setObjectName(QString::fromUtf8("i0_7"));
        i0_7->setMinimumSize(QSize(40, 38));
        i0_7->setMaximumSize(QSize(40, 38));
        i0_7->setPixmap(QPixmap(QString::fromUtf8(":/icon/res/png/led_off.png")));
        i0_7->setScaledContents(true);

        gridLayout_8->addWidget(i0_7, 7, 1, 1, 1);

        i0_1 = new QLabel(groupBox_5);
        i0_1->setObjectName(QString::fromUtf8("i0_1"));
        i0_1->setMinimumSize(QSize(40, 38));
        i0_1->setMaximumSize(QSize(40, 38));
        i0_1->setPixmap(QPixmap(QString::fromUtf8(":/icon/res/png/led_off.png")));
        i0_1->setScaledContents(true);

        gridLayout_8->addWidget(i0_1, 1, 1, 1, 1);

        i0_2 = new QLabel(groupBox_5);
        i0_2->setObjectName(QString::fromUtf8("i0_2"));
        i0_2->setMinimumSize(QSize(40, 38));
        i0_2->setMaximumSize(QSize(40, 38));
        i0_2->setPixmap(QPixmap(QString::fromUtf8(":/icon/res/png/led_off.png")));
        i0_2->setScaledContents(true);

        gridLayout_8->addWidget(i0_2, 2, 1, 1, 1);

        i0_3 = new QLabel(groupBox_5);
        i0_3->setObjectName(QString::fromUtf8("i0_3"));
        i0_3->setMinimumSize(QSize(40, 38));
        i0_3->setMaximumSize(QSize(40, 38));
        i0_3->setPixmap(QPixmap(QString::fromUtf8(":/icon/res/png/led_off.png")));
        i0_3->setScaledContents(true);

        gridLayout_8->addWidget(i0_3, 3, 1, 1, 1);

        i0_4 = new QLabel(groupBox_5);
        i0_4->setObjectName(QString::fromUtf8("i0_4"));
        i0_4->setMinimumSize(QSize(40, 38));
        i0_4->setMaximumSize(QSize(40, 38));
        i0_4->setPixmap(QPixmap(QString::fromUtf8(":/icon/res/png/led_off.png")));
        i0_4->setScaledContents(true);

        gridLayout_8->addWidget(i0_4, 4, 1, 1, 1);

        i0_5 = new QLabel(groupBox_5);
        i0_5->setObjectName(QString::fromUtf8("i0_5"));
        i0_5->setMinimumSize(QSize(40, 38));
        i0_5->setMaximumSize(QSize(40, 38));
        i0_5->setPixmap(QPixmap(QString::fromUtf8(":/icon/res/png/led_off.png")));
        i0_5->setScaledContents(true);

        gridLayout_8->addWidget(i0_5, 5, 1, 1, 1);

        label_46 = new QLabel(groupBox_5);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setMaximumSize(QSize(90, 16777215));
        label_46->setFont(font5);
        label_46->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_46, 1, 0, 1, 1);

        label_56 = new QLabel(groupBox_5);
        label_56->setObjectName(QString::fromUtf8("label_56"));
        label_56->setMaximumSize(QSize(90, 16777215));
        label_56->setFont(font5);
        label_56->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_56, 3, 2, 1, 1);

        label_57 = new QLabel(groupBox_5);
        label_57->setObjectName(QString::fromUtf8("label_57"));
        label_57->setMaximumSize(QSize(90, 16777215));
        label_57->setFont(font5);
        label_57->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_57, 4, 2, 1, 1);

        label_66 = new QLabel(groupBox_5);
        label_66->setObjectName(QString::fromUtf8("label_66"));
        label_66->setMaximumSize(QSize(90, 16777215));
        label_66->setFont(font5);
        label_66->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_66, 5, 2, 1, 1);

        label_67 = new QLabel(groupBox_5);
        label_67->setObjectName(QString::fromUtf8("label_67"));
        label_67->setMaximumSize(QSize(90, 16777215));
        label_67->setFont(font5);
        label_67->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_67, 6, 2, 1, 1);

        label_68 = new QLabel(groupBox_5);
        label_68->setObjectName(QString::fromUtf8("label_68"));
        label_68->setMaximumSize(QSize(90, 16777215));
        label_68->setFont(font5);
        label_68->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_68, 7, 2, 1, 1);

        label_69 = new QLabel(groupBox_5);
        label_69->setObjectName(QString::fromUtf8("label_69"));
        label_69->setMaximumSize(QSize(90, 16777215));
        label_69->setFont(font5);
        label_69->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_69, 0, 4, 1, 1);

        label_70 = new QLabel(groupBox_5);
        label_70->setObjectName(QString::fromUtf8("label_70"));
        label_70->setMaximumSize(QSize(90, 16777215));
        label_70->setFont(font5);
        label_70->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_70, 2, 4, 1, 1);

        label_72 = new QLabel(groupBox_5);
        label_72->setObjectName(QString::fromUtf8("label_72"));
        label_72->setMaximumSize(QSize(90, 16777215));
        label_72->setFont(font5);
        label_72->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_72, 4, 4, 1, 1);

        label_73 = new QLabel(groupBox_5);
        label_73->setObjectName(QString::fromUtf8("label_73"));
        label_73->setMaximumSize(QSize(90, 16777215));
        label_73->setFont(font5);
        label_73->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_73, 5, 4, 1, 1);

        label_74 = new QLabel(groupBox_5);
        label_74->setObjectName(QString::fromUtf8("label_74"));
        label_74->setMaximumSize(QSize(90, 16777215));
        label_74->setFont(font5);
        label_74->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_74, 6, 4, 1, 1);

        label_75 = new QLabel(groupBox_5);
        label_75->setObjectName(QString::fromUtf8("label_75"));
        label_75->setMaximumSize(QSize(90, 16777215));
        label_75->setFont(font5);
        label_75->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_75, 7, 4, 1, 1);

        label_55 = new QLabel(groupBox_5);
        label_55->setObjectName(QString::fromUtf8("label_55"));
        label_55->setMaximumSize(QSize(90, 16777215));
        label_55->setFont(font5);
        label_55->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_55, 2, 2, 1, 1);

        i0_0 = new QLabel(groupBox_5);
        i0_0->setObjectName(QString::fromUtf8("i0_0"));
        i0_0->setMinimumSize(QSize(40, 38));
        i0_0->setMaximumSize(QSize(40, 38));
        i0_0->setPixmap(QPixmap(QString::fromUtf8(":/icon/res/png/led_off.png")));
        i0_0->setScaledContents(true);

        gridLayout_8->addWidget(i0_0, 0, 1, 1, 1);

        i1_2 = new QLabel(groupBox_5);
        i1_2->setObjectName(QString::fromUtf8("i1_2"));
        i1_2->setMinimumSize(QSize(40, 38));
        i1_2->setMaximumSize(QSize(40, 38));
        i1_2->setPixmap(QPixmap(QString::fromUtf8(":/icon/res/png/led_off.png")));
        i1_2->setScaledContents(true);

        gridLayout_8->addWidget(i1_2, 2, 3, 1, 1);

        i1_3 = new QLabel(groupBox_5);
        i1_3->setObjectName(QString::fromUtf8("i1_3"));
        i1_3->setMinimumSize(QSize(40, 38));
        i1_3->setMaximumSize(QSize(40, 38));
        i1_3->setPixmap(QPixmap(QString::fromUtf8(":/icon/res/png/led_off.png")));
        i1_3->setScaledContents(true);

        gridLayout_8->addWidget(i1_3, 3, 3, 1, 1);

        i1_1 = new QLabel(groupBox_5);
        i1_1->setObjectName(QString::fromUtf8("i1_1"));
        i1_1->setMinimumSize(QSize(40, 38));
        i1_1->setMaximumSize(QSize(40, 38));
        i1_1->setPixmap(QPixmap(QString::fromUtf8(":/icon/res/png/led_off.png")));
        i1_1->setScaledContents(true);

        gridLayout_8->addWidget(i1_1, 1, 3, 1, 1);

        i1_0 = new QLabel(groupBox_5);
        i1_0->setObjectName(QString::fromUtf8("i1_0"));
        i1_0->setMinimumSize(QSize(40, 38));
        i1_0->setMaximumSize(QSize(40, 38));
        i1_0->setPixmap(QPixmap(QString::fromUtf8(":/icon/res/png/led_off.png")));
        i1_0->setScaledContents(true);

        gridLayout_8->addWidget(i1_0, 0, 3, 1, 1);

        label_71 = new QLabel(groupBox_5);
        label_71->setObjectName(QString::fromUtf8("label_71"));
        label_71->setMaximumSize(QSize(90, 16777215));
        label_71->setFont(font5);
        label_71->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_71, 3, 4, 1, 1);


        gridLayout_7->addWidget(groupBox_5, 0, 0, 1, 1);

        groupBox_6 = new QGroupBox(widget_4);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        gridLayout_10 = new QGridLayout(groupBox_6);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        q2_0 = new QPushButton(groupBox_6);
        q2_0->setObjectName(QString::fromUtf8("q2_0"));
        q2_0->setMinimumSize(QSize(100, 40));
        q2_0->setMaximumSize(QSize(100, 40));
        q2_0->setFont(font1);
        q2_0->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	background-color: rgb(108, 191, 230);\n"
"    border-radius: 11px 11px ;\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"    background-color: rgb(56, 135, 188);\n"
"}\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: rgb(144, 48, 0)\n"
"}\n"
"QPushButton::checked \n"
"{\n"
"    \n"
"	\n"
"	background-color: rgb(204, 0, 20);\n"
"}"));
        q2_0->setCheckable(true);

        gridLayout_10->addWidget(q2_0, 0, 2, 1, 1);

        q0_0 = new QPushButton(groupBox_6);
        q0_0->setObjectName(QString::fromUtf8("q0_0"));
        q0_0->setMinimumSize(QSize(100, 40));
        q0_0->setMaximumSize(QSize(100, 40));
        q0_0->setFont(font1);
        q0_0->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	background-color: rgb(108, 191, 230);\n"
"    border-radius: 11px 11px ;\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"    background-color: rgb(56, 135, 188);\n"
"}\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: rgb(144, 48, 0)\n"
"}\n"
"QPushButton::checked \n"
"{\n"
"    \n"
"	\n"
"	background-color: rgb(204, 0, 20);\n"
"}"));
        q0_0->setCheckable(true);

        gridLayout_10->addWidget(q0_0, 0, 0, 1, 1);

        q1_0 = new QPushButton(groupBox_6);
        q1_0->setObjectName(QString::fromUtf8("q1_0"));
        q1_0->setMinimumSize(QSize(100, 40));
        q1_0->setMaximumSize(QSize(100, 40));
        q1_0->setFont(font1);
        q1_0->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	background-color: rgb(108, 191, 230);\n"
"    border-radius: 11px 11px ;\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"    background-color: rgb(56, 135, 188);\n"
"}\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: rgb(144, 48, 0)\n"
"}\n"
"QPushButton::checked \n"
"{\n"
"    \n"
"	\n"
"	background-color: rgb(204, 0, 20);\n"
"}"));
        q1_0->setCheckable(true);

        gridLayout_10->addWidget(q1_0, 0, 1, 1, 1);

        q0_6 = new QPushButton(groupBox_6);
        q0_6->setObjectName(QString::fromUtf8("q0_6"));
        q0_6->setMinimumSize(QSize(100, 40));
        q0_6->setMaximumSize(QSize(100, 40));
        q0_6->setFont(font1);
        q0_6->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	background-color: rgb(108, 191, 230);\n"
"    border-radius: 11px 11px ;\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"    background-color: rgb(56, 135, 188);\n"
"}\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: rgb(144, 48, 0)\n"
"}\n"
"QPushButton::checked \n"
"{\n"
"    \n"
"	\n"
"	background-color: rgb(204, 0, 20);\n"
"}"));
        q0_6->setCheckable(true);

        gridLayout_10->addWidget(q0_6, 6, 0, 1, 1);

        q1_6 = new QPushButton(groupBox_6);
        q1_6->setObjectName(QString::fromUtf8("q1_6"));
        q1_6->setMinimumSize(QSize(100, 40));
        q1_6->setMaximumSize(QSize(100, 40));
        q1_6->setFont(font1);
        q1_6->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	background-color: rgb(108, 191, 230);\n"
"    border-radius: 11px 11px ;\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"    background-color: rgb(56, 135, 188);\n"
"}\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: rgb(144, 48, 0)\n"
"}\n"
"QPushButton::checked \n"
"{\n"
"    \n"
"	\n"
"	background-color: rgb(204, 0, 20);\n"
"}"));
        q1_6->setCheckable(true);

        gridLayout_10->addWidget(q1_6, 6, 1, 1, 1);

        q2_7 = new QPushButton(groupBox_6);
        q2_7->setObjectName(QString::fromUtf8("q2_7"));
        q2_7->setMinimumSize(QSize(100, 40));
        q2_7->setMaximumSize(QSize(100, 40));
        q2_7->setFont(font1);
        q2_7->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	background-color: rgb(108, 191, 230);\n"
"    border-radius: 11px 11px ;\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"    background-color: rgb(56, 135, 188);\n"
"}\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: rgb(144, 48, 0)\n"
"}\n"
"QPushButton::checked \n"
"{\n"
"    \n"
"	\n"
"	background-color: rgb(204, 0, 20);\n"
"}"));
        q2_7->setCheckable(true);

        gridLayout_10->addWidget(q2_7, 7, 2, 1, 1);

        q1_7 = new QPushButton(groupBox_6);
        q1_7->setObjectName(QString::fromUtf8("q1_7"));
        q1_7->setMinimumSize(QSize(100, 40));
        q1_7->setMaximumSize(QSize(100, 40));
        q1_7->setFont(font1);
        q1_7->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	background-color: rgb(108, 191, 230);\n"
"    border-radius: 11px 11px ;\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"    background-color: rgb(56, 135, 188);\n"
"}\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: rgb(144, 48, 0)\n"
"}\n"
"QPushButton::checked \n"
"{\n"
"    \n"
"	\n"
"	background-color: rgb(204, 0, 20);\n"
"}"));
        q1_7->setCheckable(true);

        gridLayout_10->addWidget(q1_7, 7, 1, 1, 1);

        q0_1 = new QPushButton(groupBox_6);
        q0_1->setObjectName(QString::fromUtf8("q0_1"));
        q0_1->setMinimumSize(QSize(100, 40));
        q0_1->setMaximumSize(QSize(100, 40));
        q0_1->setFont(font1);
        q0_1->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	background-color: rgb(108, 191, 230);\n"
"    border-radius: 11px 11px ;\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"    background-color: rgb(56, 135, 188);\n"
"}\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: rgb(144, 48, 0)\n"
"}\n"
"QPushButton::checked \n"
"{\n"
"    \n"
"	\n"
"	background-color: rgb(204, 0, 20);\n"
"}"));
        q0_1->setCheckable(true);

        gridLayout_10->addWidget(q0_1, 1, 0, 1, 1);

        q0_7 = new QPushButton(groupBox_6);
        q0_7->setObjectName(QString::fromUtf8("q0_7"));
        q0_7->setMinimumSize(QSize(100, 40));
        q0_7->setMaximumSize(QSize(100, 40));
        q0_7->setFont(font1);
        q0_7->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	background-color: rgb(108, 191, 230);\n"
"    border-radius: 11px 11px ;\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"    background-color: rgb(56, 135, 188);\n"
"}\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: rgb(144, 48, 0)\n"
"}\n"
"QPushButton::checked \n"
"{\n"
"    \n"
"	\n"
"	background-color: rgb(204, 0, 20);\n"
"}"));
        q0_7->setCheckable(true);

        gridLayout_10->addWidget(q0_7, 7, 0, 1, 1);

        q0_2 = new QPushButton(groupBox_6);
        q0_2->setObjectName(QString::fromUtf8("q0_2"));
        q0_2->setMinimumSize(QSize(100, 40));
        q0_2->setMaximumSize(QSize(100, 40));
        q0_2->setFont(font1);
        q0_2->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	background-color: rgb(108, 191, 230);\n"
"    border-radius: 11px 11px ;\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"    background-color: rgb(56, 135, 188);\n"
"}\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: rgb(144, 48, 0)\n"
"}\n"
"QPushButton::checked \n"
"{\n"
"    \n"
"	\n"
"	background-color: rgb(204, 0, 20);\n"
"}"));
        q0_2->setCheckable(true);

        gridLayout_10->addWidget(q0_2, 2, 0, 1, 1);

        q0_3 = new QPushButton(groupBox_6);
        q0_3->setObjectName(QString::fromUtf8("q0_3"));
        q0_3->setMinimumSize(QSize(100, 40));
        q0_3->setMaximumSize(QSize(100, 40));
        q0_3->setFont(font1);
        q0_3->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	background-color: rgb(108, 191, 230);\n"
"    border-radius: 11px 11px ;\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"    background-color: rgb(56, 135, 188);\n"
"}\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: rgb(144, 48, 0)\n"
"}\n"
"QPushButton::checked \n"
"{\n"
"    \n"
"	\n"
"	background-color: rgb(204, 0, 20);\n"
"}"));
        q0_3->setCheckable(true);

        gridLayout_10->addWidget(q0_3, 3, 0, 1, 1);

        q0_4 = new QPushButton(groupBox_6);
        q0_4->setObjectName(QString::fromUtf8("q0_4"));
        q0_4->setMinimumSize(QSize(100, 40));
        q0_4->setMaximumSize(QSize(100, 40));
        q0_4->setFont(font1);
        q0_4->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	background-color: rgb(108, 191, 230);\n"
"    border-radius: 11px 11px ;\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"    background-color: rgb(56, 135, 188);\n"
"}\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: rgb(144, 48, 0)\n"
"}\n"
"QPushButton::checked \n"
"{\n"
"    \n"
"	\n"
"	background-color: rgb(204, 0, 20);\n"
"}"));
        q0_4->setCheckable(true);

        gridLayout_10->addWidget(q0_4, 4, 0, 1, 1);

        q0_5 = new QPushButton(groupBox_6);
        q0_5->setObjectName(QString::fromUtf8("q0_5"));
        q0_5->setMinimumSize(QSize(100, 40));
        q0_5->setMaximumSize(QSize(100, 40));
        q0_5->setFont(font1);
        q0_5->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	background-color: rgb(108, 191, 230);\n"
"    border-radius: 11px 11px ;\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"    background-color: rgb(56, 135, 188);\n"
"}\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: rgb(144, 48, 0)\n"
"}\n"
"QPushButton::checked \n"
"{\n"
"    \n"
"	\n"
"	background-color: rgb(204, 0, 20);\n"
"}"));
        q0_5->setCheckable(true);

        gridLayout_10->addWidget(q0_5, 5, 0, 1, 1);

        q1_1 = new QPushButton(groupBox_6);
        q1_1->setObjectName(QString::fromUtf8("q1_1"));
        q1_1->setMinimumSize(QSize(100, 40));
        q1_1->setMaximumSize(QSize(100, 40));
        q1_1->setFont(font1);
        q1_1->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	background-color: rgb(108, 191, 230);\n"
"    border-radius: 11px 11px ;\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"    background-color: rgb(56, 135, 188);\n"
"}\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: rgb(144, 48, 0)\n"
"}\n"
"QPushButton::checked \n"
"{\n"
"    \n"
"	\n"
"	background-color: rgb(204, 0, 20);\n"
"}"));
        q1_1->setCheckable(true);

        gridLayout_10->addWidget(q1_1, 1, 1, 1, 1);

        q1_2 = new QPushButton(groupBox_6);
        q1_2->setObjectName(QString::fromUtf8("q1_2"));
        q1_2->setMinimumSize(QSize(100, 40));
        q1_2->setMaximumSize(QSize(100, 40));
        q1_2->setFont(font1);
        q1_2->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	background-color: rgb(108, 191, 230);\n"
"    border-radius: 11px 11px ;\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"    background-color: rgb(56, 135, 188);\n"
"}\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: rgb(144, 48, 0)\n"
"}\n"
"QPushButton::checked \n"
"{\n"
"    \n"
"	\n"
"	background-color: rgb(204, 0, 20);\n"
"}"));
        q1_2->setCheckable(true);

        gridLayout_10->addWidget(q1_2, 2, 1, 1, 1);

        q1_3 = new QPushButton(groupBox_6);
        q1_3->setObjectName(QString::fromUtf8("q1_3"));
        q1_3->setMinimumSize(QSize(100, 40));
        q1_3->setMaximumSize(QSize(100, 40));
        q1_3->setFont(font1);
        q1_3->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	background-color: rgb(108, 191, 230);\n"
"    border-radius: 11px 11px ;\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"    background-color: rgb(56, 135, 188);\n"
"}\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: rgb(144, 48, 0)\n"
"}\n"
"QPushButton::checked \n"
"{\n"
"    \n"
"	\n"
"	background-color: rgb(204, 0, 20);\n"
"}"));
        q1_3->setCheckable(true);

        gridLayout_10->addWidget(q1_3, 3, 1, 1, 1);

        q1_4 = new QPushButton(groupBox_6);
        q1_4->setObjectName(QString::fromUtf8("q1_4"));
        q1_4->setMinimumSize(QSize(100, 40));
        q1_4->setMaximumSize(QSize(100, 40));
        q1_4->setFont(font1);
        q1_4->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	background-color: rgb(108, 191, 230);\n"
"    border-radius: 11px 11px ;\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"    background-color: rgb(56, 135, 188);\n"
"}\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: rgb(144, 48, 0)\n"
"}\n"
"QPushButton::checked \n"
"{\n"
"    \n"
"	\n"
"	background-color: rgb(204, 0, 20);\n"
"}"));
        q1_4->setCheckable(true);

        gridLayout_10->addWidget(q1_4, 4, 1, 1, 1);

        q1_5 = new QPushButton(groupBox_6);
        q1_5->setObjectName(QString::fromUtf8("q1_5"));
        q1_5->setMinimumSize(QSize(100, 40));
        q1_5->setMaximumSize(QSize(100, 40));
        q1_5->setFont(font1);
        q1_5->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	background-color: rgb(108, 191, 230);\n"
"    border-radius: 11px 11px ;\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"    background-color: rgb(56, 135, 188);\n"
"}\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: rgb(144, 48, 0)\n"
"}\n"
"QPushButton::checked \n"
"{\n"
"    \n"
"	\n"
"	background-color: rgb(204, 0, 20);\n"
"}"));
        q1_5->setCheckable(true);

        gridLayout_10->addWidget(q1_5, 5, 1, 1, 1);

        q2_1 = new QPushButton(groupBox_6);
        q2_1->setObjectName(QString::fromUtf8("q2_1"));
        q2_1->setMinimumSize(QSize(100, 40));
        q2_1->setMaximumSize(QSize(100, 40));
        q2_1->setFont(font1);
        q2_1->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	background-color: rgb(108, 191, 230);\n"
"    border-radius: 11px 11px ;\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"    background-color: rgb(56, 135, 188);\n"
"}\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: rgb(144, 48, 0)\n"
"}\n"
"QPushButton::checked \n"
"{\n"
"    \n"
"	\n"
"	background-color: rgb(204, 0, 20);\n"
"}"));
        q2_1->setCheckable(true);

        gridLayout_10->addWidget(q2_1, 1, 2, 1, 1);

        q2_2 = new QPushButton(groupBox_6);
        q2_2->setObjectName(QString::fromUtf8("q2_2"));
        q2_2->setMinimumSize(QSize(100, 40));
        q2_2->setMaximumSize(QSize(100, 40));
        q2_2->setFont(font1);
        q2_2->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	background-color: rgb(108, 191, 230);\n"
"    border-radius: 11px 11px ;\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"    background-color: rgb(56, 135, 188);\n"
"}\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: rgb(144, 48, 0)\n"
"}\n"
"QPushButton::checked \n"
"{\n"
"    \n"
"	\n"
"	background-color: rgb(204, 0, 20);\n"
"}"));
        q2_2->setCheckable(true);

        gridLayout_10->addWidget(q2_2, 2, 2, 1, 1);

        q2_3 = new QPushButton(groupBox_6);
        q2_3->setObjectName(QString::fromUtf8("q2_3"));
        q2_3->setMinimumSize(QSize(100, 40));
        q2_3->setMaximumSize(QSize(100, 40));
        q2_3->setFont(font1);
        q2_3->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	background-color: rgb(108, 191, 230);\n"
"    border-radius: 11px 11px ;\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"    background-color: rgb(56, 135, 188);\n"
"}\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: rgb(144, 48, 0)\n"
"}\n"
"QPushButton::checked \n"
"{\n"
"    \n"
"	\n"
"	background-color: rgb(204, 0, 20);\n"
"}"));
        q2_3->setCheckable(true);

        gridLayout_10->addWidget(q2_3, 3, 2, 1, 1);

        q2_4 = new QPushButton(groupBox_6);
        q2_4->setObjectName(QString::fromUtf8("q2_4"));
        q2_4->setMinimumSize(QSize(100, 40));
        q2_4->setMaximumSize(QSize(100, 40));
        q2_4->setFont(font1);
        q2_4->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	background-color: rgb(108, 191, 230);\n"
"    border-radius: 11px 11px ;\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"    background-color: rgb(56, 135, 188);\n"
"}\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: rgb(144, 48, 0)\n"
"}\n"
"QPushButton::checked \n"
"{\n"
"    \n"
"	\n"
"	background-color: rgb(204, 0, 20);\n"
"}"));
        q2_4->setCheckable(true);

        gridLayout_10->addWidget(q2_4, 4, 2, 1, 1);

        q2_5 = new QPushButton(groupBox_6);
        q2_5->setObjectName(QString::fromUtf8("q2_5"));
        q2_5->setMinimumSize(QSize(100, 40));
        q2_5->setMaximumSize(QSize(100, 40));
        q2_5->setFont(font1);
        q2_5->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	background-color: rgb(108, 191, 230);\n"
"    border-radius: 11px 11px ;\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"    background-color: rgb(56, 135, 188);\n"
"}\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: rgb(144, 48, 0)\n"
"}\n"
"QPushButton::checked \n"
"{\n"
"    \n"
"	\n"
"	background-color: rgb(204, 0, 20);\n"
"}"));
        q2_5->setCheckable(true);

        gridLayout_10->addWidget(q2_5, 5, 2, 1, 1);

        q2_6 = new QPushButton(groupBox_6);
        q2_6->setObjectName(QString::fromUtf8("q2_6"));
        q2_6->setMinimumSize(QSize(100, 40));
        q2_6->setMaximumSize(QSize(100, 40));
        q2_6->setFont(font1);
        q2_6->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	background-color: rgb(108, 191, 230);\n"
"    border-radius: 11px 11px ;\n"
"}\n"
"QPushButton::hover\n"
"{\n"
"    background-color: rgb(56, 135, 188);\n"
"}\n"
"QPushButton::pressed\n"
"{\n"
"    background-color: rgb(144, 48, 0)\n"
"}\n"
"QPushButton::checked \n"
"{\n"
"    \n"
"	\n"
"	background-color: rgb(204, 0, 20);\n"
"}"));
        q2_6->setCheckable(true);

        gridLayout_10->addWidget(q2_6, 6, 2, 1, 1);


        gridLayout_7->addWidget(groupBox_6, 0, 1, 1, 1);


        horizontalLayout_2->addWidget(widget_4);

        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 1, 0, 1, 1);


        retranslateUi(DebugWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DebugWidget);
    } // setupUi

    void retranslateUi(QWidget *DebugWidget)
    {
        DebugWidget->setWindowTitle(QCoreApplication::translate("DebugWidget", "DebugWidget", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("DebugWidget", "\345\212\237\350\203\275", nullptr));
        btnXaxisHome->setText(QCoreApplication::translate("DebugWidget", "X\350\275\264\345\233\236\345\216\237\347\202\271", nullptr));
        btnXaxisReset->setText(QCoreApplication::translate("DebugWidget", "X\350\275\264\345\244\215\344\275\215", nullptr));
        btnYaxisHome->setText(QCoreApplication::translate("DebugWidget", "Y\350\275\264\345\233\236\345\216\237\347\202\271", nullptr));
        btnYaxisReset->setText(QCoreApplication::translate("DebugWidget", "Y\350\275\264\345\244\215\344\275\215", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("DebugWidget", "\345\256\232\344\275\215", nullptr));
        btnXaxisGoto->setText(QCoreApplication::translate("DebugWidget", "X\350\275\264\345\256\232\344\275\215", nullptr));
        btnYaxisGoto->setText(QCoreApplication::translate("DebugWidget", "Y\350\275\264\345\256\232\344\275\215", nullptr));
        label->setText(QCoreApplication::translate("DebugWidget", "X\350\275\264\344\275\215\347\275\256\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("DebugWidget", "MIN:111,MAX:222", nullptr));
        label_3->setText(QCoreApplication::translate("DebugWidget", "MIN:111,MAX:222", nullptr));
        labXaxisLocationOdd->setText(QCoreApplication::translate("DebugWidget", "\345\211\251\344\275\231\344\275\215\347\275\256\357\274\2320.0", nullptr));
        label_2->setText(QCoreApplication::translate("DebugWidget", "X\350\275\264\344\275\215\347\275\256\357\274\232", nullptr));
        labYaxisLocationOdd->setText(QCoreApplication::translate("DebugWidget", "\345\211\251\344\275\231\344\275\215\347\275\256\357\274\2320.0", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DebugWidget", "\347\202\271\345\212\250", nullptr));
        btnYaxisUp->setText(QCoreApplication::translate("DebugWidget", "Y\350\275\264\344\270\212\347\247\273", nullptr));
        btnXaxisR->setText(QCoreApplication::translate("DebugWidget", "X\350\275\264\345\217\263\347\247\273", nullptr));
        btnYaxisDown->setText(QCoreApplication::translate("DebugWidget", "Y\350\275\264\344\270\213\347\247\273", nullptr));
        btnXaxisL->setText(QCoreApplication::translate("DebugWidget", "X\350\275\264\345\267\246\347\247\273", nullptr));
        label_15->setText(QCoreApplication::translate("DebugWidget", "X\350\275\264\347\202\271\345\212\250\351\200\237\345\272\246\357\274\232", nullptr));
        label_16->setText(QCoreApplication::translate("DebugWidget", "MIN:111,MAX:222", nullptr));
        label_8->setText(QCoreApplication::translate("DebugWidget", "X\350\275\264\347\202\271\345\212\250\351\200\237\345\272\246\357\274\232", nullptr));
        label_17->setText(QCoreApplication::translate("DebugWidget", "MIN:111,MAX:222", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("DebugWidget", "\347\212\266\346\200\201", nullptr));
        label_13->setText(QCoreApplication::translate("DebugWidget", "0.0", nullptr));
        label_7->setText(QCoreApplication::translate("DebugWidget", "X\350\275\264\344\275\215\347\275\256\357\274\232", nullptr));
        label_10->setText(QCoreApplication::translate("DebugWidget", "0.0", nullptr));
        label_6->setText(QCoreApplication::translate("DebugWidget", "0.0", nullptr));
        label_11->setText(QCoreApplication::translate("DebugWidget", "0.0", nullptr));
        label_12->setText(QCoreApplication::translate("DebugWidget", "Y\350\275\264\344\275\215\347\275\256\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("DebugWidget", "X\350\275\264\351\200\237\345\272\246\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("DebugWidget", "Y\350\275\264\351\200\237\345\272\246\357\274\232", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("DebugWidget", "\344\274\272\346\234\215\346\216\247\345\210\266", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("DebugWidget", "\346\260\224\347\274\270\346\216\247\345\210\266", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("DebugWidget", "\350\276\223\345\205\245", nullptr));
        label_48->setText(QCoreApplication::translate("DebugWidget", "I0.0", nullptr));
        label_45->setText(QCoreApplication::translate("DebugWidget", "I0.0", nullptr));
        i2_0->setText(QString());
        label_44->setText(QCoreApplication::translate("DebugWidget", "I0.0", nullptr));
        label_47->setText(QCoreApplication::translate("DebugWidget", "I0.0", nullptr));
        label_50->setText(QCoreApplication::translate("DebugWidget", "I0.0", nullptr));
        label_51->setText(QCoreApplication::translate("DebugWidget", "I0.0", nullptr));
        label_52->setText(QCoreApplication::translate("DebugWidget", "I0.0", nullptr));
        label_53->setText(QCoreApplication::translate("DebugWidget", "I0.0", nullptr));
        i2_1->setText(QString());
        i2_2->setText(QString());
        i2_3->setText(QString());
        i2_5->setText(QString());
        label_54->setText(QCoreApplication::translate("DebugWidget", "I0.0", nullptr));
        i2_6->setText(QString());
        i2_4->setText(QString());
        i2_7->setText(QString());
        label_49->setText(QCoreApplication::translate("DebugWidget", "I0.0", nullptr));
        i0_6->setText(QString());
        i1_5->setText(QString());
        i1_6->setText(QString());
        i1_4->setText(QString());
        i1_7->setText(QString());
        i0_7->setText(QString());
        i0_1->setText(QString());
        i0_2->setText(QString());
        i0_3->setText(QString());
        i0_4->setText(QString());
        i0_5->setText(QString());
        label_46->setText(QCoreApplication::translate("DebugWidget", "I0.0", nullptr));
        label_56->setText(QCoreApplication::translate("DebugWidget", "I0.0", nullptr));
        label_57->setText(QCoreApplication::translate("DebugWidget", "I0.0", nullptr));
        label_66->setText(QCoreApplication::translate("DebugWidget", "I0.0", nullptr));
        label_67->setText(QCoreApplication::translate("DebugWidget", "I0.0", nullptr));
        label_68->setText(QCoreApplication::translate("DebugWidget", "I0.0", nullptr));
        label_69->setText(QCoreApplication::translate("DebugWidget", "I0.0", nullptr));
        label_70->setText(QCoreApplication::translate("DebugWidget", "I0.0", nullptr));
        label_72->setText(QCoreApplication::translate("DebugWidget", "I0.0", nullptr));
        label_73->setText(QCoreApplication::translate("DebugWidget", "I0.0", nullptr));
        label_74->setText(QCoreApplication::translate("DebugWidget", "I0.0", nullptr));
        label_75->setText(QCoreApplication::translate("DebugWidget", "I0.0", nullptr));
        label_55->setText(QCoreApplication::translate("DebugWidget", "I0.0", nullptr));
        i0_0->setText(QString());
        i1_2->setText(QString());
        i1_3->setText(QString());
        i1_1->setText(QString());
        i1_0->setText(QString());
        label_71->setText(QCoreApplication::translate("DebugWidget", "I0.0", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("DebugWidget", "\350\276\223\345\207\272", nullptr));
        q2_0->setText(QCoreApplication::translate("DebugWidget", "Q0.0", nullptr));
        q0_0->setText(QCoreApplication::translate("DebugWidget", "Q0.0", nullptr));
        q1_0->setText(QCoreApplication::translate("DebugWidget", "Q0.0", nullptr));
        q0_6->setText(QCoreApplication::translate("DebugWidget", "Q0.0", nullptr));
        q1_6->setText(QCoreApplication::translate("DebugWidget", "Q0.0", nullptr));
        q2_7->setText(QCoreApplication::translate("DebugWidget", "Q0.0", nullptr));
        q1_7->setText(QCoreApplication::translate("DebugWidget", "Q0.0", nullptr));
        q0_1->setText(QCoreApplication::translate("DebugWidget", "Q0.0", nullptr));
        q0_7->setText(QCoreApplication::translate("DebugWidget", "Q0.0", nullptr));
        q0_2->setText(QCoreApplication::translate("DebugWidget", "Q0.0", nullptr));
        q0_3->setText(QCoreApplication::translate("DebugWidget", "Q0.0", nullptr));
        q0_4->setText(QCoreApplication::translate("DebugWidget", "Q0.0", nullptr));
        q0_5->setText(QCoreApplication::translate("DebugWidget", "Q0.0", nullptr));
        q1_1->setText(QCoreApplication::translate("DebugWidget", "Q0.0", nullptr));
        q1_2->setText(QCoreApplication::translate("DebugWidget", "Q0.0", nullptr));
        q1_3->setText(QCoreApplication::translate("DebugWidget", "Q0.0", nullptr));
        q1_4->setText(QCoreApplication::translate("DebugWidget", "Q0.0", nullptr));
        q1_5->setText(QCoreApplication::translate("DebugWidget", "Q0.0", nullptr));
        q2_1->setText(QCoreApplication::translate("DebugWidget", "Q0.0", nullptr));
        q2_2->setText(QCoreApplication::translate("DebugWidget", "Q0.0", nullptr));
        q2_3->setText(QCoreApplication::translate("DebugWidget", "Q0.0", nullptr));
        q2_4->setText(QCoreApplication::translate("DebugWidget", "Q0.0", nullptr));
        q2_5->setText(QCoreApplication::translate("DebugWidget", "Q0.0", nullptr));
        q2_6->setText(QCoreApplication::translate("DebugWidget", "Q0.0", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("DebugWidget", "IO Map", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DebugWidget: public Ui_DebugWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEBUGWIDGET_H
