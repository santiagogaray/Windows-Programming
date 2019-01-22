// FlightView.h : interface of the CFlightView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FLIGHTVIEW_H__7C8DDB4B_C5FD_11D4_B112_000000000000__INCLUDED_)
#define AFX_FLIGHTVIEW_H__7C8DDB4B_C5FD_11D4_B112_000000000000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CFlightView : public CFormView
{
protected: // create from serialization only
	CFlightView();
	DECLARE_DYNCREATE(CFlightView)

public:
	//{{AFX_DATA(CFlightView)
	enum { IDD = IDD_FLIGHT_FORM };
	CListCtrl	m_flightListCtrl;
	CListCtrl	m_cityListCtrl;
	CString	m_cityName;
	float	m_northLat;
	float	m_westLon;
	int		m_origCity;
	int		m_destCity;
	CString	m_departureTime;
	//}}AFX_DATA

// Attributes
public:
	CFlightDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFlightView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
public:
	CString DecToMin(double num);
	void DisplayFlights(CFlightArray & flights);
	void DisplayCities(CCityArray & cities);
	int m_flightIndex;
	int m_cityIndex;
	bool m_bInitDone;
	CFlightArray* m_pFlightArray;
	CCityArray* m_pCityArray;
	virtual ~CFlightView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFlightView)
	afx_msg void OnAddCity();
	afx_msg void OnAddFlight();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in FlightView.cpp
inline CFlightDoc* CFlightView::GetDocument()
   { return (CFlightDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLIGHTVIEW_H__7C8DDB4B_C5FD_11D4_B112_000000000000__INCLUDED_)
