#pragma once
#include <GL/glew.h>
class FragmentShader
{
private:
	GLuint shaderId;
public:
	FragmentShader(const char* fileName);
	GLuint getShaderId();
	~FragmentShader();
};