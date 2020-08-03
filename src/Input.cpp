#include "Input.h"

#include <string.h>

BOOLEAN gKeyDown[MAX_KEY];
BOOLEAN gKeyDownPrev[MAX_KEY];
BOOLEAN gKeyTrg[MAX_KEY];

#define MOUSE_LEFT 0x01
#define MOUSE_RIGHT 0x10
LONG input_0; //The two bits above for mouse buttons
LONG input_4;
LONG input_8;
LONG input_c;
LONG input_10;
LONG input_14;
BOOL input_18; //Either mouse button is down

void ResetInput()
{
	memset(gKeyDown, 0, sizeof(gKeyDown));
	memset(gKeyDownPrev, 0, sizeof(gKeyDownPrev));
	memset(gKeyTrg, 0, sizeof(gKeyTrg));
	input_0 = 0;
	input_4 = 0;
	input_8 = 0;
	input_c = 0;
	input_10 = 0;
	input_14 = 0;
	input_18 = 0;
}

void KeyCapture(HWND hWnd, LONG message, LONG key)
{
	switch (message)
	{
		case WM_KEYDOWN:
			gKeyDown[key] = TRUE;
			break;
		case WM_KEYUP:
			gKeyDown[key] = FALSE;
			break;
		case WM_LBUTTONDOWN:
			input_0 |= MOUSE_LEFT;
			if (!input_18)
			{
				input_18 = TRUE;
				SetCapture(hWnd);
			}
			break;
		case WM_LBUTTONUP:
			input_0 &= ~MOUSE_LEFT;
			if (!(input_0 & MOUSE_RIGHT))
			{
				input_18 = FALSE;
				ReleaseCapture();
			}
			break;
		case WM_RBUTTONDOWN:
			input_0 |= MOUSE_RIGHT;
			if (!input_18)
			{
				input_18 = TRUE;
				SetCapture(hWnd);
			}
			break;
		case WM_RBUTTONUP:
			input_0 &= ~MOUSE_RIGHT;
			if (!(input_0 & MOUSE_LEFT))
			{
				input_18 = FALSE;
				ReleaseCapture();
			}
			break;
	}
}
