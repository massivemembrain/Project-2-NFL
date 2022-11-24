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

    void setupUi(QWidget *Admin)
    {
        if (Admin->objectName().isEmpty())
            Admin->setObjectName(QString::fromUtf8("Admin"));
        Admin->resize(793, 464);
        verticalLayoutWidget = new QWidget(Admin);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 20, 741, 281));
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


        retranslateUi(Admin);

        QMetaObject::connectSlotsByName(Admin);
    } // setupUi

    void retranslateUi(QWidget *Admin)
    {
        Admin->setWindowTitle(QCoreApplication::translate("Admin", "Form", nullptr));
        addButton->setText(QCoreApplication::translate("Admin", "Add", nullptr));
        editButton->setText(QCoreApplication::translate("Admin", "Edit", nullptr));
        deleteButton->setText(QCoreApplication::translate("Admin", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Admin: public Ui_Admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H
