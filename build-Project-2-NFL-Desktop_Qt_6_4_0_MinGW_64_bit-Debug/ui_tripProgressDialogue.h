/********************************************************************************
** Form generated from reading UI file 'tripProgressDialogue.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRIPPROGRESSDIALOGUE_H
#define UI_TRIPPROGRESSDIALOGUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_TripProgressDialogue
{
public:
    QDialogButtonBox *proceedButtons;
    QLabel *label_proceed;
    QProgressBar *progressBar;
    QLabel *stadiumName;
    QLabel *label_home;
    QLabel *teamName;
    QTableWidget *souvenirTable;
    QLabel *label_souvenir;
    QLabel *label_expenses;
    QLabel *totalExpenses;
    QComboBox *souvenirOptions;
    QLabel *label_souvenir_quantity;
    QSpinBox *souvenirQuantity;

    void setupUi(QDialog *TripProgressDialogue)
    {
        if (TripProgressDialogue->objectName().isEmpty())
            TripProgressDialogue->setObjectName("TripProgressDialogue");
        TripProgressDialogue->resize(527, 327);
        TripProgressDialogue->setSizeGripEnabled(false);
        proceedButtons = new QDialogButtonBox(TripProgressDialogue);
        proceedButtons->setObjectName("proceedButtons");
        proceedButtons->setGeometry(QRect(160, 260, 341, 32));
        proceedButtons->setOrientation(Qt::Horizontal);
        proceedButtons->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_proceed = new QLabel(TripProgressDialogue);
        label_proceed->setObjectName("label_proceed");
        label_proceed->setGeometry(QRect(340, 240, 161, 16));
        progressBar = new QProgressBar(TripProgressDialogue);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(0, 310, 531, 20));
        progressBar->setValue(24);
        progressBar->setTextVisible(false);
        stadiumName = new QLabel(TripProgressDialogue);
        stadiumName->setObjectName("stadiumName");
        stadiumName->setGeometry(QRect(40, 20, 141, 31));
        stadiumName->setTextFormat(Qt::MarkdownText);
        stadiumName->setScaledContents(false);
        stadiumName->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_home = new QLabel(TripProgressDialogue);
        label_home->setObjectName("label_home");
        label_home->setGeometry(QRect(40, 50, 71, 16));
        teamName = new QLabel(TripProgressDialogue);
        teamName->setObjectName("teamName");
        teamName->setGeometry(QRect(120, 50, 49, 16));
        souvenirTable = new QTableWidget(TripProgressDialogue);
        souvenirTable->setObjectName("souvenirTable");
        souvenirTable->setGeometry(QRect(20, 110, 241, 151));
        label_souvenir = new QLabel(TripProgressDialogue);
        label_souvenir->setObjectName("label_souvenir");
        label_souvenir->setGeometry(QRect(20, 90, 61, 16));
        label_expenses = new QLabel(TripProgressDialogue);
        label_expenses->setObjectName("label_expenses");
        label_expenses->setGeometry(QRect(370, 170, 71, 20));
        label_expenses->setTextFormat(Qt::MarkdownText);
        totalExpenses = new QLabel(TripProgressDialogue);
        totalExpenses->setObjectName("totalExpenses");
        totalExpenses->setGeometry(QRect(440, 170, 71, 21));
        souvenirOptions = new QComboBox(TripProgressDialogue);
        souvenirOptions->setObjectName("souvenirOptions");
        souvenirOptions->setGeometry(QRect(20, 260, 121, 24));
        souvenirOptions->setAcceptDrops(false);
        label_souvenir_quantity = new QLabel(TripProgressDialogue);
        label_souvenir_quantity->setObjectName("label_souvenir_quantity");
        label_souvenir_quantity->setGeometry(QRect(140, 260, 16, 21));
        label_souvenir_quantity->setAlignment(Qt::AlignCenter);
        souvenirQuantity = new QSpinBox(TripProgressDialogue);
        souvenirQuantity->setObjectName("souvenirQuantity");
        souvenirQuantity->setGeometry(QRect(160, 260, 71, 25));
        souvenirQuantity->setFocusPolicy(Qt::WheelFocus);
        souvenirQuantity->setMaximum(999);

        retranslateUi(TripProgressDialogue);
        QObject::connect(proceedButtons, &QDialogButtonBox::accepted, TripProgressDialogue, qOverload<>(&QDialog::accept));
        QObject::connect(proceedButtons, &QDialogButtonBox::rejected, TripProgressDialogue, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(TripProgressDialogue);
    } // setupUi

    void retranslateUi(QDialog *TripProgressDialogue)
    {
        TripProgressDialogue->setWindowTitle(QCoreApplication::translate("TripProgressDialogue", "Dialog", nullptr));
        label_proceed->setText(QCoreApplication::translate("TripProgressDialogue", "Proceed to next destination?", nullptr));
        stadiumName->setText(QCoreApplication::translate("TripProgressDialogue", "## cityName", nullptr));
        label_home->setText(QCoreApplication::translate("TripProgressDialogue", "Home of the", nullptr));
        teamName->setText(QCoreApplication::translate("TripProgressDialogue", "TextLabel", nullptr));
        label_souvenir->setText(QCoreApplication::translate("TripProgressDialogue", "Souvenirs", nullptr));
        label_expenses->setText(QCoreApplication::translate("TripProgressDialogue", "### Expenses:", nullptr));
        totalExpenses->setText(QCoreApplication::translate("TripProgressDialogue", "$ ", nullptr));
        souvenirOptions->setPlaceholderText(QCoreApplication::translate("TripProgressDialogue", "no item selected", nullptr));
        label_souvenir_quantity->setText(QCoreApplication::translate("TripProgressDialogue", "x", nullptr));
        souvenirQuantity->setSpecialValueText(QCoreApplication::translate("TripProgressDialogue", "Quantity", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TripProgressDialogue: public Ui_TripProgressDialogue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIPPROGRESSDIALOGUE_H
