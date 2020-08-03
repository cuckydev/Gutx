
ButtonConfig *ResetKeyboardConfig(ButtonConfig *a1)
{
  ButtonConfig *result; 

  a1->left = 37;
  a1->right = 39;
  a1->up = 38;
  result = a1;
  a1->down = 40;
  a1->shot = 17;
  a1->pause = 9;
  return result;
}


ButtonConfig *ResetJoystickConfig(ButtonConfig *a1)
{
  ButtonConfig *result; 

  result = a1;
  a1->joyShot = 0;
  a1->joyPause = 1;
  return result;
}


ButtonConfig *ResetButtonConfig(int a1)
{
  ResetKeyboardConfig((ButtonConfig *)a1);
  return ResetJoystickConfig((ButtonConfig *)a1);
}


int WriteButtonConfig(void *a1)
{
  char v2; 
  int v3; 
  FILE *v4; 

  v3 = 0;
  v4 = 0;
  sprintf(&v2, "%s\\%s", temp_guxtPath, ButtonConfigFile);
  v4 = fopen(&v2, "wb");
  if ( v4 && WriteToFile(a1, 8u, 1u, v4) == 1 )
    v3 = 1;
  if ( v4 )
    fclose(v4);
  return v3;
}



int ReadButtonConfig(void *a1)
{
  char v2; 
  int v3; 
  FILE *v4; 

  v3 = 0;
  v4 = 0;
  sprintf(&v2, "%s\\%s", temp_guxtPath, ButtonConfigFile);
  v4 = fopen(&v2, "rb");
  if ( v4 && ReadFromFile(a1, 8u, 1u, v4) == 1 )
    v3 = 1;
  if ( v4 )
    fclose(v4);
  return v3;
}



ButtonConfig *LoadButtonConfig()
{
  ButtonConfig *result; 

  result = (ButtonConfig *)ReadButtonConfig(&gKeyLeft);
  if ( !result )
    result = ResetButtonConfig((int)&gKeyLeft);
  return result;
}

