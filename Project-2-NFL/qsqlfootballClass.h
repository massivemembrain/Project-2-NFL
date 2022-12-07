#ifndef QSQLFOOTBALLCLASS_H
#define QSQLFOOTBALLCLASS_H

#include <vector>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQueryModel>


/*****************************************************************//**
 * \file   qSqlFootball.h
 * \brief  QSqlFootball get infos from data base
 *
 *
 * \date   December 2022
 *********************************************************************/

using namespace std;

/**
 * \class QSqlFootball
 * \brief QSqlFootball get infos from data base
 */
class QSqlFootball
{
private:
    static QSqlDatabase db;
    QString team_list[30];
public:
    static void initDB();
    QSqlFootball();
    ~QSqlFootball();
    /** getInfo
     * Story #2
     * Return all info for one team in a QWidget
     */
    const QSqlQueryModel* getTeamInfo(const QString TEAM_NAME) const;
    /** getAllTeams
     * Story #3, 5, 7
     * Teams are sorted alphabetically.
     */
    QSqlQueryModel* getTeams(const QString SEARCH_TERM = "*",  const QString FILTER_TERM = "Team", const QString SORT_TERM = "Team") const;
    /** getInfo
     * Story #2
     * Return all info for one team in a QWidget
     */
    const QSqlQueryModel* getStadiumInfo(const QString STADIUM_NAME) const;
    /** getAllStadiums
     * Story #4, 8
     * Stadiums are sorted alphabetically. Each stadium's corresponding team(s) are stored in
     */
    QSqlQueryModel* getStadiums(const QString SEARCH_TERM = "*",  const QString FILTER_TERM = "Name", const QString SORT_TERM = "Name") const;
    /** getAllTeams
     * Story #9
     * Teams are sorted alphabetically. Each team's corresponding stars
     */
    QSqlQueryModel* getAllTeamsStars() const;
    /** getAllTeams
     * Story #9
     * Teams are sorted alphabetically. Each team's corresponding stars
     */
    QSqlQueryModel* getTeamSouvenirs(const QString TEAM_NAME = "*") const;

    // Setters
    //void addSouvenir(const QString NAME, const QString PRICE = "0.00", const QString TEAM = "*");
    void modifySouvenirPrice(QString NAME, const QString NEW_PRICE, QString TEAM = "*");
    //void removeSouvenir(const QString NAME, const QString TEAM = "*");
    // import
    void importCSV();
    void importCSV(QString path);
};

#endif // QSQLFOOTBALLCLASS_H
