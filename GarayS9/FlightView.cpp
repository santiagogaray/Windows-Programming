// FlightView.cpp : implementation of the CFlightView class
//

#include "stdafx.h"
#include "Flight.h"

#include "FlightDoc.h"
#include "FlightView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFlightView

IMPLEMENT_DYNCREATE(CFlightView, CFormView)

BEGIN_MESSAGE_MAP(CFlightView, CFormView)
	//{{AFX_MSG_MAP(CFlightView)
	ON_BN_CLICKED(IDC_ADD_CITY, OnAddCity)
	ON_BN_CLICKED(IDC_ADD_FLIGHT, OnAddFlight)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFlightView construction/destruction

CFlightView::CFlightView()
	: CFormView(CFlightView::IDD)
{
	//{{AFX_DATA_INIT(CFlightView)
	m_cityName = _T("");
	m_northLat = 0.0f;
	m_westLon = 0.0f;
	m_origCity = 0;
	m_destCity = 0;
	m_departureTime = _T("");
	//}}AFX_DATA_INIT
	// TODO: add construction code here
	m_bInitDone = FALSE;
}

CFlightView::~CFlightView()
{
}

void CFlightView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFlightView)
	DDX_Control(pDX, IDC_FLIGHT_LIST, m_flightListCtrl);
	DDX_Control(pDX, IDC_CITY_LIST, m_cityListCtrl);
	DDX_Text(pDX, IDC_NAME, m_cityName);
	DDX_Text(pDX, IDC_NORTHLAT, m_northLat);
	DDX_Text(pDX, IDC_WESTLON, m_westLon);
	DDX_Text(pDX, IDC_ORIG_CITY, m_origCity);
	DDX_Text(pDX, IDC_DEST_CITY, m_destCity);
	DDX_Text(pDX, IDC_DEP_TIME, m_departureTime);
	//}}AFX_DATA_MAP
}

BOOL CFlightView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CFlightView diagnostics

#ifdef _DEBUG
void CFlightView::AssertValid() const
{
	CFormView::AssertValid();
}

void CFlightView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CFlightDoc* CFlightView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFlightDoc)));
	return (CFlightDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFlightView message handlers

void CFlightView::OnAddCity() 
{
	CCity city;
	UpdateData(TRUE);
	city.m_name = m_cityName;
	city.m_northLat = m_northLat;
	city.m_westLon = m_westLon;
	m_pCityArray->Add(city);
	DisplayCities(*m_pCityArray);
	m_cityName = "";
	m_northLat = 0;
	m_westLon = 0;
	UpdateData(FALSE);
	GetDocument()->UpdateAllViews(this);

}

void CFlightView::OnAddFlight() 
{

	CFlight flight;
	UpdateData(TRUE);
	if (!flight.m_DepTime.ParseDateTime(m_departureTime, VAR_TIMEVALUEONLY))
	{
		AfxMessageBox("Use the form hh:mm:ss for the time");
		return;
	}
	flight.m_origCityInd = m_origCity;
	flight.m_destCityInd = m_destCity;
	m_pFlightArray->Add(flight);
	DisplayFlights(*m_pFlightArray);
	m_departureTime = "";
	m_origCity = 0;
	m_destCity = 0;
	UpdateData(FALSE);
	GetDocument()->UpdateAllViews(this);

}

void CFlightView::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	

	if (!m_bInitDone)
	{
		m_cityListCtrl.InsertColumn(0, "Name", LVCFMT_LEFT, 74, 0);
		m_cityListCtrl.InsertColumn(1, "N.Lat.", LVCFMT_LEFT, 45, 0);
		m_cityListCtrl.InsertColumn(2, "W.Lon.", LVCFMT_LEFT, 45, 0);

		m_flightListCtrl.InsertColumn(0, "Dep.Time", LVCFMT_LEFT, 65, 0);
		m_flightListCtrl.InsertColumn(1, "Orig.City", LVCFMT_LEFT, 50, 0);
		m_flightListCtrl.InsertColumn(2, "Dest.City", LVCFMT_LEFT, 50, 0);

		m_bInitDone = TRUE;
	}
	m_cityListCtrl.DeleteAllItems();
	m_pCityArray = &GetDocument()->m_cityArray;
	for (int i = 0;  i < m_pCityArray->GetSize(); i++)
	{
		m_cityListCtrl.InsertItem(i, m_pCityArray->ElementAt(i).m_name);	
		m_cityListCtrl.SetItemText(i, 1, DecToMin(m_pCityArray->ElementAt(i).m_northLat));
		m_cityListCtrl.SetItemText(i, 2, DecToMin(m_pCityArray->ElementAt(i).m_westLon));
	}

		
	m_flightListCtrl.DeleteAllItems();
	m_pFlightArray = &GetDocument()->m_flightArray;
	for (i = 0;  i < m_pFlightArray->GetSize(); i++)
	{
		CString sDepTime;
		sDepTime = (m_pFlightArray->ElementAt(i).m_DepTime).Format();
		CString sDCity;
		sDCity.Format("%d", m_pFlightArray->ElementAt(i).m_destCityInd);
		CString sOCity;
		sOCity.Format("%d", m_pFlightArray->ElementAt(i).m_origCityInd);
		m_flightListCtrl.InsertItem(i, sDepTime);	
		m_flightListCtrl.SetItemText(i, 1, sOCity);
		m_flightListCtrl.SetItemText(i, 2, sDCity);
	}

}

void CFlightView::DisplayCities(CCityArray & cities)
{

	m_cityListCtrl.DeleteAllItems();
	for (int i = 0; i < cities.GetSize(); i++)
	{
		m_cityListCtrl.InsertItem(i, cities[i].m_name);
		m_cityListCtrl.SetItemText(i, 1, DecToMin(cities[i].m_northLat));
		m_cityListCtrl.SetItemText(i, 2, DecToMin(cities[i].m_westLon));
	}

}

void CFlightView::DisplayFlights(CFlightArray & flights)
{
	m_flightListCtrl.DeleteAllItems();
	for (int i = 0; i < flights.GetSize(); i++)
	{
		CString sDepTime;
		sDepTime = flights[i].m_DepTime.Format();
		CString sDCity;
		sDCity.Format("%d", flights[i].m_destCityInd);
		CString sOCity;
		sOCity.Format("%d", flights[i].m_origCityInd);
		m_flightListCtrl.InsertItem(i, sDepTime);	
		m_flightListCtrl.SetItemText(i, 1, sOCity);
		m_flightListCtrl.SetItemText(i, 2, sDCity);
	}

}

CString CFlightView::DecToMin(double num)
{
	CString sGrad, sMin;
	sGrad.Format("%d",(int) num);
	sMin.Format("%d", (int)((num - (int)num)*60.00));
	return sGrad + "°" + " "+ sMin + "'";

}

void CFlightView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	if(lHint == 2)
		OnInitialUpdate();

	if (lHint == 3)
		UpdateData(FALSE);
	
}
