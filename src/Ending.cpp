

void *LoadPximgEnemyName()
{
  void *result; 

  LoadPximg((int)"enemy_name", 25);
  result = memset(&EndingTextOnscreen, 0, 0x18u);
  EndingTextCount = -1;
  return result;
}




void *UnusedResetEndingText()
{
  void *result; 

  result = memset(&EndingTextOnscreen, 0, 0x18u);
  EndingTextCount = -1;
  return result;
}




int ShowNextEndingText()
{
  int result; 

  EndingTextOnscreen = 1;
  ++EndingTextCount;
  EndingTextTimer = 0;
  EndingTextUnused = 0;
  EndingTextX = EndingTextXTbl[2 * EndingTextCount] << 10;
  result = EndingTextCount;
  EndingTextY = EndingTextYTbl[2 * EndingTextCount] << 10;
  return result;
}










int EndingTextRunTimer()
{
  int result; 

  if ( EndingTextOnscreen )
  {
    result = EndingTextTimer++ + 1;
    if ( EndingTextTimer > 100 )
      EndingTextOnscreen = 0;
  }
  return result;
}




void PutEndingText()
{
  int v0; 
  int v1; 
  int v2; 
  int v3; 

  if ( EndingTextOnscreen )
  {
    v0 = EndingTextCount / 16 << 6;
    v1 = 8 * (EndingTextCount % 16);
    v2 = v0 + 64;
    v3 = v1 + 8;
    PutBitmap3((RECT *)&scWOffset_0, EndingTextX / 1024 - 32, EndingTextY / 1024 - 4, (RECT *)&v0, 25);
  }
}







BOOL CheckEndingTextCount()
{
  return EndingTextCount >= 25;
}


