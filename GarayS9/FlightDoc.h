// FlightDoc.h : interface of the CFlightDoc class
//
/////////////////////////////////////////////////////////////////////////////
#include "City.h"

#if !defined(AFX_FLIGHTDOC_H__7C8DDB49_C5FD_11D4_B112_000000000000__INCLUDED_)
#define AFX_FLIGHTDOC_H__7C8DDB49_C5FD_11D4_B112_000000000000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CFlightDoc : public CDocument
{
protected: // create from serialization only
	CFlightDoc();
	DECLARE_DYNCREATE(CFlightDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFlightDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	CCityArray m_cityArray;
	CFlightArray m_flightArray;
	virtual ~CFlightDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFlightDoc)
	afx_msg void OnFileOpentext();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLIGHTDOC_H__7C8DDB49_C5FD_11D4_B112_000000000000__INCLUDED_)
