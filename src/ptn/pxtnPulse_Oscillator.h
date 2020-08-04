#ifndef pxtnPulse_Oscillator_H
#define pxtnPulse_Oscillator_H

#include "./pxtn.h"

void pxtnPulse_Oscillator_ReadyGetSample( pxtnPOINT *p_point, int32_t point_num, int32_t volume, int32_t sample_num, int32_t point_reso );
double pxtnPulse_Oscillator_GetOneSample_Overtone( int32_t index );
double pxtnPulse_Oscillator_GetOneSample_Coodinate( int32_t index );

#endif
