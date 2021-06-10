// Tools.h: interface for the Tools class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLS_H__16F2B0E1_C614_49AE_A5C4_1C58B76F50AC__INCLUDED_)
#define AFX_TOOLS_H__16F2B0E1_C614_49AE_A5C4_1C58B76F50AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


void __cdecl OutputDebugStringF(const char *format, ...); 

#ifdef _DEBUG  
#define DbgPrintf   OutputDebugStringF  
#else  
#define DbgPrintf  
#endif 




#endif // !defined(AFX_TOOLS_H__16F2B0E1_C614_49AE_A5C4_1C58B76F50AC__INCLUDED_)
