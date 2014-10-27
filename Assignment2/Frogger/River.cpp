#include "River.h"


River::River(){		
	GameObject::initialize(); 
	_position.set(0.0f, 0.0f, -4.0f);
};

River::~River(){}

void River::draw(VSMathLib *vsml, VSShaderLib shader){
		//Agua
	vsml->pushMatrix(VSMathLib::MODEL);
	shader.setUniform("color", water);
	vsml->translate(VSMathLib::MODEL, getPosition().getX(), getPosition().getY(), getPosition().getZ());
	vsml->scale(VSMathLib::MODEL, 14.0f, 0.5f, 7.0f);
	// send matrices to uniform buffer
	vsml->matricesToGL();
	glDrawElements(GL_TRIANGLES, faceCount*3, GL_UNSIGNED_INT, 0);
	vsml->popMatrix(VSMathLib::MODEL);
}