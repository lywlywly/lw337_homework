#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	ofVideoGrabber vid;

	ofImage vidShift;

	int X = 0;
	int camW, camH;
	int Y = 0;
	int oldX = 0;
	int oldY = 0;
	float distortionScale = 0;
	float oldDistortionScale = 0;
	int sumX, sumY = 0;
	int count;

};
