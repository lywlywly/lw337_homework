#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(144);	
}

//--------------------------------------------------------------
void ofApp::update(){
	if (ofGetFrameNum() % speed == 0)
	{
		snow _snow;
		snows.push_back(_snow);
	}

	for (int i = 0; i < snows.size(); i++)
	{
		snows[i].update();
	}


		
}

//--------------------------------------------------------------
void ofApp::draw(){
	easyCam.begin();
	ofPushStyle();
	ofSetColor(ofColor::wheat);
	ofDrawBox(0, -500, 0, 4000, 400, 4000);
	ofPopStyle();
	
	for (int i = 0; i < snows.size(); i++)
	{
		snows[i].draw();
	}

	easyCam.end();
	ofPushStyle();
	ofSetColor(ofColor::white);
	ofDrawBitmapString("press mouse to change the frequency of snowflakes", 100,100 );
	ofPopStyle();

}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (index < 2)
		index++;
	else
		index = 0;
	speed = Speed[index];
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}