#include "usart_lib.h"

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_IT_TC(USART_HandlerType *USARTxHandlerType, UINT8_T msg)
{
	return USART_HandlerType_IT_TC(USARTxHandlerType, msg);
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_IT_TXE(USART_HandlerType *USARTxHandlerType, UINT8_T msg)
{
	return USART_HandlerType_IT_TXE(USARTxHandlerType, msg);
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_IT_RXNE(USART_HandlerType *USARTxHandlerType, UINT8_T msg)
{
	return USART_HandlerType_IT_RXNE(USARTxHandlerType, msg);
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_IT_IDLE(USART_HandlerType *USARTxHandlerType, UINT8_T msg)
{
	return USART_HandlerType_IT_IDLE(USARTxHandlerType, msg);
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_GPIO_SetPinMode(USART_HandlerType *USARTxHandlerType, UINT32_T msg)
{
	return USART_HandlerType_GPIO_SetPinMode(USARTxHandlerType, msg);
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_TransmitData8(USART_HandlerType *USARTxHandlerType, UINT8_T msg)
{
	return USART_HandlerType_TransmitData8(USARTxHandlerType, msg);
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_TransmitData9(USART_HandlerType *USARTxHandlerType, UINT16_T msg)
{
	return USART_HandlerType_TransmitData9(USARTxHandlerType, msg);
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_ReceiveData8(USART_HandlerType *USARTxHandlerType)
{
	return USART_HandlerType_ReceiveData8(USARTxHandlerType);
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT16_T USARTLib_HandlerType_ReceiveData9(USART_HandlerType *USARTxHandlerType)
{
	return USART_HandlerType_ReceiveData9(USARTxHandlerType);
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_SetBandRate(USART_HandlerType *USARTxHandlerType, UINT32_T bandRate)
{
	return USART_HandlerType_SetBandRate(USARTxHandlerType,bandRate);
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_SetDataWidth(USART_HandlerType *USARTxHandlerType, UINT32_T dataWidth)
{
	return USART_HandlerType_SetDataWidth( USARTxHandlerType, dataWidth);
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_SetParity(USART_HandlerType *USARTxHandlerType, UINT32_T Parity)
{
	return USART_HandlerType_SetParity( USARTxHandlerType, Parity);
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_SetStopBits(USART_HandlerType *USARTxHandlerType, UINT32_T StopBits)
{
	return USART_HandlerType_SetStopBits( USARTxHandlerType, StopBits);
}
///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_Init(USART_HandlerType *USARTxHandlerType, UINT16_T bufferSize)
{
	USART_HandlerType_StructInit(USARTxHandlerType);
	//---��ʼ���������ݽṹ��
	USARTxHandlerType->USARTxRxHandlerType.rxBufferDataSize = bufferSize;
	//---������ջ�����
	USARTxHandlerType->USARTxRxHandlerType.pRxBuffer = (UINT8_T *)malloc(bufferSize + 1);
	//---���㷢�ͻ�����
	memset(USARTxHandlerType->USARTxRxHandlerType.pRxBuffer, 0, ( bufferSize + 1 ));
	//---��ʼ���������ݽṹ��
	USARTxHandlerType->USARTxTxHandlerType.txBufferDataSize = bufferSize;
	//---���뷢�ͻ�����
	USARTxHandlerType->USARTxTxHandlerType.pTxBuffer =(UINT8_T *)malloc(bufferSize + 1);
	//---������ջ�����
	memset(USARTxHandlerType->USARTxTxHandlerType.pTxBuffer, 0, ( bufferSize + 1 ));
	//---ָ�뺯��ָ����Ϣ�崦��������
	USARTxHandlerType->USART_MSG_Task=USARTLib_HandlerType_Msg;
	//---Ӳ�����ڵĳ�ʼ��
	USARTxHandlerType->USART_MSG_Task(USARTxHandlerType, bufferSize, USART_MSG_Init);
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_DeInit(USART_HandlerType *USARTxHandlerType)
{
	USART_HandlerType_DeInit(USARTxHandlerType);
	USART_HandlerType_StructInit(USARTxHandlerType);
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_RXNEHandler(USART_HandlerType *USARTxHandlerType, UINT8_T val)
{
	//---��������������
	UINT8_T tempVal = val;
	//---�����ж�
	switch (USARTxHandlerType->USARTxRxHandlerType.rxStep)
	{
		case 0:										//---��ȡ���������Ƿ����
			//---�ж��Ƿ��������ݵĽ���
			if (USARTxHandlerType->USARTxRxHandlerType.rxIndex == 0)
			{
				//---�жϱ�ͷ�Ƿ����
				if (tempVal == USARTxHandlerType->USARTxRxHeader)
				{
					USARTxHandlerType->USARTxRxHandlerType.pRxBuffer[0] = tempVal;
					USARTxHandlerType->USARTxRxHandlerType.rxCrcVal = tempVal;
					USARTxHandlerType->USARTxRxHandlerType.rxStep = 1;
				}
			}
			break;
		case 1:										//---��ȡ�������ݳ���
			//---�ж����ݽ������Ϸ�
			if ((tempVal > 0) && (tempVal < (USARTxHandlerType->USARTxRxHandlerType.rxBufferDataSize)))
			{
				USARTxHandlerType->USARTxRxHandlerType.pRxBuffer[1] = tempVal;
				USARTxHandlerType->USARTxRxHandlerType.rxCrcVal += tempVal;
				USARTxHandlerType->USARTxRxHandlerType.rxCount = tempVal;
				USARTxHandlerType->USARTxRxHandlerType.rxStep = 2;
			}
			else
			{
				//---���ݳ��Ȳ��Ϸ������ݽ���������λ
				USARTxHandlerType->USARTxRxHandlerType.rxStep = 0;
			}
			USARTxHandlerType->USARTxRxHandlerType.rxIndex = 0;
			break;
		case 2:										//---��ȡ��������
			USARTxHandlerType->USARTxRxHandlerType.pRxBuffer[USARTxHandlerType->USARTxRxHandlerType.rxIndex + 2] = tempVal;
			USARTxHandlerType->USARTxRxHandlerType.rxIndex++;
			//---�ж������Ƿ�������
			if ((USARTxHandlerType->USARTxRxHandlerType.rxIndex) >= (USARTxHandlerType->USARTxRxHandlerType.rxCount))
			{
				//---��ȡУ���
				USARTxHandlerType->USARTxRxHandlerType.rxStep = 3;
				//----�����ձ�ͷת���ɷ��ͱ�ͷ---������ﲻ��λ�����ڷ��͵�ʱ����λ
				//UsartHandlerTypeDef->usartRxdHandlerTypedef.pRxBuffer[0] = USARTxHandlerType->USARTxTxHeader;
			}
			else
			{
				//---����У���
				USARTxHandlerType->USARTxRxHandlerType.rxCrcVal += tempVal;
			}
			break;
		case 3:										//---��ȡУ���
			if (USARTxHandlerType->USARTxRxHandlerType.rxCrcFlag != 0)
			{
				//---��ȡУ���
				USARTxHandlerType->USARTxRxHandlerType.rxCrcVal = (~USARTxHandlerType->USARTxRxHandlerType.rxCrcVal) + 1;
				if (USARTxHandlerType->USARTxRxHandlerType.rxCrcVal != tempVal)
				{
					//---���ݽ��պͷ��͵�У��Ͳ���
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
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_TXEHandler(USART_HandlerType *USARTxHandlerType)
{
	//===�ж��Ƿ������ݵķ���
	if (USARTxHandlerType->USARTxTxHandlerType.txCount != 0)
	{
		switch (USARTxHandlerType->USARTxTxHandlerType.txStep)
		{
			case 0:											//---���ݷ���
				//---�жϷ��ͻ�����������
				if (USARTxHandlerType->USARTxTxHandlerType.txIndex != USARTxHandlerType->USARTxTxHandlerType.txNum)
				{
					//---����8Bit������
					USARTxHandlerType->USART_MSG_Task(USARTxHandlerType, USARTxHandlerType->USARTxTxHandlerType.pTxBuffer[USARTxHandlerType->USARTxTxHandlerType.txNum], USART_MSG_Transmite);
					//---���ݻ���������
					USARTxHandlerType->USARTxTxHandlerType.txNum++;
					//---У�黺�����Ƿ����
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
			case 1:											//---У��͵ķ���
				USARTxHandlerType->USARTxTxHandlerType.txStep = 2;
				//---�ж����Ƿ���У�����Ϣ
				if (USARTxHandlerType->USARTxTxHandlerType.txCrcFlag != 0)
				{
					USARTxHandlerType->USARTxTxHandlerType.txCrcVal = 0;
				}
				else
				{
					//---�������,�������ݼĴ������жϲ�ʹ��
					USARTxHandlerType->USART_MSG_Task(USARTxHandlerType, DISABLE, USART_MSG_IT_TXE);
					//---ʹ�ܷ�������ж�---�������ʹ�����ݼĴ������жϣ��ڲ�������ʱ���޸ķ��Ͷ˿�Ϊ����״̬�������ᵼ��У��͵ķ���ʧ�ܣ��������ʹ�÷�������ж�
					USARTxHandlerType->USART_MSG_Task(USARTxHandlerType, ENABLE, USART_MSG_IT_TC);
					//---����У�������
					USARTxHandlerType->USART_MSG_Task(USARTxHandlerType, USARTxHandlerType->USARTxTxHandlerType.txCrcVal, USART_MSG_Transmite);
					/*USARTxHandlerType->USARTxTxHandlerType.txCrcVal = 0;
					USARTxHandlerType->USARTxTxHandlerType.txCrcFlag = 0;*/
					break;
				}
			case 2:											//---���ݷ������
				//---�������,�������ݼĴ������жϲ�ʹ��
				USARTxHandlerType->USART_MSG_Task(USARTxHandlerType, DISABLE, USART_MSG_IT_TXE);
				//���ݷ������,���㷢�����ݳ���
				USARTxHandlerType->USARTxTxHandlerType.txCount = 0;
				//---���η������
				USARTxHandlerType->USARTxTxHandlerType.txStep = 3;
				//---��������Ź��㴦��
				USARTxHandlerType->USARTxTxHandlerType.txIndex = 0;
				USARTxHandlerType->USARTxTxHandlerType.txNum = 0;
				//---���÷��Ͷ˿�Ϊ����ģʽ
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
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_TCHandler(USART_HandlerType *USARTxHandlerType)
{
	//---��ʹ�����ݷ�������ж�
	USARTxHandlerType->USART_MSG_Task(USARTxHandlerType, DISABLE, USART_MSG_IT_TC);
	//���ݷ������,���㷢�����ݳ���
	USARTxHandlerType->USARTxTxHandlerType.txCount = 0;
	//---���η������
	USARTxHandlerType->USARTxTxHandlerType.txStep = 3;
	//---��������Ź��㴦��
	USARTxHandlerType->USARTxTxHandlerType.txIndex = 0;
	USARTxHandlerType->USARTxTxHandlerType.txNum = 0;
	//---���÷��Ͷ˿�Ϊ����ģʽ
	USARTxHandlerType->USART_MSG_Task(USARTxHandlerType, USART_TxPin_SET_INPUT, USART_MSG_GPIO_Init);
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_TXESendByte(USART_HandlerType *USARTxHandlerType, UINT8_T val)
{
	//---����TX�˿�Ϊ�����������
	USARTxHandlerType->USART_MSG_Task(USARTxHandlerType, USART_TxPin_SET_OUTPUT, USART_MSG_GPIO_Init);
	//---������ݵ�������
	USARTxHandlerType->USARTxTxHandlerType.pTxBuffer[USARTxHandlerType->USARTxTxHandlerType.txIndex] = val;
	USARTxHandlerType->USARTxTxHandlerType.txIndex++;
	//---�жϻ�����Ƿ����
	if (USARTxHandlerType->USARTxTxHandlerType.txIndex >= USARTxHandlerType->USARTxTxHandlerType.txBufferDataSize)
	{
		USARTxHandlerType->USARTxTxHandlerType.txIndex = 0x00;
		USARTxHandlerType->USARTxTxHandlerType.txNum = 0x00;
	}
	//---������У���
	USARTxHandlerType->USARTxTxHandlerType.txCrcFlag = 1;
	//---������
	USARTxHandlerType->USARTxTxHandlerType.txStep = 0x00;
	//---�������ݼĴ������ж�
	USARTxHandlerType->USART_MSG_Task(USARTxHandlerType, ENABLE, USART_MSG_IT_TXE);
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_TXESendByteCrc(USART_HandlerType *USARTxHandlerType, UINT8_T val)
{
	//---����TX�˿�Ϊ�����������
	USARTxHandlerType->USART_MSG_Task(USARTxHandlerType, USART_TxPin_SET_OUTPUT, USART_MSG_GPIO_Init);
	//---������ݵ�������
	USARTxHandlerType->USARTxTxHandlerType.pTxBuffer[USARTxHandlerType->USARTxTxHandlerType.txIndex] = val;
	USARTxHandlerType->USARTxTxHandlerType.txIndex++;
	//---CRCУ��͵ļ���
	USARTxHandlerType->USARTxTxHandlerType.txCrcVal += val;
	//---�жϻ�����Ƿ����
	if (USARTxHandlerType->USARTxTxHandlerType.txIndex >= USARTxHandlerType->USARTxTxHandlerType.txBufferDataSize)
	{
		USARTxHandlerType->USARTxTxHandlerType.txIndex = 0x00;
		USARTxHandlerType->USARTxTxHandlerType.txNum = 0x00;
	}
	//---����õ���У���
	USARTxHandlerType->USARTxTxHandlerType.txCrcVal = (~(USARTxHandlerType->USARTxTxHandlerType.txCrcVal)) + 1;
	//---����У���
	USARTxHandlerType->USARTxTxHandlerType.txCrcFlag = 1;
	//---������
	USARTxHandlerType->USARTxTxHandlerType.txStep = 0x00;
	//---�������ݼĴ������ж�
	USARTxHandlerType->USART_MSG_Task(USARTxHandlerType, ENABLE, USART_MSG_IT_TXE);
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_TXESendData(USART_HandlerType *USARTxHandlerType, UINT8_T length)
{
	//---�ж�ʫ�䳤���Ƿ�����õ��������ݵĳ���
	if (length > USARTxHandlerType->USARTxTxHandlerType.txBufferDataSize)
	{
		length = USARTxHandlerType->USARTxTxHandlerType.txBufferDataSize;
	}
	else
	{
		USARTxHandlerType->USARTxTxHandlerType.txCount = length;
	}
	//---�ȴ��ϴε����ݷ������---��������
	while ((USARTxHandlerType->USARTxTxHandlerType.txStep != 0x03))
	{
		//---�ж������Ƿ������˷��ͣ���ȡ������ɵı�־λ
		if (USARTxHandlerType->USARTxTxHandlerType.txStep == 0)
		{
			break;
		}
	}
	//---����TX�˿�Ϊ�����������
	USARTxHandlerType->USART_MSG_Task(USARTxHandlerType, USART_TxPin_SET_OUTPUT, USART_MSG_GPIO_Init);
	//---�жϻ�����Ƿ����
	if (USARTxHandlerType->USARTxTxHandlerType.txIndex > USARTxHandlerType->USARTxTxHandlerType.txBufferDataSize)
	{
		USARTxHandlerType->USARTxTxHandlerType.txIndex = 0x00;
		USARTxHandlerType->USARTxTxHandlerType.txNum = 0x00;
	}
	//---CRC��ֵ���㴦��
	USARTxHandlerType->USARTxTxHandlerType.txCrcVal = 0;
	//---������У���
	USARTxHandlerType->USARTxTxHandlerType.txCrcFlag = 1;
	//---������
	USARTxHandlerType->USARTxTxHandlerType.txStep = 0x00;
	//---�������ݼĴ������ж�
	USARTxHandlerType->USART_MSG_Task(USARTxHandlerType, ENABLE, USART_MSG_IT_TXE);
	//---�������
	USARTxHandlerType->USART_MSG_Task(USARTxHandlerType, 0, USART_MSG_RX_HandlerInit);
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_TXESendDataCrc(USART_HandlerType *USARTxHandlerType, UINT8_T length)
{
	UINT8_T i = 0;
	//---�ж�ʫ�䳤���Ƿ�����õ��������ݵĳ���
	if (length > USARTxHandlerType->USARTxTxHandlerType.txBufferDataSize)
	{
		length = USARTxHandlerType->USARTxTxHandlerType.txBufferDataSize;
	}
	else
	{
		USARTxHandlerType->USARTxTxHandlerType.txCount = length;
	}
	//---�ȴ��ϴε����ݷ������---��������
	while ((USARTxHandlerType->USARTxTxHandlerType.txStep != 0x03))
	{
		//---�ж������Ƿ������˷��ͣ���ȡ������ɵı�־λ
		if (USARTxHandlerType->USARTxTxHandlerType.txStep == 0)
		{
			break;
		}
	}
	//---����TX�˿�Ϊ�����������
	USARTxHandlerType->USART_MSG_Task(USARTxHandlerType, USART_TxPin_SET_OUTPUT, USART_MSG_GPIO_Init);
	//---�жϻ�����Ƿ����
	if (USARTxHandlerType->USARTxTxHandlerType.txIndex > USARTxHandlerType->USARTxTxHandlerType.txBufferDataSize)
	{
		USARTxHandlerType->USARTxTxHandlerType.txIndex = 0x00;
		USARTxHandlerType->USARTxTxHandlerType.txNum = 0x00;
	}
	//---CRC��ֵ���㴦��
	USARTxHandlerType->USARTxTxHandlerType.txCrcVal = 0;
	//---�������
	for (i = 0; i < length; i++)
	{
		USARTxHandlerType->USARTxTxHandlerType.txCrcVal += USARTxHandlerType->USARTxTxHandlerType.pTxBuffer[i];
		USARTxHandlerType->USARTxTxHandlerType.txIndex++;
	}
	//---����õ���У���
	USARTxHandlerType->USARTxTxHandlerType.txCrcVal = (~USARTxHandlerType->USARTxTxHandlerType.txCrcVal + 1);
	//---����У���
	USARTxHandlerType->USARTxTxHandlerType.txCrcFlag = 0;
	//---������
	USARTxHandlerType->USARTxTxHandlerType.txStep = 0x00;
	//---�������ݼĴ������ж�
	USARTxHandlerType->USART_MSG_Task(USARTxHandlerType, ENABLE, USART_MSG_IT_TXE);
	//---�������
	USARTxHandlerType->USART_MSG_Task(USARTxHandlerType, 0, USART_MSG_RX_HandlerInit);
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTLib_HandlerType_RxInit(USART_HandlerType *USARTxHandlerType)
{
	USARTxHandlerType->USARTxRxHandlerType.rxStep = 0;
	USARTxHandlerType->USARTxRxHandlerType.rxCrcVal = 0;
	USARTxHandlerType->USARTxRxHandlerType.rxIndex = 0;
	USARTxHandlerType->USARTxRxHandlerType.rxCount = 0;
	//---��ս��ջ�����������
	memset(USARTxHandlerType->USARTxRxHandlerType.pRxBuffer, 0x00, USARTxHandlerType->USARTxRxHandlerType.rxBufferDataSize);
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
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
