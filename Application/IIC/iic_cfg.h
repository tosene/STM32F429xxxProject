#ifndef __IIC_CFG_H
#define __IIC_CFG_H
#ifdef __cplusplus
extern "C" 
{
#endif
	///////////////////////////////////////////////////////////////////////////////
	//////使用该函数，首先保证GPIO的时钟已经使能，函数内部已经将端口配置为开漏输出
	//////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////
	#include "complier_lib.h"
	#include "delay_lib.h"
	
	//---传输的消息
	#define I2C_HandlerType_MSG_SoftInit			0
	#define I2C_HandlerType_MSG_SoftDeInit			1
	#define I2C_HandlerType_MSG_SofSendData			2
	#define I2C_HandlerType_MSG_SofReadData			3

	//===消息体模式
	//---SDA端口
	#define I2C_SDA_OUT_0(name,index)	LL_GPIO_ResetOutputPin(	name,index )
	#define I2C_SDA_OUT_1(name,index)	LL_GPIO_SetOutputPin(	name,index )
	#define I2C_SDA_STATE(name,index)	LL_GPIO_IsInputPinSet(	name,index )
	//---SCL端口
	#define I2C_SCL_OUT_0(name,index)	LL_GPIO_ResetOutputPin(	name,index )
	#define I2C_SCL_OUT_1(name,index)	LL_GPIO_SetOutputPin(	name,index )
	#define I2C_SCL_STATE(name,index)	LL_GPIO_IsInputPinSet(	name,index )

	//---结构体定义
	typedef struct _I2C_HandlerType		I2C_HandlerType;
	typedef	struct _I2C_HandlerType		*pI2C_HandlerType;
	//---消息体定义
	typedef UINT8_T( *I2C_MSG_HandlerType )( I2C_HandlerType *I2CHandlerType, UINT8_T val, UINT8_T msg );
	//---消息体的I2C
	struct _I2C_HandlerType
	{
		I2C_TypeDef				*I2Cx;							//---使用的I2C接口
		GPIO_TypeDef			*I2CSCLGPIOx;					//---SCL端口
		GPIO_TypeDef			*I2CSDAGPIOx;					//---SDA端口
		UINT32_T				I2CSCLPin;						//---SCL引脚
		UINT32_T				I2CSDAPin;						//---SDA引脚
		UINT8_T					nowPluseWidth;					//---脉冲宽度，软件模拟使用
		UINT8_T					I2CDeviceAddr;					//---设备的地址
		UINT8_T					*I2CDataPoint;					//---读写数据的指针
		I2C_MSG_HandlerType		I2C_MSG_Task;					//---消息体处理函数
	};
	//===函数定义
	UINT8_T I2C_HandlerType_Master_SoftInit( I2C_HandlerType *I2CHandlerType );
	UINT8_T I2C_HandlerType_Master_SoftDeInit( I2C_HandlerType *I2CHandlerType );
	UINT8_T I2C_HandlerType_Master_SoftStart( I2C_HandlerType *I2CHandlerType );
	UINT8_T I2C_HandlerType_Master_SoftStop( I2C_HandlerType *I2CHandlerType );
	UINT8_T I2C_HandlerType_Master_SoftReadAck( I2C_HandlerType *I2CHandlerType );
	UINT8_T I2C_HandlerType_Master_SoftWaitAck( I2C_HandlerType *I2CHandlerType );
	UINT8_T I2C_HandlerType_Master_SoftNotAck( I2C_HandlerType *I2CHandlerType );
	UINT8_T I2C_HandlerType_Master_SoftAck( I2C_HandlerType *I2CHandlerType );
	UINT8_T I2C_HandlerType_Master_SoftSendAck( I2C_HandlerType *I2CHandlerType, UINT8_T isSendAck );
	UINT8_T I2C_HandlerType_Master_SoftSendByte( I2C_HandlerType *I2CHandlerType, UINT8_T val );
	UINT8_T I2C_HandlerType_Master_SoftReadByte( I2C_HandlerType *I2CHandlerType );
	UINT8_T I2C_HandlerType_Master_SoftSendData( I2C_HandlerType *I2CHandlerType, UINT8_T length );
	UINT8_T I2C_HandlerType_Master_SoftReadData( I2C_HandlerType *I2CHandlerType, UINT8_T length );
	//////////////////////////////////////////////////////////////////////////////////////
#ifdef __cplusplus
}
#endif
#endif /*__iic_cfg_H */
