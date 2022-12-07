#include "tripcreateWidget.h"
#include "qsqlquery.h"
#include "ui_tripcreateWidget.h"

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

    query.exec("SELECT DISTINCT Team FROM Teams");

    teamModel->setQuery(std::move(query));

    ui->tableView->setModel(teamModel);

}

TripCreateWidget::~TripCreateWidget()
{
    myDb.close();
    qDebug("Database closed.");
    delete ui;
}

void TripCreateWidget::on_proceedButtons_accepted()
{

}


void TripCreateWidget::on_proceedButtons_rejected()
{
    close();
    parentWidget()->close();
}

