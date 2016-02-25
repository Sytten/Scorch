#include "Entities/Entity.h"

using namespace std;

int Entity::timesCalled = 0;


Entity::Entity()
{
#if defined GAME_DEBUG && defined ENTITY_DEBUG
	cout << "Entity::Entity()" << endl;
#endif
	
	m_size.x = 1;
	m_size.y = 1;

	m_id = timesCalled;
	 
	m_position.x = 0;
	m_position.y = 0;

	timesCalled++;

#if defined GAME_DEBUG && defined ENTITY_DEBUG
	cout << "Entity number " << m_id << " was created at position x: " << m_position.x << ", y: " << m_position.y 
		 << " of size " << m_size.x << " by " << m_size.y << endl;
#endif
}

Entity::Entity(Vector2<double> p_position, Vector2<double> p_size)
{
#if defined GAME_DEBUG && defined ENTITY_DEBUG
	cout << "Entity::Entity(Vector2<double>, Vector2<double>)" << endl;
#endif
	m_position = p_position;
	m_size = p_size;

	m_id = timesCalled;
	timesCalled++;

#if defined GAME_DEBUG && defined ENTITY_DEBUG
	cout << "Entity number " << m_id << " was created at position x: " << m_position.x << ", y: " << m_position.y 
		 << " of size " << m_size.x << " by " << m_size.y << endl;
#endif

}

Entity::~Entity()
{
#if defined GAME_DEBUG && defined ENTITY_DEBUG
	cout << "Entity::~Entity()" << endl;
#endif
}

Vector2<double> Entity::getSize() const
{
#if defined GAME_DEBUG && defined ENTITY_DEBUG
	cout << "Entity::getSize()" << endl;
#endif
	return m_size;
}

Vector2<double> Entity::getPosition() const
{
#if defined GAME_DEBUG && defined ENTITY_DEBUG
	cout << "Entity::getPosition()" << endl;
#endif
	return m_position;
}

int Entity::getID() const
{
#if defined GAME_DEBUG && defined ENTITY_DEBUG
	cout << "Entity::getID()" << endl;
#endif
	return m_id;
}

void Entity::scale(Vector2<double> p_scale)
{
#if defined GAME_DEBUG && defined ENTITY_DEBUG
		cout << "Entity::scale(Vector2<double>)" << endl;
#endif
}

void Entity::move(Vector2<double> p_movement)
{
#if defined GAME_DEBUG && defined ENTITY_DEBUG
	cout << "Entity::move(Vector2<double>)" << endl;
	cout << "Entity::move(Vector2<double>)" << "To be moved X:" << p_movement.x << " and Y:" << p_movement.y << endl;
#endif
	m_position.x += p_movement.x;
	m_position.y += p_movement.y;

}
