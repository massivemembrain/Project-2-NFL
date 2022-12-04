#ifndef TRAVELPLAN_H
#define TRAVELPLAN_H

#include <QSqlQueryModel>
#include <QString>
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
    void tripWindow();
    QSqlQueryModel getReceipt();
    int getTotalExpense();

    Graph<int> stadiumGraph;
private:
    Receipt receipt;
};

#endif // TRAVELPLAN_H
