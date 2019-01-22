#if !defined(AFX_QUESPAGED_H__CE11A6CB_B195_11D4_B0F5_000000000000__INCLUDED_)
#define AFX_QUESPAGED_H__CE11A6CB_B195_11D4_B0F5_000000000000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// QuesPageD.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CQuesPageD dialog

class CQuesPageD : public CPropertyPage
{
	DECLARE_DYNCREATE(CQuesPageD)

// Construction
public:
	int m_maxSpin;
	int m_minSpin;
	CQuesPageD();
	~CQuesPageD();

// Dialog Data
	//{{AFX_DATA(CQuesPageD)
	enum { IDD = IDD_QUES_PAGED };
	CSpinButtonCtrl	m_spinCtrl;
	CString	m_textQues4;
	int		m_nSpin;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CQuesPageD)
	public:
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CQuesPageD)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QUESPAGED_H__CE11A6CB_B195_11D4_B0F5_000000000000__INCLUDED_)
