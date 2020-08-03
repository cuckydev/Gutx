


int LoadMusic(int a1)
{
  int v2; 
  int v3; 
  int v4; 
  int v5; 

  pxtone_Tune_Stop(v2, v3, v4, v5);
  isMusicPlaying = 0;
  sprintf((char *)&v2, "%s\\%s.%s", dataPath, a1, ptcopSuffix[0]);
  return pxtone_Tune_Load(0, 0, &v2);
}






signed int StartMusic(int a1)
{
  signed int result; 

  isMusicPlaying = 0;
  if ( pxtone_Tune_Start(a1, 0) )
  {
    isMusicPlaying = 1;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}




int SetMusicVolume(int a1)
{
  isMusicPlaying = 0;
  return pxtone_Tune_Fadeout(a1);
}




void FadeMusic()
{
  if ( isMusicPlaying )
    pxtoneFadeReturnValue = pxtone_Tune_Fadeout(200);
}





int ResumeMusic()
{
  int result; 

  if ( isMusicPlaying )
    result = pxtone_Tune_Start(pxtoneFadeReturnValue, 200);
  return result;
}



