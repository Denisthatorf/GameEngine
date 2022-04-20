#include "Window.h"
#include <stdexcept>

Window::Window(const std::string& name, int width, int height)
{
	init(name, width, height);
}

Window::~Window()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

void Window::init(const std::string& name, int width, int height)
{
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	this->name = name;
	this->width = width;
	this->height = height;

	window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);

	glfwMakeContextCurrent(window);
}