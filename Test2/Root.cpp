#include "Root.h"
#include "Renderer.h"
#include "Callbacks.h"
#include <iostream>
bool Root::initialized = false;
GLFWwindow* Root::window;
int Root::Initialize(int argc, char** argv)
{
	if (initialized)
	{
		return 1;
	}
	setupGLFW();
	setupGLEW();
	Renderer::Initialize();
	initialized = true;
	return 0;
}

int Root::Deinitialize()
{
	if (!initialized)
	{
		return 1;
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}

int Root::setupGLFW()
{
	if (!glfwInit())
	{
		// Initialization failed
	}
	glfwSetErrorCallback(error_callback);
	window = glfwCreateWindow(640, 640, "My Title", NULL, NULL);
	if (!window)
	{
		return 1;
	}
	glfwMakeContextCurrent(window);
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	glfwSetFramebufferSizeCallback(window, Callbacks::onFramebufferResized);
	glfwSwapInterval(1);
	return 0;
}

int Root::setupGLEW()
{
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
	}
	fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
	return 0;
}

void Root::error_callback(int error, const char* description)
{
	fprintf(stderr, "Error: %s\n", description);
}

GLFWwindow* Root::getWindow()
{
	return window;
}

