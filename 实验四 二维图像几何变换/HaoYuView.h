// HaoYuView.h : interface of the CHaoYuView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HAOYUVIEW_H__E4D9A193_D6EA_4172_B464_9AB965898F48__INCLUDED_)
#define AFX_HAOYUVIEW_H__E4D9A193_D6EA_4172_B464_9AB965898F48__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define UPLIMIT 4
#define STEP 5

class CHaoYuView : public CView {
protected: // create from serialization only
    CHaoYuView();
    DECLARE_DYNCREATE ( CHaoYuView )

// Attributes
public:
    CHaoYuDoc* GetDocument();

// Operations
public:

// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CHaoYuView)
public:
    virtual void OnDraw ( CDC* pDC ); // overridden to draw this view
    virtual BOOL PreCreateWindow ( CREATESTRUCT& cs );
protected:
    virtual BOOL OnPreparePrinting ( CPrintInfo* pInfo );
    virtual void OnBeginPrinting ( CDC* pDC, CPrintInfo* pInfo );
    virtual void OnEndPrinting ( CDC* pDC, CPrintInfo* pInfo );
    //}}AFX_VIRTUAL

// Implementation
public:
    virtual ~CHaoYuView();
    void ready ( CDC* pDC );
	void reDraw ();
	void Change(double* inMat,int mx,int my);
	CPoint p[UPLIMIT];
	int scale;
#ifdef _DEBUG
    virtual void AssertValid() const;
    virtual void Dump ( CDumpContext& dc ) const;
#endif

protected:

// Generated message map functions
protected:
    //{{AFX_MSG(CHaoYuView)
	afx_msg void OnHyClr();
	afx_msg void OnHyCud();
	afx_msg void OnHyDown();
	afx_msg void OnHyLeft();
	afx_msg void OnHyLr();
	afx_msg void OnHyRight();
	afx_msg void OnHyScaleDown();
	afx_msg void OnHyScaleUp();
	afx_msg void OnHyUd();
	afx_msg void OnHyUp();
	afx_msg void OnHyRotateA();
	afx_msg void OnHyRotateB();
	//}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in HaoYuView.cpp
inline CHaoYuDoc* CHaoYuView::GetDocument() {
    return ( CHaoYuDoc* ) m_pDocument;
}
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HAOYUVIEW_H__E4D9A193_D6EA_4172_B464_9AB965898F48__INCLUDED_)
