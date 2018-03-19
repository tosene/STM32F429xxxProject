#ifndef __WM8510_LIB_H
#define __WM8510_LIB_H
#ifdef __cplusplus
extern "C" 
{
#endif
	//////////////////////////////////////////////////////////////////////////////////////
	#include "wm8510_cfg.h"
	
	//===º¯Êý¶¨Òå
	void WM8510Lib_Init( void );
	void WM8510Lib_ResetDevice();
	void WM8510Lib_SetFreqHz( UINT32_T freqHz );
	void WM8510Lib_SetFreqKHz( float freqKHz );
	void WM8510Lib_SetFreqMHz( float freqMHz );

	//////////////////////////////////////////////////////////////////////////////////////
#ifdef __cplusplus
}
#endif
#endif /*__WM8510_LIB_H */
