// FiguresFrm.cpp : implementation file
//
#include "stdafx.h"
#include "Figures.h"
#include "FiguresFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFiguresFrm

CFiguresFrm::CFiguresFrm()
{
	m_Radius = 40;
	m_cix = 300, m_ciy = 200;
	RectCirc();
	m_cirColor = RGB(0,0,0);
	m_fillColor = (RGB(255,255,255));
}

CFiguresFrm::~CFiguresFrm()
{
}


BEGIN_MESSAGE_MAP(CFiguresFrm, CFrameWnd)
	//{{AFX_MSG_MAP(CFiguresFrm)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON_RADIUS, OnButtonRadiusClicked)
	ON_BN_CLICKED(IDC_BUTTON_COLOR, OnButtonColorClicked)
	ON_BN_CLICKED(IDC_CHECK_FILL, OnCheckFillClicked)
	ON_BN_CLICKED(IDC_BUTTON_ERASE, OnButtonEraseClicked)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP

END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_1,
};


/////////////////////////////////////////////////////////////////////////////
// CFiguresFrm message handlers

int CFiguresFrm::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	m_wndStatusBar.Create(this);
	m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT));

	CRect rWindow(5,5,110,25);
	m_buttonRadius.Create("Set radius", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		rWindow, this, IDC_BUTTON_RADIUS);
	rWindow = CRect(110,5,140,25);
	m_editRad.Create( WS_CHILD | WS_VISIBLE | ES_RIGHT, rWindow, this,
		IDC_EDIT_RADIUS);
	m_sRadEdit.Format("%d",m_Radius);
	m_editRad.SetWindowText(m_sRadEdit);
	rWindow = CRect(5,30,140,50);
	m_buttonColor.Create("Select color", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		rWindow, this, IDC_BUTTON_COLOR);

	rWindow = CRect(5,55,140,75);
	m_checkFill.Create("Fill circle", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
		rWindow, this, IDC_CHECK_FILL);

	rWindow = CRect(5,80,140,100);
	m_buttonErase.Create("Erase circle", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		rWindow, this, IDC_BUTTON_ERASE);

	CString sMessage;
	sMessage.Format("x: %d   y: %d",m_cix,m_ciy);
	m_wndStatusBar.SetPaneText(1,sMessage,1);
	
	
	return 0;
}

void CFiguresFrm::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	CRect r;
	GetViewRect(&r);
//TODO - replace the following with your real painting code 
	dc.FillSolidRect(r, RGB(255,255,255));
	m_frWidth = r.Width();
	m_frHeight = r.Height();

	DrawCircle(dc);

}

void CFiguresFrm::GetViewRect(LPRECT r)
{
	RepositionBars(0, 0xffff, AFX_IDW_PANE_FIRST, reposQuery, r);
}

BOOL CFiguresFrm::PreCreateWindow(CREATESTRUCT& cs) 
{
//Remove the next line if you want a resizable window
	cs.style &= (~WS_THICKFRAME);
//This sets the width and height of the window
	cs.cx = 600;
	cs.cy = 450;
//This sets the title (in the caption bar)
	cs.lpszName = "Figures Frame Window";
	return CFrameWnd::PreCreateWindow(cs);
}

void CFiguresFrm::OnButtonRadiusClicked()
{
	m_cirRect.InflateRect(2,2);
	InvalidateRect(m_cirRect);
	m_editRad.GetWindowText(m_sRadEdit);
	InvalidateRect(m_cirRect);
	m_Radius = atoi(m_sRadEdit);
	ChkCircle(1);
	InvalidateRect(RectCirc());

}

void CFiguresFrm::OnButtonColorClicked()
{
	SetMessageText("Select Color");
	CColorDialog dlg; 
	if (dlg.DoModal() == IDOK) 
	{
		InvalidateRect(m_cirRect);
		m_cirColor = dlg.GetColor();
		OnCheckFillClicked();
		InvalidateRect(RectCirc());
	}
	SetMessageText("");
}


void CFiguresFrm::OnCheckFillClicked()
{
	SetMessageText("");
	if(m_checkFill.GetState() & 0x0003)
		m_fillColor = m_cirColor;
	else
		m_fillColor = (RGB(255,255,255));
	InvalidateRect(m_cirRect);

}

void CFiguresFrm::OnButtonEraseClicked()
{
	SetMessageText("");
	InvalidateRect(m_cirRect);
	m_Radius = 0;
	InvalidateRect(RectCirc());

}

void CFiguresFrm::DrawCircle(CDC & dc)
{
	CPen pen(PS_SOLID,2,m_cirColor);
	CBrush fillBrush(m_fillColor);
	dc.SelectObject(&pen);
	dc.SelectObject(fillBrush);
	dc.Ellipse(m_cirRect);
	dc.SelectStockObject(BLACK_PEN);
	DeleteObject(&pen);

}


void CFiguresFrm::OnLButtonDown(UINT nFlags, CPoint point) 
{	
	m_cirRect.InflateRect(2,2);
	InvalidateRect(m_cirRect);
	m_cix = point.x;
	m_ciy = point.y;
	ChkCircle(0);
	InvalidateRect(RectCirc());
	
	CFrameWnd::OnLButtonDown(nFlags, point);
}

CRect CFiguresFrm::RectCirc()
{
	m_cirRect = CRect(m_cix-m_Radius,m_ciy-m_Radius,
		m_cix+m_Radius,m_ciy+m_Radius);
	return m_cirRect;
}


void CFiguresFrm::ChkCircle(bool chprop)
{
	CString sMessage;
	int newRadius = m_Radius;
	int cix = m_cix;
	int ciy = m_ciy;

	if(cix - newRadius < 0)
		if (chprop)
			newRadius += cix - newRadius;
		else
			cix = newRadius;
	if(cix + newRadius > m_frWidth)
		if (chprop)
			newRadius -= cix + newRadius - m_frWidth;
		else
			cix = m_frWidth - newRadius;
	if(ciy - newRadius < 0) 
		if (chprop)
			newRadius += ciy - newRadius;
		else
			ciy = newRadius;
	if(ciy + newRadius > m_frHeight)
		if (chprop)
			newRadius -= ciy + newRadius - m_frHeight;
		else
			ciy = m_frHeight - newRadius;
	if (chprop)
		if(newRadius < m_Radius)
		{
			m_Radius = newRadius;
			sMessage.Format("%d", m_Radius);
			m_editRad.SetWindowText(sMessage);
			sMessage.Format("Border reached: Radius was set to %d", m_Radius);
			SetMessageText(sMessage);
		}
		else
			SetMessageText("");
	if (!chprop)
		if (cix != m_cix || ciy != m_ciy)
		{
			m_ciy = ciy;
			m_cix = cix;
			sMessage.Format("Border reached: Center was set to %d,%d",
				m_cix, m_ciy);
			SetMessageText(sMessage);
		}
		else
			SetMessageText("");
	sMessage.Format("x: %d   y: %d",m_cix,m_ciy);
	m_wndStatusBar.SetPaneText(1,sMessage,1);
}
