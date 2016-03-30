TEMPLATE     = vcapp
TARGET       = Scorch
CONFIG      += warn_on qt debug_and_release windows console
HEADERS     += \
    include/Game/Cannon.h \
    include/Game/CannonBall.h \
    include/Game/Castle.h \
    include/Information/AngleStatusWidget.h \
    include/Information/EllipseAngleWidget.h \
    include/Information/FirePowerWidget.h \
    include/Information/GameModeWidget.h \
    include/Information/GradientBarWidget.h \
    include/Information/PlayerActivatedWidget.h \
    include/Information/PlayerControlModeWidget.h \
    include/Input/CommunicationFPGA.h \
    include/Input/FPGAEvent.h \
    include/Input/FPGAReceiver.h \
    include/GameBottomLayout.h \
    include/GameWindow.h

SOURCES     += \
    src/Game/Cannon.cpp \
    src/Game/CannonBall.cpp \
    src/Game/Castle.cpp \
    src/Information/AngleStatusWidget.cpp \
    src/Information/EllipseAngleWidget.cpp \
    src/Information/FirePowerWidget.cpp \
    src/Information/GameModeWidget.cpp \
    src/Information/GradientBarWidget.cpp \
    src/Information/PlayerActivatedWidget.cpp \
    src/Information/PlayerControlModeWidget.cpp \
    src/GameBottomLayout.cpp \
    src/GameWindow.cpp \
    src/main.cpp \
    src/Input/FPGAReceiver.cpp
INCLUDEPATH += include
LIBS	    += 
RESOURCES += 
QT += widgets core gui

