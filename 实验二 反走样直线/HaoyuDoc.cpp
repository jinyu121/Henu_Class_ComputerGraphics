// HaoyuDoc.cpp : implementation of the CHaoyuDoc class
//

#include "stdafx.h"
#include "Haoyu.h"

#include "HaoyuDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHaoyuDoc

IMPLEMENT_DYNCREATE(CHaoyuDoc, CDocument)

BEGIN_MESSAGE_MAP(CHaoyuDoc, CDocument)
	//{{AFX_MSG_MAP(CHaoyuDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHaoyuDoc construction/destruction

CHaoyuDoc::CHaoyuDoc()
{
	// TODO: add one-time construction code here

}

CHaoyuDoc::~CHaoyuDoc()
{
}

BOOL CHaoyuDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CHaoyuDoc serialization

void CHaoyuDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CHaoyuDoc diagnostics

#ifdef _DEBUG
void CHaoyuDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHaoyuDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHaoyuDoc commands
