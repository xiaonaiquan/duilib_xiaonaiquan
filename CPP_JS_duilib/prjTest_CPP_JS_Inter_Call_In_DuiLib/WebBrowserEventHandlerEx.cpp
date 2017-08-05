#include "stdafx.h"
#include "WebBrowserEventHandlerEx.h"


CWebBrowserEventHandlerEx::CWebBrowserEventHandlerEx()
{
}


CWebBrowserEventHandlerEx::~CWebBrowserEventHandlerEx()
{
}

void CWebBrowserEventHandlerEx::DocumentComplete(IDispatch *pDisp, VARIANT *&url)
{
	//MessageBoxW(NULL, L"Load Complete", L"", MB_OK);

	DUITRACE(L"CWebBrowserEventHandlerEx::DocumentComplete Enter\r\n");

	return;
}

