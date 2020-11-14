#include "ofApp.h"


//adapted from sample code attractors;
const int nMovers		= 3;//3 meteors
const int nplanets	= 7;//7 planets



void ofApp::setup(){
	
	ofBackground(0);
	ofSetBackgroundAuto(false);      
	ofSetFrameRate(60.);               


	for (int m=0; m<nMovers; m++)
	{
		movers.push_back(Mover());
	}

	for (int m = 0; m < nplanets; m++)
	{
		planets.push_back(planet());
	}
	
	glm::vec2 center = glm::vec2( ofGetWidth() *.5, ofGetHeight() * .5 );
	
		attractor.pos   = center;
	}




void ofApp::update(){
	

	
	
		for (int m=0; m<nMovers; m++)
		{
		
			glm::vec2 force = attractor.getForce(movers[m]);
            
			
			movers[m].applyForce(force);
		}
	
	
	
	for (int m=0; m<nMovers; m++)
	{
		movers[m].update();
	}






	for (int m = 0; m < nplanets; m++)
	{
		planets[m].update();
	}

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofSetColor(255);
	ofDrawBitmapString("there are 7 planets and 3 meteors and a sun in the center", 10, 20);
	ofDrawBitmapString("the square of angular velocity of the planet is inversely proportianal to the cube of radius", 10, 35);
	ofDrawBitmapString("left click to double the angular velocity of the planet", 10, 50);
	
	ofSetColor(0, 0, 0, 20); 
	ofDrawRectangle(0,0, ofGetWidth(),ofGetHeight());
	
	
	
		attractor.draw();
	
	
	for (int m=0; m<nMovers; m++)
	{
		movers[m].draw();
	}


	for (int m = 0; m < nplanets; m++)
	{
		planets[m].draw();
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
	for (int m = 0; m < nplanets; m++)
	{
		planets[m].vel*=2;
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
