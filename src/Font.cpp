

int LoadPximgCharactor()
{
  return LoadPximg((int)"charactor", 9);
}


int PutNumber(int a1, int x, int y, signed int value, char a5, signed int a6)
{
  int result; 
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
  int j; 
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
  int v44; 
  int v45; 
  int v46; 
  int v47; 
  int v48; 
  int v49; 
  int v50; 
  int v51; 
  int v52; 
  int v53; 
  int v54; 
  int v55; 
  int v56; 
  int v57; 
  int v58; 
  int v59; 
  int v60; 
  int v61; 
  int v62; 
  int v63; 
  int v64; 
  int v65; 
  int v66; 
  int v67; 
  int v68; 
  int v69; 
  int v70; 
  int i; 
  int v72; 

  v22 = 48;
  v23 = 8;
  v24 = 56;
  v25 = 16;
  v26 = 56;
  v27 = 8;
  v28 = 64;
  v29 = 16;
  v30 = 64;
  v31 = 8;
  v32 = 72;
  v33 = 16;
  v34 = 72;
  v35 = 8;
  v36 = 80;
  v37 = 16;
  v38 = 0;
  v39 = 16;
  v40 = 8;
  v41 = 24;
  v42 = 8;
  v43 = 16;
  v44 = 16;
  v45 = 24;
  v46 = 16;
  v47 = 16;
  v48 = 24;
  v49 = 24;
  v50 = 24;
  v51 = 16;
  v52 = 32;
  v53 = 24;
  v54 = 32;
  v55 = 16;
  v56 = 40;
  v57 = 24;
  v58 = 40;
  v59 = 16;
  v60 = 48;
  v61 = 24;
  v15 = 104;
  v16 = 0;
  v17 = 112;
  v18 = 8;
  v7 = 0;
  v8 = 1;
  v9 = 10;
  v10 = 100;
  v11 = 1000;
  v12 = 10000;
  v13 = 100000;
  v64 = 0;
  v65 = 9;
  v66 = 99;
  v67 = 999;
  v68 = 9999;
  v69 = 99999;
  v70 = 999999;
  v19 = 0;
  v62 = 0;
  j = 0;
  v63 = a5 & 0xF;
  v14 = x;
  v20 = y;
  v72 = 0;
  if ( a5 & 0xF )
  {
    if ( value > *(&v64 + v63) )
      value = *(&v64 + v63);
    if ( value < 0 )
    {
      value = -value;
      v62 = 1;
      ++v72;
    }
    for ( i = 6; i > 1 && value < *(&v7 + i); --i )
      ;
    v72 += 6 * i;
    if ( a5 & 0x10 )
    {
      v14 -= v72 / 2;
      v20 -= 4;
    }
    for ( j = v63; j > 0; --j )
    {
      i = value / *(&v7 + j);
      value %= *(&v7 + j);
      if ( v62 && i && !v19 )
      {
        if ( a6 )
          PutNumber2_(v14, v20, (int)&v15, a6, 9);
        else
          PutBitmap3((RECT *)a1, v14 - 6, v20, (RECT *)&v15, 9);
      }
      if ( v19 || i || j == 1 )
      {
        if ( a6 )
          PutNumber2_(v14, v20, (int)(&v22 + 4 * i), a6, 9);
        else
          PutBitmap3((RECT *)a1, v14, v20, (RECT *)&v22 + i, 9);
      }
      if ( i )
        v19 = 1;
      v14 += 6;
    }
    result = v14;
  }
  else
  {
    result = v14;
  }
  return result;
}


int PutTextObject(int a1, int a2, int a3, char *a4, int a5, int a6)
{
  signed int v6; 
  int v8; 
  int v9; 
  signed int v10; 
  signed int i; 
  int v12; 
  int v13; 
  int v14; 
  int v15; 

  v8 = a2;
  v9 = a3;
  v10 = strlen(a4);
  if ( a5 & 0x10 )
  {
    v8 = a2 - 6 * v10 / 2;
    v9 = a3 - 4;
  }
  for ( i = 0; i < v10; ++i )
  {
    v6 = a4[i] - 32;
    v12 = 8 * (v6 % 10);
    v14 = 8 * (v6 % 10) + 8;
    v13 = 8 * (v6 / 10);
    v15 = 8 * (v6 / 10) + 8;
    if ( a6 )
      PutNumber2_(v8, v9, (int)&v12, a6, 9);
    else
      PutBitmap3((RECT *)a1, v8, v9, (RECT *)&v12, 9);
    v8 += 6;
  }
  return v8;
}
