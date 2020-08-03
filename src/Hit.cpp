

Bullet *HitNpCharBullet()
{
  Bullet *result; 
  signed int j; 
  int b_y; 
  Bullet *bul; 
  NPCHAR *npc; 
  int i; 
  int v6; 
  int b_x; 
  int n_y; 
  int n_x; 

  result = (Bullet *)GetBulletTbl();
  bul = result;
  for ( i = 0; i < 32; ++i )
  {
    if ( bul->cond & 1 && bul->flag & 4 )
    {
      b_x = bul->x;
      b_y = bul->y;
      if ( bul->flag & 0x10 )
        SubStageXOScroll(&b_x, &b_y);
      npc = (NPCHAR *)GetNpcTable();
      for ( j = 0; j < 256; ++j )
      {
        v6 = 0;
        if ( npc->cond & 1 )
        {
          if ( bul->cond & 4 )
          {
            if ( npc->type == 13 || npc->type == 14 || npc->type == 98 )
              v6 = 1;
            if ( npc->flag & 8 )
              v6 = 1;
            if ( npc->flag & 2 && npc->flag & 1 )
              v6 = 1;
          }
          else if ( npc->flag & 9 )
          {
            v6 = 1;
          }
        }
        if ( v6 )
        {
          n_x = npc->x;
          n_y = npc->y;
          if ( npc->flag & 0x10 )
            SubStageXOScroll(&n_x, &n_y);
          if ( b_x - bul->w < npc->w + n_x
            && bul->w + b_x > n_x - npc->w
            && b_y - bul->h < npc->h + n_y
            && bul->h + b_y > n_y - npc->h )
          {
            if ( npc->flag & 8 )
            {
              if ( bul->flag & 8 )
              {
                bul->cond |= 8u;
              }
              else
              {
                bul->cond |= 8u;
                CreateCaret(7, bul->x, bul->y, 0);
                PlaySound(24);
                if ( !(bul->cond & 4) )
                {
                  bul->cond |= 2u;
                  break;
                }
              }
            }
            else
            {
              bul->cond |= 8u;
              CreateCaret(6, bul->x, bul->y, 0);
              DamageNpChar(npc, bul->damage);
              bul->life -= npc->damage;
              if ( bul->life <= 0 )
              {
                bul->cond |= 2u;
                break;
              }
            }
          }
        }
        ++npc;
      }
    }
    bul = (Bullet *)((char *)bul + 120);
    result = (Bullet *)(i + 1);
  }
  return result;
}


int *HitShipPowerup()
{
  int *result; 
  signed int i; 
  Ship *S; 
  int s_y; 
  NPCHAR *e; 
  int n_y; 
  int s_x; 
  int n_x; 

  S = (Ship *)GetShip();
  e = (NPCHAR *)GetNpcTable();
  result = (int *)S;
  if ( S->cond & 1 )
  {
    result = (int *)(S->flag & 4);
    if ( result )
    {
      s_x = S->x;
      s_y = S->y;
      result = (int *)(S->flag & 0x10);
      if ( result )
        result = SubStageXOScroll(&s_x, &s_y);
      for ( i = 0; i < 256; ++i )
      {
        if ( e->cond & 1 && e->flag & 2 )
        {
          n_x = e->x;
          n_y = e->y;
          if ( e->flag & 0x10 )
            SubStageXOScroll(&n_x, &n_y);
          if ( s_x - S->w < e->w + n_x && S->w + s_x > n_x - e->w && s_y - S->h < e->h + n_y && S->h + s_y > n_y - e->h )
          {
            result = (int *)ActPowerUp(e);
            if ( !result )
              break;
          }
        }
        ++e;
        result = (int *)(i + 1);
      }
    }
  }
  return result;
}


