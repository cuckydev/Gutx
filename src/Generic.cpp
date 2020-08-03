




int GetCompileVersion(_DWORD *a1, _DWORD *a2, _DWORD *a3, _DWORD *a4)
{
  unsigned int puLen; 
  CHAR Filename; 
  LPVOID lpBuffer; 
  DWORD dwHandle; 
  DWORD dwLen; 
  int v10; 
  int v11; 
  int v12; 
  int v13; 
  LPVOID lpData; 

  lpData = 0;
  memset(&v10, 0, 0x10u);
  if ( a1 )
    *a1 = 0;
  if ( a2 )
    *a2 = 0;
  if ( a3 )
    *a3 = 0;
  if ( a4 )
    *a4 = 0;
  GetModuleFileNameA(0, &Filename, 0x104u);
  dwLen = GetFileVersionInfoSizeA(&Filename, &dwHandle);
  if ( dwLen )
  {
    lpData = malloc(dwLen);
    if ( lpData )
    {
      if ( GetFileVersionInfoA(&Filename, 0, dwLen, lpData) && VerQueryValueA(lpData, "\\", &lpBuffer, &puLen) )
      {
        v10 = (unsigned __int16)(*((_DWORD *)lpBuffer + 2) >> 16);
        v11 = (unsigned __int16)*((_DWORD *)lpBuffer + 2);
        v12 = (unsigned __int16)(*((_DWORD *)lpBuffer + 3) >> 16);
        v13 = *((_WORD *)lpBuffer + 6);
        if ( a1 )
          *a1 = v10;
        if ( a2 )
          *a2 = v11;
        if ( a3 )
          *a3 = v12;
        if ( a4 )
          *a4 = v13;
      }
    }
  }
  if ( lpData )
    free(lpData);
  return 10 * v12 + v13 + 100 * v11 + 1000 * v10;
}


