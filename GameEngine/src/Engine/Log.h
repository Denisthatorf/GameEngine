#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <memory>

namespace Engine {
	class ENGINE_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger();
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger();

		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;
	};
}

//#define ENGINE_CORE_FATAL(...)    ::Engine::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define ENGINE_CORE_ERROR(...)    ::Engine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ENGINE_CORE_WARN(...)     ::Engine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ENGINE_CORE_INFO(...)     ::Engine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ENGINE_CORE_TRACE(...)    ::Engine::Log::GetCoreLogger()->trace(__VA_ARGS__)

//#define ENGINE_CLIENT_FATAL(...)  ::Engine::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define ENGINE_CLIENT_ERROR(...)  ::Engine::Log::GetClientLogger()->error(__VA_ARGS__)
#define ENGINE_CLIENT_WARN(...)   ::Engine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ENGINE_CLIENT_INFO(...)   ::Engine::Log::GetClientLogger()->info(__VA_ARGS__)
#define ENGINE_CLIENT_TRACE(...)  ::Engine::Log::GetClientLogger()->trace(__VA_ARGS__)

