#ifndef MAIN_H
#define MAIN_H

#include <stdint.h>
#include "gd32f4xx.h"
#include "max6691.h"
#include "USART.h"
#include "LookupTable.h"

extern uint32_t MAX_IRQ_inputTimer;
extern uint32_t deltaTime;
extern uint8_t timeReady;
extern uint8_t smMaxToInterrupt;

#endif
