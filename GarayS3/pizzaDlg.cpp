// pizzaDlg.cpp : implementation file
//

#include "stdafx.h"
#include "pizza.h"
#include "pizzaDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPizzaDlg dialog

CPizzaDlg::CPizzaDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPizzaDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPizzaDlg)
	m_bextracheese = FALSE;
	m_bholdsauce = FALSE;
	m_nsize = -1;
	m_tastes = _T("");
	m_display = _T("");
	m_tastescom = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPizzaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPizzaDlg)
	DDX_Control(pDX, IDC_TASTES_COMBO, m_tastesLB);
	DDX_Control(pDX, IDC_TASTES, m_tastesBox);
	DDX_Control(pDX, IDC_DISPLAY, m_displayCtrl);
	DDX_Check(pDX, IDC_EXTRA_CHEESE, m_bextracheese);
	DDX_Check(pDX, IDC_HOLD_SAUCE, m_bholdsauce);
	DDX_Radio(pDX, IDC_SMALL, m_nsize);
	DDX_CBString(pDX, IDC_TASTES, m_tastes);
	DDX_Text(pDX, IDC_DISPLAY, m_display);
	DDX_LBString(pDX, IDC_TASTES_COMBO, m_tastescom);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPizzaDlg, CDialog)
	//{{AFX_MSG_MAP(CPizzaDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_EXTRA_CHEESE, OnExtraCheese)
	ON_BN_CLICKED(IDC_HOLD_SAUCE, OnHoldSauce)
	ON_CBN_SELENDOK(IDC_TASTES, OnSelendokTastes)
	ON_BN_CLICKED(IDC_LARGE, SetTextSize)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_MEDIUM, SetTextSize)
	ON_BN_CLICKED(IDC_SMALL, SetTextSize)
	ON_LBN_DBLCLK(IDC_TASTES_COMBO, OnDblclkTastesCombo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPizzaDlg message handlers

BOOL CPizzaDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	TastesListInit();

	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPizzaDlg::OnPaint() 
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
HCURSOR CPizzaDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPizzaDlg::OnExtraCheese() 
{
	UpdateData(TRUE);
	m_zextracheese = m_bextracheese ? ", with extra cheese" : ""; 

	Order();	
}

void CPizzaDlg::OnHoldSauce() 
{
	UpdateData(TRUE);
	m_zholdsauce = m_bholdsauce ? " and hold the sauce" : ""; 
	
	Order();
	
}

void CPizzaDlg::SetTextSize() 
{
	UpdateData(TRUE);
	LOGFONT lf;
	memset(&lf,0,sizeof(lf));
	switch (m_nsize)
	{
		case 0:
			lf.lfHeight = 100;
			m_zsize ="Small ";	
			break;
		case 1:
			lf.lfHeight = 150;
			m_zsize = "Medium ";
			break;
		case 2:
			lf.lfHeight = 200;
			m_zsize = "Large ";
			break;
		default:
			return;
	}
	m_font.DeleteObject();
	m_font.CreatePointFontIndirect(&lf);
	m_displayCtrl.SetFont(&m_font);  
	UpdateWindow();
		
	Order();

	
}

void CPizzaDlg::OnSelendokTastes() 
{
	int i = m_tastesBox.GetCurSel();
	m_tastesBox.GetLBText(i, m_tastes);
	UpdateData(FALSE);

	if (m_tastes == "pepperoni" || m_tastes == "sausage")
		m_color = RGB(127,0,0);
	
	if (m_tastes == "peppers" || m_tastes == "onions")
		m_color = RGB(0,127,0);

	if (m_tastes == "crabmeat" || m_tastes == "lobster")
		m_color = RGB(0,0,127);

	UpdateWindow();

	TastesListInit();

	Order();

}

HBRUSH CPizzaDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	
	// TODO: Return a different brush if the default is not desired
	if (pWnd == GetDlgItem(IDC_DISPLAY))
		pDC->SetTextColor(m_color);

	return hbr;
}

void CPizzaDlg::OnDblclkTastesCombo() 
{
	int i = m_tastesLB.GetCurSel();
	CString ztastes;
	m_tastesLB.GetText(i, ztastes);

	if (ztastes.Left(1) == "o") 
		ztastes = "   " + ztastes.Mid(2);
	else
		ztastes = "o " + ztastes.Mid(3);

	m_tastesLB.DeleteString(i);
	m_tastesLB.InsertString(i,ztastes);
	m_tastesLB.SetCurSel(i);
	m_tastes = "";
	Order();
}

void CPizzaDlg::Order()
{
	CString ztastes;
	CString ztastescom = "";
	unsigned char r, g, b;
	r = g = b = 0;

	for (int i = 0; i < 6; i++)
	{
		m_tastesLB.GetText(i, ztastes);
		if ( ztastes.Left(1) == "o")
		{	
			if (ztastescom.GetLength() > 1)
				ztastescom = ztastescom + ", ";
			else
				ztastescom = ztastescom + "with ";
			
			ztastescom = ztastescom + ztastes.Mid(1);
			switch (i)
			{
			case 0:
			case 1:
				b = 127;
				break;
			case 2:
			case 3:
				g = 127;
				break;
			case 4:
			case 5:
				r = 127;
				break;
			}
			m_color = RGB(r,g,b);
			UpdateWindow();
		}
	}

	m_display = m_zsize + m_tastes + " pizza "+ ztastescom  
			+ m_zextracheese + m_zholdsauce + ".";
	UpdateData(FALSE);

}

void CPizzaDlg::TastesListInit()
{

	CString ztastes[] = { "   pepperoni" , "   sausage" , "   peppers" , "   onions"
					, "   crabmeat" , "   lobster" };
	m_tastesLB.ResetContent();
	for (int i=0; i < 6; i++)
	{

		m_tastesLB.AddString(ztastes[i]);
	}
	UpdateData(FALSE);
}

