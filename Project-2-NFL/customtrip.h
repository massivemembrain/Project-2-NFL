#ifndef CUSTOMTRIP_H
#define CUSTOMTRIP_H
#include "tripcreateWidget.h"

struct customCity{
    std::string name;
    std::vector<int> distances;
    std::vector<customCity*> city_signs;
};

class CustomTrip
{
public:
    CustomTrip();

    void fullMap(QString start, int numberOfCities);


    std::vector<customCity*> cities;
    std::vector<customCity> visited;
    std::vector<int> distances_travelled;
    int num_of_cities;
};

#endif // CUSTOMTRIP_H
