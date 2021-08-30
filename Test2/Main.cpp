// glut glew
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

// Application
#include "Root.h"
#include "Renderer.h"
#include "Globals.h"
#include "Renderable.h"
#include "WorldRenderable.h"

int main(int argc, char** argv)
{
	Root::Initialize(argc, argv);
	g_Camera = std::make_shared<Camera>();

	float bdata[] = {
		-0.5f, -0.5f, -10.0f, // left  
		 0.5f, -0.5f, -10.0f, // right 
		 0.0f,  0.5f, -10.0f,  // top
		-0.5f, -0.5f, -10.0f,
		-0.5f, -0.7f, -10.0f,
		 0.5f, -0.5f, -10.0f,
		-0.5f, -0.7f, -10.0f,
		 0.5f, -0.7f, -10.0f,
		 0.5f, -0.5f, -10.0f,
	};
	std::shared_ptr<Material> mat = std::make_shared<Material>();
	std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>(&bdata[0], 27);
	std::shared_ptr<WorldRenderable> obj = std::make_shared<WorldRenderable>(mesh, mat);
	std::shared_ptr<WorldRenderable> obj2 = std::make_shared<WorldRenderable>(mesh, mat);
	g_Camera->setPosition(glm::vec3(0, 0, 0));



	while (!glfwWindowShouldClose(Root::getWindow()))
	{
		int width, height;
		glfwGetFramebufferSize(Root::getWindow(), &width, &height);
		g_projectionMatrix = glm::perspective(glm::radians(60.0f), (float)width / (float)height, 0.1f, 100.0f);

		// update
		glm::mat4 rot = glm::rotate(glm::mat4(1), (float)glfwGetTime(), glm::vec3(0, 0, 1)) ;
		obj->getMaterial()->MVP = g_projectionMatrix * g_Camera->getViewMatrix() * rot;

		// render
		Renderer::draw(Root::getWindow(), width, height);
		glfwPollEvents();
	}
	Root::Deinitialize();
	return 0;
}