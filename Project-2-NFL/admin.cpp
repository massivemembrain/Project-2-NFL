#include "admin.h"
#include "ui_admin.h"

Admin::Admin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
    ui->comboBox->addItem("None");
    ui->comboBox->addItem("Arizona Cardinals");
    ui->comboBox->addItem("Atlanta Falcons");
    ui->comboBox->addItem("Baltimore Ravens");
    ui->comboBox->addItem("Buffalo Bills");
    ui->comboBox->addItem("Carolina Panthers");
    ui->comboBox->addItem("Chicago Bears");
    ui->comboBox->addItem("Cincinnati Bengals");
    ui->comboBox->addItem("Cleveland Browns");
    ui->comboBox->addItem("Dallas Cowboys");
    ui->comboBox->addItem("Denver Broncos");
    ui->comboBox->addItem("Detroit Lions");
    ui->comboBox->addItem("Green Bay Packers");
    ui->comboBox->addItem("Houston Texans");
    ui->comboBox->addItem("Indianapolis Colts");
    ui->comboBox->addItem("Jacksonville Jaguars");
    ui->comboBox->addItem("Kansas City Chiefs");
    ui->comboBox->addItem("Las Vegas Raiders");
    ui->comboBox->addItem("Los Angeles Chargers");
    ui->comboBox->addItem("Los Angeles Rams");
    ui->comboBox->addItem("Miami Dolphins");
    ui->comboBox->addItem("Minnesota Vikings");
    ui->comboBox->addItem("New England Patriots");
    ui->comboBox->addItem("New Orleans Saints");
    ui->comboBox->addItem("New York Giants");
    ui->comboBox->addItem("New York Jets");
    ui->comboBox->addItem("Philadelphia Eagles");
    ui->comboBox->addItem("Pittsburgh Steelers");
    ui->comboBox->addItem("San Francisco 49ers");
    ui->comboBox->addItem("Seattle Seahawks");
    ui->comboBox->addItem("Tampa Bay Buccaneers");
    ui->comboBox->addItem("Tennessee Titans");
    ui->comboBox->addItem("Washington Commanders");



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

    qryModel->setQuery("SELECT * FROM Teams");
    ui->tableView->setModel(qryModel);
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_comboBox_activated(int index)
{

}

