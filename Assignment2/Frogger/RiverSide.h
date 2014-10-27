#ifndef RIVERSIDE_H
#define RIVERSIDE_H

#include "StaticObject.h"

class RiverSide : public StaticObject
{
public:

	RiverSide();
	~RiverSide();

	void draw(VSMathLib *vsml, VSShaderLib shader);
};

#endif

