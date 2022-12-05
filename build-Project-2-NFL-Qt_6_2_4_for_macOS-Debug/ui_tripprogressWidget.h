/********************************************************************************
** Form generated from reading UI file 'tripprogressWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRIPPROGRESSWIDGET_H
#define UI_TRIPPROGRESSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TripProgressWidget
{
public:
    QLabel *teamName;
    QTableWidget *souvenirTable;
    QSpinBox *souvenirQuantity;
    QLabel *label_proceed;
    QComboBox *souvenirOptions;
    QDialogButtonBox *proceedButtons;
    QLabel *totalExpenses;
    QLabel *label_souvenir;
    QLabel *label_home;
    QLabel *label_souvenir_quantity;
    QLabel *label_expenses;
    QLabel *stadiumName;
    QProgressBar *progressBar;

    void setupUi(QWidget *TripProgressWidget)
    {
        if (TripProgressWidget->objectName().isEmpty())
            TripProgressWidget->setObjectName(QString::fromUtf8("TripProgressWidget"));
        TripProgressWidget->resize(640, 480);
        teamName = new QLabel(TripProgressWidget);
        teamName->setObjectName(QString::fromUtf8("teamName"));
        teamName->setGeometry(QRect(110, 50, 49, 16));
        souvenirTable = new QTableWidget(TripProgressWidget);
        souvenirTable->setObjectName(QString::fromUtf8("souvenirTable"));
        souvenirTable->setGeometry(QRect(20, 110, 241, 301));
        souvenirQuantity = new QSpinBox(TripProgressWidget);
        souvenirQuantity->setObjectName(QString::fromUtf8("souvenirQuantity"));
        souvenirQuantity->setGeometry(QRect(160, 410, 71, 25));
        souvenirQuantity->setFocusPolicy(Qt::WheelFocus);
        souvenirQuantity->setMaximum(999);
        label_proceed = new QLabel(TripProgressWidget);
        label_proceed->setObjectName(QString::fromUtf8("label_proceed"));
        label_proceed->setGeometry(QRect(330, 370, 161, 16));
        souvenirOptions = new QComboBox(TripProgressWidget);
        souvenirOptions->setObjectName(QString::fromUtf8("souvenirOptions"));
        souvenirOptions->setGeometry(QRect(20, 410, 121, 24));
        souvenirOptions->setAcceptDrops(false);
        proceedButtons = new QDialogButtonBox(TripProgressWidget);
        proceedButtons->setObjectName(QString::fromUtf8("proceedButtons"));
        proceedButtons->setGeometry(QRect(280, 410, 341, 32));
        proceedButtons->setOrientation(Qt::Horizontal);
        proceedButtons->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        totalExpenses = new QLabel(TripProgressWidget);
        totalExpenses->setObjectName(QString::fromUtf8("totalExpenses"));
        totalExpenses->setGeometry(QRect(430, 170, 71, 21));
        label_souvenir = new QLabel(TripProgressWidget);
        label_souvenir->setObjectName(QString::fromUtf8("label_souvenir"));
        label_souvenir->setGeometry(QRect(20, 90, 61, 16));
        label_home = new QLabel(TripProgressWidget);
        label_home->setObjectName(QString::fromUtf8("label_home"));
        label_home->setGeometry(QRect(30, 50, 71, 16));
        label_souvenir_quantity = new QLabel(TripProgressWidget);
        label_souvenir_quantity->setObjectName(QString::fromUtf8("label_souvenir_quantity"));
        label_souvenir_quantity->setGeometry(QRect(140, 410, 16, 21));
        label_souvenir_quantity->setAlignment(Qt::AlignCenter);
        label_expenses = new QLabel(TripProgressWidget);
        label_expenses->setObjectName(QString::fromUtf8("label_expenses"));
        label_expenses->setGeometry(QRect(360, 170, 71, 20));
        label_expenses->setTextFormat(Qt::MarkdownText);
        stadiumName = new QLabel(TripProgressWidget);
        stadiumName->setObjectName(QString::fromUtf8("stadiumName"));
        stadiumName->setGeometry(QRect(30, 20, 141, 31));
        stadiumName->setTextFormat(Qt::MarkdownText);
        stadiumName->setScaledContents(false);
        stadiumName->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        progressBar = new QProgressBar(TripProgressWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(0, 450, 641, 20));
        progressBar->setValue(24);
        progressBar->setTextVisible(false);

        retranslateUi(TripProgressWidget);

        QMetaObject::connectSlotsByName(TripProgressWidget);
    } // setupUi

    void retranslateUi(QWidget *TripProgressWidget)
    {
        TripProgressWidget->setWindowTitle(QCoreApplication::translate("TripProgressWidget", "Form", nullptr));
        teamName->setText(QCoreApplication::translate("TripProgressWidget", "TEAM", nullptr));
        souvenirQuantity->setSpecialValueText(QCoreApplication::translate("TripProgressWidget", "Quantity", nullptr));
        label_proceed->setText(QCoreApplication::translate("TripProgressWidget", "Proceed to next destination?", nullptr));
        souvenirOptions->setPlaceholderText(QCoreApplication::translate("TripProgressWidget", "no item selected", nullptr));
        totalExpenses->setText(QCoreApplication::translate("TripProgressWidget", "$ ", nullptr));
        label_souvenir->setText(QCoreApplication::translate("TripProgressWidget", "Souvenirs", nullptr));
        label_home->setText(QCoreApplication::translate("TripProgressWidget", "Home of the", nullptr));
        label_souvenir_quantity->setText(QCoreApplication::translate("TripProgressWidget", "x", nullptr));
        label_expenses->setText(QCoreApplication::translate("TripProgressWidget", "### Expenses:", nullptr));
        stadiumName->setText(QCoreApplication::translate("TripProgressWidget", "## cityName", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TripProgressWidget: public Ui_TripProgressWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIPPROGRESSWIDGET_H
