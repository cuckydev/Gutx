

int InitDirectInput(HINSTANCE hinst, int a2)
{
  int result; 

  if ( DirectInputCreateA(hinst, 0x500u, &ppDI, 0) )
    result = 0;
  else
    result = sub_422730(a2) != 0;
  return result;
}


signed int sub_422730(int a1)
{
  signed int result; 
  LPDIRECTINPUTA v2; 
  int v3; 

  v3 = 0;
  v2 = ppDI;
  (*((void (__stdcall **)(_DWORD))ppDI->lpVtbl + 1))(ppDI);
  (*((void (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))ppDI->lpVtbl + 4))(ppDI, 4, sub_422800, &v2, 1);
  if ( v2 )
  {
    (*((void (__stdcall **)(LPDIRECTINPUTA))v2->lpVtbl + 2))(v2);
    v2 = 0;
  }
  if ( v3 )
  {
    dword_44CD0C = v3;
    if ( (*(int (__stdcall **)(int, int *))(*(_DWORD *)v3 + 44))(v3, dword_429190) )
    {
      result = 0;
    }
    else if ( (*(int (__stdcall **)(int, int, signed int))(*(_DWORD *)dword_44CD0C + 52))(dword_44CD0C, a1, 9) )
    {
      result = 0;
    }
    else
    {
      (*(void (__stdcall **)(int))(*(_DWORD *)dword_44CD0C + 28))(dword_44CD0C);
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}




signed int sub_422800(void *this, int a2, int a3)
{
  signed int result; 

  if ( !(dword_44CD24 & 1) )
  {
    dword_44CD24 |= 1u;
    dword_44CD20 = a3;
  }
  if ( (*(int (__stdcall **)(_DWORD, int, int *, _DWORD, void *))(**(_DWORD **)dword_44CD20 + 12))(
         *(_DWORD *)dword_44CD20,
         a2 + 4,
         &dword_44CD1C,
         0,
         this) )
  {
    *(_DWORD *)(dword_44CD20 + 4) = 0;
    result = 1;
  }
  else if ( (**(int (__stdcall ***)(int, void *, int *))dword_44CD1C)(dword_44CD1C, &unk_43C9E0, &dword_44CD18) >= 0 )
  {
    if ( dword_44CD1C )
    {
      (*(void (__stdcall **)(int))(*(_DWORD *)dword_44CD1C + 8))(dword_44CD1C);
      dword_44CD1C = 0;
    }
    *(_DWORD *)(dword_44CD20 + 4) = dword_44CD18;
    result = 0;
  }
  else
  {
    dword_44CD0C = 0;
    result = 1;
  }
  return result;
}







int ReleaseDirectInput()
{
  int result; 

  if ( dword_44CD0C )
  {
    result = (*(int (__stdcall **)(int))(*(_DWORD *)dword_44CD0C + 8))(dword_44CD0C);
    dword_44CD0C = 0;
  }
  if ( ppDI )
  {
    result = (*((int (__stdcall **)(_DWORD))ppDI->lpVtbl + 2))(ppDI);
    ppDI = 0;
  }
  return result;
}



signed int JoystickProc_(int a1)
{
  int v2; 
  signed int i; 
  int v4; 
  int v5; 
  char v6[36]; 

  if ( !dword_44CD0C )
    return 0;
  if ( (*(int (__stdcall **)(int))(*(_DWORD *)dword_44CD0C + 100))(dword_44CD0C) )
    return 0;
  v2 = (*(int (__stdcall **)(int, signed int, int *))(*(_DWORD *)dword_44CD0C + 36))(dword_44CD0C, 80, &v4);
  if ( v2 == -2147024866 )
  {
    sub_422AA0(0);
  }
  else if ( v2 )
  {
    return 0;
  }
  for ( i = 0; i < 32; ++i )
  {
    if ( v6[i] & 0x80 )
      *(_DWORD *)(a1 + 16) |= 1 << i;
    else
      *(_DWORD *)(a1 + 16) &= ~(1 << i);
  }
  *(_DWORD *)(a1 + 12) = 0;
  *(_DWORD *)(a1 + 4) = 0;
  *(_DWORD *)(a1 + 8) = 0;
  *(_DWORD *)a1 = 0;
  if ( v4 >= dword_44CD10 - 10000 )
  {
    if ( v4 > dword_44CD10 + 10000 )
      *(_DWORD *)(a1 + 4) = 1;
  }
  else
  {
    *(_DWORD *)a1 = 1;
  }
  if ( v5 >= dword_44CD14 - 10000 )
  {
    if ( v5 > dword_44CD14 + 10000 )
      *(_DWORD *)(a1 + 12) = 1;
  }
  else
  {
    *(_DWORD *)(a1 + 8) = 1;
  }
  return 1;
}






signed int sub_422AA0(int a1)
{
  signed int result; 

  if ( dword_44CD0C )
  {
    if ( a1 )
      (*(void (__stdcall **)(int))(*(_DWORD *)dword_44CD0C + 28))(dword_44CD0C);
    else
      (*(void (__stdcall **)(int))(*(_DWORD *)dword_44CD0C + 32))(dword_44CD0C);
    result = 1;
  }
  else
  {
    result = 1;
  }
  return result;
}



signed int sub_422AF0()
{
  int v1; 
  int v2; 
  int v3; 

  if ( !dword_44CD0C )
    return 0;
  if ( (*(int (__stdcall **)(int))(*(_DWORD *)dword_44CD0C + 100))(dword_44CD0C) )
    return 0;
  v1 = (*(int (__stdcall **)(int, signed int, int *))(*(_DWORD *)dword_44CD0C + 36))(dword_44CD0C, 80, &v2);
  if ( v1 == 0x8007001E )
  {
    sub_422AA0(0);
  }
  else if ( v1 )
  {
    return 0;
  }
  dword_44CD10 = v2;
  dword_44CD14 = v3;
  return 1;
}



