/********
File: FPGAEvent.h
Authors: Émile Fugulin, Jean-Philippe Fournier, Philippe Spino, Julien Larochelle
Date: 06 avril 2016
Description: Costum event sent by the FPGAReceiver to notify the program about new inputs
********/

#ifndef FPGAEVENT_H
#define FPGAEVENT_H

#include <QEvent>

enum Command {Change, Increase, Decrease, None};

class FPGAEvent : public QEvent
{
public:
    FPGAEvent(Command p_command) : QEvent(FPGAEvent::type()), m_command(p_command) {}
    FPGAEvent(FPGAEvent& other) : QEvent(FPGAEvent::type()), m_command(other.m_command) {}

    Command command() {return m_command;}

    QEvent::Type type() const { return customFPGAEvent; }

    static const QEvent::Type customFPGAEvent = static_cast<QEvent::Type>(2000);

private:
    Command m_command;
};

#endif // FPGAEVENT_H
