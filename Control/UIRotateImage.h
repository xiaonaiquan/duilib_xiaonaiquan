#ifndef RotateImageUI_h__
#define RotateImageUI_h__
#pragma once

namespace DuiLib
{
	class CControl;

#define EVENT_TIME_ID	100

	class UILIB_API CRotateImageUI : public CControlUI
	{
		DECLARE_DUICONTROL(CRotateImageUI)
	public:
		CRotateImageUI();
		~CRotateImageUI();

		LPCTSTR GetClass() const;
		LPVOID GetInterface(LPCTSTR pstrName);

		void	DoInit() override;
		void	DoEvent(TEventUI& event) override;
		void	SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue) override;
		void	SetVisible(bool bVisible = true) override;

		void SetPos(RECT rc, bool bNeedInvalidate = true);

		void	SetTimeInterval(const int& nValue);
		int		GetTimeInterval();
		void	SetEachTimeAngle(const int& nValue);
		int		GetEachTimeAngle();
		void	SetFixAngle(const int& nValue);
		int		GetFixAngle();
		void	SetBkImage(const CDuiString& strImage);
		void	SetStretch(const bool& bStretch);
		bool	GetStretch();
		void	SetAutoStart(const bool& bAutoStart);
		bool	GetAutoStart();
		void	Stop();
		void	Start();
		void	Pause();

		void	PaintBkImage(HDC hDC);

	protected:
		Gdiplus::Image*	LoadImg(LPCTSTR pstrImgPath);
		void	InitInfo();

	protected:
		int m_nTimeInterval;			//时间间隔(多少毫秒旋转一次) 单位ms
		int m_nAngle;					//每次旋转角度
		bool m_bStretch;				//是否自动拉伸图片
		bool m_bIsAutoStart;			//是否自动开始旋转
		int m_nFixAngle;				//固定旋转角度		

		int m_nCurAngle;
		Gdiplus::Image*	m_pBkimage;
		IStream* m_pStream;
		CDuiString m_sBkImage;
		bool m_bIsPlaying;				//是否正在旋转

		Gdiplus::PointF m_centerPos;
	};
}

#endif // RotateImageUI_h__