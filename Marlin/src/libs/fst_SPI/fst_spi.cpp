#include "fst_spi.h"




SPI_HandleTypeDef	hFstSpi;
DMA_HandleTypeDef	hTouchSpiDmaRx;
DMA_HandleTypeDef	hTouchSpiDmaTx;
uint8_t						touch_buff[TOUCH_BUFF_SIZE];

DMA_HandleTypeDef	hFlashSpiDmaRx;
DMA_HandleTypeDef	hFlashSpiDmaTx;






void		HAL_SPI_TxRxCpltCallback(SPI_HandleTypeDef *hspi)
{
	if (hspi->Instance == hFstSpi.Instance)
		_touch_CS_Disable();
}
//==============================================================================




void 		HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi)
{
	_flash_CS_Disable();
}










uint16_t	_fst_SPIGetFlags()
{
	return hFstSpi.Instance->SR;
}
//==============================================================================




void		FST_SPIInit(void)
{
	
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	FST_SPI_CLK_ENABLE();

	// TOUCH_SPI GPIO Configuration    
	GPIO_InitStruct.Pin = FST_SPI_MISO_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Alternate = FST_SPI_GPIO_ALTERNATE;
	HAL_GPIO_Init(FST_SPI_MISO_GPIO, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = FST_SPI_MOSI_Pin;
	HAL_GPIO_Init(FST_SPI_MOSI_GPIO, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = FST_SPI_SCK_Pin;
	HAL_GPIO_Init(FST_SPI_SCK_GPIO, &GPIO_InitStruct);

	// Touch CS
	_touch_CS_Disable();
	GPIO_InitStruct.Pin = FST_SPI_CS_TOUCH_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(FST_SPI_CS_TOUCH_GPIO, &GPIO_InitStruct);


	// FLASH CS
	GPIO_InitStruct.Pin = FST_SPI_CS_FLASH_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(FST_SPI_CS_FLASH_GPIO, &GPIO_InitStruct);


	// Prepare SPI for TOUCH operations
	hFstSpi.Instance = FST_SPI;
	hFstSpi.Init.Mode = SPI_MODE_MASTER;
	hFstSpi.Init.Direction = SPI_DIRECTION_2LINES;
	hFstSpi.Init.DataSize = SPI_DATASIZE_8BIT;
	hFstSpi.Init.CLKPolarity = SPI_POLARITY_LOW;
	hFstSpi.Init.CLKPhase = SPI_PHASE_1EDGE;
	hFstSpi.Init.NSS = SPI_NSS_SOFT;
	hFstSpi.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_32;
	hFstSpi.Init.FirstBit = SPI_FIRSTBIT_MSB;
	hFstSpi.Init.TIMode = SPI_TIMODE_DISABLE;
	hFstSpi.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
	hFstSpi.Init.CRCPolynomial = 10;
	FST_SPI_CLK_ENABLE();
	HAL_SPI_Init(&hFstSpi);
}
//==============================================================================




HAL_SPI_StateTypeDef	FST_SPIGetState()
{
	return hFstSpi.State;
}
//==============================================================================




// prescaler - SPI_BAUDRATEPRESCALER_2/4/8/16/32/64/128/256
// APB2 clock is 84Mhz
void		FST_SPISetSpeed(uint16_t prescaler)
{
	// Clear baudrate bits
	hFstSpi.Instance->CR1 &= ~(SPI_CR1_BR_2 | SPI_CR1_BR_1 | SPI_CR1_BR_0);
	// Set new baudrate bits
	hFstSpi.Instance->CR1 |= prescaler;	// Set SPI speed
}
//==============================================================================




// return baudrate bits value - SPI_BAUDRATEPRESCALER_2/4/8/16/32/64/128/256
uint16_t		FST_SPIGetSpeed()
{
	return hFstSpi.Instance->CR1 & (SPI_CR1_BR_2 | SPI_CR1_BR_1 | SPI_CR1_BR_0);
}
//==============================================================================












void		TOUCH_SPIEnable()
{
	// DMA
	FST_SPI_DMA_CLK_ENABLE();

	// Prepare SPI for Touch
	hFstSpi.Instance = FST_SPI;
	hFstSpi.Init.Mode = SPI_MODE_MASTER;
	hFstSpi.Init.Direction = SPI_DIRECTION_2LINES;
	hFstSpi.Init.DataSize = SPI_DATASIZE_8BIT;
	hFstSpi.Init.CLKPolarity = SPI_POLARITY_LOW;
	hFstSpi.Init.CLKPhase = SPI_PHASE_1EDGE;
	hFstSpi.Init.NSS = SPI_NSS_SOFT;
	hFstSpi.Init.BaudRatePrescaler = FST_SPI_LOW_CLOCKSPEED;
	hFstSpi.Init.FirstBit = SPI_FIRSTBIT_MSB;
	hFstSpi.Init.TIMode = SPI_TIMODE_DISABLE;
	hFstSpi.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
	hFstSpi.Init.CRCPolynomial = 10;
	FST_SPI_CLK_ENABLE();
	HAL_SPI_Init(&hFstSpi);

	hTouchSpiDmaRx.Instance = FST_SPI_DMA_STREAM1;
	hTouchSpiDmaRx.Init.Channel = FST_SPI_DMA_CHANNEL1;
	hTouchSpiDmaRx.Init.Direction = DMA_PERIPH_TO_MEMORY;
	hTouchSpiDmaRx.Init.PeriphInc = DMA_PINC_DISABLE;
	hTouchSpiDmaRx.Init.MemInc = DMA_MINC_ENABLE;
	hTouchSpiDmaRx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
	hTouchSpiDmaRx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
	hTouchSpiDmaRx.Init.Mode = DMA_NORMAL;
	hTouchSpiDmaRx.Init.Priority = DMA_PRIORITY_LOW;
	hTouchSpiDmaRx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
	HAL_DMA_Init(&hTouchSpiDmaRx);   
	__HAL_LINKDMA(&hFstSpi, hFstSpi.hdmarx, hTouchSpiDmaRx);

	hTouchSpiDmaTx.Instance = FST_SPI_DMA_STREAM2;
	hTouchSpiDmaTx.Init.Channel = FST_SPI_DMA_CHANNEL2;
	hTouchSpiDmaTx.Init.Direction = DMA_MEMORY_TO_PERIPH;
	hTouchSpiDmaTx.Init.PeriphInc = DMA_PINC_DISABLE;
	hTouchSpiDmaTx.Init.MemInc = DMA_MINC_ENABLE;
	hTouchSpiDmaTx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
	hTouchSpiDmaTx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
	hTouchSpiDmaTx.Init.Mode = DMA_NORMAL;
	hTouchSpiDmaTx.Init.Priority = DMA_PRIORITY_LOW;
	hTouchSpiDmaTx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
	HAL_DMA_Init(&hTouchSpiDmaTx);
	__HAL_LINKDMA(&hFstSpi, hFstSpi.hdmatx, hTouchSpiDmaTx);

	// DMA interrupt init
	// DMA1_Stream3_IRQn interrupt configuration
	HAL_NVIC_SetPriority(FST_SPI_DMA_STREAM1_IRQ, 0, 0);
	HAL_NVIC_EnableIRQ(FST_SPI_DMA_STREAM1_IRQ);
	
	// DMA1_Stream4_IRQn interrupt configuration
	HAL_NVIC_SetPriority(FST_SPI_DMA_STREAM2_IRQ, 0, 0);
	HAL_NVIC_EnableIRQ(FST_SPI_DMA_STREAM2_IRQ);

	hFstSpi.Instance->CR1 |= SPI_CR1_SPE;
}
//==============================================================================




void		TOUCH_SPIDisable()
{
	HAL_SPI_Abort(hFstSpi.Instance);
	hFstSpi.Instance->CR1 &= ~SPI_CR1_SPE;
	HAL_DMA_DeInit(hFstSpi.hdmarx);
	HAL_DMA_DeInit(hFstSpi.hdmatx);
}
//==============================================================================




void		TOUCH_SPIStartRead()
{
	_touch_CS_Enable();
	memset(touch_buff, 0, TOUCH_BUFF_SIZE);
	
	for (uint8_t i = 0; i < TOUCH_BUFF_SIZE; i+=6)
		touch_buff[i] = 0x90;
	for (uint8_t i = 3; i < TOUCH_BUFF_SIZE; i+=6)
		touch_buff[i] = 0xD0;

	HAL_SPI_TransmitReceive_DMA(&hFstSpi, touch_buff, touch_buff, sizeof(touch_buff));
}
//==============================================================================

















void		FLASH_SPIEnable()
{
	// Prepare SPI for Flash
	hFstSpi.Instance = FST_SPI;
	hFstSpi.Init.Mode = SPI_MODE_MASTER;
	hFstSpi.Init.Direction = SPI_DIRECTION_2LINES;
	hFstSpi.Init.DataSize = SPI_DATASIZE_8BIT;
	hFstSpi.Init.CLKPolarity = SPI_POLARITY_HIGH;
	hFstSpi.Init.CLKPhase = SPI_PHASE_2EDGE;
	hFstSpi.Init.NSS = SPI_NSS_SOFT;
	hFstSpi.Init.BaudRatePrescaler = FST_SPI_HIGH_CLOCKSPEED;
	hFstSpi.Init.FirstBit = SPI_FIRSTBIT_MSB;
	hFstSpi.Init.TIMode = SPI_TIMODE_DISABLE;
	hFstSpi.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
	hFstSpi.Init.CRCPolynomial = 10;
	FST_SPI_CLK_ENABLE();
	HAL_SPI_Init(&hFstSpi);

	// DMA
	FST_SPI_DMA_CLK_ENABLE();
	
	// SPI1_RX Init
	hFlashSpiDmaRx.Instance = FST_SPI_DMA_STREAM1;
	hFlashSpiDmaRx.Init.Channel = FST_SPI_DMA_CHANNEL1;
	hFlashSpiDmaRx.Init.Direction = DMA_PERIPH_TO_MEMORY;
	hFlashSpiDmaRx.Init.PeriphInc = DMA_PINC_DISABLE;
	hFlashSpiDmaRx.Init.MemInc = DMA_MINC_ENABLE;
	hFlashSpiDmaRx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
	hFlashSpiDmaRx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
	hFlashSpiDmaRx.Init.Mode = DMA_NORMAL;
	hFlashSpiDmaRx.Init.Priority = DMA_PRIORITY_LOW;
	hFlashSpiDmaRx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
	HAL_DMA_Init(&hFlashSpiDmaRx);
	__HAL_LINKDMA(&hFstSpi, hdmarx, hFlashSpiDmaRx);

	// SPI1_TX Init
	hFlashSpiDmaTx.Instance = FST_SPI_DMA_STREAM2;
	hFlashSpiDmaTx.Init.Channel = FST_SPI_DMA_CHANNEL2;
	hFlashSpiDmaTx.Init.Direction = DMA_MEMORY_TO_PERIPH;
	hFlashSpiDmaTx.Init.PeriphInc = DMA_PINC_DISABLE;
	hFlashSpiDmaTx.Init.MemInc = DMA_MINC_ENABLE;
	hFlashSpiDmaTx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
	hFlashSpiDmaTx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
	hFlashSpiDmaTx.Init.Mode = DMA_NORMAL;
	hFlashSpiDmaTx.Init.Priority = DMA_PRIORITY_LOW;
	hFlashSpiDmaTx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
	HAL_DMA_Init(&hFlashSpiDmaTx);
	__HAL_LINKDMA(&hFstSpi, hFstSpi.hdmatx, hFlashSpiDmaTx);

	// DMA interrupt init
	// DMA2_Stream2_IRQn interrupt configuration
	HAL_NVIC_SetPriority(FST_SPI_DMA_STREAM1_IRQ, 0, 0);
	HAL_NVIC_EnableIRQ(FST_SPI_DMA_STREAM1_IRQ);
	// DMA2_Stream5_IRQn interrupt configuration
	HAL_NVIC_SetPriority(FST_SPI_DMA_STREAM2_IRQ, 0, 0);
	HAL_NVIC_EnableIRQ(FST_SPI_DMA_STREAM2_IRQ);

	hFstSpi.Instance->CR1 |= SPI_CR1_SPE;
}
//==============================================================================




void		FLASH_SPIDisable()
{
	HAL_SPI_Abort(hFstSpi.Instance);
	hFlashSpi.Instance->CR1 &= ~SPI_CR1_SPE;

	/* SPI1 DMA DeInit */
	HAL_DMA_DeInit(hFlashSpi.hdmarx);
	HAL_DMA_DeInit(hFlashSpi.hdmatx);
}
//==============================================================================




uint8_t		FLASH_SPIWriteReadByte(uint8_t txval)
{
	uint16_t res = 0;

	while ((_fst_SPIGetFlags() & SPI_FLAG_BSY) || (_flash_SPIGetFlags() & SPI_FLAG_TXE) == 0);
	hFstSpi.Instance->DR = txval;
	while ((_fst_SPIGetFlags() & SPI_FLAG_RXNE) ==  0);
	res = hFstSpi.Instance->DR;
/*
	while ((_flash_SPIGetFlags() & SPI_FLAG_BSY) || !(_flash_SPIGetFlags() & SPI_FLAG_TXE));
	hFstSpi.Instance->DR = txval;
	while ((_flash_SPIGetFlags() & SPI_FLAG_RXNE) ==  0);
	res = hFstSpi.Instance->DR;
*/
	return (uint8_t)res;
}
//==============================================================================




void		FLASH_SPIReadBuff(uint32_t dlen, uint8_t *dbuff)
{
	uint32_t	rlen = 0;
	uint8_t		*rbuff = dbuff;

	while ((_fst_SPIGetFlags() & SPI_FLAG_BSY) || !(_fst_SPIGetFlags() & SPI_FLAG_TXE));
	*rbuff = hFstSpi.Instance->DR & 0x00FF;
	while (rlen < dlen)
	{
		hFstSpi.Instance->DR = 0;
		while (!(_fst_SPIGetFlags() & SPI_FLAG_RXNE));
		*rbuff = hFstSpi.Instance->DR & 0x00FF;
		rbuff++;
		rlen++;
	}
	
	return;
}
//==============================================================================




void		FLASH_SPIWriteBuff(uint32_t dlen, uint8_t *dbuff)
{
	uint32_t	rlen = 0;
	uint8_t		*rbuff = dbuff;

	while ((_fst_SPIGetFlags() & SPI_FLAG_BSY) || !(_fst_SPIGetFlags() & SPI_FLAG_TXE));
	*rbuff = hFstSpi.Instance->DR & 0x00FF;
	while (rlen < dlen)
	{
		hFstSpi.Instance->DR = *rbuff;
		while (!(_fst_SPIGetFlags() & SPI_FLAG_TXE));
		rbuff++;
		rlen++;
	}
	
	return;
}
//==============================================================================




void		FLASH_SPIReadBuffDMA(uint32_t dlen, uint8_t *dbuff)
{
	while ((_fst_SPIGetFlags() & SPI_FLAG_BSY) || (_fst_SPIGetFlags() & SPI_FLAG_TXE) == 0 || hFstSpi.State != HAL_SPI_STATE_READY);
	HAL_SPI_Receive_DMA(&hFstSpi, dbuff, dlen);
	while (hFstSpi.State != HAL_SPI_STATE_READY);
	return;
}
//==============================================================================




void		FLASH_SPIWriteBuffDMA(uint32_t dlen, uint8_t *dbuff)
{
	while ((_fst_SPIGetFlags() & SPI_FLAG_BSY) || (_fst_SPIGetFlags() & SPI_FLAG_TXE) == 0 || hFstSpi.State != HAL_SPI_STATE_READY);
	HAL_SPI_Transmit_DMA(&hFstSpi, dbuff, dlen);
//	while (hFstSpi.State != HAL_SPI_STATE_READY);
	return;
}
//==============================================================================



/*
inline uint8_t		FLASH_IsDMAReady()
{
	return (hFstSpi.State == HAL_SPI_STATE_READY);
}
//==============================================================================
*/



