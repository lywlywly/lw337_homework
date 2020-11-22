#pragma once

#include "ofMain.h"

class Star 
{
public:
	Star();//get a fixed random instance variable offset for an object

	void update(ofVec2f target);
	void draw();

	ofVec2f pos;
	float offset;//add to some randomness
	float angle;		// angle in degrees
	float size = 10.;
	float lerp = 1.;	// speed, 0-1

	ofColor color;
};

class ofApp : public ofBaseApp 
{
public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);

	ofSoundPlayer soundPlayer;
	bool isAuto;
	int mode;
	float bornTime;
	float aliveTime;
	vector<Star> Stars;
	vector<Star> eraseStars;
};