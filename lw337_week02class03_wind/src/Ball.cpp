#include "Ball.h"


Wind::Wind()
{
	strength = 0;
}

void Wind::increaseWind()
{
	strength++;
}

void Wind::decreaseWind()
{
	strength--;
}

void Wind::changeDir()
{
	ofVec2f center = ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2);
	ofVec2f mouse;
	mouse.set(ofGetMouseX(), ofGetMouseY());
	ofSetColor(255);

	float rad = atan2(mouse.y- ofGetHeight()/2, mouse.x- ofGetWidth()/2);
	float angle = ofRadToDeg(rad);
	ofDrawLine(center, mouse);
	ofPushMatrix();//adapted from week2 class 4 code "Atan2"

	ofTranslate(mouse);
	ofRotate(angle);
	ofVec3f p1 = ofVec3f(0, 0);
	ofVec3f p2 = p1 - ofVec3f(30, 10);	
	ofVec3f p3 = p1 - ofVec3f(30, -10);
	ofDrawTriangle(p1, p2, p3);

	ofPopMatrix();

	ofVec2f dir;
	dir = mouse - center;
	dir.normalize();
	strengthX = dir.x*strength;
	strengthY = dir.y*strength;
}


Ball::Ball() 
{	
	radius = ofRandom(5,50);			

	float red	= ofRandom(0,255);
	float green	= ofRandom(0,255);		
	float blue	= ofRandom(0,255);
	color = ofColor(red, green, blue);

	x = ofRandom(radius, ofGetWidth()  - radius);
	y = ofRandom(radius, ofGetHeight() - radius);

	
	dirX = 0;
	dirY = 0;
}

void Ball::update(Wind wind) {

	x+=10*wind.strengthX/radius;
	y+=10*wind.strengthY/radius;	

	if (x <= radius) {
		x = radius;			
		dirX = -dirX;	
	}
	else if (x >= ofGetWidth() - radius) {
		x = ofGetWidth() - radius;		
		dirX = -dirX;
	}

	if (y <= radius) {
		y = radius;
		dirY = -dirY;
	}
	else if (y >= ofGetHeight() - radius) {
		y = ofGetHeight() - radius;
		dirY = -dirY;
	}
}


void Ball::draw() {

	ofSetColor(color);				
	ofDrawCircle(x,y, radius);		
}






