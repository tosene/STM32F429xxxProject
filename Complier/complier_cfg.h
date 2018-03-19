#ifndef __COMPLIER_CFG_H
#define __COMPLIER_CFG_H

#ifdef __cplusplus
extern "C" {
#endif 

///------------使用包含的头文件
///////////////////////////////////////////////////////////////////////////////

#ifndef USED_8BIT_MCU

	//===用于配置中断优先级的---抢占式优先级>响应优先级>中断表中的排位顺序
	#ifndef NVIC_PRIORITYGROUP_0
		//!< 0 bit  for pre-emption priority,4 bits for subpriority
		//所有4位用于指定响应优先级
		#define NVIC_PRIORITYGROUP_0         ((uint32_t)0x00000007)
		//!< 1 bit  for pre-emption priority,3 bits for subpriority
		//最高1位用于指定抢占式优先级，最低3位用于指定响应优先级
		#define NVIC_PRIORITYGROUP_1         ((uint32_t)0x00000006)
		//!< 2 bits for pre-emption priority,2 bits for subpriority
		//最高2位用于指定抢占式优先级，最低2位用于指定响应优先级
		#define NVIC_PRIORITYGROUP_2         ((uint32_t)0x00000005)
		//!< 3 bits for pre-emption priority,1 bit  for subpriority
		//最高3位用于指定抢占式优先级，最低1位用于指定响应优先级
		#define NVIC_PRIORITYGROUP_3         ((uint32_t)0x00000004)
		//!< 4 bits for pre-emption priority,0 bit  for subpriority
		//所有4位用于指定抢占式优先级
		#define NVIC_PRIORITYGROUP_4         ((uint32_t)0x00000003)
	#endif
    
	//===检查是否使用硬件的DSP库
	#if defined(ARM_MATH_CM4)||defined(ARM_MATH_CM4)
		#include "arm_math.h"
	#endif 
	
	#include "stm32f4xx.h"
	#include "iwdg_task.h"
	//---获取系统时钟的定义
	#define SYS_CLOCK_MHZ						(SystemCoreClock/1000000U) 
	//---使能全局中断
	#define SEI()								__enable_irq() // __set_PRIMASK(0)
	//---禁止全局中断
	#define CLI()								__disable_irq() //__set_PRIMASK(1)
	//---喂狗
	#define WDT_RESET()							IWDGLib_Reset();
	//---软件复位
	#define SOFT_RESET()						( CLI(),NVIC_SystemReset() )

#endif // USED_8BIT_MCU

///////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

#endif /* __COMPLIER_CFG_H */