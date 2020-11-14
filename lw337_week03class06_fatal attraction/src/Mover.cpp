#include "Mover.h"


Mover::Mover(glm::vec2 _pos)
{
    
    origPos = _pos;
    pos = origPos;
    vel = glm::vec2(0,0);
    acc = glm::vec2(0,0);
    
    mass = 5;
}

void Mover::applyForce(glm::vec2 force)
{
    acc += force / mass;
}

void Mover::applyDampingForce(float strength)
{
    float speed = glm::length(vel);
    if (speed != 0){
        glm::vec2 dir = vel / speed;
        applyForce( -dir * strength );
    }
}

void Mover::applyElasticForce(float strength)
{
    glm::vec2 diff = origPos - pos;
    float length = glm::length(diff);
    if (length != 0){
        glm::vec2 dir = diff / length;
        elasticForce = dir * strength;
        applyForce( elasticForce );

    }
    
    
}

void Mover::update()
{
    vel += acc;
    pos += vel;
    acc *= 0;
	
		if (pos.x < 0) {
			pos.x = 0;
			vel.x *= -1;
		}

		if (pos.x > ofGetWidth()) {
			pos.x = ofGetWidth();
			vel.x *= -1;
		}

		if (pos.y < 0) {
			pos.y = 0;
			vel.y *= -1;
		}

		if (pos.y > ofGetHeight()) {
			pos.y = ofGetHeight();
			vel.y *= -1;
		}
	

}

void Mover::draw()
{
    ofDrawCircle(pos, mass * 2.0);
    
}