#ifndef USART_H
#define USART_H

#include "main.h"
//#include "max6691.h"
void USART_printTemp (char *inBuffer, uint8_t *flag);

#define USART_PORT					GPIOA
#define USART_NAME					RCU_USART0
#define USART_X							USART0
#define USART_DATA_ADDRESS	((uint32_t)&USART_DATA(USART_X))
#define BAUDRATE						9600U
#define PERIPH_PORT					RCU_GPIOA
#define USART_PIN_Tx				GPIO_PIN_9
#define USART_PIN_Rx				GPIO_PIN_10
#define AltFuncNum					GPIO_AF_7

#define DMA_X					DMA1
#define CHANNEL_X			DMA_CH7
#define DMA_SUBPERIPH	DMA_SUBPERI4

#define ITfunc	DMA1_Channel7_IRQHandler



enum USARTStatus {
	USART_SUCCESS = 0,
};

/**
 * @brief Init the USART hardware.
 * 
 * @return enum USARTStatus Error code or Success.
 */
//enum USARTStatus USART_init(void);
void USART_init(char *inBuffer);

/**
 * @brief Send formatted text to the USART.
 * 
 * @param fmt Format string.
 * @param ... Substitution arguments, as in XXXprintf
 * @return enum USARTStatus Error code or Success.
 */
enum USARTStatus USART_printf(char const *fmt, ...);

#endif // USART_H
