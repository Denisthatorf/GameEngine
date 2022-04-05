#pragma once

#ifdef EG_PLATFORM_WINDOWS
	#ifdef ENGINE_BUILD_DLL
		#define ENGINE_API __declspec(dllexport)
	#else
		#define ENGINE_API __declspec(dllexport)
	#endif
#else
	#error Hazel only support Windows.
#endif 
