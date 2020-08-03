




int ShootBullet0()
{
  unsigned int v0; 
  int result; 

  v0 = fireHeldFrames % 0x18u;
  result = fireHeldFrames++ + 1;
  if ( !v0 )
  {
    result = CreateBullet(0, (int)ShipX, ShipY, 0, 0, 2);
    if ( result )
      result = PlaySound(0);
  }
  return result;
}



int ShootBullet1()
{
  unsigned int v0; 
  int result; 
  signed int v2; 

  v0 = fireHeldFrames % 8u;
  result = fireHeldFrames++ + 1;
  if ( !v0 )
  {
    v2 = CreateBullet(2, (int)(ShipX - 2048), ShipY + 2048, 0, 0, 2);
    result = v2 + CreateBullet(2, (int)(ShipX + 2048), ShipY + 2048, 0, 1, 2);
    if ( result )
      result = PlaySound(1);
  }
  return result;
}



signed int ShootBullet2()
{
  unsigned int v0; 
  signed int result; 
  HBITMAP v2; 

  v0 = fireHeldFrames % 4u;
  result = fireHeldFrames++ + 1;
  if ( !v0 )
  {
    if ( ((unsigned int)fireHeldFrames >> 2) % 2 )
      v2 = ShipX - 256;
    else
      v2 = ShipX + 256;
    result = CreateBullet(1, (int)v2, ShipY, 0, 0, 6);
    if ( result )
      result = PlaySound(2);
  }
  return result;
}



int ShootBullet3()
{
  unsigned int v0; 
  int result; 
  signed int v2; 
  int v3; 

  v0 = fireHeldFrames % 8u;
  result = fireHeldFrames++ + 1;
  if ( !v0 )
  {
    v2 = CreateBullet(0, (int)ShipX, ShipY, 0, 0, 3);
    v3 = v2 + CreateBullet(2, (int)(ShipX + 768), ShipY, 6, 1, 3);
    result = v3 + CreateBullet(2, (int)(ShipX - 1024), ShipY, 10, 2, 3);
    if ( result )
      result = PlaySound(3);
  }
  return result;
}



int ShootBullet4()
{
  unsigned int v0; 
  int result; 
  signed int v2; 
  int v3; 

  v0 = fireHeldFrames % 8u;
  result = fireHeldFrames++ + 1;
  if ( !v0 )
  {
    v2 = CreateBullet(0, (int)ShipX, ShipY, 0, 0, 3);
    v3 = v2 + CreateBullet(2, (int)(ShipX - 1280), ShipY, 8, 1, 3);
    result = v3 + CreateBullet(2, (int)(ShipX + 1280), ShipY, 8, 2, 3);
    if ( result )
      result = PlaySound(4);
  }
  return result;
}



int ShootBullet5()
{
  unsigned int v0; 
  int result; 
  signed int v2; 
  int v3; 

  v0 = fireHeldFrames % 8u;
  result = fireHeldFrames++ + 1;
  if ( !v0 )
  {
    v2 = CreateBullet(0, (int)ShipX, ShipY, 0, 0, 3);
    v3 = v2 + CreateBullet(2, (int)(ShipX + 1280), ShipY, 2, 2, 3);
    result = v3 + CreateBullet(2, (int)(ShipX - 1536), ShipY, 14, 3, 3);
    if ( result )
      result = PlaySound(5);
  }
  return result;
}



int ShootBullet6()
{
  unsigned int v0; 
  int result; 
  signed int v2; 
  int v3; 

  v0 = fireHeldFrames % 8u;
  result = fireHeldFrames++ + 1;
  if ( !v0 )
  {
    v2 = CreateBullet(2, (int)ShipX, ShipY - 3072, 0, 0, 2);
    v3 = v2 + CreateBullet(2, (int)(ShipX - 2304), ShipY + 3072, 0, 1, 2);
    result = v3 + CreateBullet(2, (int)(ShipX + 2304), ShipY + 3072, 0, 2, 2);
    if ( result )
      result = PlaySound(6);
  }
  return result;
}



int ShootBullet7()
{
  unsigned int v0; 
  int result; 
  signed int v2; 
  int v3; 
  int v4; 
  int v5; 

  v0 = fireHeldFrames % 6u;
  result = fireHeldFrames++ + 1;
  if ( !v0 )
  {
    v2 = CreateBullet(2, (int)ShipX, ShipY - 3072, 0, 0, 2);
    v3 = v2 + CreateBullet(2, (int)(ShipX - 1280), ShipY, 15, 1, 2);
    v4 = v3 + CreateBullet(2, (int)(ShipX + 1024), ShipY, 1, 2, 2);
    v5 = v4 + CreateBullet(2, (int)(ShipX + 256), ShipY, 6, 3, 3);
    result = v5 + CreateBullet(2, (int)(ShipX - 512), ShipY, 10, 4, 3);
    if ( result )
      result = PlaySound(8);
  }
  return result;
}



int ShootBullet8()
{
  unsigned int v0; 
  int result; 
  signed int v2; 
  int v3; 

  v0 = fireHeldFrames % 8u;
  result = fireHeldFrames++ + 1;
  if ( !v0 )
  {
    v2 = CreateBullet(4, (int)ShipX, ShipY - 1024, 0, 10, 1);
    v3 = v2 + CreateBullet(4, (int)(ShipX - 1024), ShipY + 4096, 13, 11, 1);
    result = v3 + CreateBullet(4, (int)(ShipX + 768), ShipY + 4096, 3, 12, 1);
    if ( result )
      result = PlaySound(10);
  }
  return result;
}



signed int ShootBullet9(int a1)
{
  unsigned int v1; 
  signed int result; 
  char v3; 

  if ( *(_DWORD *)(a1 + 4) & 1 )
  {
    ShipXM = (int)ShipX;
    ShipYM = ShipY;
  }
  v1 = fireHeldFrames % 4u;
  result = fireHeldFrames++ + 1;
  if ( !v1 )
  {
    v3 = GetArktan((int)ShipX - ShipXM, ShipY - ShipYM, -64);
    result = CreateBullet(6, (int)ShipX, ShipY, (unsigned __int8)v3, 0, 6);
    if ( result )
      result = PlaySound(5);
  }
  return result;
}





signed int ShootBullet10()
{
  unsigned int v0; 
  signed int result; 

  v0 = fireHeldFrames % 0x20u;
  result = fireHeldFrames++ + 1;
  if ( !v0 )
  {
    result = CreateBullet(7, (int)ShipX, ShipY - 0x2000, 0, 0, 2);
    if ( result )
      result = PlaySound(20);
  }
  return result;
}



int ShootBullet11()
{
  unsigned int v0; 
  int result; 
  int v2; 
  signed int v3; 
  HBITMAP x; 
  HBITMAP v5; 

  v0 = fireHeldFrames % 4u;
  result = fireHeldFrames++ + 1;
  if ( !v0 )
  {
    if ( ((unsigned int)fireHeldFrames >> 2) % 2 )
    {
      x = ShipX - 1536;
      v5 = ShipX + 1536;
    }
    else
    {
      x = ShipX - 2048;
      v5 = ShipX + 2048;
    }
    v2 = ShipY + 5120;
    v3 = CreateBullet(1, (int)x, ShipY + 4096, 0, 0, 6);
    result = v3 + CreateBullet(1, (int)v5, v2 - 1024, 0, 1, 6);
    if ( result )
      result = PlaySound(2);
  }
  return result;
}
