#include "Player.h"
#include <SDL\SDL.h>
Player::Player()
{
}

Player::~Player()
{
}

void Player::init(float speed, glm::vec2 position,
	InputManager* inputManager)
{
	_speed = speed;
	_position = position;
	_inputManager = inputManager;
	_color.set(255, 255, 255, 255);

}

void Player::update(const std::vector<std::string>& levelData,
	std::vector<Zombie*>& zombies) {

	if (_inputManager->isKeyPressed(SDLK_a)) {
		_position.x -= _speed;
	}
	if (_inputManager->isKeyPressed(SDLK_d)) {
		_position.x += _speed;
	}
	collideWithLevel(levelData);
}