

int ActBullet0(int a1)
{
  int v1; 
  int result; 

  switch ( *(_DWORD *)(a1 + 80) )
  {
    case 0:
      *(_DWORD *)(a1 + 16) = -8192;
      break;
    case 6:
      *(_DWORD *)(a1 + 12) = 6144;
      *(_DWORD *)(a1 + 16) = 6144;
      break;
    case 8:
      *(_DWORD *)(a1 + 16) = 0x2000;
      break;
    case 0xA:
      *(_DWORD *)(a1 + 12) = -6144;
      *(_DWORD *)(a1 + 16) = 6144;
      break;
    default:
      break;
  }
  *(_DWORD *)(a1 + 4) += *(_DWORD *)(a1 + 12);
  *(_DWORD *)(a1 + 8) += *(_DWORD *)(a1 + 16);
  v1 = a1 + 104;
  *(_DWORD *)v1 = 64;
  *(_DWORD *)(v1 + 4) = 0;
  *(_DWORD *)(v1 + 8) = 72;
  *(_DWORD *)(v1 + 12) = 8;
  *(_DWORD *)(a1 + 104) += 8 * (*(_DWORD *)(a1 + 80) % 8);
  result = *(_DWORD *)(a1 + 112);
  *(_DWORD *)(a1 + 112) = result + 8 * (*(_DWORD *)(a1 + 80) % 8);
  return result;
}


int ActBullet1(int a1)
{
  int v1; 
  int result; 

  switch ( *(_DWORD *)(a1 + 80) )
  {
    case 0:
      *(_DWORD *)(a1 + 16) = -6144;
      break;
    case 1:
      *(_DWORD *)(a1 + 16) = -5120;
      *(_DWORD *)(a1 + 12) = 3072;
      break;
    case 2:
      *(_DWORD *)(a1 + 16) = -4096;
      *(_DWORD *)(a1 + 12) = 4096;
      break;
    case 3:
      *(_DWORD *)(a1 + 16) = -3072;
      *(_DWORD *)(a1 + 12) = 5120;
      break;
    case 6:
      *(_DWORD *)(a1 + 12) = 4096;
      *(_DWORD *)(a1 + 16) = 4096;
      break;
    case 8:
      *(_DWORD *)(a1 + 16) = 6144;
      break;
    case 0xA:
      *(_DWORD *)(a1 + 12) = -4096;
      *(_DWORD *)(a1 + 16) = 4096;
      break;
    case 0xD:
      *(_DWORD *)(a1 + 16) = -3072;
      *(_DWORD *)(a1 + 12) = -5120;
      break;
    case 0xE:
      *(_DWORD *)(a1 + 16) = -4096;
      *(_DWORD *)(a1 + 12) = -4096;
      break;
    case 0xF:
      *(_DWORD *)(a1 + 16) = -5120;
      *(_DWORD *)(a1 + 12) = -3072;
      break;
    default:
      break;
  }
  switch ( *(_DWORD *)(a1 + 80) )
  {
    case 0:
    case 8:
      *(_DWORD *)(a1 + 28) = 0;
      *(_DWORD *)(a1 + 32) = 4096;
      break;
    case 4:
    case 0xC:
      *(_DWORD *)(a1 + 28) = 4096;
      *(_DWORD *)(a1 + 32) = 0;
      break;
    default:
      *(_DWORD *)(a1 + 28) = 2048;
      *(_DWORD *)(a1 + 32) = 2048;
      break;
  }
  *(_DWORD *)(a1 + 4) += *(_DWORD *)(a1 + 12);
  *(_DWORD *)(a1 + 8) += *(_DWORD *)(a1 + 16);
  v1 = a1 + 104;
  *(_DWORD *)v1 = 0;
  *(_DWORD *)(v1 + 4) = 8;
  *(_DWORD *)(v1 + 8) = 8;
  *(_DWORD *)(v1 + 12) = 16;
  *(_DWORD *)(a1 + 104) += 8 * (*(_DWORD *)(a1 + 80) % 8);
  result = *(_DWORD *)(a1 + 112);
  *(_DWORD *)(a1 + 112) = result + 8 * (*(_DWORD *)(a1 + 80) % 8);
  return result;
}


