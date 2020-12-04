

#include "Sphere.h"

Sphere::Sphere()
{
	pos = glm::vec3(0, 0, 0);
	radius = ofRandom(5, 20);
	setup();
}

Sphere::Sphere(glm::vec3 _pos, float _radius)
{
	pos = _pos;
	radius = _radius;
	setup();
	bornTime = ofGetElapsedTimef();
}

void Sphere::setup()
{
	// assign color based on radius

	float hue = ofMap(radius, 3, 20, 250, 150);
	color = ofColor::fromHsb(hue, 255, 255);
}

void Sphere::update()
{
	aliveTime = ofGetElapsedTimef() - bornTime;
	vel += acc;
	pos += vel;

}

void Sphere::draw()
{
	ofPushStyle();
	ofSetColor(color);
	ofDrawSphere(pos, radius);
	ofPopStyle();
}

void Sphere::setVelocity(glm::vec3 _vel)
{
	vel = _vel;
}

void Sphere::applyForce(glm::vec3 force)
{
	acc += force;
}

void Sphere::bounceWalls(float left, float right, float top, float bottom, float front, float back)
{
	// check x
	if (pos.x < left + radius) {	// left
		pos.x = left + radius;
		vel.x *= -1.;
	}

	if (pos.x > right - radius) {	// right
		pos.x = right - radius;
		vel.x *= -1.;
	}

	// check y
	if (pos.y > top - radius) {	// top  (in 3D, +y is up!)
		pos.y = top - radius;
		vel.y *= -1.;
	}

	if (pos.y < bottom + radius) {	// bottom   (in 3D, -y is down!)
		pos.y = bottom + radius;
		vel.y *= -1.;
	}

	// check z
	if (pos.z < front + radius) {	// front    (in 3D, -z is near)
		pos.z = front + radius;
		vel.z *= -1.;
	}

	if (pos.z > back - radius) {	// back     (in 3D, +z is far)
		pos.z = back - radius;
		vel.z *= -1.;
	}

}
