#ifndef __AD5593_TASK_H
#define __AD5593_TASK_H
#ifdef __cplusplus
extern "C"
{
	#endif
	//////////////////////////////////////////////////////////////////////////////////////
	#include "ad5593_lib.h"

	//===º¯Êý¶¨Òå
	UINT8_T AD5593Task_IIC_Init( void );
	UINT8_T AD5593Task_IIC_CheckDevice( void );
	UINT8_T AD5593Task_IIC_DACRead( UINT8_T channel, UINT8_T *pVal );
	//////////////////////////////////////////////////////////////////////////////////////
	#ifdef __cplusplus
}
#endif
#endif /*__AD5593_TASK_H */
