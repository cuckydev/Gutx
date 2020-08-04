#include <cstdio>
#include <cstring>
#include <windows.h>

int VarLenCheck( unsigned int us );
bool VarLenRead  ( DWORD *p, FILE* a2 );
int VarLenWrite( unsigned int val, FILE* _p_desc, DWORD p_add)