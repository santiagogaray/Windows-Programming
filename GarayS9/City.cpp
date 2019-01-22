// City.cpp : implementation file
//

#include "stdafx.h"
#include "Flight.h"
#include "City.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCity

IMPLEMENT_SERIAL(CCity, CObject, 0)


CCity::CCity()
{
}


CCity::~CCity()
{
}


/////////////////////////////////////////////////////////////////////////////
// CCity serialization

void CCity::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_name << m_northLat << m_westLon;
	}
	else
	{
		ar >> m_name >> m_northLat >> m_westLon;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CCity commands

CCity& CCity::operator=(CCity & city)
{
	m_name = city.m_name;
	m_northLat = city.m_northLat;
	m_westLon = city.m_westLon;
	return * this;
}





/////////////////////////////////////////////////////////////////////////////
// CFlight

IMPLEMENT_SERIAL(CFlight, CObject, 0)

CFlight::CFlight()
{
}


CFlight::~CFlight()
{
}


/////////////////////////////////////////////////////////////////////////////
// CFlight serialization

void CFlight::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_DepTime << m_destCityInd << m_origCityInd;
	}
	else
	{
		ar >> m_DepTime >> m_destCityInd >> m_origCityInd;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CFlight commands


CFlight& CFlight::operator =(CFlight & flight)
{
	m_DepTime = flight.m_DepTime;
	m_destCityInd = flight.m_destCityInd;
	m_origCityInd = flight.m_origCityInd;
	return * this;
}
