#ifndef QSQLFOOTBALL_H
#define QSQLFOOTBALL_H

#include <vector>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQueryModel>

using namespace std;


class QSqlFootball
{
private:
    QSqlDatabase db;
    QString team_list[30];
public:
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
    QSqlQueryModel* getTeams(const QString SEARCH_TERM = "*",  const QString FILTER_TERM = "Team(s)", const QString SORT_TERM = "team_name") const;
    /** getAllStadiums
     * Story #4, 8
     * Stadiums are sorted alphabetically. Each stadium's corresponding team(s) are stored in
     */
    const QSqlQueryModel* getStadiums(const QString SEARCH_TERM = "*",  const QString FILTER_TERM = "Team(s)", const QString SORT_TERM = "team_name") const;
    /** getAllTeams
     * Story #9
     * Teams are sorted alphabetically. Each team's corresponding stars
     */
    const QSqlQueryModel* getAllTeamsStars() const;
    /** getAllTeams
     * Story #9
     * Teams are sorted alphabetically. Each team's corresponding stars
     */
    const QSqlQueryModel* getAllTeamsSouveniers() const;

};

#endif // QSQLFOOTBALL_H
