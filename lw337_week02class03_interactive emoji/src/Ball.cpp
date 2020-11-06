#include "Ball.h"

// constructor


void emoji::drawHappy()
{
	ofFill();
	ofSetColor(255, 215, 0);
	ofDrawCircle(x, y, 200);
	ofPushStyle();
	ofNoFill();
	ofSetColor(0);
	ofSetLineWidth(5);
	ofDrawCircle(x, y, 200);
	ofPopStyle();

	ofSetLineWidth(6);
	ofSetColor(0);
	ofPolyline line1;
	line1.curveTo(x-102, y+76);
	line1.curveTo(x-102, y+76);
	line1.curveTo(x-64, y+111);
	line1.curveTo(x-2, y+128);
	line1.curveTo(x+64, y+111);
	line1.curveTo(x+98, y+76);
	line1.curveTo(x+98, y+76);
	line1.draw();


	ofPolyline line2;
	line2.curveTo(x-112, y-59);
	line2.curveTo(x-112, y-59);
	line2.curveTo(x-103, y-74);
	line2.curveTo(x-89, y-82);
	line2.curveTo(x-75, y-74);
	line2.curveTo(x-66, y-59);
	line2.curveTo(x-66, y-59);
	line2.draw();

	ofPolyline line3;
	line3.curveTo(x+112, y-59);
	line3.curveTo(x+112, y-59);
	line3.curveTo(x+103, y-74);
	line3.curveTo(x+89, y-82);
	line3.curveTo(x+75, y-74);
	line3.curveTo(x+64, y-59);
	line3.curveTo(x+64, y-59);
	line3.draw();

	ofSetColor(255, 0, 0);
	ofFill();
	ofDrawCircle(x, y+3, 9);
}


void emoji::drawSad()
{
	ofFill();
	ofSetColor(255, 215, 0);
	ofDrawCircle(x, y, 200);
	ofPushStyle();
	ofNoFill();
	ofSetColor(0);
	ofSetLineWidth(5);
	ofDrawCircle(x, y, 200);
	ofPopStyle();

	ofSetLineWidth(6);
	ofSetColor(0);
	ofPolyline line1;
	line1.curveTo(x-102, y+126);
	line1.curveTo(x-102, y+126);
	line1.curveTo(x-64, y+91);
	line1.curveTo(x-2, y+74);
	line1.curveTo(x+64, y+91);
	line1.curveTo(x+98, y+126);
	line1.curveTo(x+98, y+126);
	line1.draw();


	ofPolyline line2;
	line2.curveTo(x-112, y-59);
	line2.curveTo(x-112, y-59);
	line2.curveTo(x-103, y-44);
	line2.curveTo(x-89, y-36);
	line2.curveTo(x-75, y-44);
	line2.curveTo(x-66, y-59);
	line2.curveTo(x-66, y-59);
	line2.draw();

	ofPolyline line3;
	line3.curveTo(x+112, y-59);
	line3.curveTo(x+112, y-59);
	line3.curveTo(x+103, y-44);
	line3.curveTo(x+89, y-36);
	line3.curveTo(x+75, y-44);
	line3.curveTo(x+64, y-59);
	line3.curveTo(x+64, y-59);
	line3.draw();

	ofSetColor(0, 0, 255);
	ofFill();
	ofDrawCircle(x, y+3, 9);

	ofDrawRectangle(x-107, y-34, 36, 80);
	ofDrawRectangle(x+69, y-34, 36, 80);
}


Ball::Ball() {

	// inside the constructor you initialize the object's variables

	// random radius between 10 and 50
	radius = ofRandom(10,50);			

	// random color
	float red	= ofRandom(0,255);
	float green	= ofRandom(0,255);		
	float blue	= ofRandom(0,255);
	color = ofColor(red, green, blue);

	// random position in window
	x = ofRandom(radius, ofGetWidth()  - radius);
	y = ofRandom(radius, ofGetHeight() - radius);

	// random x and y speeds/directions between -10 and 10
	dirX = 3;
	dirY = 3;
}

// update position, etc.
void Ball::update() {

	x+=dirX;	// move along x by amount of dirX
	y+=dirY;	// move along y by amount of dirY

	// check for bounces at edges of window:

	// check left
	if (x <= radius) {
		x = radius;			// set the position back to the edge of window
		dirX = -dirX;		// and reverse direction
	}
	// check right
	else if (x >= ofGetWidth() - radius) {
		x = ofGetWidth() - radius;			// similar to above
		dirX = -dirX;
	}

	// check top and bottom
	if (y <= radius) {
		y = radius;
		dirY = -dirY;
	}
	else if (y >= ofGetHeight() - radius) {
		y = ofGetHeight() - radius;
		dirY = -dirY;
	}
}


// draw the ball
void Ball::draw() {

	ofSetColor(color);				// set the GLOBAL color
	ofDrawCircle(x,y, radius);		// and draw
}