
#include "./pxtn.h"

#include "./pxtnMem.h"
#include "./pxtnPulse_NoiseBuilder.h"

#include "./pxtnPulse_Noise.h"


#define _BASIC_SPS     44100.0
#define _BASIC_FREQUENCY 100.0 // 100 Hz
#define _SAMPLING_TOP    32767 //  16 bit max
#define _KEY_TOP        0x3200 //  40 key

#define _smp_num_rand    44100
#define _smp_num         (int32_t)( _BASIC_SPS / _BASIC_FREQUENCY )


enum _RANDOMTYPE
{
	_RANDOM_None = 0,
	_RANDOM_Saw     ,
	_RANDOM_Rect    ,
};

typedef struct
{
	double       incriment ;
	double       offset    ;
	double       volume    ;
	const short* p_smp     ;
	bool         bReverse  ;
	_RANDOMTYPE  ran_type  ;
	int32_t      rdm_start ;
	int32_t      rdm_margin;
	int32_t      rdm_index ;
}
_OSCILLATOR;

typedef struct
{
	int32_t    smp;
	double mag;
}
_POINT;

typedef struct
{
	bool        bEnable;
	double      pan[ 2 ];
	int32_t     enve_index;
	double      enve_mag_start;
	double      enve_mag_margin;
	int32_t     enve_count;
	int32_t     enve_num;
	_POINT*     enves;

	_OSCILLATOR main;
	_OSCILLATOR freq;
	_OSCILLATOR volu;
}
_UNIT;

short*  _p_tables[ pxWAVETYPE_num ];
int32_t _rand_buf [ 2 ];

//pxtnPulse_Frequency* _freq;

const short* _set_ocsillator( _OSCILLATOR *p_to, pxNOISEDESIGN_OSCILLATOR *p_from, int32_t sps)
{
	const short *p;

	if(p_from->type == 4)
		p_to->ran_type = _RANDOM_Saw;
	else
		p_to->ran_type = _RANDOM_None;
	

	p_to->incriment  = ( _BASIC_SPS / sps ) * ( p_from->freq   / _BASIC_FREQUENCY );

	// offset
	if( p_to->ran_type != _RANDOM_None ) p_to->offset = 0;
	else                                 p_to->offset = (double) _smp_num * ( p_from->offset / 100 );

	p_to->volume     = p_from->volume / 100;
	p_to->p_smp      = _p_tables[p_from->type];
	p_to->bReverse   = p_from->b_rev;

	p_to->rdm_start  = 0;
	p_to->rdm_index  = (int32_t)( (double)(_smp_num_rand) * ( p_from->offset / 100 ) );
	p = _p_tables[ pxWAVETYPE_Random ];
	p_to->rdm_margin = p[ p_to->rdm_index ];

	return p;
}

void _incriment( _OSCILLATOR *p_osc, double incriment)
{
	p_osc->offset += incriment + p_osc->offset;
	if( p_osc->offset > _smp_num )
	{
		p_osc->offset     -= _smp_num;
		if( p_osc->offset >= _smp_num ) p_osc->offset = 0;

		if( p_osc->ran_type != _RANDOM_None )
		{
			const short *p = _p_tables[ pxWAVETYPE_Random ];
			p_osc->rdm_start  = p[ p_osc->rdm_index++ ];
			if( p_osc->rdm_index >= _smp_num_rand ) 
				p_osc->rdm_index = 0;
			p_osc->rdm_margin = p[ p_osc->rdm_index ] - p_osc->rdm_start;
		}
	}
}

int pxtnPulse_NoiseBuilder_deconstructor()
{
	int res;
	for( int32_t i = 0; i < pxWAVETYPE_num; i++ ) 
	{
		pxtnMem_free( (void **)&_p_tables[ i ] );
		res = i + 1;
	}
	return res;
}

void pxtnPulse_NoiseBuilder_random_reset()
{
	_rand_buf[ 0 ] = 0x4444;
	_rand_buf[ 1 ] = 0x8888;
}

short pxtnPulse_NoiseBuilder_random_get()
{
	int32_t  w1, w2;
	char *p1;
	char *p2;

	w1 = (short)_rand_buf[ 0 ] + _rand_buf[ 1 ];
	p1 = (char *)&w1;
	p2 = (char *)&w2;
	p2[ 0 ] = p1[ 1 ];
	p2[ 1 ] = p1[ 0 ];
	_rand_buf[ 1 ] = (short)_rand_buf[ 0 ];
	_rand_buf[ 0 ] = (short)w2;

	return (short)w2;
}