int ActBullet2(int a1)
{
  int v1; 
  int result; 

  switch ( *(_DWORD *)(a1 + 80) )
  {
    case 0:
      *(_DWORD *)(a1 + 16) = -6144;
      break;
    case 1:
      *(_DWORD *)(a1 + 16) = -5120;
      *(_DWORD *)(a1 + 12) = 3072;
      break;
    case 2:
      *(_DWORD *)(a1 + 16) = -4096;
      *(_DWORD *)(a1 + 12) = 4096;
      break;
    case 3:
      *(_DWORD *)(a1 + 16) = -3072;
      *(_DWORD *)(a1 + 12) = 5120;
      break;
    case 6:
      *(_DWORD *)(a1 + 12) = 4096;
      *(_DWORD *)(a1 + 16) = 4096;
      break;
    case 8:
      *(_DWORD *)(a1 + 16) = 6144;
      break;
    case 0xA:
      *(_DWORD *)(a1 + 12) = -4096;
      *(_DWORD *)(a1 + 16) = 4096;
      break;
    case 0xD:
      *(_DWORD *)(a1 + 16) = -3072;
      *(_DWORD *)(a1 + 12) = -5120;
      break;
    case 0xE:
      *(_DWORD *)(a1 + 16) = -4096;
      *(_DWORD *)(a1 + 12) = -4096;
      break;
    case 0xF:
      *(_DWORD *)(a1 + 16) = -5120;
      *(_DWORD *)(a1 + 12) = -3072;
      break;
    default:
      break;
  }
  *(_DWORD *)(a1 + 4) += *(_DWORD *)(a1 + 12);
  *(_DWORD *)(a1 + 8) += *(_DWORD *)(a1 + 16);
  v1 = a1 + 104;
  *(_DWORD *)v1 = 0;
  *(_DWORD *)(v1 + 4) = 16;
  *(_DWORD *)(v1 + 8) = 8;
  *(_DWORD *)(v1 + 12) = 24;
  *(_DWORD *)(a1 + 104) += 8 * (*(_DWORD *)(a1 + 80) % 16);
  result = *(_DWORD *)(a1 + 112) + 8 * (*(_DWORD *)(a1 + 80) % 16);
  *(_DWORD *)(a1 + 112) = result;
  return result;
}


int ActBullet3(int a1)
{
  int v1; 
  int v2; 
  int result; 
  int v4; 

  v1 = (*(_DWORD *)(a1 + 48))++;
  if ( v1 == 3 )
  {
    if ( *(_DWORD *)(a1 + 80) )
    {
      if ( *(_DWORD *)(a1 + 80) == 3 )
      {
        *(_DWORD *)(a1 + 4) += 3072;
        *(_DWORD *)(a1 + 8) += 2048;
      }
      else
      {
        *(_DWORD *)(a1 + 4) -= 2048;
        *(_DWORD *)(a1 + 8) += 2048;
      }
    }
    else
    {
      *(_DWORD *)(a1 + 4) = *(_DWORD *)(a1 + 4);
    }
    *(_DWORD *)(a1 + 80) = 0;
  }
  v4 = *(_DWORD *)(a1 + 80);
  if ( v4 )
  {
    if ( v4 == 3 )
    {
      *(_DWORD *)(a1 + 16) = -3072;
      *(_DWORD *)(a1 + 12) = 6144;
    }
    else if ( v4 == 13 )
    {
      *(_DWORD *)(a1 + 16) = -3072;
      *(_DWORD *)(a1 + 12) = -6144;
    }
  }
  else
  {
    *(_DWORD *)(a1 + 16) = -8192;
    *(_DWORD *)(a1 + 12) = 0;
  }
  switch ( *(_DWORD *)(a1 + 80) )
  {
    case 0:
    case 8:
      *(_DWORD *)(a1 + 28) = 0;
      *(_DWORD *)(a1 + 32) = 4096;
      break;
    case 4:
    case 0xC:
      *(_DWORD *)(a1 + 28) = 4096;
      *(_DWORD *)(a1 + 32) = 0;
      break;
    default:
      *(_DWORD *)(a1 + 28) = 2048;
      *(_DWORD *)(a1 + 32) = 2048;
      break;
  }
  *(_DWORD *)(a1 + 4) += *(_DWORD *)(a1 + 12);
  *(_DWORD *)(a1 + 8) += *(_DWORD *)(a1 + 16);
  v2 = a1 + 104;
  *(_DWORD *)v2 = 0;
  *(_DWORD *)(v2 + 4) = 24;
  *(_DWORD *)(v2 + 8) = 8;
  *(_DWORD *)(v2 + 12) = 32;
  *(_DWORD *)(a1 + 104) += 8 * (*(_DWORD *)(a1 + 80) % 8);
  result = *(_DWORD *)(a1 + 112) + 8 * (*(_DWORD *)(a1 + 80) % 8);
  *(_DWORD *)(a1 + 112) = result;
  return result;
}


