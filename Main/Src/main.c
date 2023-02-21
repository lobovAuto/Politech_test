#include "main.h"

uint32_t maxTimer;
uint32_t MAX_IRQ_inputTimer = 0;
uint32_t deltaTime = 0;
uint8_t timeReady = 0;
uint8_t smMaxToInterrupt = 0;

void SysTick_Handler(void)
{
	if (maxTimer < 1000000) {
		maxTimer++;
	}
	MAX_IRQ_inputTimer++;
}

float valueToStrin (float temp, uint8_t valid, uint8_t number)
{
	char temporary[50];
	if (valid == 1)
	{
		sprintf(temporary, "Temp on %u thermistor - %fC\r\n", number, temp);
		return *temporary;
	}
	else
	{
		sprintf(temporary, "Value on %u thermistor is invalid\r\n", number);
		return *temporary;
	}
}

int main(void)
{
	SysTick_Config(SystemCoreClock / 200); //1 µs
	char USARTbuffer[200];
	MAX6691_StateMachine SM = 0;
	uint32_t delta = 0;
	maxHLstruct timeStruct;
	maxTempStruct tempStruct;
	uint8_t timeReady = 0;

	USART_init(USARTbuffer);
	max6691_init();

	while (1) {
		max_6691(&SM, delta, &timeStruct, &tempStruct, &timeReady,
			 &maxTimer);
		smMaxToInterrupt = SM;
		sprintf(USARTbuffer,"%f%f%f%f",valueToStrin(tempStruct.t1, tempStruct.t1_valid, 1),
							valueToStrin(tempStruct.t2, tempStruct.t2_valid, 2),
							valueToStrin(tempStruct.t3, tempStruct.t3_valid, 3),
							valueToStrin(tempStruct.t4, tempStruct.t4_valid, 4));
		USART_printTemp(USARTbuffer, &tempStruct.tempProcFinished);
	}
}

/*__attribute__((weak)) MAX6691Status max6691_init(void)
{
	return MAX6691_SUCCESS;
}

__attribute__((weak)) MAX6691Status
max6691_read_blocking(float *thermistors)
{
	(void)thermistors;
	return MAX6691_SUCCESS;
}

__attribute__((weak)) MAX6691Status max_6691_start(void)
{
	return MAX6691_SUCCESS;
}

__attribute__((weak)) MAX6691Status max_6691_get(float *thermistors)
{
	(void)thermistors;
	return MAX6691_SUCCESS;
} */

/*__attribute__((weak)) enum USARTStatus USART_init(void)
{
	return USART_SUCCESS;
} */

/*__attribute__((weak)) enum USARTStatus USART_printf(char const *fmt, ...)
{
	(void)fmt;
	return USART_SUCCESS;
} */
