// BlackJack.h : main header file for the BLACKJACK application
//

#if !defined(AFX_BLACKJACK_H__65B5571B_8FBC_11D4_B09F_C4588B000000__INCLUDED_)
#define AFX_BLACKJACK_H__65B5571B_8FBC_11D4_B09F_C4588B000000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBlackJackApp:
// See BlackJack.cpp for the implementation of this class
//

class CBlackJackApp : public CWinApp
{
public:
	CBlackJackApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBlackJackApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBlackJackApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BLACKJACK_H__65B5571B_8FBC_11D4_B09F_C4588B000000__INCLUDED_)
