#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
  
    gravity = glm::vec2(0, .15);

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

	ofDrawBitmapString("Use your mouse to generate a set of fireworks. The farther your mouse to the red circle, the bigger the fierworks are", 10, 20);
	ofVec2f center = ofVec2f(512, 700);
	ofVec2f mouse;
	ofDrawCircle(center, 20);
	mouse.set(ofGetMouseX(), ofGetMouseY());
	ofSetColor(ofColor::red);

	distance = ofVec2f(mouse.y - 700, mouse.x - 512);
	float rad = atan2(mouse.y- 700, mouse.x- 512);
	angle = ofRadToDeg(rad);

	ofDrawLine(center, mouse);
	ofPushMatrix();
	
	ofTranslate(mouse);
	ofRotate(angle);
	ofVec3f p1 = ofVec3f(0, 0);
	ofVec3f p2 = p1 - ofVec3f(30, 10);	
	ofVec3f p3 = p1 - ofVec3f(30, -10);
	ofDrawTriangle(p1, p2, p3);

	ofPopMatrix();

    for (int i=0; i<FireworkSystems.size(); i++){
        FireworkSystems[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    // create a new Firework system at mouse position on click
    
    FireworkSystems.push_back( FireworkSystem(angle,glm::vec2(x,y),distance.length()));

}
