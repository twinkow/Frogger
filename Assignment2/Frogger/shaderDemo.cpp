//
// Lighthouse3D.com GLSL Core Tutorial - Hello World Example
//
//
// This demo was built for learning purposes only.
// Some code could be severely optimised, but I tried to
// keep as simple and clear as possible.
//
// The code comes with no warranties, use it at your own risk.
// You may use it, or parts of it, wherever you want.
//
// If you do use it I would love to hear about it. Just post a comment
// at Lighthouse3D.com

// Have Fun :-)

#include <math.h>
#include <string>

#include "shaderDemo.h"

#include "River.h"
#include "Road.h"
#include "RoadSide.h"
#include "RiverSide.h"
#include "Car.h"
#include "Bus.h"

// include GLEW to access OpenGL 3.3 functions
#include <GL/glew.h>

// GLUT is the toolkit to interface with the OS
#include <GL/freeglut.h>

VSMathLib *vsml;
VSShaderLib shader;

River river;
RiverSide riverSide;
Road road;
RoadSide roadside;
Car car;
Bus bus;


// Window width / height
float ratio;

// lookAt arguments
float eyeX, eyeY, eyeZ, dirX, dirY, dirZ, upX, upY, upZ;

// Frogs's coordinates
float moveX, moveZ;

// Mouse's coordinates
int MousePositionX, MousePositionZ;

// Objects starting positions
float startPosLog = -6.0f;
float startPosTurtle = -6.0f;
float startPosCar = -6.0f;
float startPosBus = -5.0f;

// Camera's Position
float camX, camY, camZ;
bool isIn3, isIn4;

// Mouse Tracking Variables
int startX, startY, tracking = 0;

// Camera Spherical Coordinates
float alpha = 0.0f;

// Frame counting and FPS computation
long myTime,timebase = 0,frame = 0;
char s[32];

// Speed increase timers
int tActual, tAnterior, tDif;
float speed = 0.01f;

GLuint vao;

int random;

// ------------------------------------------------------------
//
// Reshape Callback Function
//

void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	if(h == 0)
		h = 1;
	// set the viewport to be the entire window
	glViewport(0, 0, w, h);
	// set the projection matrix
	ratio = (1.0f * w) / h;
	vsml->loadIdentity(VSMathLib::PROJECTION);
	vsml->perspective(60, ratio, 0.1f, 25.0f);
}


