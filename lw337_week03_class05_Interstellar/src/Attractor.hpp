#pragma once
#include "ofMain.h"

#include "Mover.hpp"

class Attractor {
public:
	
	Attractor();		
	Attractor(glm::vec2 _pos, float _mass);	
	
	glm::vec2 getForce(Mover m);
	
	void draw();
	
	glm::vec2 pos;
	float mass;
	
	const float G = .4;		
	
};
