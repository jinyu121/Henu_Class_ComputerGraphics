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
	ON_WM_RBUTTONDOWN()
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
    pDC->TextOut(50,50,"左键画线右键裁剪");
	//定义矩形
	CRect rect;         
	//获得客户区矩形的大小
	GetClientRect(&rect); 
	this->HY_X_L=(int)(rect.Width()*0.3);
	this->HY_X_R=(int)(rect.Width()*0.7);
	this->HY_Y_U=(int)(rect.Height()*0.3);
	this->HY_Y_D=(int)(rect.Height()*0.7);
	pDC->MoveTo(this->HY_X_L,this->HY_Y_U);
	pDC->LineTo(this->HY_X_L,this->HY_Y_D);
	pDC->LineTo(this->HY_X_R,this->HY_Y_D);
	pDC->LineTo(this->HY_X_R,this->HY_Y_U);
	pDC->LineTo(this->HY_X_L,this->HY_Y_U);
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
	this->RedrawWindow();
    this->HY_STA = point;
}

void CHaoYuView::OnLButtonUp ( UINT nFlags, CPoint point ) {
    // TODO: Add your message handler code here and/or call default
    CView::OnLButtonUp ( nFlags, point );
    this->HY_FIN = point;
	CDC *pDC=GetDC();
	pDC->MoveTo(this->HY_STA);
	pDC->LineTo(this->HY_FIN);
}

void CHaoYuView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	CView ::OnRButtonDown(nFlags, point);
	CDC* pDC=GetDC();

	this->RedrawWindow();
	int deltaX,deltaY;
	double tmin,tmax,x0,y0,x1,y1;
	tmin=1;
	tmax=0;
	x0=this->HY_STA.x;
	y0=this->HY_STA.y;
	x1=this->HY_FIN.x;
	y1=this->HY_FIN.y;
	deltaX=(int)(x1-x0);
	deltaY=(int)(y1-y0);
	double u[4]={-deltaX,deltaX,-deltaY,deltaY};
	double v[4]={x0-this->HY_X_L,this->HY_X_R-x0,y0-this->HY_Y_U,this->HY_Y_D-y0};

	for(int i=0;i<4;i++){
		if (u[i]<0){
			tmax=max(tmax,v[i]/u[i]);
		}else{
			tmin=min(tmin,v[i]/u[i]);
		}
	}
	if (tmax>tmin){
		this->HY_STA=CPoint(0,0);
		this->HY_FIN=CPoint(0,0);
		pDC->TextOut(100,100,"Sorry,Nothing to show");
	}else{
		this->HY_STA=CPoint((int)(x0+tmin*deltaX+0.5),(int)(y0+tmin*deltaY+0.5));
		this->HY_FIN=CPoint((int)(x0+tmax*deltaX+0.5),(int)(y0+tmax*deltaY+0.5));
		pDC->MoveTo(this->HY_STA);
		pDC->LineTo(this->HY_FIN);
	}
}
