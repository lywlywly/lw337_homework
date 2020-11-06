#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(2);
	ofBackground(0);	
}

//--------------------------------------------------------------
void ofApp::update(){


}

//--------------------------------------------------------------
void ofApp::draw(){
	ofDrawBitmapString("left button of mouse to add a bird at the position of cursor, right button to erase a bird", 10, ofGetHeight() - 30);
	for (int i = 0; i < birds.size(); i++) {
		birds[i].draw();
	}

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
	{
		bird tempbird;
		tempbird.setup(ofGetMouseX(), ofGetMouseY());
		
		birds.push_back(tempbird);
	}

	if (ofGetMousePressed(OF_MOUSE_BUTTON_RIGHT))
	{
		if (birds.size() != 0)//avoid operating on an empty vector
			birds.erase(birds.begin());
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
