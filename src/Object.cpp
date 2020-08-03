NPCHAR *PutObject(int a1, NPCHAR *obj, int a3, int a4)
{
  NPCHAR *result; 
  signed int v5; 
  int v6; 
  signed int v7; 
  int v8; 

  result = obj;
  if ( obj->cond & 1 )
  {
    v5 = obj->x - obj->xoff;
    v7 = obj->y - obj->yoff;
    if ( v5 < 0 )
      v5 -= 1023;
    if ( v7 < 0 )
      v7 -= 1023;
    if ( obj->flag & 0x10 )
    {
      v6 = v5 / 1024 - a3;
      v8 = v7 / 1024 - a4;
    }
    else
    {
      v6 = v5 / 1024;
      v8 = v7 / 1024;
    }
    result = (NPCHAR *)PutBitmap3((RECT *)a1, v6, v8, &obj->rect, obj->surf);
  }
  return result;
}
