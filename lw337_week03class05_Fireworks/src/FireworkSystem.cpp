#include "FireworkSystem.hpp"

FireworkSystem::FireworkSystem()
{
    pos = glm::vec2(0,0);
}

FireworkSystem::FireworkSystem(float _angle,glm::vec2 _pos,float _strength)
{
    pos = _pos;   
	angle = _angle;
	angle = ofDegToRad(angle);
	strength = _strength/100;
}

void FireworkSystem::applyForce(glm::vec2 force)
{

    
    for (int i=0; i<Fireworks.size(); i++)
    {
        Fireworks[i].applyForce(force);
    }
}

void FireworkSystem::update()
{
    // create new Fireworks
    for (int i=0; i<numNewFireworks; i++)
    {
        glm::vec2 vel = glm::vec2(sqrt(strength)*cos(-angle)+ sqrt(strength)*ofRandom(-1,1), sqrt(strength) *2*sin(angle));   // move up

        float mass = ofRandom(.01, 5);
        Firework firework = Firework(pos,vel,mass);     // start at system's position
        Fireworks.push_back(firework);
    }
	
	// update Fireworks:
    
    for (int i=0; i<Fireworks.size(); i++)
    {
        Fireworks[i].update();
    }
    
    // erase old Fireworks:
    
    while (Fireworks.size() > maxFireworks)     // keep the number of Fireworks under a limit
    {
        Fireworks.erase(Fireworks.begin());     // erase the oldest Firework
    }
    
}

void FireworkSystem::draw()
{
	
    for (int i=0; i<Fireworks.size(); i++)
    {
        Fireworks[i].draw();
    }
}

