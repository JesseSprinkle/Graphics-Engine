#include "FragmentShader.h"
#include "ShaderUtilities.h"
FragmentShader::FragmentShader(const char* fileName)
{
	shaderId = glCreateShader(GL_FRAGMENT_SHADER);
	if (!loadShaderFromFile(fileName, shaderId))
	{
		exit(0);
	}
}

FragmentShader::~FragmentShader()
{
	glDeleteShader(shaderId);
}

GLuint FragmentShader::getShaderId()
{
	return shaderId;
}