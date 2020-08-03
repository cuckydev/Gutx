
int PrepPxeve()
{
  int result; 
  PxEveEntity *v1; 
  int v2; 
  int v3; 
  int v4; 
  int v5; 
  int v6; 
  int v7; 
  PxEveEntity *v8; 
  int i; 
  int j; 
  int k; 

  if ( EntityStageTotal && EntityStagePtr )
  {
    result = EntityStageTotal - 1;
    for ( i = EntityStageTotal - 1; i; --i )
    {
      for ( j = 0; j < i; ++j )
      {
        result = *(_DWORD *)(EntityStagePtr + 24 * j + 4);
        if ( result < *(_DWORD *)(EntityStagePtr + 24 * (j + 1) + 4) )
        {
          v1 = (PxEveEntity *)(EntityStagePtr + 24 * j);
          v2 = v1->unused;
          v3 = v1->x;
          v4 = v1->y;
          v5 = v1->type;
          v6 = v1->type2;
          v7 = v1->count;
          *(_BYTE (*)[24])(EntityStagePtr + 24 * j) = *(_BYTE (*)[24])(EntityStagePtr + 24 * (j + 1));
          v8 = (PxEveEntity *)(EntityStagePtr + 24 * (j + 1));
          v8->unused = v2;
          v8->x = v3;
          v8->y = v4;
          v8->type = v5;
          result = v6;
          v8->type2 = v6;
          v8->count = v7;
        }
      }
    }
    for ( k = 0; k < EntityStageTotal; ++k )
    {
      *(_DWORD *)(EntityStagePtr + 24 * k + 20) = k;
      result = k + 1;
    }
  }
  return result;
}




signed int ResetEntityStageTotal()
{
  memset8bytes((unsigned int)&EntityStageTotal);
  return 1;
}



int LoadPxeve(int a1)
{
  CHAR Name; 
  int v3; 
  char v4; 

  v3 = 0;
  sprintf(&Name, "%s\\event%d.pxeve", dataPath, a1);
  ReleaseEntities(&EntityStageTotal);
  if ( OpenResource_(0, &Name, 0, (int)&v4) )
  {
    if ( ReadPxeve((int)&EntityStageTotal, (int)&v4) )
    {
      PrepPxeve();
      sprintf(&Name, "enemy%d", a1);
      ClearSurface(6);
      if ( LoadPximg((int)&Name, 6) )
        v3 = 1;
    }
  }
  CloseResource_((int)&v4);
  if ( !v3 )
    ReleaseEntities(&EntityStageTotal);
  return v3;
}



BOOL LoadPximgEnemy(int a1)
{
  char v2; 

  sprintf(&v2, "enemy%d", a1);
  ClearSurface(6);
  return LoadPximg((int)&v2, 6) != 0;
}


void ZeroEntityCount()
{
  EntityStageCount = 0;
}



signed int SetStageEntities()
{
  signed int result; 
  int v1; 
  int x; 
  int y; 
  int v4; 
  int v5; 
  PxEveEntity *v6; 

  if ( EntityStageTotal && EntityStagePtr )
  {
    v4 = GetStageScroll();
    v5 = GetStageXOffset();
    v1 = v4 / 1024 / 8 - 1;
    while ( EntityStageCount < EntityStageTotal && *(_DWORD *)(EntityStagePtr + 24 * EntityStageCount + 4) >= v1 )
    {
      v6 = (PxEveEntity *)(EntityStagePtr + 24 * EntityStageCount);
      x = (8 * *(_DWORD *)(EntityStagePtr + 24 * EntityStageCount) + 8) << 10;
      y = (8 * *(_DWORD *)(EntityStagePtr + 24 * EntityStageCount + 4) + 8) << 10;
      SubStageXOScroll(&x, &y);
      CreateEntity(v6->type, x, y, v6->type2);
      ++EntityStageCount;
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}





signed int SetStageEntitiesPartial()
{
  signed int result; 
  int v1; 
  PxEveEntity *v2; 

  if ( EntityStageTotal && EntityStagePtr )
  {
    v1 = GetStageScroll();
    GetStageXOffset();
    while ( EntityStageCount < EntityStageTotal
         && *(_DWORD *)(EntityStagePtr + 24 * EntityStageCount + 4) >= v1 / 1024 / 8 - 1 )
    {
      v2 = (PxEveEntity *)(EntityStagePtr + 24 * EntityStageCount);
      if ( *(_DWORD *)(EntityStagePtr + 24 * EntityStageCount + 12) == 19
        || v2->type == 22
        || v2->type == 6
        || v2->type == 38 )
      {
        CreateEntity(v2->type, 0, 0, v2->type2);
      }
      ++EntityStageCount;
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

