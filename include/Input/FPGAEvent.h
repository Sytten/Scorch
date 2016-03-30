#ifndef FPGAEVENT_H
#define FPGAEVENT_H

#include <QEvent>

enum Command {Change, Increase, Decrease};

class FPGAEvent : public QEvent
{
public:
    FPGAEvent(Command p_command) : QEvent(FPGAEvent::type()), m_command(p_command) {}

    Command command() {return m_command;}

    static const QEvent::Type customFPGAEvent = static_cast<QEvent::Type>(2000);

private:
    Command m_command;
};

#endif // FPGAEVENT_H
