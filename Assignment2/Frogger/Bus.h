#ifndef BUS_H
#define BUS_H

#include "DynamicObject.h"

class Bus : public DynamicObject
{
	
public:
	Bus();
	~Bus();

	void draw(VSMathLib *vsml, VSShaderLib shader);

};
#endif