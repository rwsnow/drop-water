// UseDll.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"

//#pragma comment(lib,"InjectDll.lib")
//extern "C" __declspec(dllimport) void ExportFunction();  
//ExportFunction();
int main(int argc, char* argv[])
{
	typedef void ( *lpTest)();

	lpTest MyFunction;
	//加载DLL
	HINSTANCE   hModule = LoadLibrary("InjectDll.dll"); 

	//获取函数地址
	MyFunction = (lpTest)GetProcAddress(hModule,"ExportFunction");

	//调用函数
	MyFunction();

	//释放DLL
	FreeLibrary(hModule);
	
	
	return 0;
}

