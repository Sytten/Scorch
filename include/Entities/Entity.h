#ifndef ENTITY_H
#define ENTITY_H

#include "Helper/Vector2.h"
#include "Helper/IDGenerator.h"

class Entity
{
    public:
        Entity(Vector2<double> p_position, Vector2<double> p_size);

        Vector2<double> getSize();
        Vector2<double> getPosition();
        int getID();

        void scale(Vector2<double> p_scale);
        void move(Vector2<double> p_movement);

        void update(double p_deltaTime) = 0;

    private:
        Vector2<double> m_position;
        Vector2<double> m_size;

        int const m_id;
};

#endif // ENTITY_H
