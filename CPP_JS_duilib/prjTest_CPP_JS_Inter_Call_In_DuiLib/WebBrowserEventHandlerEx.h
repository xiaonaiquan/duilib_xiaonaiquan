#pragma once

#include "..\DuiLib.2016-12-1_144312\Utils\WebBrowserEventHandler.h"

class CWebBrowserEventHandlerEx : public CWebBrowserEventHandler
{
public:
	CWebBrowserEventHandlerEx();
	~CWebBrowserEventHandlerEx();

	virtual void DocumentComplete(IDispatch *pDisp, VARIANT *&url);
	
};

