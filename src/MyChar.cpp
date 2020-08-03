

int ShipSpeedTableDiag[]; 
int speedDiagonal1; 
int speedDiagonal2; 
int speedDiagonal3; 
int speedDiagonal4; 
int ShipSpeedTable[]; 
int speed1; 
int speed2; 
int speed3; 
int speed4; 
int ShipSpeed; 
int ShipCond;
HBITMAP ShipX; 
int ShipY; 
int ShipXM; 
int ShipYM; 
int ShipOffsetH; 
int ShipOffsetV; 
int ShipHitboxH; 
int ShipHitboxV; 
int ShipSurf; 
int ShipState; 
int ShipFlightTimer;
int ShipLife; 
int ShipDmg; 
int ShipFlags; 
int ShipInvincibility; 
int ShipFlightExiting; 
int dword_44C308; 
int ShipRectLeft; 
int ShipRectTop; 
int ShipRectRight; 
int ShipRectBottom; 
int ShipUnused; 
int ShipUnused2; 
char ShipThrusterFrame; 
char ShipIFrameFlash; 
int fireHeldFrames; 
int ShipPowerup; 

int *GetShip()
{
  return &ShipCond;
}


void *ResetShip()
{
  void *result; 

  result = memset(&ShipCond, 0, 0x78u);
  ShipCond = 1;
  ShipX = (HBITMAP)61440;
  ShipY = 184320;
  ShipOffsetH = 12288;
  ShipOffsetV = 0x2000;
  ShipHitboxH = 4096;
  ShipHitboxV = 4096;
  ShipSurf = 0;
  ShipLife = 1;
  ShipDmg = 20;
  ShipUnused = 0;
  ShipUnused2 = 0;
  ShipSpeed = 0;
  ShipPowerup = 0;
  return result;
}












void SetInitialShipValues()
{
  ShipX = (HBITMAP)61440;
  ShipY = 184320;
  ShipState = 0;
  ShipFlightTimer = 0;
  ShipInvincibility = 100;
  ShipThrusterFrame = 0;
  ShipIFrameFlash = 0;
  fireHeldFrames = 0;
}







signed int ShipCrushProc()
{
  ShipCond |= 2u;
  PlaySound(11);
  return ShipCrushProc2();
}


signed int ActPowerUp(NPCHAR *a1)
{
  signed int result; 
  int type2; 
  int param; 
  HBITMAP o_x; 
  int o_y; 

  switch ( a1->type )
  {
    case 7:
    case 0x3D:
      a1->cond = 0;
      o_x = (HBITMAP)a1->x;
      o_y = a1->y;
      if ( a1->flag & 0x10 )
        SubStageXOScroll(&o_x, &o_y);
      type2 = a1->type2;
      if ( type2 == 1 )
      {
        if ( SetSpeedPowerUp() )
          PlaySound(27);
        else
          PlaySound(28);
        param = 8;
      }
      else if ( type2 == 2 )
      {
        param = 9;
        if ( SetLifePowerUp() )
        {
          CreateCaret(0, (int)o_x, o_y, 9);
          PlaySound(33);
        }
        else
        {
          CreateCaret(0, (int)o_x, o_y, 4);
          AddScore(4);
          PlaySound(40);
        }
      }
      else
      {
        PlaySound(29);
        SetPowerUp(a1->type2 - 2);
        param = a1->type2 + 13;
        if ( ShipState == 100 )
        {
          ShipXM = (int)ShipX;
          ShipYM = ShipY;
        }
      }
      if ( a1->type2 != 2 )
      {
        if ( a1->score )
        {
          AddScore(a1->score);
          CreateCaret(0, (int)o_x, o_y, a1->score);
          CreateCaret(0, (int)o_x, o_y - 0x2000, param);
        }
        else
        {
          CreateCaret(0, (int)o_x, o_y, param);
        }
      }
      CreateCaret(1, (int)o_x, o_y, 0);
      if ( dword_44C308 )
        dword_44C308 = 500;
      else
        dword_44C308 = 200;
      goto LABEL_35;
    case 0x2D:
    case 0x6A:
    case 0x79:
      a1->cond = 0;
      PlaySound(40);
      AddScore(a1->score);
      o_x = (HBITMAP)a1->x;
      o_y = a1->y;
      if ( a1->flag & 0x10 )
        SubStageXOScroll(&o_x, &o_y);
      CreateCaret(0, (int)o_x, o_y, a1->score);
      CreateCaret(0, (int)o_x, o_y - 0x2000, 10);
      CreateCaret(1, (int)o_x, o_y, 0);
      goto LABEL_35;
    default:
      if ( ShipInvincibility )
        goto LABEL_35;
      if ( a1->flag & 1 && !(a1->flag & 8) )
        DamageNpChar(a1, ShipDmg);
      ShipLife -= a1->damage;
      ShipInvincibility = 150;
      CreateEntity(1, (int)ShipX, ShipY, 0);
      SetGameDelay(20);
      if ( ShipLife >= 1 )
      {
        PlaySound(34);
LABEL_35:
        result = 1;
      }
      else
      {
        ShipCrushProc();
        result = 0;
      }
      return result;
  }
}








