#include "Firework.hpp"

Firework::Firework()
{
        
    pos = glm::vec3(0,0,0);
    vel = glm::vec3(0,0,0);
    acc = glm::vec3(0,0,0);
    
    bornTime = ofGetElapsedTimef();
}

Firework::Firework(glm::vec3 _pos, glm::vec3 _vel, float _mass)
{
    
    pos = _pos;
    vel = _vel;
    mass = _mass;
    
    bornTime = ofGetElapsedTimef();
}

void Firework::applyForce(glm::vec3 force)
{
    acc += force / mass;
}

void Firework::update()
{
    vel += acc;
    pos += vel;
    acc *= 0;
    
}

void Firework::draw()
{
    ofPushStyle();
    float hue = ofMap(mass, 0, 5, 0, 255);
    float sat = 255;
    float brt = 255;
    
    float aliveTime = ofGetElapsedTimef() - bornTime;
    float alpha = ofMap(aliveTime, 0, 2, 255, 0, true);
    
    ofColor color = ofColor::fromHsb(hue,sat,brt,alpha);
    ofSetColor(color);
    
	ofDrawCylinder(pos.x,pos.y,pos.z, mass,mass * 4.0);
    ofPopStyle();
}

