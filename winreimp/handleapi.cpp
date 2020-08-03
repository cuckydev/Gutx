#include <handleapi.h>

BOOL WINAPI CloseHandle(HANDLE hObject)
{
	delete hObject;
}
