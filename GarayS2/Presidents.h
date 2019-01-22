// Presidents.h : main header file for the PRESIDENTS application
//

#if !defined(AFX_PRESIDENTS_H__28EAD039_8C9A_11DD_B0B6_000000000000__INCLUDED_)
#define AFX_PRESIDENTS_H__28EAD039_8C9A_11DD_B0B6_000000000000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPresidentsApp:
// See Presidents.cpp for the implementation of this class
//

class CPresidentsApp : public CWinApp
{
public:
	CPresidentsApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPresidentsApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPresidentsApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRESIDENTS_H__28EAD039_8C9A_11DD_B0B6_000000000000__INCLUDED_)
