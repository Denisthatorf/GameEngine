#pragma once
#include <memory>
#include "Window.h"
#include "Renderer.h"

namespace Engine 
{
	class ServiceLocator
	{
	private:
		static inline std::unique_ptr<Window> m_window = nullptr;
		static inline std::unique_ptr<Renderer> m_renderer = nullptr;

	public:
		static inline const std::unique_ptr<Window>& GetWindow() { return m_window; }
		static inline const std::unique_ptr<Renderer>& GetRenderer() { return m_renderer; }

		static inline void Provide(Window* window)
		{
			if (m_window == nullptr)
				m_window = std::unique_ptr<Window>(window);
		}

		static inline void Provide(Renderer* renderer, RendererSettings settings) {
			if (m_renderer != nullptr) return;

			m_renderer = std::make_unique<Renderer>();
			m_renderer->Init(settings);
		}

		static inline void shutDownServices()
		{
			shutdownRenderer();
			shutDownWindow();
		}
	private:
		static inline void shutDownWindow() {
			m_window.reset();
			m_window = nullptr;
		}

		static inline void shutdownRenderer() {
			if (!m_renderer) return;

			m_renderer->Shutdown();
			m_renderer = nullptr;
		}
		
	};
}

