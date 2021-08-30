#include "Callbacks.h"
#include "Renderer.h"
void Callbacks::onFramebufferResized(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	Renderer::draw(window, width, height);
}