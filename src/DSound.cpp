




int AssignDirectSound(int a1)
{
  int result; 

  result = a1;
  DXSoundInterface = (LPDIRECTSOUND)a1;
  dword_44D36C = 1;
  return result;
}



signed int UnusedInitDirectSound(int a1)
{
  signed int result; 
  signed int i; 

  if ( DirectSoundCreate(0, &DXSoundInterface, 0) )
  {
    DXSoundInterface = 0;
    result = 0;
  }
  else
  {
    dword_44D36C = 0;
    if ( (*((int (__stdcall **)(_DWORD, _DWORD, _DWORD))DXSoundInterface->lpVtbl + 6))(DXSoundInterface, a1, 2) )
    {
      result = 0;
    }
    else
    {
      for ( i = 0; i < 64; ++i )
        dword_44D370[i] = 0;
      result = 1;
    }
  }
  return result;
}




int sub_424A30()
{
  int result; 
  signed int i; 

  if ( DXSoundInterface )
  {
    for ( i = 0; i < 64; ++i )
    {
      if ( dword_44D370[i] )
      {
        (*(void (__stdcall **)(int))(*(_DWORD *)dword_44D370[i] + 8))(dword_44D370[i]);
        dword_44D370[i] = 0;
      }
      result = i + 1;
    }
    if ( !dword_44D36C && DXSoundInterface )
      result = (*((int (__stdcall **)(_DWORD))DXSoundInterface->lpVtbl + 2))(DXSoundInterface);
  }
  return result;
}




signed int Unused3Sound(const CHAR *lpName, const CHAR *lpType, signed int a3)
{
  signed int result; 
  void *v4; 
  size_t v5; 
  int v6; 
  int v7; 
  int v8; 
  char *v9; 
  char v10; 
  int v11; 
  void *v12; 
  int v13; 
  size_t v14; 
  void *v15; 

  v13 = 0;
  v15 = 0;
  if ( DXSoundInterface )
  {
    if ( a3 >= 0 && a3 < 64 )
    {
      if ( sub_424C90(lpName, lpType, &v10, (int)&v11, (int)&v15) )
      {
        memset(&v6, 0, 0x14u);
        v6 = 20;
        v7 = 32994;
        v8 = v11;
        v9 = &v10;
        if ( !(*((int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD))DXSoundInterface->lpVtbl + 3))(
                DXSoundInterface,
                &v6,
                4 * a3 + 4510576,
                0)
          && !(*(int (__stdcall **)(int, _DWORD, int, void **, size_t *, void **, size_t *, _DWORD))(*(_DWORD *)dword_44D370[a3] + 44))(
                dword_44D370[a3],
                0,
                v11,
                &v12,
                &v5,
                &v4,
                &v14,
                0) )
        {
          memcpy(v12, v15, v5);
          if ( v14 )
            memcpy(v4, (char *)v15 + v5, v14);
          (*(void (__stdcall **)(int, void *, size_t, void *, size_t))(*(_DWORD *)dword_44D370[a3] + 76))(
            dword_44D370[a3],
            v12,
            v5,
            v4,
            v14);
          v13 = 1;
        }
      }
    }
    sub_424C60(&v15);
    if ( !v13 )
    {
      if ( dword_44D370[a3] )
      {
        (*(void (__stdcall **)(int))(*(_DWORD *)dword_44D370[a3] + 8))(dword_44D370[a3]);
        dword_44D370[a3] = 0;
      }
    }
    result = 1;
  }
  else
  {
    result = 1;
  }
  return result;
}



void **sub_424C60(void **a1)
{
  void **result; 

  result = a1;
  if ( *a1 )
  {
    free(*a1);
    result = a1;
    *a1 = 0;
  }
  return result;
}


int sub_424C90(LPCSTR lpName, LPCSTR lpType, void *a3, int a4, int a5)
{
  int v6; 
  char v7; 
  char v8; 
  char v9; 
  char v10; 
  char v11; 
  char v12; 
  char v13; 
  char v14; 
  char v15; 
  char v16; 
  size_t v17; 
  int v18; 
  int v19; 

  v18 = 0;
  *(_DWORD *)a5 = 0;
  memset(a3, 0, 0x12u);
  if ( OpenResource_(0, lpName, lpType, (int)&v19) )
  {
    if ( PixelRead((int)&v6, 1u, 44, (int)&v19) )
    {
      if ( (char)v6 == 82
        && SBYTE1(v6) == 73
        && SBYTE2(v6) == 70
        && SBYTE3(v6) == 70
        && v8 == 87
        && v9 == 65
        && v10 == 86
        && v11 == 69
        && v12 == 102
        && v13 == 109
        && v14 == 116
        && v15 == 32 )
      {
        memcpy(a3, &v16, 0x12u);
        if ( *(_WORD *)a3 == 1
          && (*((_WORD *)a3 + 1) == 1 || *((_WORD *)a3 + 1) == 2)
          && (*((_WORD *)a3 + 7) == 8 || *((_WORD *)a3 + 7) == 16) )
        {
          sub_4220D0((int)&v19, 12, 0);
          while ( PixelRead((int)&v6, 1u, 8, (int)&v19) )
          {
            memcpy(&v17, &v7, 4u);
            if ( !memcmp("data", &v6, 4u) )
            {
              if ( sub_424EB0(a5, v17) && PixelRead(*(_DWORD *)a5, 1u, v17, (int)&v19) )
              {
                *(_DWORD *)a4 = v17;
                v18 = 1;
              }
              break;
            }
            sub_4220D0((int)&v19, v17, 1);
          }
        }
      }
    }
  }
  if ( !v18 )
    sub_424C60((void **)a5);
  CloseResource_((int)&v19);
  return v18;
}


