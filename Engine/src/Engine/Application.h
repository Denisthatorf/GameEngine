#pragma once
#include <string>

#include "Core.h"
#include "Window.h"

namespace Engine
{
	class ENGINE_API Application
	{
	private:
		const std::string WINDOW_NAME;
		const uint32_t START_WINDOW_WIDTH;
		const uint32_t START_WINDOW_HEIGHT;
	public:
		Application();
		Application(std::string windowName, uint32_t width, uint32_t height);
		virtual ~Application();

		void Run();
		virtual void Update(float deltaTime) {};
	private:
		void initServices();
		void shutDownServices();
	};
	Application* CreateApplication();
}
