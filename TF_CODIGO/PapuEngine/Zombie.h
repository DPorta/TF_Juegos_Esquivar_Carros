#pragma once
#include "Agent.h"
#include "InputManager.h"
class Zombie : public Agent
{
protected:
	glm::vec2 direction;

public:
	Zombie();
	~Zombie();
	void init(float speed, glm::vec2 position);
	virtual void update(const std::vector<std::string>& levelData,
		std::vector<Zombie*>& zombies);

};

