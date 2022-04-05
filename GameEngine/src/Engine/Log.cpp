#include "Log.h"

namespace Engine {

	std::shared_ptr<spdlog::logger> Log::coreLogger;
	std::shared_ptr<spdlog::logger> Log::clientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^{%T} %n: %v%$");

		coreLogger = spdlog::stdout_color_mt("EngineCore");
		coreLogger->set_level(spdlog::level::trace);

		clientLogger = spdlog::stdout_color_mt("EngineClient");
		clientLogger->set_level(spdlog::level::trace);
	}

	inline std::shared_ptr<spdlog::logger>& Log::GetCoreLogger()
	{
		return Log::coreLogger;
	}
	inline std::shared_ptr<spdlog::logger>& Log::GetClientLogger()
	{
		return Log::clientLogger;
	}
}