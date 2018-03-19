#ifndef __SYSTICK_LIB_H
#define __SYSTICK_LIB_H

#ifdef __cplusplus
extern "C" {
#endif 

///------------使用包含的头文件
#include "systick_cfg.h"
///////////////////////////////////////////////////////////////////////////////

//===启动定时时基脉冲
#define	SYS_TICK_X100US_START()					( g_SysTickCount=SysTickLib_GetUsX100Val()	)
#define	SYS_TICK_X1MS_START()					( g_SysTickCount=SysTickLib_GetMsX1Val()		)
#define	SYS_TICK_X10MS_START()					( g_SysTickCount=SysTickLib_GetMsX10Val()		)
#define	SYS_TICK_X100MS_START()					( g_SysTickCount=SysTickLib_GetMsX100Val()	)
#define	SYS_TICK_X1S_START()					( g_SysTickCount=SysTickLib_GetSX1Val()		)

//===停止定时时基脉冲
#define	SYS_TICK_STOP()							( g_SysTickCount=0							)

//===定时时基是否发生溢出
#define	SYS_TICK_X100US_OVERTIME(val)			( SysTickLib_UsX100Time(val)	)
#define	SYS_TICK_X1MS_OVERTIME(val)				( SysTickLib_MsX1Time(val)		)
#define	SYS_TICK_X10MS_OVERTIME(val)			( SysTickLib_MsX10Time(val)		)
#define	SYS_TICK_X100MS_OVERTIME(val)			( SysTickLib_MsX100Time(val)	)
#define	SYS_TICK_X1S_OVERTIME(val)				( SysTickLib_SX1Time(val)		)

	//===全局定义---用于时基获取
	extern VLTUINT32_T g_SysTickCount;

	//===函数定义
	UINT8_T SysTickLib_UsX100Time(UINT32_T usTimer);
	UINT8_T SysTickLib_MsX1Time(UINT32_T msTimer);
	UINT8_T SysTickLib_MsX10Time(UINT32_T msTimer);
	UINT8_T SysTickLib_MsX100Time(UINT32_T msTimer);
	UINT8_T SysTickLib_SX1Time(UINT32_T sTimer);
	void SysTickLib_Init(void);
	void SysTickLib_Config(UINT32_T clkFreq, UINT32_T ticks);
	void SysTickLib_DecInit(void);
	void SysTickLib_IncInit(void);
	UINT32_T SysTickLib_GetUsX100Val(void);
	UINT32_T SysTickLib_GetMsX1Val(void);
	UINT32_T SysTickLib_GetMsX10Val(void);
	UINT32_T SysTickLib_GetMsX100Val(void);
	UINT32_T SysTickLib_GetSX1Val(void);
	void SysTickLib_SetUsX100(UINT32_T us);
	void SysTickLib_IRQHandler(void);
	void SysTickLib_GetSysTick( UINT32_T *ctrlVal , UINT32_T *loadVal );
	void SysTickLib_WaitSysTick( VLTUINT32_T us );
	void SysTickLib_ReSetSysTick( UINT32_T ctrlVal , UINT32_T loadVal );
///////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

#endif /* __SYSTICK_LIB_H */