#include "usart_task.h"

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTTask_HandlerType_Init(USART_HandlerType *USARTxHandlerType, UINT16_T bufferSize)
{
	return USARTLib_HandlerType_Init(USARTxHandlerType,bufferSize);
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T USARTTask_HandlerType_FuncType(USART_HandlerType *USARTxHandlerType, FuncType pFunctype)
{
	UINT8_T _return = 0;
	if ( (USARTxHandlerType->USARTxRxHandlerType.rxStep==3)|| (USARTxHandlerType->USARTxRxHandlerType.rxStep == 4))
	{
		if (pFunctype!=NULL)
		{
			pFunctype(USARTxHandlerType->USARTxRxHandlerType.pRxBuffer, USARTxHandlerType->USARTxTxHandlerType.pTxBuffer);
		}
		else
		{
			memcpy(USARTxHandlerType->USARTxTxHandlerType.pTxBuffer, USARTxHandlerType->USARTxRxHandlerType.pRxBuffer, USARTxHandlerType->USARTxRxHandlerType.rxBufferDataSize);
		}
		USARTxHandlerType->USARTxTxHandlerType.pTxBuffer[0] = USARTxHandlerType->USARTxTxHeader;
		_return = USARTxHandlerType->USART_MSG_Task(USARTxHandlerType, (USARTxHandlerType->USARTxRxHandlerType.rxCount+2), USART_MSG_TXE_DataCrc_Transmite);;
	}
	else if ((USARTxHandlerType->USARTxRxHandlerType.rxStep == 5))
	{
		USART_HandlerType_Printf(USARTxHandlerType,"���ݽ��մ���\r\n");
		_return = 1;
	}

	return _return;
}