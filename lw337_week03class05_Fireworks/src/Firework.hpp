#pragma once
#include "ofMain.h"

class Firework {
    
public:
    
    Firework();
    Firework(glm::vec2 _pos, glm::vec2 _vel, float _mass);
    
    void applyForce(glm::vec2 force);
    void update();
    void draw();
    
    glm::vec2 pos, vel, acc;
    float mass;
    
    float bornTime;
    
};
