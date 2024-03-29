#pragma once

#include "ofMain.h"
#include "sphere.h"
class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		
		ofEasyCam cam;
		ofVec3f gravity = ofVec3f(0, -0.01, 0);
		ofVec3f target=ofVec3f(-200,-100,0);
		vector<Sphere> spheres;
		int score = 0;
		float noise;
};

