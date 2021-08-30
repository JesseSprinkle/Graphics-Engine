#include "VertexShader.h"
#include "ShaderUtilities.h"
VertexShader::VertexShader(const char* fileName)
{
	shaderId = glCreateShader(GL_VERTEX_SHADER);
	if (!loadShaderFromFile(fileName, shaderId))
	{
		exit(0);
	}
}

VertexShader::~VertexShader()
{
	glDeleteShader(shaderId);
}

GLuint VertexShader::getShaderId()
{
	return shaderId;
}