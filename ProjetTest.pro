TARGET       = Scorch
CONFIG      += warn_on qt debug_and_release windows console c++11
HEADERS     += \
    include/Game/Cannon.h \
    include/Game/CannonBall.h \
    include/Game/Castle.h \
    include/Game/Entity.h \
    include/Game/Game.h \
    include/Game/Player.h \
    include/Game/State.h \
	include/Game/PauseOverlay.h \
    include/Game/GameOverlay.h \
    include/Information/AngleStatusWidget.h \
    include/Information/EllipseAngleWidget.h \
    include/Information/FirePowerWidget.h \
    include/Information/GameModeWidget.h \
    include/Information/GradientBarWidget.h \
    include/Information/PlayerActivatedWidget.h \
    include/Information/PlayerControlModeWidget.h \
    include/Input/FPGAEvent.h \
    include/Input/FPGAReceiver.h \
    include/GameBottomLayout.h \
    include/GameWindow.h \
    include/SecondaryWindows.h \
    include/Game/State.h \
    include/Game/Player.h \
	include/Terrain/Terrain.h

SOURCES     += \
    src/Game/Cannon.cpp \
    src/Game/CannonBall.cpp \
    src/Game/Castle.cpp \
    src/Game/Game.cpp \
    src/Game/Entity.cpp \
    src/Game/PauseOverlay.cpp \
    src/Game/GameOverlay.cpp \
    src/Information/AngleStatusWidget.cpp \
    src/Information/EllipseAngleWidget.cpp \
    src/Information/FirePowerWidget.cpp \
    src/Information/GameModeWidget.cpp \
    src/Information/GradientBarWidget.cpp \
    src/Information/PlayerActivatedWidget.cpp \
    src/Information/PlayerControlModeWidget.cpp \
    src/GameBottomLayout.cpp \
    src/GameWindow.cpp \
    src/SecondaryWindows.cpp \
    src/main.cpp \
    src/Input/FPGAReceiver.cpp \
	src/Terrain/Terrain.cpp	
INCLUDEPATH += include
win32{
    TEMPLATE     = vcapp
    LIBS += lib/CommunicationFPGA.lib
    HEADERS += lib/CommunicationFPGA.h
    INCLUDEPATH += lib
}
RESOURCES += Resources.qrc
QT += widgets core gui

