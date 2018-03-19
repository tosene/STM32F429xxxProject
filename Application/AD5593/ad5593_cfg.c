#include "ad5593_cfg.h"
#include "iic_cfg.h"

//---全局结构体
AD5593_HandlerType g_AD5593HandlerType=
{
	.genPurCtrReg=0,
	.adcSeqReg=0,
	.I2CAD5593=
	{
		.I2CSCLGPIOx	= AD5593_SCL_PORT,
		.I2CSDAGPIOx	= AD5593_SDA_PORT,
		.I2CSCLPin		= AD5593_SCL_BIT,
		.I2CSDAPin		= AD5593_SDA_BIT,
		.nowPluseWidth	= 10,
		.I2CDeviceAddr	= AD5593_RADDR,
		.I2CDataPoint	= NULL,
		.I2C_MSG_Task	= NULL,
	},
	.pI2CAD5593=NULL,
};
//---指针结构体
pAD5593_HandlerType pAD5593HandlerType = &g_AD5593HandlerType;
//---统一发送函数---用于兼容软硬件的模拟
UINT8_T( *AD5593_SEND_CMD )( UINT8_T * ) = NULL;
//---统一读取函数---用于兼容软硬件的模拟
UINT8_T( *AD5593_READ_CMD )( UINT8_T * ) = NULL;

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T AD5593_IIC_Init( void )
{
	pAD5593HandlerType->pI2CAD5593 = &pAD5593HandlerType->I2CAD5593;
	//---初始化IIC的通信参数
	//I2CTask_HandlerType_Master_Init( pAD5593HandlerType->pI2CAD5593,0 );
	I2CTask_HandlerType_Master_Init( I2C_AD5593HandlerType, 0 );
	//---发送函数
	AD5593_SEND_CMD = AD5593_IIC_SW_SendCmd;
	//---读取函数
	AD5593_READ_CMD = AD5593_IIC_SW_ReadCmd;
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T AD5593_IIC_SW_SendData( UINT8_T *pVal, UINT8_T length )
{
	//pAD5593HandlerType->pI2CAD5593->I2CDataPoint = pVal;
	//return pAD5593HandlerType->pI2CAD5593->I2C_MSG_Task( pAD5593HandlerType->pI2CAD5593, length, I2C_HandlerType_MSG_SofSendData );
	I2C_AD5593HandlerType->I2CDataPoint = pVal;
	return I2C_AD5593HandlerType->I2C_MSG_Task( I2C_AD5593HandlerType, length, I2C_HandlerType_MSG_SofSendData );
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T AD5593_IIC_SW_ReadData( UINT8_T *pVal, UINT8_T length )
{
	/*
	UINT8_T _return = 0;
	//---发送启动型号
	I2C_HandlerType_Master_SoftStart( pAD5593HandlerType->pI2CAD5593 );
	//---发送从机地址
	I2C_HandlerType_Master_SoftSendByte( pAD5593HandlerType->pI2CAD5593, ( pAD5593HandlerType->pI2CAD5593->I2CDeviceAddr&0xFE) );
	//---读取从机的应答信号
	_return = I2C_HandlerType_Master_SoftReadAck( pAD5593HandlerType->pI2CAD5593 );
	if (_return!=0)
	{
		_return = 1;
	}
	else
	{
		I2C_HandlerType_Master_SoftSendByte( pAD5593HandlerType->pI2CAD5593, pVal[0] );
		//---读取从机的应答信号
		_return = I2C_HandlerType_Master_SoftReadAck( pAD5593HandlerType->pI2CAD5593 );
		//---发送停止信号
		I2C_HandlerType_Master_SoftStop( pAD5593HandlerType->pI2CAD5593 );

		//---发送启动型号
		I2C_HandlerType_Master_SoftStart( pAD5593HandlerType->pI2CAD5593 );
		//---发送从机地址
		I2C_HandlerType_Master_SoftSendByte( pAD5593HandlerType->pI2CAD5593, ( pAD5593HandlerType->pI2CAD5593->I2CDeviceAddr | 0x01 ) );
		//---读取从机的应答信号
		_return = I2C_HandlerType_Master_SoftReadAck( pAD5593HandlerType->pI2CAD5593 );

		pVal[1]=I2C_HandlerType_Master_SoftReadByte( pAD5593HandlerType->pI2CAD5593 );
		I2C_HandlerType_Master_SoftSendAck( pAD5593HandlerType->pI2CAD5593,0 );
		pVal[2]=I2C_HandlerType_Master_SoftReadByte( pAD5593HandlerType->pI2CAD5593 );
		I2C_HandlerType_Master_SoftSendAck( pAD5593HandlerType->pI2CAD5593, 1 );
		//---发送停止信号
		I2C_HandlerType_Master_SoftStop( pAD5593HandlerType->pI2CAD5593 );
	}
	return _return;
	*/
	//---写地址，PointByte，发送停止信号
	//pAD5593HandlerType->pI2CAD5593->I2CDataPoint = pVal;		// 模式命令
	//pAD5593HandlerType->pI2CAD5593->I2C_MSG_Task( pAD5593HandlerType->pI2CAD5593, 1, I2C_HandlerType_MSG_SofSendData );
	//pAD5593HandlerType->pI2CAD5593->I2CDataPoint = &pVal[1];	// 读取到的数据
	//return pAD5593HandlerType->pI2CAD5593->I2C_MSG_Task( pAD5593HandlerType->pI2CAD5593, 2, I2C_HandlerType_MSG_SofReadData );
	I2C_AD5593HandlerType->I2CDataPoint = pVal;		// 模式命令
	I2C_AD5593HandlerType->I2C_MSG_Task( I2C_AD5593HandlerType, 1, I2C_HandlerType_MSG_SofSendData );
	I2C_AD5593HandlerType->I2CDataPoint = &pVal[1];	// 读取到的数据
	return pAD5593HandlerType->pI2CAD5593->I2C_MSG_Task( I2C_AD5593HandlerType, 2, I2C_HandlerType_MSG_SofReadData );
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T AD5593_IIC_SW_SendCmd( UINT8_T *pVal )
{
	return AD5593_IIC_SW_SendData( pVal, 3 );
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T AD5593_IIC_SW_ReadCmd( UINT8_T *pVal )
{
	return AD5593_IIC_SW_ReadData( pVal, 3 );
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T AD5593_IIC_ResetDevice( void )
{
	UINT8_T temp[3] = { AD5593_REG_SOFT_RESET,0x0D,0xAC };
    return AD5593_SEND_CMD(temp);
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T AD5593_IIC_CheckDevice( void )
{
	UINT8_T temp[3] = { AD5593_REG_READBACK| AD5593_REG_PULL_DOWN_CONF,0x00,0x00 };
	UINT8_T _return = 0;
	_return = AD5593_READ_CMD( temp );
	if ((_return!=0)||(temp[1]!=0x00)||(temp[2]!=0x00))
	{
		_return = 1;
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
UINT8_T AD5593_IIC_LDAC( UINT8_T model )
{
	UINT8_T temp[3] = { AD5593_CONF_MODE | AD5593_REG_LDAC_MODE,0x00,0x00 };
	temp[2] = ( model & 0x03 );
	return AD5593_SEND_CMD( temp );
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T AD5593_IIC_DACWrite( UINT8_T channel, UINT16_T val )
{
	UINT8_T temp[3] = { AD5593_DAC_WRITE | (channel&0x07),0x00,0x00 };
	UINT32_T powerVal = val;
	powerVal *= 0x03FF;
	val = powerVal / 4096;
	temp[1] = ( UINT8_T )( val >> 8 );
	temp[2] = ( UINT8_T )( val&0xFF );
	return AD5593_SEND_CMD( temp );
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T AD5593_IIC_DACRead( UINT8_T channel, UINT8_T *pVal )
{
	UINT8_T _return = 0;
	UINT8_T temp[3] = { AD5593_DAC_READBACK | (channel&0x07),0x00,0x00 };
	AD5593_READ_CMD( temp );
	//---DAC读取，最高Bit位为1，代表是读取的DAC的值，接下来的3Bit值，代表的是DAC的通道号
	pVal[0] = temp[1];
	pVal[1] = temp[2];
	if ((temp[1]&0x80)==0x00)
	{
		_return = 1;
	}
	else
	{
		UINT8_T dacChannel = (temp[1] >> 4)&0x07;
		if (temp[1]!=(channel&0x07))
		{
			_return = 1;
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
UINT8_T AD5593_IIC_DACEnableChannel( UINT8_T ioChannel )
{
	UINT8_T temp[3] = { AD5593_CONF_MODE | AD5593_REG_DAC_PIN_CONF,0x00,ioChannel };
	return AD5593_SEND_CMD( temp );
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T AD5593_IIC_DACDisableChannel( UINT8_T ioChannel )
{
	UINT8_T temp[3] = { AD5593_CONF_MODE | AD5593_REG_DAC_PIN_CONF,0x00,ioChannel };
	return AD5593_SEND_CMD( temp );
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T AD5593_IIC_ADCRead( UINT8_T channel, UINT16_T val )
{
  return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T AD5593_IIC_ADCEnableChannel( UINT8_T ioChannel )
{
	UINT8_T temp[3] = { AD5593_CONF_MODE | AD5593_REG_ADC_PIN_CONF,0x00,ioChannel };
	return AD5593_SEND_CMD( temp );
}