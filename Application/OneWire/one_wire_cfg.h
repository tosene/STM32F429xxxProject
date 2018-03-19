#ifndef __ONE_WIRE_CFG_H
#define __ONE_WIRE_CFG_H

#ifdef __cplusplus
extern "C" {
#endif 

	///------------使用包含的头文件
	#include "complier_lib.h"
	#include "delay_lib.h"

	#define OneWire_MSG_Init					0
	#define OneWire_MSG_DeInit					1
	#define OneWire_MSG_WriteByte				2
	#define OneWire_MSG_ReadByte				3

	//---端口的状态
	#define OneWire_OUT_0(name,index)			LL_GPIO_ResetOutputPin(	name,index )
	#define OneWire_OUT_1(name,index)			LL_GPIO_SetOutputPin(	name,index )
	#define OneWire_STATE(name,index)			LL_GPIO_IsInputPinSet(	name,index )
		
	///////////////////////////////////////////////////////////////////////////////
	//---定义结构体
	typedef struct _OneWire_HandlerType		OneWire_HandlerType;
	//---定义指针结构体
	typedef struct _OneWire_HandlerType		*pOneWire_HandlerType;
	//---定义消息处理函数
	typedef UINT8_T(*OneWire_MSG_HandlerType)(OneWire_HandlerType *OneWireHandlerType, UINT8_T val, UINT8_T msg);
	//---消息结构体
	struct _OneWire_HandlerType
	{
		UINT32_T					OneWirePinMask;					//---端口序号
		GPIO_TypeDef				*OneWireGPIOx;					//---端口号
		UINT8_T						*OneWireDataPoint;				//---指向数据的指针
		OneWire_MSG_HandlerType		OneWire_MSG_Task;				//---消息处理函数
	};
	//===函数定义
	UINT8_T OneWire_HandlerType_Init(OneWire_HandlerType *OneWireHandlerType);
	UINT8_T OneWire_HandlerType_DeInit(OneWire_HandlerType *OneWireHandlerType);
	UINT8_T OneWire_HandlerType_Start(OneWire_HandlerType *OneWireHandlerType);
	UINT8_T OneWire_HandlerType_WriteBit(OneWire_HandlerType *OneWireHandlerType, UINT8_T bitVal);
	UINT8_T OneWire_HandlerType_ReadBit(OneWire_HandlerType *OneWireHandlerType);
	UINT8_T OneWire_HandlerType_WriteByte(OneWire_HandlerType *OneWireHandlerType, UINT8_T val);
	UINT8_T OneWire_HandlerType_ReadByte(OneWire_HandlerType *OneWireHandlerType);

	///////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

#endif /* __ONE_WIRE_CFG_H */