
#ifndef pxtnPulse_Noise_H
#define pxtnPulse_Noise_H
#endif

#include "./pxtn.h"

#include "windows.h"

//#include "./pxtnDescriptor.h"
#include "./pxtnPulse_Frequency.h"
#include "./pxtnPulse_Oscillator.h"
//#include "./pxtnPulse_PCM.h"

enum pxWAVETYPE
{
	pxWAVETYPE_None = 0,
	pxWAVETYPE_Sine,
	pxWAVETYPE_Saw,
	pxWAVETYPE_Rect,
	pxWAVETYPE_Random,
	pxWAVETYPE_Saw2,
	pxWAVETYPE_Rect2,

	pxWAVETYPE_Tri    ,
	pxWAVETYPE_Random2,
	pxWAVETYPE_Rect3  ,
	pxWAVETYPE_Rect4  ,
	pxWAVETYPE_Rect8  ,
	pxWAVETYPE_Rect16 ,
	pxWAVETYPE_Saw3   ,
	pxWAVETYPE_Saw4   ,
	pxWAVETYPE_Saw6   ,
	pxWAVETYPE_Saw8   ,

	pxWAVETYPE_num,
};

typedef struct
{
	pxWAVETYPE type  ;
	float      freq  ;
	float      volume;
	float      offset;
	bool       b_rev ;
}
pxNOISEDESIGN_OSCILLATOR;

typedef struct
{
	bool                     bEnable ;
	DWORD                    enve_num;
	pxtnPOINT*               enves   ;
	int32_t                  pan     ;
	pxNOISEDESIGN_OSCILLATOR main    ;
	pxNOISEDESIGN_OSCILLATOR freq    ;
	pxNOISEDESIGN_OSCILLATOR volu    ;
}
pxNOISEDESIGN_UNIT;


typedef struct pxtnPulse_Noise
{
	DWORD               _smp_num_44k;
	DWORD               _unit_num   ;
	pxNOISEDESIGN_UNIT* _units      ;
}
pxtnPulse_Noise;

void _FixUnit( pxNOISEDESIGN_OSCILLATOR *p_osc );
void* pxtnPulse_Noise_Release(pxtnPulse_Noise *pdst);