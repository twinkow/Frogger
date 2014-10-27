#include "GameManager.h"

VSMathLib *vsml;
float _ratio;

GameManager::GameManager()
{
}


GameManager::~GameManager()
{
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// load identity matrices
	vsml->loadIdentity(VSMathLib::VIEW);
	vsml->loadIdentity(VSMathLib::MODEL);

	//draws	 (será que o GameManager cria instâncias deles?)

	// (ver o glprogram para o shader) 

	//swap buffers
	glutSwapBuffers();
}

void reshape(GLsizei in_w, GLsizei in_h){
	// Prevent a divide by zero, when window is too short
	if (in_h == 0)
		in_h = 1;
	// set the viewport to be the entire window
	glViewport(0, 0, in_w, in_h);
	// set the projection matrix
	_ratio = (1.0f * in_w) / in_h;
	vsml->loadIdentity(VSMathLib::PROJECTION);
	vsml->perspective(60, _ratio, 0.1f, 25.0f);
}

void keyPressed(){
	//TODO
}

//ver o que se faz aos processMouses

void idle(){
	//ate agr n tem nada
}

void onTimer(){
	//TODO, falta cenas dos objectos
}

void update(){
	// o que é pa meter aqui?
}

void init(){
	// o que é ao todo para iniciar?
}

