TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    binarynode.h \
    binarytree.h \
    node.h \
    binarysearchtree.h \
    dni.h

