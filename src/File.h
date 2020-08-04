#pragma once
#include <cstdio>
#include <cstring>
#include <windows.h>


struct PixFile
{
  char type;
  FILE *fp;
  LPVOID res;
  DWORD bytesRead;
  DWORD size;
};


bool ReadFromFile(void *p, int size, int num, PixFile* _p_desc);