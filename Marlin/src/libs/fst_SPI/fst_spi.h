#ifndef __fst_spi_H
#define __fst_spi_H


#include "../../../src/MarlinCore.h"


#define USE_HAL_SPI_REGISTER_CALLBACKS	1U

#define FST_SPI					          SPI2
#define FST_SPI_MISO_Pin			    GPIO_PIN_14
#define FST_SPI_MISO_GPIO			    GPIOB
#define FST_SPI_MOSI_Pin			    GPIO_PIN_15
#define FST_SPI_MOSI_GPIO			    GPIOB
#define FST_SPI_SCK_Pin			      GPIO_PIN_10
#define FST_SPI_SCK_GPIO			    GPIOB
#define FST_SPI_GPIO_ALTERNATE	  GPIO_AF5_SPI2

#define FST_SPI_CS_FLASH_Pin		  GPIO_PIN_12
#define FST_SPI_CS_FLASH_GPIO		  GPIOB

#define FST_SPI_CS_TOUCH_Pin      GPIO_PIN_7
#define FST_SPI_CS_TOUCH_GPIO     GPIOA

#define FST_SPI_DMA_STREAM1		    DMA1_Stream3
#define FST_SPI_DMA_CHANNEL1		  DMA_CHANNEL_0
#define FST_SPI_DMA_STREAM1_IRQ	  DMA1_Stream3_IRQn
#define FST_SPI_DMA_STREAM2		    DMA1_Stream4
#define FST_SPI_DMA_CHANNEL2		  DMA_CHANNEL_0
#define FST_SPI_DMA_STREAM2_IRQ	  DMA1_Stream4_IRQn

#define FST_SPI_CLK_ENABLE()			  __HAL_RCC_SPI2_CLK_ENABLE()
#define FST_SPI_CLK_DISABLE()			  __HAL_RCC_SPI2_CLK_DISABLE()
#define FST_SPI_DMA_CLK_ENABLE()		__HAL_RCC_DMA1_CLK_ENABLE()
#define FST_SPI_DMA_CLK_DISABLE()		__HAL_RCC_DMA1_CLK_DISABLE()

#define FST_SPI_LOW_CLOCKSPEED		  SPI_BAUDRATEPRESCALER_32
#define FST_SPI_HIGH_CLOCKSPEED		  SPI_BAUDRATEPRESCALER_2


#define		_touch_CS_Enable()	FST_SPI_CS_TOUCH_GPIO->BSRR = (uint32_t)FST_SPI_CS_TOUCH_Pin << 16U
#define 	_touch_CS_Disable()	FST_SPI_CS_TOUCH_GPIO->BSRR = FST_SPI_CS_TOUCH_Pin
#define		TOUCH_READS			    (uint8_t)16
#define		TOUCH_BUFF_SIZE		  (uint8_t)6*TOUCH_READS

#define		_flash_CS_Enable()	FST_SPI_CS_FLASH_GPIO->BSRR = (uint32_t)FST_SPI_CS_FLASH_Pin << 16U
#define 	_flash_CS_Disable()	FST_SPI_CS_FLASH_GPIO->BSRR = FST_SPI_CS_FLASH_Pin


extern SPI_HandleTypeDef		hFstSpi;

void      HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi);


uint16_t	_fst_SPIGetFlags();

void		  FST_SPIInit(void);
HAL_SPI_StateTypeDef	FST_SPIGetState();
void		  FST_SPISetSpeed(uint16_t prescaler);
uint16_t	FST_SPIGetSpeed();

void		  TOUCH_SPIEnable();
void		  TOUCH_SPIDisable();
void		  TOUCH_SPIStartRead();



void		  FLASH_SPIEnable();
void		  FLASH_SPIDisable();

uint8_t		FLASH_SPIWriteReadByte(uint8_t txval);
void		  FLASH_SPIReadBuff(uint32_t dlen, uint8_t *dbuff);
void		  FLASH_SPIWriteBuff(uint32_t dlen, uint8_t *dbuff);
void		  FLASH_SPIReadBuffDMA(uint32_t dlen, uint8_t *dbuff);
void		  FLASH_SPIWriteBuffDMA(uint32_t dlen, uint8_t *dbuff);
inline uint8_t		FLASH_IsDMAReady() { return (hFstSpi.State == HAL_SPI_STATE_READY); }




#endif /*__fst_spi_H */

