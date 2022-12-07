/********************************************************************************
** Form generated from reading UI file 'bfs.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BFS_H
#define UI_BFS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BFS
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *selectTeamButton;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *BFS)
    {
        if (BFS->objectName().isEmpty())
            BFS->setObjectName(QString::fromUtf8("BFS"));
        BFS->resize(920, 600);
        verticalLayoutWidget = new QWidget(BFS);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(50, 20, 611, 431));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        selectTeamButton = new QPushButton(verticalLayoutWidget);
        selectTeamButton->setObjectName(QString::fromUtf8("selectTeamButton"));

        horizontalLayout->addWidget(selectTeamButton);


        verticalLayout->addLayout(horizontalLayout);

        textBrowser = new QTextBrowser(verticalLayoutWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);


        retranslateUi(BFS);

        QMetaObject::connectSlotsByName(BFS);
    } // setupUi

    void retranslateUi(QWidget *BFS)
    {
        BFS->setWindowTitle(QCoreApplication::translate("BFS", "Form", nullptr));
        selectTeamButton->setText(QCoreApplication::translate("BFS", "B F S ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BFS: public Ui_BFS {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BFS_H
