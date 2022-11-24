#include "admin.h"
#include "ui_admin.h"
#include "qsqlfootball.h"
#include <QSqlQuery>
#include <QMessageBox>

Admin::Admin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
//    ui->comboBox->addItem("None");
//    ui->comboBox->addItem("Arizona Cardinals");
//    ui->comboBox->addItem("Atlanta Falcons");
//    ui->comboBox->addItem("Baltimore Ravens");
//    ui->comboBox->addItem("Buffalo Bills");
//    ui->comboBox->addItem("Carolina Panthers");
//    ui->comboBox->addItem("Chicago Bears");
//    ui->comboBox->addItem("Cincinnati Bengals");
//    ui->comboBox->addItem("Cleveland Browns");
//    ui->comboBox->addItem("Dallas Cowboys");
//    ui->comboBox->addItem("Denver Broncos");
//    ui->comboBox->addItem("Detroit Lions");
//    ui->comboBox->addItem("Green Bay Packers");
//    ui->comboBox->addItem("Houston Texans");
//    ui->comboBox->addItem("Indianapolis Colts");
//    ui->comboBox->addItem("Jacksonville Jaguars");
//    ui->comboBox->addItem("Kansas City Chiefs");
//    ui->comboBox->addItem("Las Vegas Raiders");
//    ui->comboBox->addItem("Los Angeles Chargers");
//    ui->comboBox->addItem("Los Angeles Rams");
//    ui->comboBox->addItem("Miami Dolphins");
//    ui->comboBox->addItem("Minnesota Vikings");
//    ui->comboBox->addItem("New England Patriots");
//    ui->comboBox->addItem("New Orleans Saints");
//    ui->comboBox->addItem("New York Giants");
//    ui->comboBox->addItem("New York Jets");
//    ui->comboBox->addItem("Philadelphia Eagles");
//    ui->comboBox->addItem("Pittsburgh Steelers");
//    ui->comboBox->addItem("San Francisco 49ers");
//    ui->comboBox->addItem("Seattle Seahawks");
//    ui->comboBox->addItem("Tampa Bay Buccaneers");
//    ui->comboBox->addItem("Tennessee Titans");
//    ui->comboBox->addItem("Washington Commanders");




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

    QSqlQueryModel* qryModel = new QSqlQueryModel();
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setAlternatingRowColors(true);

    qryModel->setQuery("SELECT * FROM Souvenirs");

    ui->tableView->setModel(qryModel);


}

Admin::~Admin()
{
    delete ui;
}



void Admin::on_addButton_clicked()
{
    QString teamString = ui->teamLineEdit->text();
    QString souvenirString = ui->souvenirLineEdit->text();
    QString priceString = ui->priceLineEdit->text();

    QSqlQuery query;
    QSqlQueryModel* qryModel = new QSqlQueryModel();

    query.prepare("INSERT INTO Souvenirs(Team, Souvenir, Price) VALUES (:Team, :Souvenir, :Price)");
    query.bindValue(":Team", teamString);
    query.bindValue(":Souvenir", souvenirString);
    query.bindValue(":Price", priceString);
    if (!query.exec() )
    {
         QMessageBox::warning(this, "Query Error", "Query not executed");
    }
    else
    {
         QMessageBox::information(this, "Souvenir Successfully Added", "Success");

    }

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setAlternatingRowColors(true);

    qryModel->setQuery("SELECT * FROM Souvenirs");
    ui->tableView->setModel(qryModel);


}


void Admin::on_deleteButton_clicked()
{
    QString teamString = ui->teamLineEdit->text();
    QString souvenirString = ui->souvenirLineEdit->text();

    QSqlQuery query;
    QSqlQueryModel* qryModel = new QSqlQueryModel();

    query.prepare("DELETE FROM Souvenirs WHERE Team = (:Team) AND Souvenir = (:Souvenir) ");
    query.bindValue(":Team", teamString);
    query.bindValue(":Souvenir", souvenirString);
    if (!query.exec() )
    {
         QMessageBox::warning(this, "Query Error", "Query not executed");
    }
    else
    {
         QMessageBox::information(this, "Souvenir Successfully Added", "Success");

    }

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setAlternatingRowColors(true);

    qryModel->setQuery("SELECT * FROM Souvenirs");
    ui->tableView->setModel(qryModel);
}


void Admin::on_editButton_clicked()
{
    QString teamString = ui->teamLineEdit->text();
    QString souvenirString = ui->souvenirLineEdit->text();
    QString priceString = ui->priceLineEdit->text();

    QSqlQuery query;
    QSqlQueryModel* qryModel = new QSqlQueryModel();

    query.prepare("UPDATE Souvenirs SET Price = :Price WHERE Team = :Team AND Souvenir = :Souvenir ");
    query.bindValue(":Price", priceString);
    query.bindValue(":Team", teamString);
    query.bindValue(":Souvenir", souvenirString);
    if (!query.exec() )
    {
         QMessageBox::warning(this, "Query Error", "Query not executed");
    }
    else
    {
         QMessageBox::information(this, "Souvenir Successfully Added", "Success");

    }

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setAlternatingRowColors(true);

    qryModel->setQuery("SELECT * FROM Souvenirs");
    ui->tableView->setModel(qryModel);
}

