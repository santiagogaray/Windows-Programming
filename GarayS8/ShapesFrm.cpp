// ShapesFrm.cpp : implementation file
//

#include "stdafx.h"
#include "Shapes.h"
#include "ShapesFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShapesFrm

CShapesFrm::CShapesFrm()
{
	m_nshape = 0;
	m_nselected = -1;
	m_nmoved = -1;
	m_nscaled =-1;
	m_bpaste =FALSE;
	m_butScale.CreateRectRgn(0,0,0,0);
	m_fillcolor = RGB(200,200,200);
	m_border = 1;
	m_bordercolor = RGB(0,0,0);
}

CShapesFrm::~CShapesFrm()
{
}


BEGIN_MESSAGE_MAP(CShapesFrm, CFrameWnd)
	//{{AFX_MSG_MAP(CShapesFrm)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUCIRCLE, OnCircleClicked)
	ON_BN_CLICKED(IDC_BURECTANGLE, OnRectangleClicked)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_BN_CLICKED(IDC_BUBORDER, OnSpinClicked)
	ON_BN_CLICKED(IDC_BUFILLCOLOR, OnFillColorClicked)
	ON_BN_CLICKED(IDC_BUBORDERCOLOR, OnBorderColorClicked)
	ON_BN_CLICKED(IDC_BUBACK, OnOneBackClicked)
	ON_BN_CLICKED(IDC_BUFRONT, OnOneFrontClicked)
	ON_BN_CLICKED(IDC_BUDELETE, OnDeleteClicked)
	ON_COMMAND(ID_FILE_LOAD, OnFileLoad)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_COMMAND(ID_EDIT_CUT, OnEditCut)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_1,
	ID_INDICATOR_2,
};


/////////////////////////////////////////////////////////////////////////////
// CShapesFrm message handlers

int CShapesFrm::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	m_wndStatusBar.Create(this);
	m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT));

	CRect rButton;
	GetViewRect(&rButton);
	rButton.left = rButton.right - 74;
	rButton.top -=7;
	m_groupall.Create("", WS_CHILD | WS_VISIBLE |WS_GROUP | BS_GROUPBOX,
		rButton, this, IDC_STATIC);
	rButton.DeflateRect(2,10,2,0);
	
	rButton.bottom = rButton.top+100;

	m_stgroupsh.Create("", WS_CHILD | WS_VISIBLE , rButton, this, IDC_STATIC);
	m_groupsh.Create("Shapes", WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
		rButton, this, IDC_STATIC);

	rButton.DeflateRect(5,20,5,55);

	m_bucircle.Create("Circle", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		rButton, this, IDC_BUCIRCLE);
	rButton += CPoint(0,32);
	m_burectangle.Create("Rect.", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		rButton, this, IDC_BURECTANGLE);

	rButton.InflateRect(5,-48,5,87);

	m_stgroupf.Create("", WS_CHILD | WS_VISIBLE , rButton, this, IDC_STATIC);
	rButton.InflateRect(0,0,0,32);
	m_groupf.Create("Colors", WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
		rButton, this, IDC_STATIC);

	rButton.DeflateRect(5,20,5,57);
	m_bufillcolor.Create("Fill", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		rButton, this, IDC_BUFILLCOLOR);
	rButton += CPoint(0,22);
	m_bubordercolor.Create("Border", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		rButton, this, IDC_BUBORDERCOLOR);
	rButton += CPoint(0,22);

	rButton.InflateRect(3,0,3,10);
	m_rFill =  rButton;

	rButton.InflateRect(2,-32,2,70);
	m_stgroupb.Create("", WS_CHILD | WS_VISIBLE , rButton, this, IDC_STATIC);
	m_groupb.Create("Border", WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
		rButton, this, IDC_STATIC);
	rButton.DeflateRect(5,20,40,30);

	m_edborder.Create( WS_CHILD | WS_VISIBLE | ES_CENTER | ES_READONLY,
		rButton, this, IDC_EDBORDER);
	rButton += CPoint(26,0);
	rButton.InflateRect(0,0,5,0);
	m_spborder.Create( WS_CHILD | WS_VISIBLE | UDS_AUTOBUDDY | UDS_SETBUDDYINT  |
		UDS_HORZ , rButton, this, IDC_SPBORDER);
	m_spborder.SetPos(1);
	m_spborder.SetRange(0,10);
	rButton.InflateRect(26,-20,0,20);
	m_buborder.Create("set", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		rButton, this, IDC_BUBORDER);

	rButton.InflateRect(5,-27,9,90);

	m_stgroupord.Create("", WS_CHILD | WS_VISIBLE , rButton, this, IDC_STATIC);
	m_groupord.Create("Order", WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
		rButton, this, IDC_STATIC);

	rButton.DeflateRect(5,20,5,37);
	m_buback.Create("1 back", WS_CHILD | WS_VISIBLE | WS_DISABLED | BS_PUSHBUTTON,
		rButton, this, IDC_BUBACK);
	rButton += CPoint(0,26);
	m_bufront.Create("1 front", WS_CHILD | WS_VISIBLE | WS_DISABLED | BS_PUSHBUTTON,
		rButton, this, IDC_BUFRONT);
	rButton.InflateRect(5,-34,5,35);
	m_budelete.Create("Delete", WS_CHILD | WS_VISIBLE | WS_DISABLED | BS_PUSHBUTTON,
		rButton, this, IDC_BUDELETE);

	return 0;
}

void CShapesFrm::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	CRect r;
	GetViewRect(&r);
//TODO - replace the following with your real painting code 
	dc.FillSolidRect(r, RGB(255,255,255));

	//Draw diplayed shapes	
	CPen bSel(PS_DOT,1,RGB(0,0,0));
	CBrush FillRgn(RGB(0,0,0));
	for (int i=0; i < m_nshape ; i++)
		if(m_aShape[i].display)
		{
			CPen Border(PS_SOLID,m_aShape[i].border,m_aShape[i].bordercolor);
			CBrush Fill(m_aShape[i].fillcolor);
			dc.SelectObject(Border);
			dc.SelectObject(Fill);
			if (m_aShape[i].border==0)
				dc.SelectStockObject(NULL_PEN);
			if (m_aShape[i].ntype == 1)
				dc.Ellipse(m_aShape[i].rect());
			if (m_aShape[i].ntype == 2)
				dc.Rectangle(m_aShape[i].rect());
		}

	//Draw Selected Rectangle and scale ctrl
	if(m_nselected>=0)
	{
		dc.SelectObject(bSel);
		dc.SelectStockObject(NULL_BRUSH);
		dc.Rectangle(m_aShape[m_nselected].selrect());
		dc.FillRgn(&m_butScale,&FillRgn);
	}

	//Update color/border swatch
	CString sborder;
	int bdr;
	COLORREF fclr;
	COLORREF bclr;
	CRect rf(m_rFill);
	if (m_nselected>=0)
	{
		bdr = m_aShape[m_nselected].border;
		fclr = m_aShape[m_nselected].fillcolor;
		bclr = m_aShape[m_nselected].bordercolor;
	}
	else
	{
		bdr = m_border;
		fclr = m_fillcolor;
		bclr = m_bordercolor;
	}
	rf.DeflateRect(bdr/2,bdr/2);
	CBrush swatchFill(fclr);
	CPen swatchBorder(PS_SOLID,bdr,bclr);
	dc.SelectObject(swatchFill);
	dc.SelectObject(swatchBorder);
	if (bdr==0)
		dc.SelectStockObject(NULL_PEN);
	dc.Rectangle(rf);
	sborder.Format("%d",bdr);
	m_edborder.SetWindowText(sborder);
}

void CShapesFrm::GetViewRect(LPRECT r)
{
	RepositionBars(0, 0xffff, AFX_IDW_PANE_FIRST, reposQuery, r);

}

BOOL CShapesFrm::PreCreateWindow(CREATESTRUCT& cs) 
{
//Remove the next line if you want a resizable window
	cs.style &= (~WS_THICKFRAME);
//This sets the width and height of the window
	cs.cx = 600;
	cs.cy = 438;
//This sets the title (in the caption bar)
	cs.lpszName = "Quick Shapes";

	return CFrameWnd::PreCreateWindow(cs);

}

void CShapesFrm::OnCircleClicked()
{
	if(m_nshape == 39)
	{
		SetMessageText("Can't draw more than 38 shapes");
		return;
	}
	m_aShape[m_nshape].ntype = 1;
	InitShape();
	m_aShape[m_nshape].sRgn.CreateEllipticRgnIndirect(m_aShape[m_nshape].rect());
	m_nshape++;

}


void CShapesFrm::OnRectangleClicked()
{
	if(m_nshape == 39)
	{
		SetMessageText("Can't draw more than 38 shapes");
		return;
	}
	m_aShape[m_nshape].ntype = 2;
	InitShape();
	m_aShape[m_nshape].sRgn.CreateRectRgnIndirect(m_aShape[m_nshape].rect());
	m_nshape++;

}

void CShapesFrm::InitShape()
{
	m_aShape[m_nshape].display = TRUE;
	m_aShape[m_nshape].width = 100;
	m_aShape[m_nshape].height = 100;
	m_aShape[m_nshape].TLpt.x = 200;
	m_aShape[m_nshape].TLpt.y = 200;
	m_aShape[m_nshape].border = m_border;
	m_aShape[m_nshape].fillcolor = m_fillcolor;
	m_aShape[m_nshape].bordercolor = m_bordercolor;
	m_aShape[m_nshape].sRgn.DeleteObject();
	m_nselected = m_nshape;
	SetScaleButton();
	Invalidate();
	if(m_nshape == 0)
		SetMessageText("Drag shape or scale with scale point");
	SetBarText();
	m_buback.EnableWindow(TRUE);
	m_bufront.EnableWindow(TRUE);
	m_budelete.EnableWindow(TRUE);

}

void CShapesFrm::OnLButtonDown(UINT nFlags, CPoint point) 
{

	bool bfound = FALSE;

	if (m_nselected>=0)
	{
		InvalidateRect(m_aShape[m_nselected].selrect());
		if(m_butScale.PtInRegion(point))
		{
			SetCapture();
//			m_aShape[m_nselected].bSelected = TRUE;
			m_nscaled = m_nselected;
			bfound = TRUE;
			m_oldwidth = m_aShape[m_nscaled].width;
			m_oldheight = m_aShape[m_nscaled].height;
			m_selOffset.x = point.x - m_aShape[m_nscaled].TLpt.x - 
				m_aShape[m_nscaled].width;
			m_selOffset.y = point.y - m_aShape[m_nscaled].TLpt.y - 
				m_aShape[m_nscaled].height;
			return;
		}
	}

	for (int i=m_nshape-1; i >=0 && !bfound; i--)
	{
		
		if(m_aShape[i].display)
			if(m_aShape[i].sRgn.PtInRegion(point))
			{
				SetCapture();
				m_selOffset = point - m_aShape[i].TLpt;
				m_nselected = i;
				SetScaleButton();
				InvalidateRect(m_aShape[m_nselected].selrect());
				m_nmoved = i;
				bfound = TRUE;
				m_oldwidth = m_aShape[m_nselected].TLpt.x;
				m_oldheight = m_aShape[m_nselected].TLpt.y;
				SetBarText();
			}
	}
	InvalidateRect(m_rFill);

	if (!bfound)
	{
		m_nselected = -1;
		m_wndStatusBar.SetPaneText(1,"Center:  x:        y:      ",1);
		m_wndStatusBar.SetPaneText(2,"Width:         Heigth:      ",1);
	}

	m_buback.EnableWindow(bfound);
	m_bufront.EnableWindow(bfound);
	m_budelete.EnableWindow(bfound);

	CFrameWnd::OnLButtonDown(nFlags, point);
}

void CShapesFrm::OnMouseMove(UINT nFlags, CPoint point) 
{

	if(m_nmoved>=0)
	{
		InvalidateRect(m_aShape[m_nmoved].selrect());
		m_butScale.OffsetRgn(-(m_aShape[m_nmoved].TLpt - (point - m_selOffset)));
		m_aShape[m_nmoved].TLpt = point - m_selOffset;
		InvalidateRect(m_aShape[m_nmoved].selrect());
		int difx = m_aShape[m_nmoved].TLpt.x - m_oldwidth;
		int dify = m_aShape[m_nmoved].TLpt.y - m_oldheight;
		m_smsg.Format("Moving: x: %d  y: %d", difx, dify);
		SetMessageText(m_smsg);
		SetBarText();
	}
		
	if(m_nscaled>=0)
	{	
		InvalidateRect(m_aShape[m_nscaled].selrect());
		m_aShape[m_nscaled].width = point.x - 
			m_aShape[m_nscaled].TLpt.x - m_selOffset.x;
		m_aShape[m_nscaled].height = point.y -
			m_aShape[m_nscaled].TLpt.y - m_selOffset.y;
		if (m_aShape[m_nscaled].width <=13)
			m_aShape[m_nscaled].width = 13;
		if (m_aShape[m_nscaled].height <=13)
			m_aShape[m_nscaled].height = 13;
		SetScaleButton();
		InvalidateRect(m_aShape[m_nscaled].selrect());
		float scalew = (float)m_aShape[m_nscaled].width/(float)m_oldwidth*100;
		float scaleh = (float)m_aShape[m_nscaled].height/(float)m_oldheight*100;
		m_smsg.Format("Scaling: width: %.f %%  height: %.f %%", scalew, scaleh);
		SetMessageText(m_smsg);
		SetBarText();
	}

	if (m_nshape ==0)
		SetMessageText("Create shapes or load shapes file");

	CFrameWnd::OnMouseMove(nFlags, point);
}

