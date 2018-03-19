#ifndef __ONE_WIRE_LIB_H
#define __ONE_WIRE_LIB_H

#ifdef __cplusplus
extern "C" {
#endif 

	///------------ʹ�ð�����ͷ�ļ�
	#include "one_wire_cfg.h"
	///////////////////////////////////////////////////////////////////////////////
	//===��������
	UINT8_T OneWireLib_HandlerType_Init(OneWire_HandlerType *OneWireHandlerType);
	UINT8_T OneWireLib_HandlerType_DeInit(OneWire_HandlerType *OneWireHandlerType);
	UINT8_T OneWireLib_HandlerType_Start(OneWire_HandlerType *OneWireHandlerType);
	UINT8_T OneWireLib_HandlerType_WriteByte(OneWire_HandlerType *OneWireHandlerType, UINT8_T val);
	UINT8_T OneWireLib_HandlerType_ReadByte(OneWire_HandlerType *OneWireHandlerType);
	UINT8_T OneWireLib_HandlerType_Msg( OneWire_HandlerType *OneWireHandlerType, UINT8_T val, UINT8_T msg );
	///////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

#endif /* __ONE_WIRE_LIB_H */