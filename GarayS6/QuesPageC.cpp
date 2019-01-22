// QuesPageC.cpp : implementation file
//

#include "stdafx.h"
#include "questions.h"
#include "QuesPageC.h"
#include "QuestionsPsh.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQuesPageC property page

IMPLEMENT_DYNCREATE(CQuesPageC, CPropertyPage)

CQuesPageC::CQuesPageC() : CPropertyPage(CQuesPageC::IDD)
{
	m_psp.dwFlags &= (~PSP_HASHELP); 
	m_psp.dwFlags |= PSP_USETITLE; 


	//{{AFX_DATA_INIT(CQuesPageC)
	m_textQues3 = _T("");
	m_textAnswer = _T("");
	//}}AFX_DATA_INIT
}

CQuesPageC::~CQuesPageC()
{
}

void CQuesPageC::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CQuesPageC)
	DDX_Text(pDX, IDC_TEXT_QUES3, m_textQues3);
	DDX_Text(pDX, IDC_ANSWER, m_textAnswer);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CQuesPageC, CPropertyPage)
	//{{AFX_MSG_MAP(CQuesPageC)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQuesPageC message handlers

BOOL CQuesPageC::OnSetActive() 
{
	// TODO: Add your specialized code here and/or call the base class
	((CQuestionsPsh*)GetParent())->SetButtons(); 	
	return CPropertyPage::OnSetActive();
}
