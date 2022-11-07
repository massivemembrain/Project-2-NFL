#include "qsqlfootball.h"

QSqlFootball::QSqlFootball()
{
db.open();
}
QSqlFootball::~QSqlFootball()
{
    db.close();
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
