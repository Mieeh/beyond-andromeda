#pragma once

#include"../math.h"
#include<vector>

class PhysicsBody {
public:
	vec2 pos;
	vec2 velocity;
	double linearDrag;
	double angularDrag;
};

class PhysicsSystem {

private:
	/* Private Methods */
	PhysicsSystem() { }
	static PhysicsSystem* instance;

	/* Members */
	std::vector<PhysicsBody*> physicsBodies;

public:
	/* Public members*/
	double physicsTimeStep = 50;

	/* Methods */
	static PhysicsSystem* Get();

	void AddPhysicsBody(PhysicsBody* body);
	void Setup();
	void FixedUpdate();

};