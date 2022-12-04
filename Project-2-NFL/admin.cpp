#include "admin.h"
#include "ui_admin.h"
#include "qsqlfootballClass.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QFile>

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

    QSqlQuery query;
    QSqlQueryModel* qryModel = new QSqlQueryModel();

    query.prepare("UPDATE Teams SET Name = :Stadium WHERE Team = :Team ");
    query.bindValue(":Stadium", stadiumString);
    query.bindValue(":Team", teamString);
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


void Admin::on_editCapacityButton_clicked()
{
    QString teamString = ui->teamLineEdit2->text();
    QString capacityString = ui->stadiumLineEdit2->text();

    QSqlQuery query;
    QSqlQueryModel* qryModel = new QSqlQueryModel();

    query.prepare("UPDATE Teams SET Capacity = :Capacity WHERE Team = :Team ");
    query.bindValue(":Capacity", capacityString);
    query.bindValue(":Team", teamString);
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


void Admin::on_pushButton_clicked()
{
    QFile file("../New Souvenirs.txt");
    QTextStream inFile(&file);

    QSqlDatabase myDb;

    if(QSqlDatabase::contains("qt_sql_default_connection"))
    {
        myDb = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        myDb = QSqlDatabase::addDatabase("QSQLITE");
    }
    QSqlQueryModel* qryModel = new QSqlQueryModel();
    myDb.open();

    if (!file.open(QIODevice::OpenModeFlag::ReadOnly))
        {
            qCritical()<<"please make sure that you put the .txt files in debug folder!";
            qCritical()<<file.errorString();
            return;
        }

        QString teamString;
        QString souvenirString;
        QString priceString;

        while(!inFile.atEnd())
        {
             QSqlQuery query;
             query.prepare("INSERT INTO Souvenirs(Team, Souvenir, Price) VALUES (:Team, :Souvenir, :Price)");

             teamString = inFile.readLine();
             souvenirString = inFile.readLine();
             priceString = inFile.readLine();

             query.bindValue(":Team", teamString);
             query.bindValue(":Souvenir", souvenirString);
             query.bindValue(":Price", priceString.toDouble());
             qDebug() << teamString << souvenirString << priceString;
             query.exec();

         }
         file.close();

         ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
         ui->tableView->setAlternatingRowColors(true);

         qryModel->setQuery("SELECT * FROM Souvenirs");
         ui->tableView->setModel(qryModel);
}


void Admin::on_importButton_2_clicked()
{
    QFile file("../New Team.txt");
    QTextStream inFile(&file);

    QSqlDatabase myDb;

    if(QSqlDatabase::contains("qt_sql_default_connection"))
    {
        myDb = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        myDb = QSqlDatabase::addDatabase("QSQLITE");
    }
    QSqlQueryModel* qryModel = new QSqlQueryModel();
    myDb.open();

    if (!file.open(QIODevice::OpenModeFlag::ReadOnly))
        {
            qCritical()<<"please make sure that you put the .txt files in debug folder!";
            qCritical()<<file.errorString();
            return;
        }

        QString teamString;
        QString nameString;
        QString capacityString;
        QString locationString;
        QString roofTypeString;
        QString surfaceString;
        QString openedString;
        QString conferenceString;
        QString divisionString;



        while(!inFile.atEnd())
        {
             QSqlQuery query;
             query.prepare("INSERT INTO Teams(Team, Name, Capacity, Location, RoofType, Surface, Opened, Conference, Division) VALUES (:Team, :Name, :Capacity, :Location, :RoofType, :Surface, :Opened, :Conference, :Division)");

             teamString = inFile.readLine();
             nameString = inFile.readLine();
             capacityString = inFile.readLine();
             locationString = inFile.readLine();
             roofTypeString = inFile.readLine();
             surfaceString = inFile.readLine();
             openedString = inFile.readLine();
             conferenceString = inFile.readLine();
             divisionString = inFile.readLine();

             query.bindValue(":Team", teamString);
             query.bindValue(":Name", nameString);
             query.bindValue(":Capacity", capacityString.toInt());
             query.bindValue(":Location", locationString);
             query.bindValue(":RoofType", roofTypeString);
             query.bindValue(":Surface", surfaceString);
             query.bindValue(":Opened", openedString.toInt());
             query.bindValue(":Conference", conferenceString);
             query.bindValue(":Division", divisionString);
             qDebug() << teamString << nameString << capacityString << locationString << roofTypeString << surfaceString << openedString << conferenceString << divisionString;
             if (!query.exec() )
             {
                  QMessageBox::warning(this, "Query Error", "Query Not Executed");
             }
             else
             {
                  QMessageBox::information(this, "Stadium Successfully Updated", "Success");

             }

         }
         file.close();

         ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
         ui->tableView_2->setAlternatingRowColors(true);

         qryModel->setQuery("SELECT Team, Name, Capacity FROM Teams");
         ui->tableView_2->setModel(qryModel);
}


void Admin::on_importButton_3_clicked()
{
    QFile file("../New Distances.txt");
    QTextStream inFile(&file);

    QSqlDatabase myDb;

    if(QSqlDatabase::contains("qt_sql_default_connection"))
    {
        myDb = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        myDb = QSqlDatabase::addDatabase("QSQLITE");
    }
    myDb.open();

    if (!file.open(QIODevice::OpenModeFlag::ReadOnly))
        {
            qCritical()<<"please make sure that you put the .txt files in debug folder!";
            qCritical()<<file.errorString();
            return;
        }

        QString nameString;
        QString startString;
        QString endString;
        QString distanceString;



        while(!inFile.atEnd())
        {
             QSqlQuery query;
             query.prepare("INSERT INTO Distances(Team, Starting_Stadium, Ending_Stadium, Distance) VALUES (:Team, :Start, :End, :Distance)");

             nameString = inFile.readLine();
             startString = inFile.readLine();
             endString = inFile.readLine();
             distanceString = inFile.readLine();

             query.bindValue(":Team", nameString);
             query.bindValue(":Start", startString);
             query.bindValue(":End", endString);
             query.bindValue(":Distance", distanceString);

             qDebug() << nameString << startString << endString << distanceString;
             query.exec();

         }
         file.close();

}

