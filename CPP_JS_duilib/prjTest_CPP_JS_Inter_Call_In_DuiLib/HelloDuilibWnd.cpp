#include "stdafx.h"
#include "HelloDuilibWnd.h"



#if 1
DUI_BEGIN_MESSAGE_MAP(CHelloDuilibWnd, WindowImplBase)
DUI_ON_MSGTYPE(DUI_MSGTYPE_WINDOWINIT, OnWindowInitialized)
DUI_ON_MSGTYPE(DUI_MSGTYPE_CLICK, OnClick)
DUI_END_MESSAGE_MAP()
#endif

CHelloDuilibWnd::CHelloDuilibWnd()
{
}


CHelloDuilibWnd::~CHelloDuilibWnd()
{
}

#if 1

void CHelloDuilibWnd::OnWindowInitialized(TNotifyUI& msg)
{
	DUITRACE(L"★★★CHelloDuilibWnd::OnWindowInitialized Enter\r\n");

	SetWindowTextW(m_hWnd, L"DuiLib WebBrowser");
	CenterWindow();

#if 1
	m_pbtnGo = (CButtonUI*)m_PaintManager.FindControl(_T("btnGo"));

	m_pbtnCallJS = (CButtonUI*)m_PaintManager.FindControl(_T("btnCallJS"));

	m_peditURL = (CEditUI*)m_PaintManager.FindControl(_T("editURL"));
#endif

	//SetFocus 必须的，解决：点两次内嵌网页，才可以调用C++
	m_pWebBrowserEx->SetFocus();

}

#endif

CControlUI* CHelloDuilibWnd::CreateControl(LPCTSTR pstrClass)
{
	CControlUI * pUI = NULL;

	DUITRACE(L"★★★CHelloDuilibWnd::CreateControl Enter: pstrClass : %s\r\n", pstrClass);

	if (_tcsicmp(pstrClass, _T("WebBrowserEx")) == 0)
	{
		pUI = m_pWebBrowserEx = new CWebBrowserEx;
		if (m_pWebBrowserEx)
		{ 
			m_pWebBrowserEx->SetWebBrowserEventHandler(&m_CWBEventHandler);
		}
	}
	return pUI;
}


void CHelloDuilibWnd::InitWindow()
{
	DUITRACE(L"★★★CHelloDuilibWnd::InitWindow Enter\r\n");
	
	return;
}

void CHelloDuilibWnd::OnClick(TNotifyUI& msg)
{
	DUITRACE(L"★★★CHelloDuilibWnd::OnClick Enter\r\n");
	
	if (msg.pSender == m_pbtnGo)
	{
		if (m_pWebBrowserEx)
		{
			
			CDuiString csPath = m_peditURL->GetText();
			m_pWebBrowserEx->Navigate2(csPath);
		}
	}
	else if (msg.pSender == m_pbtnCallJS)
	{
		VARIANT params[10];
		VARIANT ret;
		//获取页面window
		IDispatch *pHtmlWindow = m_pWebBrowserEx->GetHtmlWindow();
		//页面全局函数Test实际上是window的Test方法，
		CWebBrowserUI::InvokeMethod(pHtmlWindow, _T("Test"), &ret, params, 0);
	}

	__super::OnClick(msg);
}