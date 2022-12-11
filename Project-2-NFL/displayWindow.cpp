#include "displayWindow.h"
#include "ui_displayWindow.h"

// ===========================================================
// Constructor
// ===========================================================
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

    myDb.setDatabaseName("../NFLProject.db");
    //myDb.setDatabaseName("/Users/nedamohseni/Documents/GitHub/Project-2-NFL/Project-2-NFL/NFLProject.db");
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
    ui->tableView->horizontalHeader() -> setSectionResizeMode(QHeaderView::ResizeToContents);

    qryModel->setQuery("SELECT * FROM Teams");
    ui->tableView->setModel(qryModel);

    // code for combobox options
    QSqlQueryModel* comboquery = new QSqlQueryModel();
    comboquery->setQuery("SELECT Team FROM Teams");
    ui->comboBox->setModel(comboquery);
}
// =======================================================
// destructor
// =======================================================
displayWindow::~displayWindow()
{
    delete ui;
}
// =======================================================
// display all info related to only one particular team
// =======================================================
void displayWindow :: on_pushButton_selectTeam_clicked()
{
    // stores the team selected in combobox in a variable
    QString selectedTeam = ui-> comboBox ->currentText();

    QSqlQueryModel* qryModel = new QSqlQueryModel();
    qryModel->setQuery("SELECT * FROM Teams WHERE Team LIKE '%"+selectedTeam +"%' ");
    ui->tableView->setModel(qryModel);
    ui->tableView_2->setModel(NULL);
}
// =======================================================
// display list of NFL Teams sorted by team name.
// =======================================================
void displayWindow :: on_pushButton_displayTeam_clicked()
{
    QSqlQueryModel* qryModel = new QSqlQueryModel();
    qryModel->setQuery("SELECT Team FROM Teams ORDER BY Team");
    ui->tableView->setModel(qryModel);
    ui->tableView_2->setModel(NULL);
}
// ==========================================================
// display list of all NFL stadiums and their corresponding
// team name sorted by stadium name.
// ==========================================================
void displayWindow :: on_pushButton_displayStadium_clicked()
{
    QSqlQueryModel* qryModel = new QSqlQueryModel();
    qryModel->setQuery("SELECT Name, Team FROM Teams ORDER BY Name");
    ui->tableView->setModel(qryModel);
    ui->tableView_2->setModel(NULL);
}
// ===========================================================
// display the list of only American football conference teams
// sorted by team name.
// ===========================================================
void displayWindow :: on_pushButton_AFC_clicked()
{
    QSqlQueryModel* qryModel = new QSqlQueryModel();
    qryModel->setQuery("SELECT Team, Conference FROM Teams WHERE Conference LIKE '%American Football Conference%' ORDER BY Team");
    ui->tableView->setModel(qryModel);
    ui->tableView_2->setModel(NULL);
}
// ===========================================================
// display the list of only National football conference teams
// sorted by team name.
// ===========================================================
void displayWindow :: on_pushButton_NFC_clicked()
{
    QSqlQueryModel* qryModel = new QSqlQueryModel();
    qryModel->setQuery("SELECT Team, Conference FROM Teams WHERE Conference LIKE '%National Football Conference%' ORDER BY Team");
    ui->tableView->setModel(qryModel);
    ui->tableView_2->setModel(NULL);
}
// ========================================================
// display list of only NFC north teams sorted by team name/
// ========================================================
void displayWindow :: on_pushButton_NFCNORTH_clicked()
{
    QSqlQueryModel* qryModel = new QSqlQueryModel();
    qryModel->setQuery("SELECT Team, Division FROM Teams WHERE Division LIKE 'NFC%North' ORDER BY Team");
    ui->tableView->setModel(qryModel);
    ui->tableView_2->setModel(NULL);
}
// ==================================================================
// display the list of stadiums that have an open roof type
// and their corresponding team name sorted by stadium name.
// display the number of stadiums that have open roof.
// (if two teams use the same stadium, count the open roof just once)
// ===================================================================
void displayWindow :: on_pushButton_openRoof_clicked()
{
    QSqlQueryModel* qryModel = new QSqlQueryModel();
    qryModel->setQuery("SELECT Name,Team, RoofType FROM Teams WHERE RoofType LIKE '%open%' ORDER BY Name");
    ui->tableView->setModel(qryModel);

    QSqlQueryModel* qryModel2 = new QSqlQueryModel();
    qryModel2->setQuery("SELECT COUNT(DISTINCT Name) FROM Teams WHERE RoofType LIKE '%open%' "
                        "                                             AND Team NOT LIKE 'San%Sailors'"); // excluding san diego
    ui -> tableView_2 -> setModel(qryModel2);
}
// ==============================================================
// display list of NFL stadiums and their corresponding team name
// in chronical order by date opened
// =============================================================
void displayWindow :: on_pushButton_stadiumByDate_clicked()
{
    QSqlQueryModel* qryModel = new QSqlQueryModel();
    qryModel->setQuery("SELECT Name,Team, Opened FROM Teams ORDER BY Opened");
    ui->tableView->setModel(qryModel);
    ui->tableView_2->setModel(NULL);
}
// =============================================================
// display list of NFL Stadiums and their corresponding team name
// sorted by seating capacity (smallest to largest).
// display total seating capacity of all Nfl Teams.
//(if two teams use the same stadium, count the capacity of the
// stadium only once)
// ==============================================================
void displayWindow :: on_pushButton_stadiumByCapacity_clicked()
{
    QSqlQueryModel* qryModel = new QSqlQueryModel();
    qryModel->setQuery("SELECT Name,Team, Capacity FROM Teams ORDER BY Capacity");
    ui->tableView->setModel(qryModel);

    QSqlQueryModel* qryModel3 = new QSqlQueryModel();
    qryModel3->setQuery("SELECT SUM(Capacity) FROM Teams WHERE Team NOT LIKE 'Los%Rams' " // counting SoFi once
                                                          "AND TEAM NOT LIKE 'New%Jets'"  //counting MetLife Once
                                                          "AND TEAM NOT LIKE 'San%Sailors'"); // excluding san diego sailor
    ui -> tableView_2 -> setModel(qryModel3);
}
// ==========================================================
// display List of Nfl teams, their stadium name, conference,
// location sorted by conference name.
// ==========================================================
void displayWindow :: on_pushButton_teamsByConf_clicked()
{
    QSqlQueryModel* qryModel = new QSqlQueryModel();
    qryModel->setQuery("SELECT Team, Name, Conference, Location FROM Teams ORDER BY Conference");
    ui->tableView->setModel(qryModel);
    ui->tableView_2->setModel(NULL);
}
// =======================================================
// display souvenir list related to only one particular team
// =======================================================
void displayWindow::on_pushButton_displaySouvenir_clicked()
{
    // stores the team selected in combobox in a variable
    QString selectedTeam = ui-> comboBox ->currentText();

    QSqlQueryModel* qryModel = new QSqlQueryModel();
    qryModel->setQuery("SELECT * FROM Souvenirs WHERE Team LIKE '%"+selectedTeam +"%' ");
    ui->tableView->setModel(qryModel);
    ui->tableView_2->setModel(NULL);
}
// =======================================================
// display total seating capacity for all NFL teams
// =======================================================
void displayWindow::on_pushButton_totalseatcapacity_clicked()
{
    QSqlQueryModel* qryModel = new QSqlQueryModel();
    qryModel->setQuery("SELECT SUM(Capacity) FROM Teams");
    qryModel->setHeaderData(0, Qt::Horizontal, QObject::tr("total seating capacity"));
    ui->tableView->setModel(qryModel);
    ui->tableView_2->setModel(NULL);
}
// ======================================================================
// list and display count of Nfl teams whose surface type is Bermuda Grass
// ======================================================================
void displayWindow::on_pushButton_bermudaGrass_clicked()
{
    QSqlQueryModel* qryModel = new QSqlQueryModel();
    qryModel->setQuery("SELECT Team, Name, Surface FROM Teams WHERE Surface LIKE 'Bermuda%grass'");
    ui->tableView->setModel(qryModel);

    QSqlQueryModel* qryModel4 = new QSqlQueryModel();
    qryModel4->setQuery("SELECT COUNT(Team) FROM Teams WHERE Surface LIKE 'Bermuda%grass'");
    ui -> tableView_2 -> setModel(qryModel4);
}
