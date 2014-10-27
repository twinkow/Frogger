#ifndef ORTHOGONALCAMERA_H
#define ORTHOGONALCAMERA_H

#include "Camera.h"

class OrthogonalCamera : public Camera
{
protected:
	double _left;
	double _right;
	double _bottom;
	double _top;

public:

	OrthogonalCamera(double left, double right, double bottom, double top, double zNear, double zFar);
	~OrthogonalCamera();

	void update();
	void computeProjectionMatrix();
	void computeVisualizationMatrix();
};

#endif