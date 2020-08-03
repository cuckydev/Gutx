
int GameDelay; 

int StageState; 
int centerTextMiscTimer; 
int currentStage; 
int currentMusic; 
int ShipLivesCount; 
int checkpointStageScroll; 
int GameFlags; 
int debugStage; 
int debugStageScroll; 
int debugSpeed; 
int debugPowerup; 
int debugLife; 
int GameReset; 
int Timer1000TicksFinal; 
int Timer1000TicksElapsed; 
int Timer1000Ticks; 
int next_time; 
int current_time; 

int InitGameAttr()
{
  signed int i; 

  memset(&StageState, 0, 0x1Cu);
  for ( i = 1; i < 11; ++i )
  {
    if ( !LoadMusic((int)musicTable[i]) )
      return 0;
  }
  CheckGameCleared();
  return ResetGameSurface_();
}




void *CheckGameCleared()
{
  void *result; 
  char v1; 
  char v2; 
  int v3; 
  FILE *v4; 

  v3 = 0;
  sprintf(&v1, "%s\\%s", temp_guxtPath, clearedFile[0]);
  v4 = fopen(&v1, "rt");
  result = memset(&v2, 0, 0x104u);
  if ( v4 )
  {
    result = (void *)fscanf(v4, "%s\n", &v2);
    if ( result == (void *)1 )
    {
      result = (void *)strcmp(&v2, clearedMentama);
      if ( !result )
        v3 = 1;
    }
  }
  if ( v4 )
    result = (void *)fclose(v4);
  if ( v3 )
  {
    result = (void *)(GameFlags | 4);
    GameFlags |= 4u;
  }
  else
  {
    GameFlags &= 0xFFFFFFFB;
  }
  return result;
}






void CallClearCenterText()
{
  ClearCenterText();
}


int SetInReplay(int a1)
{
  int result; 

  if ( a1 )
  {
    result = GameFlags | 1;
    GameFlags |= 1u;
  }
  else
  {
    GameFlags &= 0xFFFFFFFE;
  }
  return result;
}




int SetInScoreAttack(int a1)
{
  int result; 

  if ( a1 )
  {
    result = GameFlags | 2;
    GameFlags |= 2u;
  }
  else
  {
    GameFlags &= 0xFFFFFFFD;
  }
  return result;
}




int Unused(int a1)
{
  int result; 

  if ( a1 )
  {
    result = GameFlags | 4;
    GameFlags |= 4u;
  }
  else
  {
    GameFlags &= 0xFFFFFFFB;
  }
  return result;
}




BOOL GetInReplay()
{
  return (GameFlags & 1) != 0;
}



BOOL GetInScoreAttack()
{
  return (GameFlags & 2) != 0;
}



BOOL GetGameCleared()
{
  return (GameFlags & 4) != 0;
}



signed int ChangeMusic(int a1)
{
  int v2; 

  v2 = 0;
  if ( (StageState == 30 || StageState == 31) && a1 != 1 )
    return 1;
  if ( a1 )
  {
    if ( a1 != currentMusic && (!LoadMusic((int)musicTable[a1]) || !StartMusic(0)) )
      return v2;
  }
  else
  {
    SetMusicVolume(3000);
  }
  currentMusic = a1;
  return 1;
}





signed int GameStart()
{
  currentStage = 1;
  ShipLivesCount = (GameFlags & 2) == 0;
  FreeCenterText();
  ResetShip();
  return 1;
}





int GetCurrentStage()
{
  return currentStage;
}



int IncreaseLives()
{
  PlaySound(41);
  return ShipLivesCount++ + 1;
}