int HitMapGeneric(NPCHAR *o, int (*func)(int, int, int, int), int a3)
{
  int attr; 
  int v4; 
  int v5; 
  int v6; 
  int v7; 
  int v8; 
  int v9; 
  int v10; 
  int v11; 
  int i; 
  int v13; 
  int v14; 
  int ow; 
  int v16; 
  int x; 
  int ox; 
  int attr_; 
  int oy; 
  int v21; 
  int y; 
  int flag; 
  int oh; 
  int direct; 

  direct = 0;
  flag = 0;
  ox = o->x;
  oy = o->y;
  ow = o->w;
  oh = o->h;
  if ( !(o->flag & 0x10) )
    AddStageXOScroll(&ox, &oy);
  x = (ox + 0x2000) / 0x4000;
  y = (oy + 0x2000) / 0x4000;
  if ( GetTileAttr(x - 1, y - 1) & 1 )
    direct |= 1u;
  if ( GetTileAttr(x, y - 1) & 1 )
    direct |= 2u;
  if ( GetTileAttr(x - 1, y) & 1 )
    direct |= 4u;
  if ( GetTileAttr(x, y) & 1 )
    direct |= 8u;
  if ( a3 )
    direct = 128;
  attr = direct;
  switch ( direct )
  {
    case 0:
      break;
    case 3:
      attr = oy - oh;
      if ( oy - oh < y << 14 )
      {
        oy = oh + (y << 14);
        attr = flag | 0x40;
        flag |= 0x40u;
      }
      break;
    case 5:
      if ( ox - ow < x << 14 )
      {
        attr = ow + (x << 14);
        ox = ow + (x << 14);
        flag |= 0x10u;
      }
      break;
    case 10:
      attr = x << 14;
      if ( ow + ox > x << 14 )
      {
        ox = (x << 14) - ow;
        flag |= 0x20u;
      }
      break;
    case 12:
      attr = oh + oy;
      if ( oh + oy > y << 14 )
      {
        oy = (y << 14) - oh;
        attr = flag | 0x80;
        flag |= 0x80u;
      }
      break;
    default:
      v4 = -1;
      v5 = -1;
      v6 = 1;
      v7 = 0;
      v8 = -1;
      v9 = 1;
      v10 = 1;
      v11 = 0;
      for ( i = 0; i < 4; ++i )
      {
        x += *(&v4 + 2 * i);
        y += *(&v5 + 2 * i);
        attr = GetTileAttr(x, y);
        attr_ = attr;
        if ( attr & 1 )
        {
          attr = ow + ox;
          if ( ow + ox > x << 14 )
          {
            attr = (x << 14) + 0x4000;
            if ( ox - ow <= attr && oh + oy > y << 14 )
            {
              attr = oy - oh;
              if ( oy - oh <= (y << 14) + 0x4000 )
              {
                v21 = (x << 14) + 0x2000;
                v16 = (y << 14) + 0x2000;
                v13 = ox - v21;
                if ( ox - v21 < 0 )
                  v13 = -v13;
                v14 = oy - v16;
                if ( oy - v16 < 0 )
                  v14 = -v14;
                if ( 16 * v13 / (ow + 0x2000) <= 16 * v14 / (oh + 0x2000) )
                {
                  if ( oy >= v16 )
                  {
                    oy = v16 + oh + 0x2000;
                    flag |= 0x40u;
                  }
                  else
                  {
                    oy = v16 - (oh + 0x2000);
                    flag |= 0x80u;
                  }
                }
                else if ( ox >= v21 )
                {
                  ox = v21 + ow + 0x2000;
                  flag |= 0x10u;
                }
                else
                {
                  ox = v21 - (ow + 0x2000);
                  flag |= 0x20u;
                }
                attr = attr_ & 2;
                if ( attr_ & 2 )
                {
                  if ( a3 )
                  {
                    GetTile(x, y);
                    CreateEntity(10, (16 * x + 8) << 10, (16 * y + 8) << 10, 0);
                    attr = PlaySound(15);
                    goto LABEL_49;
                  }
                }
              }
            }
          }
        }
      }
      break;
  }
LABEL_49:
  if ( flag )
  {
    if ( !(o->flag & 0x10) )
      SubStageXOScroll(&ox, &oy);
    attr = func(o, ox, oy, flag);
  }
  return attr;
}
