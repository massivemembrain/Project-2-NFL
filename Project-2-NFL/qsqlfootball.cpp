#include "qsqlfootball.h"
#include <QSqlQuery>
#include <QFile>
#include <QFileDialog>

QSqlFootball::QSqlFootball()
{
    if(QSqlDatabase::contains("qt_sql_default_connection"))
    {
        db = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        db = QSqlDatabase::addDatabase("QSQLITE");
    }
    db.setDatabaseName("../NFLProject.db");
    if(db.open())
    {
        qDebug("Database opened.");
    }
    else
    {
        qDebug("Database not opened.");
    }
}
QSqlFootball::~QSqlFootball()
{
    db.close();
    qDebug("Database closed.");
}
/*** Info for SQL helper functions ***/
// return QWidget or leave comment on why not
/** Football Team Data
 *
 * QString team_name;
 * QString team_conference;
 * QString team_division;
 * QString team_star_player;
 *
 * QString stadium_name;
 * int stadium_capacity;
 * QString stadium_location;
 * QString stadium_surface_type;
 * QString stadium_roof_type;
 *
 */

QSqlQueryModel* QSqlFootball::getTeams(const QString SEARCH_TERM,  const QString FILTER_TERM, const QString SORT_TERM) const
{
    // Prepare query
    QString query;
    if(SEARCH_TERM == "*")
    {
        query = "SELECT * FROM Teams ORDER BY :sort_term";
    }
    else
    {
        query = "SELECT * FROM Teams WHERE :filter_term = :search_term ORDER BY :sort_term";
        query.replace(":search_term", SEARCH_TERM);
        query.replace(":filter_term", FILTER_TERM);
    }

    query.replace(":sort_term", SORT_TERM);
    qDebug() << "Query:" << query;

    QSqlQueryModel* team_table = new QSqlQueryModel;
    team_table->setQuery(query);//"SELECT * FROM Teams ORDER BY Team");//query.executedQuery());
    //team_table->setHeaderData(0, Qt::Horizontal, "Name");

    qDebug("Finished query.");

    return team_table;
}

QSqlQueryModel* QSqlFootball::getStadiums(const QString SEARCH_TERM,  const QString FILTER_TERM, const QString SORT_TERM) const
{
    // Prepare query
    QString query;
    if(SEARCH_TERM == "*")
    {
        query = "SELECT * FROM Teams ORDER BY :sort_term";
    }
    else
    {
        query = "SELECT Team, Name FROM Teams WHERE :filter_term = :search_term ORDER BY :sort_term";
        query.replace(":search_term", SEARCH_TERM);
        query.replace(":filter_term", FILTER_TERM);
    }

    query.replace(":sort_term", SORT_TERM);
    qDebug() << "Query:" << query;

    QSqlQueryModel* stadium_table = new QSqlQueryModel;
    stadium_table->setQuery(query);//"SELECT * FROM Teams ORDER BY Team");//query.executedQuery());
    //team_table->setHeaderData(0, Qt::Horizontal, "Name");

    qDebug("Finished query.");

    return stadium_table;
}
 int NUM_SOU = 5;
QSqlQueryModel* QSqlFootball::getTeamSouvenirs(const QString TEAM_NAME) const
{
    // Prepare query
    QString query_default;
    QSqlQueryModel* souvenir_table = new QSqlQueryModel;
    if(TEAM_NAME == "*")
    {
        query_default = "SELECT * FROM Souvenirs ORDER BY Team";
    }
    else
    {
         //query = "SELECT DISTINCT price, FIRST_VALUE(Price) OVER (PARTITION BY Name ORDER BY Team)Price FROM Souvenirs WHERE Team IN (:team_name, *)";
        //query = "SELECT Name, Price FROM Souvenirs CASE WHEN THEN END ORDER BY Team;";
        //query.replace(":team_name", TEAM_NAME);

        query_default = "SELECT Name, Price FROM Souvenirs WHERE EXISTS (SELECT Team FROM Souvenirs WHERE Team = 0";
        QSqlQuery query_override("SELECT Name, Price FROM Souvenirs WHERE EXISTS (SELECT Team FROM Souvenirs WHERE Team = :team_name");
        query_override.bindValue(":team_name", TEAM_NAME);


        souvenir_table->setQuery(query_default);
        //query_default.exec();
        query_override.exec();

        int name_field = 0;//query_default.record().indexOf("Name");
        int price_field = 1;//query_default.record().indexOf("Name");
        while(query_override.next())
        {
            //query_default.value("Name").toString();
        }
          //      qDebug() << result.lastError();
        /*int team_field = 2;//result.record().indexOf("Team");
        while (result.next()) {
            QString country = result.value(team_field).toString();
            //doSomething(country);
        }*/


    }

    qDebug() << "Query:" << query;


    //team_table->setHeaderData(0, Qt::Horizontal, "Name");

    qDebug("Finished query.");

    return souvenir_table;
}
// Setters
//void addSouvenir(const QString NAME, const QString PRICE, const QString TEAM) {}
void modifySouvenirPrice(QString NAME, const QString NEW_PRICE, QString TEAM)
{}
//void removeSouvenir(const QString NAME, const QString TEAM) {}
// Import
void importCSV()
{
    QFileDialog file_window;


}
void importCSV(QString path)
{

}
