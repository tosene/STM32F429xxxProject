#include "gpio_cfg.h"

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
void GPIO_EnableClock(GPIO_TypeDef *GPIOx)
{
		//---ʹ�ܶ˿ڵ�ʱ��
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
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
void GPIO_DisableClock(GPIO_TypeDef *GPIOx)
{
	//---ʹ�ܶ˿ڵ�ʱ��
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
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
void GPIO_ClockInit( void )
{
	//---ʹ�ܶ˿ڵ�ʱ��
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
//////��	   ���� void GPIO_Init(void)
//////��	   �ܣ� �������еĶ˿�Ϊģ������
//////�������: ��
//////�������: ��
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
void GPIO_Init( void )
{
	//---ʹ�����ж˿ڵĶ�ʱ��
	GPIO_ClockInit();
	//---��ʼ���˿ڵ�״̬---ģ������
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