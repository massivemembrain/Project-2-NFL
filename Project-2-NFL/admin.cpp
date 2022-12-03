#include "admin.h"
#include "ui_admin.h"
#include "qsqlfootballClass.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>

Admin::Admin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);

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

    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QSqlQueryModel* qryModel2 = new QSqlQueryModel();
    ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_2->setAlternatingRowColors(true);

    qryModel2->setQuery("SELECT Team, Name, Capacity FROM Teams");

    ui->tableView_2->setModel(qryModel2);

    ui->tableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);


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


void Admin::on_editStadiumButton_clicked()
{
    QString teamString = ui->teamLineEdit2->text();
    QString stadiumString = ui->stadiumLineEdit2->text();
    QString capacityString = ui->capacityLineEdit2->text();

    QSqlQuery query;
    QSqlQueryModel* qryModel = new QSqlQueryModel();

    query.prepare("UPDATE Teams SET Name = ? , Capacity = ? WHERE Team = ?");
    query.addBindValue(stadiumString);
    query.addBindValue(capacityString);
    query.addBindValue(teamString);
    query.lastError();
    if (!query.exec() )
    {
         QMessageBox::warning(this, "Query Error", "Query Not Executed");
    }
    else
    {
         QMessageBox::information(this, "Stadium Successfully Updated", "Success");

    }

    ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_2->setAlternatingRowColors(true);

    qryModel->setQuery("SELECT Team, Name, Capacity FROM Teams");
    ui->tableView_2->setModel(qryModel);
}

