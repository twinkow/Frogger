#ifndef GAMEMANAGER_H 
#define GAMEMANAGER_H

#include "GameObject.h"
#include "LightSource.h"
#include "Camera.h"

#include "vsMathLib.h"

#include <GL/glew.h>
#include <GL/freeglut.h>

class GameManager
{
private:
	GameObject* game_object;
	LightSource* light_sources;
	Camera* _cameras;


public:
	GameManager();
	~GameManager();

	void display();
	void reshape(GLsizei in_w, GLsizei in_h);
	void keyPressed();
	void onTimer();
	void idle();
	void update();
	void init();

};
#endif

