TEMPLATE = app

TARGET = tst_qrenderstate

QT += core-private 3dcore 3dcore-private 3drender 3drender-private testlib

CONFIG += testcase

SOURCES += tst_qrenderstate.cpp

include(../../core/common/common.pri)
include(../commons/commons.pri)
