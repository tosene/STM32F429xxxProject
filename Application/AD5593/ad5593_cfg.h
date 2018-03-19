#ifndef __AD5593_CFG_H
#define __AD5593_CFG_H
#ifdef __cplusplus
extern "C"
{
	#endif
	//////////////////////////////////////////////////////////////////////////////////////
	#include "iic_task.h"

	//===端口的定义
	//---SCL
	#define	AD5593_SCL_PORT							GPIOB
	#define AD5593_SCL_BIT							LL_GPIO_PIN_6
	//---SDA
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
	#define AD5593_REG_PULL_DOWN_CONF				0x06		//[0000]---DataSheet有错误
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

	//---I/O的配置,用于配置指定IO为ADC，DAC，GPIO模式
	#define AD5593_IO_CHANNEL_0						0x01		//DAC通道0
	#define AD5593_IO_CHANNEL_1						0x02		//DAC通道1
	#define AD5593_IO_CHANNEL_2						0x04		//DAC通道2
	#define AD5593_IO_CHANNEL_3						0x08		//DAC通道3
	#define AD5593_IO_CHANNEL_4						0x10		//DAC通道4
	#define AD5593_IO_CHANNEL_5						0x20		//DAC通道5
	#define AD5593_IO_CHANNEL_6						0x40		//DAC通道6
	#define AD5593_IO_CHANNEL_7						0x80		//DAC通道7

	//---DAC通道号
	#define AD5593_DAC_CHANNEL_0					0			//DAC通道0
	#define AD5593_DAC_CHANNEL_1					1			//DAC通道1
	#define AD5593_DAC_CHANNEL_2					2			//DAC通道2
	#define AD5593_DAC_CHANNEL_3					3			//DAC通道3
	#define AD5593_DAC_CHANNEL_4					4			//DAC通道4
	#define AD5593_DAC_CHANNEL_5					5			//DAC通道5
	#define AD5593_DAC_CHANNEL_6					6			//DAC通道6
	#define AD5593_DAC_CHANNEL_7					7			//DAC通道7

	//---ADC通道号
	#define AD5593_ADC_CHANNEL_0					0x01
	#define AD5593_ADC_CHANNEL_1					0x02
	#define AD5593_ADC_CHANNEL_2					0x04
	#define AD5593_ADC_CHANNEL_3					0x08
	#define AD5593_ADC_CHANNEL_4					0x10
	#define AD5593_ADC_CHANNEL_5					0x20
	#define AD5593_ADC_CHANNEL_6					0x40
	#define AD5593_ADC_CHANNEL_7					0x80

	//---使用的通信方式
	#define I2C_AD5593HandlerType					pAD5593HandlerType->pI2CAD5593
	//---结构体定义
	typedef struct _AD5593_HandlerType
	{
		UINT8_T  dacIOChannel;								//DAC的IO功能的配置
		UINT8_T  adcIOChannel;								//ADC的IO功能的配置
		UINT16_T genPurCtrReg;
		UINT16_T adcSeqReg;
		UINT16_T adcVref;
		UINT16_T dacVref;
		UINT16_T powerDownReg;
		I2C_HandlerType		I2CAD5593;						//I2C结构体
		pI2C_HandlerType	pI2CAD5593;						//I2C指针结构
	}AD5593_HandlerType,*pAD5593_HandlerType;

	extern pAD5593_HandlerType pAD5593HandlerType;
	//===函数定义
	UINT8_T AD5593_IIC_Init( void );
	UINT8_T AD5593_IIC_SW_SendData( UINT8_T *pVal, UINT8_T length );
	UINT8_T AD5593_IIC_SW_ReadData( UINT8_T *pVal, UINT8_T length );
	UINT8_T AD5593_IIC_SW_SendCmd( UINT8_T *pVal );
	UINT8_T AD5593_IIC_SW_ReadCmd( UINT8_T *pVal );
	UINT8_T AD5593_IIC_ResetDevice( void );
	UINT8_T AD5593_IIC_CheckDevice( void );
	UINT8_T AD5593_IIC_DACRead( UINT8_T channel, UINT8_T *pVal );
	//////////////////////////////////////////////////////////////////////////////////////
	#ifdef __cplusplus
}
#endif
#endif /*__AD5593_CFG_H */
