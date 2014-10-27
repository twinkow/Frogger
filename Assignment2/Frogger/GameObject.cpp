#include "GameObject.h"




GameObject::GameObject(){}

GameObject::~GameObject(){}

void GameObject::draw(){}

void GameObject::update(double delta_t){}

void GameObject::initialize(){
	verticeCount = 24;
	faceCount = 12;

// COLORS
	blue[0] = 0.0f;	blue[1] = 0.0f; blue[2] = 0.5f; blue[3] = 1.0f;
	water[0] = 0.0f; water[1] = 0.0f; water[2] = 1.0f; water[3] = 1.0f;
	grass[0] = 0.1f; grass[1] = 0.8f; grass[2] = 0.1f; grass[3] = 1.0f;
	frog[0] = 0.0f; frog[1] = 0.5f; frog[2] = 0.0f; frog[3] = 1.0f;
	street[0] = 0.5f; street[1] = 0.5f; street[2] = 0.5f; street[3] = 1.0f;
	black[0] = 0.0f; black[1] = 0.0f; black[2] = 0.0f; black[3] = 1.0f;
	white[0] = 1.0f; white[1] = 1.0f; white[2] = 1.0f; white[3] = 1.0f;
	brown[0] = 0.4f; brown[1] = 0.2f; brown[2] = 0.0f; brown[3] = 1.0f;
	red[0] = 1.0f; red[1] = 0.0f; red[2] = 0.0f; red[3] = 1.0f;
	yellow[0] = 1.0f; yellow[1] = 0.8f; yellow[2] = 0.0f; yellow[3] = 1.0f;
}