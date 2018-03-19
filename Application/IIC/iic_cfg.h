#ifndef __IIC_CFG_H
#define __IIC_CFG_H
#ifdef __cplusplus
extern "C" 
{
#endif
	///////////////////////////////////////////////////////////////////////////////
	//////ʹ�øú��������ȱ�֤GPIO��ʱ���Ѿ�ʹ�ܣ������ڲ��Ѿ����˿�����Ϊ��©���
	//////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////
	#include "complier_lib.h"
	#include "delay_lib.h"
	
	//---�������Ϣ
	#define I2C_HandlerType_MSG_SoftInit			0
	#define I2C_HandlerType_MSG_SoftDeInit			1
	#define I2C_HandlerType_MSG_SofSendData			2
	#define I2C_HandlerType_MSG_SofReadData			3

	//===��Ϣ��ģʽ
	//---SDA�˿�
	#define I2C_SDA_OUT_0(name,index)	LL_GPIO_ResetOutputPin(	name,index )
	#define I2C_SDA_OUT_1(name,index)	LL_GPIO_SetOutputPin(	name,index )
	#define I2C_SDA_STATE(name,index)	LL_GPIO_IsInputPinSet(	name,index )
	//---SCL�˿�
	#define I2C_SCL_OUT_0(name,index)	LL_GPIO_ResetOutputPin(	name,index )
	#define I2C_SCL_OUT_1(name,index)	LL_GPIO_SetOutputPin(	name,index )
	#define I2C_SCL_STATE(name,index)	LL_GPIO_IsInputPinSet(	name,index )

	//---�ṹ�嶨��
	typedef struct _I2C_HandlerType		I2C_HandlerType;
	typedef	struct _I2C_HandlerType		*pI2C_HandlerType;
	//---��Ϣ�嶨��
	typedef UINT8_T( *I2C_MSG_HandlerType )( I2C_HandlerType *I2CHandlerType, UINT8_T val, UINT8_T msg );
	//---��Ϣ���I2C
	struct _I2C_HandlerType
	{
		I2C_TypeDef				*I2Cx;							//---ʹ�õ�I2C�ӿ�
		GPIO_TypeDef			*I2CSCLGPIOx;					//---SCL�˿�
		GPIO_TypeDef			*I2CSDAGPIOx;					//---SDA�˿�
		UINT32_T				I2CSCLPin;						//---SCL����
		UINT32_T				I2CSDAPin;						//---SDA����
		UINT8_T					nowPluseWidth;					//---�����ȣ����ģ��ʹ��
		UINT8_T					I2CDeviceAddr;					//---�豸�ĵ�ַ
		UINT8_T					*I2CDataPoint;					//---��д���ݵ�ָ��
		I2C_MSG_HandlerType		I2C_MSG_Task;					//---��Ϣ�崦����
	};
	//===��������
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
