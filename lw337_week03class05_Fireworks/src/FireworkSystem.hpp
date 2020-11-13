//
//  FireworkSystem.hpp
//  wk06_Firework_system
//
//  Created by Tyler Henry on 10/2/18.
//

#pragma once
#include "ofMain.h"
#include "Firework.hpp"

class FireworkSystem {
public:

    
    FireworkSystem();                 
    FireworkSystem(float _angle,glm::vec2 _pos,float _strength);   
    
    void applyForce(glm::vec2 force); 
	float angle;
    void update();
	float strength;
	int numNewFireworks = 1;
	int maxFireworks = 1000;
    void draw();
    
    glm::vec2 pos;                   
    
    vector<Firework> Fireworks;
};
