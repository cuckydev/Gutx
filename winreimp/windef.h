#pragma once

//Function types
#define CALLBACK	//__stdcall
#define WINAPI		//__stdcall
#define APIPRIVATE	//__stdcall
#define PASCAL		//__stdcall
#define CDECL		//__cdecl
#define _CDECL		//__cdecl

#define APIENTRY	WINAPI

//API naming
#define WINAPI_NAME(name) name##A //Always use A, no reason to implement wide versions we aren't gonna use

//Bool values
#define FALSE 0
#define TRUE  1

//Common int values
typedef unsigned char UCHAR, *PUCHAR;
typedef unsigned short USHORT, *PUSHORT;
#ifdef USE_LONG
	typedef unsigned long ULONG, *PULONG;
#else
	typedef unsigned int ULONG, *PULONG;
#endif

typedef void *LPVOID;
typedef const void *LPCVOID;
typedef int BOOL, *PBOOL, *LPBOOL;
typedef unsigned char BYTE, *PBYTE, *LPBYTE;
typedef unsigned short WORD, *PWORD, *LPWORD;
typedef int INT, *PINT, *LPINT;
typedef unsigned int UINT, *PUINT;
typedef float FLOAT, *PFLOAT;
typedef char *PSZ;
#ifdef USE_LONG
	typedef long *LPLONG;
	typedef unsigned long DWORD, *PDWORD, *LPDWORD;
#else
typedef int *LPLONG;
	typedef unsigned int DWORD, *PDWORD, *LPDWORD;
#endif

typedef void VOID;
typedef VOID *PVOID;
typedef VOID *PVOID64;
typedef BYTE BOOLEAN, *PBOOLEAN;
typedef char CHAR, *PCHAR;
typedef short SHORT, *PSHORT;
#ifdef USE_LONG
	typedef long LONG, *PLONG;
#else
	typedef int LONG, *PLONG;
#endif

//String types
typedef CHAR *PCH, *LPCH, *PNZCH;
typedef const CHAR *PCCH, *LPCCH, *PCNZCH;
typedef CHAR *PSTR, *LPSTR, *NPSTR;
typedef const CHAR *PCSTR, *LPCSTR;
typedef CHAR *PZZSTR;
typedef const CHAR *PCZZSTR;

//Size, point, and rect structs
typedef struct tagSIZE
{
	LONG cx;
	LONG cy;
} SIZE, *PSIZE, *LPSIZE;

typedef SIZE SIZEL, *PSIZEL, *LPSIZEL;

typedef struct tagPOINT
{
	LONG  x;
	LONG  y;
} POINT, *PPOINT, *LPPOINT;

typedef struct _POINTL
{
	LONG x;
	LONG y;
} POINTL, *PPOINTL;

typedef struct tagRECT
{
	LONG left;
	LONG top;
	LONG right;
	LONG bottom;
} RECT, *PRECT, *LPRECT;
typedef const RECT *LPCRECT;

typedef struct _RECTL
{
	LONG left;
	LONG top;
	LONG right;
	LONG bottom;
} RECTL, *PRECTL, *LPRECTL;

typedef const RECTL *LPCRECTL;

//Handles
typedef class _HANDLE
{
	public:
		virtual ~_HANDLE() {}
} *HANDLE, **PHANDLE, **LPHANDLE;

//Misc. constants
#define MAX_PATH 260

//Some macros
#define DWORD_PTR DWORD
#define MAKEWORD(a, b)      ((WORD)(((BYTE)((DWORD_PTR)(a) & 0xff)) | ((WORD)((BYTE)((DWORD_PTR)(b) & 0xff))) << 8))
#define MAKELONG(a, b)      ((LONG)(((WORD)((DWORD_PTR)(a) & 0xffff)) | ((DWORD)((WORD)((DWORD_PTR)(b) & 0xffff))) << 16))
#define LOWORD(l)           ((WORD)((DWORD_PTR)(l) & 0xffff))
#define HIWORD(l)           ((WORD)((DWORD_PTR)(l) >> 16))
#define LOBYTE(w)           ((BYTE)((DWORD_PTR)(w) & 0xff))
#define HIBYTE(w)           ((BYTE)((DWORD_PTR)(w) >> 8))
