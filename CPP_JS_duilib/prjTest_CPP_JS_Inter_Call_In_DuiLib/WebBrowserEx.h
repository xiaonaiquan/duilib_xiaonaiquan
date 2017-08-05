#pragma once
#include "..\DuiLib.2016-12-1_144312\Control\UIWebBrowser.h"

class CWebBrowserEx :
	public CWebBrowserUI
{
public:
	CWebBrowserEx();
	~CWebBrowserEx();

	virtual LPCTSTR GetClass() const;
	virtual LPVOID GetInterface(LPCTSTR pstrName);
	

	STDMETHOD(GetExternal)(IDispatch** ppDispatch);


	virtual HRESULT STDMETHODCALLTYPE GetIDsOfNames(__RPC__in REFIID riid, __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames, 
		UINT cNames, LCID lcid, __RPC__out_ecount_full(cNames) DISPID *rgDispId);
	

	virtual HRESULT STDMETHODCALLTYPE Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, 
		DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO *pExcepInfo, UINT *puArgErr);
	
};

