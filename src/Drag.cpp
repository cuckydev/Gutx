



void *DragEnable(HWND hWnd)
{
  DragAcceptFiles(hWnd, 1);
  return memset(szFile, 0, 0x104u);
}


signed int DragFileProc(int a1, HDROP a2)
{
  signed int v3; 

  v3 = 0;
  memset(szFile, 0, 0x104u);
  if ( DragQueryFileA(a2, 0xFFFFFFFF, 0, 0) )
  {
    DragQueryFileA(a2, 0, szFile, 0x104u);
    v3 = 1;
  }
  DragFinish(a2);
  return v3;
}


BOOL CheckDragFile()
{
  return strlen(szFile) != 0;
}


CHAR *GetDragFile()
{
  return szFile;
}


void *InitDragFile()
{
  return memset(szFile, 0, 0x104u);
}

