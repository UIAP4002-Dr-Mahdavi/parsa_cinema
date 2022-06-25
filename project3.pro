#-------------------------------------------------
#
# Project created by QtCreator 2022-06-20T19:25:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = project3
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        actor.cpp \
        addfilm.cpp \
        buy_ticket.cpp \
        dialoglogin.cpp \
        edit_information.cpp \
        film.cpp \
        history_show.cpp \
        list.cpp \
        main.cpp \
        mainwindow.cpp \
        registration.cpp \
        remove_film.cpp \
        temp.cpp \
        tmpactor.cpp \
        tmpfilm.cpp \
        user.cpp \
        usertickets.cpp

HEADERS += \
        actor.h \
        addfilm.h \
        buy_ticket.h \
        dialoglogin.h \
        edit_information.h \
        film.h \
        history_show.h \
        list.h \
        mainwindow.h \
        registration.h \
        remove_film.h \
        temp.h \
        tmpactor.h \
        tmpfilm.h \
        user.h \
        usertickets.h

FORMS += \
        addfilm.ui \
        buy_ticket.ui \
        dialoglogin.ui \
        edit_information.ui \
        history_show.ui \
        list.ui \
        mainwindow.ui \
        registration.ui \
        remove_film.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
