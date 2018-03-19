#include "iic_cfg.h"

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
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
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T I2C_HandlerType_Master_SoftInit( I2C_HandlerType *I2CHandlerType )
{
	LL_GPIO_InitTypeDef GPIO_InitStruct;
	//---GPIO�ĳ�ʼ��
	GPIO_InitStruct.Pin			= I2CHandlerType->I2CSCLPin;				//---��Ӧ��GPIO������
	GPIO_InitStruct.Mode		= LL_GPIO_MODE_OUTPUT;							//---����״̬Ϊ���ģʽ
	GPIO_InitStruct.Speed		= LL_GPIO_SPEED_FREQ_VERY_HIGH;					//---GPIO���ٶ�
	GPIO_InitStruct.OutputType	= LL_GPIO_OUTPUT_OPENDRAIN;						//---���ģʽ---��©���
	GPIO_InitStruct.Pull		= LL_GPIO_PULL_UP;								//---����
	GPIO_InitStruct.Alternate	= LL_GPIO_AF_0;									//---Ĭ������Ϊ�˿�
	//---SCL�ĳ�ʼ��
	LL_GPIO_Init( I2CHandlerType->I2CSCLGPIOx, &GPIO_InitStruct );
	//---SDA�ĳ�ʼ��
	GPIO_InitStruct.Pin = I2CHandlerType->I2CSDAPin;
	LL_GPIO_Init( I2CHandlerType->I2CSDAGPIOx, &GPIO_InitStruct );
	//---SCL��SDA�˿�����ߵ�ƽ
	I2C_SCL_OUT_1( I2CHandlerType->I2CSCLGPIOx, I2CHandlerType->I2CSCLPin );
	I2C_SDA_OUT_1( I2CHandlerType->I2CSDAGPIOx, I2CHandlerType->I2CSDAPin );
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T I2C_HandlerType_Master_SoftDeInit( I2C_HandlerType *I2CHandlerType )
{
	LL_GPIO_SetPinMode( I2CHandlerType->I2CSCLGPIOx, I2CHandlerType->I2CSCLPin, LL_GPIO_MODE_INPUT );
	LL_GPIO_SetPinMode( I2CHandlerType->I2CSDAGPIOx, I2CHandlerType->I2CSDAPin, LL_GPIO_MODE_INPUT );
	//---SCL��SDA�˿�����ߵ�ƽ
	I2C_SCL_OUT_1( I2CHandlerType->I2CSCLGPIOx, I2CHandlerType->I2CSCLPin );
	I2C_SDA_OUT_1( I2CHandlerType->I2CSDAGPIOx, I2CHandlerType->I2CSDAPin );
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T I2C_HandlerType_Master_SoftStart( I2C_HandlerType *I2CHandlerType )
{
	//I2C_SCL_OUT_0( I2CHandlerType->I2CSCLGPIOx, I2CHandlerType->I2CSCLPinMask );
	//---������ʼ�����������ź�
	I2C_SDA_OUT_1( I2CHandlerType->I2CSDAGPIOx, I2CHandlerType->I2CSDAPin );
	I2C_SCL_OUT_1( I2CHandlerType->I2CSCLGPIOx, I2CHandlerType->I2CSCLPin );
	Delay_us( I2CHandlerType->nowPluseWidth );
	//---������ʼ�ź�;
	I2C_SDA_OUT_0( I2CHandlerType->I2CSDAGPIOx, I2CHandlerType->I2CSDAPin );
	Delay_us( I2CHandlerType->nowPluseWidth );
	//---ǯסI2C���ߣ�׼�����ͻ��������
	I2C_SCL_OUT_0( I2CHandlerType->I2CSCLGPIOx, I2CHandlerType->I2CSCLPin );
	Delay_us( I2CHandlerType->nowPluseWidth );
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T I2C_HandlerType_Master_SoftStop( I2C_HandlerType *I2CHandlerType )
{
	I2C_SCL_OUT_0( I2CHandlerType->I2CSCLGPIOx, I2CHandlerType->I2CSCLPin );
	//---������ʼ�����������ź�
	I2C_SDA_OUT_0( I2CHandlerType->I2CSDAGPIOx, I2CHandlerType->I2CSDAPin );
	Delay_us( I2CHandlerType->nowPluseWidth );
	I2C_SCL_OUT_1( I2CHandlerType->I2CSCLGPIOx, I2CHandlerType->I2CSCLPin );
	I2C_SDA_OUT_1( I2CHandlerType->I2CSDAGPIOx, I2CHandlerType->I2CSDAPin );
	Delay_us( I2CHandlerType->nowPluseWidth );
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T I2C_HandlerType_Master_SoftReadAck( I2C_HandlerType *I2CHandlerType )
{
	UINT8_T is_ACk = 0;
	UINT8_T i = 0;
	I2C_SCL_OUT_1( I2CHandlerType->I2CSCLGPIOx, I2CHandlerType->I2CSCLPin );
	Delay_us( I2CHandlerType->nowPluseWidth );
	//---��ָ����ʱ���ڶ�ȡӦ���ź�
	for( i = 255; i > 0; i-- )
	{
		//---��ȡSDA��״̬
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
//////��	   ���� 
//////��	   �ܣ� ���ģ��IIC�ȴ�Ӧ���ź�
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T I2C_HandlerType_Master_SoftWaitAck( I2C_HandlerType *I2CHandlerType )
{
	UINT8_T errorCount = 0;
	I2C_SCL_OUT_1( I2CHandlerType->I2CSCLGPIOx, I2CHandlerType->I2CSCLPin );
	Delay_nop( 2 );
	//---��ָ����ʱ���ڶ�ȡӦ���ź�
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
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
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
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
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
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
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
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
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
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
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
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T I2C_HandlerType_Master_SoftSendData( I2C_HandlerType *I2CHandlerType, UINT8_T length )
{
	UINT8_T i = 0;
	UINT8_T _return = 0;
	//---���������ͺ�
	I2C_HandlerType_Master_SoftStart( I2CHandlerType );
	//---���ʹӻ���ַ
	I2C_HandlerType_Master_SoftSendByte( I2CHandlerType, I2CHandlerType->I2CDeviceAddr & 0xFE );
	//---��ȡ�ӻ���Ӧ���ź�
	_return = I2C_HandlerType_Master_SoftReadAck( I2CHandlerType );
	if (_return!=0x00)
	{
		_return = 1;
	}
	else
	{
		for( i = 0; i < length; i++ )
		{
			//---��������
			I2C_HandlerType_Master_SoftSendByte( I2CHandlerType, I2CHandlerType->I2CDataPoint[i] );
			//---��ȡ�ӻ���Ӧ���ź�
			_return = I2C_HandlerType_Master_SoftReadAck( I2CHandlerType );
			if( _return != 0x00 )
			{
				_return = 2 + i;
				break;
			}
		}
	}
	//---����ֹͣ�ź�
	I2C_HandlerType_Master_SoftStop( I2CHandlerType );
	return _return;
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T I2C_HandlerType_Master_SoftReadData( I2C_HandlerType *I2CHandlerType, UINT8_T length )
{
	UINT8_T _return = 0;
	UINT16_T i = 0;
	//---���������ͺ�
	I2C_HandlerType_Master_SoftStart( I2CHandlerType );
	//---���ʹӻ���ַ
	I2C_HandlerType_Master_SoftSendByte( I2CHandlerType, (I2CHandlerType->I2CDeviceAddr|0x01) );
	//---��ȡ�ӻ���Ӧ���ź�
	_return = I2C_HandlerType_Master_SoftReadAck( I2CHandlerType );
	if( _return != 0x00 )
	{
		_return = 1;
	}
	else
	{
		for( i = 0; i < length; i++ )
		{
			//---��ȡ����
			I2CHandlerType->I2CDataPoint[i] = I2C_HandlerType_Master_SoftReadByte( I2CHandlerType );
			//---����Ӧ��
			if( i == ( length - 1 ) )
			{
				_return = 1;
			}
			I2C_HandlerType_Master_SoftSendAck( I2CHandlerType, _return );
		}
		_return = 0;
	}
	//---����ֹͣ�ź�
	I2C_HandlerType_Master_SoftStop( I2CHandlerType );
	return _return;
}

