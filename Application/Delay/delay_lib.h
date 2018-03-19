#ifndef __DELAY_LIB_H
#define __DELAY_LIB_H

#ifdef __cplusplus
extern "C" {
#endif 

	///------------使用包含的头文件
	#include "systick_lib.h"
	///////////////////////////////////////////////////////////////////////////////
	void Delay_us( UINT32_T us );
	void Delay_ms( UINT32_T ms );
	void Delay_s( UINT32_T s );
	void DelayN_us(UINT32_T us);
	void DelayN_ms(UINT32_T ms);
	void DelayN_s(UINT32_T s);
	void Delay_nop(UINT32_T nop);
	void Delay_1us(UINT32_T us);
	void HAL_Delay(UINT32_T ms);
	///////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

#endif /* __DELAY_LIB_H */