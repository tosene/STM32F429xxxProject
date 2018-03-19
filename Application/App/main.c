#include "main.h"

///////////////////////////////////////////////////////////////////////////////
//////函	   数：void SystemClock_Config( void )
//////功	   能：系统时钟的初始化
//////输入参数: 无
//////输出参数: 无
//////说	   明：函数名不可修改，其他模块会使用到该函数，比如USB
//////////////////////////////////////////////////////////////////////////////
void SystemClock_Config( void )
{
	//---设置FLASH的延时读取周期数
	LL_FLASH_SetLatency( LL_FLASH_LATENCY_5 );
	//---等待设置完成
	if ( LL_FLASH_GetLatency( ) != LL_FLASH_LATENCY_5 )
	{
		Error_Handler( );
	}
	//---设置内部调节器的输出电压
	LL_PWR_SetRegulVoltageScaling( LL_PWR_REGU_VOLTAGE_SCALE1 );
	//---禁用驱动模式
	LL_PWR_DisableOverDriveMode();
	//---使能外部晶振
	LL_RCC_HSE_Enable( );
	//---等待外部晶振稳定
	while ( LL_RCC_HSE_IsReady( ) != 1 )
	{
		
	}
	//---设置内部低频时钟
	LL_RCC_LSI_Enable();
	//---等待低频时钟准备就绪
	while( LL_RCC_LSI_IsReady() != 1 )
	{

	}
	// -- - 设置系统的PLL-- -
	LL_RCC_PLL_ConfigDomain_SYS( LL_RCC_PLLSOURCE_HSE , LL_RCC_PLLM_DIV_4 , 168 , LL_RCC_PLLP_DIV_2 );
	//---设置USB模块的时钟，同时随机数功能也使用这个时钟
	LL_RCC_PLL_ConfigDomain_48M( LL_RCC_PLLSOURCE_HSE , LL_RCC_PLLM_DIV_4 , 168 , LL_RCC_PLLQ_DIV_7 );
	//---使能PLL
	LL_RCC_PLL_Enable( );
	//--- 等待PLL锁定
	while ( LL_RCC_PLL_IsReady( ) != 1 )
	{
		
	}
	//---设置APHB的时钟---外设的总线时钟
	LL_RCC_SetAHBPrescaler( LL_RCC_SYSCLK_DIV_1 );
	//---设置APB1的时钟---外设的总线时钟
	LL_RCC_SetAPB1Prescaler( LL_RCC_APB1_DIV_4 );
	//---设置APB2的时钟---外设的总线时钟
	LL_RCC_SetAPB2Prescaler( LL_RCC_APB2_DIV_2 );
	//---设置系统时钟为PLL之后的时钟
	LL_RCC_SetSysClkSource( LL_RCC_SYS_CLKSOURCE_PLL );
	//--- 等待系统时钟稳定
	while ( LL_RCC_GetSysClkSource( ) != LL_RCC_SYS_CLKSOURCE_STATUS_PLL )
	{
		
	}
	//---注册系统滴答定时器---1ms的延时
	//LL_Init1msTick(168000000);
	//---设置系统滴答定时器的时钟为系统高速时钟---使能滴答定时器的时钟
	LL_SYSTICK_SetClkSource( LL_SYSTICK_CLKSOURCE_HCLK );
	//---设置系统代码的时钟
	LL_SetSystemCoreClock( 168000000 );
	//---
	LL_RCC_SetTIMPrescaler( LL_RCC_TIM_PRESCALER_TWICE );
	//---使能Flash的预读取功能
	LL_FLASH_EnablePrefetch( );
	//---使能数据缓存
	LL_FLASH_EnableDataCache( );
	//---使能指令高速缓存
	LL_FLASH_EnableInstCache( );
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： void SystemNVIC_Init(void)
//////功	   能： 系统中断配置
//////输入参数: 无
//////输出参数: 无
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
void SysNVIC_Init( void )
{
	//--- 系统抢占优先级配置
	NVIC_SetPriorityGrouping( NVIC_PRIORITYGROUP_4 );
	//--- 系统终端的初始化
	/* MemoryManagement_IRQn interrupt configuration */
	NVIC_SetPriority( MemoryManagement_IRQn , NVIC_EncodePriority( NVIC_GetPriorityGrouping( ) , 0 , 0 ) );
	/* BusFault_IRQn interrupt configuration */
	NVIC_SetPriority( BusFault_IRQn , NVIC_EncodePriority( NVIC_GetPriorityGrouping( ) , 0 , 0 ) );
	/* UsageFault_IRQn interrupt configuration */
	NVIC_SetPriority( UsageFault_IRQn , NVIC_EncodePriority( NVIC_GetPriorityGrouping( ) , 0 , 0 ) );
	/* SVCall_IRQn interrupt configuration */
	NVIC_SetPriority( SVCall_IRQn , NVIC_EncodePriority( NVIC_GetPriorityGrouping( ) , 0 , 0 ) );
	/* DebugMonitor_IRQn interrupt configuration */
	NVIC_SetPriority( DebugMonitor_IRQn , NVIC_EncodePriority( NVIC_GetPriorityGrouping( ) , 0 , 0 ) );
	/* PendSV_IRQn interrupt configuration */
	NVIC_SetPriority( PendSV_IRQn , NVIC_EncodePriority( NVIC_GetPriorityGrouping( ) , 0 , 0 ) );

}
///////////////////////////////////////////////////////////////////////////////
//////函	   数：void Sys_Init( void )
//////功	   能：系统初始化
//////输入参数: 无
//////输出参数: 无
//////说	   明：
//////////////////////////////////////////////////////////////////////////////
void Sys_Init( void )
{
	//---时钟的初始化
	SystemClock_Config( );
	//---中断（NVIC）的初始化
	SysNVIC_Init( );
	//---端口的初始化
	GPIOTask_Init( );
	//---滴答定时器的配置
	SysTickTask_Init( );
	//---串口的初始化
	USARTTask_HandlerType_Init( USART1_HandlerType,64);
	//---随机数序列发生器
	RandomTask_Init();
    //---AD5593的初始化
	AD5593Task_IIC_Init();
	//---WM8510的初始化
   // WM8510Task_Init();
	//---LED显示端口的设置
	LEDTask_Init();
	//---使能去全局中断
	//SEI();
	AD5593Task_IIC_CheckDevice();
	//WM8510Task_SetFreqMHz( 12 );
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
int main(void)
{
	Sys_Init( );
	//UINT32_T temp = 0;
	//UINT32_T  i=0;
	while ( 1 )
	{
		////WM8510_IIC_SetFreqMHz( 13 );
		//Delay_ms( 10 );
		////USARTTask_HandlerType_FuncType(pUSART1, NULL);
		//temp = RandomTask_GetData();
		//USART_HandlerType_Printf(pUSART1,"Rang=%llu\r\n", temp);
		//Delay_ms(10);
		//i++;
		//USART_HandlerType_Printf(pUSART1,"打印输出次数:%llu\r\n", i);
		//Delay_ms(10);
        
		//WM8510Lib_IIC_Debug();
	}
}