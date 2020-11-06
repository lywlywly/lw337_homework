#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundAuto(true); 

	ofBackground(0);

	ofSetCircleResolution(100);

	face.x = 512;
	face.y = 384;


	
}

//--------------------------------------------------------------
void ofApp::update(){


	ball.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255);
	ofDrawBitmapString("whenever the face is hit by the ball, a smiling face is turned into a crying face ", 10, ofGetHeight() - 30);
	ofDrawBitmapString(" You can use direction keys on keyboard to dodge the ball ", 10, ofGetHeight() - 15);
	ofDrawBitmapString("total time (seconds) of being hit: ", 10, ofGetHeight() - 45);
	ofDrawBitmapString(timehit, 280, ofGetHeight() - 45);
	if ((ball.x - face.x)*(ball.x - face.x) + (ball.y - face.y)*(ball.y - face.y) <= 250*250)
	{
		face.drawSad(); 
		timehit += ofGetLastFrameTime();
	}
	
	else
		face.drawHappy();
	ball.draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if (key == OF_KEY_LEFT&&face.x>0)
		face.x-=25;
	else if (key == OF_KEY_RIGHT&&face.x<1024)
		face.x+=25;
	else if (key == OF_KEY_UP&&face.y>0)
		face.y-=25;
	else if (key == OF_KEY_DOWN&&face.y<768)
		face.y+=25;
	

	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
	
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)//left button of mouse to add a ball, right button to erase a ball
{
	
	if (ofGetMousePressed(OF_MOUSE_BUTTON_LEFT)) 
	{
	
	}

	if (ofGetMousePressed(OF_MOUSE_BUTTON_RIGHT))
	{
	
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
