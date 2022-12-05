#include <QWidget>
#include "travelplanClass.h"
#include "tripcreateWidget.h"

TravelPlan::TravelPlan()
    : stadium_graph("Distances"), receipt{Receipt()}
{
    window = new QStackedWidget;
    window->addWidget(new TripCreateWidget);
    window->show();
}
TravelPlan::~TravelPlan()
{
    QWidget* widget = nullptr;
    for(int i = window->count() - 1; i >= 0; i--)
    {
        widget = window->widget(i);
        window->removeWidget(widget);
        widget->deleteLater();
    }
    window->deleteLater();
}
