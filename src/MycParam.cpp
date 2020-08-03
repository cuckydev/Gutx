





int KillShip()
{
  int result; 

  result = PlaySound(25);
  ShipFlightTimer = 1;
  ShipState = 1000;
  ShipX = (HBITMAP)61440;
  ShipY = 327680;
  return result;
}



Ship *ShipStateEndingProc()
{
  Ship *result; 
  int v1; 

  result = (Ship *)&ShipCond;
  v1 = *(&ShipCond + 21);
  if ( v1 )
  {
    if ( v1 != 1 )
      return result;
  }
  else
  {
    result = (Ship *)(*(&ShipCond + 12))++;
    if ( (signed int)result < 290 )
      return result;
    *(&ShipCond + 21) = 1;
  }
  *(&ShipCond + 2) += 512;
  result = (Ship *)&ShipCond;
  if ( *(&ShipCond + 2) >= 136192 )
    *(&ShipCond + 21) = 2;
  return result;
}


int HitShipMap()
{
  int result; 

  result = ShipCond & 1;
  if ( ShipCond & 1 )
  {
    if ( !(ShipCond & 2) )
      result = HitMapGeneric((NPCHAR *)&ShipCond, (int (*)(int, int, int, int))MapCollideShipProc, 0);
  }
  return result;
}


NPCHAR *MapCollideShipProc(NPCHAR *a1, int a2, int a3, int a4)
{
  NPCHAR *result; 

  a1->x = a2;
  a1->y = a3;
  result = a1;
  a1->cond |= a4;
  if ( a1->y >= 163840 )
  {
    result = (NPCHAR *)(a1->cond & 0x40);
    if ( result )
    {
      ShipInvincibility = 50;
      CreateEntity(1, (int)ShipX, ShipY, 0);
      SetGameDelay(20);
      result = (NPCHAR *)ShipCrushProc();
    }
  }
  return result;
}



unsigned int PutPlayerExtra(int a1)
{
  RECT *sRect; 
  unsigned int result; 
  int *v3; 
  int v4; 
  int v5; 
  int v6; 
  int v7; 
  int v8; 
  int v9; 
  int v10; 
  int v11; 
  int v12; 
  int v13; 
  int v14; 
  int v15; 
  int v16; 
  int v17; 
  int v18; 
  int v19; 
  int v20; 
  int v21; 
  int v22; 
  int v23; 
  int v24; 
  int v25; 
  int v26; 
  int v27; 
  int v28; 
  int v29; 
  int v30; 
  int v31; 
  int v32; 
  int v33; 
  int v34; 
  int v35; 
  int v36; 
  int v37; 
  int v38; 
  int v39; 
  int v40; 
  int v41; 
  int v42; 
  int v43; 
  int a4; 
  int a3; 

  sRect = (RECT *)((char *)&shipRectTbl + 16 * ShipPowerup);
  ShipRectLeft = sRect->left;
  ShipRectTop = sRect->top;
  ShipRectRight = sRect->right;
  ShipRectBottom = sRect->bottom;
  if ( ShipInvincibility && ((signed int)(unsigned __int8)ShipIFrameFlash >> 1) % 2 )
  {
    ShipRectLeft += 24;
    ShipRectRight += 24;
  }
  a3 = GetStageXOffset() / 1024;
  a4 = GetStageScroll() / 1024;
  PutObject(a1, (NPCHAR *)&ShipCond, a3, a4);
  result = PutBitmap3(
             (RECT *)a1,
             (signed int)(ShipX - 1024) / 1024,
             (ShipY + 4096) / 1024,
             (RECT *)&unk_43C028 + ((signed int)(unsigned __int8)ShipThrusterFrame >> 1) % 2 + 2 * ShipSpeed,
             7);
  if ( ShipLife > 1 )
  {
    v8 = 0;
    v9 = 0;
    v10 = 24;
    v11 = 24;
    v12 = 24;
    v13 = 0;
    v14 = 48;
    v15 = 24;
    v16 = 48;
    v17 = 0;
    v18 = 72;
    v19 = 24;
    v20 = 72;
    v21 = 0;
    v22 = 96;
    v23 = 24;
    v24 = 96;
    v25 = 0;
    v26 = 120;
    v27 = 24;
    v28 = 120;
    v29 = 0;
    v30 = 144;
    v31 = 24;
    v32 = 144;
    v33 = 0;
    v34 = 168;
    v35 = 24;
    v36 = 168;
    v37 = 0;
    v38 = 192;
    v39 = 24;
    v3 = &v8 + 4 * (((signed int)(unsigned __int8)ShipThrusterFrame >> 1) % 8);
    v40 = *v3;
    v41 = v3[1];
    v42 = v3[2];
    v43 = v3[3];
    if ( ShipLife == 3 )
    {
      v41 += 24;
      v43 += 24;
    }
    result = PutBitmap3((RECT *)a1, (signed int)(ShipX - 3072) / 1024, (ShipY - 12288) / 1024, (RECT *)&v40, 1);
  }
  if ( ShipState == 100 && ShipPowerup == 9 )
  {
    result = fireHeldFrames / 2u;
    if ( fireHeldFrames % 2u )
    {
      v4 = 72;
      v5 = 0;
      v6 = 88;
      v7 = 16;
      result = PutBitmap3((RECT *)a1, (ShipXM - 0x2000) / 1024, (ShipYM - 0x2000) / 1024, (RECT *)&v4, 2);
    }
  }
  return result;
}
















int PutPlayer(int a1)
{
  int result; 

  result = ShipFlags & 0x100;
  if ( ShipFlags & 0x100 )
    result = PutBitmap3(
               (RECT *)a1,
               (signed int)(ShipX - 2048) / 1024,
               (ShipY - 4096) / 1024,
               (RECT *)&unk_43BF50 + ShipPowerup,
               0);
  return result;
}




signed int SetSpeedPowerUp()
{
  signed int result; 

  if ( ++ShipSpeed < 5 )
  {
    result = 1;
  }
  else
  {
    ShipSpeed = 1;
    result = 0;
  }
  return result;
}



signed int SetLifePowerUp()
{
  if ( ShipCond & 4 )
  {
    if ( ShipLife >= 2 )
      return 0;
    ++ShipLife;
  }
  else if ( ++ShipLife > 3 )
  {
    ShipLife = 1;
    ShipCond |= 4u;
    CreateBullet(5, (int)ShipX, ShipY, 0, 100, 1);
    CreateBullet(5, (int)ShipX, ShipY, 1, 101, 1);
  }
  return 1;
}



int SetSpeed(signed int a1)
{
  int result; 

  result = a1 / 5;
  ShipSpeed = a1 % 5;
  return result;
}



int SetPowerUp(int a1)
{
  int result; 

  result = a1;
  ShipPowerup = a1;
  return result;
}



void SetShipBoost()
{
  ShipState = 300;
  ShipFlightExiting = 0;
  ShipFlightTimer = 0;
}




int SetLife(int a1)
{
  int result; 

  result = a1;
  ShipLife = a1;
  return result;
}



void SetShipInvincibility()
{
  ShipInvincibility = 60000;
}



void SetShipEnding()
{
  ShipState = 900;
  ShipFlightTimer = 0;
  ShipFlightExiting = 0;
  ShipX = (HBITMAP)61440;
  ShipY = 81920;
  ShipInvincibility = 0;
}


