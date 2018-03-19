
#include "wm8510_cfg.h"
//===��������
WM8510_HandlerType g_WM8510HandlerType =
{
	.mclkDIV			= 1,
	.bclkDIV			= 1,
	.preDIV				= 0,
	.pll_N				= 0,
	.R0					= { 0x00,0x00 },
	.R1					= { 0x02,0x23 },
	.nowR6				= { 0x0D,0x41 },
	.lastR6				= { 0x00,0x00 },
	.nowR36				= { 0x00,0x00 },
	.lastR36			= { 0x00,0x00 },
	.nowR37				= { 0x00,0x00 },
	.lastR37			= { 0x00,0x00 },
	.nowR38				= { 0x00,0x00 },
	.lastR38			= { 0x00,0x00 },
	.nowR39				= { 0x00,0x00 },
	.lastR39			= { 0x00,0x00 },
	.pll_K				= 0,
	.oscFreq			= 0,
	.pllRate			= 0,
	.I2CWM8510			= 
	{
		.I2CSCLGPIOx	= WM8510_SCL_PORT,
		.I2CSDAGPIOx	= WM8510_SDA_PORT,
		.I2CSCLPin	    = WM8510_SCL_BIT,
		.I2CSDAPin	    = WM8510_SDA_BIT,
		.nowPluseWidth	= 1,
		.I2CDeviceAddr	= WM8510_WADDR,
		.I2CDataPoint	= NULL,
		.I2C_MSG_Task	= NULL,
	},
	.pI2CWM8510=NULL,
};

