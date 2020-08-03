

int ActCaret00(int a1)
{
  int result; 
  int v2; 

  if ( !*(_DWORD *)(a1 + 56) )
    *(_DWORD *)(a1 + 8) += 4096;
  result = a1;
  if ( ++*(_DWORD *)(a1 + 56) <= 65 )
  {
    if ( *(_DWORD *)(a1 + 56) < 24 )
      *(_DWORD *)(a1 + 8) -= 256;
    v2 = a1 + 104;
    *(_DWORD *)v2 = 0;
    *(_DWORD *)(v2 + 4) = 0;
    *(_DWORD *)(v2 + 8) = 32;
    *(_DWORD *)(v2 + 12) = 8;
    *(_DWORD *)(a1 + 104) += 32 * (*(_DWORD *)(a1 + 80) / 8);
    *(_DWORD *)(a1 + 112) += 32 * (*(_DWORD *)(a1 + 80) / 8);
    *(_DWORD *)(a1 + 108) += 8 * (*(_DWORD *)(a1 + 80) % 8);
    *(_DWORD *)(a1 + 116) += 8 * (*(_DWORD *)(a1 + 80) % 8);
    result = a1;
    if ( *(_DWORD *)(a1 + 56) > 50 )
    {
      result = *(_DWORD *)(a1 + 56) / 2 % 2;
      if ( result )
      {
        result = a1;
        *(_DWORD *)(a1 + 116) = *(_DWORD *)(a1 + 108);
      }
    }
  }
  else
  {
    *(_DWORD *)a1 = 0;
  }
  return result;
}


int ActCaret01(int a1)
{
  int result; 
  int *v2; 
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

  v5 = 0;
  v6 = 32;
  v7 = 24;
  v8 = 56;
  v9 = 24;
  v10 = 32;
  v11 = 48;
  v12 = 56;
  v13 = 48;
  v14 = 32;
  v15 = 72;
  v16 = 56;
  v17 = 72;
  v18 = 32;
  v19 = 96;
  v20 = 56;
  v21 = 96;
  v22 = 32;
  v23 = 120;
  v24 = 56;
  v25 = 120;
  v26 = 32;
  v27 = 144;
  v28 = 56;
  v29 = *(_DWORD *)(a1 + 80);
  v4 = *(_DWORD *)(a1 + 44);
  if ( v4 )
  {
    if ( v4 != 10 )
      goto LABEL_13;
  }
  else
  {
    if ( *(_DWORD *)(a1 + 80) )
    {
      if ( *(_DWORD *)(v29 + 68) & 0x10 )
        *(_DWORD *)(a1 + 68) |= 0x10u;
      *(_DWORD *)(a1 + 84) = *(_DWORD *)(a1 + 4) - *(_DWORD *)(v29 + 4);
      *(_DWORD *)(a1 + 88) = *(_DWORD *)(a1 + 8) - *(_DWORD *)(v29 + 8);
      *(_DWORD *)(a1 + 92) = *(_DWORD *)(v29 + 40);
    }
    *(_DWORD *)(a1 + 44) = 10;
  }
  if ( *(_DWORD *)(a1 + 80) )
  {
    *(_DWORD *)(a1 + 4) = *(_DWORD *)(a1 + 84) + *(_DWORD *)(v29 + 4);
    *(_DWORD *)(a1 + 8) = *(_DWORD *)(a1 + 88) + *(_DWORD *)(v29 + 8);
    if ( !(*(_DWORD *)v29 & 1) || *(_DWORD *)(v29 + 40) != *(_DWORD *)(a1 + 92) )
      *(_DWORD *)a1 = 0;
  }
LABEL_13:
  if ( ++*(_DWORD *)(a1 + 56) > 2 )
  {
    *(_DWORD *)(a1 + 56) = 0;
    ++*(_DWORD *)(a1 + 52);
  }
  result = a1;
  if ( *(_DWORD *)(a1 + 52) <= 5 )
  {
    v2 = &v5 + 4 * *(_DWORD *)(a1 + 52);
    v3 = a1 + 104;
    *(_DWORD *)v3 = *v2;
    *(_DWORD *)(v3 + 4) = v2[1];
    result = v2[2];
    *(_DWORD *)(v3 + 8) = result;
    *(_DWORD *)(v3 + 12) = v2[3];
  }
  else
  {
    *(_DWORD *)a1 = 0;
  }
  return result;
}


int ActCaret02(int a1)
{
  int result; 
  int *v2; 
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
  int v14; 
  int v15; 
  int v16; 
  int v17; 
  int v18; 
  int v19; 

  v4 = 144;
  v5 = 48;
  v6 = 152;
  v7 = 56;
  v8 = 152;
  v9 = 48;
  v10 = 160;
  v11 = 56;
  v12 = 160;
  v13 = 48;
  v14 = 168;
  v15 = 56;
  v16 = 168;
  v17 = 48;
  v18 = 176;
  v19 = 56;
  if ( ++*(_DWORD *)(a1 + 56) > 2 )
  {
    *(_DWORD *)(a1 + 56) = 0;
    ++*(_DWORD *)(a1 + 52);
  }
  if ( *(_DWORD *)(a1 + 52) <= 3 )
  {
    v2 = &v4 + 4 * *(_DWORD *)(a1 + 52);
    v3 = a1 + 104;
    *(_DWORD *)v3 = *v2;
    *(_DWORD *)(v3 + 4) = v2[1];
    *(_DWORD *)(v3 + 8) = v2[2];
    result = v2[3];
    *(_DWORD *)(v3 + 12) = result;
  }
  else
  {
    result = a1;
    *(_DWORD *)a1 = 0;
  }
  return result;
}


int ActCaret03(int a1)
{
  int result; 
  int *v2; 
  int v3; 
  __int64 v4; 
  int v5; 
  int v6; 
  int v7; 
  int v8; 
  int v9; 
  int v10; 
  int v11; 
  int v12; 

  v5 = 80;
  v6 = 8;
  v7 = 112;
  v8 = 16;
  v9 = 0;
  v10 = 80;
  v11 = 72;
  v12 = 88;
  *(_DWORD *)(a1 + 4) = 61440;
  *(_DWORD *)(a1 + 8) = (8 * *(_DWORD *)(a1 + 80) + 40) << 10;
  if ( ++*(_DWORD *)(a1 + 56) <= 100 )
  {
    v2 = &v5 + 4 * *(_DWORD *)(a1 + 80);
    v3 = a1 + 104;
    *(_DWORD *)v3 = *v2;
    *(_DWORD *)(v3 + 4) = v2[1];
    *(_DWORD *)(v3 + 8) = v2[2];
    *(_DWORD *)(v3 + 12) = v2[3];
    v4 = *(_DWORD *)(a1 + 112) - *(_DWORD *)(a1 + 104);
    result = ((signed int)v4 - HIDWORD(v4)) >> 1 << 10;
    *(_DWORD *)(a1 + 20) = result;
    if ( *(_DWORD *)(a1 + 56) > 85 )
    {
      result = *(_DWORD *)(a1 + 56) / 2 % 2;
      if ( result )
      {
        result = *(_DWORD *)(a1 + 108);
        *(_DWORD *)(a1 + 116) = result;
      }
    }
  }
  else
  {
    result = a1;
    *(_DWORD *)a1 = 0;
  }
  return result;
}


int ActCaret04(int a1)
{
  int result; 
  int *v2; 
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

  v5 = 0;
  v6 = 80;
  v7 = 40;
  v8 = 120;
  v9 = 40;
  v10 = 80;
  v11 = 80;
  v12 = 120;
  v13 = 80;
  v14 = 80;
  v15 = 120;
  v16 = 120;
  v17 = 0;
  v18 = 120;
  v19 = 40;
  v20 = 160;
  v21 = 40;
  v22 = 120;
  v23 = 80;
  v24 = 160;
  v25 = 80;
  v26 = 120;
  v27 = 120;
  v28 = 160;
  v29 = *(_DWORD *)(a1 + 80);
  v4 = *(_DWORD *)(a1 + 44);
  if ( v4 )
  {
    if ( v4 != 10 )
      goto LABEL_16;
  }
  else
  {
    if ( *(_DWORD *)(a1 + 80) )
    {
      if ( *(_DWORD *)(v29 + 68) & 0x10 )
      {
        *(_DWORD *)(a1 + 68) |= 0x10u;
      }
      else
      {
        *(_DWORD *)(a1 + 84) = *(_DWORD *)(a1 + 4) - *(_DWORD *)(v29 + 4);
        *(_DWORD *)(a1 + 88) = *(_DWORD *)(a1 + 8) - *(_DWORD *)(v29 + 8);
      }
      *(_DWORD *)(a1 + 92) = *(_DWORD *)(v29 + 40);
    }
    *(_DWORD *)(a1 + 44) = 10;
  }
  if ( *(_DWORD *)(a1 + 80) )
  {
    if ( !(*(_DWORD *)(v29 + 68) & 0x10) )
    {
      *(_DWORD *)(a1 + 4) = *(_DWORD *)(a1 + 84) + *(_DWORD *)(v29 + 4);
      *(_DWORD *)(a1 + 8) = *(_DWORD *)(a1 + 88) + *(_DWORD *)(v29 + 8);
    }
    if ( !(*(_DWORD *)v29 & 1) || *(_DWORD *)(v29 + 40) != *(_DWORD *)(a1 + 92) )
      *(_DWORD *)a1 = 0;
  }
LABEL_16:
  if ( ++*(_DWORD *)(a1 + 56) > 2 )
  {
    *(_DWORD *)(a1 + 56) = 0;
    ++*(_DWORD *)(a1 + 52);
  }
  if ( *(_DWORD *)(a1 + 52) <= 5 )
  {
    v2 = &v5 + 4 * *(_DWORD *)(a1 + 52);
    v3 = a1 + 104;
    *(_DWORD *)v3 = *v2;
    *(_DWORD *)(v3 + 4) = v2[1];
    *(_DWORD *)(v3 + 8) = v2[2];
    result = v2[3];
    *(_DWORD *)(v3 + 12) = result;
  }
  else
  {
    result = a1;
    *(_DWORD *)a1 = 0;
  }
  return result;
}


int ActCaret05(int a1)
{
  int result; 
  int v2; 

  ++*(_DWORD *)(a1 + 48);
  result = a1;
  if ( *(_DWORD *)(a1 + 48) <= 70 )
  {
    v2 = a1 + 104;
    *(_DWORD *)v2 = 48;
    *(_DWORD *)(v2 + 4) = 56;
    *(_DWORD *)(v2 + 8) = 72;
    *(_DWORD *)(v2 + 12) = 80;
    result = ++*(_DWORD *)(a1 + 56) % 2;
    if ( result )
    {
      result = *(_DWORD *)(a1 + 104);
      *(_DWORD *)(a1 + 112) = result;
    }
  }
  else
  {
    *(_DWORD *)a1 = 0;
  }
  return result;
}