// ------------------------------------------------------------
//
// Render stuff
//
//void drawRiver()
//{
//	// Margem central
//	vsml->pushMatrix(VSMathLib::MODEL);
//	shader.setUniform("color", grass);
//	vsml->scale(VSMathLib::MODEL, 14.0f, 0.6f, 1.0f);
//	vsml->matricesToGL();
//	glDrawElements(GL_TRIANGLES, faceCount*3, GL_UNSIGNED_INT, 0); 
//	vsml->popMatrix(VSMathLib::MODEL);
//
//
//
//	//Margem final
//	vsml->pushMatrix(VSMathLib::MODEL);
//	shader.setUniform("color", grass);
//	vsml->translate(VSMathLib::MODEL, 0.0f, 0.0f, -8.0f);
//	vsml->scale(VSMathLib::MODEL, 14.0f, 0.6f, 1.0f);
//	vsml->matricesToGL();
//	glDrawElements(GL_TRIANGLES, faceCount*3, GL_UNSIGNED_INT, 0); 
//	vsml->popMatrix(VSMathLib::MODEL);
//}
//
//void drawStreet()
//{
//	//Estrada
//	vsml->pushMatrix(VSMathLib::MODEL);
//	shader.setUniform("color", street);
//	vsml->translate(VSMathLib::MODEL, 0.0f, 0.0f, 4.0f);
//	vsml->scale(VSMathLib::MODEL, 14.0f, 0.5f, 7.0f);
//	// send matrices to uniform buffer
//	vsml->matricesToGL();
//	glDrawElements(GL_TRIANGLES, faceCount*3, GL_UNSIGNED_INT, 0);
//	vsml->popMatrix(VSMathLib::MODEL);
//
//	// Passeio
//	vsml->pushMatrix(VSMathLib::MODEL);
//	shader.setUniform("color", black);
//	vsml->translate(VSMathLib::MODEL, 0.0f, 0.0f, 8.0f);
//	vsml->scale(VSMathLib::MODEL, 14.0f, 0.6f, 1.0f);
//	vsml->matricesToGL();
//	glDrawElements(GL_TRIANGLES, faceCount*3, GL_UNSIGNED_INT, 0); 
//	vsml->popMatrix(VSMathLib::MODEL);
//}
//
//void drawFrog()
//{
//	//Cabeça
//	vsml->pushMatrix(VSMathLib::MODEL);
//	shader.setUniform("color", frog);
//	vsml->translate(VSMathLib::MODEL, moveX, 0.75f, moveZ);
//	vsml->scale(VSMathLib::MODEL, 0.5f, 0.5f, 0.5f);
//	vsml->matricesToGL();
//	glDrawElements(GL_TRIANGLES, faceCount*3, GL_UNSIGNED_INT, 0); 
//	vsml->popMatrix(VSMathLib::MODEL);
//
//	//Corpo
//	vsml->pushMatrix(VSMathLib::MODEL);
//	shader.setUniform("color", frog);
//	vsml->translate(VSMathLib::MODEL, moveX, 0.8f, moveZ + 0.5f);
//	vsml->matricesToGL();
//	glDrawElements(GL_TRIANGLES, faceCount*3, GL_UNSIGNED_INT, 0); 
//	vsml->popMatrix(VSMathLib::MODEL);
//}
//
//void drawLogCima()
//{
//	//Tronco
//	vsml->pushMatrix(VSMathLib::MODEL);
//	shader.setUniform("color", brown);
//	vsml->translate(VSMathLib::MODEL, startPosLog, 0.5f, -5.0f);
//	vsml->scale(VSMathLib::MODEL, 2.0f, 0.5f, 1.0f);
//	vsml->matricesToGL();
//	glDrawElements(GL_TRIANGLES, faceCount*3, GL_UNSIGNED_INT, 0); 
//	vsml->popMatrix(VSMathLib::MODEL);
//}
//
//void drawLogBaixo()
//{
//	//Tronco
//	vsml->pushMatrix(VSMathLib::MODEL);
//	shader.setUniform("color", brown);
//	vsml->translate(VSMathLib::MODEL, startPosLog, 0.5f, -3.5f);
//	vsml->scale(VSMathLib::MODEL, 2.0f, 0.5f, 1.0f);
//	vsml->matricesToGL();
//	glDrawElements(GL_TRIANGLES, faceCount * 3, GL_UNSIGNED_INT, 0);
//	vsml->popMatrix(VSMathLib::MODEL);
//}
//
//void drawCarCima()
//{
//	//Carro Cima
//	vsml->pushMatrix(VSMathLib::MODEL);
//	shader.setUniform("color", red);
//	vsml->translate(VSMathLib::MODEL, startPosCar, 1.0f, 3.0f);
//	vsml->scale(VSMathLib::MODEL, 2.0f, 1.0f, 1.0f);
//	vsml->matricesToGL();
//	glDrawElements(GL_TRIANGLES, faceCount*3, GL_UNSIGNED_INT, 0); 
//	vsml->popMatrix(VSMathLib::MODEL);
//
//	//Roda FE
//	vsml->pushMatrix(VSMathLib::MODEL);
//	shader.setUniform("color", black);
//	vsml->translate(VSMathLib::MODEL, startPosCar + 0.4f, 0.5f, 2.5f);
//	vsml->scale(VSMathLib::MODEL, 0.5f, 0.5f, 0.5f);
//	vsml->matricesToGL();
//	glDrawElements(GL_TRIANGLES, faceCount*3, GL_UNSIGNED_INT, 0); 
//	vsml->popMatrix(VSMathLib::MODEL);
//
//	//Roda FD
//	vsml->pushMatrix(VSMathLib::MODEL);
//	shader.setUniform("color", black);
//	vsml->translate(VSMathLib::MODEL, startPosCar + 0.4f, 0.5f, 3.5f);
//	vsml->scale(VSMathLib::MODEL, 0.5f, 0.5f, 0.5f);
//	vsml->matricesToGL();
//	glDrawElements(GL_TRIANGLES, faceCount*3, GL_UNSIGNED_INT, 0); 
//	vsml->popMatrix(VSMathLib::MODEL);
//
//	//Roda TE
//	vsml->pushMatrix(VSMathLib::MODEL);
//	shader.setUniform("color", black);
//	vsml->translate(VSMathLib::MODEL, startPosCar - 0.6f, 0.5f, 2.5f);
//	vsml->scale(VSMathLib::MODEL, 0.5f, 0.5f, 0.5f);
//	vsml->matricesToGL();
//	glDrawElements(GL_TRIANGLES, faceCount*3, GL_UNSIGNED_INT, 0); 
//	vsml->popMatrix(VSMathLib::MODEL);
//
//	//Roda TD
//	vsml->pushMatrix(VSMathLib::MODEL);
//	shader.setUniform("color", black);
//	vsml->translate(VSMathLib::MODEL, startPosCar - 0.6f, 0.5f, 3.5f);
//	vsml->scale(VSMathLib::MODEL, 0.5f, 0.5f, 0.5f);
//	vsml->matricesToGL();
//	glDrawElements(GL_TRIANGLES, faceCount*3, GL_UNSIGNED_INT, 0); 
//	vsml->popMatrix(VSMathLib::MODEL);
//}
//
//void drawCarBaixo()
//{
//	//Carro Cima
//	vsml->pushMatrix(VSMathLib::MODEL);
//	shader.setUniform("color", red);
//	vsml->translate(VSMathLib::MODEL, startPosCar, 1.0f, 6.5f);
//	vsml->scale(VSMathLib::MODEL, 2.0f, 1.0f, 1.0f);
//	vsml->matricesToGL();
//	glDrawElements(GL_TRIANGLES, faceCount * 3, GL_UNSIGNED_INT, 0);
//	vsml->popMatrix(VSMathLib::MODEL);
//
//	//Roda FE
//	vsml->pushMatrix(VSMathLib::MODEL);
//	shader.setUniform("color", black);
//	vsml->translate(VSMathLib::MODEL, startPosCar + 0.4f, 0.5f, 6.0f);
//	vsml->scale(VSMathLib::MODEL, 0.5f, 0.5f, 0.5f);
//	vsml->matricesToGL();
//	glDrawElements(GL_TRIANGLES, faceCount * 3, GL_UNSIGNED_INT, 0);
//	vsml->popMatrix(VSMathLib::MODEL);
//
//	//Roda FD
//	vsml->pushMatrix(VSMathLib::MODEL);
//	shader.setUniform("color", black);
//	vsml->translate(VSMathLib::MODEL, startPosCar + 0.4f, 0.5f, 7.0f);
//	vsml->scale(VSMathLib::MODEL, 0.5f, 0.5f, 0.5f);
//	vsml->matricesToGL();
//	glDrawElements(GL_TRIANGLES, faceCount * 3, GL_UNSIGNED_INT, 0);
//	vsml->popMatrix(VSMathLib::MODEL);
//
//	//Roda TE
//	vsml->pushMatrix(VSMathLib::MODEL);
//	shader.setUniform("color", black);
//	vsml->translate(VSMathLib::MODEL, startPosCar - 0.6f, 0.5f, 6.0f);
//	vsml->scale(VSMathLib::MODEL, 0.5f, 0.5f, 0.5f);
//	vsml->matricesToGL();
//	glDrawElements(GL_TRIANGLES, faceCount * 3, GL_UNSIGNED_INT, 0);
//	vsml->popMatrix(VSMathLib::MODEL);
//
//	//Roda TD
//	vsml->pushMatrix(VSMathLib::MODEL);
//	shader.setUniform("color", black);
//	vsml->translate(VSMathLib::MODEL, startPosCar - 0.6f, 0.5f, 7.0f);
//	vsml->scale(VSMathLib::MODEL, 0.5f, 0.5f, 0.5f);
//	vsml->matricesToGL();
//	glDrawElements(GL_TRIANGLES, faceCount * 3, GL_UNSIGNED_INT, 0);
//	vsml->popMatrix(VSMathLib::MODEL);
//}
//
//void drawBusCima()
//{
//	//Autobus
//	vsml->pushMatrix(VSMathLib::MODEL);
//	shader.setUniform("color", blue);
//	vsml->translate(VSMathLib::MODEL, startPosBus, 1.0f, 1.5f);
//	vsml->scale(VSMathLib::MODEL, 4.0f, 2.0f, 1.0f);
//	vsml->matricesToGL();
//	glDrawElements(GL_TRIANGLES, faceCount * 3, GL_UNSIGNED_INT, 0);
//	vsml->popMatrix(VSMathLib::MODEL);
//
//	//Roda FE
//	vsml->pushMatrix(VSMathLib::MODEL);
//	shader.setUniform("color", black);
//	vsml->translate(VSMathLib::MODEL, startPosBus + 0.9f, 0.5f, 1.0f);
//	vsml->scale(VSMathLib::MODEL, 0.5f, 0.5f, 0.5f);
//	vsml->matricesToGL();
//	glDrawElements(GL_TRIANGLES, faceCount * 3, GL_UNSIGNED_INT, 0);
//	vsml->popMatrix(VSMathLib::MODEL);
//
//	//Roda FD
//	vsml->pushMatrix(VSMathLib::MODEL);
//	shader.setUniform("color", black);
//	vsml->translate(VSMathLib::MODEL, startPosBus + 0.9f, 0.5f, 2.0f);
//	vsml->scale(VSMathLib::MODEL, 0.5f, 0.5f, 0.5f);
//	vsml->matricesToGL();
//	glDrawElements(GL_TRIANGLES, faceCount * 3, GL_UNSIGNED_INT, 0);
//	vsml->popMatrix(VSMathLib::MODEL);
//
//	//Roda TE
//	vsml->pushMatrix(VSMathLib::MODEL);
//	shader.setUniform("color", black);
//	vsml->translate(VSMathLib::MODEL, startPosBus - 1.1f, 0.5f, 1.0f);
//	vsml->scale(VSMathLib::MODEL, 0.5f, 0.5f, 0.5f);
//	vsml->matricesToGL();
//	glDrawElements(GL_TRIANGLES, faceCount * 3, GL_UNSIGNED_INT, 0);
//	vsml->popMatrix(VSMathLib::MODEL);
//
//	//Roda TD
//	vsml->pushMatrix(VSMathLib::MODEL);
//	shader.setUniform("color", black);
//	vsml->translate(VSMathLib::MODEL, startPosBus - 1.1f, 0.5f, 2.0f);
//	vsml->scale(VSMathLib::MODEL, 0.5f, 0.5f, 0.5f);
//	vsml->matricesToGL();
//	glDrawElements(GL_TRIANGLES, faceCount * 3, GL_UNSIGNED_INT, 0);
//	vsml->popMatrix(VSMathLib::MODEL);
//}
//
//void drawBusBaixo()
//{
//	//Autobus
//	vsml->pushMatrix(VSMathLib::MODEL);
//	shader.setUniform("color", blue);
//	vsml->translate(VSMathLib::MODEL, startPosBus, 1.0f, 5.0f);
//	vsml->scale(VSMathLib::MODEL, 4.0f, 2.0f, 1.0f);
//	vsml->matricesToGL();
//	glDrawElements(GL_TRIANGLES, faceCount*3, GL_UNSIGNED_INT, 0); 
//	vsml->popMatrix(VSMathLib::MODEL);
//
//	//Roda FE
//	vsml->pushMatrix(VSMathLib::MODEL);
//	shader.setUniform("color", black);
//	vsml->translate(VSMathLib::MODEL, startPosBus + 0.9f, 0.5f, 4.5f);
//	vsml->scale(VSMathLib::MODEL, 0.5f, 0.5f, 0.5f);
//	vsml->matricesToGL();
//	glDrawElements(GL_TRIANGLES, faceCount*3, GL_UNSIGNED_INT, 0); 
//	vsml->popMatrix(VSMathLib::MODEL);
//
//	//Roda FD
//	vsml->pushMatrix(VSMathLib::MODEL);
//	shader.setUniform("color", black);
//	vsml->translate(VSMathLib::MODEL, startPosBus + 0.9f, 0.5f, 5.5f);
//	vsml->scale(VSMathLib::MODEL, 0.5f, 0.5f, 0.5f);
//	vsml->matricesToGL();
//	glDrawElements(GL_TRIANGLES, faceCount*3, GL_UNSIGNED_INT, 0); 
//	vsml->popMatrix(VSMathLib::MODEL);
//
//	//Roda TE
//	vsml->pushMatrix(VSMathLib::MODEL);
//	shader.setUniform("color", black);
//	vsml->translate(VSMathLib::MODEL, startPosBus - 1.1f, 0.5f, 4.5f);
//	vsml->scale(VSMathLib::MODEL, 0.5f, 0.5f, 0.5f);
//	vsml->matricesToGL();
//	glDrawElements(GL_TRIANGLES, faceCount*3, GL_UNSIGNED_INT, 0); 
//	vsml->popMatrix(VSMathLib::MODEL);
//
//	//Roda TD
//	vsml->pushMatrix(VSMathLib::MODEL);
//	shader.setUniform("color", black);
//	vsml->translate(VSMathLib::MODEL, startPosBus - 1.1f, 0.5f, 5.5f);
//	vsml->scale(VSMathLib::MODEL, 0.5f, 0.5f, 0.5f);
//	vsml->matricesToGL();
//	glDrawElements(GL_TRIANGLES, faceCount*3, GL_UNSIGNED_INT, 0); 
//	vsml->popMatrix(VSMathLib::MODEL);
//}
//
//void drawTurtleCima()
//{
//	//Corpo tartaruga
//	vsml->pushMatrix(VSMathLib::MODEL);
//	shader.setUniform("color", grass);
//	vsml->translate(VSMathLib::MODEL, startPosTurtle, 1.0f, -6.5f);
//	vsml->scale(VSMathLib::MODEL, 1.0f, 1.0f, 1.0f);
//	vsml->matricesToGL();
//	glDrawElements(GL_TRIANGLES, faceCount * 3, GL_UNSIGNED_INT, 0);
//	vsml->popMatrix(VSMathLib::MODEL);
//
//	//Pata FE
//	vsml->pushMatrix(VSMathLib::MODEL);
//	shader.setUniform("color", yellow);
//	vsml->translate(VSMathLib::MODEL, startPosTurtle + 0.5f, 0.5f, -7.0f);
//	vsml->scale(VSMathLib::MODEL, 0.5f, 0.5f, 0.5f);
//	vsml->matricesToGL();
//	glDrawElements(GL_TRIANGLES, faceCount * 3, GL_UNSIGNED_INT, 0);
//	vsml->popMatrix(VSMathLib::MODEL);
//
//	//Pata FD
//	vsml->pushMatrix(VSMathLib::MODEL);
//	shader.setUniform("color", yellow);
//	vsml->translate(VSMathLib::MODEL, startPosTurtle + 0.5f, 0.5f, -6.0f);
//	vsml->scale(VSMathLib::MODEL, 0.5f, 0.5f, 0.5f);
//	vsml->matricesToGL();
//	glDrawElements(GL_TRIANGLES, faceCount * 3, GL_UNSIGNED_INT, 0);
//	vsml->popMatrix(VSMathLib::MODEL);
//
//	//Pata TE
//	vsml->pushMatrix(VSMathLib::MODEL);
//	shader.setUniform("color", yellow);
//	vsml->translate(VSMathLib::MODEL, startPosTurtle - 0.5f, 0.5f, -7.0f);
//	vsml->scale(VSMathLib::MODEL, 0.5f, 0.5f, 0.5f);
//	vsml->matricesToGL();
//	glDrawElements(GL_TRIANGLES, faceCount * 3, GL_UNSIGNED_INT, 0);
//	vsml->popMatrix(VSMathLib::MODEL);
//
//	//Pata TD
//	vsml->pushMatrix(VSMathLib::MODEL);
//	shader.setUniform("color", yellow);
//	vsml->translate(VSMathLib::MODEL, startPosTurtle - 0.5f, 0.5f, -6.0f);
//	vsml->scale(VSMathLib::MODEL, 0.5f, 0.5f, 0.5f);
//	vsml->matricesToGL();
//	glDrawElements(GL_TRIANGLES, faceCount * 3, GL_UNSIGNED_INT, 0);
//	vsml->popMatrix(VSMathLib::MODEL);
//}
//
//void drawTurtleBaixo()
//{
//	//Corpo tartaruga
//	vsml->pushMatrix(VSMathLib::MODEL);
//	shader.setUniform("color", grass);
//	vsml->translate(VSMathLib::MODEL, startPosTurtle, 1.0f, -2.0f);
//	vsml->scale(VSMathLib::MODEL, 1.0f, 1.0f, 1.0f);
//	vsml->matricesToGL();
//	glDrawElements(GL_TRIANGLES, faceCount*3, GL_UNSIGNED_INT, 0);
//	vsml->popMatrix(VSMathLib::MODEL);
//
//	//Pata FE
//	vsml->pushMatrix(VSMathLib::MODEL);
//	shader.setUniform("color", yellow);
//	vsml->translate(VSMathLib::MODEL, startPosTurtle + 0.5f, 0.5f, -2.5f);
//	vsml->scale(VSMathLib::MODEL, 0.5f, 0.5f, 0.5f);
//	vsml->matricesToGL();
//	glDrawElements(GL_TRIANGLES, faceCount*3, GL_UNSIGNED_INT, 0);
//	vsml->popMatrix(VSMathLib::MODEL);
//
//	//Pata FD
//	vsml->pushMatrix(VSMathLib::MODEL);
//	shader.setUniform("color", yellow);
//	vsml->translate(VSMathLib::MODEL, startPosTurtle + 0.5f, 0.5f, -1.5f);
//	vsml->scale(VSMathLib::MODEL, 0.5f, 0.5f, 0.5f);
//	vsml->matricesToGL();
//	glDrawElements(GL_TRIANGLES, faceCount*3, GL_UNSIGNED_INT, 0);
//	vsml->popMatrix(VSMathLib::MODEL);
//
//	//Pata TE
//	vsml->pushMatrix(VSMathLib::MODEL);
//	shader.setUniform("color", yellow);
//	vsml->translate(VSMathLib::MODEL, startPosTurtle - 0.5f, 0.5f, -2.5f);
//	vsml->scale(VSMathLib::MODEL, 0.5f, 0.5f, 0.5f);
//	vsml->matricesToGL();
//	glDrawElements(GL_TRIANGLES, faceCount*3, GL_UNSIGNED_INT, 0);
//	vsml->popMatrix(VSMathLib::MODEL);
//
//	//Pata TD
//	vsml->pushMatrix(VSMathLib::MODEL);
//	shader.setUniform("color", yellow);
//	vsml->translate(VSMathLib::MODEL, startPosTurtle - 0.5f, 0.5f, -1.5f);
//	vsml->scale(VSMathLib::MODEL, 0.5f, 0.5f, 0.5f);
//	vsml->matricesToGL();
//	glDrawElements(GL_TRIANGLES, faceCount*3, GL_UNSIGNED_INT, 0);
//	vsml->popMatrix(VSMathLib::MODEL);
//}


