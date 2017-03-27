TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    unique_ptr.cpp \
    shared_ptr.cpp

HEADERS += \
    unique_ptr.h \
    shared_ptr.h