int ActCaret06(int a1)
{
  int *v1; 
  int v2; 
  int result; 
  int v4; 
  int v5; 
  int v6; 
  int v7; 
  int v8; 
  int v9; 
  int v10; 
  int v11; 

  v4 = 72;
  v5 = 56;
  v6 = 88;
  v7 = 72;
  v8 = 104;
  v9 = 56;
  v10 = 120;
  v11 = 72;
  if ( !*(_DWORD *)(a1 + 48) )
  {
    *(_DWORD *)(a1 + 84) = (unsigned __int8)byte_443B58;
    byte_443B58 = ((unsigned __int8)byte_443B58 + 1) % 2;
  }
  if ( *(_DWORD *)(a1 + 48) > 1 )
    *(_DWORD *)a1 = 0;
  v1 = &v4 + 4 * *(_DWORD *)(a1 + 84);
  v2 = a1 + 104;
  *(_DWORD *)v2 = *v1;
  *(_DWORD *)(v2 + 4) = v1[1];
  *(_DWORD *)(v2 + 8) = v1[2];
  *(_DWORD *)(v2 + 12) = v1[3];
  *(_DWORD *)(a1 + 104) += 16 * *(_DWORD *)(a1 + 48);
  *(_DWORD *)(a1 + 112) += 16 * *(_DWORD *)(a1 + 48);
  result = *(_DWORD *)(a1 + 48) + 1;
  *(_DWORD *)(a1 + 48) = result;
  return result;
}



int ActCaret07(int a1)
{
  int result; 
  int v2; 

  result = a1;
  if ( *(_DWORD *)(a1 + 48) <= 3 )
  {
    v2 = a1 + 104;
    *(_DWORD *)v2 = 72;
    *(_DWORD *)(v2 + 4) = 72;
    *(_DWORD *)(v2 + 8) = 80;
    *(_DWORD *)(v2 + 12) = 80;
    *(_DWORD *)(a1 + 104) += 8 * *(_DWORD *)(a1 + 48);
    *(_DWORD *)(a1 + 112) += 8 * *(_DWORD *)(a1 + 48);
    result = *(_DWORD *)(a1 + 48) + 1;
    *(_DWORD *)(a1 + 48) = result;
  }
  else
  {
    *(_DWORD *)a1 = 0;
  }
  return result;
}


void *ResetCaret()
{
  void *result; 
  signed int i; 

  result = memset(CaretTbl, 0, 0xF00u);
  for ( i = 0; i < 32; ++i )
    result = (void *)(i + 1);
  return result;
}



int ActCaret()
{
  int result; 
  signed int i; 

  for ( i = 0; i < 32; ++i )
  {
    if ( CaretTbl[30 * i] & 1 )
      CaretFuncTbl[CaretTbl[30 * i + 10]]((int)&CaretTbl[30 * i]);
    result = i + 1;
  }
  return result;
}




int PutCaret(int a1)
{
  int result; 
  signed int i; 
  int v3; 
  int v4; 

  v4 = GetStageXOffset() / 1024;
  result = GetStageScroll() / 1024;
  v3 = result;
  for ( i = 0; i < 32; ++i )
  {
    PutObject(a1, (NPCHAR *)&CaretTbl[30 * i], v4, v3);
    result = i + 1;
  }
  return result;
}



int CreateCaret(int type, int x, int y, int param)
{
  int result; 
  Caret *c; 
  CaretAttr *cAttr; 
  signed int i; 

  for ( i = 0; i < 32 && CaretTbl[30 * i] & 1; ++i )
    ;
  if ( i == 32 )
  {
    result = 0;
  }
  else
  {
    c = (Caret *)&CaretTbl[30 * i];
    cAttr = (CaretAttr *)((char *)&CaretAttrTbl + 3 * type);
    memset(&CaretTbl[30 * i], 0, 0x78u);
    c->dword24 = cAttr->byte2;
    c->type = type;
    c->cond = 1;
    c->x = x;
    c->y = y;
    c->param = param;
    c->dword14 = cAttr->byte0 << 10;
    c->dword18 = cAttr->byte1 << 10;
    result = 1;
  }
  return result;
}



int UnusedGetCaretTableNext()
{
  signed int i; 
  int v2; 

  v2 = 0;
  for ( i = 0; i < 32; ++i )
  {
    if ( CaretTbl[30 * i] & 1 )
      ++v2;
  }
  return v2;
}