signed int StartStage()
{
  signed int result; 
  char v1; 

  if ( LoadStage(currentStage) )
  {
    ZeroEntityCount();
    ResetBullet();
    ResetCaret();
    ResetEntities();
    FreeCenterText();
    ResetRandom();
    SetInitialShipValues();
    ResetFade();
    SetGameDelay(0);
    StopLoopSound(32);
    SetDefaultStageScroll();
    SetScrollSpeed(0);
    SetStageXOffset(4096);
    if ( checkpointStageScroll )
    {
      SetStageScroll(checkpointStageScroll);
      SetStageEntitiesPartial();
    }
    StageState = 0;
    centerTextMiscTimer = 0;
    sprintf(&v1, "STAGE %d START!", currentStage);
    PutTextCenter(&v1);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}






signed int InitStage()
{
  signed int v1; 

  v1 = 0;
  checkpointStageScroll = 0;
  if ( debugStage )
  {
    currentStage = debugStage;
    SetPowerUp(debugPowerup);
    SetSpeed(debugSpeed);
    SetLife(debugLife);
  }
  if ( LoadPxeve(currentStage) && StartStage() )
  {
    if ( debugStage )
    {
      if ( debugStageScroll )
      {
        SetStageScroll(debugStageScroll);
        SetStageEntitiesPartial();
      }
      debugStage = 0;
    }
    v1 = 1;
  }
  return v1;
}









int SetCheckpointScroll()
{
  int result; 

  result = GetCheckpointScrollValue();
  checkpointStageScroll = result;
  return result;
}



signed int CheckStageClear(int a1)
{
  signed int result; 
  char v2; 

  if ( StageState != 30 && StageState != 31 && StageState != 32 && StageState != 40 && StageState != 50 )
  {
    sprintf(&v2, "STAGE %d CLEAR!", a1);
    PutTextCenter(&v2);
    StageState = 20;
    centerTextMiscTimer = 0;
    currentMusic = 0;
    SetMusicVolume(3000);
    result = 1;
  }
  else
  {
    result = 1;
  }
  return result;
}





signed int ShipCrushProc2()
{
  SetMusicVolume(100);
  FreeCenterText();
  centerTextMiscTimer = 0;
  currentMusic = 0;
  StageState = 30;
  return 1;
}





signed int ActStageState(int a1)
{
  int v1; 
  int v2; 
  int v3; 
  signed int result; 
  int v5; 
  int v6; 

  switch ( StageState )
  {
    case 0:
      v1 = centerTextMiscTimer++;
      if ( v1 > 100 )
      {
        FreeCenterText();
        StageState = 10;
      }
      goto LABEL_44;
    case 10:
      if ( CheckPlayRecordFlag() )
        EndRecordPlayback();
      goto LABEL_44;
    case 20:
      v2 = centerTextMiscTimer++;
      if ( v2 == 150 )
      {
        centerTextMiscTimer = 0;
        StageState = 21;
        SetShipBoost();
        PutTextCenter(noText);
      }
      goto LABEL_44;
    case 21:
      v3 = centerTextMiscTimer++;
      if ( v3 == 150 )
      {
        StageState = 22;
        SetFadeActive();
      }
      goto LABEL_44;
    case 22:
      if ( !CheckFadeEnd() )
        goto LABEL_44;
      if ( ++currentStage <= 5 )
      {
        InitStage();
        goto LABEL_44;
      }
      if ( GameFlags & 1 )
      {
        EndRecordPlayback();
        goto LABEL_44;
      }
      currentStage = 0;
      WriteGameCleared();
      result = 7;
      break;
    case 30:
      v5 = centerTextMiscTimer++;
      if ( v5 > 100 )
      {
        if ( ShipLivesCount <= 0 )
        {
          if ( GameFlags & 1 )
          {
            EndRecordPlayback();
          }
          else
          {
            PutTextCenter("GAME OVER");
            StageState = 31;
            centerTextMiscTimer = 0;
            LoadMusic((int)musGameover[0]);
            StartMusic(0);
          }
        }
        else
        {
          StageState = 40;
          SetFadeActive();
        }
      }
      goto LABEL_44;
    case 31:
      if ( *(_DWORD *)(a1 + 4) & 1 )
      {
        if ( GameFlags & 2 )
          result = 3;
        else
          result = 1;
      }
      else
      {
        if ( centerTextMiscTimer == 250 )
          SetFadeActive();
        v6 = centerTextMiscTimer++;
        if ( v6 > 300 )
        {
          StageState = 32;
          SetGameDelay(-1);
        }
LABEL_44:
        result = 2;
      }
      break;
    case 32:
      if ( !(*(_DWORD *)(a1 + 4) & 1) )
        goto LABEL_44;
      if ( GameFlags & 2 )
        result = 3;
      else
        result = 1;
      return result;
    case 40:
      if ( CheckFadeEnd() )
      {
        --ShipLivesCount;
        ResetShip();
        StartStage();
      }
      goto LABEL_44;
    default:
      goto LABEL_44;
  }
  return result;
}








int WriteGameCleared()
{
  int result; 
  char v1; 
  FILE *v2; 

  sprintf(&v1, "%s\\%s", temp_guxtPath, clearedFile[0]);
  v2 = fopen(&v1, "wt");
  if ( v2 )
  {
    fprintf(v2, "%s\n", clearedMentama);
    fclose(v2);
  }
  result = GameFlags | 4;
  GameFlags |= 4u;
  return result;
}





void EndRecordPlayback()
{
  PutTextCenter("RECORD OVER");
  StageState = 50;
  SetGameDelay(-1);
  SetMusicVolume(1000);
  StopLoopSound(32);
  RecordEndFadeWhite();
}



int PutHUD(int a1)
{
  int v2; 
  int v3; 
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

  v2 = 96;
  v3 = 0;
  v4 = 112;
  v5 = 8;
  v6 = 72;
  v7 = 80;
  v8 = 104;
  v9 = 88;
  v10 = 120;
  v11 = 48;
  v12 = 128;
  v13 = 56;
  switch ( StageState )
  {
    case 20:
      PutRect(24, 56, (RECT *)&v6, 11);
      PutScore(a1, 52, 56);
      break;
    case 0:
      PutRect(48, 56, (RECT *)&v2, 11);
      if ( GameFlags & 2 )
        PutRect(64, 56, (RECT *)&v10, 11);
      else
        PutNumber(a1, 64, 56, ShipLivesCount, 1, 0);
      break;
    case 10:
    case 30:
    case 50:
      PutScore(a1, 36, 4);
      PutRect(4, 4, (RECT *)&v2, 11);
      if ( GameFlags & 2 )
        PutRect(20, 4, (RECT *)&v10, 11);
      else
        PutNumber(a1, 20, 4, ShipLivesCount, 1, 0);
      break;
    default:
      return PutTextBuffer(a1);
  }
  return PutTextBuffer(a1);
}





signed int LoadGenericData()
{
  signed int v1; 

  v1 = 0;
  if ( LoadPximg((int)"color1", 16)
    && LoadPximg((int)"color2", 17)
    && LoadPximg((int)"color3", 18)
    && LoadPximg((int)"color4", 19)
    && LoadPximg((int)"color5", 20)
    && LoadPximg((int)"escape", 22)
    && InitSurface_(120, 160, 23, 1)
    && LoadSound((int)"beem_normal", 0)
    && LoadSound((int)"beem_twin", 1)
    && LoadSound((int)"beem_machine", 2)
    && LoadSound((int)"beem_triangle", 3)
    && LoadSound((int)"beem_back", 4)
    && LoadSound((int)"beem_wide", 5)
    && LoadSound((int)"beem_3line", 6)
    && LoadSound((int)"beem_Star", 8)
    && LoadSound((int)"beem_enemy", 7)
    && LoadSound((int)"beem_ray1", 9)
    && LoadSound((int)"beem_ray2", 10)
    && LoadSound((int)"destroy1", 11)
    && LoadSound((int)"destroy2", 12)
    && LoadSound((int)"destroy3", 13)
    && LoadSound((int)"destroy4", 14)
    && LoadSound((int)"destroy5", 15)
    && LoadSound((int)"destroy6", 16)
    && LoadSound((int)"damage1", 17)
    && LoadSound((int)"damage2", 18)
    && LoadSound((int)"damage3", 19)
    && LoadSound((int)"damage4", 20)
    && LoadSound((int)"damage5", 21)
    && LoadSound((int)"damage6", 22)
    && LoadSound((int)"damage7", 23)
    && LoadSound((int)"nodamage", 24)
    && LoadSound((int)"dead", 25)
    && LoadSound((int)"comein", 26)
    && LoadSound((int)"speedup", 27)
    && LoadSound((int)"speeddown", 28)
    && LoadSound((int)"equip", 29)
    && LoadSound((int)"charge1", 30)
    && LoadSound((int)"charge2", 31)
    && LoadSound((int)"noise1", 32)
    && LoadSound((int)"shi_on", 33)
    && LoadSound((int)"shi_off", 34)
    && LoadSound((int)"jet", 35)
    && LoadSound((int)"missile", 36)
    && LoadSound((int)"hitblock", 37)
    && LoadSound((int)"open", 38)
    && LoadSound((int)"bite", 39)
    && LoadSound((int)"bonus", 40)
    && LoadSound((int)"oneup", 41)
    && LoadSound((int)"ameba", 42)
    && LoadSound((int)"check_point", 43)
    && LoadSound((int)"pause_on", 44)
    && LoadSound((int)"pause_off", 45) )
  {
    v1 = 1;
  }
  return v1;
}


int Game(HWND hWnd)
{
  signed int v2; 
  signed int v3; 
  int v4; 

  v3 = 0;
  v2 = 0;
  v4 = 1;
  InitTriangleTable();
  LoadPximgCharactor();
  ResetStage();
  SetBackgroundColor_();
  LoadPximgBullet();
  ResetCaret2();
  LoadPximgEntities();
  LoadPximgPlayerInit();
  ResetEntityStageTotal();
  LoadPximgSymbol();
  if ( InitGameAttr() )
  {
    ClearLoopSound();
    LoadPximgScreenEffect();
    InitPlayRecord();
    DragEnable(hWnd);
LABEL_3:
    while ( !v2 )
    {
      switch ( v4 )
      {
        case 1:
          v4 = MenuLoop();
          break;
        case 3:
          v4 = RankingLoop();
          break;
        case 4:
          v4 = RankingViewLoop();
          break;
        case 5:
          v4 = KeyConfigLoop((int)hWnd, 0);
          break;
        case 6:
          v4 = KeyConfigLoop((int)hWnd, 1);
          break;
        case 2:
          v4 = ModeAction((int)hWnd);
          break;
        case 7:
          v4 = ModeEnding();
          break;
        case 0:
          v2 = 1;
          break;
        default:
          goto LABEL_3;
      }
    }
    v3 = 1;
  }
  SaveWindowSettings(hWnd);
  CallClearCenterText();
  StopLoopSound2();
  FreePlayRecord();
  return v3;
}


int LoadPximg(int a1, int a2)
{
  char v3; 

  sprintf(&v3, "%s.pximg", a1);
  return MakeSurface_Pximg(&v3, a2, 1, 0);
}


int CountFramePerSecond()
{
  DWORD v0; 

  if ( dword_441A84 )
  {
    Timer1000Ticks = GetTickCount();
    dword_441A84 = 0;
  }
  v0 = GetTickCount();
  ++Timer1000TicksElapsed;
  if ( Timer1000Ticks + 1000 <= v0 )
  {
    Timer1000Ticks += 1000;
    Timer1000TicksFinal = Timer1000TicksElapsed;
    Timer1000TicksElapsed = 0;
  }
  return Timer1000TicksFinal;
}






int PutFramePerSecond()
{
  int result; 
  int v1; 
  int v2; 
  int v3; 
  int v4; 
  int v5; 

  v5 = CountFramePerSecond();
  v1 = 112;
  v2 = 8;
  v3 = 128;
  v4 = 16;
  if ( v5 == 50 )
    result = PutBitmap3((RECT *)&scWOffset_0, ScreenRenderWidth - 16, 3, (RECT *)&v1, 11);
  else
    result = PutNumber((int)&scWOffset_0, ScreenRenderWidth - 16, 3, v5, 2, 0);
  return result;
}




signed int Flip_SystemTask()
{
  do
  {
    if ( !message() )
      return 0;
    Sleep(1u);
    current_time = GetTickCount();
  }
  while ( current_time < (unsigned int)(next_time + 20) );
  if ( current_time < (unsigned int)(next_time + 100) )
    next_time += 20;
  else
    next_time = current_time;
  Flip_Screen();
  return 1;
}




int SetReset(int a1)
{
  int result; 

  result = a1;
  GameReset = a1;
  return result;
}



int GetGameReset()
{
  return GameReset;
}



signed int Call_Escape()
{
  signed int result; 
  int v1; 
  signed int v2; 
  _DWORD v3[4]; 

  v3[0] = 0;
  v3[1] = 0;
  v3[2] = 80;
  v3[3] = 24;
  v2 = 0;
  if ( GetKeyHeld_(27) )
  {
    KeyTrigUpdate_();
    v1 = GetSurfaceColor(17);
    while ( 1 )
    {
      KeyTrigUpdate_();
      if ( GetKeyCode(112) )
        break;
      if ( GetKeyCode(113) )
      {
        SetReset(1);
        break;
      }
      if ( GetKeyCode(27) )
      {
        v2 = 1;
        break;
      }
      PutBackground((int)&scWOffset_0, v1);
      PutRect(24, 68, (RECT *)v3, 22);
      if ( !Flip_SystemTask() )
      {
        v2 = 1;
        break;
      }
    }
    KeyTrigUpdate_();
    result = v2;
  }
  else
  {
    result = 0;
  }
  return result;
}



signed int KeyConfigLoop(int a1, int joy)
{
  signed int result; 
  signed int v3; 
  int v4; 
  char v5; 
  int v6; 

  SetSoundDisabled(0);
  ChangeMusic(0);
  if ( LoadPximg((int)"keycode", 13) )
  {
    if ( !ReadButtonConfig(&v5) )
      ResetButtonConfig((int)&v5);
    v6 = GetSurfaceColor(17);
    ResetInput();
    memset(&dword_44C4B8, 0, 0xCu);
    buttonConfigCount = 0;
    do
    {
      v4 = 0;
      KeyTrigUpdate_();
      if ( GetKeyCode(27) || GetGameReset() )
      {
        v3 = 1;
        goto LABEL_22;
      }
      if ( !GetKeyCode(112) && !GetKeyCode(113) )
      {
        if ( joy )
        {
          if ( ConfigJoystick((int)&v5) )
            v4 = 1;
        }
        else if ( ConfigKey((int)&v5) )
        {
          v4 = 1;
        }
      }
      PutBackground((int)&scWOffset_0, v6);
      PutKeyConfig((int)&scWOffset_0, (int)&v5, joy, v4);
      PutFramePerSecond();
      if ( !Flip_SystemTask() )
      {
        v3 = 0;
        goto LABEL_22;
      }
    }
    while ( !v4 );
    v3 = 1;
    WriteButtonConfig(&v5);
    Sleep(0x1F4u);
LABEL_22:
    ClearSurface(13);
    result = v3;
  }
  else
  {
    result = 0;
  }
  return result;
}





signed int ConfigKey(int a1)
{
  signed int result; 
  int i; 
  signed int j; 

  ++byte_44C4B5;
  for ( i = 0; i < 256 && !GetKeyCode(i); ++i )
    ;
  if ( i == 256 )
  {
    result = 0;
  }
  else
  {
    for ( j = 0; j < (unsigned __int8)buttonConfigCount && *(_BYTE *)(j + a1) != i; ++j )
      ;
    if ( j >= (unsigned __int8)buttonConfigCount )
    {
      *(_BYTE *)(a1 + (unsigned __int8)buttonConfigCount) = i;
      if ( (signed int)(unsigned __int8)buttonConfigCount >= 5 )
      {
        PlaySound(33);
        result = 1;
      }
      else
      {
        ++buttonConfigCount;
        PlaySound(2);
        result = 0;
      }
    }
    else
    {
      buttonConfigCount = 0;
      PlaySound(34);
      ResetKeyboardConfig((ButtonConfig *)a1);
      result = 0;
    }
  }
  return result;
}




signed int ConfigJoystick(int a1)
{
  signed int result; 
  signed int i; 
  char v3; 
  int v4; 
  int j; 

  ++byte_44C4B5;
  if ( JoystickProc_((int)&v3) )
  {
    dword_44C4B8 = v4;
    UpdateTrg((int)&dword_44C4B8);
    for ( i = 0; i < 32 && !(dword_44C4BC & (1 << i)); ++i )
      ;
    if ( i == 32 )
    {
      result = 0;
    }
    else
    {
      for ( j = 0; j < (unsigned __int8)buttonConfigCount && *(_BYTE *)(j + a1 + 6) != i; ++j )
        ;
      if ( j >= (unsigned __int8)buttonConfigCount )
      {
        *(_BYTE *)(a1 + (unsigned __int8)buttonConfigCount + 6) = i;
        if ( (signed int)(unsigned __int8)buttonConfigCount >= 1 )
        {
          PlaySound(33);
          result = 1;
        }
        else
        {
          ++buttonConfigCount;
          PlaySound(2);
          result = 0;
        }
      }
      else
      {
        buttonConfigCount = 0;
        PlaySound(34);
        ResetJoystickConfig((ButtonConfig *)a1);
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






int PutKeyConfig(int a1, int a2, int a3, int a4)
{
  int result; 
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
  int i; 
  int v31; 
  int v32; 
  int v33; 
  int v34; 
  int v35; 
  int v36; 
  int v37; 
  int v38; 

  v35 = 0;
  v36 = 0;
  v37 = 64;
  v38 = 8;
  v14 = 64;
  v15 = 40;
  v16 = 128;
  v17 = 48;
  v26 = 64;
  v27 = 32;
  v28 = 128;
  v29 = 40;
  v18 = 0;
  v19 = 32;
  v20 = 64;
  v21 = 80;
  v22 = 0;
  v23 = 64;
  v24 = 64;
  v25 = 80;
  v6 = 104;
  v7 = 24;
  v8 = 112;
  v9 = 32;
  v10 = 0;
  v11 = 0;
  v12 = 0;
  v13 = 0;
  PutBitmap3((RECT *)a1, 30, 8, (RECT *)&v35, 11);
  PutBitmap3((RECT *)a1, 30, 32, (RECT *)&v18 + (a3 != 0), 11);
  PutBitmap3(
    (RECT *)a1,
    78,
    8 * (unsigned __int8)buttonConfigCount + 32,
    (RECT *)&v6 + ((signed int)(unsigned __int8)byte_44C4B5 >> 2) % 2,
    11);
  if ( a4 )
    result = PutBitmap3((RECT *)a1, 30, 136, (RECT *)&v26, 11);
  else
    result = PutBitmap3((RECT *)a1, 30, 136, (RECT *)&v14, 11);
  if ( a3 )
  {
    for ( i = 0; i < 2; ++i )
      result = PutNumber(a1, 78, 8 * i + 32, *(_BYTE *)(i + a2 + 6) + 1, 1, 0);
  }
  else
  {
    for ( i = 0; i < 6; ++i )
    {
      v5 = *(_BYTE *)(i + a2) % 16;
      v31 = 8 * v5;
      v32 = 8 * ((signed int)*(_BYTE *)(i + a2) >> 4);
      v33 = 8 * v5 + 8;
      v34 = v32 + 8;
      result = PutBitmap3((RECT *)a1, 78, 8 * i + 32, (RECT *)&v31, 13);
    }
  }
  return result;
}




int ModeEnding()
{
  int v1; 
  int v2; 
  int v3; 
  int v4; 
  int v5; 
  int v6; 
  int v7; 
  int v8; 
  FILE *v9; 
  int v10; 

  v10 = 0;
  v4 = 72;
  v5 = 80;
  v6 = 104;
  v7 = 88;
  v8 = GetSurfaceColor(17);
  SetSoundDisabled(1);
  SetReset(0);
  ClearTrg_((int)&v1);
  LoadPximg((int)"ending", 24);
  LoadPximgEnemyName();
  if ( LoadStage(6) )
  {
    if ( LoadPxeve(6) )
    {
      LoadPximgEnemy(2);
      LoadPximgEnemy(3);
      LoadPximgEnemy(4);
      LoadPximgEnemy(5);
      LoadPximgEnemy(1);
      ZeroEntityCount();
      ResetBullet();
      ResetCaret();
      ResetEntities();
      ResetRandom();
      SetInitialShipValues();
      EndingInitFade();
      SetGameDelay(0);
      StopLoopSound(32);
      SetDefaultStageScroll();
      SetScrollSpeed(0);
      SetStageXOffset(4096);
      SetShipEnding();
      v9 = 0;
      while ( 1 )
      {
        EndingPrint(v9, ++v10, "01");
        if ( Call_Escape() )
        {
          v3 = 0;
          goto LABEL_23;
        }
        EndingPrint(v9, v10, "02");
        if ( GetGameReset() )
        {
          v3 = 1;
          goto LABEL_23;
        }
        EndingPrint(v9, v10, "03");
        v1 = GetTrg();
        EndingPrint(v9, v10, "04");
        UpdateTrg((int)&v1);
        EndingPrint(v9, v10, "05");
        if ( CheckEndingTextCount() )
        {
          if ( v2 & 1 )
            break;
        }
        EndingPrint(v9, v10, "06");
        if ( !GetGameDelayed() )
        {
          EndingPrint(v9, v10, "06.1");
          SetStageEntities();
          EndingPrint(v9, v10, "06.2");
          ActStageScroll();
          EndingPrint(v9, v10, "06.3");
          ActNpc();
          EndingPrint(v9, v10, "06.4");
          ActShipState(0);
          EndingPrint(v9, v10, "06.5");
          ActBullet();
          EndingPrint(v9, v10, "06.6");
          ActCaret();
          EndingPrint(v9, v10, "06.7");
          ActFade();
          EndingPrint(v9, v10, "06.8");
        }
        EndingTextRunTimer();
        EndingPrint(v9, v10, "06.9");
        EndingPrint(v9, v10, "07");
        PutBackground((int)&scWOffset_0, v8);
        EndingPrint(v9, v10, "07.1");
        PutNpChar((int)&scWOffset_0);
        EndingPrint(v9, v10, "07.2");
        PutMapParts((WindowAttr *)&scWOffset_0);
        EndingPrint(v9, v10, "07.3");
        PutNpChar2((int)&scWOffset_0);
        EndingPrint(v9, v10, "07.4");
        PutPlayerExtra((int)&scWOffset_0);
        EndingPrint(v9, v10, "07.5");
        PutBullet((int)&scWOffset_0);
        EndingPrint(v9, v10, "07.6");
        PutMapParts2((int)&scWOffset_0);
        EndingPrint(v9, v10, "07.7");
        PutCaret((int)&scWOffset_0);
        EndingPrint(v9, v10, "07.8");
        PutFade((int)&scWOffset_0);
        EndingPrint(v9, v10, "07.9");
        PutEndingText();
        EndingPrint(v9, v10, "08");
        if ( v10 < 300 )
        {
          EndingPrint(v9, v10, "08.1");
          PutRect(0, 32, (RECT *)&unk_43C558 + v10 / 4 % 3, 24);
          EndingPrint(v9, v10, "08.2");
          PutRect(24, 48, (RECT *)&v4, 11);
          EndingPrint(v9, v10, "08.3");
          PutScore((int)&scWOffset_0, 52, 48);
        }
        EndingPrint(v9, v10, "09");
        PutFramePerSecond();
        EndingPrint(v9, v10, "10");
        if ( !Flip_SystemTask() )
        {
          v3 = 0;
          goto LABEL_23;
        }
      }
      if ( GetInScoreAttack() )
        v3 = 3;
      else
        v3 = 1;
    }
    else
    {
      v3 = 0;
    }
  }
  else
  {
    v3 = 0;
  }
LABEL_23:
  if ( v9 )
    fclose(v9);
  return v3;
}



void EndingPrint(int a1, int a2, int a3)
{
  ;
}


int ModeAction(int a1)
{
  int v1; 
  int v2; 
  char v3; 
  int v5; 
  int *v6; 
  int v7; 
  int v8; 
  int v9; 
  unsigned __int8 v10; 

  v10 = 0;
  v9 = GetSurfaceColor(16);
  if ( GameStart() )
  {
    SetSoundDisabled(0);
    ClearTrg_((int)&v8);
    ClearTrg_((int)&v5);
    if ( GetInReplay() )
    {
      ZeroPlayRecord();
      v6 = &v5;
    }
    else
    {
      NewPlayRecord();
      v6 = &v8;
    }
    InitStage();
    while ( 1 )
    {
      ++v10;
      if ( Call_Escape() )
      {
        v7 = 0;
        goto LABEL_27;
      }
      if ( GetGameReset() )
      {
        v7 = 1;
        goto LABEL_27;
      }
      KeyTrigUpdate_();
      v8 = GetTrg();
      if ( GetInReplay() )
      {
        v5 = ActPlayRecord();
        UpdateTrg((int)&v5);
      }
      else
      {
        RecordPlayRecord(v8);
      }
      UpdateTrg((int)&v8);
      if ( GetInReplay() && v8 & 1 )
        SetReset(1);
      v7 = PauseLoop(a1, (int)&v8);
      if ( v7 != 2 )
        goto LABEL_27;
      v7 = ActStageState((int)&v8);
      if ( v7 != 2 )
        goto LABEL_27;
      if ( !GetGameDelayed() )
      {
        SetStageEntities();
        ActStageScroll();
        ActNpc();
        ActShipState(v6);
        ActBullet();
        ActCaret();
        HitNpCharBullet();
        HitShipPowerup();
        HitShipMap();
        HitEntityMap();
        HitBulletMap();
        ActFade();
      }
      if ( !GetInReplay() || !(v8 & 0x40) || !(v10 % 16) )
      {
        PutBackground((int)&scWOffset_0, v9);
        PutNpChar((int)&scWOffset_0);
        PutMapParts((WindowAttr *)&scWOffset_0);
        PutPlayer((int)&scWOffset_0);
        PutNpChar2((int)&scWOffset_0);
        PutPlayerExtra((int)&scWOffset_0);
        PutBullet((int)&scWOffset_0);
        PutMapParts2((int)&scWOffset_0);
        PutCaret((int)&scWOffset_0);
        PutFade((int)&scWOffset_0);
        PutHUD((int)&scWOffset_0);
        PutFramePerSecond();
        if ( !Flip_SystemTask() )
          break;
      }
    }
    v7 = 0;
  }
  else
  {
    v7 = 0;
  }
LABEL_27:
  if ( !GetInReplay() )
  {
    EndPlayRecord();
    v1 = GetScore();
    v2 = GetCurrentStage();
    v3 = GetInScoreAttack();
    WritePlayRecord(v3, v2, v1);
  }
  StopLoopSound(32);
  return v7;
}



signed int PauseLoop(int a1, int a2)
{
  signed int result; 
  int v3; 
  int v4; 
  int v5; 
  int v6; 
  int v7; 
  int v8; 
  unsigned int v9; 
  int v10; 
  int v11; 
  int v12; 
  int v13; 

  v9 = 0;
  if ( *(_DWORD *)(a2 + 4) & 2 )
  {
    v3 = *(_DWORD *)a2;
    v4 = *(_DWORD *)(a2 + 4);
    v5 = *(_DWORD *)(a2 + 8);
    v10 = 64;
    v11 = 48;
    v12 = 104;
    v13 = 56;
    SetReset(0);
    ClearTrg_((int)&v6);
    PutBitmapPause_(23);
    PlaySound(44);
    while ( 1 )
    {
      ++v9;
      if ( Call_Escape() )
      {
        v8 = 0;
        goto LABEL_14;
      }
      if ( GetGameReset() )
      {
        v8 = 1;
        goto LABEL_14;
      }
      v6 = GetTrg();
      UpdateTrg((int)&v6);
      if ( v9 > 0x14 )
      {
        if ( v7 & 2 )
          break;
      }
      PutRect(0, 0, (RECT *)&scWOffset_0, 23);
      PutRect(2, 2, (RECT *)&v10, 11);
      if ( !Flip_SystemTask() )
        return 0;
    }
    v8 = 2;
    PlaySound(45);
LABEL_14:
    *(_DWORD *)a2 = v3;
    *(_DWORD *)(a2 + 4) = v4;
    *(_DWORD *)(a2 + 8) = v5;
    result = v8;
  }
  else
  {
    result = 2;
  }
  return result;
}













signed int ResetGameSurface_()
{
  return InitSurface_(120, 8, 10, 1);
}


void ClearCenterText()
{
  if ( centerTextBuffer )
  {
    free(centerTextBuffer);
    centerTextBuffer = 0;
  }
}


signed int FreeCenterText()
{
  RenderToSurface_((int)&unusedTextRender_, 0, 10);
  if ( centerTextBuffer )
  {
    free(centerTextBuffer);
    centerTextBuffer = 0;
  }
  return 1;
}


void *PutTextCenter(char *a1)
{
  void *result; 
  size_t v2; 

  result = (void *)RenderToSurface_((int)&unusedTextRender_, 0, 10);
  if ( a1 )
  {
    PutTextObject((int)&unusedTextRender_, 60, 4, a1, 16, 10);
    if ( centerTextBuffer )
    {
      free(centerTextBuffer);
      centerTextBuffer = 0;
    }
    v2 = strlen(a1) + 1;
    centerTextBuffer = (char *)malloc(v2);
    result = memcpy(centerTextBuffer, a1, v2);
  }
  return result;
}


int PutTextBuffer(int a1)
{
  return PutBitmap3((RECT *)a1, 0, 76, (RECT *)&unusedTextRender_, 10);
}


int sub_41EC40()
{
  int result; 

  if ( centerTextBuffer )
    result = PutTextObject((int)&unusedTextRender_, 60, 4, centerTextBuffer, 16, 10);
  return result;
}


