// Board.cpp : implementation file
//

#include "stdafx.h"
#include "TicTacToe.h"
#include "Board.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBoard

CBoard::CBoard()
{
	m_bright = m_bleft = 0;
	for (int i=0; i<9; i++)
		m_rectstate[i]=0;
	
}

CBoard::~CBoard()
{
}


BEGIN_MESSAGE_MAP(CBoard, CStatic)
	//{{AFX_MSG_MAP(CBoard)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBoard message handlers

void CBoard::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	GetClientRect(m_rect);
	dc.Rectangle(m_rect);
	dc.SelectStockObject(BLACK_PEN);

	// Draw grid and load array with rectangles
	int i =0;
	for (int xr=0; xr < 150; xr += 70)
	{
		for (int yr=0; yr < 150; yr += 70)
		{	
			m_arect[i].left = xr;
			m_arect[i].top = yr;
			m_arect[i].right = xr + 70;
			m_arect[i].bottom = yr + 70;
			
			dc.Rectangle(xr,yr,xr+70,yr+70);
			i++;
		}
	}
	
	//Update display with X and O placed on board and call Drawing functions
	for (int n=0; n < 9; n++)
	{	
		int ntemp;
		if (m_rectstate[n] == 1)
		{	ntemp = m_nrect;
			m_nrect = n;
			DrawCircle(dc);
			m_nrect=ntemp;
		}
		if (m_rectstate[n] == 2)
		{	ntemp = m_nrect;
			m_nrect = n;
			DrawCross(dc);
			m_nrect=ntemp;
		}
	}


	// Do not call CStatic::OnPaint() for painting messages
}

void CBoard::OnLButtonDown(UINT nFlags, CPoint point) 
{
	if (m_bleft ==1) return;
	Chkrectsel(point);
	if (m_nrect == 9) return;
	if (m_rectstate[m_nrect]) return;
	m_rectstate[m_nrect] = 1;
	m_bleft = 1;
	InvalidateRect(&m_arect[m_nrect]);
	m_bright = 0;
	GetParent()->SendMessage(WM_COMMAND, MAKEWPARAM(GetDlgCtrlID()
		,BOARD_LEFTCLICK),(LPARAM)m_hWnd);
	CStatic::OnLButtonDown(nFlags, point);
}

void CBoard::OnRButtonDown(UINT nFlags, CPoint point) 
{
	if (m_bright ==1) return;
	Chkrectsel(point);
	if (m_nrect == 9) return;
	if (m_rectstate[m_nrect]) return;
	m_rectstate[m_nrect] = 2;
	m_bright = 1;
	InvalidateRect(&m_arect[m_nrect]);
	m_bleft = 0;
	GetParent()->SendMessage(WM_COMMAND, MAKEWPARAM(GetDlgCtrlID()
		,BOARD_RIGHTCLICK),(LPARAM)m_hWnd);
		
	CStatic::OnRButtonDown(nFlags, point);
}

void CBoard::DrawCircle(CDC & dc)
{
	CPen pen(PS_SOLID,4,RGB(255,0,0));
	dc.SelectObject(&pen);
	CRect cirect = m_arect[m_nrect];
	cirect.InflateRect(-5,-5);
	dc.Ellipse(cirect);
	dc.SelectStockObject(BLACK_PEN);

}

void CBoard::DrawCross(CDC & dc)
{
	CPen pen(PS_SOLID,4,RGB(0,190,0));
	dc.SelectObject(&pen);

	dc.MoveTo(m_arect[m_nrect].left+8, m_arect[m_nrect].bottom-8);
	dc.LineTo(m_arect[m_nrect].right-8, m_arect[m_nrect].top+8);

	dc.MoveTo(m_arect[m_nrect].left+8, m_arect[m_nrect].top+8);
	dc.LineTo(m_arect[m_nrect].right-8, m_arect[m_nrect].bottom-8);

	dc.SelectStockObject(BLACK_PEN);

}

void CBoard::Chkrectsel(CPoint & point)
{
	m_nrect = 0;
	for (; m_nrect < 9; m_nrect++)
	{
		if(point.x > m_arect[m_nrect].left && 
			point.x < m_arect[m_nrect].right &&
			point.y > m_arect[m_nrect].top &&
			point.y < m_arect[m_nrect].bottom)
		break;
	}

}

