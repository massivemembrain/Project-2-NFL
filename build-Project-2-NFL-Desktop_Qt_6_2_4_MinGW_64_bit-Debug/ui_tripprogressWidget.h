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
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TripProgressWidget
{
public:
    QLabel *label_souvenir;
    QLabel *label_receipt;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTableView *souvenirTable;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox;
    QComboBox *comboBox_souvenirs;
    QSpinBox *spinBox_quantity;
    QPushButton *pushButton_buy;
    QPushButton *pushButton_done;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QTextBrowser *tripReceipt;
    QPushButton *pushButton_total;

    void setupUi(QWidget *TripProgressWidget)
    {
        if (TripProgressWidget->objectName().isEmpty())
            TripProgressWidget->setObjectName(QString::fromUtf8("TripProgressWidget"));
        TripProgressWidget->resize(853, 542);
        label_souvenir = new QLabel(TripProgressWidget);
        label_souvenir->setObjectName(QString::fromUtf8("label_souvenir"));
        label_souvenir->setGeometry(QRect(30, 90, 71, 16));
        label_souvenir->setTextFormat(Qt::MarkdownText);
        label_receipt = new QLabel(TripProgressWidget);
        label_receipt->setObjectName(QString::fromUtf8("label_receipt"));
        label_receipt->setGeometry(QRect(460, 90, 81, 16));
        label_receipt->setTextFormat(Qt::MarkdownText);
        verticalLayoutWidget = new QWidget(TripProgressWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 110, 401, 291));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        souvenirTable = new QTableView(verticalLayoutWidget);
        souvenirTable->setObjectName(QString::fromUtf8("souvenirTable"));

        verticalLayout->addWidget(souvenirTable);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        comboBox = new QComboBox(verticalLayoutWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);

        comboBox_souvenirs = new QComboBox(verticalLayoutWidget);
        comboBox_souvenirs->setObjectName(QString::fromUtf8("comboBox_souvenirs"));
        comboBox_souvenirs->setAcceptDrops(false);

        horizontalLayout->addWidget(comboBox_souvenirs);

        spinBox_quantity = new QSpinBox(verticalLayoutWidget);
        spinBox_quantity->setObjectName(QString::fromUtf8("spinBox_quantity"));

        horizontalLayout->addWidget(spinBox_quantity);

        pushButton_buy = new QPushButton(verticalLayoutWidget);
        pushButton_buy->setObjectName(QString::fromUtf8("pushButton_buy"));

        horizontalLayout->addWidget(pushButton_buy);


        verticalLayout->addLayout(horizontalLayout);

        pushButton_done = new QPushButton(TripProgressWidget);
        pushButton_done->setObjectName(QString::fromUtf8("pushButton_done"));
        pushButton_done->setGeometry(QRect(650, 430, 75, 24));
        verticalLayoutWidget_2 = new QWidget(TripProgressWidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(460, 110, 271, 291));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        tripReceipt = new QTextBrowser(verticalLayoutWidget_2);
        tripReceipt->setObjectName(QString::fromUtf8("tripReceipt"));

        verticalLayout_2->addWidget(tripReceipt);

        pushButton_total = new QPushButton(verticalLayoutWidget_2);
        pushButton_total->setObjectName(QString::fromUtf8("pushButton_total"));

        verticalLayout_2->addWidget(pushButton_total);


        retranslateUi(TripProgressWidget);

        QMetaObject::connectSlotsByName(TripProgressWidget);
    } // setupUi

    void retranslateUi(QWidget *TripProgressWidget)
    {
        TripProgressWidget->setWindowTitle(QCoreApplication::translate("TripProgressWidget", "Form", nullptr));
        label_souvenir->setText(QCoreApplication::translate("TripProgressWidget", "### Souvenirs", nullptr));
        label_receipt->setText(QCoreApplication::translate("TripProgressWidget", "### My Receipt", nullptr));
        comboBox_souvenirs->setPlaceholderText(QCoreApplication::translate("TripProgressWidget", "no item selected", nullptr));
        pushButton_buy->setText(QCoreApplication::translate("TripProgressWidget", "buy", nullptr));
        pushButton_done->setText(QCoreApplication::translate("TripProgressWidget", "Done", nullptr));
        pushButton_total->setText(QCoreApplication::translate("TripProgressWidget", "Display Total", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TripProgressWidget: public Ui_TripProgressWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIPPROGRESSWIDGET_H
