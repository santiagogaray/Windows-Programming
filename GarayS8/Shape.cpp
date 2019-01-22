// Shape.cpp: implementation of the Shape class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Shapes.h"
#include "Shape.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Shape::Shape()
{
	display = FALSE;
	
}

Shape::~Shape()
{

}


CRect Shape::rect()
{
	sRect = CRect(TLpt.x, TLpt.y, TLpt.x+width, TLpt.y+height);
	return sRect;
}

CRect Shape::selrect()
{
	CRect r(TLpt.x-border/2, TLpt.y-border/2,
		TLpt.x+width + border/2, TLpt.y+height+border/2);
	return r;

}
