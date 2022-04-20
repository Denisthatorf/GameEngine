#pragma once
#include "Core.h"
#include "Window.h"

namespace Engine{
	class ENGINE_API Application
	{
	public:
		Window m_window;
	public:
		Application();
		virtual ~Application();
		void Run();
	};
	Application* CreateApplication();
}
