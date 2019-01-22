// questions.h : main header file for the QUESTIONS application
//

#if !defined(AFX_QUESTIONS_H__CE11A6BB_B195_11D4_B0F5_000000000000__INCLUDED_)
#define AFX_QUESTIONS_H__CE11A6BB_B195_11D4_B0F5_000000000000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CQuestionsApp:
// See questions.cpp for the implementation of this class
//

class CQuestionsApp : public CWinApp
{
public:
	CQuestionsApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQuestionsApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CQuestionsApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QUESTIONS_H__CE11A6BB_B195_11D4_B0F5_000000000000__INCLUDED_)
