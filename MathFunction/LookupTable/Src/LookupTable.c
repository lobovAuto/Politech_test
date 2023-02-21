#include "LookupTable.h"

void BinarySearch_float(uint32_t *iLeft, uint32_t *iRight, uint32_t iMax,
			float u, float *ValuesOnAxis)
{
	*iLeft = 0;
	*iRight = iMax;

	if (u < ValuesOnAxis[*iLeft]) {
		*iRight = *iLeft;
	} else if (u > ValuesOnAxis[*iRight]) {
		*iLeft = *iRight;
	} else {
		uint32_t i;
		while ((*iRight - *iLeft) > 1) {
			i = (*iRight + *iLeft) >> 1;
			if (u < ValuesOnAxis[i]) {
				*iRight = i;
			} else {
				*iLeft = i;
			}
		}
	}
}

void LookupTable(float input, float *output, float *ValuesOnAxis_y,
		 float *ValuesOnAxis_x, uint32_t numberValueInArray_x)
{
	uint32_t iLeft;
	uint32_t iRight;
	float lambda;
	float yLeft, yRight;
	uint32_t tempValueInArray_x = numberValueInArray_x - 1;
	BinarySearch_float(&iLeft, &iRight, tempValueInArray_x, input,
			   ValuesOnAxis_x);

	if (ValuesOnAxis_x[iRight] > ValuesOnAxis_x[iLeft]) {
		float num, den;
		den = ValuesOnAxis_x[iRight];
		den -= ValuesOnAxis_x[iLeft];
		num = input;
		num -= ValuesOnAxis_x[iLeft];
		lambda = num / den;
	} else {
		lambda = 0;
	}

	yLeft = ValuesOnAxis_y[iLeft];
	yRight = ValuesOnAxis_y[iRight];
	yLeft += lambda * (yRight - yLeft);
	*output = yLeft;
}
//
