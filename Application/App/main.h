#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif 
	///------------使用包含的头文件
	#include "complier_lib.h"
	#include "delay_lib.h"
	#include "gpio_task.h"
	#include "systick_task.h"
	#include "usart_task.h"
	#include "random_task.h"
	#include "wm8510_lib.h"
	///////////////////////////////////////////////////////////////////////////////
	void SystemClock_Config( void );
	void SysNVIC_Init( void );
	void Sys_Init( void );
	///////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */