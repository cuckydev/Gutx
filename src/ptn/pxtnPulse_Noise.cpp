
#include "./pxtn.h"

#include "./pxtnMem.h"
#include "./pxtnPulse_Noise.h"

#include "../File.h"
#include "../VarLen.h"

#define NOISEDESIGNLIMIT_SMPNUM (48000 * 10)
#define NOISEDESIGNLIMIT_ENVE_X ( 1000 * 10)
#define NOISEDESIGNLIMIT_ENVE_Y (  100     )
#define NOISEDESIGNLIMIT_OSC_FREQUENCY 44100.0f
#define NOISEDESIGNLIMIT_OSC_VOLUME      200.0f
#define NOISEDESIGNLIMIT_OSC_OFFSET      100.0f

pxtnPulse_Noise * pxtnPulse_Noise_Fix(pxtnPulse_Noise *p_dst)
{
	pxNOISEDESIGN_UNIT *p_unit;
	int32_t i, e;

	if( p_dst->_smp_num_44k > NOISEDESIGNLIMIT_SMPNUM ) p_dst->_smp_num_44k = NOISEDESIGNLIMIT_SMPNUM;

	for( i = 0; i < p_dst->_unit_num; i++ )
	{
		p_unit = &p_dst->_units[ i ];
		if( p_unit->bEnable )
		{
			for( e = 0; e < p_unit->enve_num; e++ )
			{
				if( p_unit->enves[ e ].x > NOISEDESIGNLIMIT_ENVE_X ) p_unit->enves[ e ].x = NOISEDESIGNLIMIT_ENVE_X;
				if( p_unit->enves[ e ].x <                       0 ) p_unit->enves[ e ].x =                       0;
				if( p_unit->enves[ e ].y > NOISEDESIGNLIMIT_ENVE_Y ) p_unit->enves[ e ].y = NOISEDESIGNLIMIT_ENVE_Y;
				if( p_unit->enves[ e ].y <                       0 ) p_unit->enves[ e ].y =                       0;
			}
			_FixUnit( &p_unit->main );
			_FixUnit( &p_unit->freq );
			_FixUnit( &p_unit->volu );
		}
	}
	return p_dst;
}

void _FixUnit( pxNOISEDESIGN_OSCILLATOR *p_osc )
{
	if( p_osc->type   >= pxWAVETYPE_num                 ) p_osc->type   = pxWAVETYPE_None;
	if( p_osc->freq   >  NOISEDESIGNLIMIT_OSC_FREQUENCY ) p_osc->freq   = NOISEDESIGNLIMIT_OSC_FREQUENCY;
	if( p_osc->volume >  NOISEDESIGNLIMIT_OSC_VOLUME    ) p_osc->volume = NOISEDESIGNLIMIT_OSC_VOLUME;
	if( p_osc->offset >  NOISEDESIGNLIMIT_OSC_OFFSET    ) p_osc->offset = NOISEDESIGNLIMIT_OSC_OFFSET;
}

#define MAX_NOISEEDITUNITNUM     4
#define MAX_NOISEEDITENVELOPENUM 3

#define NOISEEDITFLAG_XX1       0x0001
#define NOISEEDITFLAG_XX2       0x0002
#define NOISEEDITFLAG_ENVELOPE  0x0004
#define NOISEEDITFLAG_PAN       0x0008
#define NOISEEDITFLAG_OSC_MAIN  0x0010
#define NOISEEDITFLAG_OSC_FREQ  0x0020
#define NOISEEDITFLAG_OSC_VOLU  0x0040
#define NOISEEDITFLAG_OSC_PAN   0x0080

#define NOISEEDITFLAG_UNCOVERED 0xffffff83

//                          01234567
static const char *_code = "PTNOISE-";

static const uint32_t _ver =  20051028 ; //-v.0.9.2.3

static bool _WriteOscillator( const pxNOISEDESIGN_OSCILLATOR *p_osc, FILE* a2, DWORD *p_add )
{
	int32_t work;
	work = (int32_t) p_osc->type        ; if( !VarLenWrite( work, a2, p_add ) ) return false;
	work = (int32_t) p_osc->b_rev       ; if( !VarLenWrite( work, a2, p_add ) ) return false;
	work = (int32_t)(p_osc->freq   * 10); if( !VarLenWrite( work, a2, p_add ) ) return false;
	work = (int32_t)(p_osc->volume * 10); if( !VarLenWrite( work, a2, p_add ) ) return false;
	work = (int32_t)(p_osc->offset * 10); if( !VarLenWrite( work, a2, p_add ) ) return false;
	return true;
}

