#include "usart_cfg.h"

//---ȫ�ֱ�������
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
//---ָ��ṹ��
pUSART_HandlerType pUSART1=&g_USART1;

///////////////////////////////////////////////////////////////////////////////
//////��	   ����
//////��	   �ܣ�
//////�������: 
//////�������: 
//////˵	   ����
//////////////////////////////////////////////////////////////////////////////
void USART_EnableClock(USART_TypeDef *USARTx)
{
	if ( USARTx == USART1 )
	{
		//---ʹ��USART1��ʱ���ź�
		LL_APB2_GRP1_EnableClock( LL_APB2_GRP1_PERIPH_USART1 );
	}
	else if ( USARTx == USART2 )
	{
		//---ʹ��USART2��ʱ���ź�
		LL_APB1_GRP1_EnableClock( LL_APB1_GRP1_PERIPH_USART2 );
	}
	#if defined(USART3)
		else if ( USARTx == USART3 )
		{
			//---ʹ��USART3��ʱ���ź�
			LL_APB1_GRP1_EnableClock( LL_APB1_GRP1_PERIPH_USART3 );
		}
	#endif /* USART3 */
	#if defined(USART6)
		else if ( USARTx == USART6 )
		{
			//---ʹ��USART6��ʱ���ź�
			LL_APB2_GRP1_EnableClock( LL_APB2_GRP1_PERIPH_USART6 );
		}
	#endif /* USART6 */
	#if defined(UART4)
		else if ( USARTx == UART4 )
		{
			//---ʹ��UART4��ʱ���ź�
			LL_APB1_GRP1_EnableClock( LL_APB1_GRP1_PERIPH_UART4 );
		}
	#endif /* UART4 */
	#if defined(UART5)
		else if ( USARTx == UART5 )
		{
			//---ʹ��UART5��ʱ���ź�
			LL_APB1_GRP1_EnableClock( LL_APB1_GRP1_PERIPH_UART5 );
		}
	#endif /* UART5 */
	#if defined(UART7)
		else if ( USARTx == UART7 )
		{
			//---ʹ��UART7��ʱ���ź�
			LL_APB1_GRP1_EnableClock( LL_APB1_GRP1_PERIPH_UART8 );
		}
	#endif /* UART7 */
	#if defined(UART8)
		else if ( USARTx == UART8 )
		{
			//---ʹ��UART8��ʱ���ź�
			LL_APB1_GRP1_EnableClock( LL_APB1_GRP1_PERIPH_UART8 );
		}
	#endif /* UART8 */
	#if defined(UART9)
		else if ( USARTx == UART9 )
		{
			//---ʹ��USART9��ʱ���ź�
			LL_APB2_GRP1_EnableClock( LL_APB2_GRP1_PERIPH_UART9 );
		}
	#endif /* UART9 */
	#if defined(UART10)
		else if ( USARTx == UART10 )
		{
			//---ʹ��USART10��ʱ���ź�
			LL_APB2_GRP1_EnableClock( LL_APB2_GRP1_PERIPH_UART10 );
		}
	#endif /* UART10 */
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ����
//////��	   �ܣ�
//////�������: 
//////�������: 
//////˵	   ����
//////////////////////////////////////////////////////////////////////////////
void USART_DisableClock(USART_TypeDef *USARTx)
{
	if (USARTx == USART1)
	{
		//---ʹ��USART1��ʱ���ź�
		LL_APB2_GRP1_DisableClock(LL_APB2_GRP1_PERIPH_USART1);
	}
	else if (USARTx == USART2)
	{
		//---ʹ��USART2��ʱ���ź�
		LL_APB1_GRP1_DisableClock(LL_APB1_GRP1_PERIPH_USART2);
	}
#if defined(USART3)
	else if (USARTx == USART3)
	{
		//---ʹ��USART3��ʱ���ź�
		LL_APB1_GRP1_DisableClock(LL_APB1_GRP1_PERIPH_USART3);
	}
#endif /* USART3 */
#if defined(USART6)
	else if (USARTx == USART6)
	{
		//---ʹ��USART6��ʱ���ź�
		LL_APB2_GRP1_DisableClock(LL_APB2_GRP1_PERIPH_USART6);
	}
#endif /* USART6 */
#if defined(UART4)
	else if (USARTx == UART4)
	{
		//---ʹ��UART4��ʱ���ź�
		LL_APB1_GRP1_DisableClock(LL_APB1_GRP1_PERIPH_UART4);
	}
#endif /* UART4 */
#if defined(UART5)
	else if (USARTx == UART5)
	{
		//---ʹ��UART5��ʱ���ź�
		LL_APB1_GRP1_DisableClock(LL_APB1_GRP1_PERIPH_UART5);
	}
#endif /* UART5 */
#if defined(UART7)
	else if (USARTx == UART7)
	{
		//---ʹ��UART7��ʱ���ź�
		LL_APB1_GRP1_DisableClock(LL_APB1_GRP1_PERIPH_UART8);
	}
#endif /* UART7 */
#if defined(UART8)
	else if (USARTx == UART8)
	{
		//---ʹ��UART8��ʱ���ź�
		LL_APB1_GRP1_DisableClock(LL_APB1_GRP1_PERIPH_UART8);
	}
#endif /* UART8 */
#if defined(UART9)
	else if (USARTx == UART9)
	{
		//---ʹ��USART9��ʱ���ź�
		LL_APB2_GRP1_DisableClock(LL_APB2_GRP1_PERIPH_UART9);
	}
#endif /* UART9 */
#if defined(UART10)
	else if (USARTx == UART10)
	{
		//---ʹ��USART10��ʱ���ź�
		LL_APB2_GRP1_DisableClock(LL_APB2_GRP1_PERIPH_UART10);
	}
#endif /* UART10 */
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
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
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
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
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
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
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
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
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
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
//////��	   ���� 
//////��	   �ܣ� 
//////�������:			
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART_HandlerType_TransmitData8(USART_HandlerType *USARTxHandlerType, UINT8_T msg)
{
	//---��������
	LL_USART_TransmitData8(USARTxHandlerType->USARTxCOM, msg);
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART_HandlerType_TransmitData9(USART_HandlerType *USARTxHandlerType, UINT16_T msg)
{
	//---��������
	LL_USART_TransmitData9(USARTxHandlerType->USARTxCOM, msg);
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART_HandlerType_ReceiveData8(USART_HandlerType *USARTxHandlerType )
{
	//---��������
	return LL_USART_ReceiveData8(USARTxHandlerType->USARTxCOM);
}
///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT16_T USART_HandlerType_ReceiveData9(USART_HandlerType *USARTxHandlerType )
{
	//---��������
	return LL_USART_ReceiveData9(USARTxHandlerType->USARTxCOM);
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART_HandlerType_SetBandRate(USART_HandlerType *USARTxHandlerType, UINT32_T bandRate)
{
	uint32_t periphclk = LL_RCC_PERIPH_FREQUENCY_NO;
	LL_RCC_ClocksTypeDef rcc_clocks;
	//===��ȡ�˿ڵ�����ʱ��
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

	//---��ȡ��������
	UINT32_T overSampling = LL_USART_GetOverSampling(USARTxHandlerType->USARTxCOM);
	//---����ͨ�Ų�����
	LL_USART_SetBaudRate(USARTxHandlerType->USARTxCOM, periphclk, overSampling, bandRate);
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART_HandlerType_SetDataWidth(USART_HandlerType *USARTxHandlerType, UINT32_T dataWidth)
{
	LL_USART_SetDataWidth(USARTxHandlerType->USARTxCOM, dataWidth);
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART_HandlerType_SetParity(USART_HandlerType *USARTxHandlerType, UINT32_T Parity)
{
	LL_USART_SetParity(USARTxHandlerType->USARTxCOM, Parity);
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART_HandlerType_SetStopBits(USART_HandlerType *USARTxHandlerType, UINT32_T StopBits)
{
	LL_USART_SetStopBitsLength(USARTxHandlerType->USARTxCOM, StopBits);
	return 0;
}
///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
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
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART_HandlerType_StructInit( USART_HandlerType *USARTxHandlerType )
{

	USARTxHandlerType->USARTxTxHeader = 0;
	USARTxHandlerType->USARTxRxHeader = 0;
	USARTxHandlerType->USARTxTimeOut = 0;
	USARTxHandlerType->USARTxTxPin = 0;
	USARTxHandlerType->USARTxGPIOx = NULL;
	USARTxHandlerType->USARTxCOM = NULL;

	//---���սṹ��ĳ�ʼ��
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

	//---�������ݵĳ�ʼ��
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
	//---��Ϣ����ṹ��
	USARTxHandlerType->USART_MSG_Task = NULL;
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
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
			//---��ʼ������1
			USART1_HandlerType_Init( USARTxHandlerType );
		}
		else if ( USARTxHandlerType==USART2_HandlerType )
		{
			//---��ʼ������2
			USART2_HandlerType_Init( USARTxHandlerType );
		}
	#if defined(USART3)
		else if ( USARTxHandlerType==USART3_HandlerType )
		{
			//---��ʼ������3
			USART3_HandlerType_Init( USARTxHandlerType );
		}
	#endif /* USART3 */
	#if defined(USART6)
		else if ( USARTxHandlerType==USART6_HandlerType )
		{
			//---��ʼ������6
			USART6_HandlerType_Init( USARTxHandlerType );
		}
	#endif /* USART6 */
	#if defined(UART4)
		else if ( USARTxHandlerType==USART4_HandlerType )
		{
			//---��ʼ������4
			USART4_HandlerType_Init( USARTxHandlerType );
		}
	#endif /* UART4 */
	#if defined(UART5)
		else if ( USARTxHandlerType==USART5_HandlerType )
		{
			//---��ʼ������5
			USART5_HandlerType_Init( USARTxHandlerType );
		}
	#endif /* UART5 */
	#if defined(UART7)
		else if ( USARTxHandlerType==USART7_HandlerType )
		{
			//---��ʼ������7
			USART7_HandlerType_Init( USARTxHandlerType );
		}
	#endif /* UART7 */
	#if defined(UART8)
		else if ( USARTxHandlerType==USART8_HandlerType )
		{
			//---��ʼ������8
			USART8_HandlerType_Init( USARTxHandlerType );
		}
	#endif /* UART8 */
	#if defined(UART9)
		else if ( USARTxHandlerType==USART9_HandlerType )
		{
			//---��ʼ������9
			USART9_HandlerType_Init( USARTxHandlerType );
		}
	#endif /* UART9 */
	#if defined(UART10)
		else if ( USARTxHandlerType==USART10_HandlerType )
		{
			//---��ʼ������2
			USART10_HandlerType_Init( USARTxHandlerType );
		}
	#endif /* UART10 */

		return 0;
	}
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART1_HandlerType_Init(USART_HandlerType *USARTxHandlerType)
{
	//---ʹ�ܶ˿�ʱ��
	GPIO_EnableClock(GPIOA);
	//---GPIO�Ľṹ��
	LL_GPIO_InitTypeDef GPIO_InitStruct;

	//---USART1 GPIO Configuration
	//---PA9  ------> USART1_TX---�˿ڸ���Ϊ7
	//---PA10 ------> USART1_RX---�˿ڸ���Ϊ7

	//---�˿ں�
	GPIO_InitStruct.Pin						= LL_GPIO_PIN_9 | LL_GPIO_PIN_10;
	//---ģʽ����
	GPIO_InitStruct.Mode					= LL_GPIO_MODE_ALTERNATE;
	//---�����ٶ�
	GPIO_InitStruct.Speed					= LL_GPIO_SPEED_FREQ_VERY_HIGH;
	//---���ù��ܵ��������
	GPIO_InitStruct.OutputType				= LL_GPIO_OUTPUT_PUSHPULL;
	//---��������ʹ��
	GPIO_InitStruct.Pull					= LL_GPIO_PULL_UP;
	//---���ù���ΪUSART1
	GPIO_InitStruct.Alternate				= LL_GPIO_AF_7;
	LL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	//---ʹ��USART1��ʱ���ź�
	USART_EnableClock(USART1);
	//---USART�Ľӿڽṹ��
	LL_USART_InitTypeDef USART_InitStruct;
	//---ͨ�Ų�����
	USART_InitStruct.BaudRate				= USART1_BANDRATE_VAL;//115200;
	USART_InitStruct.DataWidth				= LL_USART_DATAWIDTH_8B;
	USART_InitStruct.StopBits				= LL_USART_STOPBITS_1;
	USART_InitStruct.Parity					= LL_USART_PARITY_NONE;
	//---����Ϊ�շ�ģʽ
	USART_InitStruct.TransferDirection		= LL_USART_DIRECTION_TX_RX;
	//---Ӳ��������---Ĭ��Ϊ��
	USART_InitStruct.HardwareFlowControl	= LL_USART_HWCONTROL_NONE;
	//---����������---Ĭ������Ϊ16
	USART_InitStruct.OverSampling			= LL_USART_OVERSAMPLING_16;
	//---��ʼ������
	LL_USART_Init(USART1, &USART_InitStruct);
	//---�����첽ģʽ����
	LL_USART_ConfigAsyncMode(USART1);
	//---ʹ�ܴ���
	LL_USART_Enable(USART1);
	//---ʹ�ܽ����ж�
	LL_USART_EnableIT_RXNE(USART1);
	//---USART1_IRQ�ж�����---�жϵȼ�����
	NVIC_SetPriority(USART1_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping( ), 1, 0));
	//---ʹ���ж�
	NVIC_EnableIRQ(USART1_IRQn);
	//---������Ϣ�ṹ���е���Ϣ
	USARTxHandlerType->USARTxGPIOx		= GPIOA;
	USARTxHandlerType->USARTxTxPin		= LL_GPIO_PIN_9;
	USARTxHandlerType->USARTxCOM		= USART1;
	//---�Զ���ķ��ͺͽ��ձ�ͷ
	USARTxHandlerType->USARTxRxHeader	= USART1_RECE_HEADER;
	USARTxHandlerType->USARTxTxHeader	= USART1_SEND_HEADER;
	USART_HandlerType_GPIO_SetPinMode(USARTxHandlerType, LL_GPIO_MODE_INPUT);
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ����
//////��	   �ܣ�
//////�������: 
//////�������: 
//////˵	   ����
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART2_HandlerType_Init( USART_HandlerType *USARTxHandlerType )
{
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ����
//////��	   �ܣ�
//////�������: 
//////�������: 
//////˵	   ����
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART3_HandlerType_Init( USART_HandlerType *USARTxHandlerType )
{
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ����
//////��	   �ܣ�
//////�������: 
//////�������: 
//////˵	   ����
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART4_HandlerType_Init( USART_HandlerType *USARTxHandlerType )
{
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ����
//////��	   �ܣ�
//////�������: 
//////�������: 
//////˵	   ����
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART5_HandlerType_Init( USART_HandlerType *USARTxHandlerType )
{
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ����
//////��	   �ܣ�
//////�������: 
//////�������: 
//////˵	   ����
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART6_HandlerType_Init( USART_HandlerType *USARTxHandlerType )
{
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ����
//////��	   �ܣ�
//////�������: 
//////�������: 
//////˵	   ����
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART7_HandlerType_Init( USART_HandlerType *USARTxHandlerType )
{
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ����
//////��	   �ܣ�
//////�������: 
//////�������: 
//////˵	   ����
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART8_HandlerType_Init( USART_HandlerType *USARTxHandlerType )
{
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ����
//////��	   �ܣ�
//////�������: 
//////�������: 
//////˵	   ����
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART9_HandlerType_Init( USART_HandlerType *USARTxHandlerType )
{
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ����
//////��	   �ܣ�
//////�������: 
//////�������: 
//////˵	   ����
//////////////////////////////////////////////////////////////////////////////
UINT8_T USART10_HandlerType_Init( USART_HandlerType *USARTxHandlerType )
{
	return 0;
}
///////////////////////////////////////////////////////////////////////////////
//////��	   ���� void USART_HandlerType_Printf(USART_HandlerType *USARTxHandlerType,char *fmt, ...)
//////��	   �ܣ� �മ��ʹ��Printf��ӳ��
//////�������: 
//////�������: 
//////˵	   ���� ���η��ͺ��´η���֮����Ҫ����ʱ��������ڷ��Ͳ��ɹ���������λ�����Ӳ������ݣ�
//////////////////////////////////////////////////////////////////////////////
void USART_HandlerType_Printf(USART_HandlerType *USARTxHandlerType,char *fmt, ...)
{
	char buffer[CMD_PRINTF_BUFFER_LEN+1];  // CMD_BUFFER_LEN�����Լ������
	UINT16_T i = 0;
	va_list arg_ptr;
	//---����Ƿ�����������ж�
	UINT8_T usartTcFlag = LL_USART_IsActiveFlag_TC( USARTxHandlerType->USARTxCOM );
	if( usartTcFlag )
	{
		//---�رշ�������ж�
		LL_USART_DisableIT_TC( USARTxHandlerType->USARTxCOM );
	}
	//---���÷��Ͷ˿�Ϊ���������������
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
		//---ʹ�ܷ�������ж�
		LL_USART_EnableIT_TC( USARTxHandlerType->USARTxCOM );
	}
	USART_HandlerType_GPIO_SetPinMode( USARTxHandlerType, LL_GPIO_MODE_INPUT );
}

