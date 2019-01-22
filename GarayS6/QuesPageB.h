#if !defined(AFX_QUESPAGEB_H__CE11A6C9_B195_11D4_B0F5_000000000000__INCLUDED_)
#define AFX_QUESPAGEB_H__CE11A6C9_B195_11D4_B0F5_000000000000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// QuesPageB.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CQuesPageB dialog

class CQuesPageB : public CPropertyPage
{
	DECLARE_DYNCREATE(CQuesPageB)

// Construction
public:
	int m_nOptionsChecked;
	CStringArray m_pageBArray;
	CQuesPageB();
	~CQuesPageB();

// Dialog Data
	//{{AFX_DATA(CQuesPageB)
	enum { IDD = IDD_QUES_PAGEB };
	CCheckListBox	m_pageBList;
	CString	m_textQues2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CQuesPageB)
	public:
	virtual BOOL OnSetActive();
	virtual BOOL OnKillActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CQuesPageB)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QUESPAGEB_H__CE11A6C9_B195_11D4_B0F5_000000000000__INCLUDED_)
