// HaoyuDoc.h : interface of the CHaoyuDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HAOYUDOC_H__C6789CFC_F45E_485E_A617_EF7FCEB4E1F6__INCLUDED_)
#define AFX_HAOYUDOC_H__C6789CFC_F45E_485E_A617_EF7FCEB4E1F6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CHaoyuDoc : public CDocument
{
protected: // create from serialization only
	CHaoyuDoc();
	DECLARE_DYNCREATE(CHaoyuDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHaoyuDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHaoyuDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHaoyuDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HAOYUDOC_H__C6789CFC_F45E_485E_A617_EF7FCEB4E1F6__INCLUDED_)
