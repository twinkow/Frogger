#include "C:\Users\João\Desktop\AVT\Assignment2\LightSource.h"


LightSource::LightSource()
{
}


LightSource::~LightSource()
{
}

bool getState(){
	return _state;
}

bool setState(bool in_state){
	_state = in_state;
	return _state;
}

//ver getnum

void setDirection(const Vector3 &inDirection){
	_direction._x = inDirection._x;
	_direction._y = inDirection._y;
	_direction._z = inDirection._z;
}

void setPosition(const Vector4 &inVec){
	_position._x = inVec._x;
	_position._y = inVec._y;
	_position._z = inVec._z;
	_position._w = inVec._w;
}

void setAmbient(const Vector4 &inVec){
	_ambient._x = inVec._x;
	_ambient._y = inVec._y;
	_ambient._z = inVec._z;
	_ambient._w = inVec._w;
}

void setDiffuse(const Vector4 &inVec){
	_diffuse._x = inVec._x;
	_diffuse._y = inVec._y;
	_diffuse._z = inVec._z;
	_diffuse._w = inVec._w;
}

void setSpecular(const Vector4 &inVec){
	_specular._x = inVec._x;
	_specular._y = inVec._y;
	_specular._z = inVec._z;
	_specular._w = inVec._w;
}

void setExpoent(double in_expoent){
	_expoent = in_expoent;
}

void setCutOff(double in_cutoff){
	_cutoff = in_cutoff;
}

void draw(){
	//TODO
}
