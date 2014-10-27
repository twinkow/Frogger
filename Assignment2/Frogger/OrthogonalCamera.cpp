#include "OrthogonalCamera.h"


OrthogonalCamera::OrthogonalCamera(double left, double right, double bottom, double top, double near, double far) : 
	_left(left), _right(right), _bottom(bottom), _top(top), Camera(near, far){}

OrthogonalCamera::~OrthogonalCamera(){}

void OrthogonalCamera::update(){
	//TODO
}

void OrthogonalCamera::computeProjectionMatrix(){
	//TODO
}

void OrthogonalCamera::computeVisualizationMatrix(){
	//TODO
}