Bullet *ActBullet4(Bullet *a1)
{
  Bullet *result; 

  if ( ++*(_DWORD *)&a1->gap2C[4] < 7 )
    CreateBullet(3, a1->x, a1->y, a1->_50, a1->_5C + 10, 10);
  result = a1;
  if ( *(_DWORD *)&a1->gap2C[4] >= 15 )
    a1->cond = 0;
  return result;
}


signed int ActBullet5(int a1)
{
  unsigned __int8 v1; 
  int v2; 
  signed int result; 
  int v4; 

  v4 = *(_DWORD *)(a1 + 44);
  if ( v4 )
  {
    if ( v4 != 10 )
      goto LABEL_9;
  }
  else
  {
    *(_DWORD *)(a1 + 44) = 10;
    *(_DWORD *)a1 |= 4u;
    if ( *(_DWORD *)(a1 + 80) )
      *(_DWORD *)(a1 + 84) = 128;
  }
  if ( *(_DWORD *)(a1 + 48) < 40 )
    ++*(_DWORD *)(a1 + 48);
  *(_DWORD *)(a1 + 84) += 8;
  *(_DWORD *)(a1 + 84) %= 256;
  v1 = *(_BYTE *)(a1 + 84);
  *(_DWORD *)(a1 + 4) = (char *)ShipX + *(_DWORD *)(a1 + 48) * GetCos(*(_BYTE *)(a1 + 84)) / 2;
  *(_DWORD *)(a1 + 8) = ShipY + *(_DWORD *)(a1 + 48) * GetSin(v1) / 2;
LABEL_9:
  *(_DWORD *)(a1 + 60) = 100;
  v2 = a1 + 104;
  *(_DWORD *)v2 = 104;
  *(_DWORD *)(v2 + 4) = 0;
  *(_DWORD *)(v2 + 8) = 112;
  result = 8;
  *(_DWORD *)(v2 + 12) = 8;
  return result;
}


int ActBullet6(int a1)
{
  int v1; 
  int result; 

  if ( !*(_DWORD *)(a1 + 44) )
  {
    v1 = a1 + 104;
    *(_DWORD *)v1 = 112;
    *(_DWORD *)(v1 + 4) = 0;
    *(_DWORD *)(v1 + 8) = 120;
    *(_DWORD *)(v1 + 12) = 8;
    *(_DWORD *)(a1 + 12) = 6 * GetCos(*(_BYTE *)(a1 + 80));
    *(_DWORD *)(a1 + 16) = 6 * GetSin(*(_BYTE *)(a1 + 80));
  }
  *(_DWORD *)(a1 + 4) += *(_DWORD *)(a1 + 12);
  result = a1;
  *(_DWORD *)(a1 + 8) += *(_DWORD *)(a1 + 16);
  return result;
}


signed int ActBullet7(int a1)
{
  signed int result; 
  int *v2; 
  int v3; 
  int v4; 
  int v5; 
  int v6; 
  int v7; 
  int v8; 
  int v9; 
  int v10; 

  v3 = 88;
  v4 = 0;
  v5 = 96;
  v6 = 16;
  v7 = 96;
  v8 = 0;
  v9 = 104;
  v10 = 16;
  if ( *(_DWORD *)a1 & 8 )
  {
    *(_DWORD *)a1 = 0;
    result = CreateBullet(8, *(_DWORD *)(a1 + 4), *(_DWORD *)(a1 + 8), 0, *(_DWORD *)(a1 + 92), 10);
  }
  else
  {
    *(_DWORD *)(a1 + 16) -= 256;
    *(_DWORD *)(a1 + 12) = 0;
    *(_DWORD *)(a1 + 4) += *(_DWORD *)(a1 + 12);
    *(_DWORD *)(a1 + 8) += *(_DWORD *)(a1 + 16);
    v2 = &v3 + 4 * (++*(_DWORD *)(a1 + 52) % 2);
    result = a1 + 104;
    *(_DWORD *)result = *v2;
    *(_DWORD *)(result + 4) = v2[1];
    *(_DWORD *)(result + 8) = v2[2];
    *(_DWORD *)(result + 12) = v2[3];
  }
  return result;
}


