// questions.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "questions.h"
#include "QuestionsPsh.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQuestionsApp

BEGIN_MESSAGE_MAP(CQuestionsApp, CWinApp)
	//{{AFX_MSG_MAP(CQuestionsApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQuestionsApp construction

CQuestionsApp::CQuestionsApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CQuestionsApp object

CQuestionsApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CQuestionsApp initialization

BOOL CQuestionsApp::InitInstance()
{
	AfxEnableControlContainer();
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.
#define WIZARD_MODE

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif
	
	CQuestionsPsh sheet((LPCTSTR)"Questionaire",NULL,0); 
	m_pMainWnd = &sheet; 
#ifdef WIZARD_MODE 
    sheet.SetWizardMode(); 
#endif 
	sheet.m_psh.dwFlags |= PSH_NOAPPLYNOW; 
	sheet.m_psh.dwFlags &= (~PSH_HASHELP); 
	sheet.SetActivePage(0); 
	int nResponse = sheet.DoModal(); 
	return FALSE; 
	
}
