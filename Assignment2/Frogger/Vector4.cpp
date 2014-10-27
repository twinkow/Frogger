#include "Vector4.h"


Vector4::Vector4() : Vector3(), _w(1) {};

Vector4::Vector4(double in_x, double in_y, double in_z, double in_w) : Vector3(in_x, in_y, in_z), _w(in_w) {};

double Vector4::getW() const{ return _w; }

void Vector4::set(double in_x, double in_y, double in_z, double in_w) { Vector3::set(in_x, in_y, in_z), _w = in_w;}

Vector4 Vector4::operator+(const Vector4 &inVec){
	return Vector4(_x + inVec._x, _y + inVec._y, _z + inVec._z, _w + inVec._w);
}

Vector4 Vector4::operator-(const Vector4 &inVec){
	return Vector4(_x - inVec._x, _y - inVec._y, _z - inVec._z, _w - inVec._w);
}

Vector4 Vector4::operator/(const Vector4 &inVec){
	return Vector4(_x / inVec._x, _y / inVec._y, _z / inVec._z, _w / inVec._w);
}

Vector4 Vector4::operator*(double num){
	return Vector4(_x*num, _y*num, _z*num, _w*num);
}


Vector4::~Vector4()
{
}
