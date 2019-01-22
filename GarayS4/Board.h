#define BOARD_LEFTCLICK WM_USER + 47
#define BOARD_RIGHTCLICK WM_USER + 48


#if !defined(AFX_BOARD_H__F970DA8F_9153_11DD_B0CE_000000000000__INCLUDED_)
#define AFX_BOARD_H__F970DA8F_9153_11DD_B0CE_000000000000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Board.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBoard window

class CBoard : public CStatic
{
// Construction
public:
	CBoard();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBoard)
	//}}AFX_VIRTUAL

// Implementation
public:
	void Chkrectsel(CPoint &);
	int m_nrect;
	int m_rectstate[9];
	void DrawCross(CDC&);
	void DrawCircle(CDC&);
	bool m_bleft;
	bool m_bright;
	RECT m_arect[9];
	CRect m_rect;

	virtual ~CBoard();

	// Generated message map functions
protected:
	//{{AFX_MSG(CBoard)
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BOARD_H__F970DA8F_9153_11DD_B0CE_000000000000__INCLUDED_)
