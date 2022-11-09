#include "qsqlfootball.h"
#include <QSqlQuery>
#include <QDebug>

QSqlFootball::QSqlFootball()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./NFLProject.db");
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
    qDebug() << SEARCH_TERM;
    // Prepare query
//    QSqlQuery query;
//    query.prepare("SELECT :search_term FROM :filter_term ORDER BY :soprt_term");
//    query.bindValue(":search_term", SEARCH_TERM);
//    query.bindValue(":filter_term", FILTER_TERM);
//    query.bindValue(":sort_term", SORT_TERM);
//    query.exec();

//    while(query.next()){
//        QString obj = query.value(0).toString();
//        qDebug() << obj;
//    }
    QSqlQueryModel* team_table = new QSqlQueryModel;
    team_table->setQuery("SELECT * FROM Team(s)");//query.executedQuery());
    //team_table->setHeaderData(0, Qt::Horizontal, "Name");

    qDebug("Finished search.");

    return team_table;
}
