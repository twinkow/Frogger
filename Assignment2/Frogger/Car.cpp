#include "Car.h"

Car::Car(){
	GameObject::initialize();
	_position.set(-6.0f, 1.0f, 3.0f);
}

Car::~Car(){}

void Car::draw(VSMathLib *vsml, VSShaderLib shader){
		//Carro Cima
		vsml->pushMatrix(VSMathLib::MODEL);
		shader.setUniform("color", red);
		vsml->translate(VSMathLib::MODEL, getPosition().getX(), getPosition().getY(), getPosition().getZ());
		vsml->scale(VSMathLib::MODEL, 2.0f, 1.0f, 1.0f);
		vsml->matricesToGL();
		glDrawElements(GL_TRIANGLES, faceCount*3, GL_UNSIGNED_INT, 0); 
		vsml->popMatrix(VSMathLib::MODEL);
	
		//Roda FE
		vsml->pushMatrix(VSMathLib::MODEL);
		shader.setUniform("color", black);
		vsml->translate(VSMathLib::MODEL, getPosition().getX() + 0.4f, getPosition().getY()/2, getPosition().getZ()-0.5f);
		vsml->scale(VSMathLib::MODEL, 0.5f, 0.5f, 0.5f);
		vsml->matricesToGL();
		glDrawElements(GL_TRIANGLES, faceCount*3, GL_UNSIGNED_INT, 0); 
		vsml->popMatrix(VSMathLib::MODEL);
	
		//Roda FD
		vsml->pushMatrix(VSMathLib::MODEL);
		shader.setUniform("color", black);
		vsml->translate(VSMathLib::MODEL, getPosition().getX() + 0.4f, getPosition().getY() / 2, getPosition().getZ() + 0.5f);
		vsml->scale(VSMathLib::MODEL, 0.5f, 0.5f, 0.5f);
		vsml->matricesToGL();
		glDrawElements(GL_TRIANGLES, faceCount*3, GL_UNSIGNED_INT, 0); 
		vsml->popMatrix(VSMathLib::MODEL);
	
		//Roda TE
		vsml->pushMatrix(VSMathLib::MODEL);
		shader.setUniform("color", black);
		vsml->translate(VSMathLib::MODEL, getPosition().getX() - 0.6f, getPosition().getY() / 2, getPosition().getZ() - 0.5f);
		vsml->scale(VSMathLib::MODEL, 0.5f, 0.5f, 0.5f);
		vsml->matricesToGL();
		glDrawElements(GL_TRIANGLES, faceCount*3, GL_UNSIGNED_INT, 0); 
		vsml->popMatrix(VSMathLib::MODEL);
	
		//Roda TD
		vsml->pushMatrix(VSMathLib::MODEL);
		shader.setUniform("color", black);
		vsml->translate(VSMathLib::MODEL, getPosition().getX() - 0.6f, getPosition().getY() / 2, getPosition().getZ() + 0.5f);
		vsml->scale(VSMathLib::MODEL, 0.5f, 0.5f, 0.5f);
		vsml->matricesToGL();
		glDrawElements(GL_TRIANGLES, faceCount*3, GL_UNSIGNED_INT, 0); 
		vsml->popMatrix(VSMathLib::MODEL);


		////Carro Cima
		//vsml->pushMatrix(VSMathLib::MODEL);
		//shader.setUniform("color", red);
		//vsml->translate(VSMathLib::MODEL, getPosition().getX(), getPosition().getY(), getPosition().getZ()+3.5f);
		//vsml->scale(VSMathLib::MODEL, 2.0f, 1.0f, 1.0f);
		//vsml->matricesToGL();
		//glDrawElements(GL_TRIANGLES, faceCount * 3, GL_UNSIGNED_INT, 0);
		//vsml->popMatrix(VSMathLib::MODEL);
		//
		////Roda FE
		//vsml->pushMatrix(VSMathLib::MODEL);
		//shader.setUniform("color", black);
		//vsml->translate(VSMathLib::MODEL, getPosition().getX() + 0.4f, getPosition().getY() / 2, getPosition().getZ() + 3.0f);
		//vsml->scale(VSMathLib::MODEL, 0.5f, 0.5f, 0.5f);
		//vsml->matricesToGL();
		//glDrawElements(GL_TRIANGLES, faceCount * 3, GL_UNSIGNED_INT, 0);
		//vsml->popMatrix(VSMathLib::MODEL);
		//
		////Roda FD
		//vsml->pushMatrix(VSMathLib::MODEL);
		//shader.setUniform("color", black);
		//vsml->translate(VSMathLib::MODEL, getPosition().getX() + 0.4f, getPosition().getY() / 2, getPosition().getZ() + 4.0f);
		//vsml->scale(VSMathLib::MODEL, 0.5f, 0.5f, 0.5f);
		//vsml->matricesToGL();
		//glDrawElements(GL_TRIANGLES, faceCount * 3, GL_UNSIGNED_INT, 0);
		//vsml->popMatrix(VSMathLib::MODEL);
		//
		////Roda TE
		//vsml->pushMatrix(VSMathLib::MODEL);
		//shader.setUniform("color", black);
		//vsml->translate(VSMathLib::MODEL, getPosition().getX() - 0.6f, getPosition().getY() / 2, getPosition().getZ() + 3.0f);
		//vsml->scale(VSMathLib::MODEL, 0.5f, 0.5f, 0.5f);
		//vsml->matricesToGL();
		//glDrawElements(GL_TRIANGLES, faceCount * 3, GL_UNSIGNED_INT, 0);
		//vsml->popMatrix(VSMathLib::MODEL);
		//
		////Roda TD
		//vsml->pushMatrix(VSMathLib::MODEL);
		//shader.setUniform("color", black);
		//vsml->translate(VSMathLib::MODEL, getPosition().getX() - 0.6f, getPosition().getY() / 2, getPosition().getZ() + 4.0f);
		//vsml->scale(VSMathLib::MODEL, 0.5f, 0.5f, 0.5f);
		//vsml->matricesToGL();
		//glDrawElements(GL_TRIANGLES, faceCount * 3, GL_UNSIGNED_INT, 0);
		//vsml->popMatrix(VSMathLib::MODEL);
}