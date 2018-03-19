#ifndef __EEPROM_CFG_H
#define __EEPROM_CFG_H
#ifdef __cplusplus
extern "C"
{
	#endif
	//////////////////////////////////////////////////////////////////////////////////////
	#include "complier_lib.h"
	#include "iic_lib.h"

	//===宏定义
	#define AT24C01				127
	#define AT24C02				255
	#define	AT24C04				512
	#define AT24C08				1023
	#define AT24C16				2047

	#define AT24CXX_ADDR		0xA0
	#define AT24CXX_TYPE		AT24C08
	//===函数定义

	//////////////////////////////////////////////////////////////////////////////////////
	#ifdef __cplusplus
}
#endif
#endif /*__EEPROM_CFG_H */
