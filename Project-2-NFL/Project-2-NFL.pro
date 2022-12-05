QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    bfs.cpp \
    displayWindow.cpp \
    form.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    mst.cpp \
    qsqlfootballClass.cpp \
    travelgraphClass.cpp \
    travelplanClass.cpp \
    tripcreateWidget.cpp \
    tripprogressWidget.cpp \
    tripsummaryWidget.cpp

HEADERS += \
    admin.h \
    bfs.h \
    displayWindow.h \
    form.h \
    graphClass.h \
    login.h \
    mainwindow.h \
    mst.h \
    qsqlfootballClass.h \
    travelgraphClass.h \
    travelplanClass.h \
    tripcreateWidget.h \
    tripprogressWidget.h \
    tripsummaryWidget.h

FORMS += \
    admin.ui \
    bfs.ui \
    displayWindow.ui \
    form.ui \
    login.ui \
    mainwindow.ui \
    mst.ui \
    tripcreateWidget.ui \
    tripprogressWidget.ui \
    tripsummaryWidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
