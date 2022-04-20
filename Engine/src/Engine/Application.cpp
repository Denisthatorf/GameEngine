#include "Application.h"

namespace Engine {
	Application::Application() : m_window("First", 800, 600) {}
	Application::~Application() {}
	void Application::Run() {
		while (!m_window.shouldClose()) {
			glfwPollEvents();
		}
	}
}