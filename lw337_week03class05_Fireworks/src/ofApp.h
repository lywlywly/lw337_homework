#pragma once

#include "ofMain.h"
#include "FireworkSystem.hpp"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void mouseReleased(int x, int y, int button);
	ofVec2f distance;
	float angle;
    vector<FireworkSystem> FireworkSystems;
    glm::vec2 gravity;
    
		
};
