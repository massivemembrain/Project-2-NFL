/********************************************************************************
** Form generated from reading UI file 'admin.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_H
#define UI_ADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Admin
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QPushButton *addButton;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QLineEdit *teamLineEdit;
    QLineEdit *souvenirLineEdit;
    QLineEdit *priceLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QTableView *tableView_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *editStadiumButton;
    QPushButton *editCapacityButton;
    QLineEdit *teamLineEdit2;
    QLineEdit *stadiumLineEdit2;
    QLineEdit *capacityLineEdit2;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton;
    QPushButton *importButton_2;
    QPushButton *importButton_3;
    QPushButton *testingButton;

    void setupUi(QWidget *Admin)
    {
        if (Admin->objectName().isEmpty())
            Admin->setObjectName(QString::fromUtf8("Admin"));
        Admin->resize(1266, 464);
        verticalLayoutWidget = new QWidget(Admin);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 20, 531, 281));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(verticalLayoutWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        addButton = new QPushButton(verticalLayoutWidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        horizontalLayout->addWidget(addButton);

        editButton = new QPushButton(verticalLayoutWidget);
        editButton->setObjectName(QString::fromUtf8("editButton"));

        horizontalLayout->addWidget(editButton);

        deleteButton = new QPushButton(verticalLayoutWidget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        horizontalLayout->addWidget(deleteButton);


        verticalLayout->addLayout(horizontalLayout);

        teamLineEdit = new QLineEdit(verticalLayoutWidget);
        teamLineEdit->setObjectName(QString::fromUtf8("teamLineEdit"));

        verticalLayout->addWidget(teamLineEdit);

        souvenirLineEdit = new QLineEdit(verticalLayoutWidget);
        souvenirLineEdit->setObjectName(QString::fromUtf8("souvenirLineEdit"));

        verticalLayout->addWidget(souvenirLineEdit);

        priceLineEdit = new QLineEdit(verticalLayoutWidget);
        priceLineEdit->setObjectName(QString::fromUtf8("priceLineEdit"));

        verticalLayout->addWidget(priceLineEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayoutWidget = new QWidget(Admin);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(630, 20, 521, 281));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tableView_2 = new QTableView(horizontalLayoutWidget);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));

        verticalLayout_2->addWidget(tableView_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        editStadiumButton = new QPushButton(horizontalLayoutWidget);
        editStadiumButton->setObjectName(QString::fromUtf8("editStadiumButton"));

        horizontalLayout_4->addWidget(editStadiumButton);

        editCapacityButton = new QPushButton(horizontalLayoutWidget);
        editCapacityButton->setObjectName(QString::fromUtf8("editCapacityButton"));

        horizontalLayout_4->addWidget(editCapacityButton);


        verticalLayout_2->addLayout(horizontalLayout_4);

        teamLineEdit2 = new QLineEdit(horizontalLayoutWidget);
        teamLineEdit2->setObjectName(QString::fromUtf8("teamLineEdit2"));

        verticalLayout_2->addWidget(teamLineEdit2);

        stadiumLineEdit2 = new QLineEdit(horizontalLayoutWidget);
        stadiumLineEdit2->setObjectName(QString::fromUtf8("stadiumLineEdit2"));

        verticalLayout_2->addWidget(stadiumLineEdit2);

        capacityLineEdit2 = new QLineEdit(horizontalLayoutWidget);
        capacityLineEdit2->setObjectName(QString::fromUtf8("capacityLineEdit2"));

        verticalLayout_2->addWidget(capacityLineEdit2);


        horizontalLayout_3->addLayout(verticalLayout_2);

        horizontalLayoutWidget_2 = new QWidget(Admin);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(410, 340, 458, 80));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(horizontalLayoutWidget_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_5->addWidget(pushButton);

        importButton_2 = new QPushButton(horizontalLayoutWidget_2);
        importButton_2->setObjectName(QString::fromUtf8("importButton_2"));

        horizontalLayout_5->addWidget(importButton_2);

        importButton_3 = new QPushButton(horizontalLayoutWidget_2);
        importButton_3->setObjectName(QString::fromUtf8("importButton_3"));

        horizontalLayout_5->addWidget(importButton_3);

        testingButton = new QPushButton(horizontalLayoutWidget_2);
        testingButton->setObjectName(QString::fromUtf8("testingButton"));

        horizontalLayout_5->addWidget(testingButton);


        retranslateUi(Admin);

        QMetaObject::connectSlotsByName(Admin);
    } // setupUi

    void retranslateUi(QWidget *Admin)
    {
        Admin->setWindowTitle(QCoreApplication::translate("Admin", "Form", nullptr));
        addButton->setText(QCoreApplication::translate("Admin", "Add", nullptr));
        editButton->setText(QCoreApplication::translate("Admin", "Edit", nullptr));
        deleteButton->setText(QCoreApplication::translate("Admin", "Delete", nullptr));
        teamLineEdit->setPlaceholderText(QCoreApplication::translate("Admin", "Team Name", nullptr));
        souvenirLineEdit->setPlaceholderText(QCoreApplication::translate("Admin", "Souvenir Name", nullptr));
        priceLineEdit->setText(QString());
        priceLineEdit->setPlaceholderText(QCoreApplication::translate("Admin", "Price", nullptr));
        editStadiumButton->setText(QCoreApplication::translate("Admin", "Edit Stadium", nullptr));
        editCapacityButton->setText(QCoreApplication::translate("Admin", "Edit Capacity", nullptr));
        teamLineEdit2->setPlaceholderText(QCoreApplication::translate("Admin", "Team Name", nullptr));
        stadiumLineEdit2->setPlaceholderText(QCoreApplication::translate("Admin", "Stadium Name", nullptr));
        capacityLineEdit2->setPlaceholderText(QCoreApplication::translate("Admin", "Capacity", nullptr));
        pushButton->setText(QCoreApplication::translate("Admin", "Import Souvenirs", nullptr));
        importButton_2->setText(QCoreApplication::translate("Admin", "Import Teams", nullptr));
        importButton_3->setText(QCoreApplication::translate("Admin", "Import Distances", nullptr));
        testingButton->setText(QCoreApplication::translate("Admin", "Testing", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Admin: public Ui_Admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H
