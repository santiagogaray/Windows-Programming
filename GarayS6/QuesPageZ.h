#if !defined(AFX_QUESPAGEZ_H__93A2FE11_B19E_11D4_B0F5_000000000000__INCLUDED_)
#define AFX_QUESPAGEZ_H__93A2FE11_B19E_11D4_B0F5_000000000000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// QuesPageZ.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CQuesPageZ dialog

class CQuestionsPsh;

class CQuesPageZ : public CPropertyPage
{
	DECLARE_DYNCREATE(CQuesPageZ)

// Construction
public:
	CQuestionsPsh* m_pParent;
	CQuesPageZ();
	~CQuesPageZ();

// Dialog Data
	//{{AFX_DATA(CQuesPageZ)
	enum { IDD = IDD_QUES_PAGEZ };
	CString	m_Answer1;
	CString	m_Answer2;
	CString	m_Answer3;
	CString	m_Answer4;
	CString	m_Answer5;
	CString	m_Ques1;
	CString	m_Ques2;
	CString	m_Ques3;
	CString	m_Ques4;
	CString	m_Ques5;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CQuesPageZ)
	public:
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CQuesPageZ)
	virtual BOOL OnInitDialog();
	afx_msg void OnSaveas();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QUESPAGEZ_H__93A2FE11_B19E_11D4_B0F5_000000000000__INCLUDED_)
