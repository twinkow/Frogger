#ifndef TIMBERLOG_H
#define TIMBERLOG_H

#include "DynamicObject.h"

class Timberlog : public DynamicObject
{
public:
	Timberlog();
	~Timberlog();

	void draw(VSMathLib *vsml, VSShaderLib shader);

};
#endif