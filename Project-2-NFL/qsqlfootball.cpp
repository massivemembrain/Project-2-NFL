#include "qsqlfootball.h"
#include <QSqlQuery>

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

const QSqlQueryModel* QSqlFootball::getTeams(const QString SEARCH_TERM,  const QString FILTER_TERM, const QString SORT_TERM) const
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
