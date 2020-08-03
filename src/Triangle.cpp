

__int16 gTanTbl[]; 
int gSinTbl[]; 

void InitTriangleTable()
{
  double v0; 
  float v1; 
  float v2; 
  signed int i; 
  signed int j; 

  for ( i = 0; i < 256; ++i )
    gSinTbl[i] = (unsigned __int64)(sin((double)i * 6.2832 / 256.0) * 1024.0);
  for ( j = 0; j < 33; ++j )
  {
    v0 = (double)j * 6.2831855 / 256.0;
    v1 = v0;
    CallReturnSin(v1);
    v2 = v0;
    CallReturnCos(v1);
    gTanTbl[j] = (unsigned __int64)(v2 / v0 * 8192.0);
  }
}




int GetSin(unsigned __int8 a1)
{
  return gSinTbl[a1];
}



int GetCos(unsigned __int8 a1)
{
  return gSinTbl[(a1 + 64) % 256];
}



char GetArktan(int x, int y, char a3)
{
  char a; 
  signed int xa; 
  signed int ya; 

  xa = -x;
  ya = -y;
  a = 0;
  if ( xa <= 0 )
  {
    if ( xa >= 0 )
    {
      if ( ya >= 0 )
      {
        if ( ya <= 0 )
          a = a3;
        else
          a = 64;
      }
      else
      {
        a = -64;
      }
    }
    else if ( ya <= 0 )
    {
      if ( ya >= 0 )
      {
        a = -128;
      }
      else if ( -xa <= -ya )
      {
        while ( (signed __int16)(-8192 * xa / -ya) > gTanTbl[(unsigned __int8)a] )
          ++a;
        a = -64 - a;
      }
      else
      {
        while ( (signed __int16)(-8192 * ya / -xa) > gTanTbl[(unsigned __int8)a] )
          ++a;
        a += -128;
      }
    }
    else if ( -xa <= ya )
    {
      while ( (signed __int16)(-8192 * xa / ya) > gTanTbl[(unsigned __int8)a] )
        ++a;
      a += 64;
    }
    else
    {
      while ( (signed __int16)((ya << 13) / -xa) > gTanTbl[(unsigned __int8)a] )
        ++a;
      a = -128 - a;
    }
  }
  else if ( ya <= 0 )
  {
    if ( ya >= 0 )
    {
      a = 0;
    }
    else if ( xa <= -ya )
    {
      while ( (signed __int16)((xa << 13) / -ya) > gTanTbl[(unsigned __int8)a] )
        ++a;
      a -= 64;
    }
    else
    {
      while ( (signed __int16)(-8192 * ya / xa) > gTanTbl[(unsigned __int8)a] )
        ++a;
      a = -a;
    }
  }
  else if ( xa <= ya )
  {
    while ( (signed __int16)((xa << 13) / ya) > gTanTbl[(unsigned __int8)a] )
      ++a;
    a = 64 - a;
  }
  else
  {
    while ( (signed __int16)((ya << 13) / xa) > gTanTbl[(unsigned __int8)a] )
      ++a;
  }
  return a;
}




void CallReturnCos(float a1)
{
  ReturnCos(a1);
}


double ReturnCos(float a1)
{
  return cos(a1);
}



void CallReturnSin(float a1)
{
  ReturnSin(a1);
}


double ReturnSin(float a1)
{
  return sin(a1);
}

