// MyDll.h: interface for the MyDll class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYDLL_H__A5631B62_A8CF_4C84_B164_75BDD6108880__INCLUDED_)
#define AFX_MYDLL_H__A5631B62_A8CF_4C84_B164_75BDD6108880__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

void Init();
void Destroy();
extern "C" _declspec(dllexport) void ExportFunction();  


#endif // !defined(AFX_MYDLL_H__A5631B62_A8CF_4C84_B164_75BDD6108880__INCLUDED_)
