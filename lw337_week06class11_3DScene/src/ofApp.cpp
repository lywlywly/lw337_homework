#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{

}

//--------------------------------------------------------------
void ofApp::update() {
	for (int i = 0; i < spheres.size(); i++)
	{
		if (spheres[i].pos.y < -197&&spheres[i].aliveTime>0.8&&spheres[i].pos.x<600 && spheres[i].pos.z < 600 && spheres[i].pos.z > -600)
		{
			spheres[i].setVelocity(ofVec3f(0));

			if (!spheres[i].takenIntoScore&&spheres[i].pos.x > 250 && spheres[i].pos.x < 300 && spheres[i].pos.z < 700 * noise + 25 && spheres[i].pos.z > 700 * noise - 25)
			{
				score++;
				spheres[i].takenIntoScore = true;
			}
		}
		spheres[i].update();

	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofEnableDepthTest();

	cam.begin();
	ofSetColor(ofColor::white);
	ofDrawLine(ofVec3f(-300, -200, 0), target);

	for (int i = 0; i < spheres.size(); i++)
	{
		spheres[i].draw();
	}

	ofSetColor(ofColor::coral);
	ofDrawBox(0, -200, 0, 1200, 10, 1200);
	//ofDrawAxis(100);
	noise = ofSignedNoise(.03*ofGetElapsedTimef());
	ofSetColor(ofColor::darkRed);
	ofDrawBox(300, -175, 700 * noise, 5, 50, 50);
	ofDrawBox(250, -175, 700 * noise, 5, 50, 50);
	ofDrawBox(275, -175, 700 * noise + 25, 50, 50, 5);
	ofDrawBox(275, -175, 700 * noise - 25, 50, 50, 5);
	cam.end();

	stringstream info;
	info << "Use your up down left right direction keys to control the direction of the ball. " << endl << "Press x to decrease the force and c to increase the force." << endl << "Thorw the ball into the basket to earn a point" << endl <<"press enter to let the ball ejected"<<endl << endl << "your score is" << score;
	ofDrawBitmapStringHighlight(info.str(), 25, 50);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key==OF_KEY_LEFT)
	{
		target.z--; 
	}
	if (key==OF_KEY_RIGHT)
	{
		target.z++;
	}
	if (key==OF_KEY_UP)
	{
		target.y++;
	}
	if (key==OF_KEY_DOWN)
	{
		target.y--;
	}
	
	if (key == 'x')
	{
		target= ofVec3f(-300 + (target.x + 300)*0.9, -200 + (target.y + 200)*0.9, target.z*0.9);
	}

	if (key == 'c')
	{
		target = ofVec3f(-300 + (target.x + 300)*1.1, -200 + (target.y + 200)*1.1, target.z*1.1);
	}

	if (key == OF_KEY_RETURN)
	{
		Sphere tempSphere(ofVec3f(-300,-200,0),13);
		tempSphere.applyForce(gravity);
		tempSphere.setVelocity(ofVec3f(0.02*(target.x+300), 0.02*(target.y+200), 0.02*target.z));
		spheres.push_back(tempSphere);
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}