void *LoadPximgPlayerInit()
{
  LoadPximg((int)"player", 0);
  LoadPximg((int)"shield", 1);
  ShipSpeedTable[0] = 1024;
  ShipSpeedTableDiag[0] = 768;
  speed1 = 1536;
  speedDiagonal1 = 1152;
  speed2 = 2048;
  speedDiagonal2 = 1536;
  speed3 = 2560;
  speedDiagonal3 = 1920;
  speed4 = 3072;
  speedDiagonal4 = 2304;
  return ResetShip();
}












void *ActShipState(_DWORD *a1)
{
  void *result; 

  result = (void *)(ShipCond & 0xFFFFFF0F);
  ShipCond &= 0xFFFFFF0F;
  ++ShipThrusterFrame;
  ++ShipIFrameFlash;
  if ( ShipInvincibility )
    result = (void *)(ShipInvincibility-- - 1);
  if ( dword_44C308 )
    --dword_44C308;
  if ( ShipCond & 2 )
  {
    ShipCond = 0;
    ShipState = 200;
  }
  else
  {
    result = (void *)ShipState;
    if ( ShipState > 200 )
    {
      if ( ShipState == 300 )
      {
        result = ActShipFlightExit();
      }
      else if ( ShipState == 900 )
      {
        result = ShipStateEndingProc();
      }
    }
    else if ( ShipState == 200 )
    {
      result = (void *)KillShip();
    }
    else if ( ShipState )
    {
      if ( ShipState == 100 )
        result = (void *)ActPlayerInput(a1);
    }
    else
    {
      result = ActShipFlightIntro();
    }
  }
  return result;
}







int *ActShipFlightIntro()
{
  int *result; 

  ShipY -= 768;
  if ( (double)++ShipFlightTimer <= 75.0 )
  {
    result = (int *)(ShipFlightTimer % 2);
    if ( ShipFlightTimer % 2 == 1 )
      result = CreateEntity(4, (int)ShipX, ShipY + ((4 * (ShipFlightTimer % 4 / 2) + 4) << 10), 0);
  }
  else
  {
    ShipFlightTimer = 0;
    ShipState = 100;
    ShipInvincibility = 0;
    ShipFlags |= 4u;
    result = (int *)ShipX;
    ShipXM = (int)ShipX;
    ShipYM = ShipY;
    if ( ShipLife > 3 )
    {
      ShipLife -= 3;
      result = (int *)(ShipCond | 4);
      ShipCond |= 4u;
    }
    if ( ShipCond & 4 )
    {
      CreateBullet(5, (int)ShipX, ShipY, 0, 100, 1);
      result = (int *)CreateBullet(5, (int)ShipX, ShipY, 1, 101, 1);
    }
  }
  return result;
}








