#pragma once
#include "ofMain.h"

class Firework {
    
public:
    
    Firework();
    Firework(glm::vec3 _pos, glm::vec3 _vel, float _mass);
    
    void applyForce(glm::vec3 force);
    void update();
    void draw();
    
    glm::vec3 pos, vel, acc;
    float mass;
    
    float bornTime;
    
};