void CShapesFrm::OnLButtonUp(UINT nFlags, CPoint point) 
{
	if (m_nmoved>=0)
	{
		CRgn rgn;
		ReleaseCapture();
		if (m_aShape[m_nmoved].ntype == 1)
			rgn.CreateEllipticRgnIndirect(m_aShape[m_nmoved].selrect());
		if (m_aShape[m_nmoved].ntype == 2)
			rgn.CreateRectRgnIndirect(m_aShape[m_nmoved].selrect());
		m_aShape[m_nmoved].sRgn.CopyRgn(&rgn);
		m_nmoved = -1;
	}
	if (m_nscaled >=0)
	{
		CRgn rgn;
		ReleaseCapture();
		if (m_aShape[m_nscaled].ntype == 1)
			rgn.CreateEllipticRgnIndirect(m_aShape[m_nscaled].selrect());
		if (m_aShape[m_nscaled].ntype == 2)
			rgn.CreateRectRgnIndirect(m_aShape[m_nscaled].selrect());
		m_aShape[m_nscaled].sRgn.CopyRgn(&rgn);
		m_nscaled = -1;
	}
	SetMessageText("");

	CFrameWnd::OnLButtonUp(nFlags, point);
}

void CShapesFrm::OnSpinClicked()
{
	CString sborder;
	m_edborder.GetWindowText(sborder);
	if (m_nselected >=0)
	{
		InvalidateRect(m_aShape[m_nselected].selrect());
		m_aShape[m_nselected].border = atoi(sborder);
		SetScaleButton();
		InvalidateRect(m_aShape[m_nselected].selrect());
	}
	else
		m_border = atoi(sborder);

	InvalidateRect(m_rFill);

}

void CShapesFrm::OnFillColorClicked()
{
	CColorDialog dlg;
	if(dlg.DoModal() == IDOK)
		if(m_nselected>=0)
		{
			m_aShape[m_nselected].fillcolor = dlg.GetColor();
			InvalidateRect(m_aShape[m_nselected].selrect());
		}
		else
			m_fillcolor = dlg.GetColor();
			
	InvalidateRect(m_rFill);


}

void CShapesFrm::OnBorderColorClicked()
{
	CColorDialog dlg;
	if(dlg.DoModal() == IDOK)
		if(m_nselected>=0)
		{
			m_aShape[m_nselected].bordercolor = dlg.GetColor();
			InvalidateRect(m_aShape[m_nselected].selrect());
		}
		else
			m_bordercolor = dlg.GetColor();
			
	InvalidateRect(m_rFill);


}

void CShapesFrm::OnOneBackClicked()
{
	if(m_nselected <= 0)
		return;

	SwitchShapes( m_nselected, m_nselected-1);
	m_nselected--;
	InvalidateRect(m_aShape[m_nselected].selrect());
}

void CShapesFrm::OnOneFrontClicked()
{
	if(m_nselected == m_nshape-1 || m_nselected == -1)
		return;

	SwitchShapes( m_nselected, m_nselected+1);
	m_nselected++;
	InvalidateRect(m_aShape[m_nselected].selrect());
}




