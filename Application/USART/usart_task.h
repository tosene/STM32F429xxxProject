#ifndef __USART_TASK_H
#define __USART_TASK_H

#ifdef __cplusplus
extern "C" {
#endif 

///------------ʹ�ð�����ͷ�ļ�
#include "usart_lib.h"
///////////////////////////////////////////////////////////////////////////////
	//===��������
	UINT8_T USARTTask_HandlerType_Init(USART_HandlerType *USARTxHandlerType, UINT16_T bufferSize);
	UINT8_T USARTTask_HandlerType_FuncType(USART_HandlerType *USARTxHandlerType, FuncType pFunctype);
///////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

#endif /* __USART_TASK_H */
