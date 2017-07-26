#-------------------------------------------------
#
# Project created by QtCreator 2016-12-18T22:08:47
#
#-------------------------------------------------

QT       += core gui
QT += charts
QT += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = serialPortTest_4_0
TEMPLATE = app


SOURCES += main.cpp \
    ChartWindow.cpp \
    CheckWindow.cpp \
    CustomChart.cpp \
    CustomCOM.cpp \
    ErrorWidget.cpp

HEADERS  += \
    ChartWindow.h \
    CheckWindow.h \
    CustomChart.h \
    CustomCOM.h \
    ErrorWidget.h
