QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    bfs.cpp \
    dfs.cpp \
    dijkstra.cpp \
    displayWindow.cpp \
    login.cpp \
    #login_mainwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    mst.cpp \
    orderedtrip.cpp \
    plantrip.cpp \
    qsqlfootballClass.cpp \
    shortestDistance.cpp \
    travelgraphClass.cpp \
    travelplanClass.cpp \
    tripcreateWidget.cpp \
    tripprogressWidget.cpp \
    tripsummaryWidget.cpp

HEADERS += \
    admin.h \
    bfs.h \
    dfs.h \
    dijkstra.h \
    displayWindow.h \
    graphClass.h \
    login.h \
    #login_mainwindow.h \
    mainwindow.h \
    mst.h \
    orderedtrip.h \
    plantrip.h \
    qsqlfootballClass.h \
    shortestDistance.h \
    travelgraphClass.h \
    travelplanClass.h \
    tripcreateWidget.h \
    tripprogressWidget.h \
    tripsummaryWidget.h

FORMS += \
    admin.ui \
    bfs.ui \
    dfs.ui \
    dijkstra.ui \
    displayWindow.ui \
    login.ui \
    #login_mainwindow.ui \
    mainwindow.ui \
    mst.ui \
    orderedtrip.ui \
    planTrip.ui \
    shortestDistance.ui \
    tripcreateWidget.ui \
    tripprogressWidget.ui \
    tripsummaryWidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
