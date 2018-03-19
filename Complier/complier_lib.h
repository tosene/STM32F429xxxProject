#ifndef __COMPLIER_LIB_H
#define __COMPLIER_LIB_H

#ifdef __cplusplus
extern "C" {
#endif 

	//---����ʹ�õ��ⲿ�����Ƶ��
	#define HSE_VALUE    ((UINT32_T)8000000U) /*!< Value of the External oscillator in Hz */

	//------------ʹ�ð�����ͷ�ļ�
	#include "stdbool.h"
	#include "stddef.h"
	#include "stdlib.h"
	#include "stdio.h"
	#include "string.h"
	#include "math.h"
	#include "stdarg.h"
	#include "stdint.h"
	#include "complier_cfg.h"
    
	///////////////////////////////////////////////////////////////////////////////
	//---�޷��ŵ�8λ����
	typedef	unsigned char						UINT8_T;
	typedef	unsigned char						U8;
	typedef	unsigned char						u8;
	typedef	unsigned char						uchar;

	typedef	volatile unsigned char				VLTUINT8_T;
	typedef	volatile unsigned char				vltuint8_t;
	typedef	volatile unsigned char				VLTU8;
	typedef	volatile unsigned char				vltu8;
	typedef	volatile unsigned char				vltuchar;

	//---�з��ŵ�8λ����
	typedef	signed   char						INT8_T;
	typedef	signed   char						S8;
	typedef	signed   char						s8;

	typedef	volatile signed char				VLTINT8_T;
	typedef	volatile signed char				vltint8_t;
	typedef	volatile signed char				VLTS8;
	typedef	volatile signed char				vlts8;

	//---�޷��ŵ�16λ����
	typedef	unsigned short int					UINT16_T;
	typedef	unsigned short int					U16;
	typedef	unsigned short int					u16;

	typedef	volatile unsigned short int			VLTUINT16_T;
	typedef	volatile unsigned short int			vltuint16_t;
	typedef	volatile unsigned short int			VLTU16;
	typedef	volatile unsigned int				vltu16;

	//---�з��ŵ�16λ����
	typedef	signed short int					INT16_T;
	typedef	signed short int					S16;
	typedef	signed short int					s16;

	typedef	volatile signed short int			VLTINT16_T;
	typedef	volatile signed short int			vltint16_t;
	typedef	volatile signed short int			VLTS16;
	typedef	volatile signed short int			vlts16;

	//---�޷��ŵ�32λ����
	typedef	unsigned int						UINT32_T;
	typedef	unsigned int						U32;
	typedef	unsigned int						u32;

	typedef	volatile unsigned int				VLTUINT32_T;
	typedef	volatile unsigned int				vltuint32_t;
	typedef	volatile unsigned int				VLTU32;
	typedef	volatile unsigned int				vltu32;

	//---�з��ŵ�32λ����						
	typedef	signed	int							INT32_T;
	typedef	signed	int							S32;
	typedef	signed	int							s32;

	typedef	volatile signed	int					VLTINT32_T;
	typedef	volatile signed	int					vltint32_t;
	typedef	volatile signed	int					VLTS32;
	typedef	volatile signed	int					vlts32;

	//---�޷��ŵ�64λ����
	typedef	unsigned long int					UINT64_T;
	typedef	unsigned long int					U64;
	typedef	unsigned long int					u64;

	typedef	volatile unsigned long int			VLTUINT64_T;
	typedef	volatile unsigned long int			vltuint64_t;
	typedef	volatile unsigned long int			VLTU64;
	typedef	volatile unsigned long int			vltu64;

	//---�з��ŵ�64λ����
	typedef	signed long int						INT64_T;
	typedef	signed long int						S64;
	typedef signed long int						s64;

	typedef	volatile signed long int			VLTINT64_T;
	typedef	volatile signed long int			vltint64_t;
	typedef	volatile signed long int			VLTS64;
	typedef	volatile signed long int			vlts64;

	//---�ֽ����޷�������---8
	typedef	unsigned char						ubyte;
	typedef	unsigned char						UByte;
	typedef	unsigned char						UBYTE;

	typedef	volatile unsigned char				vltubyte;
	typedef	volatile unsigned char				VLTUByte;
	typedef	volatile unsigned char				VLTUBYTE;

	//---�ֽ����з�������
	typedef	char								byte;
	typedef	char								Byte;
	typedef	char								BYTE;

	typedef	volatile char						vltbyte;
	typedef	volatile char						VLTByte;
	typedef	volatile char						VLTBYTE;

	//---�����޷�������--16
	typedef	unsigned short int					uword;
	typedef	unsigned short int					UWord;
	typedef	unsigned short int					UWORD;

	typedef	volatile unsigned short int			vltuword;
	typedef	volatile unsigned short int			VLTUWord;
	typedef	volatile unsigned short int			VLTUWORD;

	//---�����з�������--32
	typedef short int							word;
	typedef short int							Word;
	typedef short int							WORD;

	typedef	volatile short int					vltword;
	typedef	volatile short int					VLTWord;
	typedef	volatile short int					VLTWORD;

	//---˫�����޷�������--32
	typedef	unsigned int						udword;
	typedef	unsigned int						UDWord;
	typedef	unsigned int						UDWORD;

	typedef	volatile unsigned int				vltudword;
	typedef	volatile unsigned int				VLTUDWord;
	typedef	volatile unsigned int				VLTUDWORD;

	//---˫�����з�������--32
	typedef	unsigned int						dword;
	typedef	unsigned int						DWord;
	typedef	unsigned int						DWORD;

	typedef	volatile unsigned int				vltdword;
	typedef	volatile unsigned int				VLTDWord;
	typedef	volatile unsigned int				VLTDWORD;

	//===ʹ��16λ��������
	#define	USED_UNION16_BIT
	//===ʹ��32λ��������
	#define	USED_UNION32_BIT
	//===ʹ��64λ��������
	#define	USED_UNION64_BIT
	
	//===�޷��ŵ�������
	//---8bit�޷��ŵ�������
	typedef union
	{
		struct
		{
			UINT8_T bit0 : 1;
			UINT8_T bit1 : 1;
			UINT8_T bit2 : 1;
			UINT8_T bit3 : 1;
			UINT8_T bit4 : 1;
			UINT8_T bit5 : 1;
			UINT8_T bit6 : 1;
			UINT8_T bit7 : 1;
		};
		UINT8_T b;
	}UNION_UINT8_T;

	//---16bit�޷��ŵ�������
	typedef union
	{
	#ifdef USED_UNION16_BIT
		struct
		{
			UINT8_T bit0 : 1;
			UINT8_T bit1 : 1;
			UINT8_T bit2 : 1;
			UINT8_T bit3 : 1;
			UINT8_T bit4 : 1;
			UINT8_T bit5 : 1;
			UINT8_T bit6 : 1;
			UINT8_T bit7 : 1;
			UINT8_T bit8 : 1;
			UINT8_T bit9 : 1;
			UINT8_T bit10 : 1;
			UINT8_T bit11 : 1;
			UINT8_T bit12 : 1;
			UINT8_T bit13 : 1;
			UINT8_T bit14 : 1;
			UINT8_T bit15 : 1;
		};
	#endif // USED_UNION16_BIT

		UINT16_T w;
		UINT8_T  b[2];
	}UNION_UINT16_T;

	//---32bit�޷��ŵ�������
	typedef union
	{
	#ifdef USED_UNION32_BIT
		struct
		{
			UINT8_T bit0 : 1;
			UINT8_T bit1 : 1;
			UINT8_T bit2 : 1;
			UINT8_T bit3 : 1;
			UINT8_T bit4 : 1;
			UINT8_T bit5 : 1;
			UINT8_T bit6 : 1;
			UINT8_T bit7 : 1;
			UINT8_T bit8 : 1;
			UINT8_T bit9 : 1;
			UINT8_T bit10 : 1;
			UINT8_T bit11 : 1;
			UINT8_T bit12 : 1;
			UINT8_T bit13 : 1;
			UINT8_T bit14 : 1;
			UINT8_T bit15 : 1;
			UINT8_T bit16 : 1;
			UINT8_T bit17 : 1;
			UINT8_T bit18 : 1;
			UINT8_T bit19 : 1;
			UINT8_T bit20 : 1;
			UINT8_T bit21 : 1;
			UINT8_T bit22 : 1;
			UINT8_T bit23 : 1;
			UINT8_T bit24 : 1;
			UINT8_T bit25 : 1;
			UINT8_T bit26 : 1;
			UINT8_T bit27 : 1;
			UINT8_T bit28 : 1;
			UINT8_T bit29 : 1;
			UINT8_T bit30 : 1;
			UINT8_T bit31 : 1;
		};
	#endif // USED_UNION32_BIT

		UINT32_T dw;
		UINT16_T w[2];
		UINT8_T  b[4];
	}UNION_UINT32_T;

	//---64bit�޷��ŵ�������
	typedef union
	{
	#ifdef USED_UNION64_BIT
		struct
		{
			UINT8_T bit0 : 1;
			UINT8_T bit1 : 1;
			UINT8_T bit2 : 1;
			UINT8_T bit3 : 1;
			UINT8_T bit4 : 1;
			UINT8_T bit5 : 1;
			UINT8_T bit6 : 1;
			UINT8_T bit7 : 1;
			UINT8_T bit8 : 1;
			UINT8_T bit9 : 1;
			UINT8_T bit10 : 1;
			UINT8_T bit11 : 1;
			UINT8_T bit12 : 1;
			UINT8_T bit13 : 1;
			UINT8_T bit14 : 1;
			UINT8_T bit15 : 1;
			UINT8_T bit16 : 1;
			UINT8_T bit17 : 1;
			UINT8_T bit18 : 1;
			UINT8_T bit19 : 1;
			UINT8_T bit20 : 1;
			UINT8_T bit21 : 1;
			UINT8_T bit22 : 1;
			UINT8_T bit23 : 1;
			UINT8_T bit24 : 1;
			UINT8_T bit25 : 1;
			UINT8_T bit26 : 1;
			UINT8_T bit27 : 1;
			UINT8_T bit28 : 1;
			UINT8_T bit29 : 1;
			UINT8_T bit30 : 1;
			UINT8_T bit31 : 1;
			UINT8_T bit32 : 1;
			UINT8_T bit33 : 1;
			UINT8_T bit34 : 1;
			UINT8_T bit35 : 1;
			UINT8_T bit36 : 1;
			UINT8_T bit37 : 1;
			UINT8_T bit38 : 1;
			UINT8_T bit39 : 1;
			UINT8_T bit40 : 1;
			UINT8_T bit41 : 1;
			UINT8_T bit42 : 1;
			UINT8_T bit43 : 1;
			UINT8_T bit44 : 1;
			UINT8_T bit45 : 1;
			UINT8_T bit46 : 1;
			UINT8_T bit47 : 1;
			UINT8_T bit48 : 1;
			UINT8_T bit49 : 1;
			UINT8_T bit50 : 1;
			UINT8_T bit51 : 1;
			UINT8_T bit52 : 1;
			UINT8_T bit53 : 1;
			UINT8_T bit54 : 1;
			UINT8_T bit55 : 1;
			UINT8_T bit56 : 1;
			UINT8_T bit57 : 1;
			UINT8_T bit58 : 1;
			UINT8_T bit59 : 1;
			UINT8_T bit60 : 1;
			UINT8_T bit61 : 1;
			UINT8_T bit62 : 1;
			UINT8_T bit63 : 1;
		};
	#endif // USED_UNION64_BIT

		UINT64_T ddw;
		UINT32_T dw[2];
		UINT16_T w[4];
		UINT8_T  b[8];
	}UNION_UINT64_T;

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� static inline void descending_sort_byteArray(Uint8_t *pBuffer,Uint16_t length)
//////��	   �ܣ� ��������ָ�����ȵ�8λ������
//////�������: ����������Լ����ݳ���
//////�������: ��
//////˵	   ����
//////////////////////////////////////////////////////////////////////////////
static inline void Descending_SortByteArray(UINT8_T *pBuffer, UINT16_T length)
{
	UINT8_T val = 0;
	UINT16_T i = 0, j = 0;
	//---��������--����
	for ( i = 0; i < ( length - 1 ); i++ )
	{
		for ( j = i + 1; j < length; j++ )
		{
			if ( pBuffer[i] < pBuffer[j] )
			{
				val = pBuffer[i];
				pBuffer[i] = pBuffer[j];
				pBuffer[j] = val;
			}
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� static inline void descending_sort_wordArray(Uint16_t *pBuffer,Uint16_t length)
//////��	   �ܣ� ��������ָ�����ȵ�16λ������
//////�������: ����������Լ����ݳ���
//////�������: ��
//////˵	   ����
//////////////////////////////////////////////////////////////////////////////
static inline void Descending_SortWordArray(UINT16_T *pBuffer, UINT16_T length)
{
	UINT16_T i = 0, j = 0;
	UINT16_T val = 0;
	//---��������--����
	for ( i = 0; i < ( length - 1 ); i++ )
	{
		for ( j = i + 1; j < length; j++ )
		{
			if ( pBuffer[i] < pBuffer[j] )
			{
				val = pBuffer[i];
				pBuffer[i] = pBuffer[j];
				pBuffer[j] = val;
			}
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� static inline void ascending_sort_byteArray(Uint8_t *pBuffer,Uint16_t length)
//////��	   �ܣ� ��������ָ�����ȵ�8λ������
//////�������: ����������Լ����ݳ���
//////�������: ��
//////˵	   ����
//////////////////////////////////////////////////////////////////////////////
static inline void Ascending_SortByteArray(UINT8_T *pBuffer, UINT16_T length)
{
	UINT16_T i = 0, j = 0;
	UINT8_T val = 0;
	//---��������--����
	for ( i = 0; i < ( length - 1 ); i++ )
	{
		for ( j = i + 1; j < length; j++ )
		{
			if ( pBuffer[i] > pBuffer[j] )
			{
				val = pBuffer[i];
				pBuffer[i] = pBuffer[j];
				pBuffer[j] = val;
			}
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� static inline void ascending_sort_wordArray(Uint16_t *pBuffer,Uint16_t length)
//////��	   �ܣ� ��������ָ�����ȵ�16λ������
//////�������: ����������Լ����ݳ���
//////�������: ��
//////˵	   ����
//////////////////////////////////////////////////////////////////////////////
static inline void Ascending_SortWordArray(UINT16_T *pBuffer, UINT16_T length)
{
	UINT16_T i = 0, j = 0;
	UINT16_T val = 0;
	//---��������--����
	for ( i = 0; i < ( length - 1 ); i++ )
	{
		for ( j = i + 1; j < length; j++ )
		{
			if ( pBuffer[i] > pBuffer[j] )
			{
				val = pBuffer[i];
				pBuffer[i] = pBuffer[j];
				pBuffer[j] = val;
			}
		}
	}
}
///////////////////////////////////////////////////////////////////////////////
//////��	   ���� static inline Uint8_t calculation_averageValue_byteArray(Uint8_t *pBuf,Uint16_t startIndex,Uint16_t endIndex)
//////��	   �ܣ� ��ֵ����
//////�������:
//////�������:
//////˵	   ����
//////////////////////////////////////////////////////////////////////////////
static inline UINT8_T Calculation_AverageValueByteArray(UINT8_T *pBuf, UINT16_T startIndex, UINT16_T endIndex)
{
	UINT16_T i = 0;
	UINT16_T _return = 0;

	//---�ж����ݵĴ����Ƿ�Ϸ�
	if ( startIndex > endIndex )
	{
		return 1;
	}
	//---���ݴ���---���
	for ( i = startIndex; i < endIndex; i++ )
	{
		_return += pBuf[i];
	}
	//---��ֵ����---���ֵ
	startIndex = endIndex - startIndex;
	_return /= startIndex;

	//---���ػ�ȡ�ľ�ֵ
	return ( (UINT8_T)_return );
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� static inline Uint16_t calculation_averageValue_wordArray(Uint16_t *pBuf,Uint16_t startIndex,Uint16_t endIndex)
//////��	   �ܣ� ��ֵ����
//////�������:
//////�������:
//////˵	   ����
//////////////////////////////////////////////////////////////////////////////
static inline UINT16_T Calculation_AverageValueWordArray(UINT16_T *pBuf, UINT16_T startIndex, UINT16_T endIndex)
{
	UINT16_T i = 0;
	UINT32_T _return = 0;

	//---�ж����ݵĴ����Ƿ�Ϸ�
	if ( startIndex > endIndex )
	{
		return 1;
	}
	//---���ݴ���---���
	for ( i = startIndex; i < endIndex; i++ )
	{
		_return += pBuf[i];
	}
	//---��ֵ����---���ֵ
	startIndex = endIndex - startIndex;
	_return /= startIndex;

	//---���ػ�ȡ�ľ�ֵ
	return ( (UINT16_T)_return );
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� static inline Uint8_t Compare_ByteArray(Uint8_t *pBuf1,Uint8_t *pBuf2,Uint16_t length)
//////��	   �ܣ� �����ֽ�����Ƚϴ�С
//////�������:
//////�������: 0---��ȣ�1---�����
//////˵	   ����
//////////////////////////////////////////////////////////////////////////////
static inline UINT8_T Compare_ByteArray(UINT8_T *pBuffer1, UINT8_T *pBuffer2, UINT16_T length)
{
	UINT16_T i = 0;
	//---����Ƚϴ�С
	for ( i = 0; i < length; i++ )
	{
		if ( pBuffer2[i] != pBuffer1[i] )
		{
			return 1;
		}
	}
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� static inline UINT8_T Compare_ByteVal(UINT8_T *pBuffer1,UINT8_T val,UINT16_T index,UINT16_T length)
//////��	   �ܣ� �ж�ָ���������е������Ƿ�ȫ��Ϊָ����ֵ
//////�������: *pVal---����
//////			val----ָ����ֵ
//////			index---��ʼλ��
//////			lengh---�����ܳ���
//////�������:  0---��ȣ�1---�����
//////˵	   ����
//////////////////////////////////////////////////////////////////////////////
static inline UINT8_T Compare_ByteVal(UINT8_T *pBuffer1, UINT8_T val, UINT16_T index, UINT16_T length)
{
	UINT16_T i = 0;
	//---����Ƚϴ�С
	for ( i = index; i < length; i++ )
	{
		if ( pBuffer1[i] != val )
		{
			return 1;
		}
	}
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� static inline UINT8_T Compare_Byte(UINT8_T *pBuffer1,UINT8_T val,UINT16_T length)
//////��	   �ܣ� �ж�ָ���������е������Ƿ�ȫ��Ϊָ����ֵ
//////�������: *pVal---����
//////			val----ָ����ֵ
//////			lengh---�����ܳ���
//////�������:  0---��ȣ�1---�����
//////˵	   ����
//////////////////////////////////////////////////////////////////////////////
static inline UINT8_T Compare_Byte(UINT8_T *pBuffer1, UINT8_T val, UINT16_T length)
{
	return Compare_ByteVal(pBuffer1, val, 0, length);
}
///////////////////////////////////////////////////////////////////////////////
//////��	   ���� static inline Uint8_t Compare_WordArray(Uint16_t *pBuf1,Uint16_t *pBuf2,Uint16_t length)
//////��	   �ܣ� ����������Ƚϴ�С
//////�������:
//////�������: 0---��ȣ�1---�����
//////˵	   ����
//////////////////////////////////////////////////////////////////////////////
static inline UINT8_T Compare_WordArray(UINT16_T *pBuffer1, UINT16_T *pBuffer2, UINT16_T length)
{
	UINT16_T i = 0;
	//---����Ƚϴ�С
	for ( i = 0; i < length; i++ )
	{
		if ( pBuffer2[i] != pBuffer1[i] )
		{
			return 1;
		}
	}
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� static inline UINT8_T Compare_WordVal(UINT8_T *pBuffer1,UINT8_T val,UINT16_T index,UINT16_T length)
//////��	   �ܣ� �ж�ָ���������е������Ƿ�ȫ��Ϊָ����ֵ
//////�������: *pVal---����
//////			val----ָ����ֵ
//////			index---��ʼλ��
//////			lengh---�����ܳ���
//////�������: 0---��ȣ�1---�����
//////˵	   ����
//////////////////////////////////////////////////////////////////////////////
static inline UINT8_T Compare_WordVal(UINT16_T *pBuffer1, UINT16_T val, UINT16_T index, UINT16_T length)
{
	UINT16_T i = 0;
	//---����Ƚϴ�С
	for ( i = index; i < length; i++ )
	{
		if ( pBuffer1[i] != val )
		{
			return 1;
		}
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////
//////��	   ���� static inline UINT8_T Compare_Word(UINT16_T *pBuffer1, UINT16_T val,UINT16_T length)
//////��	   �ܣ� �ж�ָ���������е������Ƿ�ȫ��Ϊָ����ֵ
//////�������: *pVal---����
//////			val----ָ����ֵ
//////			lengh---�����ܳ���
//////�������: 0---��ȣ�1---�����
//////˵	   ����
//////////////////////////////////////////////////////////////////////////////
static inline UINT8_T Compare_Word(UINT16_T *pBuffer1, UINT16_T val, UINT16_T length)
{
	return Compare_WordVal(pBuffer1, val, 0, length);
}
///////////////////////////////////////////////////////////////////////////////
//////��	   ����static inline UINT8_T GetByteBitOneCount(UINT8_T val)
//////��	   �ܣ� ��ȡbitλ��1�ĸ���
//////��������� val---����������(�ֽ�)
//////�������: ������bitλ��1�ĸ���
//////˵	   ����
//////////////////////////////////////////////////////////////////////////////
static inline UINT8_T GetByteBitOneCount(UINT8_T val)
{
	UINT8_T temp = val;
	temp = ( temp & 0x55 ) + ( ( temp & 0xAA ) >> 1 );
	temp = ( temp & 0x33 ) + ( ( temp & 0xCC ) >> 2 );
	temp = ( temp & 0x0F ) + ( ( temp & 0xF0 ) >> 4 );
	return temp;
}
///////////////////////////////////////////////////////////////////////////////
//////��	   ����static inline UINT8_T GetWordBitOneCount(UINT8_T val)
//////��	   �ܣ� ��ȡbitλ��1�ĸ���
//////��������� val---����������(��)
//////�������: ������bitλ��1�ĸ���
//////˵	   ����
//////////////////////////////////////////////////////////////////////////////
static inline UINT8_T GetWordBitOneCount(UINT16_T val)
{
	int temp = val;
	temp = ( temp & 0x5555 ) + ( ( temp & 0xAAAA ) >> 1 );
	temp = ( temp & 0x3333 ) + ( ( temp & 0xCCCC ) >> 2 );
	temp = ( temp & 0x0F0F ) + ( ( temp & 0xF0F0 ) >> 4 );
	temp = ( temp & 0x00FF ) + ( ( temp & 0xFF00 ) >> 8 );
	return (UINT8_T)temp;
}
///////////////////////////////////////////////////////////////////////////////
//////��	   ����static inline UINT8_T GetDoubleWordBitOneCount(UINT32_T val)
//////��	   �ܣ� ��ȡbitλ��1�ĸ���
//////��������� val---����������(��)
//////�������: ������bitλ��1�ĸ���
//////˵	   ����
//////////////////////////////////////////////////////////////////////////////
static inline UINT8_T GetDoubleWordBitOneCount(UINT32_T val)
{
	long temp = val;
	temp = ( temp & 0x55555555 ) + ( ( temp & 0xaaaaaaaa ) >> 1 );
	temp = ( temp & 0x33333333 ) + ( ( temp & 0xcccccccc ) >> 2 );
	temp = ( temp & 0x0f0f0f0f ) + ( ( temp & 0xf0f0f0f0 ) >> 4 );
	temp = ( temp & 0x00ff00ff ) + ( ( temp & 0xff00ff00 ) >> 8 );
	temp = ( temp & 0x0000ffff ) + ( ( temp & 0xffff0000 ) >> 16 );
	return (UINT8_T)temp;
}
///////////////////////////////////////////////////////////////////////////////
//////��	   ���� static inline Uint16_t GetWordVal(Uint8_t valH,Uint8_t valL)
//////��	   �ܣ� ������8λ�����ݺϳ�һ��16λ�����ݣ���λ��ǰ����λ�ں�
//////�������:
//////�������:
//////˵	   ����
//////////////////////////////////////////////////////////////////////////////
static inline INT16_T _getWordVal(INT8_T valH, INT8_T valL)
{
	INT16_T _return = valH;
	_return = ( _return << 8 ) + valL;
	return _return;
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ���� static inline void GetWordArrayToByteArray(UINT16_T *pWordVal,UINT16_T length,UINT8_T *pByteVal)
//////��	   �ܣ� ��ָ�����ȵ�������ת�����ֽ�����
//////�������: 
//////�������: ��
//////˵	   ���� 
//////////////////////////////////////////////////////////////////////////////
static inline void GetWordArrayToByteArray(UINT16_T *pWordVal, UINT16_T length, UINT8_T *pByteVal)
{
	UINT16_T i = 0;
	for ( i = 0; i < length; i++ )
	{
		*pByteVal = (UINT8_T)( pWordVal[i] >> 8 );
		pByteVal++;
		*pByteVal = (UINT8_T)( pWordVal[i] & 0xFF );
		pByteVal++;
	}
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ����static inline UINT8_T BCD_ToHex(UINT8_T bcdVal)
//////��	   �ܣ���BCD��ʽ������ת����16����
//////�������: 
//////�������: 
//////˵	   ����
//////////////////////////////////////////////////////////////////////////////
static inline UINT8_T BCD_ToHex(UINT8_T bcdVal)
{
	UINT8_T _return = 0;
	_return = ( bcdVal % 16 + ( bcdVal / 16 ) * 10 );
	return _return;
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ����static inline UINT8_T Hex_ToBCD( UINT8_T hexVal )
//////��	   �ܣ���16���Ƶ�����ת����BCD��ʽ
//////�������: 
//////�������: 
//////˵	   ����
//////////////////////////////////////////////////////////////////////////////
static inline UINT8_T Hex_ToBCD(UINT8_T hexVal)
{
	UINT8_T _return = 0;
	_return = ( hexVal % 10 + ( hexVal / 10 ) * 16 );
	return _return;
}

///////////////////////////////////////////////////////////////////////////////
//////��	   ����static inline UINT8_T Calculation_CheckSumByteArray(UINT8_T *pBuf,UINT16_T length)
//////��	   �ܣ�������������У�����Ϣ
//////�������: 
//////�������: �����У��ͽ��
//////˵	   ����
//////////////////////////////////////////////////////////////////////////////
static inline UINT8_T Calculation_CheckSumByteArray(UINT8_T *pBuf, UINT16_T length)
{
	UINT8_T _return = 0;
	UINT16_T i = 0;
	for ( i = 0; i < length; i++ )
	{
		_return += pBuf[i];
	}
	_return = (UINT8_T)( 0x100 - _return );
	return _return;
}

//===��������
static inline void Descending_SortByteArray(UINT8_T *pBuffer, UINT16_T length);
static inline void Descending_SortWordArray(UINT16_T *pBuffer, UINT16_T length);
static inline void Ascending_SortByteArray(UINT8_T *pBuffer, UINT16_T length);
static inline void Ascending_SortWordArray(UINT16_T *pBuffer, UINT16_T length);
static inline UINT8_T Calculation_AverageValueByteArray(UINT8_T *pBuf, UINT16_T startIndex, UINT16_T endIndex);
static inline UINT16_T Calculation_AverageValueWordArray(UINT16_T *pBuf, UINT16_T startIndex, UINT16_T endIndex);
static inline UINT8_T Compare_ByteArray(UINT8_T *pBuffer1, UINT8_T *pBuffer2, UINT16_T length);
static inline UINT8_T Compare_ByteVal(UINT8_T *pBuffer1, UINT8_T val, UINT16_T index, UINT16_T length);
static inline UINT8_T Compare_Byte(UINT8_T *pBuffer1, UINT8_T val, UINT16_T length);
static inline UINT8_T Compare_WordArray(UINT16_T *pBuffer1, UINT16_T *pBuffer2, UINT16_T length);
static inline UINT8_T Compare_WordVal(UINT16_T *pBuffer1, UINT16_T val, UINT16_T index, UINT16_T length);
static inline UINT8_T Compare_Word(UINT16_T *pBuffer1, UINT16_T val, UINT16_T length);
static inline UINT8_T GetByteBitOneCount(UINT8_T val);
static inline UINT8_T GetWordBitOneCount(UINT16_T val);
static inline UINT8_T GetDoubleWordBitOneCount(UINT32_T val);
static inline INT16_T _getWordVal(INT8_T valH, INT8_T valL);
static inline void GetWordArrayToByteArray(UINT16_T *pWordVal, UINT16_T length, UINT8_T *pByteVal);
static inline UINT8_T BCD_ToHex(UINT8_T bcdVal);
static inline UINT8_T Hex_ToBCD(UINT8_T hexVal);
static inline UINT8_T Calculation_CheckSumByteArray(UINT8_T *pBuf, UINT16_T length);

//===�������ڴ��б����˳��
//---�������ֽڴ洢����ʼ��ַ����λ��ַ��,��λ��ǰ����λ�ں�
#define	LITTLE_ENDIAN
//---�������ֽڴ洢����ʼ��ַ����λ��ַ��,��λ��ǰ����λ�ں�
//#define BIG_ENDIAN

//===���ݶ��䷽ʽ��Ĭ����С�˶���
#ifdef	LITTLE_ENDIAN
	// => 16bit: (LSB,MSB), 32bit: (LSW,MSW) or (LSB0,LSB1,LSB2,LSB3) or (MSB3,MSB2,MSB1,MSB0)
	#define	LSB(val)							( ((UINT8_T*)&val)[0] )
	#define	MSB(val)							( ((UINT8_T*)&val)[1] )
	
	#define	MSW(val)							( ((UINT16_T*)&val)[1] )
	#define	LSW(val)							( ((UINT16_T*)&val)[0] )
	
	//---��λ��ǰ
	#define	MSW0(val)							( ((UINT8_T*)&val)[3] )
	#define	MSW1(val)							( ((UINT8_T*)&val)[2] )
	#define	MSW2(val)							( ((UINT8_T*)&val)[1] )
	#define	MSW3(val)							( ((UINT8_T*)&val)[0] )
	
	//---��λ��ǰ
	#define	LSW0(val)							MSW3(val)
	#define	LSW1(val)							MSW2(val)
	#define	LSW2(val)							MSW1(val)
	#define	LSW3(val)							MSW0(val)
#else	// BIG_ENDIAN
	#define	LSB(val)							( ((UINT8_T*)&val)[1] )
	#define	MSB(val)							( ((UINT8_T*)&val)[0] )
	#define	MSW(val)							( ((UINT8_T*)&val)[1] )
	#define	LSW(val)							( ((UINT8_T*)&val)[0] )
	
	#define	MSW0(val)							( ((UINT8_T*)&val)[0] )
	#define	MSW1(val)							( ((UINT8_T*)&val)[1] )
	#define	MSW2(val)							( ((UINT8_T*)&val)[2] )
	#define	MSW3(val)							( ((UINT8_T*)&val)[3] )
	
	#define	LSW0(val)							MSW3(val)
	#define	LSW1(val)							MSW2(val)
	#define	LSW2(val)							MSW1(val)
	#define	LSW3(val)							MSW0(val)
#endif

//===�޷������ݵ�16λ����
#define	SWAP_WORD(x)							( (((x)>>8)&0x00FF)|(((x)<<8)&0xFF00 ) 
//===�޷������ݵ�32λ����
#define	SWAP_DWORD(val)							( ( (UINT32_T)((val)&0xFF)<<24 )|( (UINT32_T)( (UINT16_T)(val)&0xFF00 )<<8 )|\
												( ( (UINT32_T)(val)&0xFF0000)>>8 )|( ( (UINT32_T)(val)&0xFF000000 )>>24 ) )
//===�����޷���8λ���ݣ��ϳ�һ���޷��ŵ�16λ����
#define	MAKE_WORD(VH,VL)						_getWordVal(VH,VL)
///////////////////////////////////////////////////////////////////////////////

///----------------
void _Error_Handler(char *, int);
#define Error_Handler()		 _Error_Handler(__FILE__, __LINE__)

#ifdef USE_FULL_ASSERT
	void assert_failed(uint8_t* file, uint32_t line);
	#define assert_param(expr) ((expr) ? (void)0U : assert_failed((uint8_t *)__FILE__, __LINE__))
#else
	 #define assert_param(expr) ((void)0U)
#endif

//===����ָ��----Ϊ��ͳһ����
typedef UINT8_T(*FuncType)( UINT8_T *, UINT8_T * );

//#include "complier_cfg.h"

#ifdef __cplusplus
}
#endif

#endif /* __COMPLIER_LIB_H */
