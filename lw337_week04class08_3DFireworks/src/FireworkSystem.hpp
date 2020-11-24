#pragma once
#include "ofMain.h"
#include "Firework.hpp"

class FireworkSystem {
public:

    
    FireworkSystem();                 
    FireworkSystem(glm::vec3 _pos);   
    
    void applyForce(glm::vec3 force); 
    void update();
	float strength;
	int numNewFireworks = 1;
	int maxFireworks = 1000;
    void draw();
    
    glm::vec3 pos;                   
    


    vector<Firework> Fireworks;
};
