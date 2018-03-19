#ifndef __AD5593_LIB_H
#define __AD5593_LIB_H
#ifdef __cplusplus
extern "C"
{
	#endif
	//////////////////////////////////////////////////////////////////////////////////////
	#include "ad5593_cfg.h"

	//===º¯Êý¶¨Òå
	UINT8_T AD5593Lib_IIC_Init( void );
	UINT8_T AD5593Lib_IIC_CheckDevice( void );
	//////////////////////////////////////////////////////////////////////////////////////
	#ifdef __cplusplus
}
#endif
#endif /*__AD5593_LIB_H */
