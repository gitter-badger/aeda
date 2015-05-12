TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    binarytree.h \
    dni.h \
    node.h \
    random.h \
    avlnode.h