int MenuLoop()
{
  char *v0; 
  int v2; 
  int v3; 
  int v4; 
  int v5; 
  int v6; 
  int v7; 
  int v8; 
  int v9; 
  int v10; 
  unsigned __int8 v11; 
  int v12; 
  int v13; 
  int v14; 
  int v15; 
  int v16; 
  int v17; 
  int v18; 
  int v19; 
  int v20; 
  int v21; 
  int v22; 
  int v23; 
  int v24; 
  int v25; 
  int v26; 
  int v27; 
  int v28; 
  int v29; 
  int v30; 
  int v31; 
  int v32; 
  int v33; 
  int v34; 
  int v35; 
  int v36; 
  int v37; 
  int v38; 
  int v39; 
  int v40; 
  int v41; 
  int v42; 
  int v43; 
  int v44; 
  int v45; 
  int v46; 
  int v47; 
  int v48; 
  int curSel; 
  char v50; 
  int v51; 
  int v52; 
  int v53; 
  int v54; 

  v11 = 0;
  curSel = 0;
  v31 = 1;
  v22 = 0;
  v51 = 0;
  v52 = 88;
  v53 = 64;
  v54 = 96;
  v23 = 64;
  v24 = 56;
  v25 = 112;
  v26 = 64;
  v27 = 35;
  v28 = 8;
  v29 = 80;
  v30 = 16;
  v12 = 0;
  v13 = 96;
  v14 = 80;
  v15 = 104;
  v16 = 0;
  v17 = 104;
  v18 = 80;
  v19 = 112;
  v32 = 0;
  v33 = 0;
  v34 = 64;
  v35 = 8;
  v45 = 0;
  v46 = 0;
  v47 = 120;
  v48 = 32;
  v7 = 0;
  v8 = 32;
  v9 = 120;
  v10 = 40;
  v36 = 112;
  v37 = 0;
  v38 = 120;
  v39 = 8;
  v40 = 120;
  v41 = 0;
  v42 = 128;
  v43 = 8;
  GetCompileVersion(&v5, &v3, &v6, &v4);
  sprintf(&v50, "v.%d.%d%d%d", v5, v3, v6, v4);
  v44 = GetSurfaceColor(17);
  SetSoundDisabled(0);
  ResetScore();
  SetReset(0);
  LoadButtonConfig();
  ClearTrg_((int)&v20);
  if ( GetGameCleared() )
  {
    curSel = 1;
    v22 = 1;
  }
  LoadPximg((int)"title", 21);
  ChangeMusic(1);
  InitDragFile();
  while ( 1 )
  {
    if ( Call_Escape() )
    {
      v31 = 0;
      goto LABEL_39;
    }
    if ( GetGameReset() )
    {
      v31 = 1;
      goto LABEL_39;
    }
    v20 = GetTrg();
    UpdateTrg((int)&v20);
    if ( v21 & 1 )
    {
      switch ( curSel )
      {
        case 0:
          SetInScoreAttack(0);
          SetInReplay(0);
          v31 = 2;
          PlaySound(33);
          break;
        case 1:
          if ( v22 )
          {
            SetInScoreAttack(1);
            SetInReplay(0);
            v31 = 2;
            PlaySound(33);
          }
          else
          {
            PlaySound(19);
          }
          break;
        case 2:
          if ( v22 )
          {
            v31 = 4;
            PlaySound(33);
          }
          else
          {
            PlaySound(19);
          }
          break;
        case 3:
          if ( GetKeyHeld() )
            v31 = 5;
          else
            v31 = 6;
          PlaySound(33);
          break;
        default:
          break;
      }
      if ( v31 != 1 )
        break;
    }
    if ( CheckDragFile() )
    {
      v0 = GetDragFile();
      if ( ReadPlayRecord(v0, (int)&v2) )
      {
        SetInScoreAttack(v2);
        SetInReplay(1);
        v31 = 2;
        break;
      }
    }
    if ( v21 & 0x80 )
    {
      ++curSel;
      PlaySound(2);
    }
    if ( v21 & 0x40 )
    {
      --curSel;
      PlaySound(2);
    }
    if ( curSel < 0 )
      curSel = 3;
    if ( curSel > 3 )
      curSel = 0;
    ++v11;
    PutBackground((int)&scWOffset_0, v44);
    PutRect(0, 24, (RECT *)&v45, 21);
    PutRect(0, 144, (RECT *)&v7, 21);
    PutRect(28, 88, (RECT *)&v51, 11);
    PutRect(28, 100, (RECT *)&v12 + v22, 11);
    PutRect(28, 112, (RECT *)&v23 + v22, 11);
    PutRect(28, 124, (RECT *)&v32, 11);
    PutRect(16, 12 * curSel + 88, (RECT *)&v36 + ((signed int)v11 >> 3) % 2, 11);
    PutTextObject((int)&scWOffset_0, 60, 64, &v50, 16, 0);
    PutFramePerSecond();
    if ( !Flip_SystemTask() )
    {
      v31 = 0;
      goto LABEL_39;
    }
  }
  Sleep(0x1F4u);
LABEL_39:
  InitDragFile();
  return v31;
}



signed int message()
{
  struct tagMSG Msg; 

  while ( PeekMessageA(&Msg, 0, 0, 0, 0) || !GameFocussed )
  {
    if ( !GetMessageA(&Msg, 0, 0, 0) )
      return 0;
    TranslateMessage(&Msg);
    DispatchMessageA(&Msg);
  }
  return 1;
}



