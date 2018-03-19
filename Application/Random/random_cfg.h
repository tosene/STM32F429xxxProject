#ifndef __RANDOM_CFG_H
#define __RANDOM_CFG_H

#ifdef __cplusplus
extern "C" {
#endif 

	///------------ʹ�ð�����ͷ�ļ�
	#include "complier_lib.h"
	///////////////////////////////////////////////////////////////////////////////
	//===��������
	void Random_Init(void);
	void Random_DeInit(void);
	UINT32_T Random_GetData(void);
	UINT32_T Random_GetRang(UINT32_T minVal, UINT32_T maxVal);
	///////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

#endif /* __RANDOM_CFG_H */