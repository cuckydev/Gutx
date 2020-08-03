
char *ClearSurface(signed int a1)
{
  char *result; 
  char *v2; 

  if ( a1 < 64 )
  {
    result = (char *)&surfaceTbl2_ + 20 * a1;
    v2 = (char *)&surfaceTbl2_ + 20 * a1;
    if ( *((_DWORD *)&surfaceTbl2_ + 5 * a1 + 2) )
    {
      ReleaseSurface((void **)v2 + 1);
      (*(void (__stdcall **)(_DWORD))(**((_DWORD **)v2 + 2) + 8))(*((_DWORD *)v2 + 2));
      unusedDDrawmath -= magnification * *((_DWORD *)v2 + 4) * magnification * *((_DWORD *)v2 + 3);
      result = (char *)memset(v2, 0, 0x14u);
    }
  }
  return result;
}



void **ReleaseSurface(void **a1)
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


int ClearSurfaceTbl()
{
  int result; 
  signed int i; 

  for ( i = 0; i < 64; ++i )
  {
    ClearSurface(i);
    result = i + 1;
  }
  return result;
}


int SetRenderOffset(int a1, int a2)
{
  int result; 

  result = a1;
  RenderOffsetX = a1;
  RenderOffsetY = a2;
  return result;
}




int SetFullscreenRenderPos()
{
  int result; 

  RenderOffsetX = (GetSystemMetrics(0) - magnification * MainSurfaceWidth) / 2;
  result = (GetSystemMetrics(1) - magnification * MainSurfaceHeight) / 2;
  RenderOffsetY = result;
  return result;
}






signed int SetCooperativeMode(int a1)
{
  if ( !lpDD )
    return 0;
  if ( a1 )
  {
    if ( lpDD->lpVtbl->SetCooperativeLevel(lpDD, DDHWnd, 0x11) )
      return 0;
  }
  else
  {
    if ( lpDD->lpVtbl->SetCooperativeLevel(lpDD, DDHWnd, 8) )
      return 0;
    RenderOffsetX = 0;
    RenderOffsetY = 0;
  }
  dword_44D35C = a1;
  return 1;
}





int InitDirectDraw(int a1, char *a2, int a3, int a4)
{
  int result; 

  memset(DataPathFull, 0, 0x104u);
  if ( a2 )
    strcpy(DataPathFull, a2);
  memset(&surfaceTbl2_, 0, 0x500u);
  if ( DirectDrawCreate(0, &lpDD, 0) )
  {
    result = 0;
  }
  else
  {
    DDHWnd = (HWND)a1;
    if ( SetCooperativeMode(a3) )
    {
      unusedDDrawmath = 0;
      PximgDecodeEnabled = a4;
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  return result;
}




HRESULT EndDirectDraw(int a1)
{
  HRESULT result; 

  ClearSurfaceTbl();
  ReleaseSurfaceA();
  result = lpDD->lpVtbl->SetCooperativeLevel(lpDD, (HWND)a1, 8);
  if ( lpDD )
  {
    result = lpDD->lpVtbl->Release(lpDD);
    lpDD = 0;
  }
  DDHWnd = 0;
  return result;
}


signed int InitMainSurface(int a1, int a2, int a3, int a4)
{
  signed int result; 
  int v5; 
  int v6; 
  int v7; 
  int v8; 
  int v9; 
  int v10; 
  int v11; 
  int v12; 
  int v13; 
  int v14; 
  int v15; 
  int v16; 

  MainSurfaceWidth = a2;
  MainSurfaceHeight = a3;
  magnification = a4;
  memset(&v5, 0, 0x6Cu);
  v5 = 108;
  v6 = 1;
  v10 = 512;
  v9 = 0;
  if ( lpDD->lpVtbl->CreateSurface(lpDD, (LPDDSURFACEDESC)&v5, (LPDIRECTDRAWSURFACE *)&SurfaceA, 0) )
  {
    result = 0;
  }
  else
  {
    memset(&v5, 0, 0x6Cu);
    v5 = 108;
    v6 = 7;
    v10 = 64;
    v8 = magnification * MainSurfaceWidth;
    v7 = magnification * MainSurfaceHeight;
    if ( lpDD->lpVtbl->CreateSurface(lpDD, (LPDDSURFACEDESC)&v5, (LPDIRECTDRAWSURFACE *)&SurfaceB, 0) )
    {
      result = 0;
    }
    else
    {
      lpDD->lpVtbl->CreateClipper(lpDD, 0, (LPDIRECTDRAWCLIPPER *)&DDrawClipper, 0);
      (*(void (__stdcall **)(int, _DWORD, int))(*(_DWORD *)DDrawClipper + 32))(DDrawClipper, 0, a1);
      (*(void (__stdcall **)(int, int))(*(_DWORD *)SurfaceA + 112))(SurfaceA, DDrawClipper);
      memset(&v15, 0, 0x64u);
      v15 = 100;
      v16 = 0;
      v11 = 0;
      v13 = magnification * MainSurfaceWidth;
      v12 = 0;
      v14 = magnification * MainSurfaceHeight;
      (*(void (__stdcall **)(int, int *, _DWORD, _DWORD, signed int, int *))(*(_DWORD *)SurfaceB + 20))(
        SurfaceB,
        &v11,
        0,
        0,
        16778240,
        &v15);
      unusedDDrawmath += magnification * MainSurfaceHeight * magnification * MainSurfaceWidth;
      result = 1;
    }
  }
  return result;
}








int ReleaseSurfaceA()
{
  int result; 

  if ( SurfaceA )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)SurfaceA + 8))(SurfaceA);
    SurfaceA = 0;
    result = magnification * MainSurfaceHeight * magnification * MainSurfaceWidth;
    unusedDDrawmath -= result;
  }
  return result;
}






