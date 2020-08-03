int gScore; 
int LivesIncreaseCount; 
int StageScroll; 
int StageScrollSpeed; 


signed int LoadPximgSymbol()
{
  LoadPximg((int)"symbol", 11);
  gScore = 0;
  LivesIncreaseCount = 0;
  return 1;
}




signed int ResetScore()
{
  gScore = 0;
  LivesIncreaseCount = 0;
  return 1;
}




int GetScore()
{
  return gScore;
}



int SetScore(int a1)
{
  int result; 

  result = a1;
  gScore = a1;
  return result;
}



int AddScore(int a1)
{
  int result; 

  gScore += ScoreTbl[a1];
  result = GetInScoreAttack();
  if ( !result )
  {
    result = gScore;
    if ( gScore >= LivesScoreThresholds[LivesIncreaseCount] )
    {
      ++LivesIncreaseCount;
      IncreaseLives();
      result = CreateCaret(3, 0, 0, 0);
    }
  }
  return result;
}






int PutScore(int a1, int x, int y)
{
  int v4; 
  int v5; 
  int v6; 
  int v7; 

  v4 = 112;
  v5 = 24;
  v6 = 120;
  v7 = 32;
  if ( gScore )
    PutNumber(a1, x, y, gScore, 6, 0);
  return PutRect(x + 36, y, (RECT *)&v4, 11);
}



int SetDefaultStageScroll()
{
  int result; 

  result = (16 * GetStageHeight() - (ScreenRenderHeight - scHOffset_0)) << 10;
  StageScroll = result;
  return result;
}





int SetStageScroll(int a1)
{
  int result; 

  result = a1 << 14;
  StageScroll = a1 << 14;
  return result;
}



int SetScrollSpeed(int a1)
{
  int result; 

  result = a1;
  StageScrollSpeed = a1;
  return result;
}



int SetStageXOffset(int a1)
{
  int result; 

  result = a1;
  StageXOffset = a1;
  return result;
}



int GetCheckpointScrollValue()
{
  return StageScroll / 1024 / 16;
}



int GetStageXOffset()
{
  return StageXOffset;
}



int GetStageScroll()
{
  return StageScroll;
}



int AlignStageScroll(NPCHAR *a1)
{
  int result; 

  a1->cond = StageXOffset;
  a1->y = StageXOffset + ((ScreenRenderWidth - scWOffset_0) << 10);
  a1->x = StageScroll;
  result = StageScroll + ((ScreenRenderHeight - scHOffset_0) << 10);
  a1->xm = result;
  return result;
}








int ActStageScroll()
{
  int result; 

  StageScroll += StageScrollSpeed;
  result = (16 * GetStageHeight() - (ScreenRenderHeight - scHOffset_0)) << 10;
  if ( StageScroll < 0 )
  {
    StageScroll = 0;
    if ( StageScrollSpeed < 0 )
      StageScrollSpeed = 0;
  }
  if ( StageScroll > result )
    StageScroll = result;
  return result;
}






_DWORD *AddStageXOScroll(_DWORD *a1, _DWORD *a2)
{
  _DWORD *result; 

  if ( a1 )
  {
    result = a1;
    *a1 += StageXOffset;
  }
  if ( a2 )
  {
    result = a2;
    *a2 += StageScroll;
  }
  return result;
}




_DWORD *SubStageXOScroll(_DWORD *a1, _DWORD *a2)
{
  _DWORD *result; 

  if ( a1 )
  {
    result = a1;
    *a1 -= StageXOffset;
  }
  if ( a2 )
  {
    result = a2;
    *a2 -= StageScroll;
  }
  return result;
}







int SetGameDelay(int a1)
{
  int result; 

  result = a1;
  GameDelay = a1;
  return result;
}



BOOL GetGameDelayed()
{
  if ( GameDelay && GameDelay != -1 )
    --GameDelay;
  return GameDelay != 0;
}


