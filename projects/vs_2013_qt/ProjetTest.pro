TEMPLATE     = vcapp
TARGET       = Scorch
CONFIG      += warn_on qt debug_and_release windows console
HEADERS     += GameWindow.h FirePowerWidget.h GradientBarWidget.h AngleStatusWidget.h EllipseAngleWidget.h
SOURCES     += main.cpp GameWindow.cpp FirePowerWidget.cpp GradientBarWidget.cpp AngleStatusWidget.cpp EllipseAngleWidget.cpp
INCLUDEPATH += 
LIBS	    += 
RESOURCES += 
QT += widgets core gui

