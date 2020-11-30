#pragma once
#include "GLTexture.h"
#include "TextureCache.h"

class ResourceManager
{
private:
	static TextureCache _textureCache;
public:
	static GLTexture getTexture(std::string texturePath);
};