int sub_424EB0(int a1, size_t a2)
{
  int result; 

  *(_DWORD *)a1 = malloc(a2);
  if ( *(_DWORD *)a1 )
  {
    memset(*(void **)a1, 0, a2);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}


signed int sub_424EF0(const CHAR *lpName, const CHAR *lpType, int a3, int a4, int a5, signed int a6)
{
  signed int result; 
  void *v7; 
  size_t v8; 
  int v9; 
  int v10; 
  int v11; 
  char *v12; 
  char v13; 
  int v14; 
  void *v15; 
  int v16; 
  size_t v17; 
  void *v18; 

  v16 = 0;
  v18 = 0;
  if ( DXSoundInterface )
  {
    if ( a6 >= 0 && a6 < 64 )
    {
      if ( sub_4250A0(lpName, lpType, &v13, (int)&v14, (int)&v18, a3, a4, a5) )
      {
        memset(&v9, 0, 0x14u);
        v9 = 20;
        v10 = 32994;
        v11 = v14;
        v12 = &v13;
        if ( !(*((int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD))DXSoundInterface->lpVtbl + 3))(
                DXSoundInterface,
                &v9,
                4 * a6 + 4510576,
                0)
          && !(*(int (__stdcall **)(int, _DWORD, int, void **, size_t *, void **, size_t *, _DWORD))(*(_DWORD *)dword_44D370[a6] + 44))(
                dword_44D370[a6],
                0,
                v14,
                &v15,
                &v8,
                &v7,
                &v17,
                0) )
        {
          memcpy(v15, v18, v8);
          if ( v17 )
            memcpy(v7, (char *)v18 + v8, v17);
          (*(void (__stdcall **)(int, void *, size_t, void *, size_t))(*(_DWORD *)dword_44D370[a6] + 76))(
            dword_44D370[a6],
            v15,
            v8,
            v7,
            v17);
          v16 = 1;
        }
      }
    }
    sub_424C60(&v18);
    if ( !v16 )
    {
      if ( dword_44D370[a6] )
      {
        (*(void (__stdcall **)(int))(*(_DWORD *)dword_44D370[a6] + 8))(dword_44D370[a6]);
        dword_44D370[a6] = 0;
      }
    }
    result = v16;
  }
  else
  {
    result = 1;
  }
  return result;
}



int sub_4250A0(LPCSTR lpName, LPCSTR lpType, void *a3, int a4, int a5, int a6, int a7, int a8)
{
  __int64 v8; 
  signed int v10; 
  int v11; 
  int v12; 

  v10 = 0;
  *(_DWORD *)a5 = 0;
  memset(&v12, 0, 0xCu);
  memset(a3, 0, 0x12u);
  if ( OpenResource_(0, lpName, lpType, (int)&v11)
    && ReadPtnoise_((int)&v11, &v12, 0)
    && DecodePtnoise_((void **)a5, (int)&v12, a6, a7, a8) )
  {
    *((_WORD *)a3 + 8) = 0;
    *(_WORD *)a3 = 1;
    *((_WORD *)a3 + 1) = a6;
    *((_DWORD *)a3 + 1) = a7;
    *((_WORD *)a3 + 7) = a8;
    v8 = *((_WORD *)a3 + 7) * *((_WORD *)a3 + 1);
    *((_WORD *)a3 + 6) = ((BYTE4(v8) & 7) + (signed int)v8) >> 3;
    *((_DWORD *)a3 + 2) = *((_DWORD *)a3 + 1) * *((_WORD *)a3 + 6);
    *(_DWORD *)a4 = v12 / (44100 / a7) * *((_WORD *)a3 + 6);
    v10 = 1;
  }
  CloseResource_((int)&v11);
  if ( !v10 )
    sub_424C60((void **)a5);
  return v10;
}


signed int sub_4251F0(signed int a1)
{
  signed int result; 

  if ( DXSoundInterface )
  {
    result = a1;
    if ( dword_44D370[a1] )
    {
      if ( a1 >= 0 && a1 < 64 )
      {
        (*(void (__stdcall **)(int))(*(_DWORD *)dword_44D370[a1] + 8))(dword_44D370[a1]);
        result = a1;
        dword_44D370[a1] = 0;
      }
    }
  }
  return result;
}



int sub_425250(signed int a1)
{
  int result; 

  if ( DXSoundInterface )
  {
    result = a1;
    if ( dword_44D370[a1] )
    {
      if ( a1 >= 0 && a1 < 64 )
      {
        (*(void (__stdcall **)(int))(*(_DWORD *)dword_44D370[a1] + 72))(dword_44D370[a1]);
        (*(void (__stdcall **)(int, _DWORD))(*(_DWORD *)dword_44D370[a1] + 52))(dword_44D370[a1], 0);
        result = (*(int (__stdcall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)dword_44D370[a1] + 48))(
                   dword_44D370[a1],
                   0,
                   0,
                   0);
      }
    }
  }
  return result;
}



int startloopsoundproc_(signed int a1)
{
  int result; 

  if ( DXSoundInterface )
  {
    result = a1;
    if ( dword_44D370[a1] )
    {
      if ( a1 >= 0 && a1 < 64 )
        result = (*(int (__stdcall **)(int, _DWORD, _DWORD, signed int))(*(_DWORD *)dword_44D370[a1] + 48))(
                   dword_44D370[a1],
                   0,
                   0,
                   1);
    }
  }
  return result;
}



int stoploopsoundproc_(signed int a1)
{
  int result; 

  if ( DXSoundInterface )
  {
    result = a1;
    if ( dword_44D370[a1] )
    {
      if ( a1 >= 0 && a1 < 64 )
        result = (*(int (__stdcall **)(int))(*(_DWORD *)dword_44D370[a1] + 72))(dword_44D370[a1]);
    }
  }
  return result;
}
