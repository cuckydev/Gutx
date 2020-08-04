#pragma once
#include <cstdio>
#include <cstring>
#include <windows.h>

int VarLenCheck( unsigned int us );
bool VarLenRead  ( DWORD *p, PixFile* a2 );
int VarLenWrite( int val, FILE* _p_desc, DWORD* p_add);