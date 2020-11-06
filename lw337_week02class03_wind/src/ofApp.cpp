#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	
	ofBackground(0);

	
}

//--------------------------------------------------------------
void ofApp::update(){


	ball1.update(wind);
	ball2.update(wind);
	ball3.update(wind);

}

//--------------------------------------------------------------
void ofApp::draw(){
	wind.changeDir();
	ball1.draw();
	ball2.draw();
	ball3.draw();
	ofSetColor(255);
	ofDrawBitmapString("This homework uses an intuitive wind object", 10, 10);
	ofDrawBitmapString("We assume the wind represents the velocity", 10, 25);
	ofDrawBitmapString("The ball whose radiu is larger moves slower", 10, 40);
	ofDrawBitmapString("Left click to increase the wind, and right click to decrease", 10, 55);
	ofDrawBitmapString("You can use your mouse to control the direction of the wind", 10, 70);
	ofDrawBitmapString("current windstrength:", 830, 10);
	ofDrawBitmapString(wind.strength, 1000, 10);

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
	if (ofGetMousePressed(OF_MOUSE_BUTTON_LEFT))
	wind.increaseWind();
	
	if (ofGetMousePressed(OF_MOUSE_BUTTON_RIGHT))
	{
		if (wind.strength != 0)
			wind.decreaseWind();
	}

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
