#ifndef VECTOR3_H 
#define VECTOR3_H

class Vector3
{

protected:

	double _x; double _y; double _z;

public:

	Vector3();
	Vector3(double in_x, double in_y, double in_z);
	~Vector3();

	double getX(); 
	double getY(); 
	double getZ();

	void set(double in_x, double in_y, double in_z);

	Vector3 operator+(const Vector3 &inVec) ;
	Vector3 operator-(const Vector3 &inVec) ;
	Vector3 operator*(double num) ; 
	Vector3 operator/(const Vector3 &inVec) ;

};
#endif