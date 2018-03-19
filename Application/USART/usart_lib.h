#ifndef __USART_LIB_H
#define __USART_LIB_H

#ifdef __cplusplus
extern "C" {
#endif 

///------------使用包含的头文件
#include "usart_cfg.h"
///////////////////////////////////////////////////////////////////////////////
	//===函数定义
	UINT8_T USARTLib_HandlerType_IT_TC(USART_HandlerType *USARTxHandlerType, UINT8_T msg);
	UINT8_T USARTLib_HandlerType_IT_TXE(USART_HandlerType *USARTxHandlerType, UINT8_T msg);
	UINT8_T USARTLib_HandlerType_IT_RXNE(USART_HandlerType *USARTxHandlerType, UINT8_T msg);
	UINT8_T USARTLib_HandlerType_IT_IDLE(USART_HandlerType *USARTxHandlerType, UINT8_T msg);
	UINT8_T USARTLib_HandlerType_GPIO_SetPinMode(USART_HandlerType *USARTxHandlerType, UINT32_T msg);
	UINT8_T USARTLib_HandlerType_TransmitData8(USART_HandlerType *USARTxHandlerType, UINT8_T msg);
	UINT8_T USARTLib_HandlerType_TransmitData9(USART_HandlerType *USARTxHandlerType, UINT16_T msg);
	UINT8_T USARTLib_HandlerType_ReceiveData8(USART_HandlerType *USARTxHandlerType);
	UINT16_T USARTLib_HandlerType_ReceiveData9(USART_HandlerType *USARTxHandlerType);
	UINT8_T USARTLib_HandlerType_SetBandRate(USART_HandlerType *USARTxHandlerType, UINT32_T bandRate);
	UINT8_T USARTLib_HandlerType_SetDataWidth(USART_HandlerType *USARTxHandlerType, UINT32_T dataWidth);
	UINT8_T USARTLib_HandlerType_SetParity(USART_HandlerType *USARTxHandlerType, UINT32_T Parity);
	UINT8_T USARTLib_HandlerType_SetStopBits(USART_HandlerType *USARTxHandlerType, UINT32_T StopBits);
	UINT8_T USARTLib_HandlerType_Init(USART_HandlerType *USARTxHandlerType, UINT16_T bufferSize);
	UINT8_T USARTLib_HandlerType_DeInit(USART_HandlerType *USARTxHandlerType);
	UINT8_T USARTLib_HandlerType_Msg(USART_HandlerType *USARTxHandlerType, UINT32_T val, UINT8_T msg);
	UINT8_T USARTLib_HandlerType_RXNEHandler(USART_HandlerType *USARTxHandlerType, UINT8_T val);
	UINT8_T USARTLib_HandlerType_TXEHandler(USART_HandlerType *USARTxHandlerType);
	UINT8_T USARTLib_HandlerType_TCHandler(USART_HandlerType *USARTxHandlerType);
	UINT8_T USARTLib_HandlerType_TXESendByte(USART_HandlerType *USARTxHandlerType, UINT8_T val);
	UINT8_T USARTLib_HandlerType_TXESendByteCrc(USART_HandlerType *USARTxHandlerType, UINT8_T val);
	UINT8_T USARTLib_HandlerType_TXESendData(USART_HandlerType *USARTxHandlerType, UINT8_T length);
	UINT8_T USARTLib_HandlerType_TXESendDataCrc(USART_HandlerType *USARTxHandlerType, UINT8_T length);
	UINT8_T USARTLib_HandlerType_RxInit(USART_HandlerType *USARTxHandlerType);
	
	///////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

#endif /* __USART_LIB_H */