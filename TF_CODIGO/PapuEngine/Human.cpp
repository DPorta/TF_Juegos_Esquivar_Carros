#include "Human.h"
#include <random>
#include <ctime>
#include <glm/gtx/rotate_vector.hpp>

Human::Human()
{
}

void Human::init(float speed, glm::vec2 position)
{
	_speed = speed;
	_position = position;
	_color.set(255, 0, 255, 255);
	static std::mt19937 randomEngine(time(nullptr));
	static std::uniform_real_distribution<float>ranDir(-1.0f, 1.0f);

	_direction = glm::vec2(ranDir(randomEngine), ranDir(randomEngine));
	if (_direction.length() == 0) {
		_direction = glm::vec2(1.0f, 1.0f);
	}
}

void Human::update(const std::vector<std::string>& levelData,
	std::vector<Human*>& humans, std::vector<Zombie*>& zombies) {

	static std::mt19937 randomEngine(time(nullptr));
	static std::uniform_real_distribution<float>ranDir(-0.5f, 0.5f);
	_position += _direction * _speed;

	if (collideWithLevel(levelData)) {
		_direction = glm::vec2(ranDir(randomEngine), ranDir(randomEngine));
	}

}

Human::~Human()
{
}
