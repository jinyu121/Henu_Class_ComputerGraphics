// HYPoint.h: interface for the HYPoint class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HYPOINT_H__CC888A2A_8031_4441_BA21_4472C7FB160E__INCLUDED_)
#define AFX_HYPOINT_H__CC888A2A_8031_4441_BA21_4472C7FB160E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class HYPoint  
{
public:
	HYPoint();
	HYPoint(double,double,double);
	virtual ~HYPoint();
	double p[4];
};

#endif // !defined(AFX_HYPOINT_H__CC888A2A_8031_4441_BA21_4472C7FB160E__INCLUDED_)
