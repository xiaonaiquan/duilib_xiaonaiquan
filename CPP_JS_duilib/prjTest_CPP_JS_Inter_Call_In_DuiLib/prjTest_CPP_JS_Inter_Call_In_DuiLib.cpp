// prjTest_CPP_JS_Inter_Call_In_DuiLib.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "prjTest_CPP_JS_Inter_Call_In_DuiLib.h"
#include "HelloDuilibWnd.h"



int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);// 加载XML的时候，需要使用该句柄去定位EXE的路径，才能加载XML的路径

#if 1

	CHelloDuilibWnd wnd; // 生成对象

	wnd.Create(NULL, NULL, UI_WNDSTYLE_DIALOG, 0); // 创建DLG窗口
	wnd.CenterWindow(); // 窗口居中
	wnd.ShowModal(); // 显示

#else

	CHelloDuilibWnd* wnd = new CHelloDuilibWnd; // 生成对象

	wnd->Create(NULL, NULL, UI_WNDSTYLE_DIALOG, 0); // 创建DLG窗口
	wnd->CenterWindow(); // 窗口居中
	wnd->ShowWindow(); // 显示

	CPaintManagerUI::MessageLoop(); // 消息循环

	delete wnd; // 删除对象

#endif

	return 0;
}
