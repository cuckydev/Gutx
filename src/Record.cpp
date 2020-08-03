int PlayRecordFlag; 
int PlayRecordTrg; 
int PlayRecordActionCount; 
int PlayRecordHold; 
int PlayRecordSize; 
void *PlayRecordActionTbl; 


signed int InitPlayRecord()
{
  signed int result; 

  memset(&SystemTime, 0, 0x28u);
  PlayRecordSize = 90000;
  PlayRecordActionTbl = malloc(0xAFC80u);
  if ( PlayRecordActionTbl )
  {
    memset(PlayRecordActionTbl, 0, 8 * PlayRecordSize);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}



void FreePlayRecord()
{
  if ( PlayRecordActionTbl )
  {
    free(PlayRecordActionTbl);
    PlayRecordActionTbl = 0;
  }
}


void NewPlayRecord()
{
  GetLocalTime(&SystemTime);
  PlayRecordFlag = 0;
  PlayRecordTrg = 0;
  PlayRecordHold = 0;
  PlayRecordActionCount = 0;
}






void ZeroPlayRecord()
{
  PlayRecordFlag = 0;
  PlayRecordTrg = 0;
  PlayRecordHold = 0;
  PlayRecordActionCount = 0;
}






signed int RecordPlayRecord(int a1)
{
  signed int result; 

  if ( PlayRecordActionTbl )
  {
    if ( PlayRecordActionCount < PlayRecordSize )
    {
      if ( PlayRecordFlag & 1 )
      {
        if ( PlayRecordTrg == a1 )
        {
          ++PlayRecordHold;
        }
        else
        {
          *((_DWORD *)PlayRecordActionTbl + 2 * PlayRecordActionCount + 1) = PlayRecordTrg;
          *((_DWORD *)PlayRecordActionTbl + 2 * PlayRecordActionCount) = PlayRecordHold;
          PlayRecordTrg = a1;
          PlayRecordHold = 1;
          ++PlayRecordActionCount;
        }
      }
      else
      {
        PlayRecordFlag |= 1u;
        PlayRecordTrg = a1;
        PlayRecordHold = 1;
      }
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}







int EndPlayRecord()
{
  *((_DWORD *)PlayRecordActionTbl + 2 * PlayRecordActionCount + 1) = PlayRecordTrg;
  *((_DWORD *)PlayRecordActionTbl + 2 * PlayRecordActionCount) = PlayRecordHold;
  return PlayRecordActionCount++ + 1;
}





int ActPlayRecord()
{
  int result; 

  if ( PlayRecordActionTbl )
  {
    if ( PlayRecordActionCount < PlayRecordSize && *((_DWORD *)PlayRecordActionTbl + 2 * PlayRecordActionCount) )
    {
      if ( PlayRecordHold == *((_DWORD *)PlayRecordActionTbl + 2 * PlayRecordActionCount) )
      {
        ++PlayRecordActionCount;
        PlayRecordHold = 0;
      }
      ++PlayRecordHold;
      result = *((_DWORD *)PlayRecordActionTbl + 2 * PlayRecordActionCount + 1);
    }
    else
    {
      PlayRecordFlag |= 2u;
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}






BOOL CheckPlayRecordFlag()
{
  return (PlayRecordFlag & 2) != 0;
}



int WritePlayRecord(char inScoreAttack, int stage, int score)
{
  CHAR PathName; 
  struct _SYSTEMTIME *v5; 
  int i; 
  char v7; 
  int v8; 
  FILE *v9; 

  v8 = 0;
  v9 = 0;
  v7 = 67;
  sprintf(&PathName, "%s\\%s", pszPath, playrecordsFolder[0]);
  CreateDirectoryA(&PathName, 0);
  v5 = &SystemTime;
  if ( stage )
    v7 = stage + 48;
  sprintf(
    &PathName,
    "%s\\%s\\%04d%02d%02d-%02d%02d%02d-%c-%d.%s",
    pszPath,
    playrecordsFolder[0],
    v5->wYear,
    v5->wMonth,
    v5->wDay,
    v5->wHour,
    v5->wMinute,
    v5->wSecond,
    v7,
    10 * score,
    replayPrefix);
  v9 = fopen(&PathName, "wb");
  if ( v9
    && WriteToFile(playRecordHeader, 1u, 8u, v9) == 8
    && WriteToFile(&inScoreAttack, 4u, 1u, v9) == 1
    && WriteToFile(&PlayRecordActionCount, 4u, 1u, v9) == 1 )
  {
    for ( i = 0; i < PlayRecordActionCount; ++i )
    {
      if ( !VariableLengthWrite(*((_DWORD *)PlayRecordActionTbl + 2 * i), v9, 0)
        || !VariableLengthWrite(*((_DWORD *)PlayRecordActionTbl + 2 * i + 1), v9, 0) )
      {
        goto LABEL_13;
      }
    }
    v8 = 1;
  }
LABEL_13:
  if ( v9 )
    fclose(v9);
  if ( v8 )
  {
    sprintf(&PathName, "%s\\%s", pszPath, playrecordsFolder[0]);
    DeleteOldPlayRecord((int)&PathName, 0x10u);
  }
  return v8;
}





void DeleteOldPlayRecord(int a1, unsigned int a2)
{
  size_t v2; 
  const FILETIME *v3; 
  int v4; 
  int v5; 
  int v6; 
  int v7; 
  int v8; 
  LPCSTR *v9; 
  void **v10; 
  unsigned int l; 
  unsigned int k; 
  unsigned int j; 
  unsigned int i; 
  HANDLE hFindFile; 
  CHAR FileName; 
  struct _WIN32_FIND_DATAA FindFileData; 
  HANDLE hFile; 
  char *v19; 
  struct _FILETIME LastWriteTime; 
  char v21; 
  int v22; 

  sub_41F6D0(&v21);
  v22 = 0;
  sprintf(&FileName, "%s\\*.%s", a1, replayPrefix);
  hFindFile = FindFirstFileA(&FileName, &FindFileData);
  while ( hFindFile != (HANDLE)-1 )
  {
    if ( FindFileData.cFileName[0] != 46
      && !(FindFileData.dwFileAttributes & 0x10)
      && !(FindFileData.dwFileAttributes & 4) )
    {
      sprintf(&FileName, "%s\\%s", a1, FindFileData.cFileName);
      hFile = CreateFileA(&FileName, 0, 0, 0, 3u, 0x80u, 0);
      if ( hFile != (HANDLE)-1 )
      {
        if ( GetFileTime(hFile, 0, 0, &LastWriteTime) )
        {
          CloseHandle(hFile);
          v2 = strlen(&FileName);
          v19 = (char *)malloc(v2 + 1);
          if ( v19 )
          {
            strcpy(v19, &FileName);
            sub_41F7B0(&v21, (int)&v19);
          }
        }
      }
    }
    if ( !FindNextFileA(hFindFile, &FindFileData) )
    {
      FindClose(hFindFile);
      break;
    }
  }
  for ( i = sub_41F720((int)&v21) - 1; i; --i )
  {
    for ( j = 0; j < i; ++j )
    {
      v3 = (const FILETIME *)(sub_41F760(&v21, j + 1) + 4);
      v4 = sub_41F760(&v21, j);
      if ( CompareFileTime((const FILETIME *)(v4 + 4), v3) < 0 )
      {
        v5 = sub_41F760(&v21, j);
        v19 = *(char **)v5;
        LastWriteTime = *(struct _FILETIME *)(v5 + 4);
        v6 = sub_41F760(&v21, j + 1);
        v7 = sub_41F760(&v21, j);
        *(_DWORD *)v7 = *(_DWORD *)v6;
        *(_DWORD *)(v7 + 4) = *(_DWORD *)(v6 + 4);
        *(_DWORD *)(v7 + 8) = *(_DWORD *)(v6 + 8);
        v8 = sub_41F760(&v21, j + 1);
        *(_DWORD *)v8 = v19;
        *(struct _FILETIME *)(v8 + 4) = LastWriteTime;
      }
    }
  }
  for ( k = a2; k < sub_41F720((int)&v21); ++k )
  {
    v9 = (LPCSTR *)sub_41F760(&v21, k);
    DeleteFileA(*v9);
  }
  for ( l = 0; l < sub_41F720((int)&v21); ++l )
  {
    v10 = (void **)sub_41F760(&v21, l);
    free(*v10);
  }
  v22 = -1;
  unknown_libname_5(&v21);
}



int ReadPlayRecord(char *a1, int a2)
{
  int result; 
  CHAR Name; 
  int v4; 
  int i; 
  int v6; 
  int v7; 
  int v8; 

  v7 = 0;
  if ( a1 )
    strcpy(&Name, a1);
  else
    
    sprintf(&Name, "%s\\%s", pszPath, "demo.bin");
  if ( PlayRecordActionTbl )
  {
    memset(PlayRecordActionTbl, 0, 8 * PlayRecordSize);
    memset(&v8, 0, 0x14u);
    if ( OpenResource_(0, &Name, 0, (int)&v8)
      && PixelRead((int)&v4, 1u, 8, (int)&v8)
      && PixelRead(a2, 4u, 1, (int)&v8)
      && PixelRead((int)&v6, 4u, 1, (int)&v8)
      && !memcmp(playRecordHeader, &v4, 8u)
      && v6 <= 89998 )
    {
      for ( i = 0; i < v6; ++i )
      {
        if ( !VariableLengthRead((_DWORD *)PlayRecordActionTbl + 2 * i, (int)&v8)
          || !VariableLengthRead((_DWORD *)PlayRecordActionTbl + 2 * i + 1, (int)&v8) )
        {
          goto LABEL_19;
        }
      }
      v7 = 1;
    }
LABEL_19:
    if ( !v7 )
      memset(PlayRecordActionTbl, 0, 0xAFC80u);
    CloseResource_((int)&v8);
    result = v7;
  }
  else
  {
    result = 0;
  }
  return result;
}

