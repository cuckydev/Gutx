


signed int RankingViewLoop()
{
  int v0; 
  int v2; 
  int v3; 
  int v4; 
  char v6; 
  int v7; 

  OpenRankingFile(&v6);
  v0 = GetScore();
  v2 = sub_41BC90((int)&v6, v0);
  v7 = GetSurfaceColor(17);
  ClearTrg_((int)&v3);
  while ( 1 )
  {
    if ( Call_Escape() )
      return 0;
    if ( GetGameReset() )
      return 1;
    v3 = GetTrg();
    UpdateTrg((int)&v3);
    if ( v4 & 1 )
      break;
    PutBackground((int)&scWOffset_0, v7);
    PutRankingView((int)&scWOffset_0, (int)&v6, v2);
    PutFramePerSecond();
    if ( !Flip_SystemTask() )
      return 0;
  }
  return 1;
}



int OpenRankingFile(void *a1)
{
  signed int v1; 
  char v3; 
  int v4; 
  int v5; 
  FILE *v6; 
  char v7; 

  v5 = 0;
  v6 = 0;
  sprintf(&v3, "%s\\%s", temp_guxtPath, RankingFile);
  v6 = fopen(&v3, "rb");
  if ( v6 )
  {
    if ( ReadFromFile(a1, 0x78u, 1u, v6) == 1 && ReadFromFile(&v4, 4u, 1u, v6) == 1 && !ReadFromFile(&v7, 1u, 1u, v6) )
    {
      v1 = sub_41BC20((int)a1);
      if ( v4 == v1 )
        v5 = 1;
    }
  }
  if ( v6 )
    fclose(v6);
  if ( !v5 )
    SetDefaultRankingNames(a1);
  return v5;
}



char *SetDefaultRankingNames(void *a1)
{
  char *result; 

  memset(a1, 0, 0x78u);
  strcpy((char *)a1, "PINKY");
  *((_DWORD *)a1 + 2) = 1000;
  strcpy((char *)a1 + 12, "ZOO");
  *((_DWORD *)a1 + 5) = 900;
  strcpy((char *)a1 + 24, "FOODS");
  *((_DWORD *)a1 + 8) = 800;
  strcpy((char *)a1 + 36, "KING");
  *((_DWORD *)a1 + 11) = 700;
  strcpy((char *)a1 + 48, "PEARL-C");
  *((_DWORD *)a1 + 14) = 600;
  strcpy((char *)a1 + 60, "IRON-H");
  *((_DWORD *)a1 + 17) = 500;
  strcpy((char *)a1 + 72, "KANI");
  *((_DWORD *)a1 + 20) = 400;
  strcpy((char *)a1 + 84, "HARISEN");
  *((_DWORD *)a1 + 23) = 300;
  strcpy((char *)a1 + 96, "JACK");
  *((_DWORD *)a1 + 26) = 200;
  strcpy((char *)a1 + 108, "CHINGYO");
  result = (char *)a1 + 108;
  *((_DWORD *)a1 + 29) = 100;
  return result;
}


signed int sub_41BC20(int a1)
{
  signed int i; 
  signed int v3; 

  v3 = 7;
  for ( i = 0; (unsigned int)i < 0x78; ++i )
  {
    if ( i % 7 == 2 )
      v3 -= *(_BYTE *)(i + a1);
    else
      v3 += *(_BYTE *)(i + a1);
  }
  return v3;
}


signed int sub_41BC90(int a1, int a2)
{
  signed int result; 
  signed int i; 

  for ( i = 0; i < 10 && a2 <= *(_DWORD *)(a1 + 12 * i + 8); ++i )
    ;
  if ( i && a2 == *(_DWORD *)(a1 + 12 * (i - 1) + 8) )
    --i;
  if ( i == 10 )
    result = -1;
  else
    result = i;
  return result;
}


