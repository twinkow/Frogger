#ifndef TURTLE_H
#define TURTLE_H

#include "DynamicObject.h"

class Turtle : public DynamicObject
{
	
public:
	Turtle();
	~Turtle();

	void draw();

};
#endif