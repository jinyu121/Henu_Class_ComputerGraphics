// HaoYuView.h : interface of the CHaoYuView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HAOYUVIEW_H__93BE3D96_0DC1_4698_BFC3_8088401A676D__INCLUDED_)
#define AFX_HAOYUVIEW_H__93BE3D96_0DC1_4698_BFC3_8088401A676D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "HYFace.h"
#include "HYPoint.h"
#define poi_num 8
#define fac_num 6
#define pi 3.1415926535897932384626
#define ang_ang 5.0/360*pi
class CHaoYuView : public CView
{
protected: // create from serialization only
	CHaoYuView();
	DECLARE_DYNCREATE(CHaoYuView)

// Attributes
public:
	CHaoYuDoc* GetDocument();
	void DrawIt();
	void TransIt();
	void BaseMove(double xx,double yy,double zz);
	void SetTrans(double x11,double x12,double x13,double x14,double x21,double x22,double x23,double x24,double x31,double x32,double x33,double x34,double x41,double x42,double x43,double x44);
	HYPoint poi[poi_num];
	HYFace fac[fac_num];
	double trans[4][4];
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHaoYuView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHaoYuView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHaoYuView)
	afx_msg void OnMoveXD();
	afx_msg void OnMoveXU();
	afx_msg void OnMoveYD();
	afx_msg void OnMoveYU();
	afx_msg void OnMoveZD();
	afx_msg void OnMoveZU();
	afx_msg void OnRotateXC();
	afx_msg void OnRotateXR();
	afx_msg void OnRotateYC();
	afx_msg void OnRotateYR();
	afx_msg void OnRotateZC();
	afx_msg void OnRotateZR();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in HaoYuView.cpp
inline CHaoYuDoc* CHaoYuView::GetDocument()
   { return (CHaoYuDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HAOYUVIEW_H__93BE3D96_0DC1_4698_BFC3_8088401A676D__INCLUDED_)
