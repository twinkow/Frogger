#include "PerpectiveCamera.h"


PerpectiveCamera::PerpectiveCamera(double fovy, double aspect, double near, double far) : _fovy(fovy), _aspect(aspect), Camera(near, far){}

PerpectiveCamera::~PerpectiveCamera(){}

void PerpectiveCamera::update(){
	//TODO
}

void PerpectiveCamera::computeProjectionMatrix(){
	//TODO
}

void PerpectiveCamera::computeVisualizationMatrix(){
	//TODO
}