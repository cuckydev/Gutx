

int Fade_state; 
int Fade_wState; 
int Fade_wCount; 
int Fade_wX; 
int Fade_unused; 
int Fade_left; 
int Fade_top; 
int Fade_right; 
int Fade_bottom; 
int Fade_wLeft2; 
int Fade_wTop2; 
int Fade_wRight2; 
int Fade_wBottom2; 
int Fade_wLeft; 
int Fade_wTop; 
int Fade_wRight; 
int Fade_wBottom; 
int Fade_wColor; 
int Fade_color; 


signed int LoadPximgScreenEffect()
{
  signed int result; 

  LoadPximg((int)"screen_effect", 12);
  Fade_color = GetSurfaceColor(16);
  result = GetSurfaceColor(20);
  Fade_wColor = result;
  return result;
}




void *EndingInitFade()
{
  return memset(&Fade_state, 0, 0x44u);
}



void ResetFade()
{
  Fade_wState = 0;
  Fade_state = 10;
  Fade_left = 0;
  Fade_right = 120;
  Fade_top = 0;
  Fade_bottom = 168;
}








void SetFadeActive()
{
  Fade_state = 20;
  Fade_left = 0;
  Fade_right = 120;
  Fade_top = 168;
  Fade_bottom = 160;
}







BOOL CheckFadeEnd()
{
  return Fade_state == 30;
}



int SetFadeWhiteActive(int a1, int a2)
{
  int result; 

  Fade_wState = 10;
  Fade_wCount = 0;
  Fade_wLeft2 = 0;
  Fade_wRight2 = 120;
  Fade_wTop2 = a2;
  Fade_wBottom2 = a2;
  Fade_wLeft = a1;
  result = a1;
  Fade_wRight = a1;
  Fade_wTop = 0;
  Fade_wBottom = 160;
  Fade_wX = a1;
  Fade_unused = a2;
  return result;
}














BOOL CheckFadeWhiteEnd()
{
  return Fade_wState == 20;
}



void RecordEndFadeWhite()
{
  Fade_wState = 0;
}



int ActFade()
{
  int result; 
  signed int v1; 
  signed int v2; 

  if ( Fade_state == 10 )
  {
    if ( Fade_bottom < 0 )
      Fade_state = 0;
    else
      Fade_bottom -= 8;
  }
  else if ( Fade_state == 20 )
  {
    Fade_top -= 8;
    if ( Fade_top < 0 )
    {
      Fade_top = 0;
      Fade_state = 30;
    }
  }
  result = Fade_wState;
  if ( Fade_wState != 10 )
  {
    if ( Fade_wState != 20 )
      return result;
    goto LABEL_23;
  }
  Fade_wTop2 -= Fade_wCount;
  Fade_wBottom2 += Fade_wCount;
  Fade_wLeft -= Fade_wCount;
  Fade_wRight += Fade_wCount;
  if ( Fade_wTop2 < 0 )
    Fade_wTop2 = 0;
  if ( Fade_wBottom2 > 160 )
    Fade_wBottom2 = 160;
  if ( Fade_wLeft < 0 )
    Fade_wLeft2 = 0;
  if ( Fade_wRight > 120 )
    Fade_wRight2 = 120;
  v1 = Fade_wCount;
  result = Fade_wCount++ + 1;
  if ( v1 >= 80 )
  {
    Fade_wState = 20;
    Fade_wCount = 1;
    Fade_wLeft2 = Fade_wX - 120;
    Fade_wRight2 = Fade_wX + 120;
    Fade_wLeft = 0;
    Fade_wRight = 0;
LABEL_23:
    Fade_wLeft2 = Fade_wX - 120 / (3 * Fade_wCount);
    Fade_wRight2 = Fade_wX + 120 / (3 * Fade_wCount);
    if ( Fade_wLeft2 < 0 )
      Fade_wLeft2 = 0;
    if ( Fade_wRight2 > 120 )
      Fade_wRight2 = 120;
    v2 = Fade_wCount;
    result = Fade_wCount++ + 1;
    if ( v2 > 24 )
      Fade_wState = 0;
  }
  return result;
}














int PutFade(int a1)
{
  int result; 
  int v2; 
  int v3; 
  int v4; 
  int v5; 
  int v6; 
  int v7; 
  int v8; 
  int v9; 

  v2 = 0;
  v3 = 0;
  v4 = 120;
  v5 = 8;
  v6 = 0;
  v7 = 8;
  v8 = 120;
  v9 = 16;
  if ( Fade_wState )
  {
    sub_424150(a1, (int)&Fade_wLeft2, Fade_wColor);
    result = sub_424150(a1, (int)&Fade_wLeft, Fade_wColor);
  }
  switch ( Fade_state )
  {
    case 10:
      sub_424150(a1, (int)&Fade_left, Fade_color);
      result = PutBitmap3((RECT *)a1, 0, Fade_bottom, (RECT *)&v2, 12);
      break;
    case 20:
      sub_424150(a1, (int)&Fade_left, Fade_color);
      result = PutBitmap3((RECT *)a1, 0, Fade_top - 8, (RECT *)&v6, 12);
      break;
    case 30:
      result = sub_424150(a1, (int)&Fade_left, Fade_color);
      break;
  }
  return result;
}




