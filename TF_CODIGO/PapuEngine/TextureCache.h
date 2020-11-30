#pragma once
#include "GLTexture.h"
#include <string>
#include <map>

class TextureCache
{
	std::map<std::string, GLTexture> _textureMap;
public:
	TextureCache();
	~TextureCache();
	GLTexture getTexture(std::string texturePath);
};

