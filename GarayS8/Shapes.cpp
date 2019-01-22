// Shapes.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Shapes.h"
#include "ShapesFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShapesApp

BEGIN_MESSAGE_MAP(CShapesApp, CWinApp)
	//{{AFX_MSG_MAP(CShapesApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShapesApp construction

CShapesApp::CShapesApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CShapesApp object

CShapesApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CShapesApp initialization

BOOL CShapesApp::InitInstance()
{
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif
	m_pMainWnd = new CShapesFrm ;
	((CShapesFrm*)m_pMainWnd)->LoadFrame(IDR_MAINFRAME);
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;

}
