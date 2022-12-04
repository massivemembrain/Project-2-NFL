QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    displayWindow.cpp \
    form.cpp \
    main.cpp \
    mainwindow.cpp \
    mst.cpp \
    qsqlfootballClass.cpp \
    travelplanClass.cpp \
    tripcreateWidget.cpp

HEADERS += \
    admin.h \
    displayWindow.h \
    form.h \
    graphClass.h \
    mainwindow.h \
    mst.h \
    qsqlfootballClass.h \
    travelplanClass.h \
    tripcreateWidget.h

FORMS += \
    admin.ui \
    displayWindow.ui \
    form.ui \
    mainwindow.ui \
    mst.ui \
    tripcreateWidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
