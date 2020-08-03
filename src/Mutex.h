#pragma once
#include <synchapi.h>

struct MUTEX_INFO
{
	HANDLE file;
	HANDLE mutex;
	HANDLE file_map_view;
};

void InitMutex(MUTEX_INFO *mutex);
void CloseMutex(MUTEX_INFO *mutex);
BOOL StartMutex(MUTEX_INFO *mutex, LPCSTR lpName, LPCSTR mutexName);
HANDLE ShowExistingWindow(LPCSTR mutexName);
