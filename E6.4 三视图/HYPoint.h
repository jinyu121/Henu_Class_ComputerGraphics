// HYPoint.h: interface for the HYPoint class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HYPOINT_H__4F37A5A9_5EC9_4FF2_93B5_9189247D0CB9__INCLUDED_)
#define AFX_HYPOINT_H__4F37A5A9_5EC9_4FF2_93B5_9189247D0CB9__INCLUDED_

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

#endif // !defined(AFX_HYPOINT_H__4F37A5A9_5EC9_4FF2_93B5_9189247D0CB9__INCLUDED_)
