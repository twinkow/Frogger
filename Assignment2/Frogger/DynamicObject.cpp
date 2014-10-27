#include "DynamicObject.h"


DynamicObject::DynamicObject(){}

DynamicObject::~DynamicObject(){}

void DynamicObject::update(double delta_t){
	//TODO: update
}

Vector3 DynamicObject::getSpeed(){
	return _speed;
}

void DynamicObject::setSpeed(const Vector3 &speed){
	_speed = speed;
}

void DynamicObject::setSpeed(double x, double y, double z){
	_speed = Vector3(x, y, z);
}