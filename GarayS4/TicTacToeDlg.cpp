// TicTacToeDlg.cpp : implementation file
//


#include "stdafx.h"
#include "TicTacToe.h"
#include "TicTacToeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTicTacToeDlg dialog

CTicTacToeDlg::CTicTacToeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTicTacToeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTicTacToeDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTicTacToeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTicTacToeDlg)
	DDX_Control(pDX, IDC_RESTART, m_restart);
	DDX_Control(pDX, IDC_TURN, m_turn);
	DDX_Control(pDX, IDC_BOARD, m_board);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTicTacToeDlg, CDialog)
	//{{AFX_MSG_MAP(CTicTacToeDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CONTROL(BOARD_LEFTCLICK,IDC_BOARD, OnBoardLClicked)
	ON_CONTROL(BOARD_RIGHTCLICK,IDC_BOARD, OnBoardRClicked)
	ON_BN_CLICKED(IDC_COMPUTER, OnComputer)
	ON_BN_CLICKED(IDC_RESTART, OnRestart)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTicTacToeDlg message handlers

BOOL CTicTacToeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTicTacToeDlg::OnPaint() 
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
HCURSOR CTicTacToeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTicTacToeDlg::OnBoardLClicked()
{
	int option = BestOption();
	if (option == -2)
		m_turn.SetWindowText("O Wins");
	else
		m_turn.SetWindowText("Rightclick for X or press Computer");
}

void CTicTacToeDlg::OnBoardRClicked()
{
	int option = BestOption();
	if (option == -2)
		m_turn.SetWindowText("X Wins");
	else
		m_turn.SetWindowText("Leftclick for O or press Computer");
}

void CTicTacToeDlg::OnComputer() 
{

	int option = BestOption();
	if (m_board.m_bright == 0)
	{
		m_board.m_rectstate[option] = 2;
		m_board.InvalidateRect(&m_board.m_arect[option]);
		if (BestOption() == -2)
		{	m_turn.SetWindowText("X Wins");
			return;
		}
		else 
		{	m_board.m_bright = 1;
			m_board.m_bleft = 0;
			m_turn.SetWindowText("Leftclick for O or press Computer");
		}
	}
	else
	{
		m_board.m_rectstate[option] = 1;
		m_board.InvalidateRect(&m_board.m_arect[option]);
		if (BestOption() == -2)
		{	m_turn.SetWindowText("O Wins");
			return;
		}
		else
		{	m_board.m_bleft = 1;
			m_board.m_bright = 0;
			m_turn.SetWindowText("Rightclick for X or press Computer");
		}
	}

		
}

int CTicTacToeDlg::BestOption()
{
	int chkf = 0;
	int	optold = 0;
	int noblank, blank, state ;
	int posop[9] = {0,0,0,0,0,0,0,0,0};

	if (m_board.m_bright == 1)
		chkf = 1;
	else
		chkf=2;

	//check for ver. pattern

	for (int i=0; i<9; i+=3)
	{
		state = noblank = blank = optold = 0;
		for (int c=0; c <3; c++)
		{
			if (m_board.m_rectstate[i+c]==chkf)
				state ++;
			else
				if (m_board.m_rectstate[i+c]==0)
				{	blank = i+c;
					optold = posop[blank];
					posop[blank] = 1;
				}
				else
					noblank ++;
		}
		if (noblank == 3)
			return -2;
		if (state == 2 && blank)
			return blank;
		if (noblank == 2 && blank)
			return blank;
		if (noblank == 1 && blank)
			posop[blank] = optold;
	}

	//check for hor. pattern
	for ( i=0; i<3; i++)
	{
		state = noblank = blank = optold = 0;
		for (int c=0; c <9; c+=3)
		{
			if (m_board.m_rectstate[i+c]==chkf)
				state ++;
			else
				if (m_board.m_rectstate[i+c]==0)
				{	blank = i+c;
					optold = posop[blank];
					posop[blank] = 1;
				}
				else
					noblank ++;
		}
		if (noblank == 3)
			return -2;
		if (state == 2 && blank)
			return blank;
		if (noblank == 2 && blank)
			return blank;
		if (noblank == 1 && blank)
			posop[blank] = optold;
	}

	//check for diag. 1 pattern
	state = noblank = blank = optold = 0;
	for (int c=0; c <9; c+=4)
	{
		if (m_board.m_rectstate[c]==chkf)
			state ++;
		else
			if (m_board.m_rectstate[c]==0)
			{	blank = c;
				optold = posop[blank];
				posop[blank] = 1;
			}
			else
				noblank ++;
	}
	if (noblank == 3)
		return -2;
	if (state == 2 && blank)
		return blank;
	if (noblank == 2 && blank)
		return blank;
	if (noblank == 1 && blank)
		posop[blank] = optold;


	//check for diag. 2 pattern
	state = noblank = blank = optold = 0;
	for (c=2; c <8; c+=2)
	{
			if (m_board.m_rectstate[c]==chkf)
				state ++;
			else
				if (m_board.m_rectstate[c]==0)
				{	blank = c;
					optold = posop[blank];
					posop[blank] = 1;
				}
				else
					noblank ++;
	}
	if (noblank == 3)
		return -2;
	if (state == 2 && blank)
		return blank;
	if (noblank == 2 && blank)
		return blank;
	if (noblank == 1 && blank)
		posop[blank] = optold;

	// if only one in a row was found
	if (posop[4] == 1)
		return 4;

	for (i=0; i<9; i++)
	{
		if (posop[i] == 1)
			return i;
	}

	return -1;
}

void CTicTacToeDlg::OnRestart() 
{
	m_board.m_bright = m_board.m_bleft = 0;
	for (int i=0; i<9; i++)
		m_board.m_rectstate[i]=0;
	m_board.Invalidate();
	
}
