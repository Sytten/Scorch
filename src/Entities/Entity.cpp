#include "Entities/Entity.h"

using namespace std;

Entity::Entity()
{
#ifdef GAME_DEBUG
	cout << "Entity::Entity" << endl;
#endif
}

Entity::Entity(Vector2<double> p_position, Vector2<double> p_size)
{
#ifdef GAME_DEBUG
	cout << "Entity::Entity(Vector2<double>, Vector2<double>)" << endl;
#endif
	m_position = p_position;
	m_size = p_size;

	m_id = timeCalled;
	timeCalled++;

	cout << "Entity number " << m_id << " was created at position x:" << p_position.x << ", y:" << p_position.y << " of size " << p_size.x << " by" << p_size.y << endl;

}

Entity::~Entity()
{
#ifdef GAME_DEBUG
	cout << "Entity::~Entity" << endl;
#endif
}

Vector2<double> Entity::getSize()
{
#ifdef GAME_DEBUG
	cout << "Entity::getSize" << endl;
#endif
	return Vector2<double>();
}

Vector2<double> Entity::getPosition()
{
#ifdef GAME_DEBUG
	cout << "Entity::getPosition" << endl;
#endif
	return Vector2<double>();
}

int Entity::getID()
{
#ifdef GAME_DEBUG
	cout << "Entity::getID" << endl;
#endif
	return m_id;
}

void Entity::scale(Vector2<double> p_scale)
{
#ifdef GAME_DEBUG
		cout << "Entity::scale" << endl;
#endif
}

void Entity::move(Vector2<double> p_movement)
{
#ifdef GAME_DEBUG
	cout << "Entity::move" << endl;
#endif
}
