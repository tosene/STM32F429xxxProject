#ifndef __USART_CFG_H
#define __USART_CFG_H

#ifdef __cplusplus
extern "C" {
#endif 

///------------ʹ�ð�����ͷ�ļ�
#include "gpio_cfg.h"
///////////////////////////////////////////////////////////////////////////////

	//===����ʹ�õĴ�����Ϣ
#define USART1_HandlerType					pUSART1
#define USART2_HandlerType					NULL
#define USART3_HandlerType					NULL
#define USART4_HandlerType					NULL
#define USART5_HandlerType					NULL
#define USART6_HandlerType					NULL
#define USART7_HandlerType					NULL
#define USART8_HandlerType					NULL
#define USART9_HandlerType					NULL
#define USART10_HandlerType					NULL
#define CMD_PRINTF_BUFFER_LEN				511

	//===ʹ����Ϣ�崦�����===============
//---��Ϣ�������
#define USART_MSG_Init						1
#define USART_MSG_Deinit					2
#define USART_MSG_IT_TXE					3
#define USART_MSG_IT_TC						4
#define USART_MSG_IT_RXNE					5
#define USART_MSG_IT_IDLE					6
#define USART_MSG_GPIO_Init					7
#define USART_MSG_Transmite					8
#define USART_MSG_Receive					9
#define USART_MSG_BandRate					10
#define USART_MSG_DataWidth					11
#define USART_MSG_SetParity					12
#define USART_MSG_SetStopBits				13
#define USART_MSG_RXNE_Handler				14
#define USART_MSG_TXE_Handler				15
#define USART_MSG_TC_Handler				16
#define USART_MSG_IDLE_Handler				17
#define USART_MSG_TXE_Byte_Transmite		18
#define USART_MSG_TXE_ByteCrc_Transmite		19
#define USART_MSG_TXE_Data_Transmite		20
#define USART_MSG_TXE_DataCrc_Transmite		21
#define USART_MSG_RX_HandlerInit			22

	//---TX�˿ڵ�����
#define USART_TxPin_SET_INPUT				0
#define USART_TxPin_SET_OUTPUT				1

	//---���崮���Զ���Э��ı�ͷ�ͱ�β
	typedef enum
	{
		USART1_RECE_HEADER	 = 0x55,
		USART1_SEND_HEADER	 = 0x5A,
		USART1_BANDRATE_VAL	 = 115200,
	}USART_CustomProtocol;

	//---�������ݴ���ṹ�嶨��
	typedef struct _USART_RxHandlerTypeDef
	{
		UINT8_T		rxIndex;										//---���
		UINT8_T		rxCount;										//---�������ݳ���
		UINT8_T		rxCrcVal;										//---У���
		UINT8_T		rxCrcFlag;										//---У���־λ
		VLTUINT8_T	rxStep;											//---����
		UINT16_T	rxBufferDataSize;								//---���ݻ������Ĵ�С
		UINT8_T		*pRxBuffer;										//---������
	}USART_RxHandlerType, *pUSART_RxHandlerType;

	//---�������ݽṹ�嶨��
	typedef struct _USART_TxHandlerTypeDef
	{
		UINT8_T		txIndex;										//---д�����
		UINT8_T		txNum;											//---�������
		UINT8_T		txCount;										//---�ܳ�
		UINT8_T		txCrcVal;										//---У���
		UINT8_T		txCrcFlag;										//---У���־λ 0---����У��ͣ�1---������У���
		VLTUINT8_T	txStep;											//---����
		UINT16_T	txBufferDataSize;								//---���ݻ������Ĵ�С
		UINT8_T		*pTxBuffer;										//---������
	}USART_TxHandlerType, *pUSART_TxHandlerType;
	
	//---�����ṹ��
	typedef struct _USART_HandlerTypeDef  USART_HandlerType;
	//---����ָ��ṹ��
	typedef struct _USART_HandlerTypeDef  *pUSART_HandlerType;
	//---������Ϣ����ָ�뺯��
	typedef UINT8_T (*USART_MSG_HandlerType)( USART_HandlerType *USARTxHandlerType, UINT32_T val, UINT8_T msg );
	
	//---������Ϣ�崦�������
	struct _USART_HandlerTypeDef
	{
		VLTUINT8_T				USARTxRxHeader;						//���ձ�ͷ
		VLTUINT8_T				USARTxTxHeader;						//���ͱ�ͷ
		UINT32_T				USARTxTimeOut;						//��ʱʱ��
		UINT32_T				USARTxTxPin;						//���Ͷ˿�
		GPIO_TypeDef			*USARTxGPIOx;						//USART�˿ں�
		USART_TypeDef			*USARTxCOM;							//USART�˿�
		USART_TxHandlerType		USARTxTxHandlerType;				//���ͺ���
		USART_RxHandlerType		USARTxRxHandlerType;				//���պ���
		USART_MSG_HandlerType	USART_MSG_Task;						//��Ϣ������
	};
	//---���崮����Ϣ�Ľṹ���ָ��ṹ��
	extern USART_HandlerType  g_USART1;
	extern pUSART_HandlerType pUSART1;
    
	//===��������
	void USART_EnableClock(USART_TypeDef *USARTx);
	void USART_DisableClock(USART_TypeDef *USARTx);
	UINT8_T USART_HandlerType_IT_TC(USART_HandlerType *USARTxHandlerType, UINT8_T msg);
	UINT8_T USART_HandlerType_IT_TXE(USART_HandlerType *USARTxHandlerType, UINT8_T msg);
	UINT8_T USART_HandlerType_IT_RXNE(USART_HandlerType *USARTxHandlerType, UINT8_T msg);
	UINT8_T USART_HandlerType_IT_IDLE(USART_HandlerType *USARTxHandlerType, UINT8_T msg);
	UINT8_T USART_HandlerType_GPIO_SetPinMode(USART_HandlerType *USARTxHandlerType, UINT32_T msg);
	UINT8_T USART_HandlerType_TransmitData8(USART_HandlerType *USARTxHandlerType, UINT8_T msg);
	UINT8_T USART_HandlerType_TransmitData9(USART_HandlerType *USARTxHandlerType, UINT16_T msg);
	UINT8_T USART_HandlerType_ReceiveData8(USART_HandlerType *USARTxHandlerType);
	UINT16_T USART_HandlerType_ReceiveData9(USART_HandlerType *USARTxHandlerType);
	UINT8_T USART_HandlerType_SetBandRate(USART_HandlerType *USARTxHandlerType, UINT32_T bandRate);
	UINT8_T USART_HandlerType_SetDataWidth(USART_HandlerType *USARTxHandlerType, UINT32_T dataWidth);
	UINT8_T USART_HandlerType_SetParity(USART_HandlerType *USARTxHandlerType, UINT32_T Parity);
	UINT8_T USART_HandlerType_SetStopBits(USART_HandlerType *USARTxHandlerType, UINT32_T StopBits);
	UINT8_T USART_HandlerType_DeInit(USART_HandlerType *USARTxHandlerType);
	UINT8_T USART_HandlerType_StructInit( USART_HandlerType *USARTxHandlerType );
	UINT8_T USART_HandlerType_Init(USART_HandlerType *USARTxHandlerType);
	UINT8_T USART1_HandlerType_Init(USART_HandlerType *USARTxHandlerType);
	UINT8_T USART2_HandlerType_Init( USART_HandlerType *USARTxHandlerType );
	UINT8_T USART3_HandlerType_Init( USART_HandlerType *USARTxHandlerType );
	UINT8_T USART4_HandlerType_Init( USART_HandlerType *USARTxHandlerType );
	UINT8_T USART5_HandlerType_Init( USART_HandlerType *USARTxHandlerType );
	UINT8_T USART6_HandlerType_Init( USART_HandlerType *USARTxHandlerType );
	UINT8_T USART7_HandlerType_Init( USART_HandlerType *USARTxHandlerType );
	UINT8_T USART8_HandlerType_Init( USART_HandlerType *USARTxHandlerType );
	UINT8_T USART9_HandlerType_Init( USART_HandlerType *USARTxHandlerType );
	UINT8_T USART10_HandlerType_Init( USART_HandlerType *USARTxHandlerType );
	void USART_HandlerType_Printf(USART_HandlerType *USARTxHandlerType, char *fmt, ...);
	///////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

#endif /* __USART_CFG_H */