int *ActShipFlightExit()
{
  int *result; 

  result = (int *)ShipFlightExiting;
  if ( ShipFlightExiting )
  {
    if ( ShipFlightExiting != 1 )
      return result;
    goto LABEL_14;
  }
  if ( (signed int)ShipX < 60416 )
    ShipX += 256;
  if ( (signed int)ShipX > 62464 )
    ShipX -= 256;
  if ( ShipY < 113664 )
  {
    result = (int *)(ShipY + 1024);
    ShipY += 1024;
  }
  if ( ShipY > 115712 )
    ShipY -= 1024;
  if ( ++ShipFlightTimer >= 100 )
  {
    ShipFlightExiting = 1;
    ShipFlightTimer = 0;
    ShipYM = 1024;
    PlaySound(35);
LABEL_14:
    ++ShipFlightTimer;
    ShipYM -= 170;
    ShipY += ShipYM;
    result = (int *)(ShipFlightTimer % 2);
    if ( ShipFlightTimer % 2 == 1 )
      result = CreateEntity(4, (int)ShipX, ShipY + ((4 * (ShipFlightTimer % 4 / 2) + 4) << 10), 0);
  }
  return result;
}




int ActPlayerInput(_DWORD *a1)
{
  int result; 

  switch ( GetPlayerInput(*a1) )
  {
    case 5:
      ShipX = (HBITMAP)((char *)ShipX - ShipSpeedTableDiag[ShipSpeed]);
      ShipY -= ShipSpeedTableDiag[ShipSpeed];
      break;
    case 6:
      ShipX = (HBITMAP)((char *)ShipX + ShipSpeedTableDiag[ShipSpeed]);
      ShipY -= ShipSpeedTableDiag[ShipSpeed];
      break;
    case 7:
      ShipX = (HBITMAP)((char *)ShipX - ShipSpeedTableDiag[ShipSpeed]);
      ShipY += ShipSpeedTableDiag[ShipSpeed];
      break;
    case 8:
      ShipX = (HBITMAP)((char *)ShipX + ShipSpeedTableDiag[ShipSpeed]);
      ShipY += ShipSpeedTableDiag[ShipSpeed];
      break;
    case 1:
      ShipX = (HBITMAP)((char *)ShipX - ShipSpeedTable[ShipSpeed]);
      break;
    case 2:
      ShipX = (HBITMAP)((char *)ShipX + ShipSpeedTable[ShipSpeed]);
      break;
    case 3:
      ShipY -= ShipSpeedTable[ShipSpeed];
      break;
    case 4:
      ShipY += ShipSpeedTable[ShipSpeed];
      break;
    default:
      break;
  }
  if ( (signed int)ShipX < 0 )
    ShipX = 0;
  if ( (signed int)ShipX > 122880 )
    ShipX = (HBITMAP)122880;
  if ( ShipY < 0 )
    ShipY = 0;
  if ( ShipY > 163840 )
    ShipY = 163840;
  if ( *a1 & 1 )
  {
    switch ( ShipPowerup )
    {
      case 0:
        ShootBullet0();
        break;
      case 1:
        ShootBullet1();
        break;
      case 2:
        ShootBullet2();
        break;
      case 3:
        ShootBullet3();
        break;
      case 4:
        ShootBullet4();
        break;
      case 5:
        ShootBullet5();
        break;
      case 6:
        ShootBullet6();
        break;
      case 7:
        ShootBullet7();
        break;
      case 8:
        ShootBullet8();
        break;
      case 9:
        ShootBullet9((int)a1);
        break;
      case 10:
        ShootBullet10();
        break;
      case 11:
        ShootBullet11();
        break;
      default:
        break;
    }
  }
  else
  {
    fireHeldFrames = 0;
  }
  result = ShipCond & 2;
  if ( ShipCond & 2 )
    ShipState = 200;
  return result;
}


