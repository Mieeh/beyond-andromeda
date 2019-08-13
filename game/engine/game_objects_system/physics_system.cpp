#include"physics_system.h"

#include<iostream>

PhysicsSystem* PhysicsSystem::instance = nullptr; // singleton instance pointer

PhysicsSystem* PhysicsSystem::Get() {
	if (instance == nullptr)
		instance = new PhysicsSystem();

	return instance;
}

void PhysicsSystem::AddPhysicsBody(PhysicsBody* body)
{
	physicsBodies.push_back(body);
}

void PhysicsSystem::Setup()
{

}

void PhysicsSystem::FixedUpdate()
{
	for (auto& x : physicsBodies) {
		// Update all bodies
		x->FixedUpdate();
		
		// Resolve rotation and velocity
		x->pos.x += x->velocity.x;
		x->pos.y += x->velocity.y;
		x->velocity.x *= 1 - x->linearDrag;
		x->velocity.y *= 1 - x->linearDrag;
		x->angle += x->angularVelocity;
		x->angularVelocity *= 1 - x->angularDrag;
	}

}