#ifndef __GPIO_CFG_H
#define __GPIO_CFG_H

#ifdef __cplusplus
extern "C" {
#endif 

	///------------使用包含的头文件
	#include "complier_lib.h"
	///////////////////////////////////////////////////////////////////////////////
	void GPIO_EnableClock(GPIO_TypeDef *GPIOx);
	void GPIO_DisableClock(GPIO_TypeDef *GPIOx);
	void GPIO_ClockInit( void );
	void GPIO_Init( void );
	///////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

#endif /* __GPIO_CFG_H */