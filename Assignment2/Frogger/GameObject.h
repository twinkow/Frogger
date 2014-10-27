#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Entity.h"
//#include "DrawComponents.h"



class GameObject : Entity
{
public:

	GameObject();
	~GameObject();

	void draw();

	void update(double delta_t);

	void initialize();

protected:
	int verticeCount;
	int faceCount;

	// COLORS
	float blue[4];
	float water[4];
	float grass[4];
	float frog[4];
	float street[4];
	float black[4];
	float white[4];
	float brown[4];
	float red[4];
	float yellow[4];

};

#endif

