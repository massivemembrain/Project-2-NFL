/********************************************************************************
** Form generated from reading UI file 'bfs.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BFS_H
#define UI_BFS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BFS
{
public:
    QTextBrowser *textBrowser;

    void setupUi(QWidget *BFS)
    {
        if (BFS->objectName().isEmpty())
            BFS->setObjectName("BFS");
        BFS->resize(691, 471);
        textBrowser = new QTextBrowser(BFS);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(50, 40, 611, 391));

        retranslateUi(BFS);

        QMetaObject::connectSlotsByName(BFS);
    } // setupUi

    void retranslateUi(QWidget *BFS)
    {
        BFS->setWindowTitle(QCoreApplication::translate("BFS", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BFS: public Ui_BFS {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BFS_H
