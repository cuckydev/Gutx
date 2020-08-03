



void ClearLoopSound()
{
  loopsoundplaying_ = 0;
  loopsound_ = 0;
}




int StopLoopSound2()
{
  int result; 

  if ( loopsoundplaying_ )
  {
    result = stoploopsoundproc_(loopsound_);
    loopsoundplaying_ = 0;
    loopsound_ = 0;
  }
  return result;
}




BOOL LoadSound(int a1, int a2)
{
  int v3; 
  char v4; 
  int v5; 
  int v6; 

  sprintf(&v4, "%s\\%s.%s", dataPath, a1, Ptnoisesuffix);
  pxtone_GetQuality(&v6, &v3, &v5, 0);
  return sub_424EF0(&v4, 0, v6, v3, v5, a2) != 0;
}




int PlaySound(int a1)
{
  int result; 

  if ( !soundDisabled )
    result = sub_425250(a1);
  return result;
}



int PlayLoopSound(signed int a1)
{
  int result; 

  result = startloopsoundproc_(a1);
  loopsoundplaying_ = 1;
  loopsound_ = a1;
  return result;
}




int StopLoopSound(int a1)
{
  int result; 

  result = stoploopsoundproc_(a1);
  loopsoundplaying_ = 0;
  loopsound_ = 0;
  return result;
}




int PauseLoopSound()
{
  int result; 

  if ( loopsoundplaying_ )
    result = stoploopsoundproc_(loopsound_);
  return result;
}




int ResumeLoopSound()
{
  int result; 

  if ( loopsoundplaying_ )
    result = startloopsoundproc_(loopsound_);
  return result;
}




int SetSoundDisabled(int a1)
{
  int result; 

  result = a1;
  soundDisabled = a1;
  return result;
}

