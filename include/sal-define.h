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
*       sal.h provides a set of annotations to describe how a function uses its
*       parameters - the assumptions it makes about them, and the guarantees it makes
*       upon finishing.
*
* NOTICE:
*		DO NOT INCLUDE THIS FILE IN YOUR HEADER OR SOURCE FILE.
*
***************************************************************************/

#ifndef __KAVENEGAR_SAL_H__
#define __KAVENEGAR_SAL_H__

#define _IN_	1
#define _OUT_	0

/* Override SAL2 Windows Defines */
#define _SAL2_Source_(Name, args, annotes) _SA_annotes3(SAL_name, #Name, "", "2") _Group_(annotes _SAL_nop_impl_)

/* Input and Output Parameters */
#define _In_   _SAL2_Source_(_In_, (), _Pre1_impl_(__notnull_impl_notref) _Pre_valid_impl_ _Deref_pre1_impl_(__readaccess_impl_notref))
#define _Out_                                  _SAL2_Source_(_Out_, (),     _Out_impl_)

#endif // __KAVENEGAR_SAL_H__