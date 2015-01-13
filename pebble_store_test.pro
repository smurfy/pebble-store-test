#-------------------------------------------------
#
# Project created by QtCreator 2015-01-13T00:38:25
#
#-------------------------------------------------

QT       += webkitwidgets network core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pebble_store_test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        pebblestoreview.cpp \
        pebblewebpage.cpp

HEADERS  += mainwindow.h \
        pebblestoreview.h \
        pebblewebpage.h

FORMS    += mainwindow.ui
