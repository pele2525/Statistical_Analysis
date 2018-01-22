TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    filefetcher.cpp \
    analyzedata.cpp \
    jsonparser.cpp

HEADERS += \
    filefetcher.h \
    analyzedata.h \
    jsonparser.h
