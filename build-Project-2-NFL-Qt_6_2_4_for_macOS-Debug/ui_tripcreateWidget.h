/********************************************************************************
** Form generated from reading UI file 'tripcreateWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
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
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TripCreateWidget
{
public:
    QLabel *label_description;
    QLabel *label_proceed;
    QTableWidget *teamTable;
    QDialogButtonBox *proceedButtons;
    QLabel *label_team_available;
    QLabel *planName;
    QProgressBar *decor_progress_bar;
    QComboBox *planType;
    QTextBrowser *teamSelection;
    QLabel *label_team_selected;
    QTableView *tableView;

    void setupUi(QWidget *TripCreateWidget)
    {
        if (TripCreateWidget->objectName().isEmpty())
            TripCreateWidget->setObjectName(QString::fromUtf8("TripCreateWidget"));
        TripCreateWidget->resize(1102, 788);
        label_description = new QLabel(TripCreateWidget);
        label_description->setObjectName(QString::fromUtf8("label_description"));
        label_description->setGeometry(QRect(30, 50, 181, 16));
        label_proceed = new QLabel(TripCreateWidget);
        label_proceed->setObjectName(QString::fromUtf8("label_proceed"));
        label_proceed->setGeometry(QRect(410, 380, 181, 16));
        teamTable = new QTableWidget(TripCreateWidget);
        teamTable->setObjectName(QString::fromUtf8("teamTable"));
        teamTable->setGeometry(QRect(20, 110, 261, 311));
        proceedButtons = new QDialogButtonBox(TripCreateWidget);
        proceedButtons->setObjectName(QString::fromUtf8("proceedButtons"));
        proceedButtons->setGeometry(QRect(280, 410, 341, 32));
        proceedButtons->setOrientation(Qt::Horizontal);
        proceedButtons->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_team_available = new QLabel(TripCreateWidget);
        label_team_available->setObjectName(QString::fromUtf8("label_team_available"));
        label_team_available->setGeometry(QRect(30, 90, 111, 16));
        label_team_available->setTextFormat(Qt::MarkdownText);
        planName = new QLabel(TripCreateWidget);
        planName->setObjectName(QString::fromUtf8("planName"));
        planName->setGeometry(QRect(30, 20, 141, 31));
        planName->setTextFormat(Qt::MarkdownText);
        planName->setScaledContents(false);
        planName->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        decor_progress_bar = new QProgressBar(TripCreateWidget);
        decor_progress_bar->setObjectName(QString::fromUtf8("decor_progress_bar"));
        decor_progress_bar->setGeometry(QRect(0, 450, 641, 20));
        decor_progress_bar->setValue(0);
        decor_progress_bar->setTextVisible(false);
        planType = new QComboBox(TripCreateWidget);
        planType->setObjectName(QString::fromUtf8("planType"));
        planType->setGeometry(QRect(20, 410, 121, 24));
        planType->setAcceptDrops(false);
        teamSelection = new QTextBrowser(TripCreateWidget);
        teamSelection->setObjectName(QString::fromUtf8("teamSelection"));
        teamSelection->setGeometry(QRect(300, 110, 256, 211));
        label_team_selected = new QLabel(TripCreateWidget);
        label_team_selected->setObjectName(QString::fromUtf8("label_team_selected"));
        label_team_selected->setGeometry(QRect(310, 90, 111, 16));
        label_team_selected->setTextFormat(Qt::MarkdownText);
        tableView = new QTableView(TripCreateWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(600, 40, 381, 321));

        retranslateUi(TripCreateWidget);

        QMetaObject::connectSlotsByName(TripCreateWidget);
    } // setupUi

    void retranslateUi(QWidget *TripCreateWidget)
    {
        TripCreateWidget->setWindowTitle(QCoreApplication::translate("TripCreateWidget", "Form", nullptr));
        label_description->setText(QCoreApplication::translate("TripCreateWidget", "Your dream vacation starts here.", nullptr));
        label_proceed->setText(QCoreApplication::translate("TripCreateWidget", "Proceed to your dream vacation?", nullptr));
        label_team_available->setText(QCoreApplication::translate("TripCreateWidget", "### Available Teams", nullptr));
        planName->setText(QCoreApplication::translate("TripCreateWidget", "## My Plan", nullptr));
        planType->setPlaceholderText(QCoreApplication::translate("TripCreateWidget", "no item selected", nullptr));
        label_team_selected->setText(QCoreApplication::translate("TripCreateWidget", "### Selected Teams", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TripCreateWidget: public Ui_TripCreateWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIPCREATEWIDGET_H
