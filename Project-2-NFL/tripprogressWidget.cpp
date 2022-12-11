#include "tripprogressWidget.h"
#include "ui_tripprogressWidget.h"
#include "tripcreateWidget.h"

#include <QSqlQueryModel>
#include <iostream>
#include <iomanip>
#include <QWidget>
#include <QDebug>
#include<QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
using namespace std;

TripProgressWidget::TripProgressWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TripProgressWidget)
{
    ui->setupUi(this);


    QSqlDatabase myDb;

    if(QSqlDatabase::contains("qt_sql_default_connection"))
    {
        myDb = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        myDb = QSqlDatabase::addDatabase("QSQLITE");
    }

    //myDb.setDatabaseName("/Users/nedamohseni/Documents/GitHub/Project-2-NFL/Project-2-NFL/NFLProject.db");
    myDb.setDatabaseName("../NFLProject.db");
    if (myDb.open())
    {
        qDebug().noquote() << "db found and open";
    }
    else
    {
        qDebug().noquote() << "db not found";
    }

    QSqlQueryModel* comboquery1 = new QSqlQueryModel();
    comboquery1->setQuery("SELECT DISTINCT Team FROM Souvenirs");
    ui-> comboBox ->setModel(comboquery1);


    // stores the team selected in combobox in a variable
    QString selectedTeam = ui-> comboBox ->currentText();


    QSqlQueryModel* comboquery2 = new QSqlQueryModel();
    comboquery2->setQuery("SELECT Souvenir FROM Souvenirs WHERE Team LIKE '%"+selectedTeam +"%' ");
    ui-> souvenirOptions ->setModel(comboquery2);

    ui->spinBox_quantity->singleStep();
    ui->spinBox_quantity->setSingleStep(0);






}

TripProgressWidget::~TripProgressWidget()
{
    delete ui;
}

void TripProgressWidget::on_pushButton_buy_clicked()
{
    // stores the team selected in combobox in a variable
    QString selectedTeam = ui-> comboBox ->currentText();

    // stores the souvenir selected in combobox in a variable
    QString selectedSouvenir= ui-> souvenirOptions ->currentText();

    int quantity = ui-> spinBox_quantity->value();
    qDebug() << quantity;


    QSqlQuery query;
    //query.prepare("SELECT Price FROM Souvenirs WHERE Team LIKE '%"+selectedTeam +"%' AND Souvenir LIKE  '%"+selectedSouvenir +"%'");
    query.prepare("SELECT Price FROM Souvenirs WHERE Team LIKE 'Arizona%Cardinals' AND Souvenir LIKE 'Signed%Helmets'");
    query.exec();

      float price = query.value(0).toFloat();

      qDebug() << query.value(0);


       //qDebug() << selectedTeam  << " -  " << selectedSouvenir << " - " << quantity << price ;
      qDebug() << " p     "  << price;






}

