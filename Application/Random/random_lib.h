#ifndef __RANDOM_LIB_H
#define __RANDOM_LIB_H

#ifdef __cplusplus
extern "C" {
#endif 

	///------------使用包含的头文件
#include "random_cfg.h"
	///////////////////////////////////////////////////////////////////////////////
	void RandomLib_Init(void);
	void RandomLib_DeInit(void);
	UINT32_T RandomLib_GetData(void);
	UINT32_T RandomLib_GetRang(UINT32_T minVal, UINT32_T maxVal);
	///////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

#endif /* __RANDOM_LIB_H */