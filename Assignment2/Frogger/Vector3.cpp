#include "Vector3.h"

Vector3::Vector3() : _x(1), _y(1), _z(1) {}

Vector3::Vector3(double in_x, double in_y, double in_z) : _x(in_x), _y(in_y), _z(in_z) {}

double Vector3::getX() const{ return _x; }

double Vector3::getY() const{ return _y; }

double Vector3::getZ() const{ return _z; }

void Vector3::set(double in_x, double in_y, double in_z){ _x = in_x, _y = in_y, _z = in_z; }

Vector3 Vector3::operator+(const Vector3 &inVec){
	return Vector3(_x + inVec._x, _y + inVec._y , _z + inVec._z);
}

Vector3 Vector3::operator-(const Vector3 &inVec){
	return Vector3(_x - inVec._x, _y - inVec._y , _z - inVec._z);
}

Vector3 Vector3::operator/(const Vector3 &inVec){ 
	return Vector3(_x / inVec._x, _y / inVec._y , _z / inVec._z);
}

Vector3 Vector3::operator*(double num){ 
	return Vector3(_x*num, _y*num, _z*num); 
}