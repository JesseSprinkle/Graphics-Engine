#include "ShaderProgram.h"
#include <iostream>
ShaderProgram::ShaderProgram(std::shared_ptr<VertexShader> vertexShader, std::shared_ptr<FragmentShader> fragmentShader)
{
	progId = glCreateProgram();
	glAttachShader(progId, vertexShader->getShaderId());
	glAttachShader(progId, fragmentShader->getShaderId());
	glLinkProgram(progId);

	// check for errors
	GLint linked = GL_FALSE;
	glGetProgramiv(progId, GL_LINK_STATUS, &linked);
	if (!linked)
	{
		std::cout << "Error linking shader program" << std::endl;
		GLint progLogLength;
		glGetProgramiv(progId, GL_INFO_LOG_LENGTH, &progLogLength);
		if (progLogLength > 0) {
			char* progLogOutput = new char[progLogLength + 1];
			glGetProgramInfoLog(progId, progLogLength, NULL, progLogOutput);
			std::cout << "Shader Program log: " << progLogOutput << std::endl;
			delete[] progLogOutput;
		}
		exit(1);
	}
	glDetachShader(progId, vertexShader->getShaderId());
	glDetachShader(progId, fragmentShader->getShaderId());
	
}

ShaderProgram::~ShaderProgram()
{
	glDeleteProgram(progId);
}

GLuint ShaderProgram::getProgramId()
{
	return progId;
}

void ShaderProgram::use()
{
	glUseProgram(progId);
}