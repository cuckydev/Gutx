#include "Window.h"

#include <handleapi.h>
#include <stdio.h>
#include <string.h>

#include "SafeRead.h"

LPCSTR lpWindowPosPath;
LPCSTR gTempPtr2;

void SetWindowPosPath(LPCSTR tempPath)
{
	lpWindowPosPath = tempPath;
}

BOOL SetWindowPosRect(HWND hWnd, LPCSTR a2, BOOL a3)
{
	int show = SW_SHOWNORMAL;
	RECT rect;
	
	//Open file
	char path[MAX_PATH + 6];
#ifndef FORWARD_SLASH
	sprintf(path, "%s\\%s", lpWindowPosPath, a2);
#else
	sprintf(path, "%s/%s", lpWindowPosPath, a2);
#endif
	FILE *fp = fopen(path, "rb");
	if (!fp)
		return FALSE;
	
#ifndef SAFE_READ
	fread(&rect, 4*4, 1, fp);
	fread(&show, 4, 1, fp);
#else
	rect.left = SafeRead_32(fp);
	rect.top = SafeRead_32(fp);
	rect.right = SafeRead_32(fp);
	rect.bottom = SafeRead_32(fp);
	show = SafeRead_32(fp);
#endif
	
	fclose(fp);
	
	/*
	SystemParametersInfoA(0x30u, 0, &pvParam, 0);
	v7 = GetSystemMetrics(61);
	v5 = GetSystemMetrics(62);
	v6 = GetSystemMetrics(28);
	v9 = GetSystemMetrics(29);
	if ( v12 - X < v6 )
	v12 = v6 + X;
	if ( v13 - Y < v9 )
	v13 = v9 + Y;
	if ( v12 - X > v7 )
	v12 = v7 + X;
	if ( v13 - Y > v5 )
	v13 = v5 + Y;
	if ( X < pvParam )
	{
	v12 += pvParam - X;
	X = pvParam;
	}
	if ( Y < v16 )
	{
	v13 += v16 - Y;
	Y = v16;
	}
	if ( v12 > v17 )
	{
	X -= v12 - v17;
	v12 = v17;
	}
	if ( v13 > v18 )
	{
	Y -= v13 - v18;
	v13 = v18;
	}
	if ( a3 )
	MoveWindow(hWnd, X, Y, v12 - X, v13 - Y, 0);
	else
	SetWindowPos(hWnd, 0, X, Y, 0, 0, 1u);
	if ( v14 == 3 )
	ShowWindow(hWnd, 3);
	else
	ShowWindow(hWnd, 1);
	return 1;
	*/
}

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

void SetUnusedPtrTempGuxt(LPCSTR a1)
{
	gTempPtr2 = a1;
}
