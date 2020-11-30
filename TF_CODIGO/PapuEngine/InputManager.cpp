#include "InputManager.h"

void InputManager::pressKey(unsigned int keyCode) {
	_keyMap[keyCode] = true;
}

void InputManager::releaseKey(unsigned int keyCode) {
	_keyMap[keyCode] = false;

}
bool InputManager::isKeyPressed(unsigned int keyCode) {
	auto it = _keyMap.find(keyCode);
	if (it != _keyMap.end()) {
		return it->second;
	}
	return false;
}

void InputManager::setMouseCoords(float x, float y) {
	_mouseCoords.x = x;
	_mouseCoords.y = y;
}

InputManager::InputManager():_mouseCoords(0.0f,0.0f)
{
}


InputManager::~InputManager()
{
}
