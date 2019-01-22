#if !defined(AFX_QUESTIONSPSH_H__CE11A6C7_B195_11D4_B0F5_000000000000__INCLUDED_)
#define AFX_QUESTIONSPSH_H__CE11A6C7_B195_11D4_B0F5_000000000000__INCLUDED_

#include "QuesPageA.h"	// Added by ClassView
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// QuestionsPsh.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CQuestionsPsh
#include "QuesPageA.h"
#include "QuesPageB.h"
#include "QuesPageC.h"
#include "QuesPageD.h"
#include "QuesPageZ.h"

class CQuestionsPsh : public CPropertySheet
{
	DECLARE_DYNAMIC(CQuestionsPsh)

// Construction
public:
	CQuestionsPsh(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQuestionsPsh)
	//}}AFX_VIRTUAL

// Implementation
public:
	void SetButtons();
	CQuesPageA m_page1;
	CQuesPageB m_page2;
	CQuesPageB m_page3;
	CQuesPageC m_page4;
	CQuesPageD m_page5;
	CQuesPageZ m_page6;

	virtual ~CQuestionsPsh();

	// Generated message map functions
protected:
	//{{AFX_MSG(CQuestionsPsh)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QUESTIONSPSH_H__CE11A6C7_B195_11D4_B0F5_000000000000__INCLUDED_)
