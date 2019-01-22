// Rectangles.cpp : implementation file
//

#include "stdafx.h"
#include "BlackJack.h"
#include "Rectangles.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRectangles

CRectangles::CRectangles()
{
	m_currect = 0;
}

CRectangles::~CRectangles()
{
}


BEGIN_MESSAGE_MAP(CRectangles, CStatic)
	//{{AFX_MSG_MAP(CRectangles)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRectangles message handlers

void CRectangles::OnPaint() 
{	
	//Setting vertically aligned rectangles
	CPaintDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	dc.Rectangle(rect);
	int height = rect.Height()/22;
	rect.bottom = height;
	rect.right = rect.Width();
	rect.InflateRect(-2,-1);
	CBrush redBrush(RGB(255,0,0));
	CBrush greenBrush(RGB(0,255,0));

	// Draw rectangles per point
	for (int i = 0; (i < m_currect) && (i < 23) ; i++)
	{
		if (i > 20) 
			dc.SelectObject(redBrush);
		else
			dc.SelectObject(greenBrush);
		dc.Rectangle(rect);
		rect += CPoint(0, height);
	}


}
