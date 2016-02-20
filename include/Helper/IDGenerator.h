#ifndef IDGENERATOR_H
#define IDGENERATOR_H


class IDGenerator
{
    public:
        static int generateID();

    private:
        static int m_currentID;
};

#endif // IDGENERATOR_H