int PutRankingView(int a1, int a2, int a3)
{
  int v3; 
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
  int i; 

  v13 = 36;
  v14 = 8;
  v15 = 80;
  v16 = 16;
  v21 = 120;
  v22 = 24;
  v23 = 128;
  v24 = 32;
  v17 = 112;
  v18 = 24;
  v19 = 120;
  v20 = 32;
  v5 = 0;
  v6 = 24;
  v7 = 104;
  v8 = 32;
  v9 = 0;
  v10 = 0;
  v11 = 0;
  v12 = 0;
  if ( a3 >= 0 && *(_DWORD *)(a2 + 12 * a3 + 8) )
  {
    v3 = ((signed int)(unsigned __int8)byte_44C4C4++ >> 2) % 2;
    PutBitmap3((RECT *)a1, 8, 12 * a3 + 32, (RECT *)&v5 + v3, 11);
  }
  result = PutBitmap3((RECT *)a1, 38, 8, (RECT *)&v13, 11);
  for ( i = 0; i < 10; ++i )
  {
    if ( i == 9 )
      PutBitmap3((RECT *)a1, 8, 140, (RECT *)&v21, 11);
    else
      PutNumber(a1, 8, 12 * i + 32, i + 1, 1, 0);
    PutTextObject(a1, 20, 12 * i + 32, (char *)(a2 + 12 * i), 0, 0);
    if ( *(_DWORD *)(a2 + 12 * i + 8) )
      PutNumber(a1, 68, 12 * i + 32, *(_DWORD *)(a2 + 12 * i + 8), 6, 0);
    PutBitmap3((RECT *)a1, 104, 12 * i + 32, (RECT *)&v17, 11);
    result = i + 1;
  }
  return result;
}



signed int RankingLoop()
{
  int v0; 
  signed int result; 
  signed int v2; 
  int v3; 
  int v4; 
  char v5; 
  char v6; 
  char v7[120]; 
  int v8; 

  memset(&v5, 46, 7u);
  v6 = 0;
  OpenRankingFile(v7);
  v0 = GetScore();
  v2 = sub_41C150((int)v7, v0);
  if ( v2 == -1 )
  {
    result = 1;
  }
  else
  {
    v8 = GetSurfaceColor(17);
    ClearTrg_((int)&v3);
    ResetRankingInput();
    while ( 1 )
    {
      if ( Call_Escape() )
      {
        v4 = 0;
        goto LABEL_13;
      }
      if ( GetGameReset() )
      {
        v4 = 1;
        goto LABEL_13;
      }
      v3 = GetTrg();
      UpdateTrg((int)&v3);
      if ( !RunRankingInput((int)&v5, (int)&v3) )
        break;
      PutBackground((int)&scWOffset_0, v8);
      PutRankingInput((int)&scWOffset_0, &v5);
      PutFramePerSecond();
      if ( !Flip_SystemTask() )
        return 0;
    }
    v4 = 4;
    strcpy(&v7[12 * v2], &v5);
    WriteRankingFile(v7);
LABEL_13:
    result = v4;
  }
  return result;
}




int WriteRankingFile(void *a1)
{
  char v2; 
  int v3; 
  int v4; 
  FILE *v5; 

  v4 = 0;
  v5 = 0;
  v3 = sub_41BC20((int)a1);
  sprintf(&v2, "%s\\%s", temp_guxtPath, RankingFile);
  v5 = fopen(&v2, "wb");
  if ( v5 && WriteToFile(a1, 0x78u, 1u, v5) == 1 && WriteToFile(&v3, 4u, 1u, v5) == 1 )
    v4 = 1;
  if ( v5 )
    fclose(v5);
  return v4;
}



signed int sub_41C150(int a1, int a2)
{
  signed int result; 
  int v3; 
  int v4; 
  signed int i; 
  signed int j; 

  for ( i = 0; i < 10 && a2 <= *(_DWORD *)(a1 + 12 * i + 8); ++i )
    ;
  if ( i == 10 )
  {
    result = -1;
  }
  else
  {
    for ( j = 9; j > i; --j )
    {
      v3 = a1 + 12 * (j - 1);
      v4 = a1 + 12 * j;
      *(_DWORD *)v4 = *(_DWORD *)v3;
      *(_DWORD *)(v4 + 4) = *(_DWORD *)(v3 + 4);
      *(_DWORD *)(v4 + 8) = *(_DWORD *)(v3 + 8);
    }
    *(_DWORD *)(a1 + 12 * i + 8) = a2;
    memset((void *)(a1 + 12 * i), 0, 8u);
    result = i;
  }
  return result;
}


