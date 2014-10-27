#ifndef VECTOR4_H 
#define VECTOR4_H

#include "Vector3.h"
class Vector4 :
	public Vector3
{
private:
	double _w;

public:
	Vector4();
	Vector4(double _x, double _y, double _z, double _w);
	~Vector4();

	double getW();
	void set(double _x, double _y, double _z, double _w);

	Vector4 operator+(const Vector4 &inVec);
	Vector4 operator-(const Vector4 &inVec);
	Vector4 operator*(double num);
	Vector4 operator/(const Vector4 &inVec);
};
#endif
