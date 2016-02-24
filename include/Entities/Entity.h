#ifndef ENTITY_H
#define ENTITY_H

#define MAX_NUM_OBJ 80;

#include "Helper/Vector2.h"
#include "Helper/IDGenerator.h"

#include <iostream>


class Entity
{
    public:
		Entity();
		Entity(Vector2<double> p_position, Vector2<double> p_size);
        virtual ~Entity();

        Vector2<double> getSize();
        Vector2<double> getPosition();
        int getID();

        void scale(Vector2<double> p_scale);
        void move(Vector2<double> p_movement);

        virtual void update(double p_deltaTime) = 0;

    private:
        Vector2<double> m_position;
        Vector2<double> m_size;

        int  m_id;
		static int timesCalled;
};


#endif // ENTITY_H
