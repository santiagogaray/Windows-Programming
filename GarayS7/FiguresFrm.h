#if !defined(AFX_FiguresFRM_H__6B91848F_465C_11D2_9003_444553540000__INCLUDED_)
#define AFX_FiguresFRM_H__6B91848F_465C_11D2_9003_444553540000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// FiguresFrm.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFiguresFrm window

class CFiguresFrm : public CFrameWnd
{
// Construction
public:
	CFiguresFrm();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFiguresFrm)
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	void ChkCircle(bool chprop);
	void GetViewRect(LPRECT r);
	CStatusBar m_wndStatusBar;
	virtual ~CFiguresFrm();
	CButton m_buttonRadius;
	CEdit m_editRad;
	CButton m_buttonColor;
	CButton m_checkFill;
	CButton m_buttonErase;
	int m_Radius;
	CString m_sRadEdit;
	CRect m_cirRect;
	void DrawCircle(CDC & dc);
	int m_cix;
	int m_ciy;
	CRect RectCirc();
	COLORREF m_cirColor;
	COLORREF m_fillColor;
	int m_frWidth;
	int m_frHeight;

	// Generated message map functions
protected:
	//{{AFX_MSG(CFiguresFrm)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg void OnButtonRadiusClicked();
	afx_msg void OnButtonColorClicked();
	afx_msg void OnCheckFillClicked();
	afx_msg void OnButtonEraseClicked();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FiguresFRM_H__6B91848F_465C_11D2_9003_444553540000__INCLUDED_)
