#ifndef __SYSTICK_CFG_H
#define __SYSTICK_CFG_H

#ifdef __cplusplus
extern "C" {
#endif 

///------------ʹ�ð�����ͷ�ļ�
#include "complier_lib.h"
	///////////////////////////////////////////////////////////////////////////////
	//---ϵͳ�δ�ʱ�����жϵȼ�
	#define SYSTICK_IRQ_PP_VAL						15			//---��ռ���ȼ�
	#define SYSTICK_IRQ_SP_VAL						0			//---�������ȼ�

	//---��Сʱ��������
	#define	SYSTICK_BASE_TIME_US					100
	#if SYSTICK_BASE_TIME_US>100
		#define	 SYSTICK_BASE_TIME_US				100	
	#elif (SYSTICK_BASE_TIME_US<100)
		#define	 SYSTICK_BASE_TIME_US				100	
	#else
		#define	SYSTICK_BASE_TIME_US					100
	#endif
	//---�δ�ʱ�Ķ�ʱ���������ֵ
	#define SYSTICK_BASE_TIME_COUNT					( SystemCoreClock/SYS_CLOCK_MHZ/SYSTICK_BASE_TIME_US  )
	//---����ʱ������ļ���
	#define	SYSTICK_BASE_TIME_MS					( 1000/SYSTICK_BASE_TIME_US )
	#define	SYSTICK_BASE_TIME_10MS					( SYSTICK_BASE_TIME_MS*10	)
	#define	SYSTICK_BASE_TIME_100MS					( SYSTICK_BASE_TIME_MS*100	)
	#define	SYSTICK_BASE_TIME_S						( SYSTICK_BASE_TIME_MS*1000	)
	//===���嶨ʱ������ʹ�õĽṹ��
	//---�ṹ��
	typedef struct _SysTick_HandlerType			SysTick_HandlerType; 
	//---�ṹ��ָ��
	typedef struct _SysTick_HandlerType			*pSysTick_HandlerType;
	//---�ṹ���ʽ
	struct  _SysTick_HandlerType
	{
		VLTUINT8_T  tickModel;					//---����ģʽ 0---��ģʽ
		VLTUINT32_T usXBaseNum;					//---��ʱ�����ĸ���
		VLTUINT32_T usXBaseCount;				//---100΢�����,�ж������ʱ�����
		VLTUINT32_T msX1Count;					//---1�������
		VLTUINT32_T msX10Count;					//---10�������
		VLTUINT32_T msX100Count;				//---100�������
		VLTUINT32_T sX1Count;					//---1��ļ���
	};

	extern SysTick_HandlerType	g_SysTick;
	extern pSysTick_HandlerType pSysTick;

	//===��������
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