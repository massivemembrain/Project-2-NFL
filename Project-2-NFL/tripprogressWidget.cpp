#include "tripprogressWidget.h"
#include "ui_tripprogressWidget.h"

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


    ui -> comboBox_quantity -> addItem("1");
    ui -> comboBox_quantity -> addItem("2");
    ui -> comboBox_quantity -> addItem("3");
    ui -> comboBox_quantity -> addItem("4");
    ui -> comboBox_quantity -> addItem("5");
    ui -> comboBox_quantity -> addItem("6");
    ui -> comboBox_quantity -> addItem("7");
    ui -> comboBox_quantity -> addItem("8");
    ui -> comboBox_quantity -> addItem("9");
    ui -> comboBox_quantity -> addItem("10");
    ui -> comboBox_quantity -> addItem("11");
    ui -> comboBox_quantity -> addItem("12");
    ui -> comboBox_quantity -> addItem("13");
    ui -> comboBox_quantity -> addItem("14");
    ui -> comboBox_quantity -> addItem("15");
    ui -> comboBox_quantity -> addItem("16");
    ui -> comboBox_quantity -> addItem("17");
    ui -> comboBox_quantity -> addItem("18");
    ui -> comboBox_quantity -> addItem("19");
    ui -> comboBox_quantity -> addItem("20");
    ui -> comboBox_quantity -> addItem("21");
    ui -> comboBox_quantity -> addItem("22");
    ui -> comboBox_quantity -> addItem("23");
    ui -> comboBox_quantity -> addItem("24");
    ui -> comboBox_quantity -> addItem("25");
    ui -> comboBox_quantity -> addItem("26");
    ui -> comboBox_quantity -> addItem("27");
    ui -> comboBox_quantity -> addItem("28");
    ui -> comboBox_quantity -> addItem("29");
    ui -> comboBox_quantity -> addItem("30");



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

    QString quantity = ui-> comboBox_quantity ->currentText();
    int quant = quantity.toInt();
    qDebug() << quantity;
    cout << quant;


    QSqlQuery query;
    //query.prepare("SELECT Price FROM Souvenirs WHERE Team LIKE '%"+selectedTeam +"%' AND Souvenir LIKE  '%"+selectedSouvenir +"%'");
    query.prepare("SELECT Price FROM Souvenirs WHERE Team LIKE 'Arizona%Cardinals' AND Souvenir LIKE 'Signed%Helmets'");
    query.exec();

      float price = query.value(0).toFloat();

      qDebug() << query.value(0);


       //qDebug() << selectedTeam  << " -  " << selectedSouvenir << " - " << quantity << price ;
      qDebug() << " p     "  << price;






}

