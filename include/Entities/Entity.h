#ifndef ENTITY_H
#define ENTITY_H

#include "Vector2.h"

class Entity
{
    public:
        Entity(Vector2<double> p_position, Vector2<double> p_size);

        Vector2<double> getSize();
        Vector2<double> getPosition();

        void update(double p_deltaTime) = 0;

    private:
        Vector2<double> m_position;
        Vector2<double> m_size;
};

#endif // ENTITY_H
