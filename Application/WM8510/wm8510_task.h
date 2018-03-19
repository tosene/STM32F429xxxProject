#ifndef __WM8510_TASK_H
#define __WM8510_TASK_H
#ifdef __cplusplus
extern "C"
{
#endif
	//////////////////////////////////////////////////////////////////////////////////////
	#include "wm8510_lib.h"

	//===º¯Êý¶¨Òå
	void WM8510Task_Init( void );
	void WM8510Task_ResetDevice();
	void WM8510Task_SetFreqHz( UINT32_T freqHz );
	void WM8510Task_SetFreqKHz( float freqKHz );
	void WM8510Task_SetFreqMHz( float freqMHz );

	//////////////////////////////////////////////////////////////////////////////////////
	#ifdef __cplusplus
}
#endif
#endif /*__WM8510_TASK_H */
