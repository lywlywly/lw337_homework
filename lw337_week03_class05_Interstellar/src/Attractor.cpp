#include "Attractor.hpp"

Attractor::Attractor()
{
	pos.x = ofRandom(ofGetWidth());
	pos.y = ofRandom(ofGetHeight());
	mass = 45;
	
}

Attractor::Attractor(glm::vec2 _pos, float _mass)
{
	pos = _pos;
	mass =100; 
	
}

glm::vec2 Attractor::getForce(Mover mover)
{
	
	glm::vec2 dir	= pos - mover.pos;	
    float distance	= glm::length(dir);
    
    glm::vec2 force = glm::vec2(0,0);
    
    if (distance > 0) { 
  
        float distanceMod	= ofClamp(distance, 5., 25.);
        
        float strength	    = (G * mass * mover.mass) / (distanceMod * distanceMod);
	
        glm::vec2 dirNorm   = dir / distance;  
        force	= dirNorm * strength;
	
    }
	return force;
}

void Attractor::draw()
{
	ofPushStyle();
	
	float hue       = ofMap(mass, 5, 30, 180, 255);
	ofColor color   = ofColor::fromHsb(hue, 255, 200);
	
	ofSetColor(color);

	ofDrawCircle(pos, mass);

	ofPopStyle();
}
	
	
	
	
