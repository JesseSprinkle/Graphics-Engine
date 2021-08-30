#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
class Root
{
private:
    static bool initialized;
    static int setupGLEW();
    static int setupGLFW();
    static void error_callback(int error, const char* description);
    static GLFWwindow* window;
public:
    static int Initialize(int argc, char** argv);
    static int Deinitialize();
    static GLFWwindow* getWindow();

};