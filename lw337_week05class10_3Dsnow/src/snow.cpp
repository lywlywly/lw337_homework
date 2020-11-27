#include "snow.h"




snow::snow()
{
	pos=ofVec3f(ofRandom(-1500,1500), ofRandom(500,700), ofRandom(-1500, 1500));
	
}


void snow::update()
{
	if (!isStopped)
	{
		pos.y -= 1;
		pos.x += ofSignedNoise(ofGetElapsedTimef() / 5);
		
		if (pos.y+300<=1)
			isStopped = true;
	}
}

void snow::draw()

{
	
	ofPushMatrix();
	ofTranslate(pos);
	ofDrawLine(0, 0, 0, 0 + size);
	ofDrawLine(0, 0 + 0.6*size, 0 - 0.3*size, 0 + 0.9*size);
	ofDrawLine(0, 0 + 0.6*size, 0 + 0.3*size, 0 + 0.9*size);
	ofRotate(60);
	ofDrawLine(0, 0, 0, 0 + size);
	ofDrawLine(0, 0 + 0.6*size, 0 - 0.3*size, 0 + 0.9*size);
	ofDrawLine(0, 0 + 0.6*size, 0 + 0.3*size, 0 + 0.9*size);
	ofRotate(60);
	ofDrawLine(0, 0, 0, 0 + size);
	ofDrawLine(0, 0 + 0.6*size, 0 - 0.3*size, 0 + 0.9*size);
	ofDrawLine(0, 0 + 0.6*size, 0 + 0.3*size, 0 + 0.9*size);
	ofRotate(60);
	ofDrawLine(0, 0, 0, 0 + size);
	ofDrawLine(0, 0 + 0.6*size, 0 - 0.3*size, 0 + 0.9*size);
	ofDrawLine(0, 0 + 0.6*size, 0 + 0.3*size, 0 + 0.9*size);
	ofRotate(60);
	ofDrawLine(0, 0, 0, 0 + size);
	ofDrawLine(0, 0 + 0.6*size, 0 - 0.3*size, 0 + 0.9*size);
	ofDrawLine(0, 0 + 0.6*size, 0 + 0.3*size, 0 + 0.9*size);
	ofRotate(60);
	ofDrawLine(0, 0, 0, 0 + size);
	ofDrawLine(0, 0 + 0.6*size, 0 - 0.3*size, 0 + 0.9*size);
	ofDrawLine(0, 0 + 0.6*size, 0 + 0.3*size, 0 + 0.9*size);

	ofRotateY(60);

	ofDrawLine(0, 0, 0, 0 + size);
	ofDrawLine(0, 0 + 0.6*size, 0 - 0.3*size, 0 + 0.9*size);
	ofDrawLine(0, 0 + 0.6*size, 0 + 0.3*size, 0 + 0.9*size);
	ofRotate(60);
	ofDrawLine(0, 0, 0, 0 + size);
	ofDrawLine(0, 0 + 0.6*size, 0 - 0.3*size, 0 + 0.9*size);
	ofDrawLine(0, 0 + 0.6*size, 0 + 0.3*size, 0 + 0.9*size);
	ofRotate(60);
	ofDrawLine(0, 0, 0, 0 + size);
	ofDrawLine(0, 0 + 0.6*size, 0 - 0.3*size, 0 + 0.9*size);
	ofDrawLine(0, 0 + 0.6*size, 0 + 0.3*size, 0 + 0.9*size);
	ofRotate(60);
	ofDrawLine(0, 0, 0, 0 + size);
	ofDrawLine(0, 0 + 0.6*size, 0 - 0.3*size, 0 + 0.9*size);
	ofDrawLine(0, 0 + 0.6*size, 0 + 0.3*size, 0 + 0.9*size);
	ofRotate(60);
	ofDrawLine(0, 0, 0, 0 + size);
	ofDrawLine(0, 0 + 0.6*size, 0 - 0.3*size, 0 + 0.9*size);
	ofDrawLine(0, 0 + 0.6*size, 0 + 0.3*size, 0 + 0.9*size);
	ofRotate(60);
	ofDrawLine(0, 0, 0, 0 + size);
	ofDrawLine(0, 0 + 0.6*size, 0 - 0.3*size, 0 + 0.9*size);
	ofDrawLine(0, 0 + 0.6*size, 0 + 0.3*size, 0 + 0.9*size);

	ofRotateY(60);

	ofDrawLine(0, 0, 0, 0 + size);
	ofDrawLine(0, 0 + 0.6*size, 0 - 0.3*size, 0 + 0.9*size);
	ofDrawLine(0, 0 + 0.6*size, 0 + 0.3*size, 0 + 0.9*size);
	ofRotate(60);
	ofDrawLine(0, 0, 0, 0 + size);
	ofDrawLine(0, 0 + 0.6*size, 0 - 0.3*size, 0 + 0.9*size);
	ofDrawLine(0, 0 + 0.6*size, 0 + 0.3*size, 0 + 0.9*size);
	ofRotate(60);
	ofDrawLine(0, 0, 0, 0 + size);
	ofDrawLine(0, 0 + 0.6*size, 0 - 0.3*size, 0 + 0.9*size);
	ofDrawLine(0, 0 + 0.6*size, 0 + 0.3*size, 0 + 0.9*size);
	ofRotate(60);
	ofDrawLine(0, 0, 0, 0 + size);
	ofDrawLine(0, 0 + 0.6*size, 0 - 0.3*size, 0 + 0.9*size);
	ofDrawLine(0, 0 + 0.6*size, 0 + 0.3*size, 0 + 0.9*size);
	ofRotate(60);
	ofDrawLine(0, 0, 0, 0 + size);
	ofDrawLine(0, 0 + 0.6*size, 0 - 0.3*size, 0 + 0.9*size);
	ofDrawLine(0, 0 + 0.6*size, 0 + 0.3*size, 0 + 0.9*size);
	ofRotate(60);
	ofDrawLine(0, 0, 0, 0 + size);
	ofDrawLine(0, 0 + 0.6*size, 0 - 0.3*size, 0 + 0.9*size);
	ofDrawLine(0, 0 + 0.6*size, 0 + 0.3*size, 0 + 0.9*size);
	ofPopMatrix();
}

