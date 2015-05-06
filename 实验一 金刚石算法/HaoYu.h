// HaoYu.h : main header file for the HAOYU application
//

#if !defined(AFX_HAOYU_H__ECF5A269_BCB0_4CF2_B2F7_B72EFA8BF48C__INCLUDED_)
#define AFX_HAOYU_H__ECF5A269_BCB0_4CF2_B2F7_B72EFA8BF48C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CHaoYuApp:
// See HaoYu.cpp for the implementation of this class
//

class CHaoYuApp : public CWinApp
{
public:
	CHaoYuApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHaoYuApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CHaoYuApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HAOYU_H__ECF5A269_BCB0_4CF2_B2F7_B72EFA8BF48C__INCLUDED_)
