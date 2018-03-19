#include "gpio_cfg.h"

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
void GPIO_EnableClock(GPIO_TypeDef *GPIOx)
{
		//---使能端口的时钟
	#ifdef GPIOA
		if ( GPIOx == GPIOA )
		{
			LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
		}
	#endif // GPIOA
	
	#ifdef GPIOB
		if ( GPIOx == GPIOB )
		{
			LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOB);
		}
	#endif // GPIOB
	
	#ifdef GPIOC
		if ( GPIOx == GPIOC )
		{
			LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOC);
		}
	#endif // GPIOC
	
	#ifdef GPIOD
		if ( GPIOx == GPIOD )
		{
			LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOD);
		}
	#endif // GPIOD
	
	#ifdef GPIOE
		if ( GPIOx == GPIOE )
		{
			LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOE);
		}
	#endif // GPIOE
	
	#ifdef GPIOF
		if ( GPIOx == GPIOF )
		{
			LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOF);
		}
	#endif // GPIOF
	
	#ifdef GPIOG
		if ( GPIOx == GPIOG )
		{
			LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOG);
		}
	#endif // GPIOG
	
	#ifdef GPIOH
		if ( GPIOx == GPIOH )
		{
			LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOH);
		}
	#endif // GPIOH
	
	#ifdef GPIOI
		if ( GPIOx == GPIOI )
		{
			LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOI);
		}
	#endif // GPIOI
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
void GPIO_DisableClock(GPIO_TypeDef *GPIOx)
{
	//---使能端口的时钟
	#ifdef GPIOA
	if ( GPIOx == GPIOA )
	{
		LL_AHB1_GRP1_DisableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
	}
	#endif // GPIOA
	
	#ifdef GPIOB
		if ( GPIOx == GPIOB )
		{
			LL_AHB1_GRP1_DisableClock(LL_AHB1_GRP1_PERIPH_GPIOB);
		}
	#endif // GPIOB
	
	#ifdef GPIOC
		if ( GPIOx == GPIOC )
		{
			LL_AHB1_GRP1_DisableClock(LL_AHB1_GRP1_PERIPH_GPIOC);
		}
	#endif // GPIOC
	
	#ifdef GPIOD
		if ( GPIOx == GPIOD )
		{
			LL_AHB1_GRP1_DisableClock(LL_AHB1_GRP1_PERIPH_GPIOD);
		}
	#endif // GPIOD
	
	#ifdef GPIOE
		if ( GPIOx == GPIOE )
		{
			LL_AHB1_GRP1_DisableClock(LL_AHB1_GRP1_PERIPH_GPIOE);
		}
	#endif // GPIOE
	
	#ifdef GPIOF
		if ( GPIOx == GPIOF )
		{
			LL_AHB1_GRP1_DisableClock(LL_AHB1_GRP1_PERIPH_GPIOF);
		}
	#endif // GPIOF
	
	#ifdef GPIOG
		if ( GPIOx == GPIOG )
		{
			LL_AHB1_GRP1_DisableClock(LL_AHB1_GRP1_PERIPH_GPIOG);
		}
	#endif // GPIOG
	
	#ifdef GPIOH
		if ( GPIOx == GPIOH )
		{
			LL_AHB1_GRP1_DisableClock(LL_AHB1_GRP1_PERIPH_GPIOH);
		}
	#endif // GPIOH
	
	#ifdef GPIOI
		if ( GPIOx == GPIOI )
		{
			LL_AHB1_GRP1_DisableClock(LL_AHB1_GRP1_PERIPH_GPIOI);
		}
	#endif // GPIOI
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
void GPIO_ClockInit( void )
{
	//---使能端口的时钟
	#ifdef GPIOA
		LL_AHB1_GRP1_EnableClock( LL_AHB1_GRP1_PERIPH_GPIOA );
	#endif // GPIOA

	#ifdef GPIOB
		LL_AHB1_GRP1_EnableClock( LL_AHB1_GRP1_PERIPH_GPIOB );
	#endif // GPIOB

	#ifdef GPIOC
		LL_AHB1_GRP1_EnableClock( LL_AHB1_GRP1_PERIPH_GPIOC );
	#endif // GPIOC

	#ifdef GPIOD
		LL_AHB1_GRP1_EnableClock( LL_AHB1_GRP1_PERIPH_GPIOD );
	#endif // GPIOD

	#ifdef GPIOE
		LL_AHB1_GRP1_EnableClock( LL_AHB1_GRP1_PERIPH_GPIOE );
	#endif // GPIOE

	#ifdef GPIOF
		LL_AHB1_GRP1_EnableClock( LL_AHB1_GRP1_PERIPH_GPIOF );
	#endif // GPIOF

	#ifdef GPIOG
		LL_AHB1_GRP1_EnableClock( LL_AHB1_GRP1_PERIPH_GPIOG );
	#endif // GPIOG

	#ifdef GPIOH
		LL_AHB1_GRP1_EnableClock( LL_AHB1_GRP1_PERIPH_GPIOH );
	#endif // GPIOH

	#ifdef GPIOI
		LL_AHB1_GRP1_EnableClock( LL_AHB1_GRP1_PERIPH_GPIOI );
	#endif // GPIOI
}
///////////////////////////////////////////////////////////////////////////////
//////函	   数： void GPIO_Init(void)
//////功	   能： 设置所有的端口为模拟输入
//////输入参数: 无
//////输出参数: 无
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
void GPIO_Init( void )
{
	//---使能所有端口的额时钟
	GPIO_ClockInit();
	//---初始化端口的状态---模拟输入
	LL_GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.Pin = LL_GPIO_PIN_2 | LL_GPIO_PIN_3 | LL_GPIO_PIN_4 | LL_GPIO_PIN_5
		| LL_GPIO_PIN_6 | LL_GPIO_PIN_7 | LL_GPIO_PIN_8 | LL_GPIO_PIN_9
		| LL_GPIO_PIN_10 | LL_GPIO_PIN_11 | LL_GPIO_PIN_12 | LL_GPIO_PIN_13
		| LL_GPIO_PIN_14 | LL_GPIO_PIN_15 | LL_GPIO_PIN_0 | LL_GPIO_PIN_1;
	GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
	GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
	LL_GPIO_Init( GPIOE, &GPIO_InitStruct );

	GPIO_InitStruct.Pin = LL_GPIO_PIN_13 | LL_GPIO_PIN_14 | LL_GPIO_PIN_15 | LL_GPIO_PIN_0
		| LL_GPIO_PIN_1 | LL_GPIO_PIN_2 | LL_GPIO_PIN_3 | LL_GPIO_PIN_4
		| LL_GPIO_PIN_5 | LL_GPIO_PIN_6 | LL_GPIO_PIN_7 | LL_GPIO_PIN_8
		| LL_GPIO_PIN_9 | LL_GPIO_PIN_10 | LL_GPIO_PIN_11 | LL_GPIO_PIN_12;
	GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
	GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
	LL_GPIO_Init( GPIOC, &GPIO_InitStruct );

	GPIO_InitStruct.Pin = LL_GPIO_PIN_0 | LL_GPIO_PIN_1 | LL_GPIO_PIN_2 | LL_GPIO_PIN_3
		| LL_GPIO_PIN_4 | LL_GPIO_PIN_5 | LL_GPIO_PIN_6 | LL_GPIO_PIN_7
		| LL_GPIO_PIN_8 | LL_GPIO_PIN_11 | LL_GPIO_PIN_12;
	GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
	GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
	LL_GPIO_Init( GPIOA, &GPIO_InitStruct );

	GPIO_InitStruct.Pin = LL_GPIO_PIN_0 | LL_GPIO_PIN_1 | LL_GPIO_PIN_2 | LL_GPIO_PIN_10
		| LL_GPIO_PIN_11 | LL_GPIO_PIN_12 | LL_GPIO_PIN_13 | LL_GPIO_PIN_14
		| LL_GPIO_PIN_15 | LL_GPIO_PIN_5 | LL_GPIO_PIN_6 | LL_GPIO_PIN_7
		| LL_GPIO_PIN_8 | LL_GPIO_PIN_9;
	GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
	GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
	LL_GPIO_Init( GPIOB, &GPIO_InitStruct );

	GPIO_InitStruct.Pin = LL_GPIO_PIN_8 | LL_GPIO_PIN_9 | LL_GPIO_PIN_10 | LL_GPIO_PIN_11
		| LL_GPIO_PIN_12 | LL_GPIO_PIN_13 | LL_GPIO_PIN_14 | LL_GPIO_PIN_15
		| LL_GPIO_PIN_0 | LL_GPIO_PIN_1 | LL_GPIO_PIN_2 | LL_GPIO_PIN_3
		| LL_GPIO_PIN_4 | LL_GPIO_PIN_5 | LL_GPIO_PIN_6 | LL_GPIO_PIN_7;
	GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
	GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
	LL_GPIO_Init( GPIOD, &GPIO_InitStruct );
}