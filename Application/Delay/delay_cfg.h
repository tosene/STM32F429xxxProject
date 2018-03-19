#ifndef __DELAY_CFG_H
#define __DELAY_CFG_H
#ifdef __cplusplus
extern "C"
{
	#endif
	//////////////////////////////////////////////////////////////////////////////////////
	#include "systick_lib.h"
	//===º¯Êý¶¨Òå
	void Delay_us( UINT32_T us );
	void Delay_ms( UINT32_T ms );
	void Delay_s( UINT32_T s );
	void DelayN_us( UINT32_T us );
	void DelayN_ms( UINT32_T ms );
	void DelayN_s( UINT32_T s );
	void Delay_nop( UINT32_T nop );
	void Delay_1us( UINT32_T us );
	void HAL_Delay( UINT32_T ms );
	//////////////////////////////////////////////////////////////////////////////////////
	#ifdef __cplusplus
}
#endif
#endif /*__DELAY_CFG_H */