void renderScene(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// load identity matrices
	vsml->loadIdentity(VSMathLib::VIEW);
	vsml->loadIdentity(VSMathLib::MODEL);
	if(isIn3)
	{
		eyeX = moveX;
		eyeY = 3.0f;
		eyeZ = moveZ + 4.0f;
		dirX = camX;
		dirY = 1.0f;
		dirZ = camZ;
	}
	else if(isIn4)
	{
		eyeX = camX + moveX; 
		eyeY = 3.0f; 
		eyeZ = camZ + moveZ; 
		dirX = moveX; 
		dirY = 1.0f; 
		dirZ = moveZ;
	}
	// set the camera using a function similar to gluLookAt
	vsml->lookAt(eyeX, eyeY, eyeZ, dirX, dirY, dirZ, upX, upY, upZ);

	// use our shader
	glUseProgram(shader.getProgramIndex());

	/////////////////////////////////////////////////////////
	glBindVertexArray(vao);

	river.draw(vsml, shader);
	riverSide.draw(vsml, shader);

	road.draw(vsml, shader);
	roadside.draw(vsml, shader);
	car.draw(vsml, shader);
	bus.draw(vsml, shader);
	//drawStreet();
	//drawRiver();
	//drawFrog();
	//if(random == 0)
	//{
	//	drawLogCima();
	//	drawCarCima();
	//}
	//else if(random == 1)
	//{
	//		drawTurtleCima();
	//		drawBusCima();
	//}
	//else if( random == 2)
	//{
	//	drawLogBaixo();
	//	drawBusBaixo();
	//}
	//else
	//{
	//	drawTurtleBaixo();
	//	drawCarBaixo();
	//}

	/////////////////////////////////////////////////////////

	//swap buffers
	glutSwapBuffers();
}


