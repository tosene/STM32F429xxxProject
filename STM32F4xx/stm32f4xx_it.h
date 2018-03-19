
#ifndef __STM32F4xx_IT_H
#define __STM32F4xx_IT_H

#ifdef __cplusplus
 extern "C" {
#endif 
	
	//===使用包含的头文件
	 #include "systick_task.h"
	 #include "usart_task.h"
	///////////////////////////////////////////////////////////////////////////////
	void NMI_Handler(void);
	void HardFault_Handler(void);
	void MemManage_Handler(void);
	void BusFault_Handler(void);
	void UsageFault_Handler(void);
	void SVC_Handler(void);
	void DebugMon_Handler(void);
	void PendSV_Handler(void);
	void SysTick_Handler(void);
	void OTG_FS_IRQHandler(void);
	///////////////////////////////////////////////////////////////////////////////
#ifdef __cplusplus
}
#endif

#endif /* __STM32F4xx_IT_H */
