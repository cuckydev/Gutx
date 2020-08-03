#include <fileapi.h>
#include <sys/stat.h>

BOOL CreateDirectoryA(LPCSTR lpPathName, LPSECURITY_ATTRIBUTES lpSecurityAttributes)
{
	return mkdir(lpPathName, 0777) ? FALSE : TRUE;
}
