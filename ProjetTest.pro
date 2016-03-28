TEMPLATE     = vcapp
TARGET       = Scorch
CONFIG      += warn_on qt debug_and_release windows console
HEADERS     += include/GameWindow.h \
			   include/FirePowerWidget.h \
			   include/GradientBarWidget.h \
			   include/AngleStatusWidget.h \
			   include/EllipseAngleWidget.h \
			   include/GameBottomLayout.h \
			   include/GameModeWidget.h \
			   include/PlayerActivatedWidget.h \
			   include/PlayerControlModeWidget.h
SOURCES     += main.cpp \
			   src/GameWindow.cpp \
			   src/FirePowerWidget.cpp \
			   src/GradientBarWidget.cpp \
			   src/AngleStatusWidget.cpp \
			   src/EllipseAngleWidget.cpp \
			   src/GameBottomLayout.cpp \
			   src/GameModeWidget.cpp \
			   src/PlayerActivatedWidget.cpp \
			   src/PlayerControlModeWidget.cpp
INCLUDEPATH += include
LIBS	    += 
RESOURCES += 
QT += widgets core gui

