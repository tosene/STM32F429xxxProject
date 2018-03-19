#include "one_wire_lib.h"

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T OneWireLib_HandlerType_Init(OneWire_HandlerType *OneWireHandlerType)
{
	OneWire_HandlerType_Init(OneWireHandlerType);
	OneWireHandlerType->OneWire_MSG_Task = OneWireLib_HandlerType_Msg;
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T OneWireLib_HandlerType_DeInit(OneWire_HandlerType *OneWireHandlerType)
{
	return  OneWire_HandlerType_DeInit(OneWireHandlerType);
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T OneWireLib_HandlerType_Start(OneWire_HandlerType *OneWireHandlerType)
{
	return OneWire_HandlerType_Start(OneWireHandlerType);
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T OneWireLib_HandlerType_WriteByte(OneWire_HandlerType *OneWireHandlerType, UINT8_T val)
{
	return OneWireLib_HandlerType_WriteByte(OneWireHandlerType, val);
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T OneWireLib_HandlerType_ReadByte(OneWire_HandlerType *OneWireHandlerType)
{
	return OneWire_HandlerType_ReadByte(OneWireHandlerType);
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T OneWireLib_HandlerType_Msg(OneWire_HandlerType *OneWireHandlerType, UINT8_T val, UINT8_T msg)
{
	UINT8_T _return = 0;
	switch (msg)
	{
		case OneWire_MSG_Init:
			_return=OneWireLib_HandlerType_Init( OneWireHandlerType );
			break;
		case OneWire_MSG_DeInit:
			_return=OneWireLib_HandlerType_DeInit( OneWireHandlerType );
			break;
		case OneWire_MSG_WriteByte:
			_return = OneWireLib_HandlerType_WriteByte( OneWireHandlerType, val );
			break;
		case OneWire_MSG_ReadByte:
			_return = OneWireLib_HandlerType_ReadByte( OneWireHandlerType );
			break;
		default:
			break;
	}
	return _return;
}