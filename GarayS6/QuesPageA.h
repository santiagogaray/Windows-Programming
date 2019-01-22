#if !defined(AFX_QUESPAGEA_H__CE11A6C8_B195_11D4_B0F5_000000000000__INCLUDED_)
#define AFX_QUESPAGEA_H__CE11A6C8_B195_11D4_B0F5_000000000000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// QuesPageA.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CQuesPageA dialog

class CQuesPageA : public CPropertyPage
{
	DECLARE_DYNCREATE(CQuesPageA)

// Construction
public:
	CQuesPageA();
	~CQuesPageA();

// Dialog Data
	//{{AFX_DATA(CQuesPageA)
	enum { IDD = IDD_QUES_PAGEA };
	CString	m_textQues1;
	int		m_nAnswer;
	CString	m_textAnswer1;
	CString	m_textAnswer2;
	CString	m_textAnswer3;
	CString	m_textAnswer4;
	CString	m_textAnswer5;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CQuesPageA)
	public:
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CQuesPageA)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QUESPAGEA_H__CE11A6C8_B195_11D4_B0F5_000000000000__INCLUDED_)
