// DPIDemo.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "DPIDemo.h"
#include "FrameWnd.h"

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	

	CPaintManagerUI::SetInstance(hInstance);// 加载XML的时候，需要使用该句柄去定位EXE的路径，才能加载XML的路径

	CPaintManagerUI::SetCurrentPath(CPaintManagerUI::GetInstancePath());
	CPaintManagerUI::SetResourcePath(L"skin\\HiDPIDemo");
	HRESULT Hr = ::CoInitialize(NULL);
	if (FAILED(Hr)) return 0;

	CFrameWnd *pFrame = new CFrameWnd(_T("Main_dlg.xml"));
	pFrame->Create(NULL, _T("HiDPI Demo Window1"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	pFrame->ShowWindow();
	pFrame->setDPI(CDPI::GetMainMonitorDPI());
	pFrame->CenterWindow();

	CPaintManagerUI::MessageLoop();

	delete pFrame;

	::CoUninitialize();

	return 0;
}

