#ifndef __IIC_LIB_H
#define __IIC_LIB_H
#ifdef __cplusplus
extern "C" 
{
#endif
	//////////////////////////////////////////////////////////////////////////////////////
	#include "iic_cfg.h"
	//===º¯Êý¶¨Òå
	UINT8_T I2CLib_HandlerType_Master_SoftInit( I2C_HandlerType *I2CHandlerType );
	UINT8_T I2CLib_HandlerType_Master_SoftDeInit( I2C_HandlerType *I2CHandlerType );
	UINT8_T I2CLib_HandlerType_Master_SoftSendData( I2C_HandlerType *I2CHandlerType, UINT8_T length );
	UINT8_T I2CLib_HandlerType_Master_SoftReadData( I2C_HandlerType *I2CHandlerType, UINT8_T length );
	UINT8_T I2CLib_HandlerType_Msg( I2C_HandlerType *I2CHandlerType, UINT8_T val, UINT8_T msg );
	//////////////////////////////////////////////////////////////////////////////////////
#ifdef __cplusplus
}
#endif
#endif /*__iic_lib_H */
