// Figures.h : main header file for the FIGURES application
//

#if !defined(AFX_ZDI_H__6B918485_465C_11D2_9003_444553540000__INCLUDED_)
#define AFX_ZDI_H__6B918485_465C_11D2_9003_444553540000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFiguresApp:
// See Figures.cpp for the implementation of this class
//

class CFiguresApp : public CWinApp
{
public:
	CFiguresApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFiguresApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFiguresApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZDI_H__6B918485_465C_11D2_9003_444553540000__INCLUDED_)
