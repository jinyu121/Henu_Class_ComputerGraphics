// HYPoint.cpp: implementation of the HYPoint class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HaoYu.h"
#include "HYPoint.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

HYPoint::HYPoint()
{

}

HYPoint::HYPoint(double xx,double yy,double zz)
{
	this->p[0]=xx;
	this->p[1]=yy;
	this->p[2]=zz;
	this->p[3]=1;
}

HYPoint::~HYPoint()
{

}
