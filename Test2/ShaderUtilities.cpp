#include "ShaderUtilities.h"
GLint loadShaderFromFile(const char* fileName, GLuint shaderId)
{
	std::string shaderCode;
	std::ifstream shaderFStream(fileName);
	if (shaderFStream.is_open()) {
		std::stringstream shaderSStream;
		shaderSStream << shaderFStream.rdbuf();
		shaderFStream.close();
		shaderCode = shaderSStream.str();
	}
	else {
		std::cout << "Could not open " << fileName << std::endl;
		exit(1);
	}

	// compile
	const char* cstrShaderCode = shaderCode.c_str();
	glShaderSource(shaderId, 1, &cstrShaderCode, NULL);
	glCompileShader(shaderId);

	// check for errors
	GLint compiled = GL_FALSE;
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &compiled);
	if (!compiled)
	{
		std::cout << "Error compiling shader " << fileName << std::endl;
		GLint shaderLogLength;
		glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &shaderLogLength);
		if (shaderLogLength > 0) {
			char* shaderLogOutput = new char[shaderLogLength + 1];
			glGetShaderInfoLog(shaderId, shaderLogLength, NULL, shaderLogOutput);
			std::cout << "Shader log: " << shaderLogOutput << std::endl;
			delete[] shaderLogOutput;
		}
	}
	return compiled;
}