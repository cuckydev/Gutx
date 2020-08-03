#include <winuser.h>
#include "SDL.h"

int WINAPI MessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType)
{
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, lpCaption, lpText, hWnd ? hWnd->GetSDLWindow() : nullptr);
}

HWND capture = nullptr;

HWND WINAPI SetCapture(HWND hWnd)
{
	HWND result = capture;
	capture = hWnd;
	SDL_CaptureMouse(SDL_TRUE);
	return nullptr;
}

BOOL WINAPI ReleaseCapture()
{
	capture = nullptr;
	return SDL_CaptureMouse(SDL_FALSE) ? FALSE : TRUE;
}
