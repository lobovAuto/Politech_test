#include "max6691.h"
//params for tune:
float yAxis1[2] = { -55, 125 }; //temp
float xAxis1[2] = { 400, 800 }; //resistance
float yAxis2[2] = { -55, 125 };
float xAxis2[2] = { 400, 800 };
float yAxis3[2] = { -55, 125 };
float xAxis3[2] = { 400, 800 };
float yAxis4[2] = { -55, 125 };
float xAxis4[2] = { 400, 800 };
//

void timeToResist(uint32_t tHigh, uint32_t tLow, uint32_t rRef,
		  uint16_t *rTherm)
{
	float div = (float)tHigh / (float)tLow;
	*rTherm =
		(uint16_t)(((float)rRef / (div - (float)0.0002)) - (float)rRef);
}

void checkHighTimeToErr(uint32_t tHigh, uint8_t *validFlag)
{
	if ((tHigh <= DATA_T_H_E_MAX) & (tHigh >= DATA_T_H_E_MIN)) {
		*validFlag = 0;
	} else {
		*validFlag = 1;
	}
}

void max_6691(MAX6691_StateMachine *SM, uint32_t inputDelta,
	      maxHLstruct *inStruct, maxTempStruct *outStruct,
	      uint8_t *timeReady, uint32_t *inputTimer)
{
	uint16_t outR1, outR2, outR3, outR4;
	static uint32_t setStartBitTime = 0;
	//static uint16_t errorTime;

	switch (*SM) {
	case MAX_IDLE:
		if ((*inputTimer >= 100000) & (setStartBitTime == 0)) {
			setStartBitTime = *inputTimer;
		}
		if (*inputTimer < (setStartBitTime + TIME_START_PULSE)) {
			gpio_bit_set(MAX_OUT_PORT, MAX_OUT_PIN);
		}
		if (*inputTimer >= (setStartBitTime + TIME_START_PULSE)) {
			gpio_bit_reset(MAX_OUT_PORT, MAX_OUT_PIN);
		}

		if (*timeReady == 1) {
			*timeReady = 0;
			*SM = MAX_CONV;
			setStartBitTime = 0;
		}
		break;

	case MAX_ERROR:
		if (*inputTimer >= TIME_FOR_ERR_RESET) {
			*SM = MAX_IDLE;
			*inputTimer = 0;
		}
		break;

	case MAX_CONV: //in this case we waiting end of conversation
		if (*timeReady == 1) {
			*timeReady = 0;
			if ((inputDelta <= DATA_CONV_MAX) &
			    (inputDelta >=
			     DATA_CONV_MIN)) //if pulse width in normal range
			{
				*SM = MAX_T_READY;
			} else {
				*SM = MAX_ERROR;
				*inputTimer = 0;
			}
		}
		break;

	case MAX_T_READY:
		if (*timeReady == 1) {
			*timeReady = 0;
			if ((inputDelta <= DATA_READY_MAX) &
			    (inputDelta >=
			     DATA_READY_MIN)) //if pulse width in normal range
			{
				*SM = MAX_T_READY;
			} else {
				*SM = MAX_ERROR;
				*inputTimer = 0;
			}
		}

		break;

	case MAX_T1_H:
		if (*timeReady == 1) {
			*timeReady = 0;
			inStruct->t1H = inputDelta;
			*SM = MAX_T1_L;
		}
		break;

	case MAX_T1_L:
		if (*timeReady == 1) {
			*timeReady = 0;
			inStruct->t1L = inputDelta;
			*SM = MAX_T2_H;
			if ((inputDelta >= DATA_T_LOW_MAX) |
			    (inputDelta <= DATA_T_LOW_MIN)) {
				*SM = MAX_ERROR;
				*inputTimer = 0;
			}
		}
		break;

	case MAX_T2_H:
		if (*timeReady == 1) {
			*timeReady = 0;
			inStruct->t2H = inputDelta;
			*SM = MAX_T2_L;
		}
		break;

	case MAX_T2_L:
		if (*timeReady == 1) {
			*timeReady = 0;
			inStruct->t2L = inputDelta;
			*SM = MAX_T3_H;
		}
		if ((inputDelta >= DATA_T_LOW_MAX) |
		    (inputDelta <= DATA_T_LOW_MIN)) {
			*SM = MAX_ERROR;
			*inputTimer = 0;
		}
		break;

	case MAX_T3_H:
		if (*timeReady == 1) {
			*timeReady = 0;
			inStruct->t3H = inputDelta;
			*SM = MAX_T3_L;
		}
		break;

	case MAX_T3_L:
		if (*timeReady == 1) {
			*timeReady = 0;
			inStruct->t3L = inputDelta;
			*SM = MAX_T4_H;
		}
		if ((inputDelta >= DATA_T_LOW_MAX) |
		    (inputDelta <= DATA_T_LOW_MIN)) {
			*SM = MAX_ERROR;
			*inputTimer = 0;
		}
		break;

	case MAX_T4_H:
		if (*timeReady == 1) {
			*timeReady = 0;
			inStruct->t4H = inputDelta;
			*SM = MAX_T4_L;
		}
		break;

	case MAX_T4_L:
		if (*timeReady == 1) {
			*timeReady = 0;
			inStruct->t4L = inputDelta;
			*SM = MAX_Processing;
		}
		if ((inputDelta >= DATA_T_LOW_MAX) |
		    (inputDelta <= DATA_T_LOW_MIN)) {
			*SM = MAX_ERROR;
			*inputTimer = 0;
		}
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
		*inputTimer = 0;

		break;
	}
}

MAX6691Status max6691_init()
{
	rcu_periph_clock_enable(MAX_IN_PORT); //switch on rcc for input port
	gpio_mode_set(MAX_IN_PORT, GPIO_MODE_INPUT, GPIO_PUPD_NONE, MAX_IN_PIN);
	gpio_output_options_set(MAX_IN_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ,
				MAX_IN_PIN);
	nvic_irq_enable(MAX_EXTI_IRQn, 2U, 0U); // This is not accurate
	syscfg_exti_line_config(MAX_EXTI_PORT, MAX_EXTI_PIN);
	exti_init(MAX_EXTI, EXTI_INTERRUPT, EXTI_TRIG_BOTH);
	//exti_interrupt_flag_clear(MAX_EXTI);

	rcu_periph_clock_enable(MAX_OUT_PORT); //switch on rcc for input port
	gpio_mode_set(MAX_OUT_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE,
		      MAX_OUT_PIN);
	gpio_output_options_set(MAX_OUT_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ,
				MAX_OUT_PIN);

	return MAX6691_SUCCESS;
}

void MAX_IRQ_HANDLER(void)
{
	static uint32_t timeStart = 0;
	if (exti_interrupt_flag_get(MAX_EXTI) == SET) //if flag was set
	{
		exti_interrupt_flag_clear(MAX_EXTI); //clear flag

		if (timeStart == 0) {
			timeStart = MAX_IRQ_inputTimer;
		} else {
			deltaTime = MAX_IRQ_inputTimer - timeStart;
			timeStart = MAX_IRQ_inputTimer;
			timeReady = 1;
		}

		if (smMaxToInterrupt == MAX_T4_L) {
			timeStart = 0;
		} //reset the start time at the end of measurements
	}
}
