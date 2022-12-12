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
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TripCreateWidget
{
public:
    QLabel *label_description;
    QLabel *label_team_available;
    QLabel *planName;
    QProgressBar *decor_progress_bar;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_team_selected;
    QTextBrowser *textBrowser_team;
    QPushButton *pushButton_done;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox_team;
    QPushButton *pushButton_select;
    QComboBox *comboBox_algorithm;
    QTableView *teamTable;

    void setupUi(QWidget *TripCreateWidget)
    {
        if (TripCreateWidget->objectName().isEmpty())
            TripCreateWidget->setObjectName(QString::fromUtf8("TripCreateWidget"));
        TripCreateWidget->resize(1102, 788);
        label_description = new QLabel(TripCreateWidget);
        label_description->setObjectName(QString::fromUtf8("label_description"));
        label_description->setGeometry(QRect(30, 50, 181, 16));
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
        verticalLayoutWidget = new QWidget(TripCreateWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(290, 80, 291, 351));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_team_selected = new QLabel(verticalLayoutWidget);
        label_team_selected->setObjectName(QString::fromUtf8("label_team_selected"));
        label_team_selected->setTextFormat(Qt::MarkdownText);

        verticalLayout->addWidget(label_team_selected);

        textBrowser_team = new QTextBrowser(verticalLayoutWidget);
        textBrowser_team->setObjectName(QString::fromUtf8("textBrowser_team"));

        verticalLayout->addWidget(textBrowser_team);

        pushButton_done = new QPushButton(verticalLayoutWidget);
        pushButton_done->setObjectName(QString::fromUtf8("pushButton_done"));

        verticalLayout->addWidget(pushButton_done);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        comboBox_team = new QComboBox(verticalLayoutWidget);
        comboBox_team->setObjectName(QString::fromUtf8("comboBox_team"));

        horizontalLayout->addWidget(comboBox_team);

        pushButton_select = new QPushButton(verticalLayoutWidget);
        pushButton_select->setObjectName(QString::fromUtf8("pushButton_select"));

        horizontalLayout->addWidget(pushButton_select);


        verticalLayout->addLayout(horizontalLayout);

        comboBox_algorithm = new QComboBox(verticalLayoutWidget);
        comboBox_algorithm->setObjectName(QString::fromUtf8("comboBox_algorithm"));

        verticalLayout->addWidget(comboBox_algorithm);

        teamTable = new QTableView(TripCreateWidget);
        teamTable->setObjectName(QString::fromUtf8("teamTable"));
        teamTable->setGeometry(QRect(20, 120, 261, 261));

        retranslateUi(TripCreateWidget);

        QMetaObject::connectSlotsByName(TripCreateWidget);
    } // setupUi

    void retranslateUi(QWidget *TripCreateWidget)
    {
        TripCreateWidget->setWindowTitle(QCoreApplication::translate("TripCreateWidget", "Form", nullptr));
        label_description->setText(QCoreApplication::translate("TripCreateWidget", "Your dream vacation starts here.", nullptr));
        label_team_available->setText(QCoreApplication::translate("TripCreateWidget", "All Teams", nullptr));
        planName->setText(QCoreApplication::translate("TripCreateWidget", "## My Plan", nullptr));
        label_team_selected->setText(QCoreApplication::translate("TripCreateWidget", "### Selected Teams", nullptr));
        pushButton_done->setText(QCoreApplication::translate("TripCreateWidget", "Done", nullptr));
        pushButton_select->setText(QCoreApplication::translate("TripCreateWidget", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TripCreateWidget: public Ui_TripCreateWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIPCREATEWIDGET_H
