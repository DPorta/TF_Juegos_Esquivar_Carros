#pragma once
#include <string>
#include <vector>
#include "SpriteBacth.h"
using namespace std;

const int TILE_WIDTH = 64;
class Level
{
private:
	vector<string> levelData;
	int numHumans;
	void parseLevel();
public:
	glm::vec2 playerPosition;
	vector<glm::vec2> zombiePosition;
	vector<glm::vec2> vidaPosition;
	int getNumHumans()const {
		return numHumans;
	}
	int getWidth()const {
		return levelData[1].size();
	}
	int getHeight()const {
		return levelData[1].size();
	}
	const std::vector<std::string>& getLevelData() {
		return levelData;
	}
	glm::vec2 getPlayerPosition() const {
		return playerPosition;
	}
	std::vector<glm::vec2> getZombiesPosition()const {
		return zombiePosition;
	}
	std::vector<glm::vec2> getVidaPosition()const {
		return vidaPosition;
	}
	Level(const std::string& fileName);
	void draw();
	SpriteBacth spriteBatch;
	~Level();
};

