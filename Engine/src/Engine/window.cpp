#include "Window.h"
#include <stdexcept>
#include <iostream>

namespace Engine
{
	Window::Window(const std::string& name, int width, int height)
		: m_name(name),
		  m_width (width),
		  m_height( height),
		  m_window(nullptr) {}

	Window::~Window()
	{
		glfwDestroyWindow(m_window);
		glfwTerminate();
	}

	void Window::OpenWindow()
	{
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		m_window = glfwCreateWindow(m_width, m_height, m_name.c_str(), NULL, NULL);

		glfwMakeContextCurrent(m_window);
	}

	bool Window::Update() {
		glfwPollEvents();
		return !glfwWindowShouldClose(m_window);
	}

	void Window::RequestDrawSurface(std::unordered_map<SurfaceArgs, std::any> args)
	{
		try {
			auto vkInstance = std::any_cast<VkInstance>(args[SurfaceArgs::INSTANCE]);
			auto* allocationCallbacks = args[SurfaceArgs::ALLOCATORS].has_value() ?
				std::any_cast<VkAllocationCallbacks*>(args[SurfaceArgs::ALLOCATORS]) : nullptr;
			auto* outSurface = std::any_cast<VkSurfaceKHR*>(args[SurfaceArgs::OUT_SURFACE]);

			if (vkInstance == VK_NULL_HANDLE) {
				throw std::runtime_error("Must provide an instance!");
			}

			if (glfwCreateWindowSurface(vkInstance, m_window, allocationCallbacks, outSurface) != VK_SUCCESS) {
				throw std::runtime_error("Failed to create window surface!");
			}
		}
		catch (std::bad_any_cast& e) {
			std::cout << "Failed to cast window surface arguments: " << e.what() << "\n";
		}
	}

	void Window::RequestDrawSurface(VkInstance instance, VkSurfaceKHR* surface)
	{
		if (glfwCreateWindowSurface(instance, m_window, nullptr, surface) != VK_SUCCESS) {
			throw std::runtime_error("failed to create window surface!");
		}
	}

	VkExtent2D Window::GetWindowExtents() {
		int width, height;
		glfwGetFramebufferSize(m_window, &width, &height);

		return VkExtent2D{ static_cast<uint32_t>(width), static_cast<uint32_t>(height) };
	}
}