int ActBullet8(int a1)
{
  char *v1; 
  int result; 

  if ( *(_DWORD *)(a1 + 44) )
  {
    *(_DWORD *)(a1 + 64) = 0;
    if ( ++*(_DWORD *)(a1 + 52) > 5 )
      *(_DWORD *)a1 = 0;
  }
  else
  {
    ++*(_DWORD *)(a1 + 44);
    PlaySound(14);
  }
  v1 = (char *)&unk_43B3A0 + 16 * *(_DWORD *)(a1 + 52);
  result = a1 + 104;
  *(_DWORD *)result = *(_DWORD *)v1;
  *(_DWORD *)(result + 4) = *((_DWORD *)v1 + 1);
  *(_DWORD *)(result + 8) = *((_DWORD *)v1 + 2);
  *(_DWORD *)(result + 12) = *((_DWORD *)v1 + 3);
  return result;
}


int *GetBulletTbl()
{
  return BulletTbl;
}


void *ResetBullet()
{
  void *result; 
  signed int i; 

  result = memset(BulletTbl, 0, 0xF00u);
  for ( i = 0; i < 32; ++i )
    result = (void *)(i + 1);
  return result;
}


void *LoadPximgBullet()
{
  LoadPximg((int)"bullet", 2);
  return ResetBullet();
}


int ActBullet()
{
  int result; 
  signed int i; 
  Bullet *bul; 

  for ( i = 0; i < 32; ++i )
  {
    bul = (Bullet *)&BulletTbl[30 * i];
    if ( BulletTbl[30 * i] & 1 )
    {
      bulletFuncTbl[bul->type]((int)bul);
      if ( bul->cond & 2 )
        bul->cond &= 0xFFFFFFFE;
      if ( !(bul->cond & 4) && (bul->x < -8192 || bul->x > 0x20000 || bul->y < -8192 || bul->y > 172032) )
        bul->cond &= 0xFFFFFFFE;
    }
    result = i + 1;
  }
  return result;
}



int HitBulletMap()
{
  int result; 
  signed int i; 

  for ( i = 0; i < 32; ++i )
  {
    if ( BulletTbl[30 * i] & 1 )
      HitMapGeneric((NPCHAR *)&BulletTbl[30 * i], (int (*)(int, int, int, int))MapCollideBulletProc, 1);
    result = i + 1;
  }
  return result;
}


int MapCollideBulletProc(int a1)
{
  int result; 

  result = a1;
  if ( !(*(_DWORD *)a1 & 4) )
  {
    if ( *(_DWORD *)(a1 + 68) & 0x20 )
    {
      result = a1;
      *(_DWORD *)a1 |= 8u;
    }
    else
    {
      *(_DWORD *)a1 = 0;
      CreateCaret(2, *(_DWORD *)(a1 + 4), *(_DWORD *)(a1 + 8), 0);
      result = PlaySound(37);
    }
  }
  return result;
}


int PutBullet(int a1)
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
    PutObject(a1, (NPCHAR *)&BulletTbl[30 * i], v4, v3);
    result = i + 1;
  }
  return result;
}


int CountBullet(int a1)
{
  signed int i; 
  int v3; 

  v3 = 0;
  for ( i = 0; i < 32; ++i )
  {
    if ( BulletTbl[30 * i] & 1 )
    {
      if ( BulletTblType[30 * i] == a1 )
        ++v3;
    }
  }
  return v3;
}



signed int CreateBullet(int type, int x, int y, int a4, int a5, int max)
{
  signed int result; 
  Bullet *bul; 
  BulletAttr *bAttr; 
  signed int i; 

  if ( CountBullet(a5) < max )
  {
    for ( i = 0; i < 32 && BulletTbl[30 * i] & 1; ++i )
      ;
    if ( i == 32 )
    {
      result = 0;
    }
    else
    {
      bul = (Bullet *)&BulletTbl[30 * i];
      bAttr = (BulletAttr *)((char *)&BulletAttrTbl + 12 * type);
      memset(&BulletTbl[30 * i], 0, 0x78u);
      bul->_24 = 2;
      bul->type = type;
      bul->cond = 1;
      bul->flag = bAttr->flag | 4;
      bul->x = x;
      bul->y = y;
      bul->_50 = a4;
      bul->xoff = bAttr->xoff << 10;
      bul->yoff = bAttr->yoff << 10;
      bul->w = bAttr->w << 10;
      bul->h = bAttr->h << 10;
      bul->life = bAttr->life;
      bul->damage = bAttr->damage;
      bul->_5C = a5;
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
