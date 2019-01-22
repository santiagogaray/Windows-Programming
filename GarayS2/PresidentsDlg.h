// PresidentsDlg.h : header file
//

#if !defined(AFX_PRESIDENTSDLG_H__28EAD03B_8C9A_11DD_B0B6_000000000000__INCLUDED_)
#define AFX_PRESIDENTSDLG_H__28EAD03B_8C9A_11DD_B0B6_000000000000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CPresidentsDlg dialog

class CPresidentsDlg : public CDialog
{
// Construction
public:
	void ChkHorScroll();
	int CurPos;
	void ProcessName(CString szPresident);
	CPresidentsDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPresidentsDlg)
	enum { IDD = IDD_PRESIDENTS_DIALOG };
	CListBox	m_PresidentsLB;
	CString	m_initialsmsg;
	CString	m_szInputFile;
	CString	m_lengthmsg;
	CString	m_SecondName;
	CString	m_LastName;
	CString	m_FirstName;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPresidentsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPresidentsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnCancel();
	virtual void OnOK();
	afx_msg void OnDone();
	afx_msg void OnBrowse();
	afx_msg void OnOpen();
	afx_msg void OnDblclkPresidentsLb();
	afx_msg void OnSave();
	afx_msg void OnUpdate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRESIDENTSDLG_H__28EAD03B_8C9A_11DD_B0B6_000000000000__INCLUDED_)
