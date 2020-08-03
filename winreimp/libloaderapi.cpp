#include <libloaderapi.h>
#include <string.h>
#include <stddef.h>

#include "SDL_filesystem.h"

DWORD WINAPI GetModuleFileNameA(HMODULE hModule, LPSTR lpFilename, DWORD nSize)
{
	char *base_path = SDL_GetBasePath();
	if (base_path != nullptr)
	{
		memset(lpFilename, 0, nSize);
		strncpy(lpFilename, base_path, nSize);
		SDL_free(base_path);
		size_t len = strlen(lpFilename);
		return len > nSize ? nSize : len;
	}
	else
	{
		if (nSize >= 3)
			strcpy(lpFilename, "./");
		else
			*lpFilename = 0;
		return strlen(lpFilename);
	}
}
