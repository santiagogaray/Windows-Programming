// Flight.h : main header file for the FLIGHT application
//

#if !defined(AFX_FLIGHT_H__7C8DDB43_C5FD_11D4_B112_000000000000__INCLUDED_)
#define AFX_FLIGHT_H__7C8DDB43_C5FD_11D4_B112_000000000000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CFlightApp:
// See Flight.cpp for the implementation of this class
//

class CFlightApp : public CWinApp
{
public:
	CFlightApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFlightApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFlightApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLIGHT_H__7C8DDB43_C5FD_11D4_B112_000000000000__INCLUDED_)
