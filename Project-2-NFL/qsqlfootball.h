#ifndef QSQLFOOTBALL_H
#define QSQLFOOTBALL_H

#include <vector>
#include <QString>
#include <QSqlDatabase>
#include <QWidget>

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
    const QWidget getInfo(const QString TEAM_NAME) const;
    /** getAllTeams
     * Story #3
     * Teams are sorted alphabetically.
     */
    const QWidget getAllTeams() const;
    /** getAllStadiums
     * Story #4
     * Stadiums are sorted alphabetically. Each stadium's corresponding team(s) are stored in
     */
    const QWidget getAllStadiumsSortBy(const QString TEAM_NAME, const QString SORT_TERM = "alphabetical") const;
    /** getInfo
     * Story #5
     * Teams are sorted alphabetically.
     */
    const QWidget getTeamsFilterByConference(const QString CONFERENCE_NAME) const;
    /** getInfo
     * Story #7
     * Teams are sorted alphabetically.
     */
    const QWidget getTeamsFilterByDivision(const QString TEAM_NAME) const;
    /** getInfo
     * Story #8
     * Stadiums are sorted alphabetically. Each stadium's corresponding team(s) are stored in
     */
    const QWidget getStadiumsFilterByRoof(const QString STADIUM_ROOF_TYPE) const;
    /** getAllTeams
     * Story #9
     * Teams are sorted alphabetically. Each team's corresponding stars
     */
    const QWidget getAllTeamsStars() const;

};

#endif // QSQLFOOTBALL_H
