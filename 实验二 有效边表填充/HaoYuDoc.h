// HaoYuDoc.h : interface of the CHaoYuDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HAOYUDOC_H__3A377292_A0FC_43E4_817D_575D38407621__INCLUDED_)
#define AFX_HAOYUDOC_H__3A377292_A0FC_43E4_817D_575D38407621__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CHaoYuDoc : public CDocument
{
protected: // create from serialization only
	CHaoYuDoc();
	DECLARE_DYNCREATE(CHaoYuDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHaoYuDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHaoYuDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHaoYuDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HAOYUDOC_H__3A377292_A0FC_43E4_817D_575D38407621__INCLUDED_)
