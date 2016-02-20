#include "D:\\Qt\include\Entities\Entity.h"

using namespace std;


Entity::Entity()
{
}

Entity::Entity(Vector2<double> p_position, Vector2<double> p_size)
{
	m_position = p_position;
	m_size = p_size;

	m_id = timeCalled;
	timeCalled++;

	cout << "L'entite numero " << m_id << " a ete cree a l'endroit " << p_position.x << "," << p_position.y << "de grosseur " << p_size.x << "par" << p_size.y << endl;

}

Entity::~Entity()
{
}

Vector2<double> Entity::getSize()
{
	return Vector2<double>();
}

Vector2<double> Entity::getPosition()
{
	return Vector2<double>();
}

int Entity::getID()
{
	return m_id;
}

void Entity::scale(Vector2<double> p_scale)
{
}

void Entity::move(Vector2<double> p_movement)
{
}
