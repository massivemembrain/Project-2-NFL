/********************************************************************************
** Form generated from reading UI file 'tripcreateWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRIPCREATEWIDGET_H
#define UI_TRIPCREATEWIDGET_H

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

class Ui_TripCreateWidget
{
public:
    QLabel *label_home;
    QLabel *label_proceed;
    QSpinBox *souvenirQuantity;
    QTableWidget *souvenirTable;
    QDialogButtonBox *proceedButtons;
    QLabel *label_souvenir;
    QLabel *stadiumName;
    QProgressBar *progressBar;
    QLabel *teamName;
    QLabel *totalExpenses;
    QLabel *label_expenses;
    QLabel *label_souvenir_quantity;
    QComboBox *souvenirOptions;

    void setupUi(QWidget *TripCreateWidget)
    {
        if (TripCreateWidget->objectName().isEmpty())
            TripCreateWidget->setObjectName("TripCreateWidget");
        TripCreateWidget->resize(640, 480);
        label_home = new QLabel(TripCreateWidget);
        label_home->setObjectName("label_home");
        label_home->setGeometry(QRect(30, 50, 71, 16));
        label_proceed = new QLabel(TripCreateWidget);
        label_proceed->setObjectName("label_proceed");
        label_proceed->setGeometry(QRect(330, 370, 161, 16));
        souvenirQuantity = new QSpinBox(TripCreateWidget);
        souvenirQuantity->setObjectName("souvenirQuantity");
        souvenirQuantity->setGeometry(QRect(160, 410, 71, 25));
        souvenirQuantity->setFocusPolicy(Qt::WheelFocus);
        souvenirQuantity->setMaximum(999);
        souvenirTable = new QTableWidget(TripCreateWidget);
        souvenirTable->setObjectName("souvenirTable");
        souvenirTable->setGeometry(QRect(20, 110, 241, 301));
        proceedButtons = new QDialogButtonBox(TripCreateWidget);
        proceedButtons->setObjectName("proceedButtons");
        proceedButtons->setGeometry(QRect(280, 410, 341, 32));
        proceedButtons->setOrientation(Qt::Horizontal);
        proceedButtons->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_souvenir = new QLabel(TripCreateWidget);
        label_souvenir->setObjectName("label_souvenir");
        label_souvenir->setGeometry(QRect(20, 90, 61, 16));
        stadiumName = new QLabel(TripCreateWidget);
        stadiumName->setObjectName("stadiumName");
        stadiumName->setGeometry(QRect(30, 20, 141, 31));
        stadiumName->setTextFormat(Qt::MarkdownText);
        stadiumName->setScaledContents(false);
        stadiumName->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        progressBar = new QProgressBar(TripCreateWidget);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(0, 450, 641, 20));
        progressBar->setValue(24);
        progressBar->setTextVisible(false);
        teamName = new QLabel(TripCreateWidget);
        teamName->setObjectName("teamName");
        teamName->setGeometry(QRect(110, 50, 49, 16));
        totalExpenses = new QLabel(TripCreateWidget);
        totalExpenses->setObjectName("totalExpenses");
        totalExpenses->setGeometry(QRect(430, 170, 71, 21));
        label_expenses = new QLabel(TripCreateWidget);
        label_expenses->setObjectName("label_expenses");
        label_expenses->setGeometry(QRect(360, 170, 71, 20));
        label_expenses->setTextFormat(Qt::MarkdownText);
        label_souvenir_quantity = new QLabel(TripCreateWidget);
        label_souvenir_quantity->setObjectName("label_souvenir_quantity");
        label_souvenir_quantity->setGeometry(QRect(140, 410, 16, 21));
        label_souvenir_quantity->setAlignment(Qt::AlignCenter);
        souvenirOptions = new QComboBox(TripCreateWidget);
        souvenirOptions->setObjectName("souvenirOptions");
        souvenirOptions->setGeometry(QRect(20, 410, 121, 24));
        souvenirOptions->setAcceptDrops(false);

        retranslateUi(TripCreateWidget);

        QMetaObject::connectSlotsByName(TripCreateWidget);
    } // setupUi

    void retranslateUi(QWidget *TripCreateWidget)
    {
        TripCreateWidget->setWindowTitle(QCoreApplication::translate("TripCreateWidget", "Form", nullptr));
        label_home->setText(QCoreApplication::translate("TripCreateWidget", "Home of the", nullptr));
        label_proceed->setText(QCoreApplication::translate("TripCreateWidget", "Proceed to next destination?", nullptr));
        souvenirQuantity->setSpecialValueText(QCoreApplication::translate("TripCreateWidget", "Quantity", nullptr));
        label_souvenir->setText(QCoreApplication::translate("TripCreateWidget", "Souvenirs", nullptr));
        stadiumName->setText(QCoreApplication::translate("TripCreateWidget", "## cityName", nullptr));
        teamName->setText(QCoreApplication::translate("TripCreateWidget", "TEAM", nullptr));
        totalExpenses->setText(QCoreApplication::translate("TripCreateWidget", "$ ", nullptr));
        label_expenses->setText(QCoreApplication::translate("TripCreateWidget", "### Expenses:", nullptr));
        label_souvenir_quantity->setText(QCoreApplication::translate("TripCreateWidget", "x", nullptr));
        souvenirOptions->setPlaceholderText(QCoreApplication::translate("TripCreateWidget", "no item selected", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TripCreateWidget: public Ui_TripCreateWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIPCREATEWIDGET_H
