#ifndef __GPIO_TASK_H
#define __GPIO_TASK_H

#ifdef __cplusplus
extern "C" {
#endif 

	///------------使用包含的头文件
	#include "gpio_lib.h"
	///////////////////////////////////////////////////////////////////////////////
	void GPIOTask_EnableClock(GPIO_TypeDef *GPIOx);
	void GPIOTask_DisableClock(GPIO_TypeDef *GPIOx);
	void GPIOTask_ClockInit(void);
	void GPIOTask_Init(void);
	///////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

#endif /* __GPIO_TASK_H */