#pragma once
#include <windef.h>
#include <winuser.h>

DWORD WINAPI GetModuleFileNameA(
	HMODULE hModule,
	LPSTR   lpFilename,
	DWORD   nSize
);
#define GetModuleFileName WINAPI_NAME(GetModuleFileName)
