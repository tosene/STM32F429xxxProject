#ifndef __ONE_WIRE_CFG_H
#define __ONE_WIRE_CFG_H

#ifdef __cplusplus
extern "C" {
#endif 

	///------------ʹ�ð�����ͷ�ļ�
	#include "complier_lib.h"
	#include "delay_lib.h"

	#define OneWire_MSG_Init					0
	#define OneWire_MSG_DeInit					1
	#define OneWire_MSG_WriteByte				2
	#define OneWire_MSG_ReadByte				3

	//---�˿ڵ�״̬
	#define OneWire_OUT_0(name,index)			LL_GPIO_ResetOutputPin(	name,index )
	#define OneWire_OUT_1(name,index)			LL_GPIO_SetOutputPin(	name,index )
	#define OneWire_STATE(name,index)			LL_GPIO_IsInputPinSet(	name,index )
		
	///////////////////////////////////////////////////////////////////////////////
	//---����ṹ��
	typedef struct _OneWire_HandlerType		OneWire_HandlerType;
	//---����ָ��ṹ��
	typedef struct _OneWire_HandlerType		*pOneWire_HandlerType;
	//---������Ϣ������
	typedef UINT8_T(*OneWire_MSG_HandlerType)(OneWire_HandlerType *OneWireHandlerType, UINT8_T val, UINT8_T msg);
	//---��Ϣ�ṹ��
	struct _OneWire_HandlerType
	{
		UINT32_T					OneWirePinMask;					//---�˿����
		GPIO_TypeDef				*OneWireGPIOx;					//---�˿ں�
		UINT8_T						*OneWireDataPoint;				//---ָ�����ݵ�ָ��
		OneWire_MSG_HandlerType		OneWire_MSG_Task;				//---��Ϣ������
	};
	//===��������
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