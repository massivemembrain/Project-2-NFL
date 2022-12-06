/********************************************************************************
** Form generated from reading UI file 'dfs.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DFS_H
#define UI_DFS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DFS
{
public:
    QTextBrowser *textBrowser;
    QPushButton *pushButton;

    void setupUi(QWidget *DFS)
    {
        if (DFS->objectName().isEmpty())
            DFS->setObjectName("DFS");
        DFS->resize(678, 684);
        textBrowser = new QTextBrowser(DFS);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(20, 60, 541, 601));
        pushButton = new QPushButton(DFS);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 20, 141, 32));

        retranslateUi(DFS);

        QMetaObject::connectSlotsByName(DFS);
    } // setupUi

    void retranslateUi(QWidget *DFS)
    {
        DFS->setWindowTitle(QCoreApplication::translate("DFS", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("DFS", "display DFS", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DFS: public Ui_DFS {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DFS_H
