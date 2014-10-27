#include "LightSource.h"


LightSource::LightSource()
{
}


LightSource::~LightSource()
{
}

bool LightSource::getState(){
	return _state;
}

bool LightSource::setState(bool in_state){
	_state = in_state;
	return _state;
}

//ver getnum

void LightSource::setDirection(const Vector3 &inDirection){
	_direction.set(inDirection.getX(), inDirection.getY(), inDirection.getZ());
}

void LightSource::setPosition(const Vector4 &inVec){
	_position.set(inVec.getX(), inVec.getY(), inVec.getZ(), inVec.getW());
}

void LightSource::setAmbient(const Vector4 &inVec){
	_ambient.set(inVec.getX(), inVec.getY(), inVec.getZ(), inVec.getW());
}

void LightSource::setDiffuse(const Vector4 &inVec){
	_diffuse.set(inVec.getX(), inVec.getY(), inVec.getZ(), inVec.getW());
}

void LightSource::setSpecular(const Vector4 &inVec){
	_specular.set(inVec.getX(), inVec.getY(), inVec.getZ(), inVec.getW());
}

void LightSource::setExponent(double in_exponent){
	_exponent = in_exponent;
}

void LightSource::setCutOff(double in_cutoff){
	_cut_off = in_cutoff;
}

void LightSource::draw(){
	//TODO
}
