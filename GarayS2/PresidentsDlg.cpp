// PresidentsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Presidents.h"
#include "PresidentsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPresidentsDlg dialog

CPresidentsDlg::CPresidentsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPresidentsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPresidentsDlg)
	m_initialsmsg = _T("");
	m_szInputFile = _T("");
	m_lengthmsg = _T("");
	m_SecondName = _T("");
	m_LastName = _T("");
	m_FirstName = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPresidentsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPresidentsDlg)
	DDX_Control(pDX, IDC_PRESIDENTS_LB, m_PresidentsLB);
	DDX_Text(pDX, IDC_INITIALS_MSGE, m_initialsmsg);
	DDX_Text(pDX, IDC_INPUT_FILE, m_szInputFile);
	DDX_Text(pDX, IDC_LENGTH_MSGE, m_lengthmsg);
	DDX_Text(pDX, IDC_SECOND, m_SecondName);
	DDX_Text(pDX, IDC_LAST, m_LastName);
	DDX_Text(pDX, IDC_FIRST, m_FirstName);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPresidentsDlg, CDialog)
	//{{AFX_MSG_MAP(CPresidentsDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_DONE, OnDone)
	ON_BN_CLICKED(IDC_BROWSE, OnBrowse)
	ON_BN_CLICKED(IDC_OPEN, OnOpen)
	ON_LBN_DBLCLK(IDC_PRESIDENTS_LB, OnDblclkPresidentsLb)
	ON_BN_CLICKED(IDC_SAVE, OnSave)
	ON_BN_CLICKED(IDC_UPDATE, OnUpdate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPresidentsDlg message handlers

BOOL CPresidentsDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	GetDlgItem(IDC_INPUT_FILE)->SetFocus();

	
	return FALSE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPresidentsDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPresidentsDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPresidentsDlg::OnCancel() 
{
	AfxMessageBox("To exit, click on the Done button");
}

void CPresidentsDlg::OnOK() 
{
	AfxMessageBox("To exit, click on the Done button");
}

void CPresidentsDlg::OnDone() 
{
	EndDialog(IDOK);
}

void CPresidentsDlg::OnBrowse() 
{
	CFileDialog dlg (TRUE, NULL, "presidents.txt", 
		OFN_HIDEREADONLY, "Text files (.txt)|*.txt|All files (*.*)|*.*||"); 
	if (dlg.DoModal() == IDOK) 
	{ 
		m_szInputFile = dlg.GetPathName(); 
		UpdateData(FALSE); 
		OnOpen(); 
	} 
	
}

void CPresidentsDlg::OnOpen() 
{

	UpdateData(TRUE);
	CString szNames;

	CStdioFile theFile(m_szInputFile, CFile::modeRead);

	m_PresidentsLB.ResetContent();

	while (theFile.ReadString (szNames))
	{
		if (szNames.Left(2) != "//" && szNames != "") //Avoid comment or null lines
		{
		m_PresidentsLB.AddString(szNames);
		}
	}
	theFile.Close();

	ChkHorScroll();
}


void CPresidentsDlg::OnDblclkPresidentsLb() 
{
	CurPos = m_PresidentsLB.GetCurSel();

	CString szNames;
	m_PresidentsLB.GetText(CurPos, szNames);

	szNames += " ";

	//	Avoid any extra blank spaces in name divisions 
	for ( int ncount = 0, name = 0; name < 3;)
	{	
		if (szNames.Mid(ncount,1) == " ")
		{
			if (name == 0) m_FirstName = szNames.Left(ncount);
			if (name == 1) m_SecondName = szNames.Left(ncount);
			if (name == 2) m_LastName = szNames.Left(ncount);
			name++;
			szNames = szNames.Mid(ncount+1);
			ncount = 0;
		}
		else
			ncount++;
	}

	szNames = m_FirstName + " " + m_SecondName + " " + m_LastName;
	ProcessName(szNames);

	UpdateData(FALSE);

}

void CPresidentsDlg::OnSave() 
{
	CString szNames;
	CFileDialog dlg(FALSE, "txt", "presidents.txt", OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, 
		"Text Files (*.txt)|*.txt|All Files (*.*)|*.*||"); 
	if (dlg.DoModal() == IDOK) 
	{
		CStdioFile outFile(dlg.GetPathName(), CFile::modeWrite | CFile::modeCreate); 
		outFile.WriteString("// start of list\n");
		for (int i = 0 ; i < m_PresidentsLB.GetCount(); i++) 
		{
			m_PresidentsLB.GetText(i, szNames);
			outFile.WriteString(szNames+ "\n");
		}
		outFile.WriteString("// end of list");

	} 
	
}

void CPresidentsDlg::OnUpdate() 
{
	UpdateData(TRUE);
	
	if (m_FirstName == "" || m_SecondName == "")
	{
		AfxMessageBox("You should not enter null names in the First or Middle boxes");
		return;
	}
	if (m_FirstName.Find(" ") > -1 || m_SecondName.Find(" ") > -1)
	{
		AfxMessageBox("You should not enter blank spaces in the First or Middle boxes");
		return;
	}
		

	m_PresidentsLB.DeleteString(CurPos);
	CString szNames = m_FirstName + " " + m_SecondName + " " + m_LastName;
	m_PresidentsLB.InsertString (CurPos, szNames);

	ProcessName(szNames);

	UpdateData(FALSE);
	ChkHorScroll();	
}

void CPresidentsDlg::ProcessName(CString szNames)
{

	m_lengthmsg.Format("The name %s contains %d letters.", szNames,
						szNames.GetLength() - 2);

	CString szInitials;
	szInitials = m_FirstName.Left(1) +m_SecondName.Left(1)+m_LastName.Left(1);
	m_initialsmsg.Format("%s initials are %s", szNames, szInitials);

}

void CPresidentsDlg::ChkHorScroll()
{
	CString szNames;
	int LongestLine = 0;
	CDC* pDC = m_PresidentsLB.GetDC(); 
	CFont* pFont = m_PresidentsLB.GetFont(); 
	CFont* pOldFont = pDC->SelectObject(pFont); 
	for ( int i= 0; i < m_PresidentsLB.GetCount(); i++)
	{
		m_PresidentsLB.GetText(i, szNames);
		LongestLine = max (LongestLine, pDC->GetTextExtent(szNames).cx);
	}
		pDC->SelectObject(pOldFont); 
	 	m_PresidentsLB.ReleaseDC(pDC); 
		m_PresidentsLB.ReleaseDC(pDC); 
		m_PresidentsLB.SetHorizontalExtent(LongestLine+3); 
}
