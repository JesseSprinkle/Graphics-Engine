#pragma once
#include <GL/glew.h>
class VertexShader
{
private:
	GLuint shaderId;
public:
	VertexShader(const char* fileName);
	GLuint getShaderId();
	~VertexShader();
};