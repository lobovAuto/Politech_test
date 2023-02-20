#include "USART.h"

void USART_init(char *inBuffer)
{
	/* port setting part*/
	rcu_periph_clock_enable(PERIPH_PORT); // enable GPIO clock
	rcu_periph_clock_enable(USART_NAME); // enable USART clock 
	gpio_af_set(USART_PORT, AltFuncNum, USART_PIN_Tx);  // configure the USART TX pin
	gpio_af_set(USART_PORT, AltFuncNum, USART_PIN_Rx);	// configure the USART RX pin
	/* configure USART TX as alternate function push-pull */
	gpio_mode_set(USART_PORT, GPIO_MODE_AF, GPIO_PUPD_PULLUP, USART_PIN_Tx);	
  gpio_output_options_set(USART_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, USART_PIN_Tx);
	/* configure USART RX as alternate function push-pull */
  gpio_mode_set(USART_PORT, GPIO_MODE_AF, GPIO_PUPD_PULLUP, USART_PIN_Rx);
  gpio_output_options_set(USART_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, USART_PIN_Rx);
	/* USART configure */
  usart_deinit(USART_X);
  usart_baudrate_set(USART_X, BAUDRATE);
  usart_receive_config(USART_X, USART_RECEIVE_DISABLE);
  usart_transmit_config(USART_X, USART_TRANSMIT_ENABLE);
  usart_enable(USART_X);
	/*DMA setting part*/
	dma_single_data_parameter_struct dma_init_struct;
	dma_deinit(DMA_X, CHANNEL_X);
	dma_init_struct.direction = DMA_MEMORY_TO_PERIPH;
	dma_init_struct.memory0_addr = (uint32_t)inBuffer;
	dma_init_struct.memory_inc = DMA_MEMORY_INCREASE_ENABLE;
	dma_init_struct.periph_memory_width = DMA_PERIPH_WIDTH_8BIT;
	dma_init_struct.number = sizeof(inBuffer);
	dma_init_struct.periph_addr = USART_DATA_ADDRESS;
	dma_init_struct.periph_inc = DMA_PERIPH_INCREASE_DISABLE;
	dma_init_struct.priority = DMA_PRIORITY_ULTRA_HIGH;
	dma_single_data_mode_init(DMA_X, CHANNEL_X, &dma_init_struct);
	/* configure DMA mode */
  dma_circulation_disable(DMA_X, CHANNEL_X);
  dma_channel_subperipheral_select(DMA_X, CHANNEL_X, DMA_SUBPERIPH);
	/* enable DMAx channel_x transfer complete interrupt */
  dma_interrupt_enable(DMA_X, CHANNEL_X, DMA_CHXCTL_FTFIE);
  /* enable DMAX channel_x */
  dma_channel_enable(DMA_X, CHANNEL_X);
	
	usart_dma_transmit_config(USART_X, USART_TRANSMIT_DMA_ENABLE);
	
}
//
void USART_printTemp (char *inBuffer, uint8_t *flag)
{
	if (*flag==1)
	{
		*flag = 0;
		DMA_CHM0ADDR(DMA_X, CHANNEL_X) = (uint32_t)inBuffer;
		dma_channel_enable(DMA_X, CHANNEL_X);
		
	}
}

void ITfunc (void)
{
	if (dma_interrupt_flag_get(DMA_X, CHANNEL_X, DMA_INT_FLAG_FTF)==SET)
	{
		dma_interrupt_flag_clear(DMA_X, CHANNEL_X, DMA_INT_FLAG_FTF);
		dma_channel_disable(DMA_X, CHANNEL_X);
	}
}
//
