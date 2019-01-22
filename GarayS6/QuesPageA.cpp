// QuesPageA.cpp : implementation file
//

#include "stdafx.h"
#include "questions.h"
#include "QuesPageA.h"
#include "QuestionsPsh.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQuesPageA property page

IMPLEMENT_DYNCREATE(CQuesPageA, CPropertyPage)

CQuesPageA::CQuesPageA() : CPropertyPage(CQuesPageA::IDD)
{
	m_psp.dwFlags &= (~PSP_HASHELP); 
	m_psp.dwFlags |= PSP_USETITLE; 

	m_nAnswer = 0;

	//{{AFX_DATA_INIT(CQuesPageA)
	m_textQues1 = _T("");
	m_nAnswer = -1;
	m_textAnswer1 = _T("");
	m_textAnswer2 = _T("");
	m_textAnswer3 = _T("");
	m_textAnswer4 = _T("");
	m_textAnswer5 = _T("");
	//}}AFX_DATA_INIT
}

CQuesPageA::~CQuesPageA()
{

}

void CQuesPageA::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CQuesPageA)
	DDX_Text(pDX, IDC_TEXT_QUES1, m_textQues1);
	DDX_Radio(pDX, IDC_ANSWER1, m_nAnswer);
	DDX_Text(pDX, IDC_TEXT_ANSWER1, m_textAnswer1);
	DDX_Text(pDX, IDC_TEXT_ANSWER2, m_textAnswer2);
	DDX_Text(pDX, IDC_TEXT_ANSWER3, m_textAnswer3);
	DDX_Text(pDX, IDC_TEXT_ANSWER4, m_textAnswer4);
	DDX_Text(pDX, IDC_TEXT_ANSWER5, m_textAnswer5);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CQuesPageA, CPropertyPage)
	//{{AFX_MSG_MAP(CQuesPageA)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQuesPageA message handlers

BOOL CQuesPageA::OnSetActive() 
{
		// TODO: Add your specialized code here and/or call the base class
	((CQuestionsPsh*)GetParent())->SetButtons();
	m_nAnswer = 0;

	return CPropertyPage::OnSetActive();
}
