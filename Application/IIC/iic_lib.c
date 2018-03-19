
#include "iic_lib.h"

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T I2CLib_HandlerType_Master_SoftInit( I2C_HandlerType *I2CHandlerType )
{
	 I2C_HandlerType_Master_SoftInit( I2CHandlerType );
	 I2CHandlerType->I2C_MSG_Task = I2CLib_HandlerType_Msg;
	 return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T I2CLib_HandlerType_Master_SoftDeInit( I2C_HandlerType *I2CHandlerType )
{
	return I2C_HandlerType_Master_SoftDeInit( I2CHandlerType );
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T I2CLib_HandlerType_Master_SoftSendData( I2C_HandlerType *I2CHandlerType, UINT8_T length )
{
	return I2C_HandlerType_Master_SoftSendData( I2CHandlerType, length );
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T I2CLib_HandlerType_Master_SoftReadData( I2C_HandlerType *I2CHandlerType, UINT8_T length )
{
	return I2C_HandlerType_Master_SoftReadData( I2CHandlerType, length );
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T I2CLib_HandlerType_Msg( I2C_HandlerType *I2CHandlerType, UINT8_T val, UINT8_T msg )
{
	UINT8_T _return = 0;
	switch( msg )
	{
		case I2C_HandlerType_MSG_SoftInit:
			_return = I2CLib_HandlerType_Master_SoftInit( I2CHandlerType );
			break;
		case I2C_HandlerType_MSG_SoftDeInit:
			_return = I2CLib_HandlerType_Master_SoftDeInit( I2CHandlerType );
			break;
		case I2C_HandlerType_MSG_SofSendData:
			_return = I2CLib_HandlerType_Master_SoftSendData( I2CHandlerType, val );
			break;
		case I2C_HandlerType_MSG_SofReadData:
			_return = I2CLib_HandlerType_Master_SoftReadData( I2CHandlerType, val );
			break;
		default:
			break;
	}
	return _return;
}