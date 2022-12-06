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
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TripSummaryWidget
{
public:
    QLabel *label_title;
    QLabel *totalExpensePlan;
    QTextBrowser *tripReceipt;
    QLabel *label_plan_total;
    QTextBrowser *tripSummary;
    QLabel *label_plan_summary;
    QLabel *label_souvenir;

    void setupUi(QWidget *TripSummaryWidget)
    {
        if (TripSummaryWidget->objectName().isEmpty())
            TripSummaryWidget->setObjectName("TripSummaryWidget");
        TripSummaryWidget->resize(640, 480);
        label_title = new QLabel(TripSummaryWidget);
        label_title->setObjectName("label_title");
        label_title->setGeometry(QRect(30, 20, 141, 31));
        label_title->setTextFormat(Qt::MarkdownText);
        label_title->setScaledContents(false);
        label_title->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        totalExpensePlan = new QLabel(TripSummaryWidget);
        totalExpensePlan->setObjectName("totalExpensePlan");
        totalExpensePlan->setGeometry(QRect(410, 330, 71, 21));
        tripReceipt = new QTextBrowser(TripSummaryWidget);
        tripReceipt->setObjectName("tripReceipt");
        tripReceipt->setGeometry(QRect(300, 110, 256, 211));
        label_plan_total = new QLabel(TripSummaryWidget);
        label_plan_total->setObjectName("label_plan_total");
        label_plan_total->setGeometry(QRect(300, 330, 111, 20));
        label_plan_total->setTextFormat(Qt::MarkdownText);
        tripSummary = new QTextBrowser(TripSummaryWidget);
        tripSummary->setObjectName("tripSummary");
        tripSummary->setGeometry(QRect(20, 110, 241, 301));
        label_plan_summary = new QLabel(TripSummaryWidget);
        label_plan_summary->setObjectName("label_plan_summary");
        label_plan_summary->setGeometry(QRect(30, 90, 111, 20));
        label_plan_summary->setTextFormat(Qt::MarkdownText);
        label_souvenir = new QLabel(TripSummaryWidget);
        label_souvenir->setObjectName("label_souvenir");
        label_souvenir->setGeometry(QRect(310, 90, 81, 16));
        label_souvenir->setTextFormat(Qt::MarkdownText);

        retranslateUi(TripSummaryWidget);

        QMetaObject::connectSlotsByName(TripSummaryWidget);
    } // setupUi

    void retranslateUi(QWidget *TripSummaryWidget)
    {
        TripSummaryWidget->setWindowTitle(QCoreApplication::translate("TripSummaryWidget", "Form", nullptr));
        label_title->setText(QCoreApplication::translate("TripSummaryWidget", "## My Trip", nullptr));
        totalExpensePlan->setText(QCoreApplication::translate("TripSummaryWidget", "$ ", nullptr));
        label_plan_total->setText(QCoreApplication::translate("TripSummaryWidget", "### Plan Expenses:", nullptr));
        label_plan_summary->setText(QCoreApplication::translate("TripSummaryWidget", "### Plan Summary", nullptr));
        label_souvenir->setText(QCoreApplication::translate("TripSummaryWidget", "### My Receipt", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TripSummaryWidget: public Ui_TripSummaryWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIPSUMMARYWIDGET_H
