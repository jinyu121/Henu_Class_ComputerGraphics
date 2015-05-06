// HaoYuView.h : interface of the CHaoYuView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HAOYUVIEW_H__087FAA7A_6BE9_4F07_A1ED_6A8744359CED__INCLUDED_)
#define AFX_HAOYUVIEW_H__087FAA7A_6BE9_4F07_A1ED_6A8744359CED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CHaoYuView : public CView
{
protected: // create from serialization only
	CHaoYuView();
	DECLARE_DYNCREATE(CHaoYuView)

// Attributes
public:
	CHaoYuDoc* GetDocument();
	CPoint po[100];
	int n;

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
	void CHaoYuView::HYFill(CDC* pDC, int n, CPoint* p,COLORREF color);
	//{{AFX_MSG(CHaoYuView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
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

#endif // !defined(AFX_HAOYUVIEW_H__087FAA7A_6BE9_4F07_A1ED_6A8744359CED__INCLUDED_)
