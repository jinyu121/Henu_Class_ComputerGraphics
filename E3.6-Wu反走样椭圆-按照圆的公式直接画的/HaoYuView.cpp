// HaoYuView.cpp : implementation of the CHaoYuView class
//

#include "stdafx.h"
#include "HaoYu.h"

#include "HaoYuDoc.h"
#include "HaoYuView.h"
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHaoYuView

IMPLEMENT_DYNCREATE ( CHaoYuView, CView )

BEGIN_MESSAGE_MAP ( CHaoYuView, CView )
    //{{AFX_MSG_MAP(CHaoYuView)
    ON_WM_LBUTTONDOWN()
    ON_WM_LBUTTONUP()
    //}}AFX_MSG_MAP
    // Standard printing commands
    ON_COMMAND ( ID_FILE_PRINT, CView::OnFilePrint )
    ON_COMMAND ( ID_FILE_PRINT_DIRECT, CView::OnFilePrint )
    ON_COMMAND ( ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview )
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHaoYuView construction/destruction

CHaoYuView::CHaoYuView() {
    // TODO: add construction code here
}

CHaoYuView::~CHaoYuView() {
}

BOOL CHaoYuView::PreCreateWindow ( CREATESTRUCT& cs ) {
    // TODO: Modify the Window class or styles here by modifying
    //  the CREATESTRUCT cs
    return CView::PreCreateWindow ( cs );
}

/////////////////////////////////////////////////////////////////////////////
// CHaoYuView drawing

void CHaoYuView::OnDraw ( CDC* pDC ) {
    CHaoYuDoc* pDoc = GetDocument();
    ASSERT_VALID ( pDoc );
    // TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CHaoYuView printing

BOOL CHaoYuView::OnPreparePrinting ( CPrintInfo* pInfo ) {
    // default preparation
    return DoPreparePrinting ( pInfo );
}

void CHaoYuView::OnBeginPrinting ( CDC* /*pDC*/, CPrintInfo* /*pInfo*/ ) {
    // TODO: add extra initialization before printing
}

void CHaoYuView::OnEndPrinting ( CDC* /*pDC*/, CPrintInfo* /*pInfo*/ ) {
    // TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CHaoYuView diagnostics

#ifdef _DEBUG
void CHaoYuView::AssertValid() const {
    CView::AssertValid();
}

void CHaoYuView::Dump ( CDumpContext& dc ) const {
    CView::Dump ( dc );
}

CHaoYuDoc* CHaoYuView::GetDocument() { // non-debug version is inline
    ASSERT ( m_pDocument->IsKindOf ( RUNTIME_CLASS ( CHaoYuDoc ) ) );
    return ( CHaoYuDoc* ) m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHaoYuView message handlers

void CHaoYuView::OnLButtonDown ( UINT nFlags, CPoint point ) {
    // TODO: Add your message handler code here and/or call default
    CView::OnLButtonDown ( nFlags, point );
    this->HY_STA = point;
}

void CHaoYuView::OnLButtonUp ( UINT nFlags, CPoint point ) {
    // TODO: Add your message handler code here and/or call default
    CView::OnLButtonUp ( nFlags, point );
    //this->HY_FIN = point;
    CDC *pDC = GetDC();

	// 基础工作
	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(),rect.Height());
	pDC->SetViewportExt(rect.Width(),-rect.Height());
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);


	// 改变坐标系
	this->HY_STA.x=this->HY_STA.x-rect.Width()/2;
	this->HY_STA.y=rect.Height()/2-this->HY_STA.y;
	//pDC->SetPixelV(this->HY_STA,RGB(0,0,0));

	double R2=pow(this->HY_STA.x,2)+pow(this->HY_STA.y,2);
	double R=sqrt(R2);
	double d=0;
	int UpRange=(int)(R/sqrt(2))+1;

	int x=0,y=(int)(R+1.0);

	d=y-sqrt(R2-x*x);
	for(x=0;x<=UpRange;x++){
		DrawPoint(pDC,x,y,d);
		DrawPoint(pDC,x,y-1,1-d);

		DrawPoint(pDC,x,-y,d);
		DrawPoint(pDC,x,-(y-1),1-d);

		DrawPoint(pDC,-x,y,d);
		DrawPoint(pDC,-x,y-1,1-d);

		DrawPoint(pDC,-x,-y,d);
		DrawPoint(pDC,-x,-(y-1),1-d);

		DrawPoint(pDC,y,x,d);
		DrawPoint(pDC,y-1,x,1-d);

		DrawPoint(pDC,y,-x,d);
		DrawPoint(pDC,y-1,-x,1-d);

		DrawPoint(pDC,-y,x,d);
		DrawPoint(pDC,-(y-1),x,1-d);

		DrawPoint(pDC,-y,-x,d);
		DrawPoint(pDC,-(y-1),-x,1-d);

		d=y-sqrt(R2-x*x);
		if (d>=1){
			y--;
			d=y-sqrt(R2-x*x);
		}
	}


    ReleaseDC ( pDC );
}


void CHaoYuView::DrawPoint(CDC* pDC,int x,int y,double gray){
	pDC->SetPixelV(x,y,RGB(255*gray,255*gray,255*gray));
}