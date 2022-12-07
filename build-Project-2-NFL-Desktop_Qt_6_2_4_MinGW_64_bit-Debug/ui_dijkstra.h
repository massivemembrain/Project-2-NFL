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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dijkstra
{
public:
    QTextBrowser *textBrowser;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox_start;
    QComboBox *comboBox_end;
    QPushButton *pushButton_find;

    void setupUi(QWidget *Dijkstra)
    {
        if (Dijkstra->objectName().isEmpty())
            Dijkstra->setObjectName(QString::fromUtf8("Dijkstra"));
        Dijkstra->resize(834, 388);
        textBrowser = new QTextBrowser(Dijkstra);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(260, 120, 256, 192));
        horizontalLayoutWidget = new QWidget(Dijkstra);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(190, 20, 391, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        comboBox_start = new QComboBox(horizontalLayoutWidget);
        comboBox_start->setObjectName(QString::fromUtf8("comboBox_start"));

        horizontalLayout->addWidget(comboBox_start);

        comboBox_end = new QComboBox(horizontalLayoutWidget);
        comboBox_end->setObjectName(QString::fromUtf8("comboBox_end"));

        horizontalLayout->addWidget(comboBox_end);

        pushButton_find = new QPushButton(horizontalLayoutWidget);
        pushButton_find->setObjectName(QString::fromUtf8("pushButton_find"));

        horizontalLayout->addWidget(pushButton_find);


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
