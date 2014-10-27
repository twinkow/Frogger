#ifndef ROADSIDE_H
#define ROADSIDE_H

#include "StaticObject.h"

class RoadSide : public StaticObject
{
public:

	RoadSide();
	~RoadSide();

	void draw(VSMathLib *vsml, VSShaderLib shader);
};

#endif

