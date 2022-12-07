/********************************************************************************
** Form generated from reading UI file 'dijkstra.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIJKSTRA_H
#define UI_DIJKSTRA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dijkstra
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox_start;
    QComboBox *comboBox_end;
    QPushButton *pushButton_find;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *Dijkstra)
    {
        if (Dijkstra->objectName().isEmpty())
            Dijkstra->setObjectName(QString::fromUtf8("Dijkstra"));
        Dijkstra->resize(834, 388);
        verticalLayoutWidget = new QWidget(Dijkstra);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(140, 30, 521, 301));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        comboBox_start = new QComboBox(verticalLayoutWidget);
        comboBox_start->setObjectName(QString::fromUtf8("comboBox_start"));

        horizontalLayout->addWidget(comboBox_start);

        comboBox_end = new QComboBox(verticalLayoutWidget);
        comboBox_end->setObjectName(QString::fromUtf8("comboBox_end"));

        horizontalLayout->addWidget(comboBox_end);

        pushButton_find = new QPushButton(verticalLayoutWidget);
        pushButton_find->setObjectName(QString::fromUtf8("pushButton_find"));

        horizontalLayout->addWidget(pushButton_find);


        verticalLayout->addLayout(horizontalLayout);

        textBrowser = new QTextBrowser(verticalLayoutWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);


        retranslateUi(Dijkstra);

        QMetaObject::connectSlotsByName(Dijkstra);
    } // setupUi

    void retranslateUi(QWidget *Dijkstra)
    {
        Dijkstra->setWindowTitle(QCoreApplication::translate("Dijkstra", "Form", nullptr));
        pushButton_find->setText(QCoreApplication::translate("Dijkstra", "Find", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dijkstra: public Ui_Dijkstra {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIJKSTRA_H
