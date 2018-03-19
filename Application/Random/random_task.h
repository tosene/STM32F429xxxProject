#ifndef __RANDOM_TASK_H
#define __RANDOM_TASK_H

#ifdef __cplusplus
extern "C" {
#endif 

	///------------使用包含的头文件
#include "random_lib.h"
	///////////////////////////////////////////////////////////////////////////////
	void RandomTask_Init(void);
	void RandomTask_DeInit(void);
	UINT32_T RandomTask_GetData(void);
	UINT32_T RandomTask_GetRang(UINT32_T minVal, UINT32_T maxVal);
	///////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

#endif /* __RANDOM_TASK_H */