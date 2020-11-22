#include "ofApp.h"

Star::Star() //adapted from week 02 class 04 sample code "followers"
{
	offset = ofRandom(-50, 50);
}

void Star::update(ofVec2f target) 
{
	pos = pos * (1. - lerp) + target * lerp; // move "lerp" % to target
	ofVec3f direction = target - pos;
	float radians = atan2(direction.y, direction.x);	// atan2 returns angle in radians
	angle = ofRadToDeg(radians);	// convert radians to degrees
}

void Star::draw() 
{
	// triangle
	ofVec3f p1 = ofVec3f(0, offset);	// front
	ofVec3f p2 = p1 - ofVec3f(0.2*size, 0.1*size + offset);	// rear pt 1
	ofVec3f p3 = p1 - ofVec3f(0.2*size, -0.1*size + offset);	// rear pt 2 

	ofPushMatrix();
	ofTranslate(pos);
	ofRotate(angle);
	ofPushStyle();
	ofSetColor(color);
	ofDrawTriangle(p1, p2, p3);
	ofPopStyle();
	ofPopMatrix();
}


void ofApp::setup() 
{
	bornTime = ofGetElapsedTimef();
	mode = 1;
	soundPlayer.load("Aurelion Sol,the Star Forger.mp3");
	soundPlayer.setLoop(true);
	soundPlayer.play();
	ofBackground(255);
	ofSetBackgroundAuto(false);

	for (int i = 0; i < 5000; i++) 
	{
		Star Star;
		Star.pos = ofVec2f(0);
		Star.lerp = ofMap(i, 0, 5000, .004, .02);	// set interpolation "speed", slow to fast
		Star.size = ofMap(i, 0, 5000, 5, 0.2);		// set size, large to small
		float hue = ofMap(i, 0, 5000, 125, 255);
		Star.color = ofColor::fromHsb(hue, 255, 220);	// hue, saturation, brightness
		Stars.push_back(Star);
	}

	for (int i = 0; i < 5000; i++) 
	{

		Star Star;
		Star.pos = ofVec2f(0);
		Star.lerp = ofMap(i, 0, 5000, .004, .02);	// set interpolation "speed", slow to fast
		Star.size = ofMap(i, 0, 5000, 3, 0.1);		// set size, large to small
		Star.color = ofColor::white;	// hue, saturation, brightness
		eraseStars.push_back(Star);
	}
}

//--------------------------------------------------------------
void ofApp::update() 
{
	ofVec2f target;

	if (isAuto)
	{
		target.set(mouseX, mouseY);
		for (auto& Star : Stars) 
			Star.update(target);
	}
	else
	{
		aliveTime = ofGetElapsedTimef() - bornTime;
		ofVec2f oldTarget;
		if (aliveTime > 60)
			if (mode == 1)
				oldTarget.set(512 + 900 * cos(0.7*(aliveTime - 60) + 1.07), 384 + 650 * sin(0.5*(aliveTime - 60)));
			else if (mode == 2)
				oldTarget.set(512 + 900 * cos(1 * (aliveTime - 60) + 1.07), 384 + 650 * sin(0.63*(aliveTime - 60)));
			else
				oldTarget.set(512 + 900 * cos(0.35 * (aliveTime - 60) + 1.07), 384 + 650 * sin(0.25*(aliveTime - 60)));


		if (mode == 1)
			target.set(512 + 900 * cos(0.7*aliveTime + 1.07), 384 + 650 * sin(0.5*aliveTime));
		else if (mode == 2)
			target.set(512 + 900 * cos(1 * aliveTime + 1.07), 384 + 650 * sin(0.63*aliveTime));
		else
			target.set(512 + 900 * cos(0.35 * aliveTime + 1.07), 384 + 650 * sin(0.25*ofGetElapsedTimef()));



		for (auto& Star : Stars) 
			Star.update(target);


		for (auto& Star : eraseStars)
			Star.update(oldTarget);
	}
}

//--------------------------------------------------------------
void ofApp::draw() 
{
	for (auto& Star : Stars) 
		Star.draw();

	for (auto& Star : eraseStars)
		Star.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) 
{
	if (key == 'a')//toggle auto mode;
		isAuto = !isAuto;

	if (key == 'g')//galaxy mode;
	{
		bornTime = ofGetElapsedTimef();
		mode = 1;
		ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
		soundPlayer.stop();
		soundPlayer.load("Aurelion Sol,the Star Forger.mp3");

		soundPlayer.play();
		int i = 0;
		for (auto& Star : Stars)
		{
			i++;
			float hue = ofMap(i, 0, 5000, 125, 225);
			Star.color = ofColor::fromHsb(hue, 255, 220);	// hue, saturation, brightness-
		}
	}

	if (key == 'u')//upbeat mode;
	{
		bornTime = ofGetElapsedTimef();
		mode = 2;
		ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
		soundPlayer.stop();
		soundPlayer.load("Stepping Along.mp3");

		soundPlayer.play();
		int i = 0;
		for (auto& Star : Stars)
		{
			i++;
			float hue = ofMap(i, 0, 5000, 10, 90);
			Star.color = ofColor::fromHsb(hue, 255, 220);	// hue, saturation, brightness-
		}
	}

	if (key == 's')//sentiment mode;
	{
		bornTime = ofGetElapsedTimef();
		mode = 3;
		ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
		soundPlayer.stop();
		soundPlayer.load("Horner- For The Love Of A Princess.mp3");

		soundPlayer.play();
		int i = 0;
		for (auto& Star : Stars)
		{
			i++;
			float hue = ofMap(i, 0, 5000, 170, 255);
			Star.color = ofColor::fromHsb(hue, 205, 100);	// hue, saturation, brightness
		}
	}
}