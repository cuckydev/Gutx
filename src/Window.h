#pragma once
#include <synchapi.h>
#include <winuser.h>

struct MUTEX_INFO
{
	HANDLE file;
	HANDLE mutex;
	HANDLE file_map_view;
};

BOOL SetWindowPosRect(HWND hWnd, LPCSTR a2, BOOL a3);
void SetWindowPosPath(LPCSTR tempPath);
void InitMutex(MUTEX_INFO *mutex);
void CloseMutex(MUTEX_INFO *mutex);
BOOL StartMutex(MUTEX_INFO *mutex, LPCSTR lpName, LPCSTR mutexName);
HANDLE ShowExistingWindow(LPCSTR mutexName);
void SetUnusedPtrTempGuxt(LPCSTR a1);
