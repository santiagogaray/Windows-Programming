// FlightDoc.cpp : implementation of the CFlightDoc class
//

#include "stdafx.h"
#include "Flight.h"

#include "FlightDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFlightDoc

IMPLEMENT_DYNCREATE(CFlightDoc, CDocument)

BEGIN_MESSAGE_MAP(CFlightDoc, CDocument)
	//{{AFX_MSG_MAP(CFlightDoc)
	ON_COMMAND(ID_FILE_OPENTEXT, OnFileOpentext)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFlightDoc construction/destruction

CFlightDoc::CFlightDoc()
{
	// TODO: add one-time construction code here

}

CFlightDoc::~CFlightDoc()
{
}

BOOL CFlightDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CFlightDoc serialization

void CFlightDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
	m_cityArray.Serialize(ar);
	m_flightArray.Serialize(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CFlightDoc diagnostics

#ifdef _DEBUG
void CFlightDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFlightDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFlightDoc commands

void AFXAPI SerializeElements <CCity> (CArchive& ar, CCity* pNewCity, int nCount )
{
	for (int i = 0; i < nCount; i++, pNewCity++)
	{
		pNewCity->Serialize(ar);
	}
}

void CFlightDoc::OnFileOpentext() 
{
	CString m_szInputFile;
	CString szcity;
	CCity city;
	CString stemp;
	int grad, min;

	CFileDialog dlg (TRUE, NULL, "cities.txt", 
		OFN_HIDEREADONLY, "Text files (.txt)|*.txt|All files (*.*)|*.*||"); 
	if (dlg.DoModal() == IDOK) 
	{ 
		m_szInputFile = dlg.GetPathName(); 
		CStdioFile theFile(m_szInputFile, CFile::modeRead);
		for (int i=0; i < 21 ; i++)
		{
			theFile.ReadString(szcity);
			city.m_name = szcity.Left(szcity.Find(" "));
			int div = city.m_name.Find("_");
			if (div >= 0)
			{
				stemp = city.m_name.Left(div)+" "+city.m_name.Mid(div+1);
				city.m_name = stemp;
			}
			szcity = szcity.Right(szcity.GetLength()-city.m_name.GetLength()-1);

			grad = atoi(szcity.Left(szcity.Find(" ")));
			szcity = szcity.Mid(szcity.Find(" ")+1);
			min = atoi(szcity.Left(szcity.Find(" ")));
			szcity = szcity.Mid(szcity.Find(" ")+1);
			city.m_northLat = grad + (float)min/60.0f;

			grad = atoi(szcity.Left(szcity.Find(" ")));
			szcity = szcity.Mid(szcity.Find(" ")+1);
			min = atoi(szcity.Left(szcity.Find(" ")));
			city.m_westLon = grad + (float)min/60.0f;

			m_cityArray.Add(city);
		
		}
		UpdateAllViews(NULL,2);
	} 


}
