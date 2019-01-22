
#if !defined(AFX_MAPVIEW_H__1D1A4B87_CD1E_11D4_B11E_000000000000__INCLUDED_)
#define AFX_MAPVIEW_H__1D1A4B87_CD1E_11D4_B11E_000000000000__INCLUDED_

#include "FlightDoc.h"	// Added by ClassView
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// MapView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMapView view

class CMapView : public CScrollView
{
protected:
	CMapView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CMapView)

// Attributes
public:

// Operations
public:
	bool bdestcity;
	CFlightDoc* GetDocument();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMapView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnInitialUpdate();     // first time after construct
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CMapView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CMapView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAPVIEW_H__1D1A4B87_CD1E_11D4_B11E_000000000000__INCLUDED_)
