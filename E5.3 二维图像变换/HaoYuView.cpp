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
	ON_WM_TIMER()
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
	this->points[0][0]=AA;
	this->points[0][1]=-BB+AA;
	this->points[0][2]=1;
	this->points[1][0]=AA;
	this->points[1][1]=-BB-AA;
	this->points[1][2]=1;
	this->points[2][0]=-AA;
	this->points[2][1]=-BB-AA;
	this->points[2][2]=1;
	this->points[3][0]=-AA;
	this->points[3][1]=-BB+AA;
	this->points[3][2]=1;
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
	CRect rect;         
	//获得客户区矩形的大小
	GetClientRect(&rect);                      
	//自定义坐标系
	pDC->SetMapMode(MM_ANISOTROPIC);                    
	//设置窗口比例
	pDC->SetWindowExt(rect.Width(),rect.Height());      
	//设置视区比例，且x轴水平向右，y轴垂直向上
	pDC->SetViewportExt(rect.Width(),-rect.Height());   
	//设置客户区中心为坐标系原点
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);
	//矩形与客户区重合
	rect.OffsetRect(-rect.Width()/2,-rect.Height()/2);  
	pDC->TextOut(50,50,"左键开始右键停止");
	// 坐标轴
	pDC->MoveTo(-BB,0);
	pDC->LineTo(BB,0);
	pDC->MoveTo(0,0);
	pDC->LineTo(0,-BB);
	// 画矩形
	pDC->MoveTo((int)(this->points[0][0]+0.5),(int)(this->points[0][1]+0.5));
	pDC->LineTo((int)(this->points[1][0]+0.5),(int)(this->points[1][1]+0.5));
	pDC->LineTo((int)(this->points[2][0]+0.5),(int)(this->points[2][1]+0.5));
	pDC->LineTo((int)(this->points[3][0]+0.5),(int)(this->points[3][1]+0.5));
	pDC->LineTo((int)(this->points[0][0]+0.5),(int)(this->points[0][1]+0.5));
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


void CHaoYuView::ImageRotate(){
	int i,j,k;
	double p[4][3]={	{0,0,0},
						{0,0,0},
						{0,0,0}
					};

	double t[3][3]={	{cos(angle),	sin(angle),		0},
						{-sin(angle),	cos(angle),		0},
						{-BB*sin(angle),BB*(cos(angle)-1),1}
					};
	
	for(i=0;i<4;i++){
		for(j=0;j<3;j++){
			for(k=0;k<3;k++){
				p[i][j]+=(this->points[i][k] * t[k][j]);
			}
		}
	}
	
	for(i=0;i<4;i++){
		for(j=0;j<2;j++){
			this->points[i][j]=p[i][j];
		}
	}
	
}

void CHaoYuView::OnTimer(UINT nIDEvent) 
{
	ImageRotate();
	CDC* pDC=GetDC();
	this->RedrawWindow();
	OnDraw(pDC);
	ReleaseDC ( pDC );
	CView ::OnTimer(nIDEvent);
}

void CHaoYuView::OnLButtonDown ( UINT nFlags, CPoint point ) {
    // TODO: Add your message handler code here and/or call default
    CView::OnLButtonDown ( nFlags, point );
	SetTimer(1,5,NULL);
}

void CHaoYuView::OnLButtonUp ( UINT nFlags, CPoint point ) {
    // TODO: Add your message handler code here and/or call default
    CView::OnLButtonUp ( nFlags, point );
}

void CHaoYuView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	KillTimer(1);
	
	CView ::OnRButtonDown(nFlags, point);
}
