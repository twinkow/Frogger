#ifndef ENTITY_H
#define ENTITY_H

#include "Vector3.h"

class Entity
{
protected:
	Vector3 _position;

public:
	Entity();
	~Entity();

	Vector3 getPosition(); 
	Vector3 setPosition(double in_x, double in_y, double in_z);
	Vector3 setPosition(const Vector3 &pos);

};

#endif
