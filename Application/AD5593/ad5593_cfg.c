#include "ad5593_cfg.h"

AD5593_HandlerType g_AD5593HandlerType=
{
	.genPurCtrReg=0,
	.adcSeqReg=0,
	.I2CAD5593=
	{
		.I2CSCLGPIOx = AD5593_SCL_PORT,
		.I2CSDAGPIOx = AD5593_SDA_PORT,
		.I2CSCLPin = AD5593_SCL_BIT,
		.I2CSDAPin = AD5593_SDA_BIT,
		.nowPluseWidth = 1,
		.I2CDeviceAddr = AD5593_WADDR,
		.I2CDataPoint = NULL,
		.I2C_MSG_Task = NULL,
	},
	.pI2CAD5593=NULL,
};

//---指针函数
pAD5593_HandlerType pAD5593HandlerType = &g_AD5593HandlerType;
//===统一发送函数---用于兼容软硬件的模拟
UINT8_T( *AD55593_SEND_CMD )( UINT8_T * ) = NULL;
UINT8_T( *AD55593_READ_CMD )( UINT8_T * ) = NULL;
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
	I2CTask_HandlerType_Master_Init( pAD5593HandlerType->pI2CAD5593,0 );
	AD55593_SEND_CMD = AD5593_IIC_SW_SendCmd;
	AD55593_READ_CMD = AD5593_IIC_SW_ReadCmd;
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
	pAD5593HandlerType->pI2CAD5593->I2CDataPoint = pVal;
	return pAD5593HandlerType->pI2CAD5593->I2C_MSG_Task( pAD5593HandlerType->pI2CAD5593, length, I2C_HandlerType_MSG_SofSendData );
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
	//---写地址，PointByte，发送停止信号
	pAD5593HandlerType->pI2CAD5593->I2CDataPoint = pVal;		// 模式命令
	pAD5593HandlerType->pI2CAD5593->I2C_MSG_Task( pAD5593HandlerType->pI2CAD5593, 1, I2C_HandlerType_MSG_SofSendData );
	pAD5593HandlerType->pI2CAD5593->I2CDataPoint = &pVal[1];	// 读取的
	return pAD5593HandlerType->pI2CAD5593->I2C_MSG_Task( pAD5593HandlerType->pI2CAD5593, 2, I2C_HandlerType_MSG_SofSendData );
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
    return AD55593_SEND_CMD(temp);
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
	_return = AD55593_READ_CMD( temp );
	if (temp[2]==0xFF)
	{
		_return = 0;
	}
	else
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
UINT8_T AD5593_IIC_DACWrite( UINT8_T channel, UINT16_T val )
{
	UINT8_T temp[3] = { AD5593_DAC_WRITE | channel,0x00,0x00 };
	UINT32_T powerVal = val;
	powerVal *= 0x03FF;
	val = powerVal / 4096;
	temp[1] = ( UINT8_T )( val >> 8 );
	temp[2] = ( UINT8_T )( val&0xFF );
	return AD55593_SEND_CMD( temp );
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
	UINT8_T temp[3] = { AD5593_DAC_READBACK | channel,0x00,0x00 };
	AD55593_READ_CMD( temp );
	pVal[0] = temp[1];
	pVal[1] = temp[2];
	return 0;
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
