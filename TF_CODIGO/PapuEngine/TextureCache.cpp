#include "TextureCache.h"
#include "ImageLoader.h"
#include <iostream>
using namespace std;

TextureCache::TextureCache()
{
}

GLTexture TextureCache::getTexture(std::string texturePath) {
	//std::map<std::string, GLTexture>::iterator mit
		//= _textureMap.find(texturePath);
	auto mit = _textureMap.find(texturePath);
	if (mit == _textureMap.end()) {
		GLTexture texture = ImageLoader::loadPNG(texturePath);
		//std::pair<std::string, GLTexture> 
			//	newPair(texturePath, texture);
		_textureMap[texturePath] = texture;
		//_textureMap.insert(newPair);
		return texture;
	}
	return mit->second;
}


TextureCache::~TextureCache()
{
}