static int _MakeFlags( const pxNOISEDESIGN_UNIT *pU )
{
	int flags = 4;
	if( pU->pan                          ) flags = 4                      ;
	if( pU->main.type != pxWAVETYPE_None ) flags |= NOISEEDITFLAG_OSC_MAIN;
	if( pU->freq.type != pxWAVETYPE_None ) flags |= NOISEEDITFLAG_OSC_FREQ;
	if( pU->volu.type != pxWAVETYPE_None ) flags |= NOISEEDITFLAG_OSC_VOLU;
	return flags;
}


static signed int _ReadOscillator( pxNOISEDESIGN_OSCILLATOR *p_osc, PixFile* p_add )
{
	DWORD work;
	if( !VarLenRead( &work, p_add)          ) return false     ; p_osc->type     = (pxWAVETYPE)work;
	if( !VarLenRead( &work, p_add )          ) return false     ; p_osc->b_rev    = work ? true : false;
	if( !VarLenRead( &work, p_add )          ) return false     ; p_osc->freq     = (float)work / 10;
	if( !VarLenRead( &work, p_add )          ) return false     ; p_osc->volume   = (float)work / 10;
	if( !VarLenRead( &work, p_add )          ) return false     ; p_osc->offset   = (float)work / 10;

	return true;
}

