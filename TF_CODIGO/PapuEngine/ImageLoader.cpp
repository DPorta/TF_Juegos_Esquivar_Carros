#include "ImageLoader.h"
#include "picoPNG.h"
#include "Error.h"
#include "IOManager.h"


GLTexture ImageLoader::loadPNG(std::string filepath) {
	GLTexture texture = {};
	std::vector<unsigned char>out;
	std::vector<unsigned char> in;
	unsigned long width, height;

	if (!IOManager::readFileToBuffer(filepath, in)) {
		fatalError("Could not read  " + filepath);
	}

	int errorCode = decodePNG(out, width, height, &(in[0]), in.size());

	if (errorCode != 0) {
		fatalError("decode PNG with error " + std::to_string(errorCode));
	}

	glGenTextures(1, &(texture.id));
	//bindeamos texture
	glBindTexture(GL_TEXTURE_2D, texture.id);
	//tipo de texture / level de mipmal ,internal format, ancho , alto, border, format, type of data, pointer pixel data
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &(out[0]));

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE, 0);
	texture.height = height;
	texture.width = width;

	return texture;
}