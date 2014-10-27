#ifndef LIGHTSOURCE_H 
#define LIGHTSOURCE_H

#include "Vector4.h"

class LightSource
{
private:
	bool _state;

	Vector4 _ambient;
	Vector4 _diffuse;
	Vector4 _specular;
	Vector4 _position;
	Vector3 _direction;

	double _cut_off;
	double _exponent;

	// ver num


public:
	LightSource();	   // ver
	~LightSource();
	// ver getnum

	bool getState();
	bool setState(bool in_state);

	void setPosition(const Vector4 &inVec);
	void setAmbient(const Vector4 &inVec);
	void setDiffuse(const Vector4 &inVec);
	void setSpecular(const Vector4 &inVec);
	void setDirection(const Vector3 &inVec);

	void setExponent(double in_exponent);
	void setCutOff(double in_cutoff);

	void draw();

};
#endif
