#pragma once
#include "ofMain.h"


class planet
{
public:


	planet();
	float mass;
	float radius;
	float vel;
	ofVec2f pos;
	void update();
	void draw();

	ofColor color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));

};

class Mover {
    
public:
    
    Mover();
    Mover(glm::vec2 _pos, float _mass);
    
    void applyForce(glm::vec2 force);
    void applyDampingForce(float strength);

    void bounceWindowEdges();  
    
    void update();
    void draw();

    glm::vec2 pos, vel, acc;
    float mass;
    
};
