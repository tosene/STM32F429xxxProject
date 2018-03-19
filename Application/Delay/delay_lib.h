#ifndef __DELAY_LIB_H
#define __DELAY_LIB_H

#ifdef __cplusplus
extern "C" {
#endif 

	///------------使用包含的头文件
	#include "delay_cfg.h"
	///////////////////////////////////////////////////////////////////////////////
	void DelayLib_us( UINT32_T us );
	void DelayLib_ms( UINT32_T ms );
	void DelayLib_s( UINT32_T s );
	void DelayNLib_us(UINT32_T us);
	void DelayNLib_ms(UINT32_T ms);
	void DelayNLib_s(UINT32_T s);
	void DelayLib_nop(UINT32_T nop);
	void DelayLib_1us(UINT32_T us);
	void HAL_Delay(UINT32_T ms);
	///////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

#endif /* __DELAY_LIB_H */