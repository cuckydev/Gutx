
int randomSeed1; 
int randomSeed2; 

void ResetRandom()
{
  randomSeed1 = 17476;
  randomSeed2 = 34952;
}




__int16 GetRandom(signed int max)
{
  unsigned __int16 v2; 
  int v3; 

  v3 = randomSeed2 + (signed __int16)randomSeed1;
  LOBYTE(v2) = BYTE1(v3);
  HIBYTE(v2) = randomSeed2 + randomSeed1;
  randomSeed2 = (signed __int16)randomSeed1;
  randomSeed1 = (signed __int16)v2;
  return v2 % max;
}

