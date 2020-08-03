#pragma once
#include <windef.h>

BOOL WINAPI PathRemoveFileSpecA(
	LPSTR pszPath
);
#define PathRemoveFileSpec WINAPI_NAME(PathRemoveFileSpec)
