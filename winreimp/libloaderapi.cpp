#include <libloaderapi.h>
#include <string>

#include "SDL_filesystem.h"

const char *module_name = "Gutx";

DWORD WINAPI GetModuleFileNameA(HMODULE hModule, LPSTR lpFilename, DWORD nSize)
{
	char *base_path = SDL_GetBasePath();
	std::string res = (base_path != nullptr) ? std::string(base_path) + module_name : "./";
	size_t i;
	for (i = 0; i < res.length() && i < (nSize - 1); i++)
		*lpFilename++ = res[i];
	*lpFilename = 0;
	return i;
}