int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
  int result; 
  int v5; 
  __int64 v6; 
  signed __int64 v7; 
  DWORD v8; 
  char v9; 
  CHAR WindowName; 

  InitMutex((int)&v9);
  dword_44C6E4 = (int)hInstance;
  if ( StartMutex((int)&v9, lpName, mutexName) )
  {
    InitCommonControls();
    ResetInput();
    GetModuleFileNameA(0, pszPath, 0x104u);
    PathRemoveFileSpecA(pszPath);
    sprintf_((int)temp_guxtPath, "%s\\temp_guxt", pszPath);
    sprintf_((int)dataPath, "%s\\data", pszPath);
    CreateDirectoryA(temp_guxtPath, 0);
    SetPtrTempGuxt((int)temp_guxtPath);
    SetUnusedPtrTempGuxt((int)temp_guxtPath);
    if ( SetWindowAttr(hInstance, (int)lpClassName, (int)menu) )
    {
      hMenu = LoadMenuA(hInstance, "MENU_MAIN");
      sprintf(&WindowName, "%s", windowName[0]);
      hWnd = CreateWindowExA(0, lpClassName, &WindowName, 0x800A0000, 2147483648, 2147483648, 0, 0, 0, 0, hInstance, 0);
      if ( StartMutex2((int)&v9, lpName, mutexName, (int)hWnd) )
      {
        InitMenuItem(hWnd);
        ReadMainScreenMode();
        if ( InitDirectDraw((int)hWnd, dataPath, fullscreenEnabled, 1) )
        {
          if ( InitMainSurface((int)hWnd, 120, 160, screenSize) )
          {
            SetRenderOffset(0, 0);
            InitFont(0, 6, 12);
            SetScreenMode(0, 1);
            if ( !fullscreenEnabled && !SetWindowPosRect(hWnd, mainrectFile, 0) )
              SetFullscreenWindowPos(hWnd);
            v8 = GetTickCount();
            DrawStudioPixel();
            InitDirectInput(hInstance, (int)hWnd);
            sub_422AF0();
            pxtone_Ready(hWnd, 2, 44100, 16, 1036831949, 1, 0);
            v5 = pxtone_GetDirectSound();
            AssignDirectSound(v5);
            pxtnPulse_Frequency::Init();
            if ( LoadGenericData() )
            {
              do
              {
                v7 = GetTickCount();
                v6 = v8;
              }
              while ( (double)v8 + 500.0 > (double)v7 );
              Game(hWnd);
            }
            pxtone_Tune_Stop(v6, HIDWORD(v6), v7, HIDWORD(v7));
            pxtone_Release();
            ReleaseDirectInput();
            CallDeleteObject();
            EndDirectDraw((int)hWnd);
            DestroyWindow(hWnd);
            DestroyMenu(hMenu);
            CloseMutex((int)&v9);
            result = 1;
          }
          else
          {
            MessageBoxA(0, "main surface", "error", 0);
            CloseMutex((int)&v9);
            result = 0;
          }
        }
        else
        {
          MessageBoxA(0, "dxdraw", "error", 0);
          CloseMutex((int)&v9);
          result = 0;
        }
      }
      else
      {
        CloseMutex((int)&v9);
        result = 0;
      }
    }
    else
    {
      CloseMutex((int)&v9);
      result = 0;
    }
  }
  else
  {
    CloseMutex((int)&v9);
    result = 0;
  }
  return result;
}









int ReadMainScreenMode()
{
  char v1; 
  int v2; 
  FILE *v3; 

  v2 = 0;
  v3 = 0;
  sprintf(&v1, "%s\\%s", temp_guxtPath, mainscreemodeFile[0]);
  v3 = fopen(&v1, "rb");
  if ( v3 )
  {
    if ( ReadFromFile(&screenSize, 4u, 1u, v3) != 1 || ReadFromFile(&fullscreenEnabled, 4u, 1u, v3) != 1 )
      goto LABEL_12;
    fclose(v3);
  }
  if ( screenSize != 1 && screenSize != 2 && screenSize != 3 && screenSize != 4 && screenSize != 5 )
    screenSize = 2;
  v2 = 1;
LABEL_12:
  if ( !v2 )
  {
    screenSize = 2;
    fullscreenEnabled = 0;
  }
  return v2;
}