// ------------------------------------------------------------
//
// Events from the Keyboard
//

void processKeys(unsigned char key, int xx, int yy)
{
	switch(key) {

	case 27:
		glutLeaveMainLoop();
		break;

	case '1':
		vsml->loadIdentity(VSMathLib::PROJECTION);
		eyeX = 0; eyeY = 16; eyeZ = 5; dirX = 0; dirY = 0; dirZ = 0; upX = 0; upY = 0; upZ = -1;
		vsml->perspective(60, ratio, 0.1f, 25);
		isIn3 = false;
		isIn4 = false;
		break;

	case '2':
		vsml->loadIdentity(VSMathLib::PROJECTION);
		eyeX = 0; eyeY = 5; eyeZ = 0; dirX = 0; dirY = 0; dirZ = 0; upX = 0; upY = 0; upZ = -1;
		vsml->ortho(-8,8, -9,9, 0,5);
		isIn3 = false;
		isIn4 = false;
		break;

	case '3':
		vsml->loadIdentity(VSMathLib::PROJECTION);
		eyeX = moveX; eyeY = 4.0f; eyeZ = moveZ+3; dirX = camX; dirY = 1.0f; dirZ = camZ; upX = 0; upY = 1; upZ = 0;
		vsml->perspective(80, ratio, 0.1, 50);
		isIn3 = true;
		isIn4 = false;
		break;

	case '4':
		vsml->loadIdentity(VSMathLib::PROJECTION);
		eyeX = camX + moveX; eyeY = 3.0f; eyeZ = camZ + moveZ; dirX = moveX; dirY = 1.0f; dirZ = moveZ; upX = 0; upY = 1; upZ = 0;
		vsml->perspective(80, ratio, 0.1, 50);
		isIn3 = false;
		isIn4 = true;
		break;

	case 'o':
		moveX -= 1.0f;
		break;

	case 'p':
		moveX += 1.0f;
		break;

	case 'a':
		moveZ += 1.0f;
		break;

	case 'q':
		moveZ -= 1.0f;
		break;
	}

	//  uncomment this if not using an idle func
	//	glutPostRedisplay();
}

