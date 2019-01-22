// QuestionsPsh.cpp : implementation file
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
// CQuestionsPsh

IMPLEMENT_DYNAMIC(CQuestionsPsh, CPropertySheet)

CQuestionsPsh::CQuestionsPsh(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	AddPage(&m_page1); 
	m_page1.m_psp.pszTitle = "Personal Situation"; 
	AddPage(&m_page2); 
	m_page2.m_psp.pszTitle = "Activities"; 
	AddPage(&m_page3); 
	m_page3.m_psp.pszTitle = "Places"; 
	AddPage(&m_page4); 
	m_page4.m_psp.pszTitle = "You decide"; 
	AddPage(&m_page5); 
	m_page5.m_psp.pszTitle = "Reservations"; 
	AddPage(&m_page6); 
	m_page6.m_psp.pszTitle = "Your order"; 

	m_page1.m_textQues1 = "Are you tired?";
	m_page1.m_textAnswer1 ="No";
	m_page1.m_textAnswer2 ="Not much";
	m_page1.m_textAnswer3 ="A little";
	m_page1.m_textAnswer4 ="Yes";
	m_page1.m_textAnswer5 ="Yes, very much";

	m_page2.m_textQues2 = "Select the activities you whould like to do";
	m_page2.m_pageBArray.Add("Work");
	m_page2.m_pageBArray.Add("Study");
	m_page2.m_pageBArray.Add("Sleep");
	m_page2.m_pageBArray.Add("Play Sports");
	m_page2.m_pageBArray.Add("House keeping");
	m_page2.m_pageBArray.Add("Reading");
	m_page2.m_pageBArray.Add("Take a holiday somewhere");

	m_page3.m_textQues2 = "Which places whould you select?";
	m_page3.m_pageBArray.Add("Big cities");
	m_page3.m_pageBArray.Add("Country side");
	m_page3.m_pageBArray.Add("Lakes");
	m_page3.m_pageBArray.Add("Desert");
	m_page3.m_pageBArray.Add("Mountain");
	m_page3.m_pageBArray.Add("A paradise island");
	
	m_page4.m_textQues3 = "Whould you like to be in Kokipi?";

	m_page5.m_textQues4 = "How many tickets you whant (1-10)?";
	m_page5.m_minSpin = 1;
	m_page5.m_maxSpin = 10;



}

CQuestionsPsh::~CQuestionsPsh()
{
}


BEGIN_MESSAGE_MAP(CQuestionsPsh, CPropertySheet)
	//{{AFX_MSG_MAP(CQuestionsPsh)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQuestionsPsh message handlers

void CQuestionsPsh::SetButtons()
{
    if (GetActiveIndex() == 0) 
        SetWizardButtons(PSWIZB_NEXT); 
    else if (GetActiveIndex() == GetPageCount() -1) 
        SetWizardButtons(PSWIZB_BACK | PSWIZB_FINISH); 
    else 
        SetWizardButtons(PSWIZB_BACK | PSWIZB_NEXT); 

}