signed int DrawStudioPixel()
{
  int *v0; 
  int v2; 
  int v3; 
  int v4; 
  int v5; 
  int v6; 
  int v7; 
  int v8; 
  int v9; 
  int v10; 
  int i; 
  int v12; 
  int v13; 
  int v14; 
  int v15; 
  int v16; 
  int v17; 
  int v18; 
  int v19; 
  int v20; 
  int v21; 
  int v22; 
  int v23; 
  int v24; 
  int v25; 
  int v26; 
  int v27; 
  int v28; 
  int v29; 
  int v30; 
  int v31; 
  int v32; 
  int v33; 
  int v34; 
  int v35; 
  int v36; 
  int v37; 
  int v38; 
  int v39; 
  int v40; 
  int v41; 
  int v42; 
  int v43; 
  int v44; 
  int v45; 
  int v46; 
  int v47; 
  int v48; 
  int v49; 
  int v50; 
  int v51; 
  int v52; 
  int v53; 
  int v54; 
  int v55; 
  int v56; 
  int v57; 
  int v58; 
  int v59; 
  int v60; 
  int v61; 
  int v62; 
  int v63; 
  int v64; 
  int v65; 
  int v66; 
  int v67; 
  int v68; 
  int v69; 
  int v70; 
  int v71; 
  int v72; 
  int v73; 
  int v74; 
  int v75; 
  int v76; 
  int v77; 
  int v78; 
  int v79; 
  int v80; 
  int v81; 
  int v82; 
  int v83; 
  int v84; 
  int v85; 
  int v86; 
  int v87; 
  int v88; 
  int v89; 
  int v90; 
  int v91; 
  int v92; 
  int v93; 
  int v94; 
  int v95; 
  int v96; 
  int v97; 
  int v98; 
  int v99; 
  int v100; 
  int v101; 
  int v102; 
  int v103; 
  int v104; 
  int v105; 
  int v106; 
  int v107; 
  int v108; 
  int v109; 
  int v110; 
  int v111; 
  int v112; 
  int v113; 
  int v114; 
  int v115; 
  int v116; 
  int v117; 
  int v118; 
  int v119; 
  int v120; 
  int v121; 
  int v122; 
  int v123; 
  int v124; 
  int v125; 
  int v126; 
  int v127; 
  int v128; 
  int v129; 
  int v130; 
  int v131; 
  int v132; 
  int v133; 
  int v134; 
  int v135; 
  int v136; 
  int v137; 
  int v138; 
  int v139; 
  int v140; 
  int v141; 
  int v142; 
  int v143; 
  int v144; 
  int v145; 
  int v146; 
  int v147; 
  int v148; 
  int v149; 
  int v150; 
  int v151; 
  int v152; 
  int v153; 
  int v154; 
  int v155; 
  int v156; 
  int v157; 
  int v158; 
  int v159; 
  int v160; 
  int v161; 
  int v162; 
  int v163; 
  int v164; 
  int v165; 
  int v166; 
  int v167; 
  int v168; 
  int v169; 

  v6 = 0;
  v7 = 0;
  v8 = 128;
  v9 = 16;
  v13 = 28;
  v14 = 3;
  v15 = 29;
  v16 = 14;
  v17 = 29;
  v18 = 3;
  v19 = 33;
  v20 = 7;
  v21 = 34;
  v22 = 3;
  v23 = 38;
  v24 = 7;
  v25 = 38;
  v26 = 3;
  v27 = 39;
  v28 = 14;
  v29 = 31;
  v30 = 8;
  v31 = 33;
  v32 = 14;
  v33 = 34;
  v34 = 8;
  v35 = 36;
  v36 = 14;
  v37 = 30;
  v38 = 9;
  v39 = 37;
  v40 = 12;
  v41 = 42;
  v42 = 3;
  v43 = 47;
  v44 = 4;
  v45 = 48;
  v46 = 3;
  v47 = 53;
  v48 = 4;
  v49 = 42;
  v50 = 4;
  v51 = 46;
  v52 = 6;
  v53 = 49;
  v54 = 4;
  v55 = 53;
  v56 = 6;
  v57 = 42;
  v58 = 6;
  v59 = 43;
  v60 = 8;
  v61 = 52;
  v62 = 6;
  v63 = 53;
  v64 = 8;
  v65 = 44;
  v66 = 8;
  v67 = 51;
  v68 = 11;
  v69 = 42;
  v70 = 11;
  v71 = 47;
  v72 = 14;
  v73 = 48;
  v74 = 11;
  v75 = 53;
  v76 = 14;
  v77 = 60;
  v78 = 3;
  v79 = 63;
  v80 = 4;
  v81 = 56;
  v82 = 4;
  v83 = 67;
  v84 = 5;
  v85 = 56;
  v86 = 5;
  v87 = 58;
  v88 = 7;
  v89 = 65;
  v90 = 5;
  v91 = 67;
  v92 = 7;
  v93 = 56;
  v94 = 8;
  v95 = 59;
  v96 = 10;
  v97 = 59;
  v98 = 6;
  v99 = 64;
  v100 = 9;
  v101 = 64;
  v102 = 8;
  v103 = 67;
  v104 = 10;
  v105 = 60;
  v106 = 9;
  v107 = 63;
  v108 = 13;
  v109 = 59;
  v110 = 11;
  v111 = 64;
  v112 = 12;
  v113 = 56;
  v114 = 13;
  v115 = 67;
  v116 = 14;
  v117 = 70;
  v118 = 3;
  v119 = 79;
  v120 = 10;
  v121 = 70;
  v122 = 10;
  v123 = 73;
  v124 = 14;
  v125 = 80;
  v126 = 7;
  v127 = 83;
  v128 = 9;
  v129 = 80;
  v130 = 10;
  v131 = 83;
  v132 = 14;
  v133 = 84;
  v134 = 7;
  v135 = 87;
  v136 = 10;
  v137 = 88;
  v138 = 7;
  v139 = 91;
  v140 = 10;
  v141 = 86;
  v142 = 9;
  v143 = 89;
  v144 = 12;
  v145 = 84;
  v146 = 11;
  v147 = 87;
  v148 = 14;
  v149 = 88;
  v150 = 11;
  v151 = 91;
  v152 = 14;
  v153 = 92;
  v154 = 7;
  v155 = 98;
  v156 = 11;
  v157 = 92;
  v158 = 11;
  v159 = 93;
  v160 = 12;
  v161 = 92;
  v162 = 12;
  v163 = 98;
  v164 = 14;
  v165 = 99;
  v166 = 3;
  v167 = 102;
  v168 = 14;
  v169 = SetSurfaceColor(0);
  v12 = SetSurfaceColor(0xF0F0F0u);
  v10 = SetSurfaceColor(0xF00000u);
  InitSurface_(128, 16, 3, 0);
  PutBackground((int)&scWOffset_0, v169);
  RenderToSurface_((int)&v6, v169, 3);
  for ( i = 0; i < 39; ++i )
  {
    v0 = &v13 + 4 * i;
    v2 = *v0;
    v3 = v0[1];
    v4 = v0[2];
    v5 = v0[3];
    --v2;
    ++v4;
    RenderToSurface_((int)&v2, v10, 3);
  }
  for ( i = 0; i < 39; ++i )
    RenderToSurface_((int)(&v13 + 4 * i), v12, 3);
  PutBitmap3((RECT *)&scWOffset_0, ScreenRenderWidth / 2 - 64, ScreenRenderHeight / 2 - 8, (RECT *)&v6, 3);
  return Flip_Screen();
}





