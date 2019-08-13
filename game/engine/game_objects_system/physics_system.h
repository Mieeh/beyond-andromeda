#pragma once

#include"../math.h"
#include<vector>

class PhysicsBody {
public:
	vec2 pos = vec2(0, 0);
	float angle = 0;

	vec2 velocity = vec2(0, 0);
	float angularVelocity = 0;

	double linearDrag = 0.05;
	double angularDrag = 0.05;

	virtual void FixedUpdate() = 0;
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
	double physicsTimeStep = 20;          

	/* Methods */
	static PhysicsSystem* Get();

	void AddPhysicsBody(PhysicsBody* body);
	void Setup();
	void FixedUpdate();

};