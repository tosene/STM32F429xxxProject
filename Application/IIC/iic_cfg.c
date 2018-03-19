#include "iic_cfg.h"

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T I2C_HandlerType_StructInit( I2C_HandlerType *I2CHandlerType )
{
	I2CHandlerType->I2CSCLGPIOx = NULL;
	I2CHandlerType->I2CSDAGPIOx=NULL;
	I2CHandlerType->I2CSCLPin=0;
	I2CHandlerType->I2CSDAPin=0;
	I2CHandlerType->nowPluseWidth=0;
	I2CHandlerType->I2CDeviceAddr=0;
	I2CHandlerType->I2CDataPoint=NULL;
	I2CHandlerType->I2C_MSG_Task=NULL;
    return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T I2C_HandlerType_Master_SoftInit( I2C_HandlerType *I2CHandlerType )
{
	LL_GPIO_InitTypeDef GPIO_InitStruct;
	//---GPIO的初始化
	GPIO_InitStruct.Pin			= I2CHandlerType->I2CSCLPin;				//---对应的GPIO的引脚
	GPIO_InitStruct.Mode		= LL_GPIO_MODE_OUTPUT;							//---配置状态为输出模式
	GPIO_InitStruct.Speed		= LL_GPIO_SPEED_FREQ_VERY_HIGH;					//---GPIO的速度
	GPIO_InitStruct.OutputType	= LL_GPIO_OUTPUT_OPENDRAIN;						//---输出模式---开漏输出
	GPIO_InitStruct.Pull		= LL_GPIO_PULL_UP;								//---上拉
	GPIO_InitStruct.Alternate	= LL_GPIO_AF_0;									//---默认配置为端口
	//---SCL的初始化
	LL_GPIO_Init( I2CHandlerType->I2CSCLGPIOx, &GPIO_InitStruct );
	//---SDA的初始化
	GPIO_InitStruct.Pin = I2CHandlerType->I2CSDAPin;
	LL_GPIO_Init( I2CHandlerType->I2CSDAGPIOx, &GPIO_InitStruct );
	//---SCL和SDA端口输出高电平
	I2C_SCL_OUT_1( I2CHandlerType->I2CSCLGPIOx, I2CHandlerType->I2CSCLPin );
	I2C_SDA_OUT_1( I2CHandlerType->I2CSDAGPIOx, I2CHandlerType->I2CSDAPin );
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T I2C_HandlerType_Master_SoftDeInit( I2C_HandlerType *I2CHandlerType )
{
	LL_GPIO_SetPinMode( I2CHandlerType->I2CSCLGPIOx, I2CHandlerType->I2CSCLPin, LL_GPIO_MODE_INPUT );
	LL_GPIO_SetPinMode( I2CHandlerType->I2CSDAGPIOx, I2CHandlerType->I2CSDAPin, LL_GPIO_MODE_INPUT );
	//---SCL和SDA端口输出高电平
	I2C_SCL_OUT_1( I2CHandlerType->I2CSCLGPIOx, I2CHandlerType->I2CSCLPin );
	I2C_SDA_OUT_1( I2CHandlerType->I2CSDAGPIOx, I2CHandlerType->I2CSDAPin );
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T I2C_HandlerType_Master_SoftStart( I2C_HandlerType *I2CHandlerType )
{
	//I2C_SCL_OUT_0( I2CHandlerType->I2CSCLGPIOx, I2CHandlerType->I2CSCLPinMask );
	//---发送起始条件的数据信号
	I2C_SDA_OUT_1( I2CHandlerType->I2CSDAGPIOx, I2CHandlerType->I2CSDAPin );
	I2C_SCL_OUT_1( I2CHandlerType->I2CSCLGPIOx, I2CHandlerType->I2CSCLPin );
	Delay_us( I2CHandlerType->nowPluseWidth );
	//---发送起始信号;
	I2C_SDA_OUT_0( I2CHandlerType->I2CSDAGPIOx, I2CHandlerType->I2CSDAPin );
	Delay_us( I2CHandlerType->nowPluseWidth );
	//---钳住I2C总线，准备发送或接收数据
	I2C_SCL_OUT_0( I2CHandlerType->I2CSCLGPIOx, I2CHandlerType->I2CSCLPin );
	Delay_us( I2CHandlerType->nowPluseWidth );
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T I2C_HandlerType_Master_SoftStop( I2C_HandlerType *I2CHandlerType )
{
	I2C_SCL_OUT_0( I2CHandlerType->I2CSCLGPIOx, I2CHandlerType->I2CSCLPin );
	//---发送起始条件的数据信号
	I2C_SDA_OUT_0( I2CHandlerType->I2CSDAGPIOx, I2CHandlerType->I2CSDAPin );
	Delay_us( I2CHandlerType->nowPluseWidth );
	I2C_SCL_OUT_1( I2CHandlerType->I2CSCLGPIOx, I2CHandlerType->I2CSCLPin );
	I2C_SDA_OUT_1( I2CHandlerType->I2CSDAGPIOx, I2CHandlerType->I2CSDAPin );
	Delay_us( I2CHandlerType->nowPluseWidth );
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T I2C_HandlerType_Master_SoftReadAck( I2C_HandlerType *I2CHandlerType )
{
	UINT8_T is_ACk = 0;
	UINT8_T i = 0;
	I2C_SCL_OUT_1( I2CHandlerType->I2CSCLGPIOx, I2CHandlerType->I2CSCLPin );
	Delay_us( I2CHandlerType->nowPluseWidth );
	//---在指定的时间内读取应答信号
	for( i = 255; i > 0; i-- )
	{
		//---读取SDA的状态
		if( I2C_SDA_STATE( I2CHandlerType->I2CSDAGPIOx, I2CHandlerType->I2CSDAPin ) )
		{
			is_ACk = 1;
			break;
		}
	}
	I2C_SCL_OUT_0( I2CHandlerType->I2CSCLGPIOx, I2CHandlerType->I2CSCLPin );
	Delay_us( I2CHandlerType->nowPluseWidth );
	return is_ACk;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 软件模拟IIC等待应答信号
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T I2C_HandlerType_Master_SoftWaitAck( I2C_HandlerType *I2CHandlerType )
{
	UINT8_T errorCount = 0;
	I2C_SCL_OUT_1( I2CHandlerType->I2CSCLGPIOx, I2CHandlerType->I2CSCLPin );
	Delay_nop( 2 );
	//---在指定的时间内读取应答信号
	while( I2C_SDA_STATE( I2CHandlerType->I2CSDAGPIOx, I2CHandlerType->I2CSDAPin ) )
	{
		if( errorCount > 250 )
		{
			I2C_HandlerType_Master_SoftStop( I2CHandlerType );
			return 1;
		}
		else
		{
			errorCount++;
		}
	}
	I2C_SCL_OUT_0( I2CHandlerType->I2CSCLGPIOx, I2CHandlerType->I2CSCLPin );
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T I2C_HandlerType_Master_SoftNotAck( I2C_HandlerType *I2CHandlerType )
{
	I2C_SCL_OUT_0( I2CHandlerType->I2CSCLGPIOx, I2CHandlerType->I2CSCLPin );
	I2C_SDA_OUT_1( I2CHandlerType->I2CSDAGPIOx, I2CHandlerType->I2CSDAPin );
	Delay_us( I2CHandlerType->nowPluseWidth );
	I2C_SCL_OUT_1( I2CHandlerType->I2CSCLGPIOx, I2CHandlerType->I2CSCLPin );
	Delay_us( I2CHandlerType->nowPluseWidth );
	I2C_SCL_OUT_0( I2CHandlerType->I2CSCLGPIOx, I2CHandlerType->I2CSCLPin );
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T I2C_HandlerType_Master_SoftAck( I2C_HandlerType *I2CHandlerType )
{
	I2C_SCL_OUT_0( I2CHandlerType->I2CSCLGPIOx, I2CHandlerType->I2CSCLPin );
	I2C_SDA_OUT_0( I2CHandlerType->I2CSDAGPIOx, I2CHandlerType->I2CSDAPin );
	Delay_us( I2CHandlerType->nowPluseWidth );
	I2C_SCL_OUT_1( I2CHandlerType->I2CSCLGPIOx, I2CHandlerType->I2CSCLPin );
	Delay_us( I2CHandlerType->nowPluseWidth );
	I2C_SCL_OUT_0( I2CHandlerType->I2CSCLGPIOx, I2CHandlerType->I2CSCLPin );
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T I2C_HandlerType_Master_SoftSendAck( I2C_HandlerType *I2CHandlerType, UINT8_T isSendAck )
{
	if (isSendAck!=0x00)
	{
		I2C_HandlerType_Master_SoftNotAck( I2CHandlerType );
	}
	else
	{
		I2C_HandlerType_Master_SoftAck( I2CHandlerType );
	}
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T I2C_HandlerType_Master_SoftSendByte( I2C_HandlerType *I2CHandlerType, UINT8_T val )
{
	UINT8_T i = 0;
	I2C_SCL_OUT_0( I2CHandlerType->I2CSCLGPIOx, I2CHandlerType->I2CSCLPin );
	for (i=0;i<8;i++)
	{
		if ((val&0x80)!=0x00)
		{
			I2C_SDA_OUT_1( I2CHandlerType->I2CSDAGPIOx, I2CHandlerType->I2CSDAPin );
		}
		else
		{
			I2C_SDA_OUT_0( I2CHandlerType->I2CSDAGPIOx, I2CHandlerType->I2CSDAPin );
		}
		val <<= 1;
		Delay_us( I2CHandlerType->nowPluseWidth );
		I2C_SCL_OUT_1( I2CHandlerType->I2CSCLGPIOx, I2CHandlerType->I2CSCLPin );
		Delay_us( I2CHandlerType->nowPluseWidth );
		I2C_SCL_OUT_0( I2CHandlerType->I2CSCLGPIOx, I2CHandlerType->I2CSCLPin );
	}
    return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T I2C_HandlerType_Master_SoftReadByte( I2C_HandlerType *I2CHandlerType )
{
	UINT8_T i = 0;
	UINT8_T _return = 0;
	for (i=0;i<8;i++)
	{
		I2C_SCL_OUT_0( I2CHandlerType->I2CSCLGPIOx, I2CHandlerType->I2CSCLPin );
		Delay_us( I2CHandlerType->nowPluseWidth );
		_return <<= 1;
		I2C_SCL_OUT_1( I2CHandlerType->I2CSCLGPIOx, I2CHandlerType->I2CSCLPin );
		Delay_us( I2CHandlerType->nowPluseWidth );
		if ( I2C_SDA_STATE( I2CHandlerType->I2CSDAGPIOx, I2CHandlerType->I2CSDAPin ) !=0x00)
		{
			_return += 1;
		}
	}
	return _return;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T I2C_HandlerType_Master_SoftSendData( I2C_HandlerType *I2CHandlerType, UINT8_T length )
{
	UINT8_T i = 0;
	UINT8_T _return = 0;
	//---发送启动型号
	I2C_HandlerType_Master_SoftStart( I2CHandlerType );
	//---发送从机地址
	I2C_HandlerType_Master_SoftSendByte( I2CHandlerType, I2CHandlerType->I2CDeviceAddr & 0xFE );
	//---读取从机的应答信号
	_return = I2C_HandlerType_Master_SoftReadAck( I2CHandlerType );
	if (_return!=0x00)
	{
		_return = 1;
	}
	else
	{
		for( i = 0; i < length; i++ )
		{
			//---发送数据
			I2C_HandlerType_Master_SoftSendByte( I2CHandlerType, I2CHandlerType->I2CDataPoint[i] );
			//---读取从机的应答信号
			_return = I2C_HandlerType_Master_SoftReadAck( I2CHandlerType );
			if( _return != 0x00 )
			{
				_return = 2 + i;
				break;
			}
		}
	}
	//---发送停止信号
	I2C_HandlerType_Master_SoftStop( I2CHandlerType );
	return _return;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T I2C_HandlerType_Master_SoftReadData( I2C_HandlerType *I2CHandlerType, UINT8_T length )
{
	UINT8_T _return = 0;
	UINT16_T i = 0;
	//---发送启动型号
	I2C_HandlerType_Master_SoftStart( I2CHandlerType );
	//---发送从机地址
	I2C_HandlerType_Master_SoftSendByte( I2CHandlerType, (I2CHandlerType->I2CDeviceAddr|0x01) );
	//---读取从机的应答信号
	_return = I2C_HandlerType_Master_SoftReadAck( I2CHandlerType );
	if( _return != 0x00 )
	{
		_return = 1;
	}
	else
	{
		for( i = 0; i < length; i++ )
		{
			//---读取数据
			I2CHandlerType->I2CDataPoint[i] = I2C_HandlerType_Master_SoftReadByte( I2CHandlerType );
			//---发送应答
			if( i == ( length - 1 ) )
			{
				_return = 1;
			}
			I2C_HandlerType_Master_SoftSendAck( I2CHandlerType, _return );
		}
		_return = 0;
	}
	//---发送停止信号
	I2C_HandlerType_Master_SoftStop( I2CHandlerType );
	return _return;
}

