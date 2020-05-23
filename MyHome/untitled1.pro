#-------------------------------------------------
#
# Project created by QtCreator 2018-03-12T00:32:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Begin
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


SOURCES += .cpp/main.cpp\
        .cpp/error.cpp \
        .cpp/qingccc.cpp \
        .cpp/sorry.cpp \
        .cpp/ui1.cpp \
        .cpp/welcome1.cpp \
        .cpp/widget.cpp

HEADERS  += .h/widget.h \
    .h/BigInt_multiply.h \
    .h/error.h \
    .h/qingccc.h \
    .h/sorry.h \
    .h/ui1.h \
    .h/welcome1.h

FORMS    += .ui/widget.ui \
    .ui/error.ui \
    .ui/qingccc.ui \
    .ui/sorry.ui \
    .ui/ui1.ui \
    .ui/welcome1.ui

RESOURCES += \
    res.qrc


RC_FILE +=tubiao.rc
