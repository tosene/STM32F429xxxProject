#ifndef __DELAY_TASK_H
#define __DELAY_TASK_H

#ifdef __cplusplus
extern "C" {
	#endif 

	///------------使用包含的头文件
	#include "delay_cfg.h"
	///////////////////////////////////////////////////////////////////////////////
	void DelayTask_us( UINT32_T us );
	void DelayTask_ms( UINT32_T ms );
	void DelayTask_s( UINT32_T s );
	void DelayTask_nop( UINT32_T nop );
	void DelayTask_1us( UINT32_T us );
	///////////////////////////////////////////////////////////////////////////////

	#ifdef __cplusplus
}
#endif

#endif /* __DELAY_TASK_H */