pWM8510_HandlerType pWM8510HandlerType = &g_WM8510HandlerType;
//===ͳһ���ͺ���---���ڼ�����Ӳ����ģ��
UINT8_T( *WM8510_SEND_CMD )( UINT8_T * ) = NULL;

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T WM8510_IIC_Init( void )
{
	pWM8510HandlerType->pI2CWM8510 = &pWM8510HandlerType->I2CWM8510;
	//---��ʼ����ʱ�����������һ��
	I2CTask_HandlerType_Master_Init( pWM8510HandlerType->pI2CWM8510,0 );
	//---ָ���ͺ���
	WM8510_SEND_CMD = WM8510_IIC_SW_SendCmd;
	//---������������
	WM8510_SEND_CMD( pWM8510HandlerType->R0 );
	//---???��֪��Ϊʲô��R0�Ĵ��������ô���,��Ҫ��������
	WM8510_SEND_CMD( pWM8510HandlerType->R0 );
	//---���üĴ���R1
	WM8510_SEND_CMD( pWM8510HandlerType->R1 );
    return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T WM8510_IIC_SW_SendData( UINT8_T *pRegistValue, UINT8_T length )
{
	pWM8510HandlerType->pI2CWM8510->I2CDataPoint = pRegistValue;
	//return I2CLib_HandlerType_Master_SoftSendData( pWM8510HandlerType->pI2CWM8510, length );
	return pWM8510HandlerType->pI2CWM8510->I2C_MSG_Task( pWM8510HandlerType->pI2CWM8510, length, I2C_HandlerType_MSG_SofSendData );
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
UINT8_T WM8510_IIC_SW_SendCmd( UINT8_T *pRegistValue )
{
	return WM8510_IIC_SW_SendData( pRegistValue, 2 );
}

/////////////////////////////////////////////////////
// ��	����  WM8510_Calc_PllRate(UINT32_T freq)
// ��	�ܣ�  ����WM8510��PLL������
// ��������� Ŀ��Ƶ��
// ��������� ��
/////////////////////////////////////////////////////
void WM8510_Calc_PllRate( UINT32_T freq )
{
	pWM8510HandlerType->oscFreq = WM8510_FREQ;
	//---���ƽ��
	if( freq > WM8510_OUT_MAX_FREQ )
	{
		//---������Ƶ��
		freq = WM8510_OUT_MAX_FREQ;
	}
	//---Ƶ��
	if( freq < WM8510_OUT_MIN_FREQ )
	{
		//---��С���Ƶ��
		freq = WM8510_OUT_MIN_FREQ;
	}
	//---��������
	if( freq > PDIV0_MDIV1_BDIV1_MIN )
	{
		pWM8510HandlerType->preDIV = 0;
		pWM8510HandlerType->mclkDIV = MCLK_DIV_1;
		pWM8510HandlerType->bclkDIV = BCLK_DIV_1;
	}
	else if( freq > PDIV0_MDIV2_BDIV1_MIN )
	{
		pWM8510HandlerType->preDIV = 0;
		pWM8510HandlerType->mclkDIV = MCLK_DIV_2;
		pWM8510HandlerType->bclkDIV = BCLK_DIV_1;
		freq <<= 1;	// ����2
	}
	else if( freq > PDIV0_MDIV4_BDIV1_MIN )
	{
		pWM8510HandlerType->preDIV = 0;
		pWM8510HandlerType->mclkDIV = MCLK_DIV_4;
		pWM8510HandlerType->bclkDIV = BCLK_DIV_1;
		freq <<= 2;	// ����4
	}
	else if( freq > PDIV0_MDIV8_BDIV1_MIN )
	{
		pWM8510HandlerType->preDIV = 0;
		pWM8510HandlerType->mclkDIV = MCLK_DIV_8;
		pWM8510HandlerType->bclkDIV = BCLK_DIV_1;
		freq <<= 3;	// ����8
	}
	else if( freq > PDIV0_MDIV8_BDIV2_MIN )
	{
		pWM8510HandlerType->preDIV = 0;
		pWM8510HandlerType->mclkDIV = MCLK_DIV_8;
		pWM8510HandlerType->bclkDIV = BCLK_DIV_2;
		freq <<= 4;	// ����16
	}
	else if( freq > PDIV0_MDIV8_BDIV4_MIN )
	{
		pWM8510HandlerType->preDIV = 0;
		pWM8510HandlerType->mclkDIV = MCLK_DIV_8;
		pWM8510HandlerType->bclkDIV = BCLK_DIV_4;
		freq <<= 5;	// ����32
	}
	else if( freq > PDIV0_MDIV8_BDIV8_MIN )
	{
		pWM8510HandlerType->preDIV = 0;
		pWM8510HandlerType->mclkDIV = MCLK_DIV_8;
		pWM8510HandlerType->bclkDIV = BCLK_DIV_8;
		freq <<= 6;	// ����64
	}
	else if( freq > PDIV0_MDIV4_BDIV32_MIN )
	{
		pWM8510HandlerType->preDIV = 0;
		pWM8510HandlerType->mclkDIV = MCLK_DIV_4;
		pWM8510HandlerType->bclkDIV = BCLK_DIV_32;
		freq <<= 7;	// ����128
	}
	else if( freq > PDIV1_MDIV8_BDIV16_MIN )
	{
		pWM8510HandlerType->preDIV = 1;
		pWM8510HandlerType->mclkDIV = MCLK_DIV_8;
		pWM8510HandlerType->bclkDIV = BCLK_DIV_16;
		freq <<= 7;	// ����128
		pWM8510HandlerType->oscFreq >>= 1;
	}
	else if( freq > PDIV1_MDIV8_BDIV32_MIN )
	{
		pWM8510HandlerType->preDIV = 1;
		pWM8510HandlerType->mclkDIV = MCLK_DIV_8;
		pWM8510HandlerType->bclkDIV = BCLK_DIV_32;
		freq <<= 8;	// ����256
		pWM8510HandlerType->oscFreq >>= 1;
	}
	else
	{
		pWM8510HandlerType->preDIV = 1;
		pWM8510HandlerType->mclkDIV = MCLK_DIV_12;
		pWM8510HandlerType->bclkDIV = BCLK_DIV_32;
		freq *= 384;	// ����384
		pWM8510HandlerType->oscFreq >>= 1;
	}
	freq <<= 2;	// ����4
	pWM8510HandlerType->pllRate = ( float )freq / pWM8510HandlerType->oscFreq;
	pWM8510HandlerType->pll_N = ( UINT8_T )pWM8510HandlerType->pllRate;
	pWM8510HandlerType->pll_K = ( UINT32_T )( ( pWM8510HandlerType->pllRate - pWM8510HandlerType->pll_N ) * ( float )0xFFFFFF );

	//---����ģʽ
	pWM8510HandlerType->nowR6[0] = ( 6 << 1 ) | 0x01;
	pWM8510HandlerType->nowR6[1] = ( UINT8_T )pWM8510HandlerType->mclkDIV << 5;
	pWM8510HandlerType->nowR6[1] |= ( UINT8_T )pWM8510HandlerType->bclkDIV << 2;
	pWM8510HandlerType->nowR6[1] |= 0x01;

	pWM8510HandlerType->nowR36[0] = 36 << 1;
	pWM8510HandlerType->nowR36[1] = ( pWM8510HandlerType->preDIV == 0 ) ? 0 : ( 1 << 4 );
	pWM8510HandlerType->nowR36[1] |= pWM8510HandlerType->pll_N;

	pWM8510HandlerType->nowR37[0] = 37 << 1;
	pWM8510HandlerType->nowR37[1] = ( UINT8_T )( ( pWM8510HandlerType->pll_K & 0xFC0000 ) >> 18 );

	pWM8510HandlerType->nowR38[0] = ( UINT8_T )( ( 38 << 1 ) | ( ( pWM8510HandlerType->pll_K & ( UINT32_T )0x20000 ) == 0 ? 0 : 1 ) );
	pWM8510HandlerType->nowR38[1] = ( UINT8_T )( ( pWM8510HandlerType->pll_K & 0x1FE00 ) >> 9 );

	pWM8510HandlerType->nowR39[0] = ( UINT8_T )( ( 39 << 1 ) | ( ( pWM8510HandlerType->pll_K & ( UINT32_T )0x100 ) == 0 ? 0 : 1 ) );
	pWM8510HandlerType->nowR39[1] = ( UINT8_T )( pWM8510HandlerType->pll_K & 0xFF );
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
void WM8510_IIC_ResetDevice( void )
{
	//---������������
	WM8510_SEND_CMD( pWM8510HandlerType->R0 );
	//---???��֪��Ϊʲô��R0�Ĵ��������ô���,��Ҫ��������
	WM8510_SEND_CMD( pWM8510HandlerType->R0 );
	//---���üĴ���R1
	WM8510_SEND_CMD( pWM8510HandlerType->R1 );
	//---����Ϊ0
	memset( pWM8510HandlerType->lastR6,  0, 2 );
	memset( pWM8510HandlerType->lastR36, 0, 2 );
	memset( pWM8510HandlerType->lastR37, 0, 2 );
	memset( pWM8510HandlerType->lastR38, 0, 2 );
	memset( pWM8510HandlerType->lastR39, 0, 2 );
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
void WM8510_IIC_SetFreqHz( UINT32_T freq )
{
	//---����Ŀ��Ƶ�ʵĳ�ֵ
	WM8510_Calc_PllRate( freq );
	//---R6�Ĵ���
	if (Compare_ByteArray( pWM8510HandlerType->nowR6, pWM8510HandlerType->lastR6, 2))
	{
		WM8510_SEND_CMD( pWM8510HandlerType->nowR6 );
		pWM8510HandlerType->lastR6[0] = pWM8510HandlerType->nowR6[0];
		pWM8510HandlerType->lastR6[1] = pWM8510HandlerType->nowR6[1];
	}
	//---R36�Ĵ���
	if (Compare_ByteArray(pWM8510HandlerType->nowR36,pWM8510HandlerType->lastR36,2))
	{
		WM8510_SEND_CMD( pWM8510HandlerType->nowR36 );
		pWM8510HandlerType->lastR36[0] = pWM8510HandlerType->nowR36[0];
		pWM8510HandlerType->lastR36[1] = pWM8510HandlerType->nowR36[1];
	}
	//---R37�Ĵ���
	if (Compare_ByteArray(pWM8510HandlerType->nowR37, pWM8510HandlerType->lastR37, 2))
	{
		WM8510_SEND_CMD( pWM8510HandlerType->nowR37 );
		pWM8510HandlerType->lastR37[0] = pWM8510HandlerType->nowR37[0];
		pWM8510HandlerType->lastR37[1] = pWM8510HandlerType->nowR37[1];
	}
	//---R38�Ĵ���
	if (Compare_ByteArray(pWM8510HandlerType->nowR38, pWM8510HandlerType->lastR38, 2))
	{
		WM8510_SEND_CMD( pWM8510HandlerType->nowR38 );
		pWM8510HandlerType->lastR38[0] = pWM8510HandlerType->nowR38[0];
		pWM8510HandlerType->lastR38[1] = pWM8510HandlerType->nowR38[1];
	}
	//---R39�Ĵ���
	if (Compare_ByteArray(pWM8510HandlerType->nowR39, pWM8510HandlerType->lastR39, 2))
	{
		WM8510_SEND_CMD( pWM8510HandlerType->nowR39 );
		pWM8510HandlerType->lastR39[0] = pWM8510HandlerType->nowR39[0];
		pWM8510HandlerType->lastR39[1] = pWM8510HandlerType->nowR39[1];
	}
}
///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
void WM8510_IIC_SetFreqKHz( float freqKHz )
{
	UINT32_T freq = ( UINT32_T )( freqKHz * 1000 );
	WM8510_IIC_SetFreqHz( freq );
}
///////////////////////////////////////////////////////////////////////////////
//////��	   ���� 
//////��	   �ܣ� 
//////�������: 
//////�������: 
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
void WM8510_IIC_SetFreqMHz( float freqMHz )
{
	UINT32_T freq = ( UINT32_T )( freqMHz * 1000000 );
	WM8510_IIC_SetFreqHz( freq );
}