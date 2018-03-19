#include "one_wire_cfg.h"

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T OneWire_HandlerType_Init(OneWire_HandlerType *OneWireHandlerType)
{
	LL_GPIO_InitTypeDef GPIO_InitStruct;
	//---GPIO�ĳ�ʼ��
	GPIO_InitStruct.Pin			= OneWireHandlerType->OneWirePinMask;			//---��Ӧ��GPIO������
	GPIO_InitStruct.Mode		= LL_GPIO_MODE_OUTPUT;							//---����״̬Ϊ���ģʽ
	GPIO_InitStruct.Speed		= LL_GPIO_SPEED_FREQ_VERY_HIGH;					//---GPIO���ٶ�
	GPIO_InitStruct.OutputType  = LL_GPIO_OUTPUT_OPENDRAIN;						//---���ģʽ---��©���
	GPIO_InitStruct.Pull		= LL_GPIO_PULL_UP;								//---����ʹ��
	GPIO_InitStruct.Alternate	= LL_GPIO_AF_0;									//---Ĭ������Ϊ�˿�
	//---�˿ڵ�����
	LL_GPIO_Init(OneWireHandlerType->OneWireGPIOx, &GPIO_InitStruct);
	//---����ߵ�ƽ
	OneWire_OUT_1(OneWireHandlerType->OneWireGPIOx, OneWireHandlerType->OneWirePinMask);
	//---��Ϣ��
	OneWireHandlerType->OneWire_MSG_Task = NULL;
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T OneWire_HandlerType_DeInit(OneWire_HandlerType *OneWireHandlerType)
{
	//---GPIO�ĳ�ʼ��
	LL_GPIO_SetPinMode(OneWireHandlerType->OneWireGPIOx, OneWireHandlerType->OneWirePinMask, LL_GPIO_MODE_INPUT);
	//---����ߵ�ƽ
	OneWire_OUT_1(OneWireHandlerType->OneWireGPIOx, OneWireHandlerType->OneWirePinMask);
	//---��Ϣ��
	OneWireHandlerType->OneWire_MSG_Task = NULL;
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T OneWire_HandlerType_Start(OneWire_HandlerType *OneWireHandlerType)
{
	UINT8_T _return = 0;
	//---����Ϊ����������
	OneWire_OUT_0(OneWireHandlerType->OneWireGPIOx, OneWireHandlerType->OneWirePinMask);
	Delay_us(500);				//>=480
	//---����ߵ�ƽ
	OneWire_OUT_1(OneWireHandlerType->OneWireGPIOx, OneWireHandlerType->OneWirePinMask);
	Delay_us(50);				//15us~60us֮��
	_return = OneWire_STATE(OneWireHandlerType->OneWireGPIOx, OneWireHandlerType->OneWirePinMask);
	Delay_us(200);				//60us~240us
	return _return;
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T OneWire_HandlerType_WriteBit(OneWire_HandlerType *OneWireHandlerType, UINT8_T bitVal)
{	
	//---�������ߣ�ǿ������
	OneWire_OUT_0(OneWireHandlerType->OneWireGPIOx, OneWireHandlerType->OneWirePinMask);
	Delay_us(4);
	if (bitVal)
	{
		//---�ͷ�����
		OneWire_OUT_1(OneWireHandlerType->OneWireGPIOx, OneWireHandlerType->OneWirePinMask);
	}
	Delay_us(50);		//<60us 
	//---�ͷ�����
	OneWire_OUT_1(OneWireHandlerType->OneWireGPIOx, OneWireHandlerType->OneWirePinMask);
	Delay_us(4);
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T OneWire_HandlerType_ReadBit(OneWire_HandlerType *OneWireHandlerType)
{
	UINT8_T _return = 0;
	//---��������,ǿ������
	OneWire_OUT_0(OneWireHandlerType->OneWireGPIOx, OneWireHandlerType->OneWirePinMask);
	Delay_us(8);
	//---�ͷ�����
	OneWire_OUT_1(OneWireHandlerType->OneWireGPIOx, OneWireHandlerType->OneWirePinMask);
	Delay_us(14);
	//---��ȡ����
	if ( OneWire_STATE(OneWireHandlerType->OneWireGPIOx, OneWireHandlerType->OneWirePinMask))
	{
		_return = 1;
	}
	Delay_us(40);
	//---�ͷ�����
	OneWire_OUT_1(OneWireHandlerType->OneWireGPIOx, OneWireHandlerType->OneWirePinMask);
	return _return;
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T OneWire_HandlerType_WriteByte(OneWire_HandlerType *OneWireHandlerType, UINT8_T val)
{
	UINT8_T i = 0;
	for (i = 0; i < 8; i++)
	{
		//---�ȷ��͵�λ����
		OneWire_HandlerType_WriteBit(OneWireHandlerType, (val & 0x01));
		val >>= 1;
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
UINT8_T OneWire_HandlerType_ReadByte(OneWire_HandlerType *OneWireHandlerType)
{
	UINT8_T _return = 0, i = 0;
	for (i = 0; i < 8; i++)
	{
		_return |= (OneWire_HandlerType_ReadBit(OneWireHandlerType) << i);
	}
	Delay_us(5);
	return _return;
}