void CShapesFrm::SwitchShapes(int orig, int dest)
{

	Shape shtemp;
	shtemp.sRect = m_aShape[dest].rect();
	shtemp.display = m_aShape[dest].display;
	shtemp.height = m_aShape[dest].height;
	shtemp.width = m_aShape[dest].width;
	shtemp.border = m_aShape[dest].border;
	shtemp.fillcolor = m_aShape[dest].fillcolor;
	shtemp.bordercolor = m_aShape[dest].bordercolor;
	shtemp.ntype = m_aShape[dest].ntype;
	shtemp.TLpt = m_aShape[dest].TLpt;
	shtemp.sRgn.CreateRectRgnIndirect(m_aShape[dest].rect());

	m_aShape[dest].sRect = m_aShape[orig].rect();
	m_aShape[dest].display = m_aShape[orig].display;
	m_aShape[dest].height = m_aShape[orig].height;
	m_aShape[dest].width = m_aShape[orig].width;
	m_aShape[dest].border = m_aShape[orig].border;
	m_aShape[dest].fillcolor = m_aShape[orig].fillcolor;
	m_aShape[dest].bordercolor = m_aShape[orig].bordercolor;
	m_aShape[dest].ntype = m_aShape[orig].ntype;
	m_aShape[dest].TLpt = m_aShape[orig].TLpt;
	m_aShape[dest].sRgn.CopyRgn(&m_aShape[orig].sRgn);

	m_aShape[orig].sRect = shtemp.rect();
	m_aShape[orig].display = shtemp.display;
	m_aShape[orig].height = shtemp.height;
	m_aShape[orig].width = shtemp.width;
	m_aShape[orig].border = shtemp.border;
	m_aShape[orig].fillcolor = shtemp.fillcolor;
	m_aShape[orig].bordercolor = shtemp.bordercolor;
	m_aShape[orig].ntype = shtemp.ntype;
	m_aShape[orig].TLpt = shtemp.TLpt;
	m_aShape[orig].sRgn.CopyRgn(&shtemp.sRgn);
	

}

void CShapesFrm::CopyShape(int orig, int dest)
{
	m_aShape[dest].sRect = m_aShape[orig].rect();
	m_aShape[dest].display = m_aShape[orig].display;
	m_aShape[dest].height = m_aShape[orig].height;
	m_aShape[dest].width = m_aShape[orig].width;
	m_aShape[dest].border = m_aShape[orig].border;
	m_aShape[dest].fillcolor = m_aShape[orig].fillcolor;
	m_aShape[dest].bordercolor = m_aShape[orig].bordercolor;
	m_aShape[dest].ntype = m_aShape[orig].ntype;
	m_aShape[dest].TLpt = m_aShape[orig].TLpt;
	m_aShape[dest].sRgn.DeleteObject();
	m_aShape[dest].sRgn.CreateRectRgn(0,0,0,0);
	m_aShape[dest].sRgn.CopyRgn(&m_aShape[orig].sRgn);
}

void CShapesFrm::SetScaleButton()
{
	CRect r = m_aShape[m_nselected].selrect();
	r.DeflateRect(m_aShape[m_nselected].width +
		m_aShape[m_nselected].border-12,
		m_aShape[m_nselected].height+
		m_aShape[m_nselected].border-12,2,2);
	m_butScale.SetRectRgn(r);

}

void CShapesFrm::SetBarText()
{
		m_smsg.Format("Center:  x: %d  y: %d",
			m_aShape[m_nselected].TLpt.x+m_aShape[m_nselected].width/2,
			m_aShape[m_nselected].TLpt.y+m_aShape[m_nselected].height/2);
		m_wndStatusBar.SetPaneText(1,m_smsg,1);
		m_smsg.Format("Width: %d   Height: %d",m_aShape[m_nselected].width,
			m_aShape[m_nselected].height);
		m_wndStatusBar.SetPaneText(2,m_smsg,1);

}

