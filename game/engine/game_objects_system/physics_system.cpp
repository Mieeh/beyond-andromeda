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
}

void PhysicsSystem::Setup()
{
}

void PhysicsSystem::FixedUpdate()
{
	std::cout << "Fixed Update Has Been Called!" << std::endl;
}