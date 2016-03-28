#ifndef ENTITY_H
#define ENTITY_H

#define MAX_NUM_OBJ 80;

#include "Helper/Vector2.h"
#include "Helper/IDGenerator.h"

#include <iostream>

//#define ENTITY_DEBUG

class Entity
{
    public:
		Entity();
		Entity(Vector2<double> p_position, Vector2<double> p_size);


        virtual ~Entity();

        Vector2<double> getSize() const;
        Vector2<double> getPosition() const;
		int getID() const;

        void scale(Vector2<double> p_scale);
        void move(Vector2<double> p_movement);

        virtual void update(double p_deltaTime) = 0;

    private:
        Vector2<double> m_position;
        Vector2<double> m_size;

        
		static int timesCalled;

	protected:
		int  m_id;
};


#endif // ENTITY_H
