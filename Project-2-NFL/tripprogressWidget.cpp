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

    totalCost = 0;

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

    QSqlQueryModel* tableQuery = new QSqlQueryModel();
    ui->souvenirTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->souvenirTable->setAlternatingRowColors(true);
    tableQuery->setQuery("SELECT Souvenirs.Team, Souvenirs.Souvenir, Souvenirs.Price FROM Souvenirs INNER JOIN Custom_Trip WHERE Souvenirs.Team = Custom_Trip.City");
    ui ->souvenirTable ->setModel(tableQuery);


    QSqlQueryModel* comboquery1 = new QSqlQueryModel();
    comboquery1->setQuery("SELECT City FROM Custom_Trip");
    ui-> comboBox ->setModel(comboquery1);

    QSqlQuery vectorQuery;
    vectorQuery.prepare("SELECT City FROM Custom_Trip");
    qDebug() << "vectorQuery" << vectorQuery.exec();
    while (vectorQuery.next())
    {
        cityTotal.push_back(make_pair(vectorQuery.value(0).toString(), 0));
    }


    // stores the team selected in combobox in a variable
    QString selectedTeam = ui-> comboBox ->currentText();





    ui->spinBox_quantity->singleStep();
    ui->spinBox_quantity->setSingleStep(0);








}

TripProgressWidget::~TripProgressWidget()
{
    delete ui;
    QSqlQuery query;
    query.prepare("DELETE FROM Custom_Trip");
    qDebug() << "Delete query" << query.exec();
}

void TripProgressWidget::on_pushButton_buy_clicked()
{
    // stores the team selected in combobox in a variable
    QString selectedTeam = ui-> comboBox ->currentText();

    // stores the souvenir selected in combobox in a variable
    QString selectedSouvenir= ui-> comboBox_souvenirs ->currentText();

    int quantity = ui-> spinBox_quantity->value();
    qDebug() << quantity;

    double price;
    qDebug() << "Price before is " << price;
    QString stringToFloat;


    QSqlQuery query;
    //query.prepare("SELECT Price FROM Souvenirs WHERE Team LIKE '%"+selectedTeam +"%' AND Souvenir LIKE  '%"+selectedSouvenir +"%'");
    query.prepare("SELECT Price FROM Souvenirs WHERE Team = (:Team) AND Souvenir = (:Souvenir)");\
    query.bindValue(":Team", ui->comboBox->currentText());
    query.bindValue(":Souvenir", ui->comboBox_souvenirs->currentText());
    qDebug() << "Buy Query" << query.exec();
    while (query.next())
    {
        stringToFloat = query.value(0).toString();
        qDebug() << "String of price is" << stringToFloat;
        price = stringToFloat.toDouble();

        qDebug() << "Price is " << price;
    }



      float amount = price * quantity;
      QString intToString;

      for (int i =0; i < cityTotal.size(); i++)
      {
          if (cityTotal[i].first == ui->comboBox->currentText())
          {
              cityTotal[i].second += amount;
              intToString = QString::number(cityTotal[i].second);
              ui->tripReceipt->append(cityTotal[i].first + " total is " + intToString);
          }
      }

      totalCost += amount;



       //qDebug() << selectedTeam  << " -  " << selectedSouvenir << " - " << quantity << price ;
      qDebug() << " p     "  << price;






}


void TripProgressWidget::on_comboBox_currentTextChanged(const QString &arg1)
{
    ui->comboBox_souvenirs->clear();

    QSqlQuery query;
    query.prepare("SELECT Souvenir FROM Souvenirs WHERE Team = (:Team)");
    query.bindValue(":Team", ui->comboBox->currentText());
    qDebug() << query.exec();
    while (query.next())
    {
           ui->comboBox_souvenirs->addItem(query.value(0).toString());
    }
}


void TripProgressWidget::on_pushButton_done_clicked()
{
    QSqlQuery query;
    query.prepare("DELETE FROM Custom_Trip");
    qDebug() << "Delete query" << query.exec();

    TripProgressWidget::close();
}


void TripProgressWidget::on_pushButton_total_clicked()
{
    QString doubleToString = QString::number(totalCost);
    ui->tripReceipt->append("The total cost for the trip is: " + doubleToString);
}

