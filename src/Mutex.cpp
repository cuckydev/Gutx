#include "Mutex.h"
#include <synchapi.h>
#include <handleapi.h>

void InitMutex(MUTEX_INFO *mutex)
{
	mutex->file = nullptr;
	mutex->mutex = nullptr;
	mutex->file_map_view = nullptr;
}

void CloseMutex(MUTEX_INFO *mutex)
{
	if (mutex->mutex)
		ReleaseMutex(mutex->mutex);
	if (mutex->file)
		CloseHandle(mutex->file);
}

BOOL StartMutex(MUTEX_INFO *mutex, LPCSTR lpName, LPCSTR mutexName)
{
	mutex->mutex = OpenMutex(MUTEX_ALL_ACCESS, FALSE, lpName);
	if (mutex->mutex)
	{
		ShowExistingWindow(mutexName);
		return FALSE;
	}
	else
	{
		mutex->mutex = CreateMutex(nullptr, FALSE, lpName);
		return mutex->mutex != nullptr;
	}
}

HANDLE ShowExistingWindow(LPCSTR mutexName)
{
	return nullptr;
}