void processSpecialKeys(int key, int x, int y) {

	switch(key) {
	case GLUT_KEY_LEFT :
		moveX -= 1.0f;
		break;
	case GLUT_KEY_RIGHT :
		moveX += 1.0f; 
		break;
	case GLUT_KEY_UP :
		moveZ -= 1.0f; 
		break;
	case GLUT_KEY_DOWN :
		moveZ += 1.0f;
		break;
	}
}


// ------------------------------------------------------------
//
// Mouse Events
//

void processMouseButtons(int button, int state, int xx, int yy)
{
	// start tracking the mouse
	if (state == GLUT_DOWN)  {
		startX = xx;
		startY = yy;
		if (button == GLUT_LEFT_BUTTON)
			tracking = 1;
		else if (button == GLUT_RIGHT_BUTTON){
			tracking = 2;
		}
	}

	//stop tracking the mouse
	else if (state == GLUT_UP) {
		if (tracking == 1) {
			alpha -= (xx - startX);

		}
		else if (tracking == 2) {
			MousePositionX = xx;
			MousePositionZ = yy;
		}

		tracking = 0;
	}
}

// Track mouse motion while buttons are pressed

void processMouseMotion(int xx, int yy)
{
	int deltaX, deltaY;
	float alphaAux;

	deltaX =  - xx + startX;
	deltaY =    yy - startY;

	// left mouse button: move camera
	if (tracking == 1) 
	{
		alphaAux = alpha + deltaX;

		camX = 10 * sin(alphaAux * 3.14f / 180.0f);
		camZ = 10 * cos(alphaAux * 3.14f / 180.0f);
	}

	// right mouse button: move frog
	else if (tracking == 2) {

		if (xx > 0){
			if (xx > MousePositionX && xx - MousePositionX >= 1)
				moveX += 0.1f;
			else if (xx < MousePositionX && MousePositionX - xx >= 1)
				moveX -= 0.1f;
		}

		if (yy > 0){
			if (yy > MousePositionZ && yy-MousePositionZ >=1)
				moveZ += 0.1f;
			else if (yy < MousePositionZ && MousePositionZ-yy>=1)
				moveZ -= 0.1f;
		}

		MousePositionX = xx;
		MousePositionZ = yy;
	}
//  uncomment this if not using an idle func
//	glutPostRedisplay();
}

