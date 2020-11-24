#include "ofApp.h"

//adapted from sample code particle system
//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
  
    gravity = glm::vec3(0, -.05,0);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i=0; i<FireworkSystems.size(); i++){
        FireworkSystems[i].applyForce(gravity);
        FireworkSystems[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
	easyCam.begin();
	ofTranslate(0,-300,0);
	
	ofVec2f mouse;

    for (int i=0; i<FireworkSystems.size(); i++){
        FireworkSystems[i].draw();
    }
	ofDrawSphere(pointer, 15);
	ofDrawAxis(100);
	easyCam.end();
	ofDrawBitmapString("Press any key to change the position of the fireworks to be set off. Click mouse button to set off", 10, 20);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    
    FireworkSystems.push_back( FireworkSystem(pointer));

}


void ofApp::keyReleased(int key) {
	pointer = glm::vec3(ofRandom(300), ofRandom(300), ofRandom(300));

	
}