//unused
int pxtnPulse_Noise_write(FILE *fp, int *p_add, pxtnPulse_Noise *p_dst)
{
	bool  b_ret = false;
	DWORD   u, e, seek, num_seek, flags;
	char  byte;
	char  unit_num = 0;
	const pxNOISEDESIGN_UNIT *pU;

//	Fix();

	if( p_add ) seek = *p_add;
	else        seek =      0;

	if( !fwrite( _code, 1, 8 , fp) ) goto End;
	if( !fwrite( &_ver, 4, 1 , fp) ) goto End;
	seek += 12;
	if( !VarLenWrite( p_dst->_smp_num_44k, fp, &seek ) ) goto End;

	if( !fwrite( &unit_num , 1, 1, fp) ) goto End;
	num_seek = seek;
	seek += 1;

	for( u = 0; u < p_dst->_unit_num; u++ )
	{
		pU = &p_dst->_units[ u ];
		if( pU->bEnable )
		{
			// フラグ
			flags = _MakeFlags( pU );
			if( !VarLenWrite( flags, fp, &seek ) ) goto End;
			if( flags & NOISEEDITFLAG_ENVELOPE )
			{
				if( !VarLenWrite( pU->enve_num, fp, &seek ) ) goto End;
				for( e = 0; e < pU->enve_num; e++ )
				{
					if( !VarLenWrite( pU->enves[ e ].x, fp, &seek ) ) goto End;
					if( !VarLenWrite( pU->enves[ e ].y, fp, &seek ) ) goto End;
				}
			}
			if( flags & NOISEEDITFLAG_PAN      )
			{
				byte = (char)pU->pan;
				if( !fwrite( &byte, 1, 1, fp) ) goto End;
				seek++;
			}
			if( flags & NOISEEDITFLAG_OSC_MAIN ){ if( !_WriteOscillator( &pU->main, fp, &seek ) ) goto End; }
			if( flags & NOISEEDITFLAG_OSC_FREQ ){ if( !_WriteOscillator( &pU->freq, fp, &seek ) ) goto End; }
			if( flags & NOISEEDITFLAG_OSC_VOLU ){ if( !_WriteOscillator( &pU->volu, fp, &seek ) ) goto End; }
			unit_num++;
		}
	}

	// update unit_num.
	fseek( fp, num_seek - seek, 1 );
	if( !fwrite( &unit_num, 1, 1, fp ) ) goto End;
	fseek( fp, seek - num_seek -1, 1 );
	if( p_add ) *p_add = seek;

	b_ret = true;
End:

	return b_ret;
}
int pxtnPulse_Noise_read( PixFile *fp, pxtnPulse_Noise *p_dst, int flags)
{
	int      res       =            0;
	char     unit_num  =            0;
	char     byte      =            0;
	uint32_t ver       =            0;

	pxNOISEDESIGN_UNIT* pU = NULL;

	char       code[ 8 ] = {0};
	
	if( !ReadFromFile( code, 1, 8, fp )         ){ goto term; }
	if( memcmp( code, _code, 8 )        ){ goto term; }
	if( !ReadFromFile( &ver     , 4, 1, fp )    ){ goto term; }	
	if( ver > _ver                      ){ goto term; }	
	if( !VarLenRead( &p_dst->_smp_num_44k , fp )    ){ goto term; }
	if( !ReadFromFile( &unit_num, 1, 1, fp )    ){ goto term; }
	if( unit_num < 0                    ){ goto term; }
	if( unit_num > MAX_NOISEEDITUNITNUM ){ goto term; }
	p_dst->_unit_num = unit_num;			    

	if( !pxtnMem_zero_alloc( (void**)&p_dst->_units, sizeof(pxNOISEDESIGN_UNIT) * p_dst->_unit_num ) ){ goto term; }

	for( int32_t u = 0; u < p_dst->_unit_num; u++ )
	{
		pU = &p_dst->_units[ u ];
		pU->bEnable = true;

		if( !VarLenRead( (DWORD*)&flags, fp ) ){ goto term; }
		if( flags & NOISEEDITFLAG_UNCOVERED ){ goto term; }

		// envelope
		if( flags & NOISEEDITFLAG_ENVELOPE )
		{
			if( !VarLenRead( &pU->enve_num, fp ) ){ goto term; }
			if( pU->enve_num > MAX_NOISEEDITENVELOPENUM ){ goto term; }
			if( !pxtnMem_zero_alloc( (void**)&pU->enves, sizeof(pxtnPOINT) * pU->enve_num ) ){ goto term; }
			for( int32_t e = 0; e < pU->enve_num; e++ )
			{
				if( !VarLenRead( &pU->enves[ e ].x, fp ) ){ goto term; }
				if( !VarLenRead( &pU->enves[ e ].y, fp ) ){ goto term; }
			}
		}
		// pan
		if( flags & NOISEEDITFLAG_PAN )
		{
			if( !ReadFromFile( &byte, 1, 1, fp ) ){ goto term; }
			pU->pan = byte;
		}
		
		if( flags & NOISEEDITFLAG_OSC_MAIN && !_ReadOscillator( &pU->main, fp )
		||  flags & NOISEEDITFLAG_OSC_FREQ && !_ReadOscillator( &pU->freq, fp )
		||  flags & NOISEEDITFLAG_OSC_VOLU && !_ReadOscillator( &pU->volu, fp ) )
			{ goto term; }
	}

	res = true;
term:
	if( res != true ) pxtnPulse_Noise_Release(p_dst);

	return res;
}

void* pxtnPulse_Noise_Release(pxtnPulse_Noise *pdst)
{
  int32_t i; // [sp+0h] [bp-4h]@2

  if ( pdst->_units )
  {
    for ( i = 0; i < pdst->_unit_num; ++i )
    {
      if ( pdst->_units[i].enves )
        pxtnMem_free((void**)&pdst->_units[i].enves);
    }
    pxtnMem_free((void**)&pdst->_units);
  }
  return memset(pdst, 0, 0xCu);
}

bool pxtnPulse_Noise_Allocate( pxtnPulse_Noise *p_dst, int unit_num, int32_t envelope_num )
{
	bool b_ret = false;

	p_dst->_unit_num = unit_num;
	if( !pxtnMem_zero_alloc( (void**)&p_dst->_units, sizeof(pxNOISEDESIGN_UNIT) * unit_num ) ) goto End;

	for( int32_t u = 0; u < unit_num; u++ )
	{
		pxNOISEDESIGN_UNIT *p_unit = &p_dst->_units[ u ];
		p_unit->enve_num = envelope_num;
		if( !pxtnMem_zero_alloc( (void**)&p_unit->enves, sizeof(pxtnPOINT) * p_unit->enve_num ) ) goto End;
	}

	b_ret = true;
End:
	if( !b_ret ) pxtnPulse_Noise_Release(p_dst);

	return b_ret;
}