// prepare tables. (110Hz)
bool pxtnPulse_NoiseBuilder_Init()
{
	int32_t    s;
	short  *p;
	double work;

	int32_t    a;
	short  v;

	pxtnPOINT overtones_sine[ 1] = { {1,128} };
	pxtnPOINT overtones_saw2[16] = { { 1,128},{ 2,128},{ 3,128},{ 4,128}, { 5,128},{ 6,128},{ 7,128},{ 8,128},
								{ 9,128},{10,128},{11,128},{12,128}, {13,128},{14,128},{15,128},{16,128},};
	pxtnPOINT overtones_rect2[8] = { {1,128},{3,128},{5,128},{7,128}, {9,128},{11,128},{13,128},{15,128},};

	pxtnPOINT coodi_tri[ 4 ] = { {0,0}, {_smp_num/4,128}, {_smp_num*3/4,(DWORD)-128}, {_smp_num,0} };
	
	int _b_init = 0;

	pxtnPulse_NoiseBuilder_random_reset();

	//_freq = new pxtnPulse_Frequency(); if( !_freq->Init() ) goto End;


	for( s = 0; s < pxWAVETYPE_num; s++ ) _p_tables[ s ] = NULL;

	if( !pxtnMem_zero_alloc( (void **)&_p_tables[ pxWAVETYPE_None    ], sizeof(short) * _smp_num      ) ) goto End;
	if( !pxtnMem_zero_alloc( (void **)&_p_tables[ pxWAVETYPE_Sine    ], sizeof(short) * _smp_num      ) ) goto End;
	if( !pxtnMem_zero_alloc( (void **)&_p_tables[ pxWAVETYPE_Saw     ], sizeof(short) * _smp_num      ) ) goto End;
	if( !pxtnMem_zero_alloc( (void **)&_p_tables[ pxWAVETYPE_Rect    ], sizeof(short) * _smp_num      ) ) goto End;
	if( !pxtnMem_zero_alloc( (void **)&_p_tables[ pxWAVETYPE_Random  ], sizeof(short) * _smp_num_rand ) ) goto End;
	if( !pxtnMem_zero_alloc( (void **)&_p_tables[ pxWAVETYPE_Saw2    ], sizeof(short) * _smp_num      ) ) goto End;
	if( !pxtnMem_zero_alloc( (void **)&_p_tables[ pxWAVETYPE_Rect2   ], sizeof(short) * _smp_num      ) ) goto End;
	// none --

    // sine --
	pxtnPulse_Oscillator_ReadyGetSample( overtones_sine, 1, 128, _smp_num, 0 );
	p = _p_tables[ pxWAVETYPE_Sine ];
	for( s = 0; s < _smp_num; s++ )
	{
		work = pxtnPulse_Oscillator_GetOneSample_Overtone( s ); if( work > 1.0 ) work = 1.0; if( work < -1.0 ) work = -1.0;
		*p = (short)( work * _SAMPLING_TOP );
		p++;
	}

	// saw down --
	p = _p_tables[ pxWAVETYPE_Saw ];
	work = _SAMPLING_TOP + _SAMPLING_TOP;
	for( s = 0; s < _smp_num; s++ ){
		*p = (short)( _SAMPLING_TOP - work * s / _smp_num );
		p++;
	}

	// rect --
	p = _p_tables[ pxWAVETYPE_Rect ];
	for( s = 0; s < _smp_num / 2; s++ ){ *p = (short)( _SAMPLING_TOP  ); p++; }
	for( s    ; s < _smp_num    ; s++ ){ *p = (short)( -_SAMPLING_TOP ); p++; }

	// random -- 
	p = _p_tables[ pxWAVETYPE_Random ];
	pxtnPulse_NoiseBuilder_random_reset();
	for( s = 0; s < _smp_num_rand; s++ ){ *p = pxtnPulse_NoiseBuilder_random_get(); p++; }

    // saw2 --
	pxtnPulse_Oscillator_ReadyGetSample( overtones_saw2, 16, 128, _smp_num, 0 );
	p = _p_tables[ pxWAVETYPE_Saw2 ];
	for( s = 0; s < _smp_num; s++ )
	{
		work = pxtnPulse_Oscillator_GetOneSample_Overtone( s ); if( work > 1.0 ) work = 1.0; if( work < -1.0 ) work = -1.0;
		*p = (short)( work * _SAMPLING_TOP );
		p++;
	}

    // rect2 --
	pxtnPulse_Oscillator_ReadyGetSample( overtones_rect2, 8, 128, _smp_num, 0 );
	p = _p_tables[ pxWAVETYPE_Rect2 ];
	for( s = 0; s < _smp_num; s++ )
	{
		work = pxtnPulse_Oscillator_GetOneSample_Overtone( s ); if( work > 1.0 ) work = 1.0; if( work < -1.0 ) work = -1.0;
		*p = (short)( work * _SAMPLING_TOP );
		p++;
	}

	_b_init = true;
End:

	return _b_init;
}

