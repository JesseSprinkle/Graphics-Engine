#include "Renderer.h"
#include <filesystem>
#include <iostream>
std::map<ShaderProgramType, std::shared_ptr<ShaderProgram>> Renderer::shaderPrograms;

void Renderer::setupShaderPrograms()
{
	std::shared_ptr<VertexShader> uiVertShader = std::make_shared<VertexShader>("shaders\\vertShader.vert");
	std::shared_ptr<FragmentShader> uiFragShader = std::make_shared<FragmentShader>("shaders\\fragShader.frag");

	std::shared_ptr<ShaderProgram> uiShaderProg = std::make_shared<ShaderProgram>(uiVertShader, uiFragShader);
	shaderPrograms[ShaderProgramType::UI] = uiShaderProg;


	std::shared_ptr<VertexShader> wVertShader = std::make_shared<VertexShader>("shaders\\MVPShader.vert");
	std::shared_ptr<FragmentShader> wFragShader = std::make_shared<FragmentShader>("shaders\\MVPShader.frag");
	std::shared_ptr<ShaderProgram> wShaderProg = std::make_shared<ShaderProgram>(wVertShader, wFragShader);
	shaderPrograms[ShaderProgramType::WORLD] = wShaderProg; 
}


void Renderer::Initialize()
{
	setupShaderPrograms();
}

void Renderer::draw(GLFWwindow* window, int width, int height)
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// loop through shader programs
	for (auto it = shaderPrograms.begin(); it != shaderPrograms.end(); it++)
	{
		// get renderables for that program
		Renderable** renderables = Renderable::getRenderablesForShaderProgram(it->first);
		if (renderables == nullptr)
		{
			continue;
		}
		std::shared_ptr<ShaderProgram> currProg = it->second;

		// load program, draw renderables
		currProg->use();
		for (int j = 0; j < MAX_RENDERABLES_PER_SHADER; j++)
		{
			if (renderables[j] != nullptr)
			{
				renderables[j]->draw(currProg->getProgramId());
			}
		}
	}
	glfwSwapBuffers(window);
}