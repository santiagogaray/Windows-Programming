#if !defined(AFX_QUESPAGEC_H__CE11A6CA_B195_11D4_B0F5_000000000000__INCLUDED_)
#define AFX_QUESPAGEC_H__CE11A6CA_B195_11D4_B0F5_000000000000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// QuesPageC.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CQuesPageC dialog

class CQuesPageC : public CPropertyPage
{
	DECLARE_DYNCREATE(CQuesPageC)

// Construction
public:
	CQuesPageC();
	~CQuesPageC();

// Dialog Data
	//{{AFX_DATA(CQuesPageC)
	enum { IDD = IDD_QUES_PAGEC };
	CString	m_textQues3;
	CString	m_textAnswer;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CQuesPageC)
	public:
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CQuesPageC)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QUESPAGEC_H__CE11A6CA_B195_11D4_B0F5_000000000000__INCLUDED_)
