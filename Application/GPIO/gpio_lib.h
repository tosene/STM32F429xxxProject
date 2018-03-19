#ifndef __GPIO_LIB_H
#define __GPIO_LIB_H

#ifdef __cplusplus
extern "C" {
#endif 

	///------------使用包含的头文件
	#include "gpio_cfg.h"
	///////////////////////////////////////////////////////////////////////////////
	void GPIOLib_EnableClock(GPIO_TypeDef *GPIOx);
	void GPIOLib_DisableClock(GPIO_TypeDef *GPIOx);
	void GPIOLib_ClockInit(void);
	void GPIOLib_Init(void);
	///////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

#endif /* __GPIO_LIB_H */