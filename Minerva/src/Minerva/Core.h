#pragma once

#ifdef MV_PLATFORM_WINDOWS
	#ifdef MV_BUILD_DLL
		#define MINERVA_API _declspec(dllexport)
	#else
		#define MINERVA_API _declspec(dllimport)
	#endif
#else
	#error Minerva only suports Windows
#endif

#ifdef MV_ENABLE_ASSERTS
	#define MV_ASSERT(x, ...) { if(!(x)){MV_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreack(); }}
	#define MV_CORE_ASSERT(x, ...) { if(!(x)){MV_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreack(); }}
#else
	#define MV_ASSERT(x, ...)
	#define MV_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)