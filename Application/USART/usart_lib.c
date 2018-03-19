#include "usart_lib.h"

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_IT_TC(USART_HandlerType *USARTxHandlerType, UINT8_T msg)
{
	return USART_HandlerType_IT_TC(USARTxHandlerType, msg);
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_IT_TXE(USART_HandlerType *USARTxHandlerType, UINT8_T msg)
{
	return USART_HandlerType_IT_TXE(USARTxHandlerType, msg);
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_IT_RXNE(USART_HandlerType *USARTxHandlerType, UINT8_T msg)
{
	return USART_HandlerType_IT_RXNE(USARTxHandlerType, msg);
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_IT_IDLE(USART_HandlerType *USARTxHandlerType, UINT8_T msg)
{
	return USART_HandlerType_IT_IDLE(USARTxHandlerType, msg);
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_GPIO_SetPinMode(USART_HandlerType *USARTxHandlerType, UINT32_T msg)
{
	return USART_HandlerType_GPIO_SetPinMode(USARTxHandlerType, msg);
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_TransmitData8(USART_HandlerType *USARTxHandlerType, UINT8_T msg)
{
	return USART_HandlerType_TransmitData8(USARTxHandlerType, msg);
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_TransmitData9(USART_HandlerType *USARTxHandlerType, UINT16_T msg)
{
	return USART_HandlerType_TransmitData9(USARTxHandlerType, msg);
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_ReceiveData8(USART_HandlerType *USARTxHandlerType)
{
	return USART_HandlerType_ReceiveData8(USARTxHandlerType);
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT16_T USARTLib_HandlerType_ReceiveData9(USART_HandlerType *USARTxHandlerType)
{
	return USART_HandlerType_ReceiveData9(USARTxHandlerType);
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_SetBandRate(USART_HandlerType *USARTxHandlerType, UINT32_T bandRate)
{
	return USART_HandlerType_SetBandRate(USARTxHandlerType,bandRate);
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_SetDataWidth(USART_HandlerType *USARTxHandlerType, UINT32_T dataWidth)
{
	return USART_HandlerType_SetDataWidth( USARTxHandlerType, dataWidth);
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_SetParity(USART_HandlerType *USARTxHandlerType, UINT32_T Parity)
{
	return USART_HandlerType_SetParity( USARTxHandlerType, Parity);
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_SetStopBits(USART_HandlerType *USARTxHandlerType, UINT32_T StopBits)
{
	return USART_HandlerType_SetStopBits( USARTxHandlerType, StopBits);
}
///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_Init(USART_HandlerType *USARTxHandlerType, UINT16_T bufferSize)
{
	USART_HandlerType_StructInit(USARTxHandlerType);
	//---初始化接收数据结构体
	USARTxHandlerType->USARTxRxHandlerType.rxBufferDataSize = bufferSize;
	//---申请接收缓存区
	USARTxHandlerType->USARTxRxHandlerType.pRxBuffer = (UINT8_T *)malloc(bufferSize + 1);
	//---清零发送缓存区
	memset(USARTxHandlerType->USARTxRxHandlerType.pRxBuffer, 0, ( bufferSize + 1 ));
	//---初始化发送数据结构体
	USARTxHandlerType->USARTxTxHandlerType.txBufferDataSize = bufferSize;
	//---申请发送缓存区
	USARTxHandlerType->USARTxTxHandlerType.pTxBuffer =(UINT8_T *)malloc(bufferSize + 1);
	//---清零接收缓存区
	memset(USARTxHandlerType->USARTxTxHandlerType.pTxBuffer, 0, ( bufferSize + 1 ));
	//---指针函数指向消息体处理函数函数
	USARTxHandlerType->USART_MSG_Task=USARTLib_HandlerType_Msg;
	//---硬件串口的初始化
	USARTxHandlerType->USART_MSG_Task(USARTxHandlerType, bufferSize, USART_MSG_Init);
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_DeInit(USART_HandlerType *USARTxHandlerType)
{
	USART_HandlerType_DeInit(USARTxHandlerType);
	USART_HandlerType_StructInit(USARTxHandlerType);
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_RXNEHandler(USART_HandlerType *USARTxHandlerType, UINT8_T val)
{
	//---保存数到的数据
	UINT8_T tempVal = val;
	//---数据判断
	switch (USARTxHandlerType->USARTxRxHandlerType.rxStep)
	{
		case 0:										//---获取接收数据是否合理
			//---判断是否允许数据的接收
			if (USARTxHandlerType->USARTxRxHandlerType.rxIndex == 0)
			{
				//---判断报头是否合理
				if (tempVal == USARTxHandlerType->USARTxRxHeader)
				{
					USARTxHandlerType->USARTxRxHandlerType.pRxBuffer[0] = tempVal;
					USARTxHandlerType->USARTxRxHandlerType.rxCrcVal = tempVal;
					USARTxHandlerType->USARTxRxHandlerType.rxStep = 1;
				}
			}
			break;
		case 1:										//---获取接收数据长度
			//---判断数据接收书否合法
			if ((tempVal > 0) && (tempVal < (USARTxHandlerType->USARTxRxHandlerType.rxBufferDataSize)))
			{
				USARTxHandlerType->USARTxRxHandlerType.pRxBuffer[1] = tempVal;
				USARTxHandlerType->USARTxRxHandlerType.rxCrcVal += tempVal;
				USARTxHandlerType->USARTxRxHandlerType.rxCount = tempVal;
				USARTxHandlerType->USARTxRxHandlerType.rxStep = 2;
			}
			else
			{
				//---数据长度不合法，数据接收重新置位
				USARTxHandlerType->USARTxRxHandlerType.rxStep = 0;
			}
			USARTxHandlerType->USARTxRxHandlerType.rxIndex = 0;
			break;
		case 2:										//---获取接收数据
			USARTxHandlerType->USARTxRxHandlerType.pRxBuffer[USARTxHandlerType->USARTxRxHandlerType.rxIndex + 2] = tempVal;
			USARTxHandlerType->USARTxRxHandlerType.rxIndex++;
			//---判断数据是否接收完成
			if ((USARTxHandlerType->USARTxRxHandlerType.rxIndex) >= (USARTxHandlerType->USARTxRxHandlerType.rxCount))
			{
				//---获取校验和
				USARTxHandlerType->USARTxRxHandlerType.rxStep = 3;
				//----将接收报头转换成发送报头---如果这里不置位，则在发送的时候置位
				//UsartHandlerTypeDef->usartRxdHandlerTypedef.pRxBuffer[0] = USARTxHandlerType->USARTxTxHeader;
			}
			else
			{
				//---计算校验和
				USARTxHandlerType->USARTxRxHandlerType.rxCrcVal += tempVal;
			}
			break;
		case 3:										//---获取校验和
			if (USARTxHandlerType->USARTxRxHandlerType.rxCrcFlag != 0)
			{
				//---获取校验和
				USARTxHandlerType->USARTxRxHandlerType.rxCrcVal = (~USARTxHandlerType->USARTxRxHandlerType.rxCrcVal) + 1;
				if (USARTxHandlerType->USARTxRxHandlerType.rxCrcVal != tempVal)
				{
					//---数据接收和发送的校验和不对
					USARTxHandlerType->USARTxRxHandlerType.rxIndex = 0;
					USARTxHandlerType->USARTxRxHandlerType.rxStep = 5;
				}
				break;
			}
			else
			{
				USARTxHandlerType->USARTxRxHandlerType.rxStep = 4;
			}
			break;
		case 4:
		case 5:
		default:
			break;
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
UINT8_T USARTLib_HandlerType_TXEHandler(USART_HandlerType *USARTxHandlerType)
{
	//===判断是否有数据的发送
	if (USARTxHandlerType->USARTxTxHandlerType.txCount != 0)
	{
		switch (USARTxHandlerType->USARTxTxHandlerType.txStep)
		{
			case 0:											//---数据发送
				//---判断发送缓存区的内容
				if (USARTxHandlerType->USARTxTxHandlerType.txIndex != USARTxHandlerType->USARTxTxHandlerType.txNum)
				{
					//---发送8Bit的数据
					USARTxHandlerType->USART_MSG_Task(USARTxHandlerType, USARTxHandlerType->USARTxTxHandlerType.pTxBuffer[USARTxHandlerType->USARTxTxHandlerType.txNum], USART_MSG_Transmite);
					//---数据缓存区左移
					USARTxHandlerType->USARTxTxHandlerType.txNum++;
					//---校验缓存区是否溢出
					if (USARTxHandlerType->USARTxTxHandlerType.txNum > USARTxHandlerType->USARTxTxHandlerType.txBufferDataSize)
					{
						USARTxHandlerType->USARTxTxHandlerType.txNum = 0;
					}
				}
				else
				{
					USARTxHandlerType->USARTxTxHandlerType.txStep = 1;
				}
				break;
			case 1:											//---校验和的发送
				USARTxHandlerType->USARTxTxHandlerType.txStep = 2;
				//---判断是是否发送校验和信息
				if (USARTxHandlerType->USARTxTxHandlerType.txCrcFlag != 0)
				{
					USARTxHandlerType->USARTxTxHandlerType.txCrcVal = 0;
				}
				else
				{
					//---发送完成,发送数据寄存器空中断不使能
					USARTxHandlerType->USART_MSG_Task(USARTxHandlerType, DISABLE, USART_MSG_IT_TXE);
					//---使能发送完成中断---如果继续使用数据寄存器空中断，在步骤三的时候修改发送端口为输入状态，这样会导致校验和的发送失败；这里采用使用发送完成中断
					USARTxHandlerType->USART_MSG_Task(USARTxHandlerType, ENABLE, USART_MSG_IT_TC);
					//---发送校验和数据
					USARTxHandlerType->USART_MSG_Task(USARTxHandlerType, USARTxHandlerType->USARTxTxHandlerType.txCrcVal, USART_MSG_Transmite);
					/*USARTxHandlerType->USARTxTxHandlerType.txCrcVal = 0;
					USARTxHandlerType->USARTxTxHandlerType.txCrcFlag = 0;*/
					break;
				}
			case 2:											//---数据发送完成
				//---发送完成,发送数据寄存器空中断不使能
				USARTxHandlerType->USART_MSG_Task(USARTxHandlerType, DISABLE, USART_MSG_IT_TXE);
				//数据发送完成,清零发送数据长度
				USARTxHandlerType->USARTxTxHandlerType.txCount = 0;
				//---本次发送完成
				USARTxHandlerType->USARTxTxHandlerType.txStep = 3;
				//---缓存区序号归零处理
				USARTxHandlerType->USARTxTxHandlerType.txIndex = 0;
				USARTxHandlerType->USARTxTxHandlerType.txNum = 0;
				//---设置发送端口为输入模式
				USARTxHandlerType->USART_MSG_Task(USARTxHandlerType, USART_TxPin_SET_INPUT, USART_MSG_GPIO_Init);
				break;
			case 3:
			case 4:
			default:
				break;
		}
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
UINT8_T USARTLib_HandlerType_TCHandler(USART_HandlerType *USARTxHandlerType)
{
	//---不使能数据发送完成中断
	USARTxHandlerType->USART_MSG_Task(USARTxHandlerType, DISABLE, USART_MSG_IT_TC);
	//数据发送完成,清零发送数据长度
	USARTxHandlerType->USARTxTxHandlerType.txCount = 0;
	//---本次发送完成
	USARTxHandlerType->USARTxTxHandlerType.txStep = 3;
	//---缓存区序号归零处理
	USARTxHandlerType->USARTxTxHandlerType.txIndex = 0;
	USARTxHandlerType->USARTxTxHandlerType.txNum = 0;
	//---设置发送端口为输入模式
	USARTxHandlerType->USART_MSG_Task(USARTxHandlerType, USART_TxPin_SET_INPUT, USART_MSG_GPIO_Init);
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_TXESendByte(USART_HandlerType *USARTxHandlerType, UINT8_T val)
{
	//---设置TX端口为复用推挽输出
	USARTxHandlerType->USART_MSG_Task(USARTxHandlerType, USART_TxPin_SET_OUTPUT, USART_MSG_GPIO_Init);
	//---填充数据到缓存区
	USARTxHandlerType->USARTxTxHandlerType.pTxBuffer[USARTxHandlerType->USARTxTxHandlerType.txIndex] = val;
	USARTxHandlerType->USARTxTxHandlerType.txIndex++;
	//---判断混存区是否溢出
	if (USARTxHandlerType->USARTxTxHandlerType.txIndex >= USARTxHandlerType->USARTxTxHandlerType.txBufferDataSize)
	{
		USARTxHandlerType->USARTxTxHandlerType.txIndex = 0x00;
		USARTxHandlerType->USARTxTxHandlerType.txNum = 0x00;
	}
	//---不发送校验和
	USARTxHandlerType->USARTxTxHandlerType.txCrcFlag = 1;
	//---允许发送
	USARTxHandlerType->USARTxTxHandlerType.txStep = 0x00;
	//---启动数据寄存器空中断
	USARTxHandlerType->USART_MSG_Task(USARTxHandlerType, ENABLE, USART_MSG_IT_TXE);
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_TXESendByteCrc(USART_HandlerType *USARTxHandlerType, UINT8_T val)
{
	//---设置TX端口为复用推挽输出
	USARTxHandlerType->USART_MSG_Task(USARTxHandlerType, USART_TxPin_SET_OUTPUT, USART_MSG_GPIO_Init);
	//---填充数据到缓存区
	USARTxHandlerType->USARTxTxHandlerType.pTxBuffer[USARTxHandlerType->USARTxTxHandlerType.txIndex] = val;
	USARTxHandlerType->USARTxTxHandlerType.txIndex++;
	//---CRC校验和的计算
	USARTxHandlerType->USARTxTxHandlerType.txCrcVal += val;
	//---判断混存区是否溢出
	if (USARTxHandlerType->USARTxTxHandlerType.txIndex >= USARTxHandlerType->USARTxTxHandlerType.txBufferDataSize)
	{
		USARTxHandlerType->USARTxTxHandlerType.txIndex = 0x00;
		USARTxHandlerType->USARTxTxHandlerType.txNum = 0x00;
	}
	//---计算得到的校验和
	USARTxHandlerType->USARTxTxHandlerType.txCrcVal = (~(USARTxHandlerType->USARTxTxHandlerType.txCrcVal)) + 1;
	//---发送校验和
	USARTxHandlerType->USARTxTxHandlerType.txCrcFlag = 1;
	//---允许发送
	USARTxHandlerType->USARTxTxHandlerType.txStep = 0x00;
	//---启动数据寄存器空中断
	USARTxHandlerType->USART_MSG_Task(USARTxHandlerType, ENABLE, USART_MSG_IT_TXE);
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_TXESendData(USART_HandlerType *USARTxHandlerType, UINT8_T length)
{
	//---判断诗句长度是否合理，得到发送数据的长度
	if (length > USARTxHandlerType->USARTxTxHandlerType.txBufferDataSize)
	{
		length = USARTxHandlerType->USARTxTxHandlerType.txBufferDataSize;
	}
	else
	{
		USARTxHandlerType->USARTxTxHandlerType.txCount = length;
	}
	//---等待上次的数据发送完成---阻塞发送
	while ((USARTxHandlerType->USARTxTxHandlerType.txStep != 0x03))
	{
		//---判断数据是否启动了发送，获取发送完成的标志位
		if (USARTxHandlerType->USARTxTxHandlerType.txStep == 0)
		{
			break;
		}
	}
	//---设置TX端口为复用推挽输出
	USARTxHandlerType->USART_MSG_Task(USARTxHandlerType, USART_TxPin_SET_OUTPUT, USART_MSG_GPIO_Init);
	//---判断混存区是否溢出
	if (USARTxHandlerType->USARTxTxHandlerType.txIndex > USARTxHandlerType->USARTxTxHandlerType.txBufferDataSize)
	{
		USARTxHandlerType->USARTxTxHandlerType.txIndex = 0x00;
		USARTxHandlerType->USARTxTxHandlerType.txNum = 0x00;
	}
	//---CRC的值清零处理
	USARTxHandlerType->USARTxTxHandlerType.txCrcVal = 0;
	//---不发送校验和
	USARTxHandlerType->USARTxTxHandlerType.txCrcFlag = 1;
	//---允许发送
	USARTxHandlerType->USARTxTxHandlerType.txStep = 0x00;
	//---启动数据寄存器空中断
	USARTxHandlerType->USART_MSG_Task(USARTxHandlerType, ENABLE, USART_MSG_IT_TXE);
	//---允许接收
	USARTxHandlerType->USART_MSG_Task(USARTxHandlerType, 0, USART_MSG_RX_HandlerInit);
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_TXESendDataCrc(USART_HandlerType *USARTxHandlerType, UINT8_T length)
{
	UINT8_T i = 0;
	//---判断诗句长度是否合理，得到发送数据的长度
	if (length > USARTxHandlerType->USARTxTxHandlerType.txBufferDataSize)
	{
		length = USARTxHandlerType->USARTxTxHandlerType.txBufferDataSize;
	}
	else
	{
		USARTxHandlerType->USARTxTxHandlerType.txCount = length;
	}
	//---等待上次的数据发送完成---阻塞发送
	while ((USARTxHandlerType->USARTxTxHandlerType.txStep != 0x03))
	{
		//---判断数据是否启动了发送，获取发送完成的标志位
		if (USARTxHandlerType->USARTxTxHandlerType.txStep == 0)
		{
			break;
		}
	}
	//---设置TX端口为复用推挽输出
	USARTxHandlerType->USART_MSG_Task(USARTxHandlerType, USART_TxPin_SET_OUTPUT, USART_MSG_GPIO_Init);
	//---判断混存区是否溢出
	if (USARTxHandlerType->USARTxTxHandlerType.txIndex > USARTxHandlerType->USARTxTxHandlerType.txBufferDataSize)
	{
		USARTxHandlerType->USARTxTxHandlerType.txIndex = 0x00;
		USARTxHandlerType->USARTxTxHandlerType.txNum = 0x00;
	}
	//---CRC的值清零处理
	USARTxHandlerType->USARTxTxHandlerType.txCrcVal = 0;
	//---数据填充
	for (i = 0; i < length; i++)
	{
		USARTxHandlerType->USARTxTxHandlerType.txCrcVal += USARTxHandlerType->USARTxTxHandlerType.pTxBuffer[i];
		USARTxHandlerType->USARTxTxHandlerType.txIndex++;
	}
	//---计算得到的校验和
	USARTxHandlerType->USARTxTxHandlerType.txCrcVal = (~USARTxHandlerType->USARTxTxHandlerType.txCrcVal + 1);
	//---发送校验和
	USARTxHandlerType->USARTxTxHandlerType.txCrcFlag = 0;
	//---允许发送
	USARTxHandlerType->USARTxTxHandlerType.txStep = 0x00;
	//---启动数据寄存器空中断
	USARTxHandlerType->USART_MSG_Task(USARTxHandlerType, ENABLE, USART_MSG_IT_TXE);
	//---允许接收
	USARTxHandlerType->USART_MSG_Task(USARTxHandlerType, 0, USART_MSG_RX_HandlerInit);
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_RxInit(USART_HandlerType *USARTxHandlerType)
{
	USARTxHandlerType->USARTxRxHandlerType.rxStep = 0;
	USARTxHandlerType->USARTxRxHandlerType.rxCrcVal = 0;
	USARTxHandlerType->USARTxRxHandlerType.rxIndex = 0;
	USARTxHandlerType->USARTxRxHandlerType.rxCount = 0;
	//---清空接收缓存区的数据
	memset(USARTxHandlerType->USARTxRxHandlerType.pRxBuffer, 0x00, USARTxHandlerType->USARTxRxHandlerType.rxBufferDataSize);
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_Msg(USART_HandlerType *USARTxHandlerType, UINT32_T val, UINT8_T msg)
{
	UINT8_T _return = 0;
	switch ( msg )
	{
		case USART_MSG_Init			:
			_return=USART_HandlerType_Init(USARTxHandlerType);
			break;
		case USART_MSG_Deinit		:
			_return=USARTLib_HandlerType_DeInit(USARTxHandlerType);
			break;
		case USART_MSG_IT_TXE		:
			_return=USARTLib_HandlerType_IT_TXE(USARTxHandlerType, val);
			break;
		case USART_MSG_IT_TC		:
			_return=USARTLib_HandlerType_IT_TC(USARTxHandlerType, val);
			break;
		case USART_MSG_IT_RXNE		:
			_return=USARTLib_HandlerType_IT_RXNE(USARTxHandlerType, val);
			break;
		case USART_MSG_IT_IDLE		:
			_return=USARTLib_HandlerType_IT_IDLE(USARTxHandlerType, val);
			break;
		case USART_MSG_GPIO_Init	:
			_return=USARTLib_HandlerType_GPIO_SetPinMode(USARTxHandlerType, val);
			break;
		case USART_MSG_Transmite	:
			_return=USARTLib_HandlerType_TransmitData8(USARTxHandlerType, val);
			break;
		case USART_MSG_Receive		:
			_return=USARTLib_HandlerType_ReceiveData8(USARTxHandlerType);
			break;
		case USART_MSG_BandRate		:
			_return=USARTLib_HandlerType_SetBandRate(USARTxHandlerType, val);
			break;
		case USART_MSG_DataWidth	:
			_return=USARTLib_HandlerType_SetDataWidth(USARTxHandlerType, val);
			break;
		case USART_MSG_SetParity	:
			_return=USARTLib_HandlerType_SetParity(USARTxHandlerType, val);
			break;
		case USART_MSG_SetStopBits	:
			_return=USARTLib_HandlerType_SetStopBits(USARTxHandlerType, val);
			break;
		case USART_MSG_RXNE_Handler	:
			_return=USARTLib_HandlerType_RXNEHandler(USARTxHandlerType,val);
			break;
		case USART_MSG_TXE_Handler	:
			_return=USARTLib_HandlerType_TXEHandler(USARTxHandlerType);
			break;
		case USART_MSG_TC_Handler	:
			_return=USARTLib_HandlerType_TCHandler(USARTxHandlerType);
			break;
		case USART_MSG_IDLE_Handler	:
			break;
		case USART_MSG_TXE_Byte_Transmite :
			_return = USARTLib_HandlerType_TXESendByte(USARTxHandlerType, val);
			break;
		case USART_MSG_TXE_ByteCrc_Transmite:
			_return = USARTLib_HandlerType_TXESendByteCrc(USARTxHandlerType, val);
			break;
		case USART_MSG_TXE_Data_Transmite :
			_return = USARTLib_HandlerType_TXESendData(USARTxHandlerType, val);
			break;
		case USART_MSG_TXE_DataCrc_Transmite :
			_return = USARTLib_HandlerType_TXESendDataCrc(USARTxHandlerType, val);
			break;
		case USART_MSG_RX_HandlerInit:
			_return = USARTLib_HandlerType_RxInit(USARTxHandlerType);
			break;
		default:
			break;
	}
	return _return;
}
