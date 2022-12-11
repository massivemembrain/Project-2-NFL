#ifndef TOTALHOLDER_H
#define TOTALHOLDER_H

class TotalHolder
{
    int totalCost;
    int currentTeam = -1;

    void setTotal(int total)
    {
        totalCost += total;
        currentTeam++;
    }
};

#endif // TOTALHOLDER_H
