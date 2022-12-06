#include <QWidget>
#include "travelplanClass.h"
#include "tripcreateWidget.h"
#include "tripprogressWidget.h"
#include "tripsummaryWidget.h"

TravelPlan::TravelPlan()
    : receipt{}//, stadium_graph("Distances")
{
    window = new QStackedWidget;
    window->addWidget(new TripCreateWidget);
    window->addWidget(new TripProgressWidget);
    window->addWidget(new TripSummaryWidget);

    window->setMinimumSize(640, 480);
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

void TravelPlan::setWidget(int index)
{
    window->setCurrentIndex(index);
}
