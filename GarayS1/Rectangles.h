#if !defined(AFX_RECTANGLES_H__2695FEC5_9030_11D4_B0A1_4C8F49000000__INCLUDED_)
#define AFX_RECTANGLES_H__2695FEC5_9030_11D4_B0A1_4C8F49000000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Rectangles.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRectangles window

class CRectangles : public CStatic
{
// Construction
public:
	CRectangles();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRectangles)
	//}}AFX_VIRTUAL

// Implementation
public:
	int m_currect;
	virtual ~CRectangles();

	// Generated message map functions
protected:
	//{{AFX_MSG(CRectangles)
	afx_msg void OnPaint();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RECTANGLES_H__2695FEC5_9030_11D4_B0A1_4C8F49000000__INCLUDED_)