BOOL SetWindowAttr(HINSTANCE hInstance, int a2, int a3)
{
  WNDCLASSEXA v4; 

  memset(&v4, 0, 0x30u);
  v4.cbSize = 48;
  v4.lpszClassName = (LPCSTR)a2;
  v4.style = 3;
  v4.lpfnWndProc = (WNDPROC)a3;
  v4.hInstance = hInstance;
  v4.hbrBackground = (HBRUSH)GetStockObject(4);
  v4.hIcon = LoadIconA(hInstance, "0");
  v4.hCursor = LoadCursorA(0, (LPCSTR)0x7F00);
  return RegisterClassExA(&v4) != 0;
}


int SetScreenMode(__int16 a1, int a2)
{
  int result; 
  struct tagRECT Rect; 
  int v4; 
  int v5; 

  v4 = screenSize;
  v5 = fullscreenEnabled;
  switch ( a1 )
  {
    case 0x9C46:
      v4 = 1;
      break;
    case 0x9C47:
      v4 = 2;
      break;
    case 0x9C48:
      v4 = 3;
      break;
    case 0x9C4E:
      v4 = 4;
      break;
    case 0x9C4F:
      v4 = 5;
      break;
    case 0x9C54:
      v5 = fullscreenEnabled == 0;
      break;
    default:
      break;
  }
  if ( a2 || v4 != screenSize )
  {
    result = ResetSurfaceTbl((int)hWnd, v4);
    if ( !result )
      return result;
    unknown_libname_4();
  }
  if ( a2 || v5 != fullscreenEnabled )
  {
    if ( v5 )
    {
      result = SetCooperativeMode(1);
      if ( !result )
        return result;
    }
    else
    {
      result = SetCooperativeMode(0);
      if ( !result )
        return result;
    }
  }
  CheckMenuItem(hMenu, 0x9C46u, 0);
  CheckMenuItem(hMenu, 0x9C47u, 0);
  CheckMenuItem(hMenu, 0x9C48u, 0);
  CheckMenuItem(hMenu, 0x9C4Eu, 0);
  CheckMenuItem(hMenu, 0x9C4Fu, 0);
  switch ( v4 )
  {
    case 1:
      CheckMenuItem(hMenu, 0x9C46u, 8u);
      break;
    case 2:
      CheckMenuItem(hMenu, 0x9C47u, 8u);
      break;
    case 3:
      CheckMenuItem(hMenu, 0x9C48u, 8u);
      break;
    case 4:
      CheckMenuItem(hMenu, 0x9C4Eu, 8u);
      break;
    case 5:
      CheckMenuItem(hMenu, 0x9C4Fu, 8u);
      break;
    default:
      break;
  }
  if ( v5 )
    CheckMenuItem(hMenu, 0x9C54u, 8u);
  else
    CheckMenuItem(hMenu, 0x9C54u, 0);
  if ( v5 )
  {
    SetFullscreenRenderPos();
    GetWindowRect(hWnd, &Rect);
    result = RedrawWindow(hWnd, &Rect, 0, 5u);
  }
  else
  {
    result = SetWindowPos(hWnd, 0, 0, 0, 120 * v4, 160 * v4, 2u);
    if ( fullscreenEnabled )
      result = SetFullscreenWindowPos(hWnd);
  }
  screenSize = v4;
  fullscreenEnabled = v5;
  return result;
}



