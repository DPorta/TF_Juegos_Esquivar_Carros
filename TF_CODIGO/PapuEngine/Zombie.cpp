#include "Zombie.h"

Zombie::Zombie() {

}

Zombie::~Zombie() {

}
void Zombie::update(const std::vector<std::string>& levelData,
	std::vector<Zombie*>& zombies) {
	collideWithLevel(levelData);
	_position += direction * _speed;
}



void Zombie::init(float speed, glm::vec2 position) {
	_speed = speed;
	_position = position;
	_color.set(255, 0, 0, 255);

	direction = glm::vec2(0.0f, -1.0f);
	if (direction.length() == 0) {
		direction = glm::vec2(1.0f, 1.0f);
	}
}


