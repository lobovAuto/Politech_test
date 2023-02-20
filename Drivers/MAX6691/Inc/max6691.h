#ifndef MAX6691_H
#define MAX6691_H
#include "main.h"
//#include "gd32f4xx.h"


typedef struct name{
	float t1;
	uint8_t t1_valid;
	float t2;
	uint8_t t2_valid;
	float t3;
	uint8_t t3_valid;
	float t4;
	uint8_t t4_valid;
	uint8_t tempProcFinished;
} maxTempStruct;

//Params for tune
#define EXT_RESIST		10000 // External resister. Typically 10kOhm
#define MAX_IN_PORT		RCU_GPIOA // set port for input pin
#define MAX_EXTI_PORT	EXTI_SOURCE_GPIOA// set port for exti
#define MAX_IN_PIN		GPIO_PIN_0//set pin for input
#define MAX_EXTI_PIN	EXTI_SOURCE_PIN0//set input pin as exti
#define MAX_EXTI			EXTI_0//again set pin as exti line
#define MAX_EXTI_IRQn	EXTI0_IRQn//switch on necessesary interrupt
//pins 0-3 - EXTI0, pins 4-7 - EXTI1, pins 8-11 - EXTI 2, pins 12-15 - EXTI 3
#define MAX_IRQ_HANDLER	EXTI0_IRQHandler
//pins 0-3 - EXTI0_IRQHandler, pins 4-7 - EXTI1_IRQHandler, 
//pins 8-11 - EXTI2_IRQHandler, pins 12-15 - EXTI3_IRQHandler
#define MAX_OUT_PORT 	RCU_GPIOA// set port for out pin
#define MAX_OUT_PIN		GPIO_PIN_1


#define TIME_FOR_ERR_RESET	200000
#define TIME_START_PULSE		10

#define DATA_READY_MAX	188
#define DATA_READY_MIN	103
#define DATA_CONV_MAX		156000
#define DATA_CONV_MIN		86000
#define DATA_T_LOW_MAX	7500
#define DATA_T_LOW_MIN	4000
#define DATA_T_H_E_MAX	188
#define DATA_T_H_E_MIN	103

//

#define MAX6691_NUM_THERMISTORS 4

typedef enum  {
MAX_IDLE = 				0,
MAX_ERROR = 			1,
MAX_CONV = 				2,
MAX_T_READY = 		3,
MAX_T1_H = 				4,
MAX_T1_L = 				5,
MAX_T2_H = 				6,
MAX_T2_L = 				7,
MAX_T3_H = 				8,
MAX_T3_L = 				9,
MAX_T4_H = 				10,
MAX_T4_L = 				11,
MAX_Processing =	12,
} MAX6691_StateMachine;

typedef struct  {
	uint32_t t1H;
	uint32_t t1L;
	uint32_t t2H;
	uint32_t t2L;
	uint32_t t3H;
	uint32_t t3L;
	uint32_t t4H;
	uint32_t t4L;
	//uint8_t timeCollectFinished;
} maxHLstruct;




typedef enum  {
	MAX6691_SUCCESS = 0,
	// define error codes according to the datasheet
}MAX6691Status;

/**
 * @brief Initialize all the hardware and variables.
 * 
 * @return enum MAX6691Status Error code or 0 for success
 */
MAX6691Status max6691_init(void);

/**
 * @brief Blocking read of temperatures.
 * Start the conversion, wait for MAX6691 to be ready, get the result.
 * 
 * @param thermistors Where to put temperatures, in deg. Celcius
 * @return MAX6691Status Error code or 0 for success
 */
MAX6691Status max6691_read_blocking(float *thermistors);

/**
 * @brief Force MAX6691 to start the conversion.
 * 
 * @return MAX6691Status Error code or 0 for success.
 */
MAX6691Status max_6691_start(void);

/**
 * @brief Check whether the result is ready and get it.
 * 
 * @param thermistors Where to put acquired values (if conversion is ready).
 * @return MAX6691Status Error code, or Conversion in progress status, or Conversion Ready status.
 */
MAX6691Status max_6691_get(float *thermistors);



void max_6691 (MAX6691_StateMachine *SM, uint32_t inputDelta, maxHLstruct *inStruct,
							 maxTempStruct *outStruct, uint8_t *timeReady, uint32_t *inputTimer);

#endif // MAX6691_H
