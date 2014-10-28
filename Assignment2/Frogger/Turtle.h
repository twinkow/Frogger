#ifndef TURTLE_H
#define TURTLE_H

#include "DynamicObject.h"

class Turtle : public DynamicObject
{
	
public:
	Turtle();
	~Turtle();

	void draw(VSMathLib *vsml, VSShaderLib shader);

};
#endif