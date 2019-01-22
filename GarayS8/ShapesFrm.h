#if !defined(AFX_ShapesFRM_H__6B91848F_465C_11D2_9003_444553540000__INCLUDED_)
#define AFX_ShapesFRM_H__6B91848F_465C_11D2_9003_444553540000__INCLUDED_

#include "Shape.h"	// Added by ClassView
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// ShapesFrm.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CShapesFrm window

class CShapesFrm : public CFrameWnd
{
// Construction
public:
	CShapesFrm();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShapesFrm)
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	bool m_bpaste;
	CButton m_groupall;
	void CopyShape(int orig, int dest);
	CButton m_budelete;
	void SetBarText();
	void SetScaleButton();
	int m_oldheight;
	int m_oldwidth;
	CString m_smsg;
	void SwitchShapes(int orig, int dest);
	CButton m_bufront;
	CButton m_buback;
	CStatic m_stgroupord;
	CButton m_groupord;
	CStatic m_stgroupsh;
	CButton m_groupsh;
	void InitShape();
	CButton m_buborder;
	CSpinButtonCtrl m_spborder;
	CEdit m_edborder;
	CStatic m_stgroupb;
	CButton m_groupb;
	CStatic m_stgroupf;
	CButton m_groupf;
	CButton m_bubordercolor;
	COLORREF m_bordercolor;
	int m_border;
	COLORREF m_fillcolor;
	CRect m_rFill;
	CButton m_bufillcolor;
	CButton m_burectangle;
	int m_nscaled;
	int m_nmoved;
	CRgn m_butScale;
	int m_nselected;
	CPoint m_selOffset;
	int m_nshape;
	Shape m_aShape[41];
	CButton m_bucircle;
	void GetViewRect(LPRECT r);
	CStatusBar m_wndStatusBar;
	virtual ~CShapesFrm();

	// Generated message map functions
protected:
	//{{AFX_MSG(CShapesFrm)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg void OnCircleClicked();
	afx_msg void OnRectangleClicked();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnSpinClicked();
	afx_msg void OnFillColorClicked();
	afx_msg void OnBorderColorClicked();
	afx_msg void OnOneBackClicked();
	afx_msg void OnOneFrontClicked();
	afx_msg void OnDeleteClicked();
	afx_msg void OnFileLoad();
	afx_msg void OnFileSave();
	afx_msg void OnEditCopy();
	afx_msg void OnEditCut();
	afx_msg void OnEditPaste();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ShapesFRM_H__6B91848F_465C_11D2_9003_444553540000__INCLUDED_)
