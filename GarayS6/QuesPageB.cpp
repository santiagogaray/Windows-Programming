// QuesPageB.cpp : implementation file
//

#include "stdafx.h"
#include "questions.h"
#include "QuesPageB.h"
#include "QuestionsPsh.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQuesPageB property page

IMPLEMENT_DYNCREATE(CQuesPageB, CPropertyPage)

CQuesPageB::CQuesPageB() : CPropertyPage(CQuesPageB::IDD)
{
	m_psp.dwFlags &= (~PSP_HASHELP); 
	m_psp.dwFlags |= PSP_USETITLE; 
	m_nOptionsChecked = 0;
	//{{AFX_DATA_INIT(CQuesPageB)
	m_textQues2 = _T("");
	//}}AFX_DATA_INIT
}

CQuesPageB::~CQuesPageB()
{

}

void CQuesPageB::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CQuesPageB)
	DDX_Control(pDX, IDC_PAGEBLIST, m_pageBList);
	DDX_Text(pDX, IDC_TEXTQUES2, m_textQues2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CQuesPageB, CPropertyPage)
	//{{AFX_MSG_MAP(CQuesPageB)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQuesPageB message handlers

BOOL CQuesPageB::OnSetActive() 
{
	// TODO: Add your specialized code here and/or call the base class
	((CQuestionsPsh*)GetParent())->SetButtons();
	m_nOptionsChecked = 0;

	return CPropertyPage::OnSetActive();
}

BOOL CQuesPageB::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: Add extra initialization here

	for (int i = 0; i < m_pageBArray.GetSize(); i++) 
		m_pageBList.AddString(m_pageBArray[i]);	

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CQuesPageB::OnKillActive() 
{
	// TODO: Add your specialized code here and/or call the base class
	for (int i = 0; i < m_pageBList.GetCount(); i++) 
    m_nOptionsChecked += (m_pageBList.GetCheck(i) == 1); 

	return CPropertyPage::OnKillActive();
}
