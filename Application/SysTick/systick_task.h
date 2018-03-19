#ifndef __SYSTICK_TASK_H
#define __SYSTICK_TASK_H
#ifdef __cplusplus
extern "C" {
#endif 

///------------使用包含的头文件
#include "systick_lib.h"
///////////////////////////////////////////////////////////////////////////////
	//===函数定义
	void SysTickTask_Init( void );
	void SysTickTask_Config(UINT32_T clkFreq, UINT32_T ticks);
	void SysTickTask_IRQHandler( void );
///////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif
#endif /*__SYSTICK_TASK_H */

