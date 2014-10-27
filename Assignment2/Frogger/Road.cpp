#include "Road.h"


Road::Road(){
	_position.set(0.0f, 0.0f, 4.0f);
}

Road::~Road(){}

void Road::draw(VSMathLib *vsml, VSShaderLib shader){


		//Estrada
		vsml->pushMatrix(VSMathLib::MODEL);
		shader.setUniform("color", street);
		vsml->translate(VSMathLib::MODEL, 0.0f, 0.0f, 4.0f);
		vsml->scale(VSMathLib::MODEL, 14.0f, 0.5f, 7.0f);
		// send matrices to uniform buffer
		vsml->matricesToGL();
		glDrawElements(GL_TRIANGLES, faceCount*3, GL_UNSIGNED_INT, 0);
		vsml->popMatrix(VSMathLib::MODEL);


}