#pragma once
#include <glm/glm.hpp>
#include "SpriteBacth.h"
#include <string>
#include "GLTexture.h"

class Zombie;
class Human;

const float AGENT_WIDTH = 60.0f;
const float AGENT_RADIUS = AGENT_WIDTH / 2.0f;
class Agent
{
protected:
	glm::vec2 _position;
	float _speed;
	Color _color;
	void checkTilePosition(const std::vector<std::string>& levelData, std::vector<glm::vec2>& collidePosition, float x, float y);
	void collidWithTile(glm::vec2 tilePos);

public:
	Agent();
	virtual ~Agent();
	//el 0 hace que todos los hijos la sobreescriban
	bool collideWithLevel(const std::vector<std::string>& levelData);
	bool collidedWithAgent(Agent* agent);
	glm::vec2 getPosition()const { return _position; }
	void draw(SpriteBacth& spriteBatch);
};

