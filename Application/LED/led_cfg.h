#ifndef __LED_CFG_H
#define __LED_CFG_H
#ifdef __cplusplus
extern "C"
{
	#endif
	//////////////////////////////////////////////////////////////////////////////////////
	#include "complier_lib.h"

	#define LED_WORK_PORT					GPIOF
	#define LED_WORK_BIT					LL_GPIO_PIN_2

	//===º¯Êý¶¨Òå
	UINT8_T LED_Init( void );
	UINT8_T LED_Work_Init( void );
	UINT8_T LED_Work_ON( void );
	UINT8_T LED_Work_OFF( void );
	UINT8_T LED_Work_Change( void );
	UINT8_T LED_RGB_Init( void );

	//////////////////////////////////////////////////////////////////////////////////////
	#ifdef __cplusplus
}
#endif
#endif /*__LED_CFG_H */
