#include "usart_cfg.h"

//---全局变量定义
USART_HandlerType  g_USART1 =
{
	.USARTxRxHeader=0,
	.USARTxTxHeader=0,
	.USARTxTimeOut=0,
	.USARTxTxPin=0,
	.USARTxGPIOx=NULL,
	.USARTxCOM=NULL,
	.USARTxTxHandlerType=
	{
		.txIndex=0,
		.txNum=0,
		.txCount=0,
		.txCrcVal=0,
		.txCrcFlag=0,
		.txStep=0,
		.txBufferDataSize=0,
		.pTxBuffer=NULL
	},
	.USARTxRxHandlerType=
	{
		.rxIndex=0,
		.rxCount=0,
		.rxCrcVal=0,
		.rxCrcFlag=0,
		.rxStep=0,
		.rxBufferDataSize=0,
		.pRxBuffer=NULL,
	},
	.USART_MSG_Task=NULL,
	
};
//---指针结构体
pUSART_HandlerType pUSART1=&g_USART1;

///////////////////////////////////////////////////////////////////////////////
//////函	   数：
//////功	   能：
//////输入参数: 
//////输出参数: 
//////说	   明：
//////////////////////////////////////////////////////////////////////////////
void USART_EnableClock(USART_TypeDef *USARTx)
{
	if ( USARTx == USART1 )
	{
		//---使能USART1的时钟信号
		LL_APB2_GRP1_EnableClock( LL_APB2_GRP1_PERIPH_USART1 );
	}
	else if ( USARTx == USART2 )
	{
		//---使能USART2的时钟信号
		LL_APB1_GRP1_EnableClock( LL_APB1_GRP1_PERIPH_USART2 );
	}
	#if defined(USART3)
		else if ( USARTx == USART3 )
		{
			//---使能USART3的时钟信号
			LL_APB1_GRP1_EnableClock( LL_APB1_GRP1_PERIPH_USART3 );
		}
	#endif /* USART3 */
	#if defined(USART6)
		else if ( USARTx == USART6 )
		{
			//---使能USART6的时钟信号
			LL_APB2_GRP1_EnableClock( LL_APB2_GRP1_PERIPH_USART6 );
		}
	#endif /* USART6 */
	#if defined(UART4)
		else if ( USARTx == UART4 )
		{
			//---使能UART4的时钟信号
			LL_APB1_GRP1_EnableClock( LL_APB1_GRP1_PERIPH_UART4 );
		}
	#endif /* UART4 */
	#if defined(UART5)
		else if ( USARTx == UART5 )
		{
			//---使能UART5的时钟信号
			LL_APB1_GRP1_EnableClock( LL_APB1_GRP1_PERIPH_UART5 );
		}
	#endif /* UART5 */
	#if defined(UART7)
		else if ( USARTx == UART7 )
		{
			//---使能UART7的时钟信号
			LL_APB1_GRP1_EnableClock( LL_APB1_GRP1_PERIPH_UART8 );
		}
	#endif /* UART7 */
	#if defined(UART8)
		else if ( USARTx == UART8 )
		{
			//---使能UART8的时钟信号
			LL_APB1_GRP1_EnableClock( LL_APB1_GRP1_PERIPH_UART8 );
		}
	#endif /* UART8 */
	#if defined(UART9)
		else if ( USARTx == UART9 )
		{
			//---使能USART9的时钟信号
			LL_APB2_GRP1_EnableClock( LL_APB2_GRP1_PERIPH_UART9 );
		}
	#endif /* UART9 */
	#if defined(UART10)
		else if ( USARTx == UART10 )
		{
			//---使能USART10的时钟信号
			LL_APB2_GRP1_EnableClock( LL_APB2_GRP1_PERIPH_UART10 );
		}
	#endif /* UART10 */
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数：
//////功	   能：
//////输入参数: 
//////输出参数: 
//////说	   明：
//////////////////////////////////////////////////////////////////////////////
void USART_DisableClock(USART_TypeDef *USARTx)
{
	if (USARTx == USART1)
	{
		//---使能USART1的时钟信号
		LL_APB2_GRP1_DisableClock(LL_APB2_GRP1_PERIPH_USART1);
	}
	else if (USARTx == USART2)
	{
		//---使能USART2的时钟信号
		LL_APB1_GRP1_DisableClock(LL_APB1_GRP1_PERIPH_USART2);
	}
#if defined(USART3)
	else if (USARTx == USART3)
	{
		//---使能USART3的时钟信号
		LL_APB1_GRP1_DisableClock(LL_APB1_GRP1_PERIPH_USART3);
	}
#endif /* USART3 */
#if defined(USART6)
	else if (USARTx == USART6)
	{
		//---使能USART6的时钟信号
		LL_APB2_GRP1_DisableClock(LL_APB2_GRP1_PERIPH_USART6);
	}
#endif /* USART6 */
#if defined(UART4)
	else if (USARTx == UART4)
	{
		//---使能UART4的时钟信号
		LL_APB1_GRP1_DisableClock(LL_APB1_GRP1_PERIPH_UART4);
	}
#endif /* UART4 */
#if defined(UART5)
	else if (USARTx == UART5)
	{
		//---使能UART5的时钟信号
		LL_APB1_GRP1_DisableClock(LL_APB1_GRP1_PERIPH_UART5);
	}
#endif /* UART5 */
#if defined(UART7)
	else if (USARTx == UART7)
	{
		//---使能UART7的时钟信号
		LL_APB1_GRP1_DisableClock(LL_APB1_GRP1_PERIPH_UART8);
	}
#endif /* UART7 */
#if defined(UART8)
	else if (USARTx == UART8)
	{
		//---使能UART8的时钟信号
		LL_APB1_GRP1_DisableClock(LL_APB1_GRP1_PERIPH_UART8);
	}
#endif /* UART8 */
#if defined(UART9)
	else if (USARTx == UART9)
	{
		//---使能USART9的时钟信号
		LL_APB2_GRP1_DisableClock(LL_APB2_GRP1_PERIPH_UART9);
	}
#endif /* UART9 */
#if defined(UART10)
	else if (USARTx == UART10)
	{
		//---使能USART10的时钟信号
		LL_APB2_GRP1_DisableClock(LL_APB2_GRP1_PERIPH_UART10);
	}
#endif /* UART10 */
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART_HandlerType_IT_TC(USART_HandlerType *USARTxHandlerType, UINT8_T msg)
{
	if (msg==ENABLE)
	{
		LL_USART_EnableIT_TC(USARTxHandlerType->USARTxCOM);
	}
	else
	{
		LL_USART_DisableIT_TC(USARTxHandlerType->USARTxCOM);
	}
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART_HandlerType_IT_TXE(USART_HandlerType *USARTxHandlerType, UINT8_T msg)
{
	if ( msg == ENABLE )
	{
		LL_USART_EnableIT_TXE(USARTxHandlerType->USARTxCOM);
	}
	else
	{
		LL_USART_DisableIT_TXE(USARTxHandlerType->USARTxCOM);
	}
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART_HandlerType_IT_RXNE(USART_HandlerType *USARTxHandlerType, UINT8_T msg)
{
	if ( msg == ENABLE )
	{
		LL_USART_EnableIT_RXNE(USARTxHandlerType->USARTxCOM);
	}
	else
	{
		LL_USART_DisableIT_RXNE(USARTxHandlerType->USARTxCOM);
	}
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART_HandlerType_IT_IDLE(USART_HandlerType *USARTxHandlerType, UINT8_T msg)
{
	if ( msg == ENABLE )
	{
		LL_USART_EnableIT_IDLE(USARTxHandlerType->USARTxCOM);
	}
	else
	{
		LL_USART_DisableIT_IDLE(USARTxHandlerType->USARTxCOM);
	}
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART_HandlerType_GPIO_SetPinMode(USART_HandlerType *USARTxHandlerType, UINT32_T msg)
{
	if (msg== USART_TxPin_SET_INPUT)
	{
		LL_GPIO_SetPinMode(USARTxHandlerType->USARTxGPIOx, USARTxHandlerType->USARTxTxPin, LL_GPIO_MODE_INPUT);
	}
	else
	{
		LL_GPIO_SetPinMode(USARTxHandlerType->USARTxGPIOx, USARTxHandlerType->USARTxTxPin, LL_GPIO_MODE_ALTERNATE);
	}
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数:			
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART_HandlerType_TransmitData8(USART_HandlerType *USARTxHandlerType, UINT8_T msg)
{
	//---发送数据
	LL_USART_TransmitData8(USARTxHandlerType->USARTxCOM, msg);
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART_HandlerType_TransmitData9(USART_HandlerType *USARTxHandlerType, UINT16_T msg)
{
	//---发送数据
	LL_USART_TransmitData9(USARTxHandlerType->USARTxCOM, msg);
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART_HandlerType_ReceiveData8(USART_HandlerType *USARTxHandlerType )
{
	//---接收数据
	return LL_USART_ReceiveData8(USARTxHandlerType->USARTxCOM);
}
///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT16_T USART_HandlerType_ReceiveData9(USART_HandlerType *USARTxHandlerType )
{
	//---接收数据
	return LL_USART_ReceiveData9(USARTxHandlerType->USARTxCOM);
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART_HandlerType_SetBandRate(USART_HandlerType *USARTxHandlerType, UINT32_T bandRate)
{
	uint32_t periphclk = LL_RCC_PERIPH_FREQUENCY_NO;
	LL_RCC_ClocksTypeDef rcc_clocks;
	//===获取端口的总线时钟
	LL_RCC_GetSystemClocksFreq(&rcc_clocks);
	if ( USARTxHandlerType->USARTxCOM == USART1 )
	{
		periphclk = rcc_clocks.PCLK2_Frequency;
	}
	else if ( USARTxHandlerType->USARTxCOM == USART2 )
	{
		periphclk = rcc_clocks.PCLK1_Frequency;
	}
#if defined(USART3)
	else if ( USARTxHandlerType->USARTxCOM == USART3 )
	{
		periphclk = rcc_clocks.PCLK1_Frequency;
	}
#endif /* USART3 */
#if defined(USART6)
	else if ( USARTxHandlerType->USARTxCOM == USART6 )
	{
		periphclk = rcc_clocks.PCLK2_Frequency;
	}
#endif /* USART6 */
#if defined(UART4)
	else if ( USARTxHandlerType->USARTxCOM == UART4 )
	{
		periphclk = rcc_clocks.PCLK1_Frequency;
	}
#endif /* UART4 */
#if defined(UART5)
	else if ( USARTxHandlerType->USARTxCOM == UART5 )
	{
		periphclk = rcc_clocks.PCLK1_Frequency;
	}
#endif /* UART5 */
#if defined(UART7)
	else if ( USARTxHandlerType->USARTxCOM == UART7 )
	{
		periphclk = rcc_clocks.PCLK1_Frequency;
	}
#endif /* UART7 */
#if defined(UART8)
	else if ( USARTxHandlerType->USARTxCOM == UART8 )
	{
		periphclk = rcc_clocks.PCLK1_Frequency;
	}
#endif /* UART8 */
#if defined(UART9)
	else if ( USARTxHandlerType->USARTxCOM == UART9 )
	{
		periphclk = rcc_clocks.PCLK1_Frequency;
	}
#endif /* UART9 */
#if defined(UART10)
	else if ( USARTxHandlerType->USARTxCOM == UART10 )
	{
		periphclk = rcc_clocks.PCLK1_Frequency;
	}
#endif /* UART10 */

	//---获取过采样率
	UINT32_T overSampling = LL_USART_GetOverSampling(USARTxHandlerType->USARTxCOM);
	//---设置通信波特率
	LL_USART_SetBaudRate(USARTxHandlerType->USARTxCOM, periphclk, overSampling, bandRate);
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART_HandlerType_SetDataWidth(USART_HandlerType *USARTxHandlerType, UINT32_T dataWidth)
{
	LL_USART_SetDataWidth(USARTxHandlerType->USARTxCOM, dataWidth);
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART_HandlerType_SetParity(USART_HandlerType *USARTxHandlerType, UINT32_T Parity)
{
	LL_USART_SetParity(USARTxHandlerType->USARTxCOM, Parity);
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART_HandlerType_SetStopBits(USART_HandlerType *USARTxHandlerType, UINT32_T StopBits)
{
	LL_USART_SetStopBitsLength(USARTxHandlerType->USARTxCOM, StopBits);
	return 0;
}
///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART_HandlerType_DeInit(USART_HandlerType *USARTxHandlerType)
{
	if (USARTxHandlerType->USARTxCOM!=NULL)
	{
		LL_USART_DeInit(USARTxHandlerType->USARTxCOM);
		USART_DisableClock(USARTxHandlerType->USARTxCOM);
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART_HandlerType_StructInit( USART_HandlerType *USARTxHandlerType )
{

	USARTxHandlerType->USARTxTxHeader = 0;
	USARTxHandlerType->USARTxRxHeader = 0;
	USARTxHandlerType->USARTxTimeOut = 0;
	USARTxHandlerType->USARTxTxPin = 0;
	USARTxHandlerType->USARTxGPIOx = NULL;
	USARTxHandlerType->USARTxCOM = NULL;

	//---接收结构体的初始化
	USARTxHandlerType->USARTxRxHandlerType.rxIndex = 0;
	USARTxHandlerType->USARTxRxHandlerType.rxCount = 0;
	USARTxHandlerType->USARTxRxHandlerType.rxCrcVal = 0;
	USARTxHandlerType->USARTxRxHandlerType.rxCrcFlag = 0;
	USARTxHandlerType->USARTxRxHandlerType.rxStep = 0;
	USARTxHandlerType->USARTxRxHandlerType.rxBufferDataSize = 0;
	if( USARTxHandlerType->USARTxRxHandlerType.pRxBuffer != NULL )
	{
		free( USARTxHandlerType->USARTxRxHandlerType.pRxBuffer );
	}
	else
	{
		USARTxHandlerType->USARTxRxHandlerType.pRxBuffer = NULL;
	}

	//---发送数据的初始化
	USARTxHandlerType->USARTxTxHandlerType.txIndex = 0;
	USARTxHandlerType->USARTxTxHandlerType.txNum = 0;
	USARTxHandlerType->USARTxTxHandlerType.txCount = 0;
	USARTxHandlerType->USARTxTxHandlerType.txCrcVal = 0;
	USARTxHandlerType->USARTxTxHandlerType.txCrcFlag = 0;
	USARTxHandlerType->USARTxTxHandlerType.txStep = 0;
	USARTxHandlerType->USARTxTxHandlerType.txBufferDataSize = 0;
	if( USARTxHandlerType->USARTxTxHandlerType.pTxBuffer != NULL )
	{
		free( USARTxHandlerType->USARTxTxHandlerType.pTxBuffer );
	}
	else
	{
		USARTxHandlerType->USARTxTxHandlerType.pTxBuffer = NULL;
	}
	//---消息处理结构体
	USARTxHandlerType->USART_MSG_Task = NULL;
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART_HandlerType_Init( USART_HandlerType *USARTxHandlerType )
{
	if ( USARTxHandlerType== NULL )
	{
		return 1;
	}
	else
	{
		if ( USARTxHandlerType==USART1_HandlerType )
		{
			//---初始化串口1
			USART1_HandlerType_Init( USARTxHandlerType );
		}
		else if ( USARTxHandlerType==USART2_HandlerType )
		{
			//---初始化串口2
			USART2_HandlerType_Init( USARTxHandlerType );
		}
	#if defined(USART3)
		else if ( USARTxHandlerType==USART3_HandlerType )
		{
			//---初始化串口3
			USART3_HandlerType_Init( USARTxHandlerType );
		}
	#endif /* USART3 */
	#if defined(USART6)
		else if ( USARTxHandlerType==USART6_HandlerType )
		{
			//---初始化串口6
			USART6_HandlerType_Init( USARTxHandlerType );
		}
	#endif /* USART6 */
	#if defined(UART4)
		else if ( USARTxHandlerType==USART4_HandlerType )
		{
			//---初始化串口4
			USART4_HandlerType_Init( USARTxHandlerType );
		}
	#endif /* UART4 */
	#if defined(UART5)
		else if ( USARTxHandlerType==USART5_HandlerType )
		{
			//---初始化串口5
			USART5_HandlerType_Init( USARTxHandlerType );
		}
	#endif /* UART5 */
	#if defined(UART7)
		else if ( USARTxHandlerType==USART7_HandlerType )
		{
			//---初始化串口7
			USART7_HandlerType_Init( USARTxHandlerType );
		}
	#endif /* UART7 */
	#if defined(UART8)
		else if ( USARTxHandlerType==USART8_HandlerType )
		{
			//---初始化串口8
			USART8_HandlerType_Init( USARTxHandlerType );
		}
	#endif /* UART8 */
	#if defined(UART9)
		else if ( USARTxHandlerType==USART9_HandlerType )
		{
			//---初始化串口9
			USART9_HandlerType_Init( USARTxHandlerType );
		}
	#endif /* UART9 */
	#if defined(UART10)
		else if ( USARTxHandlerType==USART10_HandlerType )
		{
			//---初始化串口2
			USART10_HandlerType_Init( USARTxHandlerType );
		}
	#endif /* UART10 */

		return 0;
	}
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART1_HandlerType_Init(USART_HandlerType *USARTxHandlerType)
{
	//---使能端口时钟
	GPIO_EnableClock(GPIOA);
	//---GPIO的结构体
	LL_GPIO_InitTypeDef GPIO_InitStruct;

	//---USART1 GPIO Configuration
	//---PA9  ------> USART1_TX---端口复用为7
	//---PA10 ------> USART1_RX---端口复用为7

	//---端口号
	GPIO_InitStruct.Pin						= LL_GPIO_PIN_9 | LL_GPIO_PIN_10;
	//---模式配置
	GPIO_InitStruct.Mode					= LL_GPIO_MODE_ALTERNATE;
	//---工作速度
	GPIO_InitStruct.Speed					= LL_GPIO_SPEED_FREQ_VERY_HIGH;
	//---复用功能的推完输出
	GPIO_InitStruct.OutputType				= LL_GPIO_OUTPUT_PUSHPULL;
	//---输入上拉使能
	GPIO_InitStruct.Pull					= LL_GPIO_PULL_UP;
	//---复用功能为USART1
	GPIO_InitStruct.Alternate				= LL_GPIO_AF_7;
	LL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	//---使能USART1的时钟信号
	USART_EnableClock(USART1);
	//---USART的接口结构体
	LL_USART_InitTypeDef USART_InitStruct;
	//---通信波特率
	USART_InitStruct.BaudRate				= USART1_BANDRATE_VAL;//115200;
	USART_InitStruct.DataWidth				= LL_USART_DATAWIDTH_8B;
	USART_InitStruct.StopBits				= LL_USART_STOPBITS_1;
	USART_InitStruct.Parity					= LL_USART_PARITY_NONE;
	//---配置为收发模式
	USART_InitStruct.TransferDirection		= LL_USART_DIRECTION_TX_RX;
	//---硬件流控制---默认为无
	USART_InitStruct.HardwareFlowControl	= LL_USART_HWCONTROL_NONE;
	//---过采样次数---默认配置为16
	USART_InitStruct.OverSampling			= LL_USART_OVERSAMPLING_16;
	//---初始化串口
	LL_USART_Init(USART1, &USART_InitStruct);
	//---串口异步模式配置
	LL_USART_ConfigAsyncMode(USART1);
	//---使能串口
	LL_USART_Enable(USART1);
	//---使能接收中断
	LL_USART_EnableIT_RXNE(USART1);
	//---USART1_IRQ中断配置---中断等级配置
	NVIC_SetPriority(USART1_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping( ), 1, 0));
	//---使能中断
	NVIC_EnableIRQ(USART1_IRQn);
	//---配置消息结构体中的信息
	USARTxHandlerType->USARTxGPIOx		= GPIOA;
	USARTxHandlerType->USARTxTxPin		= LL_GPIO_PIN_9;
	USARTxHandlerType->USARTxCOM		= USART1;
	//---自定义的发送和接收报头
	USARTxHandlerType->USARTxRxHeader	= USART1_RECE_HEADER;
	USARTxHandlerType->USARTxTxHeader	= USART1_SEND_HEADER;
	USART_HandlerType_GPIO_SetPinMode(USARTxHandlerType, LL_GPIO_MODE_INPUT);
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数：
//////功	   能：
//////输入参数: 
//////输出参数: 
//////说	   明：
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART2_HandlerType_Init( USART_HandlerType *USARTxHandlerType )
{
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数：
//////功	   能：
//////输入参数: 
//////输出参数: 
//////说	   明：
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART3_HandlerType_Init( USART_HandlerType *USARTxHandlerType )
{
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数：
//////功	   能：
//////输入参数: 
//////输出参数: 
//////说	   明：
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART4_HandlerType_Init( USART_HandlerType *USARTxHandlerType )
{
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数：
//////功	   能：
//////输入参数: 
//////输出参数: 
//////说	   明：
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART5_HandlerType_Init( USART_HandlerType *USARTxHandlerType )
{
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数：
//////功	   能：
//////输入参数: 
//////输出参数: 
//////说	   明：
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART6_HandlerType_Init( USART_HandlerType *USARTxHandlerType )
{
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数：
//////功	   能：
//////输入参数: 
//////输出参数: 
//////说	   明：
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART7_HandlerType_Init( USART_HandlerType *USARTxHandlerType )
{
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数：
//////功	   能：
//////输入参数: 
//////输出参数: 
//////说	   明：
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART8_HandlerType_Init( USART_HandlerType *USARTxHandlerType )
{
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数：
//////功	   能：
//////输入参数: 
//////输出参数: 
//////说	   明：
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART9_HandlerType_Init( USART_HandlerType *USARTxHandlerType )
{
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数：
//////功	   能：
//////输入参数: 
//////输出参数: 
//////说	   明：
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART10_HandlerType_Init( USART_HandlerType *USARTxHandlerType )
{
	return 0;
}
///////////////////////////////////////////////////////////////////////////////
//////函	   数： void USART_HandlerType_Printf(USART_HandlerType *USARTxHandlerType,char *fmt, ...)
//////功	   能： 多串口使用Printf重映射
//////输入参数: 
//////输出参数: 
//////说	   明： 本次发送和下次发送之间需要有延时，否则存在发送不成功的现象（上位机监视不到数据）
//////////////////////////////////////////////////////////////////////////////
void USART_HandlerType_Printf(USART_HandlerType *USARTxHandlerType,char *fmt, ...)
{
	char buffer[CMD_PRINTF_BUFFER_LEN+1];  // CMD_BUFFER_LEN长度自己定义吧
	UINT16_T i = 0;
	va_list arg_ptr;
	//---检查是否启动了完成中断
	UINT8_T usartTcFlag = LL_USART_IsActiveFlag_TC( USARTxHandlerType->USARTxCOM );
	if( usartTcFlag )
	{
		//---关闭发送完成中断
		LL_USART_DisableIT_TC( USARTxHandlerType->USARTxCOM );
	}
	//---设置发送端口为复用推挽输出功能
	USART_HandlerType_GPIO_SetPinMode( USARTxHandlerType, LL_GPIO_MODE_ALTERNATE );
	va_start(arg_ptr, fmt);
	vsnprintf(buffer, CMD_PRINTF_BUFFER_LEN+1, fmt, arg_ptr);
	while ((i <= CMD_PRINTF_BUFFER_LEN) && buffer)
	{
		LL_USART_TransmitData8(USARTxHandlerType->USARTxCOM, buffer[i]);
		while (LL_USART_IsActiveFlag_TC(USARTxHandlerType->USARTxCOM) == RESET);
		if (buffer[i]=='\n')
		{
			break;
		}
		else
		{
			i++;
		}
	}
	va_end(arg_ptr);
	if( usartTcFlag )
	{
		//---使能发送完成中断
		LL_USART_EnableIT_TC( USARTxHandlerType->USARTxCOM );
	}
	USART_HandlerType_GPIO_SetPinMode( USARTxHandlerType, LL_GPIO_MODE_INPUT );
}

