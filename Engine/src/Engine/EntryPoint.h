#pragma once
#include "Log.h"

#ifdef WINDOWS_PLATFORM

extern Engine::Application* Engine::CreateApplication();

int main(int argc, char** argv) {
	Engine::Log::Init();
	ENGINE_CLIENT_ERROR("dsf");
	auto app = Engine::CreateApplication();
	app->Run();
	delete app;

	return 1;
}
#endif
