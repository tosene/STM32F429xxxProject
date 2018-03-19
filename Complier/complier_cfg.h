#ifndef __COMPLIER_CFG_H
#define __COMPLIER_CFG_H

#ifdef __cplusplus
extern "C" {
#endif 

///------------ʹ�ð�����ͷ�ļ�
///////////////////////////////////////////////////////////////////////////////

#ifndef USED_8BIT_MCU

	//===���������ж����ȼ���---��ռʽ���ȼ�>��Ӧ���ȼ�>�жϱ��е���λ˳��
	#ifndef NVIC_PRIORITYGROUP_0
		//!< 0 bit  for pre-emption priority,4 bits for subpriority
		//����4λ����ָ����Ӧ���ȼ�
		#define NVIC_PRIORITYGROUP_0         ((uint32_t)0x00000007)
		//!< 1 bit  for pre-emption priority,3 bits for subpriority
		//���1λ����ָ����ռʽ���ȼ������3λ����ָ����Ӧ���ȼ�
		#define NVIC_PRIORITYGROUP_1         ((uint32_t)0x00000006)
		//!< 2 bits for pre-emption priority,2 bits for subpriority
		//���2λ����ָ����ռʽ���ȼ������2λ����ָ����Ӧ���ȼ�
		#define NVIC_PRIORITYGROUP_2         ((uint32_t)0x00000005)
		//!< 3 bits for pre-emption priority,1 bit  for subpriority
		//���3λ����ָ����ռʽ���ȼ������1λ����ָ����Ӧ���ȼ�
		#define NVIC_PRIORITYGROUP_3         ((uint32_t)0x00000004)
		//!< 4 bits for pre-emption priority,0 bit  for subpriority
		//����4λ����ָ����ռʽ���ȼ�
		#define NVIC_PRIORITYGROUP_4         ((uint32_t)0x00000003)
	#endif
    
	//===����Ƿ�ʹ��Ӳ����DSP��
	#if defined(ARM_MATH_CM4)||defined(ARM_MATH_CM4)
		#include "arm_math.h"
	#endif 
	
	#include "stm32f4xx.h"
	#include "iwdg_task.h"
	//---��ȡϵͳʱ�ӵĶ���
	#define SYS_CLOCK_MHZ						(SystemCoreClock/1000000U) 
	//---ʹ��ȫ���ж�
	#define SEI()								__enable_irq() // __set_PRIMASK(0)
	//---��ֹȫ���ж�
	#define CLI()								__disable_irq() //__set_PRIMASK(1)
	//---ι��
	#define WDT_RESET()							IWDGLib_Reset();
	//---�����λ
	#define SOFT_RESET()						( CLI(),NVIC_SystemReset() )

#endif // USED_8BIT_MCU

///////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

#endif /* __COMPLIER_CFG_H */