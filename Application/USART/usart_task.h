#ifndef __USART_TASK_H
#define __USART_TASK_H

#ifdef __cplusplus
extern "C" {
#endif 

///------------使用包含的头文件
#include "usart_lib.h"
///////////////////////////////////////////////////////////////////////////////
	//===函数定义
	UINT8_T USARTTask_HandlerType_Init(USART_HandlerType *USARTxHandlerType, UINT16_T bufferSize);
	UINT8_T USARTTask_HandlerType_FuncType(USART_HandlerType *USARTxHandlerType, FuncType pFunctype);
///////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

#endif /* __USART_TASK_H */
