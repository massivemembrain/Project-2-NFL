#ifndef TRAVELPLAN_H
#define TRAVELPLAN_H

#include <QSqlQueryModel>
#include <QString>
#include <QStackedWidget>
#include "graphClass.h"


class TravelPlan
{
public:
    struct ReceiptEntry
    {
        QString item;
        int quantity;
        int price;
    };
    struct Receipt
    {
      vector<ReceiptEntry> item_list;
      int total_expense;
    };
    //Graph<int> travel_graph;
    //Receipt receipt;
    TravelPlan();
    ~TravelPlan();
    void tripContinue();
    QSqlQueryModel getReceipt();
    int getTotalExpense();

    Graph<int> stadium_graph;
private:
    Receipt receipt;
    QStackedWidget* window;
};

#endif // TRAVELPLAN_H
