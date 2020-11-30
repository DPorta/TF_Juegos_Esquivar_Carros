#pragma once
#include "Agent.h"
#include "InputManager.h"
class Vidas : public Agent
{
protected:
	glm::vec2 direction;

public:
	Vidas();
	~Vidas();
	void init(float speed, glm::vec2 position);
	virtual void update(const std::vector<std::string>& levelData, std::vector<Vidas*>& vidas);

};

