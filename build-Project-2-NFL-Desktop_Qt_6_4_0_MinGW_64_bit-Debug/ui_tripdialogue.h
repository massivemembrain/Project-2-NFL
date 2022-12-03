/********************************************************************************
** Form generated from reading UI file 'tripdialogue.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRIPDIALOGUE_H
#define UI_TRIPDIALOGUE_H

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

class Ui_TripDialogue
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

    void setupUi(QDialog *TripDialogue)
    {
        if (TripDialogue->objectName().isEmpty())
            TripDialogue->setObjectName("TripDialogue");
        TripDialogue->resize(527, 327);
        TripDialogue->setSizeGripEnabled(false);
        proceedButtons = new QDialogButtonBox(TripDialogue);
        proceedButtons->setObjectName("proceedButtons");
        proceedButtons->setGeometry(QRect(160, 260, 341, 32));
        proceedButtons->setOrientation(Qt::Horizontal);
        proceedButtons->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_proceed = new QLabel(TripDialogue);
        label_proceed->setObjectName("label_proceed");
        label_proceed->setGeometry(QRect(340, 240, 161, 16));
        progressBar = new QProgressBar(TripDialogue);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(0, 310, 531, 20));
        progressBar->setValue(24);
        progressBar->setTextVisible(false);
        stadiumName = new QLabel(TripDialogue);
        stadiumName->setObjectName("stadiumName");
        stadiumName->setGeometry(QRect(40, 20, 141, 31));
        stadiumName->setTextFormat(Qt::MarkdownText);
        stadiumName->setScaledContents(false);
        stadiumName->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_home = new QLabel(TripDialogue);
        label_home->setObjectName("label_home");
        label_home->setGeometry(QRect(40, 50, 71, 16));
        teamName = new QLabel(TripDialogue);
        teamName->setObjectName("teamName");
        teamName->setGeometry(QRect(120, 50, 49, 16));
        souvenirTable = new QTableWidget(TripDialogue);
        souvenirTable->setObjectName("souvenirTable");
        souvenirTable->setGeometry(QRect(20, 110, 241, 151));
        label_souvenir = new QLabel(TripDialogue);
        label_souvenir->setObjectName("label_souvenir");
        label_souvenir->setGeometry(QRect(20, 90, 61, 16));
        label_expenses = new QLabel(TripDialogue);
        label_expenses->setObjectName("label_expenses");
        label_expenses->setGeometry(QRect(370, 170, 71, 20));
        label_expenses->setTextFormat(Qt::MarkdownText);
        totalExpenses = new QLabel(TripDialogue);
        totalExpenses->setObjectName("totalExpenses");
        totalExpenses->setGeometry(QRect(440, 170, 71, 21));
        souvenirOptions = new QComboBox(TripDialogue);
        souvenirOptions->setObjectName("souvenirOptions");
        souvenirOptions->setGeometry(QRect(20, 260, 121, 24));
        souvenirOptions->setAcceptDrops(false);
        label_souvenir_quantity = new QLabel(TripDialogue);
        label_souvenir_quantity->setObjectName("label_souvenir_quantity");
        label_souvenir_quantity->setGeometry(QRect(140, 260, 16, 21));
        label_souvenir_quantity->setAlignment(Qt::AlignCenter);
        souvenirQuantity = new QSpinBox(TripDialogue);
        souvenirQuantity->setObjectName("souvenirQuantity");
        souvenirQuantity->setGeometry(QRect(160, 260, 71, 25));
        souvenirQuantity->setFocusPolicy(Qt::WheelFocus);
        souvenirQuantity->setMaximum(999);

        retranslateUi(TripDialogue);
        QObject::connect(proceedButtons, &QDialogButtonBox::accepted, TripDialogue, qOverload<>(&QDialog::accept));
        QObject::connect(proceedButtons, &QDialogButtonBox::rejected, TripDialogue, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(TripDialogue);
    } // setupUi

    void retranslateUi(QDialog *TripDialogue)
    {
        TripDialogue->setWindowTitle(QCoreApplication::translate("TripDialogue", "Dialog", nullptr));
        label_proceed->setText(QCoreApplication::translate("TripDialogue", "Proceed to next destination?", nullptr));
        stadiumName->setText(QCoreApplication::translate("TripDialogue", "## cityName", nullptr));
        label_home->setText(QCoreApplication::translate("TripDialogue", "Home of the", nullptr));
        teamName->setText(QCoreApplication::translate("TripDialogue", "TextLabel", nullptr));
        label_souvenir->setText(QCoreApplication::translate("TripDialogue", "Souvenirs", nullptr));
        label_expenses->setText(QCoreApplication::translate("TripDialogue", "### Expenses:", nullptr));
        totalExpenses->setText(QCoreApplication::translate("TripDialogue", "$ ", nullptr));
        souvenirOptions->setPlaceholderText(QCoreApplication::translate("TripDialogue", "no item selected", nullptr));
        label_souvenir_quantity->setText(QCoreApplication::translate("TripDialogue", "x", nullptr));
        souvenirQuantity->setSpecialValueText(QCoreApplication::translate("TripDialogue", "Quantity", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TripDialogue: public Ui_TripDialogue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIPDIALOGUE_H
