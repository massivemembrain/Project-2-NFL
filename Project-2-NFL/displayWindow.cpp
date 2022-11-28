#include "displayWindow.h"
#include "ui_displayWindow.h"



displayWindow::displayWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::displayWindow)
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

    myDb.setDatabaseName("/Users/nedamohseni/Documents/Github/Project-2-NFL/Project-2-NFL//NFLProject.db");
    if (myDb.open())
    {
        qDebug().noquote() << "db found and open";
    }
    else
    {
        qDebug().noquote() << "db not found";
    }

    QSqlQueryModel* qryModel = new QSqlQueryModel();
    ui->tableView->setAlternatingRowColors(true);
    qryModel->setQuery("SELECT * FROM Teams");
    ui->tableView->setModel(qryModel);


    // code for combobox options
    QSqlQueryModel* comboquery = new QSqlQueryModel();
    comboquery->setQuery("SELECT Team FROM Teams");
    ui->comboBox->setModel(comboquery);

}
// =======================================================
displayWindow::~displayWindow()
{
    delete ui;
}
// =======================================================

void displayWindow :: on_pushButton_selectTeam_clicked()
{
    // stores the team selected in combobox in a variable
    QString selectedTeam = ui-> comboBox ->currentText();

    QSqlQueryModel* qryModel = new QSqlQueryModel();
    //ui->tableView->setAlternatingRowColors(true);
    qryModel->setQuery("SELECT * FROM Teams WHERE Team LIKE '%"+selectedTeam +"%' ");
    ui->tableView->setModel(qryModel);
}
// =======================================================
void displayWindow :: on_pushButton_displayTeam_clicked()
{
    QSqlQueryModel* qryModel = new QSqlQueryModel();
    //ui->tableView->setAlternatingRowColors(true);
    qryModel->setQuery("SELECT Team FROM Teams ORDER BY Team");
    ui->tableView->setModel(qryModel);
}
// =======================================================
void displayWindow :: on_pushButton_displayStadium_clicked()
{
    QSqlQueryModel* qryModel = new QSqlQueryModel();
    //ui->tableView->setAlternatingRowColors(true);
    qryModel->setQuery("SELECT Name, Team FROM Teams ORDER BY Name");
    ui->tableView->setModel(qryModel);
}
// =======================================================
void displayWindow :: on_pushButton_AFC_clicked()
{
    QSqlQueryModel* qryModel = new QSqlQueryModel();
    //ui->tableView->setAlternatingRowColors(true);
    qryModel->setQuery("SELECT Team, Conference FROM Teams WHERE Conference LIKE '%American Football Conference%' ORDER BY Team");
    ui->tableView->setModel(qryModel);
}
// =======================================================
void displayWindow :: on_pushButton_NFC_clicked()
{
    QSqlQueryModel* qryModel = new QSqlQueryModel();
    //ui->tableView->setAlternatingRowColors(true);
    qryModel->setQuery("SELECT Team, Conference FROM Teams WHERE Conference LIKE '%National Football Conference%' ORDER BY Team");
    ui->tableView->setModel(qryModel);
}
// =======================================================
void displayWindow :: on_pushButton_NFCNORTH_clicked()
{
    QSqlQueryModel* qryModel = new QSqlQueryModel();
    //ui->tableView->setAlternatingRowColors(true);
    qryModel->setQuery("SELECT Team, Division FROM Teams WHERE Division LIKE 'NFC%North' ORDER BY Team");
    ui->tableView->setModel(qryModel);
}
// =======================================================
void displayWindow :: on_pushButton_openRoof_clicked()
{
    QSqlQueryModel* qryModel = new QSqlQueryModel();
    //ui->tableView->setAlternatingRowColors(true);
    qryModel->setQuery("SELECT Name,Team, RoofType FROM Teams WHERE RoofType LIKE '%open%' ORDER BY Name");
    ui->tableView->setModel(qryModel);

    QSqlQueryModel* qryModel2 = new QSqlQueryModel();
    qryModel2->setQuery("SELECT COUNT(DISTINCT Name) FROM Teams WHERE RoofType LIKE '%open%'");
    ui -> tableView_2 -> setModel(qryModel2);
}
// =======================================================
void displayWindow :: on_pushButton_stadiumByDate_clicked()
{
    QSqlQueryModel* qryModel = new QSqlQueryModel();
    //ui->tableView->setAlternatingRowColors(true);
    qryModel->setQuery("SELECT Name,Team, Opened FROM Teams ORDER BY Opened");
    ui->tableView->setModel(qryModel);
}
// =======================================================
void displayWindow :: on_pushButton_stadiumByCapacity_clicked()
{
    QSqlQueryModel* qryModel = new QSqlQueryModel();
    //ui->tableView->setAlternatingRowColors(true);
    qryModel->setQuery("SELECT Name,Team, Capacity FROM Teams ORDER BY Capacity");
    ui->tableView->setModel(qryModel);

    QSqlQueryModel* qryModel3 = new QSqlQueryModel();
    qryModel3->setQuery("SELECT SUM(Capacity) FROM Teams ");             // this query not working corretly
    ui -> tableView_2 -> setModel(qryModel3);
}
// =======================================================
void displayWindow :: on_pushButton_teamsByConf_clicked()
{
    QSqlQueryModel* qryModel = new QSqlQueryModel();
    //ui->tableView->setAlternatingRowColors(true);
    qryModel->setQuery("SELECT Team, Name, Conference, Location FROM Teams ORDER BY Conference");
    ui->tableView->setModel(qryModel);
}
// =======================================================
