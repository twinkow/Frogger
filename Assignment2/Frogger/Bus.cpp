#include "Bus.h"

Bus::Bus(){
	_position.set(-5.0, 1.0, 1.5);
}

Bus::~Bus(){}

void Bus::draw(VSMathLib *vsml, VSShaderLib shader){
	vsml->pushMatrix(VSMathLib::MODEL);
		shader.setUniform("color", blue);
		vsml->translate(VSMathLib::MODEL, getPosition().getX(), getPosition().getY(), getPosition().getZ());
		vsml->scale(VSMathLib::MODEL, 4.0f, 2.0f, 1.0f);
		vsml->matricesToGL();
		glDrawElements(GL_TRIANGLES, faceCount * 3, GL_UNSIGNED_INT, 0);
		vsml->popMatrix(VSMathLib::MODEL);
	
		//Roda FE
		vsml->pushMatrix(VSMathLib::MODEL);
		shader.setUniform("color", black);
		vsml->translate(VSMathLib::MODEL, getPosition().getX() + 0.9, getPosition().getY()/2, getPosition().getZ()-0.5);
		vsml->scale(VSMathLib::MODEL, 0.5f, 0.5f, 0.5f);
		vsml->matricesToGL();
		glDrawElements(GL_TRIANGLES, faceCount * 3, GL_UNSIGNED_INT, 0);
		vsml->popMatrix(VSMathLib::MODEL);
	
		//Roda FD
		vsml->pushMatrix(VSMathLib::MODEL);
		shader.setUniform("color", black);
		vsml->translate(VSMathLib::MODEL, getPosition().getX() + 0.9, getPosition().getY() / 2, getPosition().getZ() + 0.5);
		vsml->scale(VSMathLib::MODEL, 0.5f, 0.5f, 0.5f);
		vsml->matricesToGL();
		glDrawElements(GL_TRIANGLES, faceCount * 3, GL_UNSIGNED_INT, 0);
		vsml->popMatrix(VSMathLib::MODEL);
	
		//Roda TE
		vsml->pushMatrix(VSMathLib::MODEL);
		shader.setUniform("color", black);
		vsml->translate(VSMathLib::MODEL, getPosition().getX() - 1.1, getPosition().getY() / 2, getPosition().getZ() - 0.5);
		vsml->scale(VSMathLib::MODEL, 0.5f, 0.5f, 0.5f);
		vsml->matricesToGL();
		glDrawElements(GL_TRIANGLES, faceCount * 3, GL_UNSIGNED_INT, 0);
		vsml->popMatrix(VSMathLib::MODEL);
	
		//Roda TD
		vsml->pushMatrix(VSMathLib::MODEL);
		shader.setUniform("color", black);
		vsml->translate(VSMathLib::MODEL, getPosition().getX() - 1.1, getPosition().getY() / 2, getPosition().getZ() + 0.5);
		vsml->scale(VSMathLib::MODEL, 0.5f, 0.5f, 0.5f);
		vsml->matricesToGL();
		glDrawElements(GL_TRIANGLES, faceCount * 3, GL_UNSIGNED_INT, 0);
		vsml->popMatrix(VSMathLib::MODEL);
}