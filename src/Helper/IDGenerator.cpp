#include "D:\\Qt\include\Helper\IDGenerator.h"

int IDGenerator::m_currentID = 0;

int IDGenerator::generateID()
{
    return m_currentID++;
}
