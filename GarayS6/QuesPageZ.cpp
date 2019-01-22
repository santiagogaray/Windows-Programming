// QuesPageZ.cpp : implementation file
//

#include "stdafx.h"
#include "questions.h"
#include "QuesPageZ.h"
#include "QuestionsPsh.h"
#include "QuesPageA.h"
#include "QuesPageB.h"
#include "QuesPageC.h"
#include "QuesPageD.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQuesPageZ property page

IMPLEMENT_DYNCREATE(CQuesPageZ, CPropertyPage)

CQuesPageZ::CQuesPageZ() : CPropertyPage(CQuesPageZ::IDD)
{
	m_psp.dwFlags &= (~PSP_HASHELP); 
	m_psp.dwFlags |= PSP_USETITLE;

	//{{AFX_DATA_INIT(CQuesPageZ)
	m_Answer1 = _T("");
	m_Answer2 = _T("");
	m_Answer3 = _T("");
	m_Answer4 = _T("");
	m_Answer5 = _T("");
	m_Ques1 = _T("");
	m_Ques2 = _T("");
	m_Ques3 = _T("");
	m_Ques4 = _T("");
	m_Ques5 = _T("");
	//}}AFX_DATA_INIT
}

CQuesPageZ::~CQuesPageZ()
{
}

void CQuesPageZ::DoDataExchange(CDataExchange* pDX)
{

	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CQuesPageZ)
	DDX_Text(pDX, IDC_ANSWER1, m_Answer1);
	DDX_Text(pDX, IDC_ANSWER2, m_Answer2);
	DDX_Text(pDX, IDC_ANSWER3, m_Answer3);
	DDX_Text(pDX, IDC_ANSWER4, m_Answer4);
	DDX_Text(pDX, IDC_ANSWER5, m_Answer5);
	DDX_Text(pDX, IDC_TEXTQUES1, m_Ques1);
	DDX_Text(pDX, IDC_TEXTQUES2, m_Ques2);
	DDX_Text(pDX, IDC_TEXTQUES3, m_Ques3);
	DDX_Text(pDX, IDC_TEXTQUES4, m_Ques4);
	DDX_Text(pDX, IDC_TEXTQUES5, m_Ques5);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CQuesPageZ, CPropertyPage)
	//{{AFX_MSG_MAP(CQuesPageZ)
	ON_BN_CLICKED(IDC_SAVEAS, OnSaveas)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQuesPageZ message handlers

BOOL CQuesPageZ::OnInitDialog() 
{

	CPropertyPage::OnInitDialog(); 
	m_pParent = (CQuestionsPsh*)GetParent(); 
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CQuesPageZ::OnSetActive() 
{
	// TODO: Add your specialized code here and/or call the base class
	m_pParent->SetButtons(); 
	m_Ques1 = (m_pParent->m_page1.m_textQues1);
	m_Ques2 = (m_pParent->m_page2.m_textQues2);
	m_Ques3 = (m_pParent->m_page3.m_textQues2);
	m_Ques4 = (m_pParent->m_page4.m_textQues3);
	m_Ques5 = (m_pParent->m_page5.m_textQues4);

	m_Answer1.Format("%d",(m_pParent->m_page1.m_nAnswer));
	m_Answer2.Format("%d",(m_pParent->m_page2.m_nOptionsChecked));
	m_Answer3.Format("%d",(m_pParent->m_page3.m_nOptionsChecked));
	m_Answer4 = (m_pParent->m_page4.m_textAnswer);
	m_Answer5.Format("%d",(m_pParent->m_page5.m_nSpin));
	
	UpdateData(FALSE);

	return CPropertyPage::OnSetActive();
}

void CQuesPageZ::OnSaveas() 
{
	CFileDialog dlg(FALSE, "txt", "answers.txt", OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, 
		"Text Files (*.txt)|*.txt|All Files (*.*)|*.*||"); 
	if (dlg.DoModal() == IDOK) 
	{ 
		// create the output file (or overwrite it if it exists) 
		CStdioFile outFile(dlg.GetPathName(), CFile::modeWrite | CFile::modeCreate); 
		outFile.WriteString(m_Ques1 + " " + m_Answer1 + "\n");	
		outFile.WriteString(m_Ques2 + " " + m_Answer2 + "\n");	
		outFile.WriteString(m_Ques3 + " " + m_Answer3 + "\n");	
		outFile.WriteString(m_Ques4 + " " + m_Answer4 + "\n");	
		outFile.WriteString(m_Ques5 + " " + m_Answer5 + "\n");	

	}
}