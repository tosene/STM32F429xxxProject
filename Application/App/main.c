#include "main.h"

///////////////////////////////////////////////////////////////////////////////
//////��	   ����void SystemClock_Config( void )
//////��	   �ܣ�ϵͳʱ�ӵĳ�ʼ��
//////�������: ��
//////�������: ��
//////˵	   ���������������޸ģ�����ģ���ʹ�õ��ú���������USB
//////////////////////////////////////////////////////////////////////////////
void SystemClock_Config( void )
{
	//---����FLASH����ʱ��ȡ������
	LL_FLASH_SetLatency( LL_FLASH_LATENCY_5 );
	//---�ȴ��������
	if ( LL_FLASH_GetLatency( ) != LL_FLASH_LATENCY_5 )
	{
		Error_Handler( );
	}
	//---�����ڲ��������������ѹ
	LL_PWR_SetRegulVoltageScaling( LL_PWR_REGU_VOLTAGE_SCALE1 );
	//---��������ģʽ
	LL_PWR_DisableOverDriveMode();
	//---ʹ���ⲿ����
	LL_RCC_HSE_Enable( );
	//---�ȴ��ⲿ�����ȶ�
	while ( LL_RCC_HSE_IsReady( ) != 1 )
	{
		
	}
	//---�����ڲ���Ƶʱ��
	LL_RCC_LSI_Enable();
	//---�ȴ���Ƶʱ��׼������
	while( LL_RCC_LSI_IsReady() != 1 )
	{

	}
	// -- - ����ϵͳ��PLL-- -
	LL_RCC_PLL_ConfigDomain_SYS( LL_RCC_PLLSOURCE_HSE , LL_RCC_PLLM_DIV_4 , 168 , LL_RCC_PLLP_DIV_2 );
	//---����USBģ���ʱ�ӣ�ͬʱ���������Ҳʹ�����ʱ��
	LL_RCC_PLL_ConfigDomain_48M( LL_RCC_PLLSOURCE_HSE , LL_RCC_PLLM_DIV_4 , 168 , LL_RCC_PLLQ_DIV_7 );
	//---ʹ��PLL
	LL_RCC_PLL_Enable( );
	//--- �ȴ�PLL����
	while ( LL_RCC_PLL_IsReady( ) != 1 )
	{
		
	}
	//---����APHB��ʱ��---���������ʱ��
	LL_RCC_SetAHBPrescaler( LL_RCC_SYSCLK_DIV_1 );
	//---����APB1��ʱ��---���������ʱ��
	LL_RCC_SetAPB1Prescaler( LL_RCC_APB1_DIV_4 );
	//---����APB2��ʱ��---���������ʱ��
	LL_RCC_SetAPB2Prescaler( LL_RCC_APB2_DIV_2 );
	//---����ϵͳʱ��ΪPLL֮���ʱ��
	LL_RCC_SetSysClkSource( LL_RCC_SYS_CLKSOURCE_PLL );
	//--- �ȴ�ϵͳʱ���ȶ�
	while ( LL_RCC_GetSysClkSource( ) != LL_RCC_SYS_CLKSOURCE_STATUS_PLL )
	{
		
	}
	//---ע��ϵͳ�δ�ʱ��---1ms����ʱ
	//LL_Init1msTick(168000000);
	//---����ϵͳ�δ�ʱ����ʱ��Ϊϵͳ����ʱ��---ʹ�ܵδ�ʱ����ʱ��
	LL_SYSTICK_SetClkSource( LL_SYSTICK_CLKSOURCE_HCLK );
	//---����ϵͳ�����ʱ��
	LL_SetSystemCoreClock( 168000000 );
	//---
	LL_RCC_SetTIMPrescaler( LL_RCC_TIM_PRESCALER_TWICE );
	//---ʹ��Flash��Ԥ��ȡ����
	LL_FLASH_EnablePrefetch( );
	//---ʹ�����ݻ���
	LL_FLASH_EnableDataCache( );
	//---ʹ��ָ����ٻ���
	LL_FLASH_EnableInstCache( );
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� void SystemNVIC_Init(void)
//////��	   �ܣ� ϵͳ�ж�����
//////�������: ��
//////�������: ��
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
void SysNVIC_Init( void )
{
	//--- ϵͳ��ռ���ȼ�����
	NVIC_SetPriorityGrouping( NVIC_PRIORITYGROUP_4 );
	//--- ϵͳ�ն˵ĳ�ʼ��
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
//////��	   ����void Sys_Init( void )
//////��	   �ܣ�ϵͳ��ʼ��
//////�������: ��
//////�������: ��
//////˵	   ����
//////////////////////////////////////////////////////////////////////////////
void Sys_Init( void )
{
	//---ʱ�ӵĳ�ʼ��
	SystemClock_Config( );
	//---�жϣ�NVIC���ĳ�ʼ��
	SysNVIC_Init( );
	//---�˿ڵĳ�ʼ��
	GPIOTask_Init( );
	//---�δ�ʱ��������
	SysTickTask_Init( );
	//---���ڵĳ�ʼ��
	USARTTask_HandlerType_Init( USART1_HandlerType,64);
	//---��������з�����
	RandomTask_Init();
    //---AD5593�ĳ�ʼ��
	AD5593Task_IIC_Init();
	//---WM8510�ĳ�ʼ��
   // WM8510Task_Init();
	//---LED��ʾ�˿ڵ�����
	LEDTask_Init();
	//---ʹ��ȥȫ���ж�
	//SEI();
	AD5593Task_IIC_CheckDevice();
	//WM8510Task_SetFreqMHz( 12 );
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
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
		//USART_HandlerType_Printf(pUSART1,"��ӡ�������:%llu\r\n", i);
		//Delay_ms(10);
        
		//WM8510Lib_IIC_Debug();
	}
}