#include "Timberlog.h"

Timberlog::Timberlog(){
	_position.set(-6.0, 0.5, -5.0);
}

Timberlog::~Timberlog(){}

void Timberlog::draw(VSMathLib *vsml, VSShaderLib shader){
		vsml->pushMatrix(VSMathLib::MODEL);
		shader.setUniform("color", brown);
		vsml->translate(VSMathLib::MODEL, getPosition().getX(), getPosition().getY(), getPosition().getZ());
		vsml->scale(VSMathLib::MODEL, 2.0f, 0.5f, 1.0f);
		vsml->matricesToGL();
		glDrawElements(GL_TRIANGLES, faceCount*3, GL_UNSIGNED_INT, 0); 
		vsml->popMatrix(VSMathLib::MODEL);
}