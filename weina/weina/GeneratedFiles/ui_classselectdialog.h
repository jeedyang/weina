/********************************************************************************
** Form generated from reading UI file 'classselectdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLASSSELECTDIALOG_H
#define UI_CLASSSELECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ClassSelectDialog
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_class0;
    QPushButton *pushButton_class1;
    QPushButton *pushButton_class2;
    QPushButton *pushButton_class3;

    void setupUi(QDialog *ClassSelectDialog)
    {
        if (ClassSelectDialog->objectName().isEmpty())
            ClassSelectDialog->setObjectName(QString::fromUtf8("ClassSelectDialog"));
        ClassSelectDialog->resize(334, 283);
        verticalLayout = new QVBoxLayout(ClassSelectDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_class0 = new QPushButton(ClassSelectDialog);
        pushButton_class0->setObjectName(QString::fromUtf8("pushButton_class0"));
        pushButton_class0->setMinimumSize(QSize(0, 60));

        verticalLayout->addWidget(pushButton_class0);

        pushButton_class1 = new QPushButton(ClassSelectDialog);
        pushButton_class1->setObjectName(QString::fromUtf8("pushButton_class1"));
        pushButton_class1->setMinimumSize(QSize(0, 60));

        verticalLayout->addWidget(pushButton_class1);

        pushButton_class2 = new QPushButton(ClassSelectDialog);
        pushButton_class2->setObjectName(QString::fromUtf8("pushButton_class2"));
        pushButton_class2->setMinimumSize(QSize(0, 60));

        verticalLayout->addWidget(pushButton_class2);

        pushButton_class3 = new QPushButton(ClassSelectDialog);
        pushButton_class3->setObjectName(QString::fromUtf8("pushButton_class3"));
        pushButton_class3->setMinimumSize(QSize(0, 60));

        verticalLayout->addWidget(pushButton_class3);


        retranslateUi(ClassSelectDialog);

        QMetaObject::connectSlotsByName(ClassSelectDialog);
    } // setupUi

    void retranslateUi(QDialog *ClassSelectDialog)
    {
        ClassSelectDialog->setWindowTitle(QApplication::translate("ClassSelectDialog", "ClassSelectDialog", nullptr));
        pushButton_class0->setText(QApplication::translate("ClassSelectDialog", "0\345\217\267\346\235\277", nullptr));
        pushButton_class1->setText(QApplication::translate("ClassSelectDialog", "1\345\217\267\346\235\277", nullptr));
        pushButton_class2->setText(QApplication::translate("ClassSelectDialog", "2\345\217\267\346\235\277", nullptr));
        pushButton_class3->setText(QApplication::translate("ClassSelectDialog", "3\345\217\267\346\235\277", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClassSelectDialog: public Ui_ClassSelectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLASSSELECTDIALOG_H
