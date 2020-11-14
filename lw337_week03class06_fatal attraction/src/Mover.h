#pragma once
#include "ofMain.h"

class Mover {
    
public:
    
    Mover(glm::vec2 _pos);
    
    void applyForce(glm::vec2 force);
    void applyDampingForce(float strength);
    void applyElasticForce(float strength);
    void update();
    void draw();
    
    glm::vec2 origPos, pos, vel, acc;
    glm::vec2 elasticForce;
    float mass;

    
    
};