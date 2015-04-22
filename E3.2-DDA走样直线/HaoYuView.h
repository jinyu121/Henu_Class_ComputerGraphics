// HaoYuView.h : interface of the CHaoYuView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HAOYUVIEW_H__E4D9A193_D6EA_4172_B464_9AB965898F48__INCLUDED_)
#define AFX_HAOYUVIEW_H__E4D9A193_D6EA_4172_B464_9AB965898F48__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CHaoYuView : public CView
{
protected: // create from serialization only
	CHaoYuView();
	CPoint HY_STA,HY_FIN;
	DECLARE_DYNCREATE(CHaoYuView)

// Attributes
public:
	CHaoYuDoc* GetDocument();

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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
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

#endif // !defined(AFX_HAOYUVIEW_H__E4D9A193_D6EA_4172_B464_9AB965898F48__INCLUDED_)