int pxtnPulse_NoiseBuilder_BuildNoise( pxtnPulse_Noise *p_dst, pxtnPulse_Noise *p_noise, int32_t ch, int32_t sps, int32_t bps ) 
{

	bool           b_ret    = false;
	int32_t        offset   =     0;
	double         work     =     0;
	double         vol      =     0;
	double         fre      =     0;
	double freq;
	double         store    =     0;
	int32_t        byte4    =     0;
	int32_t        unit_num =     0;
	WORD*       p        = NULL ;
	int32_t        smp_num  =     0;

	_UNIT*         units    = NULL ;

	pxtnPulse_Noise_Fix(p_noise);

	unit_num = p_noise->_unit_num;

	if( !pxtnPulse_NoiseBuilder_Init() && !pxtnMem_zero_alloc( (void**)&units, sizeof(_UNIT) * unit_num ) ) goto End;

	for( int32_t u = 0; u < unit_num; u++ )
	{
		_UNIT *pU = &units[ u ];

		pxNOISEDESIGN_UNIT *p_du = &p_noise->_units[u];

		pU->bEnable     = p_du->bEnable;
		pU->enve_num    = p_du->enve_num;
		if(       p_du->pan == 0 )
		{
			pU->pan[ 0 ] = 1;
			pU->pan[ 1 ] = 1;
		}
		else if( p_du->pan < 0 )
		{
			pU->pan[ 0 ] = 1;
			pU->pan[ 1 ] = (double)( 100.0f + p_du->pan ) / 100;
		}
		else
		{
			pU->pan[ 1 ] = 1;
			pU->pan[ 0 ] = (double)( 100.0f - p_du->pan ) / 100;
		}

		if( !pxtnMem_zero_alloc( (void**)&pU->enves, sizeof(_POINT) * pU->enve_num ) ) goto End;

		// envelope
		for( int32_t e = 0; e < p_du->enve_num; e++ )
		{
			pU->enves[ e ].smp =   sps * p_du->enves[ e ].x / 1000;
			pU->enves[ e ].mag = (double)p_du->enves[ e ].y /  100;
		}
		pU->enve_index      = 0;
		pU->enve_mag_start  = 0;
		pU->enve_mag_margin = 0;
		pU->enve_count      = 0;
		while( pU->enve_index < pU->enve_num )
		{
			pU->enve_mag_margin = pU->enves[ pU->enve_index ].mag - pU->enve_mag_start;
			if( pU->enves[ pU->enve_index ].smp ) break;
			pU->enve_mag_start = pU->enves[ pU->enve_index ].mag;
			pU->enve_index++;
		}

		_set_ocsillator( &pU->main, &p_du->main, sps );
		_set_ocsillator( &pU->freq, &p_du->freq, sps );
		_set_ocsillator( &pU->volu, &p_du->volu, sps );
	}

	smp_num = (int32_t)( (double)p_noise->_smp_num_44k / ( 44100.0 / sps ) );
	if ( p_dst->_smp_num_44k )
    {
      free((void*)p_dst->_smp_num_44k);
      p_dst->_smp_num_44k = 0;
    }
	p_dst->_smp_num_44k = *(DWORD*)malloc(bps * ch * smp_num / 8);
    if ( !p_dst->_smp_num_44k )
      return 0;
    p = (WORD*) p_dst->_smp_num_44k;
	for( int32_t s = 0; s < smp_num; s++ )
	{
		for( int32_t c = 0; c < ch; c++ )
		{
			store = 0;
			for( int32_t u = 0; u < unit_num; u++ )
			{
				_UNIT *pU = &units[ u ];
	
				if( pU->bEnable )
				{
					_OSCILLATOR *po;

					// main
					po = &pU->main;
					switch( po->ran_type )
					{
					case _RANDOM_None:
						offset =            (int32_t)po->offset    ;
						if( offset >= 0  ) work = po->p_smp[ offset ];
						else               work = 0;
						break;
					case _RANDOM_Saw:
						if( po->offset >= 0 ) work = po->rdm_start + po->rdm_margin * (int32_t)po->offset / _smp_num;
						else                  work = 0;
						break;
					case _RANDOM_Rect:
						if( po->offset >= 0 ) work = po->rdm_start;
						else                  work = 0;
						break;
					}
					if( po->bReverse ) work *= -1;
					work *= po->volume;
					
					// volu
					po = &pU->volu;
					switch( po->ran_type )
					{
					case _RANDOM_None:
						offset = (int32_t   )po->offset;
						vol    = (double)po->p_smp[ offset ];
						break;
					case _RANDOM_Saw:
						vol = po->rdm_start + po->rdm_margin * (int32_t)po->offset / _smp_num;
						break;
					case _RANDOM_Rect:
						vol = po->rdm_start;
						break;
					}
					if( po->bReverse ) vol *= -1;
					vol *= po->volume;

					work = work * ( vol + _SAMPLING_TOP ) / ( _SAMPLING_TOP * 2 );
					work = work * pU->pan[ c ];

					// envelope
					if( pU->enve_index < pU->enve_num )
						work *= pU->enve_mag_start + ( pU->enve_mag_margin * pU->enve_count / pU->enves[ pU->enve_index ].smp );
					else 
						work *= pU->enve_mag_start;
					store += work;
				}
			}

			byte4 = (int32_t)store;
			if( byte4 >  _SAMPLING_TOP ) byte4 =  _SAMPLING_TOP;
			if( byte4 < -_SAMPLING_TOP ) byte4 = -_SAMPLING_TOP;
			if( bps ==  8 ){ *           p   = (unsigned char)( ( byte4 >> 8 ) + 128 ); p += 1; } //  8bit
			else           { *( (short *)p ) = (short        )    byte4               ; p += 2; } // 16bit
		}

		// incriment
		for( int32_t u = 0; u < unit_num; u++ )
		{
			_UNIT *pU = &units[ u ];

			if( pU->bEnable )
			{
				_OSCILLATOR *po = &pU->freq;

				switch( po->ran_type )
				{
				case _RANDOM_None:
					offset = (int32_t)po->offset    ;
					fre = _KEY_TOP * po->p_smp[ offset ] / _SAMPLING_TOP;
					break;
				case _RANDOM_Saw:
					fre = po->rdm_start + po->rdm_margin * (int32_t) po->offset / _smp_num;
					break;
				case _RANDOM_Rect:
					fre = po->rdm_start;
					break;
				}

				if( po->bReverse ) fre *= -1;
				fre *= po->volume;

				freq = pxtnPulse_Frequency_Get(fre);

				_incriment( &pU->main, pU->main.incriment * freq );
				_incriment( &pU->freq, pU->freq.incriment );
				_incriment( &pU->volu, pU->volu.incriment );

				// envelope
				if( pU->enve_index < pU->enve_num )
				{
					pU->enve_count++;
					if( pU->enve_count >= pU->enves[ pU->enve_index ].smp )
					{
						pU->enve_count      = 0;
						pU->enve_mag_start  = pU->enves[ pU->enve_index ].mag;
						pU->enve_mag_margin = 0;
						pU->enve_index++;
						while( pU->enve_index < pU->enve_num )
						{
							pU->enve_mag_margin = pU->enves[ pU->enve_index ].mag - pU->enve_mag_start;
							if( pU->enves[ pU->enve_index ].smp ) break;
							pU->enve_mag_start  = pU->enves[ pU->enve_index ].mag;
							pU->enve_index++;
						}
					}
				}
			}
		}
	}

	b_ret = true;
End:
	pxtnPulse_NoiseBuilder_deconstructor();

	return b_ret;
}
