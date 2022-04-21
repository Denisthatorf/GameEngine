#include "Application.h"
#include "ServiceLocator.h"
#include "Renderer.h"

namespace Engine 
{
	Application::Application() : Application::Application("NoobApp", 800, 600) {}

	Application::Application(std::string windowName, uint32_t width, uint32_t height) 
		: WINDOW_NAME(std::move(windowName)), 
		START_WINDOW_WIDTH(width),
		START_WINDOW_HEIGHT(height) 
	{
		initServices();
	}

	Application::~Application()
	{
		shutDownServices();
	}

	void Application::Run() 
	{
		while (ServiceLocator::GetWindow()->Update()) 
		{
			Update(0.0f);
			ServiceLocator::GetRenderer()->RenderFrame();
		}
	}
	void Application::initServices()
	{
		ServiceLocator::Provide(new Window(WINDOW_NAME, START_WINDOW_WIDTH, START_WINDOW_HEIGHT));
		ServiceLocator::GetWindow()->OpenWindow();

		RendererSettings settings{};
		settings.ApplicationName = WINDOW_NAME;
		ServiceLocator::Provide(new Renderer(), settings);
	}
	void Application::shutDownServices()
	{
	}
}