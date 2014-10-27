#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Entity.h"

class GameObject : Entity
{
public:

	GameObject();
	~GameObject();

	virtual void draw() = 0;

	void update(double delta_t);

};

#endif

