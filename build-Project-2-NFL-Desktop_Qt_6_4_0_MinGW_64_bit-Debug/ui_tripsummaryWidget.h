/********************************************************************************
** Form generated from reading UI file 'tripsummaryWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRIPSUMMARYWIDGET_H
#define UI_TRIPSUMMARYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TripSummaryWidget
{
public:
    QLabel *stadiumName;

    void setupUi(QWidget *TripSummaryWidget)
    {
        if (TripSummaryWidget->objectName().isEmpty())
            TripSummaryWidget->setObjectName("TripSummaryWidget");
        TripSummaryWidget->resize(640, 480);
        stadiumName = new QLabel(TripSummaryWidget);
        stadiumName->setObjectName("stadiumName");
        stadiumName->setGeometry(QRect(30, 20, 141, 31));
        stadiumName->setTextFormat(Qt::MarkdownText);
        stadiumName->setScaledContents(false);
        stadiumName->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        retranslateUi(TripSummaryWidget);

        QMetaObject::connectSlotsByName(TripSummaryWidget);
    } // setupUi

    void retranslateUi(QWidget *TripSummaryWidget)
    {
        TripSummaryWidget->setWindowTitle(QCoreApplication::translate("TripSummaryWidget", "Form", nullptr));
        stadiumName->setText(QCoreApplication::translate("TripSummaryWidget", "## My Trip", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TripSummaryWidget: public Ui_TripSummaryWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIPSUMMARYWIDGET_H
