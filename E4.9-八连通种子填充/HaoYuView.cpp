// HaoYuView.cpp : implementation of the CHaoYuView class
//

#include "stdafx.h"
#include "HaoYu.h"

#include "HaoYuDoc.h"
#include "HaoYuView.h"
#include <queue>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHaoYuView

IMPLEMENT_DYNCREATE(CHaoYuView, CView)

BEGIN_MESSAGE_MAP(CHaoYuView, CView)
	//{{AFX_MSG_MAP(CHaoYuView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHaoYuView construction/destruction

CHaoYuView::CHaoYuView()
{
	// TODO: add construction code here

}

CHaoYuView::~CHaoYuView()
{
}

BOOL CHaoYuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CHaoYuView drawing

void CHaoYuView::OnDraw(CDC* pDC)
{
	CHaoYuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	pDC->MoveTo(100,100);
	pDC->LineTo(100,200);
	pDC->LineTo(200,200);
	pDC->LineTo(200,100);
	pDC->LineTo(100,100);

	pDC->MoveTo(201,201);
	pDC->LineTo(201,301);
	pDC->LineTo(301,301);
	pDC->LineTo(301,201);
	pDC->LineTo(201,201);

	HYFill(pDC,150,150);
	HYFill(pDC,250,250);
}

void CHaoYuView::HYFill(CDC* pDC,int x,int y){
	int i;
	int xx[]={0,1,1,1,0,-1,-1,-1};
	int yy[]={-1,-1,0,1,1,1,0,-1};
	std::queue<CPoint> q;
	q.push(CPoint(x,y));
	while(!q.empty()){
		CPoint tHead=q.front();
		q.pop();
		for(i=0;i<8;i++){
			CPoint tp=CPoint(tHead.x+xx[i],tHead.y+yy[i]);
			COLORREF c=pDC->GetPixel(tp);
			int r=GetRValue(c);
			int g=GetGValue(c);
			int b=GetBValue(c);
			if (!(r==0 && g==0 && b==0) && !(r==0 && g==255 && b==0)){
				pDC->SetPixelV(tp,RGB(0,255,0));
				q.push(tp);
			}
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CHaoYuView printing

BOOL CHaoYuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CHaoYuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CHaoYuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CHaoYuView diagnostics

#ifdef _DEBUG
void CHaoYuView::AssertValid() const
{
	CView::AssertValid();
}

void CHaoYuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHaoYuDoc* CHaoYuView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHaoYuDoc)));
	return (CHaoYuDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHaoYuView message handlers
