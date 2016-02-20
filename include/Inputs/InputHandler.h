#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "D://Qt/include/Inputs/FPGAReceiver.h"
#include "D://Qt/include/Inputs/Input.h"

class InputHandler
{
    public:
        InputHandler();

        Input getCurrentInput();

    private:
        FPGAReceiver m_inputReceiver;
};

#endif // INPUTHANDLER_H
