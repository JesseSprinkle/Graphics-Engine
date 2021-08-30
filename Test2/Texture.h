#pragma once
#include <GL/glew.h>
#include <string>
#include "stb_image.h"
class Texture
{
private:
	int width, height, nChannels;
	GLuint textureId;
public:
	//Texture(const char* fileName);
	GLuint getTextureID();
};