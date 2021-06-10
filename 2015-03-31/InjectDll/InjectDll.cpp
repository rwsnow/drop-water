// InjectDll.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "MyDll.h"
BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		Init();
		break;
	case DLL_PROCESS_DETACH:
		Destroy();
		break;
    }
    return TRUE;
}

