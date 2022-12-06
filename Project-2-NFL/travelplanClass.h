#ifndef TRAVELPLAN_H
#define TRAVELPLAN_H

#include <QSqlQueryModel>
#include <QString>
#include <QStackedWidget>
//#include "graphClass.h"

using namespace std;

class TravelPlan
{
public:
    struct ReceiptEntry
    {
        QString item;
        int quantity = 0;
        int price = 0;
    };
    struct CityReceipt
    {
      QString city_name;
      vector<ReceiptEntry> item_list;
      int total_expense = 0;
    };
    typedef vector<CityReceipt> TripReceipt;

    //Graph<int> travel_graph;
    //Receipt receipt;
    TravelPlan();
    ~TravelPlan();
    void tripContinue();
    QSqlQueryModel getReceipt();
    int getTotalExpense();

    void setWidget(int index);
    //Graph<int> stadium_graph;
private:
    TripReceipt receipt;
    QStackedWidget* window;
    vector<QString> team_destinations;
    vector<QString>::iterator current_team;
};

#endif // TRAVELPLAN_H
