// TicTacToe.h : main header file for the TICTACTOE application
//

#if !defined(AFX_TICTACTOE_H__F970DA83_9153_11DD_B0CE_000000000000__INCLUDED_)
#define AFX_TICTACTOE_H__F970DA83_9153_11DD_B0CE_000000000000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTicTacToeApp:
// See TicTacToe.cpp for the implementation of this class
//

class CTicTacToeApp : public CWinApp
{
public:
	CTicTacToeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTicTacToeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTicTacToeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TICTACTOE_H__F970DA83_9153_11DD_B0CE_000000000000__INCLUDED_)
