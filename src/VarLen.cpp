
#include "File.h"
#include "VarLen.h"
#include <cstdint>

//pxtnDescriptor_v_chk (unused)
int VarLenCheck( unsigned int us )
{

	if( us <        0x80 ) return 1;	// 1byte( 7bit)
	if( us <      0x4000 ) return 2;	// 2byte(14bit)
	if( us <    0x200000 ) return 3;	// 3byte(21bit)
	if( us <  0x10000000 ) return 4;	// 4byte(28bit)
//	if( value < 0x800000000 ) return 5;	// 5byte(35bit)
	if( us <= 0xffffffff ) return 5;

	return 6;
}

//pxtnDescriptor::v_r
// 可変長読み込み（int32_t  までを保証）
bool VarLenRead  ( DWORD *p, PixFile* a2 )
{
	int          i;
	uint8_t a[ 5 ] = {0};
	uint8_t b[ 5 ] = {0};

	for( i = 0; i < 5; i++ )
	{
		if( !ReadFromFile( &a[i], 1, 1, a2 ) ) return false;
		if( !(a[i] & 0x80) ) break;
	}
	switch( i )
	{
	case 0:
		b[0]    =  (a[0]&0x7F)>>0;
		break;
	case 1:
		b[0]    = ((a[0]&0x7F)>>0) | (a[1]<<7);
		b[1]    =  (a[1]&0x7F)>>1;
		break;
	case 2:
		b[0]    = ((a[0]&0x7F)>>0) | (a[1]<<7);
		b[1]    = ((a[1]&0x7F)>>1) | (a[2]<<6);
		b[2]    =  (a[2]&0x7F)>>2;
		break;
	case 3:
		b[0]    = ((a[0]&0x7F)>>0) | (a[1]<<7);
		b[1]    = ((a[1]&0x7F)>>1) | (a[2]<<6);
		b[2]    = ((a[2]&0x7F)>>2) | (a[3]<<5);
		b[3]    =  (a[3]&0x7F)>>3;
		break;
	case 4:
		b[0]    = ((a[0]&0x7F)>>0) | (a[1]<<7);
		b[1]    = ((a[1]&0x7F)>>1) | (a[2]<<6);
		b[2]    = ((a[2]&0x7F)>>2) | (a[3]<<5);
		b[3]    = ((a[3]&0x7F)>>3) | (a[4]<<4);
		b[4]    =  (a[4]&0x7F)>>4;
		break;
	case 5:
		return false;
	}

	*p = *((int32_t*)b);

	return true;
}

//pxtnDescriptor::v_w_asfile
int VarLenWrite( int val, FILE* _p_desc, DWORD* p_add)
{
	uint8_t  a[ 5 ] = {0};
	uint8_t  b[ 5 ] = {0};
	uint32_t us     = (uint32_t )val;
	int32_t  bytes  = 0;
	
	a[ 0 ] = *( (uint8_t *)(&us) + 0 );
	a[ 1 ] = *( (uint8_t *)(&us) + 1 );
	a[ 2 ] = *( (uint8_t *)(&us) + 2 );
	a[ 3 ] = *( (uint8_t *)(&us) + 3 );
	a[ 4 ] = 0;

	// 1byte(7bit)
	if     ( us < 0x00000080 )
	{
		bytes = 1;
		b[0]  = a[0];
	}

	// 2byte(14bit)
	else if( us < 0x00004000 )
	{
		bytes = 2;
		b[0]  =             ((a[0]<<0)&0x7F) | 0x80;
		b[1]  = (a[0]>>7) | ((a[1]<<1)&0x7F);
	}

	// 3byte(21bit)
	else if( us < 0x00200000 )
	{
		bytes = 3;
		b[0] =             ((a[0]<<0)&0x7F) | 0x80;
		b[1] = (a[0]>>7) | ((a[1]<<1)&0x7F) | 0x80;
		b[2] = (a[1]>>6) | ((a[2]<<2)&0x7F);
	}

	// 4byte(28bit)
	else if( us < 0x10000000 )
	{
		bytes = 4;
		b[0] =             ((a[0]<<0)&0x7F) | 0x80;
		b[1] = (a[0]>>7) | ((a[1]<<1)&0x7F) | 0x80;
		b[2] = (a[1]>>6) | ((a[2]<<2)&0x7F) | 0x80;
		b[3] = (a[2]>>5) | ((a[3]<<3)&0x7F);
	}

	// 5byte(32bit)
	else
	{
		bytes = 5;
		b[0] =             ((a[0]<<0)&0x7F) | 0x80;
		b[1] = (a[0]>>7) | ((a[1]<<1)&0x7F) | 0x80;
		b[2] = (a[1]>>6) | ((a[2]<<2)&0x7F) | 0x80;
		b[3] = (a[2]>>5) | ((a[3]<<3)&0x7F) | 0x80;
		b[4] = (a[3]>>4) | ((a[4]<<4)&0x7F);
	}
	if( fwrite( b, 1, bytes, (FILE*)_p_desc )     != bytes ) return false;
	if( p_add ) p_add += bytes;
	return true;

	return false;
}
