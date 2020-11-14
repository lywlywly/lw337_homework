#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
	for(int i=0;i<5;i++)
	{

		Mover mover(glm::vec2(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight())));

		movers.push_back(mover);
	}
    }



//--------------------------------------------------------------
void ofApp::update(){
    
	win = true;
	if(!finallyWin)
	for (int i = 0; i < movers.size(); i++)
	{
		if (pow((movers[i].pos.x - mouseX), 2) + pow((movers[i].pos.y - mouseY), 2) > 40000)
		{
			win = false;
			break;
		}
	}

	if (win)
		finallyWin = true;

	if (ofGetFrameNum()%150 == 0&&!finallyWin)
	{

		Mover mover(glm::vec2(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight())));

		movers.push_back(mover);
	}

    glm::vec2 mousePos = glm::vec2( ofGetMouseX(), ofGetMouseY() );
    
    for (int i=0; i<movers.size(); i++){
        
        glm::vec2 diff = mousePos - movers[i].pos;
        
        float distance = glm::length(diff);
    
		if (ofGetMousePressed(OF_MOUSE_BUTTON_LEFT)&&distance<200)
		{
			glm::vec2 norm = diff / distance;
			movers[i].applyForce(norm);
		}

		if (ofGetMousePressed(OF_MOUSE_BUTTON_LEFT) && distance < 100)
		{
			glm::vec2 norm = diff / distance;
			movers[i].applyForce(-2 * norm);
		}

        
        movers[i].applyDampingForce(0.2);
        movers[i].update();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofDrawBitmapString("use your mouse to attract all the balls. Once you have done it, you win.", 20, 20);
	ofDrawBitmapString("pressed your mouse left botton to enable attraction and repulsion", 20, 40);
    
    for (int i=0; i<movers.size(); i++)
    {
        movers[i].draw();
    }
    

    ofNoFill();
    ofDrawCircle(mouseX, mouseY, 100);
    ofDrawCircle(mouseX, mouseY, 200);
    ofFill();

	if (finallyWin)
	{
		ofBackground(255);
		ofSetColor(ofColor::red);
		ofDrawBitmapString("You win! Congrats!", 455,384);
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