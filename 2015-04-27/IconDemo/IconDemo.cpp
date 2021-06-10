// IconDemo.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"
HINSTANCE hAppInstance;
BOOL CALLBACK MainDlgProc(HWND hDlg,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	BOOL bRet = TRUE;
	HICON hIconSmall;
	HICON hIconBig;
	switch(uMsg)
	{
	case WM_INITDIALOG :
		  hIconSmall = LoadIcon (hAppInstance, MAKEINTRESOURCE (IDI_ICON_SMALL));
		  hIconBig = LoadIcon (hAppInstance, MAKEINTRESOURCE (IDI_ICON_BIG));
		  //…Ë÷√Õº±Í
		  SendMessage(hDlg,WM_SETICON,ICON_BIG,(DWORD)hIconBig);
		  SendMessage(hDlg,WM_SETICON,ICON_SMALL,(DWORD)hIconSmall);
		
          return 0 ;
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case IDC_BUTTON_OUT:
			EndDialog(hDlg,0);
			break;
		default:
			bRet = FALSE;
			break;
		}
		break;
	
	default:
			bRet = FALSE;
			break;
	}
	
	return bRet;
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	hAppInstance = hInstance;

	DialogBox(hInstance,MAKEINTRESOURCE(IDD_DIALOG_MAIN),NULL,MainDlgProc);

	return 0;
}



