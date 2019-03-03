#-------------------------------------------------
#
# Project created by QtCreator 2017-07-18T18:08:59
#
#-------------------------------------------------

QT       += core gui
QT       += charts

CONFIG += c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DataChart
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        MainWindow.cpp \
    TimerTest.cpp \
    CustomerDataListModel.cpp \
    XML/DataAgent_Int.cpp \
    XML/XmlManager_EquipmentInfo.cpp \
    XML/Xml_SpotAddress.cpp \
    XML/Xml_EquipmentError.cpp \
    XML/Xml_EquipmentInfo.cpp \
    ChartForm.cpp

HEADERS += \
        MainWindow.h \
    TimerTest.h \
    CustomerDataListModel.h \
    CustomerData.h \
    XML/DataAgent_Int.h \
    XML/SpotAddress.h \
    XML/EquipmentInfo.h \
    XML/EquipmentError.h \
    XML/XmlManager_EquipmentInfo.h \
    XML/Xml_SpotAddress.h \
    XML/Xml_EquipmentError.h \
    XML/Xml_EquipmentInfo.h \
    ChartForm.h

FORMS += \
        MainWindow.ui \
    ChartForm.ui