void myTimer(int value) {
	tActual = glutGet(GLUT_ELAPSED_TIME);
	tDif = tActual - tAnterior;
	if (tDif >= 3000){
		speed *= 1.5f;
		tAnterior = tActual;
	}
	startPosBus += speed;
	startPosCar += speed*1.5f;
	startPosLog += speed*2.0f;
	startPosTurtle += speed*2.5f;
	if (startPosBus > 9.0f || startPosCar > 9.0f){
		startPosCar = -6.0f;
		startPosBus = -5.0f;
		startPosLog = -6.0f;
		startPosTurtle = -6.0f;
		random = rand() % 4;
	}
	glutPostRedisplay();
	glutTimerFunc(1000/60, myTimer, 1);
}

// --------------------------------------------------------
//
// Shader Stuff
//


GLuint setupShaders() {

	// Shader for models
	shader.init();
	shader.loadShader(VSShaderLib::VERTEX_SHADER, "shaders/helloWorld.vert");
	shader.loadShader(VSShaderLib::FRAGMENT_SHADER, "shaders/helloWorld.frag");

	// set semantics for the shader variables
	shader.setProgramOutput(0,"outputF");
	shader.setVertexAttribName(VSShaderLib::VERTEX_COORD_ATTRIB, "position");


	shader.prepareProgram();

	printf("InfoLog for Hello World Shader\n%s\n\n", shader.getAllInfoLogs().c_str());

	return(shader.isProgramValid());
}



