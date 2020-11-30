#pragma once
#include <unordered_map>
#include <glm\glm.hpp>

class InputManager
{
private:
	std::unordered_map<unsigned int, bool> _keyMap;
	glm::vec2 _mouseCoords;

public:
	InputManager();
	~InputManager();
	glm::vec2 getMouseCoords() const {
		return _mouseCoords;
	}
	void setMouseCoords(float x, float y);
	void pressKey(unsigned int keyCode);
	void releaseKey(unsigned int keyCode);
	bool isKeyPressed(unsigned int keyCode);
};

