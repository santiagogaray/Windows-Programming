// BlackJackDlg.h : header file
//

#if !defined(AFX_BLACKJACKDLG_H__65B5571D_8FBC_11D4_B09F_C4588B000000__INCLUDED_)
#define AFX_BLACKJACKDLG_H__65B5571D_8FBC_11D4_B09F_C4588B000000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
#include "Rectangles.h"
/////////////////////////////////////////////////////////////////////////////
// CBlackJackDlg dialog


class CBlackJackDlg : public CDialog
{
// Construction
public:
	void EnableHitStandButns( BOOL bEnable);
	void YouWin();
	void ComputerWin();
	void ComputerTurn();
	CBlackJackDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBlackJackDlg)
	enum { IDD = IDD_BLACKJACK_DIALOG };
	CRectangles	m_rectangles2;
	CRectangles	m_rectangles;
	CButton	m_hitmeButton;
	CButton	m_standButton;
	CString	m_message;
	int		m_points;
	int		m_losses;
	int		m_wins;
	int		m_points2;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBlackJackDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBlackJackDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStart();
	afx_msg void OnHitme();
	afx_msg void OnStand();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BLACKJACKDLG_H__65B5571D_8FBC_11D4_B09F_C4588B000000__INCLUDED_)