// ------------------------------------------------------------
//
// Model loading and OpenGL setup
//
void initOpenGL()
{
	// set the camera position based on its spherical coordinates
	camX = 10 * sin(alpha * 3.14f / 180.0f) ;
	camZ = 10 * cos(alpha * 3.14f / 180.0f) ;

	isIn3 = false;
	isIn4 = false;

	eyeX = 0; 
	eyeY = 16; 
	eyeZ = 5; 
	dirX = 0; 
	dirY = 0; 
	dirZ = 0; 
	upX = 0; 
	upY = 0; 
	upZ = -1;

	moveX = 0.0f;
	moveZ = 7.5f;

	random = rand() % 4;

	// some GL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_MULTISAMPLE);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	// create the VAO
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// create buffers for our vertex data
	GLuint buffers[4];
	glGenBuffers(4, buffers);

	//vertex coordinates buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VSShaderLib::VERTEX_COORD_ATTRIB);
	glVertexAttribPointer(VSShaderLib::VERTEX_COORD_ATTRIB, 4, GL_FLOAT, 0, 0, 0);

	//texture coordinates buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffers[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(texCoords), texCoords, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VSShaderLib::TEXTURE_COORD_ATTRIB);
	glVertexAttribPointer(VSShaderLib::TEXTURE_COORD_ATTRIB, 2, GL_FLOAT, 0, 0, 0);

	//normals buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffers[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(normals), normals, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VSShaderLib::NORMAL_ATTRIB);
	glVertexAttribPointer(VSShaderLib::NORMAL_ATTRIB, 3, GL_FLOAT, 0, 0, 0);

	//index buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[3]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(faceIndex), faceIndex, GL_STATIC_DRAW);

	// unbind the VAO
	glBindVertexArray(0);
}


