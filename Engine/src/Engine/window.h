#pragma once
#include <string>
#include <unordered_map>
#include <any>

#define GLFW_INCLUDE_VULKAN
#include "vulkan/vulkan.h"
#include <GLFW/glfw3.h>

namespace Engine
{
	enum class SurfaceArgs {
		INSTANCE,
		ALLOCATORS,
		OUT_SURFACE
	};

	class Window
	{
	private:
		std::string m_name;
		int m_width;
		int m_height;
		GLFWwindow* m_window;

	public:
		Window(const Window&) = delete;
		Window& operator=(const Window&) = delete;
		Window(const std::string& name, int width, int height);
		~Window();

	public:
		bool Update();
		void OpenWindow();

		void RequestDrawSurface(std::unordered_map<SurfaceArgs, std::any> args);
		void RequestDrawSurface(VkInstance instance, VkSurfaceKHR* surface);
		
	public:
		GLFWwindow* getGLFWwindow() const { return m_window; }
		VkExtent2D GetWindowExtents();
	};
}


