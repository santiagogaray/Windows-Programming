#if !defined(AFX_CITY_H__7C8DDB54_C5FD_11D4_B112_000000000000__INCLUDED_)
#define AFX_CITY_H__7C8DDB54_C5FD_11D4_B112_000000000000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <afxdisp.h>
// City.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCity document

class CCity : public CObject
{
public:
	CCity();           // protected constructor used by dynamic creation
	DECLARE_SERIAL(CCity)

// Attributes
public:

// Operations
public:

// Overrides
	public:
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
	protected:

// Implementation
public:
	CCity& operator=(CCity& city);
	CString m_name;
	double m_westLon;
	double m_northLat;
	virtual ~CCity();

protected:
};

typedef CArray<CCity, CCity&> CCityArray;






class CFlight : public CObject
{
public:
	CFlight();           // protected constructor used by dynamic creation
	DECLARE_SERIAL(CFlight)

// Attributes
public:

// Operations
public:

// Overrides
	public:
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
	protected:

// Implementation
public:
	CFlight& operator=(CFlight& flight);
	COleDateTime m_DepTime;
	WORD m_destCityInd;
	WORD m_origCityInd;
	virtual ~CFlight();

protected:
};

typedef CArray<CFlight, CFlight&> CFlightArray;






#endif // !defined(AFX_CITY_H__7C8DDB54_C5FD_11D4_B112_000000000000__INCLUDED_)
