/********************************************************************************
** Form generated from reading UI file 'selectAlgo.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTALGO_H
#define UI_SELECTALGO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_selectAlgo
{
public:
    QTextEdit *textEdit;
    QComboBox *algoBox;
    QPushButton *go;

    void setupUi(QWidget *selectAlgo)
    {
        if (selectAlgo->objectName().isEmpty())
            selectAlgo->setObjectName(QString::fromUtf8("selectAlgo"));
        selectAlgo->resize(400, 300);
        textEdit = new QTextEdit(selectAlgo);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(80, 50, 251, 51));
        algoBox = new QComboBox(selectAlgo);
        algoBox->addItem(QString());
        algoBox->addItem(QString());
        algoBox->addItem(QString());
        algoBox->addItem(QString());
        algoBox->setObjectName(QString::fromUtf8("algoBox"));
        algoBox->setGeometry(QRect(90, 150, 111, 31));
        go = new QPushButton(selectAlgo);
        go->setObjectName(QString::fromUtf8("go"));
        go->setGeometry(QRect(210, 150, 81, 31));

        retranslateUi(selectAlgo);

        QMetaObject::connectSlotsByName(selectAlgo);
    } // setupUi

    void retranslateUi(QWidget *selectAlgo)
    {
        selectAlgo->setWindowTitle(QCoreApplication::translate("selectAlgo", "Form", nullptr));
        textEdit->setHtml(QCoreApplication::translate("selectAlgo", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:700;\">Choose your algorithm here!</span></p></body></html>", nullptr));
        algoBox->setItemText(0, QCoreApplication::translate("selectAlgo", "Dijkstra\342\200\231s", nullptr));
        algoBox->setItemText(1, QCoreApplication::translate("selectAlgo", "Order Specified", nullptr));
        algoBox->setItemText(2, QCoreApplication::translate("selectAlgo", "Visit All", nullptr));
        algoBox->setItemText(3, QCoreApplication::translate("selectAlgo", "Custom trip", nullptr));

        go->setText(QCoreApplication::translate("selectAlgo", "GO!!!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class selectAlgo: public Ui_selectAlgo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTALGO_H