void ResetRankingInput()
{
  ranking_0 = 0;
  ranking_4 = 0;
  ranking_3 = 0;
  ranking_1 = 0;
  ranking_2 = 0;
  ranking_int = 0;
}








signed int RunRankingInput(int a1, int a2)
{
  signed int v3; 

  v3 = GetPlayerInput(*(_DWORD *)a2);
  ++ranking_2;
  if ( v3 )
  {
    if ( ranking_int == v3 )
    {
      if ( (signed int)(unsigned __int8)++ranking_1 > 12 )
      {
        switch ( v3 )
        {
          case 1:
            --ranking_0;
            break;
          case 2:
            ++ranking_0;
            break;
          case 3:
            --ranking_4;
            break;
          case 4:
            ++ranking_4;
            break;
          default:
            break;
        }
        PlaySound(2);
        ranking_1 = 6;
      }
    }
    else
    {
      switch ( v3 )
      {
        case 1:
          --ranking_0;
          break;
        case 2:
          ++ranking_0;
          break;
        case 3:
          --ranking_4;
          break;
        case 4:
          ++ranking_4;
          break;
        default:
          break;
      }
      PlaySound(2);
      ranking_int = v3;
      ranking_1 = 0;
    }
  }
  else
  {
    ranking_int = 0;
    ranking_1 = 0;
  }
  if ( ranking_0 > 9 )
    ranking_0 = 0;
  if ( ranking_0 < 0 )
    ranking_0 = 9;
  if ( ranking_4 > 9 )
    ranking_4 = 0;
  if ( ranking_4 < 0 )
    ranking_4 = 9;
  if ( *(_DWORD *)(a2 + 4) & 1 )
  {
    if ( ranking_4 == 9 && (ranking_0 == 8 || ranking_0 == 9) )
    {
      PlaySound(25);
      return 0;
    }
    if ( ranking_4 != 9 || ranking_0 != 6 && ranking_0 != 7 )
    {
      if ( ranking_4 != 9 || ranking_0 != 5 )
      {
        PlaySound(1);
        *(_BYTE *)(a1 + ranking_3) = ranking_0 + 10 * ranking_4 + 32;
        if ( ranking_3 < 6 )
          ++ranking_3;
      }
      else
      {
        PlaySound(1);
        *(_BYTE *)(a1 + ranking_3) = 32;
        if ( ranking_3 < 6 )
          ++ranking_3;
      }
    }
    else if ( ranking_3 > 0 )
    {
      *(_BYTE *)(a1 + ranking_3) = 32;
      PlaySound(17);
      --ranking_3;
    }
  }
  return 1;
}








int PutRankingInput(int a1, char *a2)
{
  int v2; 
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

  v20 = 0;
  v21 = 8;
  v22 = 80;
  v23 = 16;
  v12 = 0;
  v13 = 0;
  v14 = 80;
  v15 = 80;
  v16 = 112;
  v17 = 24;
  v18 = 120;
  v19 = 32;
  v4 = 104;
  v5 = 24;
  v6 = 112;
  v7 = 32;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  v11 = 0;
  PutBitmap3((RECT *)a1, 6 * ranking_3 + 38, 40, (RECT *)&v4 + ((signed int)(unsigned __int8)ranking_2 >> 2) % 2, 11);
  PutBitmap3(
    (RECT *)a1,
    8 * ranking_0 + 20,
    8 * ranking_4 + 64,
    (RECT *)&v4 + ((signed int)(unsigned __int8)ranking_2 >> 2) % 2,
    11);
  PutBitmap3((RECT *)a1, 20, 8, (RECT *)&v20, 11);
  PutBitmap3((RECT *)a1, 90, 24, (RECT *)&v16, 11);
  v2 = GetScore();
  PutNumber(a1, 54, 24, v2, 6, 0);
  PutTextObject(a1, 38, 40, a2, 0, 0);
  return PutBitmap3((RECT *)a1, 20, 64, (RECT *)&v12, 9);
}

