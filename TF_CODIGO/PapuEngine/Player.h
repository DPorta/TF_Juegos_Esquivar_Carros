#pragma once
#include "Human.h"
#include "InputManager.h"
class Player : public Human
{
private:
	InputManager* _inputManager;
public:
	Player();
	~Player();
	virtual void update(const std::vector<std::string>& levelData,
		std::vector<Zombie*>& zombies);
	void init(float speed, glm::vec2 position, InputManager* inputManager);
};

