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

#define BIT(x) (1 << x)