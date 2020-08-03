#pragma once
#include <windef.h>

typedef struct _SECURITY_ATTRIBUTES {
	DWORD  nLength;
	LPVOID lpSecurityDescriptor;
	BOOL   bInheritHandle;
} SECURITY_ATTRIBUTES, *PSECURITY_ATTRIBUTES, *LPSECURITY_ATTRIBUTES;

#define MUTEX_MODIFY_STATE	0x00000001L
#define DELETE				0x00010000L
#define READ_CONTROL 		0x00020000L
#define WRITE_DAC			0x00040000L
#define WRITE_OWNER			0x00080000L
#define SYNCHRONIZE			0x00100000L
#define MUTEX_ALL_ACCESS	(DELETE | READ_CONTROL | WRITE_DAC | \
							WRITE_OWNER | SYNCHRONIZE | MUTEX_MODIFY_STATE)

HANDLE WINAPI OpenMutexA(
	DWORD dwDesiredAccess,
	BOOL bInheritHandle,
	LPCSTR lpName
);
#define OpenMutex WINAPI_NAME(OpenMutex)

HANDLE WINAPI CreateMutexA(
	LPSECURITY_ATTRIBUTES lpMutexAttributes,
	BOOL bInitialOwner,
	LPCSTR lpName
);
#define CreateMutex WINAPI_NAME(CreateMutex)

BOOL WINAPI ReleaseMutex(
	HANDLE hMutex
);
