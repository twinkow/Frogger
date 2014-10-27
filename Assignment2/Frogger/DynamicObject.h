#ifndef DYNAMICOBJECT_H
#define DYNAMICOBJECT_H

#include "GameObject.h"

class DynamicObject : GameObject
{

protected:
	Vector3 _speed;

public:

	DynamicObject();
	
	~DynamicObject();

	void update(double delta_t);

	Vector3 getSpeed();

	void setSpeed(const Vector3& speed);

	void setSpeed(double x, double y, double z);
};

#endif

