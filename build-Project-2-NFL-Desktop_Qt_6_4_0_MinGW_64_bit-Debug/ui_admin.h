/********************************************************************************
** Form generated from reading UI file 'admin.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
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

    void setupUi(QWidget *Admin)
    {
        if (Admin->objectName().isEmpty())
            Admin->setObjectName("Admin");
        Admin->resize(793, 464);
        verticalLayoutWidget = new QWidget(Admin);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(30, 20, 741, 281));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(verticalLayoutWidget);
        tableView->setObjectName("tableView");

        verticalLayout->addWidget(tableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        addButton = new QPushButton(verticalLayoutWidget);
        addButton->setObjectName("addButton");

        horizontalLayout->addWidget(addButton);

        editButton = new QPushButton(verticalLayoutWidget);
        editButton->setObjectName("editButton");

        horizontalLayout->addWidget(editButton);

        deleteButton = new QPushButton(verticalLayoutWidget);
        deleteButton->setObjectName("deleteButton");

        horizontalLayout->addWidget(deleteButton);


        verticalLayout->addLayout(horizontalLayout);

        teamLineEdit = new QLineEdit(verticalLayoutWidget);
        teamLineEdit->setObjectName("teamLineEdit");

        verticalLayout->addWidget(teamLineEdit);

        souvenirLineEdit = new QLineEdit(verticalLayoutWidget);
        souvenirLineEdit->setObjectName("souvenirLineEdit");

        verticalLayout->addWidget(souvenirLineEdit);

        priceLineEdit = new QLineEdit(verticalLayoutWidget);
        priceLineEdit->setObjectName("priceLineEdit");

        verticalLayout->addWidget(priceLineEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");

        verticalLayout->addLayout(horizontalLayout_2);


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
    } // retranslateUi

};

namespace Ui {
    class Admin: public Ui_Admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H
