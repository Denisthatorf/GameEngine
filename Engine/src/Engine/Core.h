#pragma once

#ifdef WINDOWS_PLATFORM
	#ifdef DLL_BUILD
		#define ENGINE_API __declspec(dllexport)
	#else
		#define ENGINE_API __declspec(dllimport)
	#endif 
#else
	#error Hazel only support Windows.
#endif 
