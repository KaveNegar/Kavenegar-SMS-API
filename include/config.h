/****************************************************************************
*
* Created: 1/9/2017 by Ali Sepehri-Amin
* Version: 1.00
*
* Description:
*		The code and information provided "as-is" without
*		warranty of any kind, either expressed or implied.
*
* Purpose:
*       Compiler version config macro defination
*
***************************************************************************/

#ifndef __KAVENEGAR_CONFIG_H__
#define __KAVENEGAR_CONFIG_H__

#ifndef __BORLANDC__
#define __BORLANDC___CONFIG_GUARD	1
#else
#define __BORLANDC__CONFIG_GUARD	0
#endif
#ifndef _MSC_VER
#define _MSC_VER_CONFIG_GUARD		1
#else
#define _MSC_VER_CONFIG_GUARD		0
#endif
#ifndef _MSC_FULL_VER
#define _MSC_FULL_VER_CONFIG_GUARD	1
#else
#define _MSC_FULL_VER_CONFIG_GUARD	0
#endif
#ifndef __GNUC__
#define __GNUC___CONFIG_GUARD		1
#else
#define __GNUC___CONFIG_GUARD		0
#endif
#ifndef KAVENEGAR_MSVC
#define KAVENEGAR_MSVC_CONFIG_GUARD 1
#else
#define KAVENEGAR_MSVC_CONFIG_GUARD 0
#endif

#define KAVENEGAR_CONFIG(symbol, test)              \
         ((symbol ## _CONFIG_GUARD + 0 == 0) &&     \
         (symbol != 0) && (1 % (( (symbol test) ) + 1)))

#define KAVENEGAR_CONFIG(symbol, test) 0

#endif // __KAVENEGAR_CONFIG_H__