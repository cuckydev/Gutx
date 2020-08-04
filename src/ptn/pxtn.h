// '16/04/28 pxtn.h
// '16/12/03 pxtnRESULT.
// '16/12/15 pxtnRESULT -> pxtnERR/pxtnOK.

#ifndef pxtn_H
#define pxtn_H

//#define pxINCLUDE_OGGVORBIS 1
// $(SolutionDir)libogg\include;$(SolutionDir)libvorbis\include;

#if defined(_WIN32)
#include <cstdint>
#else
#include <stdint.h>
#endif

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#include <windows.h>

typedef struct
{
    DWORD x;
    DWORD y;
}
pxtnPOINT;

//#include "./pxtnError.h"

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if( p ){ delete( p ); p = NULL; } }
#endif

#endif
