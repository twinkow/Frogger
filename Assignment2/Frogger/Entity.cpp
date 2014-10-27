#include "Entity.h"


Entity::Entity(){
	_position = Vector3();
}

Entity::~Entity(){}

Vector3 Entity::getPosition(){ return _position;}

Vector3 Entity::setPosition(double in_x, double in_y, double in_z){
	_position = Vector3(in_x, in_y, in_z);
	return _position;
}

Vector3 Entity::setPosition(const Vector3 &pos){
	_position = pos;
	return _position;
}