#pragma once
#include <GL/glew.h>
#include <glfw/glfw3.h>
#include <memory>
#include <map>
#include "ShaderProgram.h"
#include "Renderable.h"
class Renderer
{
private:
	static std::map<ShaderProgramType, std::shared_ptr<ShaderProgram>> shaderPrograms;
public:
	static void draw(GLFWwindow* window, int width, int height);
	static void Initialize();
	static void setupShaderPrograms();
};