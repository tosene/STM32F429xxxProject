#include "one_wire_cfg.h"

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T OneWire_HandlerType_Init(OneWire_HandlerType *OneWireHandlerType)
{
	LL_GPIO_InitTypeDef GPIO_InitStruct;
	//---GPIO的初始化
	GPIO_InitStruct.Pin			= OneWireHandlerType->OneWirePinMask;			//---对应的GPIO的引脚
	GPIO_InitStruct.Mode		= LL_GPIO_MODE_OUTPUT;							//---配置状态为输出模式
	GPIO_InitStruct.Speed		= LL_GPIO_SPEED_FREQ_VERY_HIGH;					//---GPIO的速度
	GPIO_InitStruct.OutputType  = LL_GPIO_OUTPUT_OPENDRAIN;						//---输出模式---开漏输出
	GPIO_InitStruct.Pull		= LL_GPIO_PULL_UP;								//---上拉使能
	GPIO_InitStruct.Alternate	= LL_GPIO_AF_0;									//---默认配置为端口
	//---端口的配置
	LL_GPIO_Init(OneWireHandlerType->OneWireGPIOx, &GPIO_InitStruct);
	//---输出高电平
	OneWire_OUT_1(OneWireHandlerType->OneWireGPIOx, OneWireHandlerType->OneWirePinMask);
	//---消息体
	OneWireHandlerType->OneWire_MSG_Task = NULL;
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T OneWire_HandlerType_DeInit(OneWire_HandlerType *OneWireHandlerType)
{
	//---GPIO的初始化
	LL_GPIO_SetPinMode(OneWireHandlerType->OneWireGPIOx, OneWireHandlerType->OneWirePinMask, LL_GPIO_MODE_INPUT);
	//---输出高电平
	OneWire_OUT_1(OneWireHandlerType->OneWireGPIOx, OneWireHandlerType->OneWirePinMask);
	//---消息体
	OneWireHandlerType->OneWire_MSG_Task = NULL;
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T OneWire_HandlerType_Start(OneWire_HandlerType *OneWireHandlerType)
{
	UINT8_T _return = 0;
	//---设置为输出且输出零
	OneWire_OUT_0(OneWireHandlerType->OneWireGPIOx, OneWireHandlerType->OneWirePinMask);
	Delay_us(500);				//>=480
	//---输出高电平
	OneWire_OUT_1(OneWireHandlerType->OneWireGPIOx, OneWireHandlerType->OneWirePinMask);
	Delay_us(50);				//15us~60us之间
	_return = OneWire_STATE(OneWireHandlerType->OneWireGPIOx, OneWireHandlerType->OneWirePinMask);
	Delay_us(200);				//60us~240us
	return _return;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T OneWire_HandlerType_WriteBit(OneWire_HandlerType *OneWireHandlerType, UINT8_T bitVal)
{	
	//---控制总线，强制拉低
	OneWire_OUT_0(OneWireHandlerType->OneWireGPIOx, OneWireHandlerType->OneWirePinMask);
	Delay_us(4);
	if (bitVal)
	{
		//---释放总线
		OneWire_OUT_1(OneWireHandlerType->OneWireGPIOx, OneWireHandlerType->OneWirePinMask);
	}
	Delay_us(50);		//<60us 
	//---释放总线
	OneWire_OUT_1(OneWireHandlerType->OneWireGPIOx, OneWireHandlerType->OneWirePinMask);
	Delay_us(4);
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T OneWire_HandlerType_ReadBit(OneWire_HandlerType *OneWireHandlerType)
{
	UINT8_T _return = 0;
	//---控制总线,强制拉低
	OneWire_OUT_0(OneWireHandlerType->OneWireGPIOx, OneWireHandlerType->OneWirePinMask);
	Delay_us(8);
	//---释放总线
	OneWire_OUT_1(OneWireHandlerType->OneWireGPIOx, OneWireHandlerType->OneWirePinMask);
	Delay_us(14);
	//---读取数据
	if ( OneWire_STATE(OneWireHandlerType->OneWireGPIOx, OneWireHandlerType->OneWirePinMask))
	{
		_return = 1;
	}
	Delay_us(40);
	//---释放总线
	OneWire_OUT_1(OneWireHandlerType->OneWireGPIOx, OneWireHandlerType->OneWirePinMask);
	return _return;
}

///////////////////////////////////////////////////////////////////////////////
//////函	   数： 
//////功	   能： 
//////输入参数: 
//////输出参数: 
//////说	   明： 
//////////////////////////////////////////////////////////////////////////////
UINT8_T OneWire_HandlerType_WriteByte(OneWire_HandlerType *OneWireHandlerType, UINT8_T val)
{
	UINT8_T i = 0;
	for (i = 0; i < 8; i++)
	{
		//---先发送低位数据
		OneWire_HandlerType_WriteBit(OneWireHandlerType, (val & 0x01));
		val >>= 1;
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