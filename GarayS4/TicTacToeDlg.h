// TicTacToeDlg.h : header file
//
#define COMPUTER_LEFTCLICK WM_USER + 49

#include "Board.h"

#if !defined(AFX_TICTACTOEDLG_H__F970DA85_9153_11DD_B0CE_000000000000__INCLUDED_)
#define AFX_TICTACTOEDLG_H__F970DA85_9153_11DD_B0CE_000000000000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CTicTacToeDlg dialog

class CTicTacToeDlg : public CDialog
{
// Construction
public:
	int BestOption();

	CTicTacToeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTicTacToeDlg)
	enum { IDD = IDD_TICTACTOE_DIALOG };
	CButton	m_restart;
	CStatic	m_turn;
	CBoard	m_board;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTicTacToeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTicTacToeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBoardLClicked();
	afx_msg	void OnBoardRClicked();
	afx_msg void OnComputer();
	afx_msg void OnRestart();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TICTACTOEDLG_H__F970DA85_9153_11DD_B0CE_000000000000__INCLUDED_)
