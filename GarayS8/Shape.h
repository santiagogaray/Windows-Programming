// Shape.h: interface for the Shape class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHAPE_H__56DC3495_BC2F_11D4_B104_000000000000__INCLUDED_)
#define AFX_SHAPE_H__56DC3495_BC2F_11D4_B104_000000000000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class Shape  
{
public:
	CRect selrect();
	int ntype;
	CRect rect();
	CPoint TLpt;
	COLORREF bordercolor;
	int border;
	COLORREF fillcolor;
	bool display;
	int height;
	int width;
	CRect sRect;
	CRgn sRgn;
	Shape();
	virtual ~Shape();

};

#endif // !defined(AFX_SHAPE_H__56DC3495_BC2F_11D4_B104_000000000000__INCLUDED_)
