TEMPLATE = app

TARGET = tst_inputsequence

QT += core-private 3dcore 3dcore-private 3dinput 3dinput-private testlib

CONFIG += testcase

SOURCES += tst_inputsequence.cpp

include(../commons/commons.pri)
