#pragma once

#include "ofMain.h"
#include "FireworkSystem.hpp"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void mouseReleased(int x, int y, int button);

	void keyReleased(int key);

    vector<FireworkSystem> FireworkSystems;
    glm::vec3 gravity;
	ofEasyCam easyCam;
	glm::vec3 pointer=glm::vec3(0,0,0);
};
