#pragma once		
#include "ofMain.h"



class snow
{
public:
	snow();

	void update();
	void draw();

	float size = 30;
	ofVec3f pos;
	ofVec3f v;
	ofVec3f a;
	bool isStopped = false;


};


