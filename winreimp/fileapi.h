#pragma once
#include <windef.h>
#include <winbase.h>

BOOL CreateDirectoryA(
	LPCSTR                lpPathName,
	LPSECURITY_ATTRIBUTES lpSecurityAttributes
);
#define CreateDirectory WINAPI_NAME(CreateDirectory)
