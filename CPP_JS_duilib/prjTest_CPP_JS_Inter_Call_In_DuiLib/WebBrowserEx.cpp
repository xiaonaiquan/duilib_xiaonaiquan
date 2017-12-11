#include "stdafx.h"
#include "WebBrowserEx.h"
#include <ctime>
#include <chrono>
#if 1

CWebBrowserEx::CWebBrowserEx()
{
	
}


CWebBrowserEx::~CWebBrowserEx()
{
}

#endif

LPCTSTR CWebBrowserEx::GetClass() const
{
	DUITRACE(L"★★★CWebBrowserEx::GetClass Enter\r\n");

	return L"WebBrowserEx";
}

LPVOID CWebBrowserEx::GetInterface(LPCTSTR pstrName)
{
	DUITRACE(L"★★★CWebBrowserEx::GetInterface Enter: pstrName : %s\r\n", pstrName);

	if (_tcsicmp(pstrName, _T("Browser")) == 0)
	{
		return static_cast<CWebBrowserEx*>(this);
	}
	return CControlUI::GetInterface(pstrName);
}


STDMETHODIMP CWebBrowserEx::GetExternal(IDispatch** ppDispatch)
{
	DUITRACE(L"★★★CWebBrowserEx::GetExternal Enter\r\n");

	*ppDispatch = this;
	return(S_OK);
}

//HRESULT STDMETHODCALLTYPE CWebBrowserEx::GetIDsOfNames(__RPC__in REFIID riid, __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames, UINT cNames, LCID lcid, __RPC__out_ecount_full(cNames) DISPID *rgDispId)
STDMETHODIMP CWebBrowserEx::GetIDsOfNames(REFIID riid, OLECHAR **rgszNames, UINT cNames, LCID lcid, DISPID *rgDispId)
{
	HRESULT hr = NOERROR;
	UINT    i = 0;
	CDuiString cszName = CDuiString(rgszNames[i]);

	DUITRACE(L"★★★CWebBrowserEx::GetIDsOfNames Enter: rgszNames : %s\r\n", cszName);

	for (i = 0; i < cNames; ++i)
	{
		if (cszName == _T("JavaScriptCallCpp"))
		{
			//rgDispId[i] = 100;
			*rgDispId = 100;
		}
		else if (cszName == _T("JavaScriptCallCpp2"))
		{
			*rgDispId = 101;
		}
		else  {
			/* 此处很关键，如果没有很容易造成程序崩溃 */
			hr = ResultFromScode(DISP_E_UNKNOWNNAME);
			rgDispId[i] = DISPID_UNKNOWN;
		}
	}

	//return __super::GetIDsOfNames(riid, rgszNames, cNames, lcid, rgDispId);
	return(S_OK);
}

//HRESULT STDMETHODCALLTYPE CWebBrowserEx::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO *pExcepInfo, UINT *puArgErr)
STDMETHODIMP CWebBrowserEx::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, 
	DISPPARAMS* pDispParams, VARIANT* pVarResult, EXCEPINFO* pExcepInfo, UINT* puArgErr)
{
	DUITRACE(L"★★★CWebBrowserEx::Invoke Enter: dispIdMember : %d\r\n", dispIdMember);

	if (dispIdMember == 100)
	{
		CDuiString strTemp;

		strTemp.Format(L"Javascript call cpp : ");

		for (int i = pDispParams->cArgs - 1; i >= 0; i--)
		{
			BSTR bstr;
			bstr = pDispParams->rgvarg[i].bstrVal;

			strTemp += bstr;
			strTemp += L", ";

			//_com_util::ConvertBSTRToString(pDispParams->rgvarg[2].bstrVal);

		}

		MessageBoxW(NULL, strTemp, L"HAHA，DUILIB JS <--> C++", MB_OK);

	}
	else if (dispIdMember == 101)
	{
		__int64 date = pDispParams->rgvarg[0].date;
		/*SYSTEMTIME a = Int64ToSystemTime(date);
		int b = a.wYear;
		CDuiString bb;
		bb.Format(L"%d", b);
		MessageBox(NULL, bb, L"sss", NULL);*/
		std::tm *a= gettm(date);
		int b = a->tm_mon;
		CDuiString bb;
		bb.Format(L"%d", b);
		MessageBox(NULL, bb, L"sss", NULL);
	}

	return __super::Invoke(dispIdMember, riid, lcid, wFlags, pDispParams, pVarResult, pExcepInfo, puArgErr);
	//return(S_OK);
}

__int64 CWebBrowserEx::SystemTimeToInt64(const SYSTEMTIME& itime)
{
	FILETIME ft;
	SystemTimeToFileTime(&itime, &ft);
	ULARGE_INTEGER ularge;
	ularge.LowPart = ft.dwLowDateTime;
	ularge.HighPart = ft.dwHighDateTime;
	__int64 int64 = ularge.QuadPart;
	return int64;
}


SYSTEMTIME CWebBrowserEx::Int64ToSystemTime(const __int64& itime)
{
	FILETIME ft;
	SYSTEMTIME st;
	ULARGE_INTEGER ularge;
	__int64 tmptimeA, tmptimeB;
	tmptimeA = itime;
	tmptimeB = itime;
	ularge.HighPart = (DWORD)(tmptimeA >> 32);
	ularge.LowPart = (DWORD)((tmptimeB << 32) >> 32);
	ft.dwLowDateTime = ularge.LowPart;
	ft.dwHighDateTime = ularge.HighPart;
	FileTimeToSystemTime(&ft, &st);

	return st;
}

std::tm* CWebBrowserEx::gettm(__int64 timestamp)
{
	__int64 milli = timestamp + (__int64)8 * 60 * 60 * 1000;//此处转化为东八区北京时间，如果是其它时区需要按需求修改  
	auto mTime = std::chrono::milliseconds(milli);
	auto tp = std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds>(mTime);
	auto tt = std::chrono::system_clock::to_time_t(tp);
	std::tm* now = std::gmtime(&tt);
//	printf("%4d年%02d月%02d日 %02d:%02d:%02d\n", now->tm_year + 1900, now->tm_mon + 1, now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec);
	now->tm_year = now->tm_year + 1900;
	now->tm_mon = now->tm_mon + 1;
	return now;
}

