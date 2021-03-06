#-------------------------------------------------
#
# Project created by QtCreator 2020-03-28T16:05:25
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = stepper_motor_control
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

QMAKE_CXXFLAGS += -std=c++17
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(view/include_view.pri)
include(model/include_model.pri)
include(controller/include_controller.pri)

SOURCES += \
        main.cpp \
        view/mainwindow.cpp \
        view/view.cpp\
        model/tsp_client.cpp\
        model/model.cpp\
        controller/controller.cpp


HEADERS += \
        view/mainwindow.h \
        view/view.h\
        model/tsp_client.h\
        model/model.h\
        controller/controller.h

FORMS += \
        view/mainwindow.ui

RESOURCES += \
    view/resource/resource.qrc
