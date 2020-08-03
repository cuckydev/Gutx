#pragma once
#include <windows.h>

#define MAX_KEY 0x100

extern BOOLEAN gKeyDown[MAX_KEY];
extern BOOLEAN gKeyDownPrev[MAX_KEY];
extern BOOLEAN gKeyTrg[MAX_KEY];

void ResetInput();
void KeyCapture(HWND hWnd, LONG message, LONG key);
