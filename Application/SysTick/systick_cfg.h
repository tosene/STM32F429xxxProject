#ifndef __SYSTICK_CFG_H
#define __SYSTICK_CFG_H

#ifdef __cplusplus
extern "C" {
#endif 

///------------使用包含的头文件
#include "complier_lib.h"
	///////////////////////////////////////////////////////////////////////////////
	//---系统滴答定时器的中断等级
	#define SYSTICK_IRQ_PP_VAL						15			//---抢占优先级
	#define SYSTICK_IRQ_SP_VAL						0			//---分组优先级

	//---最小时基脉冲宽度
	#define	SYSTICK_BASE_TIME_US					100
	#if SYSTICK_BASE_TIME_US>100
		#define	 SYSTICK_BASE_TIME_US				100	
	#elif (SYSTICK_BASE_TIME_US<100)
		#define	 SYSTICK_BASE_TIME_US				100	
	#else
		#define	SYSTICK_BASE_TIME_US					100
	#endif
	//---滴答定时的定时脉冲基数初值
	#define SYSTICK_BASE_TIME_COUNT					( SystemCoreClock/SYS_CLOCK_MHZ/SYSTICK_BASE_TIME_US  )
	//---其他时基脉冲的计数
	#define	SYSTICK_BASE_TIME_MS					( 1000/SYSTICK_BASE_TIME_US )
	#define	SYSTICK_BASE_TIME_10MS					( SYSTICK_BASE_TIME_MS*10	)
	#define	SYSTICK_BASE_TIME_100MS					( SYSTICK_BASE_TIME_MS*100	)
	#define	SYSTICK_BASE_TIME_S						( SYSTICK_BASE_TIME_MS*1000	)
	//===定义定时计数器使用的结构体
	//---结构体
	typedef struct _SysTick_HandlerType			SysTick_HandlerType; 
	//---结构体指针
	typedef struct _SysTick_HandlerType			*pSysTick_HandlerType;
	//---结构体格式
	struct  _SysTick_HandlerType
	{
		VLTUINT8_T  tickModel;					//---工作模式 0---无模式
		VLTUINT32_T usXBaseNum;					//---延时计数的个数
		VLTUINT32_T usXBaseCount;				//---100微秒计数,中断脉冲的时间基数
		VLTUINT32_T msX1Count;					//---1毫秒计数
		VLTUINT32_T msX10Count;					//---10毫秒计数
		VLTUINT32_T msX100Count;				//---100毫秒计数
		VLTUINT32_T sX1Count;					//---1秒的计数
	};

	extern SysTick_HandlerType	g_SysTick;
	extern pSysTick_HandlerType pSysTick;

	//===函数定义
	void SysTickCfg_SuspendTick(void);
	void SysTickCfg_ResumeTick(void);
	void SysTickCfg_Init(void);
	void SysTickCfg_Config(UINT32_T clkFreq, UINT32_T ticks);
	void SysTickCfg_IncInit(void);
	void SysTickCfg_DecInit(void);
	UINT32_T SysTickCfg_GetUsX100Val(void);
	UINT32_T SysTickCfg_GetMsX1Val(void);
	UINT32_T SysTickCfg_GetMsX10Val(void);
	UINT32_T SysTickCfg_GetMsX100Val(void);
	UINT32_T SysTickCfg_GetSX1Val(void);
	void SysTickCfg_SetUsX100(UINT32_T us);
	UINT32_T SysTickCfg_GetUsX100(void);
	void SysTickCfg_IRQHandler(void);
	void SysTickCfg_GetSysTick( UINT32_T *ctrlVal , UINT32_T *loadVal );
	void SysTickCfg_WaitSysTick( UINT32_T us );
	void SysTickCfg_ReSetSysTick( UINT32_T ctrlVal , UINT32_T loadVal );
///////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

#endif /* __SYSTICK_CFG_H */