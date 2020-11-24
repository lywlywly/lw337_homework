#include "FireworkSystem.hpp"

FireworkSystem::FireworkSystem()
{
    pos = glm::vec3(0,0,0);
}

FireworkSystem::FireworkSystem(glm::vec3 _pos)
{
    pos = _pos;   
	strength = 10;
}

void FireworkSystem::applyForce(glm::vec3 force)
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
		float random = ofRandom(-1, 1);
        glm::vec3 vel = glm::vec3(sqrt(strength)*ofRandom(-.5, .5), sqrt(strength),  sqrt(strength)*ofRandom(-.5, .5));   // move 
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

