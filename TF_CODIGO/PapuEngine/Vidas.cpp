#include "Vidas.h"

Vidas::Vidas()
{
}

Vidas::~Vidas()
{
}

void Vidas::init(float speed, glm::vec2 position)
{
	_speed = speed;
	_position = position;
	_color.set(255, 255, 255, 255);

	direction = glm::vec2(0.0f, -1.0f);
	if (direction.length() == 0) {
		direction = glm::vec2(1.0f, 1.0f);
	}
}

void Vidas::update(const std::vector<std::string>& levelData, std::vector<Vidas*>& vidas)
{
	collideWithLevel(levelData);
	_position += direction * _speed;
}
