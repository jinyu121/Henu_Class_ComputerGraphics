// HYFace.h: interface for the HYFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HYFACE_H__6AD67C1F_2310_4563_BEBD_68E6DC9F672F__INCLUDED_)
#define AFX_HYFACE_H__6AD67C1F_2310_4563_BEBD_68E6DC9F672F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class HYFace  
{
public:
	HYFace();
	HYFace(int);
	virtual ~HYFace();
	int num_p;
	int index[10];
};

#endif // !defined(AFX_HYFACE_H__6AD67C1F_2310_4563_BEBD_68E6DC9F672F__INCLUDED_)
