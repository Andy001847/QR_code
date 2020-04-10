#-------------------------------------------------
#
# Project created by QtCreator 2019-08-14T15:29:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TwoDimensionCode
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += HAVE_CONFIG_H

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        libqrencode-4.0.2/bitstream.c \
        libqrencode-4.0.2/mask.c \
        libqrencode-4.0.2/mmask.c \
        libqrencode-4.0.2/mqrspec.c \
        libqrencode-4.0.2/qrencode.c \
        libqrencode-4.0.2/qrinput.c \
        libqrencode-4.0.2/qrspec.c \
        libqrencode-4.0.2/rsecc.c \
        libqrencode-4.0.2/split.c \
        main.cpp \
        TwoDimensionCode.cpp

HEADERS += \
        TwoDimensionCode.h \
        libqrencode-4.0.2/bitstream.h \
        libqrencode-4.0.2/config.h \
        libqrencode-4.0.2/mask.h \
        libqrencode-4.0.2/mmask.h \
        libqrencode-4.0.2/mqrspec.h \
        libqrencode-4.0.2/qrencode.h \
        libqrencode-4.0.2/qrencode_inner.h \
        libqrencode-4.0.2/qrinput.h \
        libqrencode-4.0.2/qrspec.h \
        libqrencode-4.0.2/rsecc.h \
        libqrencode-4.0.2/split.h

FORMS += \
        TwoDimensionCode.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
