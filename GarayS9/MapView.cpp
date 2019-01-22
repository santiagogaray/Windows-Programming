// MapView.cpp : implementation file
//


#include "stdafx.h"
#include "flight.h"
#include "MapView.h"
#include "FlightDoc.h"
#include "MainFrm.h"
#include "FlightView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMapView

IMPLEMENT_DYNCREATE(CMapView, CScrollView)

CMapView::CMapView()
{
	bdestcity = FALSE;
}

CMapView::~CMapView()
{
}


BEGIN_MESSAGE_MAP(CMapView, CScrollView)
	//{{AFX_MSG_MAP(CMapView)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMapView drawing

void CMapView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = 2200;
	sizeTotal.cy = 1250;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

void CMapView::OnDraw(CDC* pDC)
{
	CFlightDoc* pDoc = GetDocument();

// Grid
	CPen GrayPen (PS_SOLID, 1, RGB(180,180,180));
	for (int stp=1; stp <=5; stp+=4)
	{
	if (stp ==1)
		pDC->SelectObject(GrayPen);
	else
		pDC->SelectStockObject(BLACK_PEN);

		for (int i=0; i < 2200; i+=40*stp)
		{
			pDC->MoveTo(i,0);
			pDC->LineTo(i,1250);
		}
		for (int c=0; c < 1250; c+=50*stp)
		{
			pDC->MoveTo(0,c);
			pDC->LineTo(2200,c);
		}
	}

//Cities
	pDC->SetBkMode(TRANSPARENT);
	pDC->SelectStockObject(BLACK_BRUSH);
	for (int i=0; i < pDoc->m_cityArray.GetSize(); i++)
	{
		int ypos =(int) ((50-pDoc->m_cityArray.ElementAt(i).m_northLat)*50);
		int xpos =(int) ((125-pDoc->m_cityArray.ElementAt(i).m_westLon)*40);
		pDC->Ellipse(xpos-5, ypos-5, xpos+5, ypos+5);
		CRect r(xpos+10, ypos-10, xpos+130, ypos+10);
		pDC->DrawText(pDoc->m_cityArray.ElementAt(i).m_name, -1, r, DT_LEFT |
			DT_VCENTER  | DT_SINGLELINE );
	}

//Flights
	CPen DotPen (PS_DOT, 1, RGB(0,0,0));
	pDC->SelectObject(DotPen);

	for ( i=0; i < pDoc->m_flightArray.GetSize(); i++)
	{
		int or_x = (int) ((125-pDoc->m_cityArray.ElementAt(pDoc->
			m_flightArray.ElementAt(i).m_origCityInd-1).m_westLon)*40);
		int or_y = (int) ((50-pDoc->m_cityArray.ElementAt(pDoc->
			m_flightArray.ElementAt(i).m_origCityInd-1).m_northLat)*50);
		int de_x = (int) ((125-pDoc->m_cityArray.ElementAt(pDoc->
			m_flightArray.ElementAt(i).m_destCityInd-1).m_westLon)*40);
		int de_y = (int) ((50-pDoc->m_cityArray.ElementAt(pDoc->
			m_flightArray.ElementAt(i).m_destCityInd-1).m_northLat)*50);
		pDC->MoveTo(or_x, or_y);
		pDC->LineTo(de_x, de_y);
	}

}

/////////////////////////////////////////////////////////////////////////////
// CMapView diagnostics

#ifdef _DEBUG
void CMapView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CMapView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMapView message handlers

CFlightDoc* CMapView::GetDocument()
{
	return (CFlightDoc*)m_pDocument;
}

void CMapView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	POSITION pos = GetDocument()->GetFirstViewPosition ();
	CFlightView* pFView = (CFlightView*)GetDocument()->GetNextView(pos);
	CFlightDoc* pDoc = GetDocument();
	CClientDC dc (this);
	OnPrepareDC(&dc);
	dc.DPtoLP(&point);
	for (int i=0; i < pDoc->m_cityArray.GetSize(); i++)
	{
		int city_x = (int)((125-pDoc->m_cityArray.ElementAt(i).m_westLon)*40);
		int city_y = (int)((50-pDoc->m_cityArray.ElementAt(i).m_northLat)*50);
		if (point.x > city_x-10 && point.x < city_x+10 &&
			point.y > city_y-10 && point.y < city_y+10)
		{

			CString scitysel= "New Flight mode:  " + pDoc->m_cityArray.ElementAt(i).m_name + 
				" selected/Index box updated.  ";
			if (bdestcity)
			{
				scitysel += " Now type Departure time.";

				pFView->m_destCity = i+1;
				GetDocument()->UpdateAllViews(this,3);
			}
			else
			{
				scitysel += " Now pick or type Destination city.";
				pFView->m_origCity = i+1;
				GetDocument()->UpdateAllViews(this,3);
				
			}
			bdestcity = !bdestcity;
			((CMainFrame*)AfxGetMainWnd())->SetMessageText(scitysel);
			return;
		}
	}
	float Nlat = 50.0f-point.y/50.0f;
	float Wlon = 125.0f-point.x/40.0f;
	pFView->m_northLat = Nlat;
	pFView->m_westLon = Wlon;
	((CMainFrame*)AfxGetMainWnd())->SetMessageText
		("New City mode:  Long/Lat Boxes updated. Now type City name.");

	GetDocument()->UpdateAllViews(this,3);


	CScrollView::OnLButtonDown(nFlags, point);
}

void CMapView::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView) 
{

	((CMainFrame*)AfxGetMainWnd())->SetMessageText("");
	
	CScrollView::OnActivateView(bActivate, pActivateView, pDeactiveView);
}
