#include "RoadSide.h"


RoadSide::RoadSide(){
	_position.set(0.0f, 0.0f, 8.0f);
}

RoadSide::~RoadSide(){}

void RoadSide::draw(VSMathLib *vsml, VSShaderLib shader){
		vsml->pushMatrix(VSMathLib::MODEL);
		shader.setUniform("color", black);
		vsml->scale(VSMathLib::MODEL, 14.0f, 0.6f, 1.0f);
		vsml->matricesToGL();
		glDrawElements(GL_TRIANGLES, faceCount * 3, GL_UNSIGNED_INT, 0);
		vsml->popMatrix(VSMathLib::MODEL);

		vsml->pushMatrix(VSMathLib::MODEL);
		shader.setUniform("color", black);
		vsml->translate(VSMathLib::MODEL, getPosition().getX(), getPosition().getY(), getPosition().getZ());
		vsml->scale(VSMathLib::MODEL, 14.0f, 0.6f, 1.0f);
		vsml->matricesToGL();
		glDrawElements(GL_TRIANGLES, faceCount*3, GL_UNSIGNED_INT, 0); 
		vsml->popMatrix(VSMathLib::MODEL);
}