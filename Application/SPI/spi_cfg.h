#ifndef __SPI_CFG_H
#define __SPI_CFG_H
#ifdef __cplusplus
extern "C"
{
	#endif
	//////////////////////////////////////////////////////////////////////////////////////
	#include "complier_lib.h"


	//---定义结构体
	struct _SPI_HandlerType
	{
		GPIO_TypeDef *SPISSGPIOx;
		GPIO_TypeDef *SPISCKGPIOx;
		GPIO_TypeDef *SPIMOSIGPIOx;
		GPIO_TypeDef *SPIMISOGPIOx;
		UINT32_T	 SPISSPin;
		UINT32_T	 SPISCKPin;
		UINT32_T	 SPIMOSIPin;
		UINT32_T	 SPIMISOPin;
	};
	//===函数定义

	//////////////////////////////////////////////////////////////////////////////////////
	#ifdef __cplusplus
}
#endif
#endif /*__SPI_CFG_H */
