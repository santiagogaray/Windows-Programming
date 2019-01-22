// pizzaDlg.h : header file
//

#if !defined(AFX_PIZZADLG_H__A4158586_99F8_11D4_883A_CA493DDD9D01__INCLUDED_)
#define AFX_PIZZADLG_H__A4158586_99F8_11D4_883A_CA493DDD9D01__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CPizzaDlg dialog

class CPizzaDlg : public CDialog
{
// Construction
public:
	void TastesListInit();
	void Order();
	CFont m_font;
	CString m_zholdsauce;
	CString m_zextracheese;
	CString m_zsize;
	COLORREF m_color;
	CPizzaDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPizzaDlg)
	enum { IDD = IDD_PIZZA_DIALOG };
	CListBox	m_tastesLB;
	CComboBox	m_tastesBox;
	CEdit	m_displayCtrl;
	BOOL	m_bextracheese;
	BOOL	m_bholdsauce;
	int		m_nsize;
	CString	m_tastes;
	CString	m_display;
	CString	m_tastescom;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPizzaDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPizzaDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnExtraCheese();
	afx_msg void OnHoldSauce();
	afx_msg void OnSelendokTastes();
	afx_msg void SetTextSize();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnDblclkTastesCombo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PIZZADLG_H__A4158586_99F8_11D4_883A_CA493DDD9D01__INCLUDED_)
