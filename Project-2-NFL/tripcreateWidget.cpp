#include "tripcreateWidget.h"
#include "qsqlquery.h"
#include "ui_tripcreateWidget.h"
#include "customtrip.h"

TripCreateWidget::TripCreateWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TripCreateWidget)
{
    ui->setupUi(this);
    ui->planType->addItem("Selected Order");
    ui->planType->addItem("Shortest Order");


    if(QSqlDatabase::contains("qt_sql_default_connection"))
    {
        myDb = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        myDb = QSqlDatabase::addDatabase("QSQLITE");
    }

    myDb.setDatabaseName("../NFLProject.db");
    if (myDb.open())
    {
        qDebug().noquote() << "db found and open";
    }
    else
    {
        qDebug().noquote() << "db not found";
    }

    QSqlQueryModel model;
    QSqlQuery query(myDb);

    QSqlQueryModel* teamModel = new QSqlQueryModel();

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setAlternatingRowColors(true);

    query.exec("SELECT DISTINCT Team, Name FROM Teams");

    teamModel->setQuery(std::move(query));

    ui->tableView->setModel(teamModel);

    QSqlQueryModel* comboquery = new QSqlQueryModel();
    comboquery->setQuery("SELECT Name FROM Teams");
    ui->comboBox_team->setModel(comboquery);

    count = 1; //setting next city check to 1;
    addCity = 0;//resetting the addcity count;

}

TripCreateWidget::~TripCreateWidget()
{
    myDb.close();
    qDebug("Database closed.");
    delete ui;

    QSqlQuery query;
    query.prepare("DELETE FROM Custom_Trip");
    query.exec();
}

void TripCreateWidget::on_proceedButtons_accepted()
{

}


void TripCreateWidget::on_proceedButtons_rejected()
{
    close();
    parentWidget()->close();
}


void TripCreateWidget::on_pushButton_select_clicked()
{
    QString city;

    QSqlQuery addCityQuery;
    QSqlQueryModel* qryModel = new QSqlQueryModel();

        city = ui->comboBox_team->currentText();

        addCityQuery.prepare("INSERT INTO Custom_Trip VALUES (:city)");
        addCityQuery.bindValue(":city", city);
        qDebug() << city << addCityQuery.exec();

        qryModel->setQuery("SELECT City FROM Custom_Trip");

        ui->tableView_custom->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableView_custom->setAlternatingRowColors(true);
        ui->tableView_custom->setModel(qryModel);

        ui->comboBox_team->removeItem(ui->comboBox_team->currentIndex());
        addCity++;


}

void TripCreateWidget::on_pushButton_done_clicked()
{
    if (addCity != 0)
    {
        QSqlQuery *addQuery = new QSqlQuery(myDb);
        QSqlQuery *startingCityQuery = new QSqlQuery(myDb);
        QSqlQueryModel* qryModel = new QSqlQueryModel();
        QString startingCity;

        startingCityQuery->exec("SELECT City FROM Custom_Trip");
        startingCityQuery->next();
        startingCity = startingCityQuery->value(0).toString();

        if (addCity == 1)
        {
              addQuery->prepare("INSERT INTO Berlin_Trip VALUES ((:City),(:distance))");
              addQuery->bindValue(":City", startingCity);
              addQuery->bindValue(":distance", 0);
              addQuery->exec();
              nextCityCheck = addCity;
        }
        else
        {
            CustomTrip map;
            map.fullMap(startingCity, addCity);
            nextCityCheck = addCity;
        }
        ui->tableView_custom->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableView_custom->setAlternatingRowColors(true);
        qryModel->setQuery("SELECT City, Distance_Travelled AS'Total Distance Traveled' FROM Berlin_trip");
        ui->tableView_custom->setModel(qryModel);
        customTripNotClicked = false;

}

}

void TripCreateWidget::on_pushButton_delete_clicked()
{
    QSqlQuery query;
    query.prepare("DELETE FROM Custom_Trip");
    query.exec();
}