void CShapesFrm::OnFileLoad() 
{
	CFileDialog dlg (TRUE, NULL, "shapes.txt", 
		OFN_HIDEREADONLY, "Text files (.txt)|*.txt|All files (*.*)|*.*||"); 
	if (dlg.DoModal() == IDOK) 
	{
		CString stemp;
		CStdioFile inFile(dlg.GetPathName(), CFile::modeRead); 
		inFile.ReadString(stemp);
		m_nshape = atoi(stemp);
		if (m_nshape > 38)
			m_nshape = 38;
		inFile.ReadString(stemp);
		for (int i = 0 ; i < m_nshape; i++)
		{
				inFile.ReadString(stemp);
				if (atoi(stemp) == 0)
					m_aShape[i].display = FALSE;
				else
					m_aShape[i].display = TRUE;
				inFile.ReadString(stemp);
				m_aShape[i].height = atoi(stemp);
				inFile.ReadString(stemp);
				m_aShape[i].width = atoi(stemp);
				inFile.ReadString(stemp);
				m_aShape[i].border = atoi(stemp);
				inFile.ReadString(stemp);
				m_aShape[i].fillcolor = atoi(stemp);
				inFile.ReadString(stemp);
				m_aShape[i].bordercolor = atoi(stemp);
				inFile.ReadString(stemp);
				m_aShape[i].ntype = atoi(stemp);
				inFile.ReadString(stemp);
				m_aShape[i].TLpt.x = atoi(stemp);
				inFile.ReadString(stemp);
				m_aShape[i].TLpt.y = atoi(stemp);
				inFile.ReadString(stemp);

				m_aShape[i].sRgn.DeleteObject();
				if(m_aShape[i].ntype == 1)
					m_aShape[i].sRgn.CreateEllipticRgnIndirect(m_aShape[i].rect());
				else
					m_aShape[i].sRgn.CreateRectRgnIndirect(m_aShape[i].rect());

		}
		inFile.Close();
	} 
	m_nscaled = -1;
	m_nmoved = -1;
	m_nselected = -1;
	m_buback.EnableWindow(FALSE);
	m_bufront.EnableWindow(FALSE);
	m_budelete.EnableWindow(FALSE);

	Invalidate();

}

void CShapesFrm::OnFileSave() 
{
	if (m_nshape == 0)
	{
		SetMessageText("Can't save empty drawing");
		return;
	}


	CFileDialog dlg(FALSE, "txt", "shapes.txt", OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, 
		"Text Files (*.txt)|*.txt|All Files (*.*)|*.*||"); 
	if (dlg.DoModal() == IDOK) 
	{ 
		CString stemp;
		CStdioFile outFile(dlg.GetPathName(), CFile::modeWrite | CFile::modeCreate); 
		stemp.Format("%d", m_nshape);
		outFile.WriteString( stemp + "\n" + "\n");
		for (int i = 0 ; i < m_nshape; i++)
		{
				stemp.Format("%d", m_aShape[i].display);
				outFile.WriteString( stemp + "\n"); 
				stemp.Format("%d",m_aShape[i].height);
				outFile.WriteString( stemp + "\n"); 
				stemp.Format("%d",m_aShape[i].width);
				outFile.WriteString( stemp + "\n"); 
				stemp.Format("%d",m_aShape[i].border);
				outFile.WriteString( stemp + "\n"); 
				stemp.Format("%d",m_aShape[i].fillcolor);
				outFile.WriteString( stemp + "\n"); 
				stemp.Format("%d",m_aShape[i].bordercolor);
				outFile.WriteString( stemp + "\n"); 
				stemp.Format("%d",m_aShape[i].ntype);
				outFile.WriteString( stemp + "\n"); 
				stemp.Format("%d",m_aShape[i].TLpt.x);
				outFile.WriteString( stemp + "\n"); 
				stemp.Format("%d",m_aShape[i].TLpt.y);
				outFile.WriteString( stemp + "\n" + "\n"); 
		} 

	}
}


void CShapesFrm::OnDeleteClicked()
{
	if (m_nshape == 0 || m_nselected ==-1)
		return;
	if (m_nshape > 1)
		for (int i = m_nselected; i < m_nshape-1; i++)
			CopyShape(i+1, i);
	m_nshape--;
	m_nselected = -1;
	m_buback.EnableWindow(FALSE);
	m_bufront.EnableWindow(FALSE);
	m_budelete.EnableWindow(FALSE);
	Invalidate();
	
}


void CShapesFrm::OnEditCopy() 
{
	if (m_nselected == -1 || m_nshape >=39)
		return;
	CopyShape(m_nselected, 40);
	m_bpaste = TRUE;

}

void CShapesFrm::OnEditCut() 
{
	if (m_nselected == -1 || m_nshape >=39)
		return;
	CopyShape(m_nselected, 40);
	OnDeleteClicked();
	m_bpaste = TRUE;	
}

void CShapesFrm::OnEditPaste() 
{
	if(!m_bpaste || m_nshape >=39)
	{
		SetMessageText("Can't draw more than 38 shapes");
		return;
	}

	CopyShape(40, m_nshape);
	m_aShape[m_nshape].TLpt.x += 5;
	m_aShape[m_nshape].TLpt.y += 5;
	InvalidateRect(m_aShape[m_nshape].selrect());
	m_nshape++;
}

