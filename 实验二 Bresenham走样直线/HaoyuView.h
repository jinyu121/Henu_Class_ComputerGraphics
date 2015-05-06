// HaoyuView.h : interface of the CHaoyuView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HAOYUVIEW_H__76E908A4_6D7D_4407_8E86_56B3B58CE8C8__INCLUDED_)
#define AFX_HAOYUVIEW_H__76E908A4_6D7D_4407_8E86_56B3B58CE8C8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CHaoyuView : public CView
{
protected: // create from serialization only
	CHaoyuView();
	DECLARE_DYNCREATE(CHaoyuView)
	CPoint STA,FIN;
// Attributes
public:
	CHaoyuDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHaoyuView)
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
	virtual ~CHaoyuView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHaoyuView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in HaoyuView.cpp
inline CHaoyuDoc* CHaoyuView::GetDocument()
   { return (CHaoyuDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HAOYUVIEW_H__76E908A4_6D7D_4407_8E86_56B3B58CE8C8__INCLUDED_)