int __stdcall menu(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  int v4; 
  int v5; 
  HMENU v6; 
  int result; 
  HIMC v8; 
  struct tagPOINT Point; 

  if ( Msg > 0x112 )
  {
    switch ( Msg )
    {
      case 0x201u:
        if ( !fullscreenEnabled )
          PostMessageA(hWnd, 0xA1u, 2u, lParam);
        return 0;
      case 0x204u:
        Point.x = (unsigned __int16)lParam;
        Point.y = HIWORD(lParam);
        ClientToScreen(hWnd, &Point);
        v4 = Point.y;
        v5 = Point.x;
        v6 = GetSubMenu(hMenu, 0);
        TrackPopupMenu(v6, 0, v5, v4, 0, hWnd, 0);
        return 0;
      case 0x233u:
        DragFileProc((int)hWnd, (HDROP)wParam);
        SetForegroundWindow(hWnd);
        return 0;
      case 0x282u:
        if ( wParam == 8 )
        {
          v8 = ImmGetContext(hWnd);
          ImmSetOpenStatus(v8, 0);
          ImmReleaseContext(hWnd, v8);
        }
        return 0;
      default:
        return DefWindowProcA(hWnd, Msg, wParam, lParam);
    }
    return DefWindowProcA(hWnd, Msg, wParam, lParam);
  }
  if ( Msg == 274 )
  {
    if ( wParam != 61696 && wParam != 61760 && wParam != 61808 )
      DefWindowProcA(hWnd, Msg, wParam, lParam);
    return 0;
  }
  if ( Msg <= 0x10 )
  {
    if ( Msg == 16 )
    {
      PostQuitMessage(0);
    }
    else if ( Msg == 1 )
    {
      GameFocussed = 1;
    }
    else
    {
      if ( Msg != 5 )
        return DefWindowProcA(hWnd, Msg, wParam, lParam);
      if ( wParam )
      {
        if ( wParam == 1 )
          MinimizeGame();
      }
      else
      {
        RestoreGame();
      }
    }
    return 0;
  }
  if ( Msg < 0x100 )
    return DefWindowProcA(hWnd, Msg, wParam, lParam);
  if ( Msg <= 0x101 )
  {
    OutputDebugStringA("kk\n");
    KeyCapture_(hWnd, Msg, wParam);
    return 0;
  }
  if ( Msg != 273 )
    return DefWindowProcA(hWnd, Msg, wParam, lParam);
  switch ( (unsigned __int16)wParam )
  {
    case 0x9C4Bu:
      SetReset(1);
      return 0;
    case 0x9C42u:
      SendMessageA(hWnd, 0x10u, 0, 0);
      return 0;
    case 0x9C46u:
    case 0x9C47u:
    case 0x9C48u:
    case 0x9C4Eu:
    case 0x9C4Fu:
    case 0x9C54u:
      SetScreenMode(wParam, 0);
      return 0;
    case 0x9C50u:
      ShowWindow(hWnd, 6);
      return 0;
    case 0x9C52u:
      OpenSoundVolume(hWnd);
      return 0;
    default:
      result = DefWindowProcA(hWnd, Msg, wParam, lParam);
      break;
  }
  return result;
}



