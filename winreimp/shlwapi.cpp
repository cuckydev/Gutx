#include <shlwapi.h>
#include <string>

BOOL WINAPI PathRemoveFileSpecA(LPSTR pszPath)
{
	std::string path = std::string(pszPath);
	size_t orig_len = path.length();
	size_t last_slash = path.find_last_of("/\\");
	if (last_slash != std::string::npos)
	{
		pszPath[last_slash] = 0;
		return TRUE;
	}
	return FALSE;
}
