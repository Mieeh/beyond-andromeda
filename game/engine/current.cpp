#include"current.h"

Current* Current::_instance = nullptr;

Current::Current()
{
	timeScale = 1.0f;
	deltaTime = 1.0f;
}