int MinimizeGame()
{
  int result; 

  if ( GameFocussed )
  {
    GameFocussed = 0;
    FadeMusic();
    result = PauseLoopSound();
  }
  return result;
}



void *RestoreGame()
{
  void *result; 

  if ( !GameFocussed )
  {
    SetFocus(hWnd);
    GameFocussed = 1;
    ResumeMusic();
    ResumeLoopSound();
    result = ResetInput();
  }
  return result;
}



BOOL OpenSoundVolume(HWND hwnd)
{
  CHAR Buffer; 
  CHAR File; 
  HINSTANCE v4; 
  HINSTANCE v5; 
  CHAR pszPath; 

  GetSystemDirectoryA(&Buffer, 0x104u);
  sprintf(&File, "%s\\Sndvol32.exe", &Buffer);
  strcpy(&pszPath, &Buffer);
  PathRemoveFileSpecA(&pszPath);
  strcat(&pszPath, "\\Sndvol32.exe");
  v4 = ShellExecuteA(hwnd, "open", &File, 0, 0, 5);
  v5 = ShellExecuteA(hwnd, "open", &pszPath, 0, 0, 5);
  return (signed int)v4 > 32 || (signed int)v5 > 32;
}


UINT InitMenuItem(HWND hWnd)
{
  HMENU v1; 
  UINT result; 
  struct tagMENUITEMINFOA mii; 
  UINT item; 
  HMENU hMenu; 

  v1 = GetSystemMenu(hWnd, 0);
  hMenu = v1;
  result = GetMenuItemCount(v1) - 1;
  for ( item = result; (item & 0x80000000) == 0; --item )
  {
    memset(&mii, 0, 0x30u);
    mii.cbSize = 48;
    mii.fMask = 18;
    result = GetMenuItemInfoA(hMenu, item, 1, &mii);
    if ( result && (mii.wID == 61440 || mii.wID == 61488) )
      result = DeleteMenu(hMenu, item, 0x400u);
  }
  return result;
}


FILE *SaveWindowSettings(HWND hWnd)
{
  SaveWindowRect(hWnd, mainrectFile);
  return WriteScreenMode();
}


FILE *WriteScreenMode()
{
  FILE *result; 
  char v1; 
  FILE *v2; 

  v2 = 0;
  sprintf(&v1, "%s\\%s", temp_guxtPath, mainscreemodeFile[0]);
  result = fopen(&v1, "wb");
  v2 = result;
  if ( result )
  {
    WriteToFile(&screenSize, 4u, 1u, v2);
    WriteToFile(&fullscreenEnabled, 4u, 1u, v2);
    result = (FILE *)fclose(v2);
  }
  return result;
}


