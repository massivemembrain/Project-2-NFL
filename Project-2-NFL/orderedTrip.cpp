#include "orderedtrip.h"
#include "ui_orderedtrip.h"
#include <QTableView>
#include <QTableWidget>
#include <QItemSelectionModel>
#include <QVector>
#include <QSqlQueryModel>
#include "dijkstra.h"
//#include"dijkstra.cpp"

// vector definition
QVector<QString> myVector;
int matrix[NUMBER_CITIES][NUMBER_CITIES];


OrderedTrip::OrderedTrip(QWidget *parent)
    :     QWidget(parent),
      ui(new Ui::orderedTrip)
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

    //myDb.setDatabaseName("/Users/nedamohseni/Documents/GitHub/Project-2-NFL/NFLProject.db");
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
    ui->comboBox->setModel(comboquery);
}
// =============================================================================
 OrderedTrip :: ~ OrderedTrip()
 {
    // myVector.clear();
 }
// =============================================================================
void OrderedTrip::on_pushButton_selectOrigin_clicked()
{
    // stores the team selected in combobox in a variable
    QString originTeam = ui-> comboBox ->currentText();

    myVector.push_back(originTeam);

     ui -> textBrowser -> insertPlainText("first : " + originTeam + "\n");

    QSqlQueryModel* qryModel = new QSqlQueryModel();
    qryModel->setQuery("SELECT DISTINCT Team FROM Distances WHERE Team NOT LIKE '%"+ originTeam +"%' ");
   ui->tableView->setModel(qryModel);
   ui->tableView->setAlternatingRowColors(true);
   ui->tableView->horizontalHeader() -> setSectionResizeMode(QHeaderView::Stretch);
}
// ===================================================================================
void OrderedTrip::on_tableView_clicked(const QModelIndex &index)
{
   ui -> tableView -> setSelectionMode(QAbstractItemView::MultiSelection);
   ui -> tableView -> setSelectionBehavior(QAbstractItemView:: SelectItems);

    // gets the data on the which was cell clicked on & store it in chosen
    QString chosen = ui -> tableView -> model() -> data(index).toString();

    qDebug() << "selected : " << chosen;

    myVector.push_back(chosen);

    ui -> textBrowser -> insertPlainText(chosen);
    ui -> textBrowser -> insertPlainText("\n");

    //ui->tableView->selectRow(index.row());

    //numClicked ++;
    //qDebug() << "helloooo" << numClicked;

}
// ======================================================================================
void OrderedTrip::on_pushButton_done_clicked()
{
    ui -> textBrowser -> append("here is my vector values:\n");

    for (int i = 0; i < myVector.size(); i ++)
    {
         ui -> textBrowser -> append(myVector.at(i));
    }

    Dijkstra d ;  // object of dij class

    QString startString;
    QString endString;

    for (int i = 0; i < myVector.size() - 1  ; i ++)
    {
        //cout << "cout first" << i << endl;

       QSqlQuery query;
       query.prepare("SELECT Start_Number FROM Distances WHERE Team = :Team");
       query.bindValue(":Team", myVector.at(i));
       qDebug() << query.exec();

       if (query.first())
           startString = query.value(0).toString();

       int start = startString.toInt();

       // ======================================

       QSqlQuery query2;
       query2.prepare("SELECT Start_Number FROM Distances WHERE Team = :Team");
       query2.bindValue(":Team", myVector.at(i+1));
       qDebug() << query2.exec();

       if (query2.first())
           endString = query2.value(0).toString();

       int end = endString.toInt();

       qDebug() << "initial :" << myVector.at(i);
       qDebug() << "final :" << myVector.at(i+1);

        // calling dij
       d.shortestPath(start, end);
  }

}


void OrderedTrip::on_pushButton_startAnotherTrip_clicked()
{
    myVector.clear();
    ui -> textBrowser -> append("content of vector after deleting\n");

    for (int i = 0; i < myVector.size(); i ++)
    {
         ui -> textBrowser -> append(myVector.at(i));
    }

}

