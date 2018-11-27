QT += core
QT -= gui

CONFIG += c++11

TARGET = insectacolony
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += src/main/cpp/ants/ant.cpp \
    src/main/cpp/ants/beetle.cpp \
    src/main/cpp/ants/namegenerator.cpp \
    src/main/cpp/ants/colony.cpp \
    src/main/cpp/ants/util.cpp \
    src/main/cpp/ants/room.cpp \
    src/main/cpp/ants/insect.cpp \
    src/main/cpp/ants/state.cpp \
    src/main/cpp/ants/namedentity.cpp \
    src/main/cpp/ants/insectacolony.cpp
    
HEADERS += src/main/cpp/ants/ant.h \
    src/main/cpp/ants/beetle.h \
    src/main/cpp/ants/colony.h \
    src/main/cpp/ants/insect.h \
    src/main/cpp/ants/insecttestsuite.h \
    src/main/cpp/ants/namedentity.h \
    src/main/cpp/ants/namegenerator.h \
    src/main/cpp/ants/room.h \
    src/main/cpp/ants/roomnames.h \
    src/main/cpp/ants/state.h \
    src/main/cpp/ants/util.h
