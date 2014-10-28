#include "Turtle.h"

Turtle::Turtle(){
	_position.set(-6.0, 1.0, -2.0);
}

Turtle::~Turtle(){}

void Turtle::draw(VSMathLib *vsml, VSShaderLib shader){
		//Corpo tartaruga
	vsml->pushMatrix(VSMathLib::MODEL);
	shader.setUniform("color", grass);
	vsml->translate(VSMathLib::MODEL, getPosition().getX(), 1.0f, -2.0f);
	vsml->scale(VSMathLib::MODEL, 1.0f, 1.0f, 1.0f);
	vsml->matricesToGL();
	glDrawElements(GL_TRIANGLES, faceCount*3, GL_UNSIGNED_INT, 0);
	vsml->popMatrix(VSMathLib::MODEL);

	//Pata FE
	vsml->pushMatrix(VSMathLib::MODEL);
	shader.setUniform("color", yellow);
	vsml->translate(VSMathLib::MODEL, getPosition().getX() + 0.5f, 0.5f, -2.5f);
	vsml->scale(VSMathLib::MODEL, 0.5f, 0.5f, 0.5f);
	vsml->matricesToGL();
	glDrawElements(GL_TRIANGLES, faceCount*3, GL_UNSIGNED_INT, 0);
	vsml->popMatrix(VSMathLib::MODEL);

	//Pata FD
	vsml->pushMatrix(VSMathLib::MODEL);
	shader.setUniform("color", yellow);
	vsml->translate(VSMathLib::MODEL, getPosition().getX() + 0.5f, 0.5f, -1.5f);
	vsml->scale(VSMathLib::MODEL, 0.5f, 0.5f, 0.5f);
	vsml->matricesToGL();
	glDrawElements(GL_TRIANGLES, faceCount*3, GL_UNSIGNED_INT, 0);
	vsml->popMatrix(VSMathLib::MODEL);

	//Pata TE
	vsml->pushMatrix(VSMathLib::MODEL);
	shader.setUniform("color", yellow);
	vsml->translate(VSMathLib::MODEL, getPosition().getX() - 0.5f, 0.5f, -2.5f);
	vsml->scale(VSMathLib::MODEL, 0.5f, 0.5f, 0.5f);
	vsml->matricesToGL();
	glDrawElements(GL_TRIANGLES, faceCount*3, GL_UNSIGNED_INT, 0);
	vsml->popMatrix(VSMathLib::MODEL);

	//Pata TD
	vsml->pushMatrix(VSMathLib::MODEL);
	shader.setUniform("color", yellow);
	vsml->translate(VSMathLib::MODEL, getPosition().getX() - 0.5f, 0.5f, -1.5f);
	vsml->scale(VSMathLib::MODEL, 0.5f, 0.5f, 0.5f);
	vsml->matricesToGL();
	glDrawElements(GL_TRIANGLES, faceCount*3, GL_UNSIGNED_INT, 0);
	vsml->popMatrix(VSMathLib::MODEL);
}