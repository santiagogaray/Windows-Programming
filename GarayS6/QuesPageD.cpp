// QuesPageD.cpp : implementation file
//

#include "stdafx.h"
#include "questions.h"
#include "QuesPageD.h"
#include "QuestionsPsh.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQuesPageD property page

IMPLEMENT_DYNCREATE(CQuesPageD, CPropertyPage)

CQuesPageD::CQuesPageD() : CPropertyPage(CQuesPageD::IDD)
{
	m_psp.dwFlags &= (~PSP_HASHELP); 
	m_psp.dwFlags |= PSP_USETITLE; 
	m_nSpin = 1;

	//{{AFX_DATA_INIT(CQuesPageD)
	m_textQues4 = _T("");
	m_nSpin = 0;
	//}}AFX_DATA_INIT
}

CQuesPageD::~CQuesPageD()
{
}

void CQuesPageD::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CQuesPageD)
	DDX_Control(pDX, IDC_SPIN, m_spinCtrl);
	DDX_Text(pDX, IDC_TEXT_QUES4, m_textQues4);
	DDX_Text(pDX, IDC_NUMBER, m_nSpin);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CQuesPageD, CPropertyPage)
	//{{AFX_MSG_MAP(CQuesPageD)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQuesPageD message handlers

BOOL CQuesPageD::OnSetActive() 
{
	// TODO: Add your specialized code here and/or call the base class
	((CQuestionsPsh*)GetParent())->SetButtons();
	m_spinCtrl.SetPos(m_minSpin);
	m_spinCtrl.SetRange(m_minSpin, m_maxSpin);
	return CPropertyPage::OnSetActive();
}
