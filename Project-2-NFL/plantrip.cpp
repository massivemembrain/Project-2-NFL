#include "plantrip.h"
#include "ui_planTrip.h"
#include <QTableView>
#include <QTableWidget>
#include <QItemSelectionModel>
#include <QVector>
#include <QSqlQueryModel>

QVector<QString> myV;

planTrip::planTrip(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::planTrip)
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

    // code for combobox options
    QSqlQueryModel* comboquery = new QSqlQueryModel();
    comboquery->setQuery("SELECT DISTINCT Team FROM Distances");
    ui->starting_comboBox->setModel(comboquery);

//    QSqlQueryModel* qryModel = new QSqlQueryModel();
//    qryModel->setQuery("SELECT DISTINCT Team FROM Distances WHERE Team NOT LIKE '%"+ originTeam +"%' ");
//    ui->rest_tableView->setModel(qryModel);
//    ui->rest_tableView->setAlternatingRowColors(true);
}

planTrip::~planTrip()
{
    delete ui;
}

void planTrip::on_pushButton_choose_clicked()
{
    // stores the team selected in combobox in a variable
    QString originTeam = ui-> starting_comboBox ->currentText();

    myV.push_back(originTeam);

     ui -> textBrowser -> insertPlainText("first : " + originTeam + "\n");

   QSqlQueryModel* qryModel = new QSqlQueryModel();
   qryModel->setQuery("SELECT DISTINCT Team FROM Distances WHERE Team NOT LIKE '%"+ originTeam +"%' ");
   ui->rest_tableView->setModel(qryModel);
   ui->rest_tableView->setAlternatingRowColors(true);
   ui->rest_tableView->horizontalHeader() -> setSectionResizeMode(QHeaderView::Stretch);
}
