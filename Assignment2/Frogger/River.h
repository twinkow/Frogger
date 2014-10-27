#ifndef RIVER_H
#define RIVER_H

#include "StaticObject.h"

#include "VSMathlib.h"
#include "VSShaderlib.h"


class River : public StaticObject
{

public:

	River();
	~River();

	void draw(VSMathLib *vsml, VSShaderLib shader);
};

#endif

