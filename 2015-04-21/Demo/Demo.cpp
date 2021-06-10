// Demo.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Tools.h"

HINSTANCE hAppInstance;

LRESULT CALLBACK WindowProc(  
	IN  HWND hwnd,  
	IN  UINT uMsg,  
	IN  WPARAM wParam,  
	IN  LPARAM lParam  
	);  


int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	hAppInstance = hInstance;
	
	//窗口的类名
	PSTR className = "My First Window"; 
	
	// 创建窗口类的对象 
	WNDCLASS wndclass = {0};						//一定要先将所有值赋值
	wndclass.hbrBackground = (HBRUSH)COLOR_MENU;	//窗口的背景色
	wndclass.hCursor = LoadCursor(NULL,IDC_APPSTARTING);	
	wndclass.lpfnWndProc = WindowProc;				//窗口过程函数
	wndclass.lpszClassName = className;				//窗口类的名字	
	wndclass.hInstance = hInstance;					//定义窗口类的应用程序的实例句柄

	
	// 注册窗口类  
	// 参加MSDN文档RegisterClass->Parameters：
	// You must fill the structure with the appropriate class attributes 
	// before passing it to the function. 
	RegisterClass(&wndclass);  
	
	// 创建窗口  
	HWND hwnd = CreateWindow(  
		className,				//类名
		"我的第一个窗口",		//窗口标题
		WS_OVERLAPPEDWINDOW,	//窗口外观样式  
		10,						//相对于父窗口的X坐标
		10,						//相对于父窗口的Y坐标
		600,					//窗口的宽度  
		300,					//窗口的高度  
		NULL,					//父窗口句柄，为NULL  
		NULL,					//菜单句柄，为NULL  
		hInstance,				//当前应用程序的句柄  
		NULL);					//附加数据一般为NULL
	
	if(hwnd == NULL)			//是否创建成功  
		return 0;  
	
	// 显示窗口  
	ShowWindow(hwnd, SW_SHOW);  
	
	// 更新窗口  
	UpdateWindow(hwnd);  
	
	// 消息循环  
	MSG msg;  
	while(GetMessage(&msg, NULL, 0, 0))  
	{  
		TranslateMessage(&msg);  
		DispatchMessage(&msg);  
	}  
	
	return 0;  
}


LRESULT CALLBACK WindowProc(  
	IN  HWND hwnd,  
	IN  UINT uMsg,  
	IN  WPARAM wParam,  
	IN  LPARAM lParam  
	)  
{  
	switch(uMsg)
	{
		//窗口消息
		case WM_CREATE: 
			{
				DbgPrintf("WM_CREATE %d %d\n",wParam,lParam);
				CREATESTRUCT* createst = (CREATESTRUCT*)lParam;
				DbgPrintf("CREATESTRUCT %s\n",createst->lpszClass);
				break;
			}
		case WM_MOVE:
			{
				DbgPrintf("WM_MOVE %d %d\n",wParam,lParam);
				POINTS points = MAKEPOINTS(lParam);
				DbgPrintf("X Y %d %d\n",points.x,points.y);
				break;
			}
		case WM_SIZE:
			{
				DbgPrintf("WM_SIZE %d %d\n",wParam,lParam);
				int newWidth  = (int)(short) LOWORD(lParam);    
				int newHeight  = (int)(short) HIWORD(lParam);   
				DbgPrintf("WM_SIZE %d %d\n",newWidth,newHeight);
				break;
			}
		case WM_DESTROY:
			{
				DbgPrintf("WM_DESTROY %d %d\n",wParam,lParam);
				PostQuitMessage(0);
				return 0;
				break;
			}
		//键盘消息
		case WM_KEYUP:
			{
				DbgPrintf("WM_KEYUP %d %d\n",wParam,lParam);
				break;
			}
		case WM_KEYDOWN:
			{
				DbgPrintf("WM_KEYDOWN %d %d\n",wParam,lParam);
				break;
			}
		//鼠标消息
		case WM_LBUTTONDOWN:
			{
				DbgPrintf("WM_LBUTTONDOWN %d %d\n",wParam,lParam);
				POINTS points = MAKEPOINTS(lParam);
				DbgPrintf("WM_LBUTTONDOWN %d %d\n",points.x,points.y);
				break;
			}
		default:  
			return DefWindowProc(hwnd,uMsg,wParam,lParam);
	}
	return 0;  
}  