signed int Flip_Screen()
{
  signed int result; 
  int v1; 
  int v2; 
  int v3; 
  int v4; 
  struct tagRECT Rect; 

  if ( lpDD && DDHWnd )
  {
    v1 = 0;
    v2 = 0;
    v3 = magnification * MainSurfaceWidth;
    v4 = magnification * MainSurfaceHeight;
    GetWindowRect(DDHWnd, &Rect);
    Rect.left += RenderOffsetX;
    Rect.top += RenderOffsetY;
    Rect.right = Rect.left + magnification * MainSurfaceWidth;
    Rect.bottom = Rect.top + magnification * MainSurfaceHeight;
    (*(void (__stdcall **)(int, struct tagRECT *, int, int *, signed int, _DWORD))(*(_DWORD *)SurfaceA + 20))(
      SurfaceA,
      &Rect,
      SurfaceB,
      &v1,
      0x1000000,
      0);
    sub_4245E0();
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}








int MakeSurface_Pximg(char *a1, int a2, int a3, int a4)
{
  int result; 
  HMODULE v5; 
  size_t v6; 
  signed int fuLoad; 
  CHAR name; 
  char pv; 
  int wSrc; 
  int hSrc; 
  char *v12; 
  HANDLE h; 

  if ( a2 < 64 )
  {
    if ( surfaceTbl_[5 * a2] )
    {
      result = 0;
    }
    else
    {
      v12 = (char *)&surfaceTbl2_ + 20 * a2;
      if ( a3 )
      {
        if ( a1[1] == 58 )
          strcpy(&name, a1);
        else
          sprintf(&name, "%s\\%s", DataPathFull, a1);
        fuLoad = 8208;
      }
      else
      {
        strcpy(&name, a1);
        fuLoad = 0x2000;
      }
      v5 = GetModuleHandleA(0);
      h = LoadImageA(v5, &name, 0, 0, 0, fuLoad);
      if ( h )
      {
        GetObjectA(h, 24, &pv);
        if ( MakeSurface((int)(v12 + 8), wSrc, hSrc, a4) )
        {
          PreparePximg(*((_DWORD *)v12 + 2), h, wSrc, hSrc);
          DeleteObject(h);
          ReleaseSurface((void **)v12 + 1);
          v6 = strlen(a1);
          if ( !AllocSurface((int)(v12 + 4), v6 + 1) )
            ClearSurface(a2);
          strcpy(*((char **)v12 + 1), a1);
          *((_DWORD *)v12 + 3) = wSrc;
          *((_DWORD *)v12 + 4) = hSrc;
          *(_DWORD *)v12 = 0;
          if ( a3 )
            *(_DWORD *)v12 |= 1u;
          if ( a4 )
            *(_DWORD *)v12 |= 2u;
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
    }
  }
  else
  {
    result = 0;
  }
  return result;
}



int AllocSurface(int a1, size_t a2)
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


signed int MakeSurface(int a1, int a2, int a3, int a4)
{
  signed int result; 
  int v5; 
  int v6; 
  int v7; 
  int v8; 
  int v9; 
  int v10; 
  int v11; 

  memset(&v5, 0, 0x6Cu);
  v5 = 108;
  v6 = 7;
  v8 = magnification * a2;
  v7 = magnification * a3;
  if ( a4 )
    v9 = 2112;
  else
    v9 = 64;
  if ( lpDD->lpVtbl->CreateSurface(lpDD, (LPDDSURFACEDESC)&v5, (LPDIRECTDRAWSURFACE *)a1, 0) )
  {
    result = 0;
  }
  else
  {
    unusedDDrawmath += v7 * v8;
    v10 = 0;
    v11 = 0;
    (*(void (__stdcall **)(_DWORD, signed int, int *))(**(_DWORD **)a1 + 116))(*(_DWORD *)a1, 8, &v10);
    result = 1;
  }
  return result;
}



BOOL PreparePximg(int a1, HGDIOBJ h, int wSrc, int hSrc)
{
  int i; 
  char info; 
  int v7; 
  HDC hdc; 
  HGDIOBJ v9; 
  HDC hdcDest; 

  hdc = CreateCompatibleDC(0);
  v9 = SelectObject(hdc, h);
  (*(void (__stdcall **)(int, HDC *))(*(_DWORD *)a1 + 68))(a1, &hdcDest);
  if ( PximgDecodeEnabled )
  {
    if ( DecodePximg((PximgDecodeInfo *)&info, hSrc, 0x4444, 0x8888) )
    {
      for ( i = 0; i < hSrc; ++i )
        StretchBlt(
          hdcDest,
          0,
          magnification * i,
          magnification * wSrc,
          magnification,
          hdc,
          0,
          *(_DWORD *)(v7 + 4 * i),
          wSrc,
          1,
          0xCC0020u);
      ReleasePximgDecoder((int)&info);
    }
  }
  else
  {
    StretchBlt(hdcDest, 0, 0, magnification * wSrc, magnification * hSrc, hdc, 0, 0, wSrc, hSrc, 0xCC0020u);
  }
  (*(void (__stdcall **)(int, HDC))(*(_DWORD *)a1 + 104))(a1, hdcDest);
  SelectObject(hdc, v9);
  return DeleteDC(hdc);
}




int DecodePximg(PximgDecodeInfo *info, int img_height, __int16 hash_a, __int16 hash_b)
{
  int result; 
  int i; 
  signed int cycle_count; 
  int cur_line; 

  memset(info, 0, 0x10u);
  info->hash_a = (unsigned __int16)hash_a;
  *(_DWORD *)&info->hash_b = (unsigned __int16)hash_b;
  info->height = img_height;
  info->line_indexes = malloc(4 * img_height);
  if ( info->line_indexes )
  {
    memset((void *)info->line_indexes, 255, 4 * img_height);
    cur_line = 0;
    for ( i = 0; i < img_height; ++i )
    {
      cycle_count = (signed int)(unsigned __int16)PximgHashShuffle(info) >> 8;
      if ( !cycle_count )
        cycle_count = 1;
      do
      {
        cur_line = (cur_line + 1) % img_height;
        if ( *(_DWORD *)(info->line_indexes + 4 * cur_line) == -1 )
          --cycle_count;
      }
      while ( cycle_count );
      *(_DWORD *)(info->line_indexes + 4 * cur_line) = i;
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}


__int16 PximgHashShuffle(PximgDecodeInfo *a1)
{
  __int16 res; 
  int *u1; 
  __int16 *u2; 
  int tmp; 

  tmp = (signed __int16)(a1->hash_b + a1->hash_a);
  u1 = &tmp;
  u2 = &res;
  LOBYTE(res) = BYTE1(tmp);
  HIBYTE(res) = tmp;
  *(_DWORD *)&a1->hash_b = LOWORD(a1->hash_a);
  a1->hash_a = res;
  return res;
}


int ReleasePximgDecoder(int a1)
{
  int result; 

  result = a1;
  if ( *(_DWORD *)(a1 + 4) )
  {
    free(*(void **)(a1 + 4));
    result = a1;
    *(_DWORD *)(a1 + 4) = 0;
  }
  return result;
}


signed int InitSurface_(int a1, int a2, signed int a3, int a4)
{
  signed int result; 
  _DDSURFACEDESC *v5; 

  if ( a3 < 64 )
  {
    if ( surfaceTbl_[5 * a3] )
    {
      result = 0;
    }
    else
    {
      v5 = (_DDSURFACEDESC *)((char *)&surfaceTbl2_ + 20 * a3);
      if ( MakeSurface((int)&surfaceTbl2_ + 20 * a3 + 8, a1, a2, a4) )
      {
        ReleaseSurface((void **)&v5->dwFlags);
        v5->dwWidth = a1;
        v5->lPitch = a2;
        if ( a4 )
          v5->dwSize |= 2u;
        else
          v5->dwSize &= 0xFFFFFFFD;
        result = 1;
      }
      else
      {
        result = 0;
      }
    }
  }
  else
  {
    result = 0;
  }
  return result;
}



int MakeSurface_Generic(char *a1, int a2, int a3)
{
  int result; 
  HMODULE v4; 
  size_t v5; 
  signed int fuLoad; 
  CHAR name; 
  char pv; 
  int wSrc; 
  int hSrc; 
  char *v11; 
  HANDLE h; 

  if ( a2 < 64 )
  {
    if ( surfaceTbl_[5 * a2] )
    {
      v11 = (char *)&surfaceTbl2_ + 20 * a2;
      if ( a3 )
      {
        if ( a1[1] == 58 )
          strcpy(&name, a1);
        else
          sprintf(&name, "%s\\%s", DataPathFull, a1);
        fuLoad = 8208;
      }
      else
      {
        strcpy(&name, a1);
        fuLoad = 0x2000;
      }
      v4 = GetModuleHandleA(0);
      h = LoadImageA(v4, &name, 0, 0, 0, fuLoad);
      if ( h )
      {
        GetObjectA(h, 24, &pv);
        PreparePximg(*((_DWORD *)v11 + 2), h, wSrc, hSrc);
        DeleteObject(h);
        ReleaseSurface((void **)v11 + 1);
        v5 = strlen(a1);
        if ( !AllocSurface((int)(v11 + 4), v5 + 1) )
          ClearSurface(a2);
        strcpy(*((char **)v11 + 1), a1);
        if ( a3 )
          *(_DWORD *)v11 |= 1u;
        else
          *(_DWORD *)v11 &= 0xFFFFFFFE;
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
  }
  else
  {
    result = 0;
  }
  return result;
}



RECT *MagnifyRect(RECT *a1)
{
  RECT *result; 

  a1->left *= magnification;
  a1->right *= magnification;
  a1->top *= magnification;
  result = a1;
  a1->bottom *= magnification;
  return result;
}


int PutRect(int x, int y, RECT *rect, signed int surf_no)
{
  int result; 
  LONG v5; 
  LONG v6; 
  LONG v7; 
  LONG v8; 
  int v9; 
  int v10; 
  LONG v11; 
  LONG v12; 

  if ( surf_no < 64 )
  {
    result = 20 * surf_no;
    if ( surfaceTbl_[5 * surf_no] )
    {
      v5 = rect->left;
      v6 = rect->top;
      v7 = rect->right;
      v8 = rect->bottom;
      v9 = x;
      v11 = rect->right + x - rect->left;
      v10 = y;
      v12 = rect->bottom + y - rect->top;
      MagnifyRect((RECT *)&v5);
      MagnifyRect((RECT *)&v9);
      result = (*(int (__stdcall **)(int, int *, int, int *, signed int, _DWORD))(*(_DWORD *)SurfaceB + 20))(
                 SurfaceB,
                 &v9,
                 surfaceTbl_[5 * surf_no],
                 (int *)&v5,
                 16809984,
                 0);
    }
  }
  return result;
}




int PutBitmapPause_(signed int a1)
{
  int result; 
  int v2; 
  int v3; 
  int v4; 
  int v5; 
  int v6; 

  if ( a1 < 64 )
  {
    result = 20 * a1;
    if ( surfaceTbl_[5 * a1] )
    {
      memset(&v6, 0, 0x64u);
      v6 = 100;
      v2 = 0;
      v4 = MainSurfaceWidth;
      v3 = 0;
      v5 = MainSurfaceHeight;
      MagnifyRect((RECT *)&v2);
      result = (*(int (__stdcall **)(int, int *, int, int *, signed int, int *))(*(_DWORD *)surfaceTbl_[5 * a1] + 20))(
                 surfaceTbl_[5 * a1],
                 &v2,
                 SurfaceB,
                 &v2,
                 0x1000000,
                 &v6);
    }
  }
  return result;
}






int PutBitmap3(RECT *rcView, int x, int y, RECT *rect, signed int surf_no)
{
  int result; 
  RECT rcWork; 
  RECT rcSet; 

  if ( surf_no < 64 )
  {
    result = 20 * surf_no;
    if ( surfaceTbl_[5 * surf_no] )
    {
      rcWork.left = rect->left;
      rcWork.top = rect->top;
      rcWork.right = rect->right;
      rcWork.bottom = rect->bottom;
      if ( rect->right + x - rect->left > rcView->right )
        rcWork.right -= rect->right + x - rect->left - rcView->right;
      if ( x < rcView->left )
      {
        rcWork.left += rcView->left - x;
        x = rcView->left;
      }
      if ( rect->bottom + y - rect->top > rcView->bottom )
        rcWork.bottom -= rect->bottom + y - rect->top - rcView->bottom;
      if ( y < rcView->top )
      {
        rcWork.top += rcView->top - y;
        y = rcView->top;
      }
      rcSet.left = x;
      rcSet.top = y;
      rcSet.right = rcWork.right + x - rcWork.left;
      rcSet.bottom = rcWork.bottom + y - rcWork.top;
      MagnifyRect(&rcWork);
      MagnifyRect(&rcSet);
      result = (*(int (__stdcall **)(int, RECT *, int, RECT *, signed int, _DWORD))(*(_DWORD *)SurfaceB + 20))(
                 SurfaceB,
                 &rcSet,
                 surfaceTbl_[5 * surf_no],
                 &rcWork,
                 16809984,
                 0);
    }
  }
  return result;
}




int PutNumber2_(int a1, int a2, int a3, signed int a4, signed int a5)
{
  int result; 
  int v6; 
  int v7; 
  int v8; 
  int v9; 
  int v10; 
  int v11; 
  int v12; 
  int v13; 

  if ( a4 < 64 && a5 < 64 )
  {
    result = 20 * a4;
    if ( surfaceTbl_[5 * a4] )
    {
      if ( surfaceTbl_[5 * a5] )
      {
        v6 = *(_DWORD *)a3;
        v7 = *(_DWORD *)(a3 + 4);
        v8 = *(_DWORD *)(a3 + 8);
        v9 = *(_DWORD *)(a3 + 12);
        v10 = a1;
        v11 = a2;
        v12 = *(_DWORD *)(a3 + 8) + a1 - *(_DWORD *)a3;
        v13 = *(_DWORD *)(a3 + 12) + a2 - *(_DWORD *)(a3 + 4);
        MagnifyRect((RECT *)&v6);
        MagnifyRect((RECT *)&v10);
        result = (*(int (__stdcall **)(int, int *, int, int *, signed int, _DWORD))(*(_DWORD *)surfaceTbl_[5 * a4] + 20))(
                   surfaceTbl_[5 * a4],
                   &v10,
                   surfaceTbl_[5 * a5],
                   &v6,
                   16809984,
                   0);
      }
    }
  }
  return result;
}



int PutBackground(int a1, int a2)
{
  int v3; 
  int v4; 
  int v5; 
  int v6; 
  int v7; 
  int v8; 

  memset(&v7, 0, 0x64u);
  v7 = 100;
  v8 = a2;
  v3 = *(_DWORD *)a1;
  v4 = *(_DWORD *)(a1 + 4);
  v5 = *(_DWORD *)(a1 + 8);
  v6 = *(_DWORD *)(a1 + 12);
  MagnifyRect((RECT *)&v3);
  return (*(int (__stdcall **)(int, int *, _DWORD, _DWORD, signed int, int *))(*(_DWORD *)SurfaceB + 20))(
           SurfaceB,
           &v3,
           0,
           0,
           16778240,
           &v7);
}



int Unused2(int a1, int a2, int a3)
{
  int v4; 
  int v5; 
  int v6; 
  int v7; 
  int v8; 
  int v9; 
  int v10; 
  int v11; 
  int v12; 
  int v13; 

  memset(&v8, 0, 0x64u);
  v8 = 100;
  v9 = a3;
  v10 = *(_DWORD *)a2;
  v11 = *(_DWORD *)(a2 + 4);
  v12 = *(_DWORD *)(a2 + 8);
  v13 = *(_DWORD *)(a2 + 12);
  if ( v10 < *(_DWORD *)a1 )
    v10 = *(_DWORD *)a1;
  if ( v11 < *(_DWORD *)(a1 + 4) )
    v11 = *(_DWORD *)(a1 + 4);
  if ( v12 > *(_DWORD *)(a1 + 8) )
    v12 = *(_DWORD *)(a1 + 8);
  if ( v13 > *(_DWORD *)(a1 + 12) )
    v13 = *(_DWORD *)(a1 + 12);
  v4 = v10;
  v5 = v11;
  v7 = v13;
  v6 = v10 + 1;
  MagnifyRect((RECT *)&v4);
  (*(void (__stdcall **)(int, int *, _DWORD, _DWORD, signed int, int *))(*(_DWORD *)SurfaceB + 20))(
    SurfaceB,
    &v4,
    0,
    0,
    16778240,
    &v8);
  v4 = v10;
  v5 = v11;
  v6 = v12;
  v7 = v11 + 1;
  MagnifyRect((RECT *)&v4);
  (*(void (__stdcall **)(int, int *, _DWORD, _DWORD, signed int, int *))(*(_DWORD *)SurfaceB + 20))(
    SurfaceB,
    &v4,
    0,
    0,
    16778240,
    &v8);
  v5 = v11;
  v6 = v12;
  v7 = v13;
  v4 = v12 - 1;
  MagnifyRect((RECT *)&v4);
  (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)SurfaceB + 20))(
    SurfaceB,
    &v4,
    0,
    0,
    16778240,
    &v8);
  v4 = v10;
  v6 = v12;
  v7 = v13;
  v5 = v13 - 1;
  MagnifyRect((RECT *)&v4);
  return (*(int (__stdcall **)(int, int *, _DWORD, _DWORD, signed int, int *))(*(_DWORD *)SurfaceB + 20))(
           SurfaceB,
           &v4,
           0,
           0,
           16778240,
           &v8);
}



int RenderToSurface_(int a1, int a2, signed int a3)
{
  int result; 
  int v4; 
  int v5; 
  int v6; 
  int v7; 
  int v8; 
  int v9; 

  if ( a3 < 64 )
  {
    result = 20 * a3;
    if ( surfaceTbl_[5 * a3] )
    {
      memset(&v8, 0, 0x64u);
      v8 = 100;
      v9 = a2;
      if ( a1 )
      {
        v4 = *(_DWORD *)a1;
        v5 = *(_DWORD *)(a1 + 4);
        v6 = *(_DWORD *)(a1 + 8);
        v7 = *(_DWORD *)(a1 + 12);
      }
      else
      {
        v4 = 0;
        v6 = dword_44CE3C[5 * a3];
        v5 = 0;
        v7 = dword_44CE40[5 * a3];
      }
      MagnifyRect((RECT *)&v4);
      result = (*(int (__stdcall **)(int, int *, _DWORD, _DWORD, signed int, int *))(*(_DWORD *)surfaceTbl_[5 * a3] + 20))(
                 surfaceTbl_[5 * a3],
                 &v4,
                 0,
                 0,
                 16778240,
                 &v8);
    }
  }
  return result;
}





int sub_424150(int a1, int a2, int a3)
{
  int v4; 
  int v5; 
  int v6; 
  int v7; 
  int v8; 
  int v9; 

  memset(&v8, 0, 0x64u);
  v8 = 100;
  v9 = a3;
  v4 = *(_DWORD *)a2;
  v5 = *(_DWORD *)(a2 + 4);
  v6 = *(_DWORD *)(a2 + 8);
  v7 = *(_DWORD *)(a2 + 12);
  if ( v4 < *(_DWORD *)a1 )
    v4 = *(_DWORD *)a1;
  if ( v5 < *(_DWORD *)(a1 + 4) )
    v5 = *(_DWORD *)(a1 + 4);
  if ( v6 > *(_DWORD *)(a1 + 8) )
    v6 = *(_DWORD *)(a1 + 8);
  if ( v7 > *(_DWORD *)(a1 + 12) )
    v7 = *(_DWORD *)(a1 + 12);
  MagnifyRect((RECT *)&v4);
  return (*(int (__stdcall **)(int, int *, _DWORD, _DWORD, signed int, int *))(*(_DWORD *)SurfaceB + 20))(
           SurfaceB,
           &v4,
           0,
           0,
           16778240,
           &v8);
}



int SetSurfaceColor(COLORREF color)
{
  int result; 
  COLORREF v2; 
  int v3; 
  int *v4; 
  unsigned int v5; 
  HDC hdc; 
  int v7; 

  if ( (*(int (__stdcall **)(int, HDC *))(*(_DWORD *)SurfaceB + 68))(SurfaceB, &hdc) )
  {
    result = -1;
  }
  else
  {
    v2 = GetPixel(hdc, 0, 0);
    SetPixel(hdc, 0, 0, color);
    (*(void (__stdcall **)(int, HDC))(*(_DWORD *)SurfaceB + 104))(SurfaceB, hdc);
    memset(&v3, 0, 0x6Cu);
    v3 = 108;
    if ( (*(int (__stdcall **)(int, _DWORD, int *, signed int, _DWORD))(*(_DWORD *)SurfaceB + 100))(
           SurfaceB,
           0,
           &v3,
           1,
           0) )
    {
      result = -1;
    }
    else
    {
      v7 = *v4;
      if ( v5 < 0x20 )
        v7 &= (1 << v5) - 1;
      (*(void (__stdcall **)(int, _DWORD))(*(_DWORD *)SurfaceB + 128))(SurfaceB, 0);
      if ( (*(int (__stdcall **)(int, HDC *))(*(_DWORD *)SurfaceB + 68))(SurfaceB, &hdc) )
      {
        result = -1;
      }
      else
      {
        SetPixel(hdc, 0, 0, v2);
        (*(void (__stdcall **)(int, HDC))(*(_DWORD *)SurfaceB + 104))(SurfaceB, hdc);
        result = v7;
      }
    }
  }
  return result;
}



signed int GetSurfaceColor(int a1)
{
  signed int result; 
  int v2; 
  int *v3; 
  unsigned int v4; 
  int v5; 

  memset(&v2, 0, 0x6Cu);
  v2 = 108;
  if ( (*(int (__stdcall **)(int, _DWORD, int *, signed int, _DWORD))(*(_DWORD *)surfaceTbl_[5 * a1] + 100))(
         surfaceTbl_[5 * a1],
         0,
         &v2,
         1,
         0) )
  {
    result = -1;
  }
  else
  {
    v5 = *v3;
    if ( v4 < 0x20 )
      v5 &= (1 << v4) - 1;
    (*(void (__stdcall **)(int, _DWORD))(*(_DWORD *)surfaceTbl_[5 * a1] + 128))(surfaceTbl_[5 * a1], 0);
    result = v5;
  }
  return result;
}



HFONT InitFont(LPCSTR pszFaceName, char a2, int cHeight)
{
  HFONT result; 

  result = CreateFontA(cHeight, a2, 0, 0, 400, 0, 0, 0, 1u, 4u, 0, 0, 1u, pszFaceName);
  ho = result;
  return result;
}


BOOL CallDeleteObject()
{
  return DeleteObject(ho);
}


signed int DoNothing2(int a1)
{
  return 1;
}


int sub_4245E0()
{
  int result; 
  signed int i; 
  char v2; 
  int v3; 
  char *v4; 
  int v5; 
  int v6; 
  int v7; 
  int v8; 

  v3 = 0;
  v5 = 0;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  if ( SurfaceA )
  {
    if ( SurfaceB )
    {
      if ( (*(int (__stdcall **)(int))(*(_DWORD *)SurfaceA + 96))(SurfaceA) == -2005532222 )
      {
        ++v3;
        (*(void (__stdcall **)(int))(*(_DWORD *)SurfaceA + 108))(SurfaceA);
        DoNothing2(102);
      }
      if ( (*(int (__stdcall **)(int))(*(_DWORD *)SurfaceB + 96))(SurfaceB) == -2005532222 )
      {
        ++v3;
        (*(void (__stdcall **)(int))(*(_DWORD *)SurfaceB + 108))(SurfaceB);
        DoNothing2(98);
      }
      for ( i = 0; i < 64; ++i )
      {
        if ( surfaceTbl_[5 * i] )
        {
          v4 = (char *)&surfaceTbl2_ + 20 * i;
          if ( (*(int (__stdcall **)(_DWORD))(**((_DWORD **)&surfaceTbl2_ + 5 * i + 2) + 96))(*((_DWORD *)&surfaceTbl2_
                                                                                              + 5 * i
                                                                                              + 2)) == -2005532222 )
          {
            ++v3;
            (*(void (__stdcall **)(_DWORD))(**((_DWORD **)v4 + 2) + 108))(*((_DWORD *)v4 + 2));
            DoNothing2(i + 48);
            if ( !(*(_DWORD *)v4 & 2) )
            {
              if ( *((_DWORD *)v4 + 1) )
              {
                strcpy(&v2, *((const char **)v4 + 1));
                MakeSurface_Generic(&v2, i, (*(_DWORD *)v4 & 1) != 0);
              }
              else
              {
                v7 = *((_DWORD *)v4 + 3);
                v8 = *((_DWORD *)v4 + 4);
                RenderToSurface_((int)&v5, 0, i);
              }
            }
          }
        }
      }
      result = v3;
    }
    else
    {
      result = v3;
    }
  }
  else
  {
    result = v3;
  }
  return result;
}





signed int ResetSurfaceTbl(int a1, int a2)
{
  signed int result; 
  int v3; 
  char v4; 
  int v5; 
  int v6; 
  int i; 
  char *v8; 

  if ( magnification == a2 )
  {
    result = 1;
  }
  else
  {
    v6 = magnification;
    ReleaseSurfaceA();
    InitMainSurface(a1, MainSurfaceWidth, MainSurfaceHeight, a2);
    for ( i = 0; i < 64; ++i )
    {
      if ( surfaceTbl_[5 * i] )
      {
        v8 = (char *)&surfaceTbl2_ + 20 * i;
        (*(void (__stdcall **)(_DWORD))(**((_DWORD **)&surfaceTbl2_ + 5 * i + 2) + 8))(*((_DWORD *)&surfaceTbl2_
                                                                                       + 5 * i
                                                                                       + 2));
        *((_DWORD *)v8 + 2) = 0;
        unusedDDrawmath -= v6 * *((_DWORD *)v8 + 4) * v6 * *((_DWORD *)v8 + 3);
        v3 = (*(_DWORD *)v8 & 1) != 0;
        v5 = (*(_DWORD *)v8 & 2) != 0;
        if ( *((_DWORD *)v8 + 1) )
        {
          strcpy(&v4, *((const char **)v8 + 1));
          InitSurface_(*((_DWORD *)v8 + 3), *((_DWORD *)v8 + 4), i, v5);
          MakeSurface_Generic(&v4, i, v3);
        }
        else
        {
          InitSurface_(*((_DWORD *)v8 + 3), *((_DWORD *)v8 + 4), i, v5);
        }
      }
    }
    result = 1;
  }
  return result;
}


