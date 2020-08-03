#include <windows.h>

#include <string.h>

#include "Input.h"
#include "Window.h"

LPCSTR lpName = "directxsample";
LPCSTR mutexName = "map_directxsample";

HINSTANCE ghInstance;

CHAR gDataPath[MAX_PATH + 4];
CHAR gModulePath[MAX_PATH];
CHAR gTempPath[MAX_PATH];

/*
BOOL message()
{
	MSG Msg;

	while (PeekMessageA(&Msg, nullptr, nullptr, nullptr, nullptr) || !GameFocussed)
	{
		if (!GetMessageA(&Msg, nullptr, nullptr, nullptr))
			return FALSE;
		TranslateMessage(&Msg);
		DispatchMessageA(&Msg);
	}
	return TRUE;
}
*/

//Entry points
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	MUTEX_INFO mutex;
	
	//Initialize and remember the executing instance
	InitMutex(&mutex);
	ghInstance = hInstance;
	
	//Start mutex
	if (StartMutex(&mutex, lpName, mutexName))
	{
		//Initialize window controls
		InitCommonControls();
		
		//Reset input
		ResetInput();
		
		//Handle paths
		GetModuleFileName(nullptr, gModulePath, MAX_PATH);
		PathRemoveFileSpec(gModulePath);
#ifndef FORWARD_SLASH
		sprintf(gTempPath, "%s\\temp_guxt", gModulePath);
		sprintf(gDataPath, "%s\\data", gModulePath);
#else
		sprintf(gTempPath, "%s/temp_guxt", gModulePath);
		sprintf(gDataPath, "%s/data", gModulePath);
#endif
		CreateDirectory(gTempPath, 0);
		
		SetWindowPosPath(gTempPath);
		SetUnusedPtrTempGuxt(gTempPath);
		return 1;
	}
	else
	{
		CloseMutex(&mutex);
		return 0;
	}
}

#if (defined(REIMP_WINMAIN) || !defined(TARGET_WIN))
#ifndef TARGET_WIN
#include "SDL.h"
#endif

int main(int argc, char *argv[])
{
#ifndef TARGET_WIN
	//Initialize SDL
	SDL_Init(0);
#endif
	
	//TODO: construct HINSTANCE... what is it anyways?
	
	//Run WinMain
	int result = WinMain(nullptr, nullptr, nullptr, 0);
	
#ifndef TARGET_WIN
	//Quit SDL
	SDL_Quit();
#endif
}
#endif

//Window managing
BOOL SetWindowAttr(HINSTANCE hInstance, LPCSTR name, WNDPROC proc)
{
	WNDCLASSEX wndClass;
	memset(&wndClass, 0, sizeof(WNDCLASSEX));

	wndClass.cbSize = sizeof(WNDCLASSEX);
	wndClass.lpszClassName = name;
	wndClass.style = CS_VREDRAW | CS_HREDRAW;
	wndClass.lpfnWndProc = proc;
	wndClass.hInstance = ghInstance;
	wndClass.hbrBackground = GetStockObject(BLACK_BRUSH);
	wndClass.hIcon = LoadIconA(ghInstance, "0");
	wndClass.hCursor = LoadCursorA(nullptr, IDC_ARROW);
	return RegisterClassEx(&wndClass) != 0;
}
