#include <Engine.h>

class Sandbox : public Engine::Application {
public:
	Sandbox() 
	{

	}
	~Sandbox() {

	}
	void Update(float deltaTime) override{

	}
};

Engine::Application* Engine::CreateApplication() {
	return new Sandbox();
}
