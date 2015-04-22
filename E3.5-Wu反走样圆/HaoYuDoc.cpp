// HaoYuDoc.cpp : implementation of the CHaoYuDoc class
//

#include "stdafx.h"
#include "HaoYu.h"

#include "HaoYuDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHaoYuDoc

IMPLEMENT_DYNCREATE(CHaoYuDoc, CDocument)

BEGIN_MESSAGE_MAP(CHaoYuDoc, CDocument)
	//{{AFX_MSG_MAP(CHaoYuDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHaoYuDoc construction/destruction

CHaoYuDoc::CHaoYuDoc()
{
	// TODO: add one-time construction code here

}

CHaoYuDoc::~CHaoYuDoc()
{
}

BOOL CHaoYuDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CHaoYuDoc serialization

void CHaoYuDoc::Serialize(CArchive& ar)
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
// CHaoYuDoc diagnostics

#ifdef _DEBUG
void CHaoYuDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHaoYuDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHaoYuDoc commands
