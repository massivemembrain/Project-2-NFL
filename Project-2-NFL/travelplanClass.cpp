#include "travelplanClass.h"

TravelPlan::TravelPlan()
    : stadiumGraph{Graph<int>("Distances")}, receipt{Receipt()}
{

}
TravelPlan::~TravelPlan()
{

}