void initVSL() {
	vsml = VSMathLib::getInstance();
	// tell VSL the uniform block name
	vsml->setUniformBlockName("Matrices");
	// set semantics for the matrix variable
	vsml->setUniformName(VSMathLib::PROJ_VIEW_MODEL, "pvm");
}

// ------------------------------------------------------------
//
// Main function
//


int main(int argc, char **argv) {

	//  GLUT initialization
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA|GLUT_MULTISAMPLE);

	glutInitContextVersion (3, 3);
	glutInitContextProfile (GLUT_CORE_PROFILE );
	glutInitContextFlags(GLUT_DEBUG);

	glutInitWindowPosition(100,100);
	glutInitWindowSize(512,512);
	glutCreateWindow("Assignment 1");

	//  Callback Registration
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);

	//	Mouse and Keyboard Callbacks
	glutKeyboardFunc(processKeys);
	glutSpecialFunc(processSpecialKeys);
	glutMouseFunc(processMouseButtons);
	glutMotionFunc(processMouseMotion);

	// 
	glutTimerFunc(30, myTimer, 1);

	//	return from main loop
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	//	Init GLEW
	glewExperimental = GL_TRUE;
	glewInit();

	printf ("Vendor: %s\n", glGetString (GL_VENDOR));
	printf ("Renderer: %s\n", glGetString (GL_RENDERER));
	printf ("Version: %s\n", glGetString (GL_VERSION));
	printf ("GLSL: %s\n", glGetString (GL_SHADING_LANGUAGE_VERSION));

	if (!setupShaders())
		return(1);

	initOpenGL();

	initVSL();

	tAnterior = glutGet(GLUT_ELAPSED_TIME);

	//  GLUT main loop
	glutMainLoop();

	return(0);

}

