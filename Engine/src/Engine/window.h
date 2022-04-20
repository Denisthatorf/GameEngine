#pragma once
#include <string>

#include <GLFW/glfw3.h>

class Window
{
private:
	std::string name;
	int width;
	int height;
	GLFWwindow* window;
private:
	void init(const std::string& name, int width, int height);
public:
	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;
	Window(const std::string& name, int width, int height);
	~Window();

public:
	GLFWwindow* getGLFWwindow() const { return window; }
	bool shouldClose() const { return glfwWindowShouldClose(window); };
};


