#ifndef PERSPECTIVECAMERA_H
#define PERSPECTIVECAMERA_H

#include "Camera.h"

class PerpectiveCamera : public Camera
{
private:
	double _fovy;
	double _aspect;

public:

	PerpectiveCamera(double fovy, double aspect, double zNear, double zFar);
	~PerpectiveCamera();

	void update();
	void computeProjectionMatrix();
	void computeVisualizationMatrix();
};

#endif