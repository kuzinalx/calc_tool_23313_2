#-------------------------------------------------
#
# Project created by QtCreator 2015-03-14T19:04:51
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = calc_tool
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    integrate.cpp \
    solve_ode.cpp \
    solve_alg_eqv.cpp \
    expression_calc.cpp

HEADERS += \
    mode_functions.h \
    expression_calc.h \
    calc_tool_exception.h
