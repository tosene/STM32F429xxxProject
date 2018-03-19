#include "iic_task.h"

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T I2CTask_HandlerType_Master_Init( I2C_HandlerType *I2CHandlerType ,UINT8_T isHwMode)
{
	UINT8_T _return = 0;
	//if (isHwMode==0)
	//{
	//	_return = I2CLib_HandlerType_Master_SoftInit( I2CHandlerType );
	//}
	I2CLib_HandlerType_Master_SoftInit( I2CHandlerType );
	return _return;
}
