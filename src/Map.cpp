
int stageWidth; 
int stageHeight; 
int mapTilePtr; 
int pxAttrWidth; 
int pxAttrHeight; 
int pxAttrPtr; 

signed int ResetStage()
{
  memset12bytes(&stageWidth);
  memset12bytes(&pxAttrWidth);
  return 1;
}




int GetStageHeight()
{
  int result; 

  if ( mapTilePtr )
    result = stageHeight;
  else
    result = 0;
  return result;
}




int LoadStage(int a1)
{
  CHAR Name; 
  int v3; 
  char v4; 

  v3 = 0;
  sprintf(&Name, "%s\\map%d.pxmap", dataPath, a1);
  ReleaseStageAttr((int)&stageWidth);
  if ( OpenResource_(0, &Name, 0, (int)&v4) )
  {
    if ( LoadStageAttr((int)&stageWidth, (int)&v4) )
    {
      CloseResource_((int)&v4);
      sprintf(&Name, "%s\\parts%d.pxatrb", dataPath, a1);
      ReleaseStageAttr((int)&pxAttrWidth);
      if ( OpenResource_(0, &Name, 0, (int)&v4) )
      {
        if ( LoadStageAttr((int)&pxAttrWidth, (int)&v4) )
        {
          CloseResource_((int)&v4);
          sprintf(&Name, "parts%d", a1);
          ClearSurface(4);
          if ( LoadPximg((int)&Name, 4) )
            v3 = 1;
        }
      }
    }
  }
  if ( !v3 )
  {
    ReleaseStageAttr((int)&stageWidth);
    ReleaseStageAttr((int)&pxAttrWidth);
  }
  CloseResource_((int)&v4);
  return v3;
}




int PutMapParts(WindowAttr *window)
{
  __int64 w; 
  __int64 h; 
  int result; 
  int tilesY; 
  int tilesH; 
  int scroll; 
  int xoff; 
  signed int tile; 
  int j; 
  int i; 
  tagRECT rect; 

  xoff = GetStageXOffset() / 1024;
  scroll = GetStageScroll() / 1024;
  w = window->w - window->offsetw;
  tilesY = xoff / 16 + (((BYTE4(w) & 0xF) + (signed int)w) >> 4) + 2;
  h = window->h - window->offseth;
  tilesH = scroll / 16 + (((BYTE4(h) & 0xF) + (signed int)h) >> 4) + 2;
  result = stageWidth - 1;
  if ( tilesY > stageWidth - 1 )
    tilesY = stageWidth - 1;
  if ( tilesH > stageHeight - 1 )
  {
    result = stageHeight - 1;
    tilesH = stageHeight - 1;
  }
  for ( i = 0; i <= tilesH; ++i )
  {
    for ( j = 0; j <= tilesY; ++j )
    {
      tile = *(_BYTE *)(mapTilePtr + j + stageWidth * i);
      if ( (signed int)*(_BYTE *)(pxAttrPtr + tile % 16 + pxAttrWidth * (tile / 16)) < 8 )
      {
        rect.left = 16 * (tile % 16);
        rect.right = rect.left + 16;
        rect.top = 16 * (tile / 16);
        rect.bottom = 16 * (tile / 16) + 16;
        PutBitmap3((RECT *)window, 16 * j - xoff, 16 * i - scroll, &rect, 4);
      }
      result = j + 1;
    }
  }
  return result;
}







int PutMapParts2(int a1)
{
  __int64 v1; 
  __int64 v2; 
  int result; 
  int v4; 
  int v5; 
  int v6; 
  int v7; 
  signed int v8; 
  int j; 
  int i; 
  int v11; 
  int v12; 
  int v13; 
  int v14; 

  v7 = GetStageXOffset() / 1024;
  v6 = GetStageScroll() / 1024;
  v1 = *(_DWORD *)(a1 + 8) - *(_DWORD *)a1;
  v4 = v7 / 16 + (((BYTE4(v1) & 0xF) + (signed int)v1) >> 4) + 2;
  v2 = *(_DWORD *)(a1 + 12) - *(_DWORD *)(a1 + 4);
  v5 = v6 / 16 + (((BYTE4(v2) & 0xF) + (signed int)v2) >> 4) + 2;
  result = stageWidth - 1;
  if ( v4 > stageWidth - 1 )
    v4 = stageWidth - 1;
  if ( v5 > stageHeight - 1 )
  {
    result = stageHeight - 1;
    v5 = stageHeight - 1;
  }
  for ( i = 0; i <= v5; ++i )
  {
    for ( j = 0; j <= v4; ++j )
    {
      v8 = *(_BYTE *)(mapTilePtr + j + stageWidth * i);
      if ( (signed int)*(_BYTE *)(pxAttrPtr + v8 % 16 + pxAttrWidth * (v8 / 16)) >= 8 )
      {
        v11 = 16 * (v8 % 16);
        v13 = v11 + 16;
        v12 = 16 * (v8 / 16);
        v14 = 16 * (v8 / 16) + 16;
        PutBitmap3((RECT *)a1, 16 * j - v7, 16 * i - v6, (RECT *)&v11, 4);
      }
      result = j + 1;
    }
  }
  return result;
}







int GetTileAttr(int x, int y)
{
  int attr; 
  int index; 
  int index2; 

  if ( x >= 0 && y >= 0 )
  {
    index = x + y * stageWidth;
    if ( index < stageHeight * stageWidth )
    {
      index2 = *(_BYTE *)(index + mapTilePtr) % 16 + pxAttrWidth * (*(_BYTE *)(index + mapTilePtr) / 16);
      if ( index2 < pxAttrHeight * pxAttrWidth )
        attr = *(_BYTE *)(index2 + pxAttrPtr);
      else
        attr = 0;
    }
    else
    {
      attr = 0;
    }
  }
  else
  {
    attr = 0;
  }
  return attr;
}








int GetTile(int x, int y)
{
  int tile; 
  int v3; 

  if ( x >= 0 && y >= 0 )
  {
    tile = x + y * stageWidth;
    v3 = x + y * stageWidth;
    if ( v3 < stageHeight * stageWidth )
    {
      tile = *(_BYTE *)(v3 + mapTilePtr) - 1;
      *(_BYTE *)(v3 + mapTilePtr) = tile;
    }
  }
  return tile;
}


