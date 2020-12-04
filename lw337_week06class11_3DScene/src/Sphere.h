

#pragma once
#include "ofMain.h"

class Sphere
{
public:

	Sphere();
	Sphere(glm::vec3 _pos, float _radius);

	void setup();
	void update();
	void draw();

	void setVelocity(glm::vec3 _vel);
	void applyForce(glm::vec3 force);

	// bounce off walls
	void bounceWalls(float left, float right, float top, float bottom, float front, float back);

	glm::vec3 pos, vel, acc;

	float radius;
	ofColor color;
	float aliveTime;
	float bornTime;
	bool takenIntoScore=false;
};
