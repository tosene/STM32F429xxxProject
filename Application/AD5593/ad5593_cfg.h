#ifndef __AD5593_CFG_H
#define __AD5593_CFG_H
#ifdef __cplusplus
extern "C"
{
	#endif
	//////////////////////////////////////////////////////////////////////////////////////
	#include "iic_task.h"

	//===端口的定义
	#define	AD5593_SCL_PORT							GPIOB
	#define AD5593_SCL_BIT							LL_GPIO_PIN_6
	#define AD5593_SDA_PORT							GPIOB
	#define AD5593_SDA_BIT							LL_GPIO_PIN_7

	//===宏定义
	#define AD5593_A0								1
	#if AD5593_A0
		#define	AD5593_WADDR						0x22		
		#define AD5593_RADDR						0x23
	#else
		#define	AD5593_WADDR						0x20	
		#define AD5593_RADDR						0z21
	#endif

	//---Pointer Byte Configuration
	#define AD5593_CONF_MODE						0x00		//配置模式
	#define AD5593_DAC_WRITE						0x10		//DAC写操作
	#define AD5593_ADC_READBACK						0x40		//ADC读返回
	#define AD5593_DAC_READBACK						0x50		//DAC读返回
	#define AD5593_GPIO_READBACK					0x60		//GPIO读返回
	#define AD5593_REG_READBACK						0x70		//寄存器读返回

	//---Control Registers
	#define AD5593_REG_NOP							0x00		//[0000]
	#define AD5593_REG_ADC_SEQ						0x02		//[0000]
	#define AD5593_REG_GEN_PUR						0x03		//[0000]
	#define AD5593_REG_ADC_PIN_CONF					0x04		//[0000]
	#define AD5593_REG_DAC_PIN_CONF					0x05		//[0000]
	#define AD5593_REG_PULL_DOWN_CONF				0x06		//[00FF]---可以用于判断设备是否连接(下拉配置，对地85K的电阻)
	#define AD5593_REG_LDAC_MODE					0x07		//[0000]
	#define AD5593_REG_GPIO_WRITE_CONF				0x08		//[0000]
	#define AD5593_REG_GPIO_WRITE_DATA				0x09		//[0000]
	#define AD5593_REG_GPIO_READ_CONF				0x0A		//[0000]
	#define AD5593_REG_POWER_DOWN_REF				0x0B		//[0000]
	#define AD5593_REG_OPEN_DRAIN_CONF				0x0C		//[0000]
	#define AD5593_REG_THREE_STATE_PIN				0x0D		//[0000]
	#define AD5593_REG_NULL							0x0E		//[0000]
	#define AD5593_REG_SOFT_RESET					0x0F		//[0000]

	//---General - Purpose Control Register Descriptions
	#define AD5593_GEN_PUR_ADC_BUFFER_PRECHARGE		9			//ADC缓存预充电
	#define AD5593_GEN_PUR_ADC_BUFFER_ENABLE		8			//ADC缓存使能
	#define AD5593_GEN_PUR_LOCK_CONF				7			//锁定端口的配置
	#define AD5593_GEN_PUR_WRITE_ALL_DAC			6			//写所有的DAC通道
	#define AD5593_GEN_PUR_ADC_RANGE_SELECT			5			//配置ADC的参考电压的增益
	#define AD5593_GEN_PUR_DAC_RANGE_SELECT			4			//配置DAC的参考电压的增益

	//---LDAC Mode Register
	#define AD5593_LDAC_MODE_LOAD_UPDATE			0x00		//加载并立即更新
	#define AD5593_LDAC_MODE_LOAD					0x01		//加载不立即更新
	#define AD5593_LDAC_MODE_UPDATE					0x02		//更新
	#define AD5593_LDAC_MODE_NULL					0x03		//保留



	//---结构体定义
	typedef struct _AD5593_HandlerType
	{
		UINT16_T genPurCtrReg;
		UINT16_T adcSeqReg;
		UINT16_T adcVref;
		UINT16_T dacVref;
		UINT16_T powerDownReg;
		I2C_HandlerType		I2CAD5593;						//I2C结构体
		pI2C_HandlerType	pI2CAD5593;						//I2C指针结构
	}AD5593_HandlerType,*pAD5593_HandlerType;
	//===函数定义
	UINT8_T AD5593_IIC_Init( void );
	UINT8_T AD5593_IIC_SW_SendData( UINT8_T *pVal, UINT8_T length );
	UINT8_T AD5593_IIC_SW_ReadData( UINT8_T *pVal, UINT8_T length );
	UINT8_T AD5593_IIC_SW_SendCmd( UINT8_T *pVal );
	UINT8_T AD5593_IIC_SW_ReadCmd( UINT8_T *pVal );
	UINT8_T AD5593_IIC_ResetDevice( void );
	UINT8_T AD5593_IIC_CheckDevice( void );
	//////////////////////////////////////////////////////////////////////////////////////
	#ifdef __cplusplus
}
#endif
#endif /*__AD5593_CFG_H */
