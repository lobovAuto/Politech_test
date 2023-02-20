
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif

#include "max6691_bus.h"

/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void max6691_Outputs_wrapper(const uint32_T *inputDelta,
			uint8_T *SM,
			maxHLstruct *inStruct,
			maxTempStruct *outStruct,
			uint8_T *timeReady,
			uint32_T *inputTimer)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
uint16_t outR1, outR2, outR3, outR4;
	//static uint16_t errorTime;
	
	switch (*SM)
	{
		case MAX_IDLE:
			if (*timeReady == 1)
			{
				*timeReady = 0;
				*SM = MAX_CONV;
			}
		break;
		
		case MAX_ERROR:
			if (*inputTimer>=TIME_FOR_ERR_RESET) {*SM = MAX_IDLE;}
		break;
		
		case MAX_CONV:	//in this case we waiting end of conversation
			if (*timeReady == 1)
			{
				*timeReady = 0;
				if ((inputDelta<=DATA_CONV_MAX)&(inputDelta>=DATA_CONV_MIN)) //if pulse width in normal range
				{
					*SM = MAX_T_READY;
				}
				else { *SM = MAX_ERROR; *inputTimer = 0;}
			}
		break;
		
		case MAX_T_READY:
			if (*timeReady == 1)
			{
				*timeReady = 0;
				if ((inputDelta<=DATA_READY_MAX)&(inputDelta>=DATA_READY_MIN)) //if pulse width in normal range
				{
					*SM = MAX_T_READY;
				}
				else { *SM = MAX_ERROR; *inputTimer = 0;} 
			} 
			
		break;
		
		case MAX_T1_H:
			if (*timeReady == 1)
			{
				*timeReady = 0;
				inStruct->t1H = inputDelta;
				*SM = MAX_T1_L;
			}
		break;
		
		case MAX_T1_L:
			if (*timeReady == 1)
			{
				*timeReady = 0;
				inStruct->t1L = inputDelta;
				*SM = MAX_T2_H;
				if ((inputDelta>=DATA_T_LOW_MAX)|(inputDelta<=DATA_T_LOW_MIN))
				{ *SM = MAX_ERROR; *inputTimer = 0;}
			}
		break;
		
		case MAX_T2_H:
			if (*timeReady == 1)
			{
				*timeReady = 0;
				inStruct->t2H = inputDelta;
				*SM = MAX_T2_L;
			}
		break;
		
		case MAX_T2_L:
			if (*timeReady == 1)
			{
				*timeReady = 0;
				inStruct->t2L = inputDelta;
				*SM = MAX_T3_H;
			}
			if ((inputDelta>=DATA_T_LOW_MAX)|(inputDelta<=DATA_T_LOW_MIN))
				{ *SM = MAX_ERROR; *inputTimer = 0;}
		break;
		
		case MAX_T3_H:
			if (*timeReady == 1)
			{
				*timeReady = 0;
				inStruct->t3H = inputDelta;
				*SM = MAX_T3_L;
			}
		break;
		
		case MAX_T3_L:
			if (*timeReady == 1)
			{
				*timeReady = 0;
				inStruct->t3L = inputDelta;
				*SM = MAX_T4_H;
			}
			if ((inputDelta>=DATA_T_LOW_MAX)|(inputDelta<=DATA_T_LOW_MIN))
				{ *SM = MAX_ERROR; *inputTimer = 0;}
		break;
		
		case MAX_T4_H:
			if (*timeReady == 1)
			{
				*timeReady = 0;
				inStruct->t4H = inputDelta;
				*SM = MAX_T4_L;
			}
		break;
		
		case MAX_T4_L:
			if (*timeReady == 1)
			{
				*timeReady = 0;
				inStruct->t4L = inputDelta;
				*SM = MAX_Processing;
			}
			if ((inputDelta>=DATA_T_LOW_MAX)|(inputDelta<=DATA_T_LOW_MIN))
				{ *SM = MAX_ERROR; *inputTimer = 0;}
		break;
		
		case MAX_Processing:
				timeToResist(inStruct->t1H, inStruct->t1L, EXT_RESIST, &outR1);
				LookupTable((float)outR1, &outStruct->t1, yAxis1, xAxis1, 2);
				checkHighTimeToErr(inStruct->t1H, &outStruct->t1_valid);
				timeToResist(inStruct->t2H, inStruct->t2L, EXT_RESIST, &outR2);
				LookupTable((float)outR2, &outStruct->t2, yAxis2, xAxis2, 2);
				checkHighTimeToErr(inStruct->t2H, &outStruct->t2_valid);
				timeToResist(inStruct->t3H, inStruct->t3L, EXT_RESIST, &outR3);
				LookupTable((float)outR3, &outStruct->t3, yAxis3, xAxis3, 2);
				checkHighTimeToErr(inStruct->t3H, &outStruct->t3_valid);
				timeToResist(inStruct->t4H, inStruct->t4L, EXT_RESIST, &outR4);
				LookupTable((float)outR4, &outStruct->t4, yAxis4, xAxis4, 2);
				checkHighTimeToErr(inStruct->t4H, &outStruct->t4_valid);
				outStruct->tempProcFinished = 1;
				*SM = MAX_IDLE;
			
		break;
		
		
	}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


