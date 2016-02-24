#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "Inputs/FPGAReceiver.h"
#include "Inputs/Input.h"

class InputHandler
{
    public:
        InputHandler();

        Input getCurrentInput();

    private:
        FPGAReceiver m_inputReceiver;
};

#endif // INPUTHANDLER_H
