// BlackJackDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BlackJack.h"
#include "BlackJackDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBlackJackDlg dialog

CBlackJackDlg::CBlackJackDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBlackJackDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBlackJackDlg)
	m_message = _T("");
	m_points = 0;
	m_losses = 0;
	m_wins = 0;
	m_points2 = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBlackJackDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBlackJackDlg)
	DDX_Control(pDX, IDC_RECTANGLES2, m_rectangles2);
	DDX_Control(pDX, IDC_RECTANGLES, m_rectangles);
	DDX_Control(pDX, IDC_HITME, m_hitmeButton);
	DDX_Control(pDX, IDC_STAND, m_standButton);
	DDX_Text(pDX, IDC_COMPUTER, m_message);
	DDX_Text(pDX, IDC_POINTS, m_points);
	DDX_Text(pDX, IDC_LOSSES, m_losses);
	DDX_Text(pDX, IDC_WINS, m_wins);
	DDX_Text(pDX, IDC_POINTS2, m_points2);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBlackJackDlg, CDialog)
	//{{AFX_MSG_MAP(CBlackJackDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START, OnStart)
	ON_BN_CLICKED(IDC_HITME, OnHitme)
	ON_BN_CLICKED(IDC_STAND, OnStand)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBlackJackDlg message handlers

BOOL CBlackJackDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	srand(time(NULL));
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBlackJackDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBlackJackDlg::OnPaint() 
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
HCURSOR CBlackJackDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CBlackJackDlg::OnStart() 
{	
	//Initialize variables
	m_points = m_points2 = 0;
	m_message = " The Game has begun";
	UpdateData(FALSE);
	EnableHitStandButns(TRUE);

	// Repaint both rectangles
	m_rectangles.m_currect =  m_rectangles2.m_currect = 0;
	m_rectangles.Invalidate();
	m_rectangles2.Invalidate();
}

void CBlackJackDlg::OnHitme() 
{
	// Choose number between 1-10
	m_points += 1 + rand()%10;
	UpdateData(FALSE);

	// Update the current rectangle and call OnPaint()
	m_rectangles.m_currect = m_points;
	m_rectangles.Invalidate();
	UpdateWindow();

	// Check significant scores
	if (m_points > 21)	{
		ComputerWin();
		return;
	}
	if (m_points == 21)	{
		YouWin();
		return;
	}
}

void CBlackJackDlg::OnStand() 
{
	ComputerTurn();	
}

void CBlackJackDlg::ComputerTurn()
{
	//Choose number between 15-25
	m_points2 = 15 + rand()%10;
	m_message.Format(" Computer cards total %d points", m_points2);
	UpdateData(FALSE);

	// Update the current rectangle and call OnPaint()
	m_rectangles2.m_currect = m_points2;
	m_rectangles2.Invalidate();
	UpdateWindow();

	// Check significant scores and take the right function
	if (m_points2 > 21)	{
		YouWin();
		return;
	}
	if (m_points2 == 21)	{
		ComputerWin();
		return;
	}
	if (m_points2 > m_points)	{
		ComputerWin();
		return;
	}
	else
		YouWin();	{
		return;
	}
}


void CBlackJackDlg::ComputerWin()
{
	m_message = " Computer Won";
	m_losses++;
	::Sleep(1000);
	UpdateData(FALSE);
	EnableHitStandButns(FALSE);
}


void CBlackJackDlg::YouWin()
{
	m_message = " You Won";
	m_wins++;
	::Sleep(1000);
	UpdateData(FALSE);
	EnableHitStandButns(FALSE);
}

void CBlackJackDlg::EnableHitStandButns(BOOL bEnable)
{
	m_hitmeButton.EnableWindow(bEnable);
	m_standButton.EnableWindow(bEnable);
}
