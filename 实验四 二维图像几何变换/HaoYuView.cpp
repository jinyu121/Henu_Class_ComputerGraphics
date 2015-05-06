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
    ON_COMMAND ( ID_HY_CLR, OnHyClr )
    ON_COMMAND ( ID_HY_CUD, OnHyCud )
    ON_COMMAND ( ID_HY_DOWN, OnHyDown )
    ON_COMMAND ( ID_HY_LEFT, OnHyLeft )
    ON_COMMAND ( ID_HY_LR, OnHyLr )
    ON_COMMAND ( ID_HY_RIGHT, OnHyRight )
    ON_COMMAND ( ID_HY_SCALE_DOWN, OnHyScaleDown )
    ON_COMMAND ( ID_HY_SCALE_UP, OnHyScaleUp )
    ON_COMMAND ( ID_HY_UD, OnHyUd )
    ON_COMMAND ( ID_HY_UP, OnHyUp )
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
    this->p[0] = CPoint ( 50, 50 );
    this->p[1] = CPoint ( 50, -50 );
    this->p[2] = CPoint ( -50, -50 );
    this->p[3] = CPoint ( -50, 50 );
    this->scale = 3;
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
    ready ( pDC );
    pDC->MoveTo ( this->p[0] );
    pDC->LineTo ( this->p[1] );
    pDC->LineTo ( this->p[2] );
    pDC->LineTo ( this->p[3] );
    pDC->LineTo ( this->p[0] );
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

void CHaoYuView::reDraw() {
    CDC* pDC = GetDC();
    this->RedrawWindow();
    OnDraw ( pDC );
}

void CHaoYuView::ready ( CDC* pDC ) {
//定义矩形
    CRect rect;
//获得客户区矩形的大小
    GetClientRect ( &rect );
//自定义坐标系
    pDC->SetMapMode ( MM_ANISOTROPIC );
//设置窗口比例
    pDC->SetWindowExt ( rect.Width(), rect.Height() );
//设置视区比例，且x轴水平向右，y轴垂直向上
    pDC->SetViewportExt ( rect.Width(), -rect.Height() );
//设置客户区中心为坐标系原点
    pDC->SetViewportOrg ( rect.Width() / 2, rect.Height() / 2 );
//矩形与客户区重合
    rect.OffsetRect ( -rect.Width() / 2, -rect.Height() / 2 );
    // 画坐标轴
    pDC->MoveTo ( 0, 0 );
    pDC->LineTo ( 0, 200 );
    pDC->MoveTo ( 0, 0 );
    pDC->LineTo ( 200, 0 );
    pDC->MoveTo ( 0, 0 );
    pDC->LineTo ( 0, -200 );
    pDC->MoveTo ( 0, 0 );
    pDC->LineTo ( -200, 0 );
}


void CHaoYuView::OnHyUp() {
    for ( int i = 0; i < UPLIMIT; i++ ) {
        this->p[i].y += STEP;
    }

    reDraw();
}

void CHaoYuView::OnHyDown() {
    for ( int i = 0; i < UPLIMIT; i++ ) {
        this->p[i].y -= STEP;
    }

    reDraw();
}

void CHaoYuView::OnHyLeft() {
    for ( int i = 0; i < UPLIMIT; i++ ) {
        this->p[i].x -= STEP;
    }

    reDraw();
}

void CHaoYuView::OnHyRight() {
    for ( int i = 0; i < UPLIMIT; i++ ) {
        this->p[i].x += STEP;
    }

    reDraw();
}

void CHaoYuView::OnHyLr() {
    for ( int i = 0; i < UPLIMIT; i++ ) {
        this->p[i].x = - ( this->p[i].x );
    }

    reDraw();
}

void CHaoYuView::OnHyUd() {
    for ( int i = 0; i < UPLIMIT; i++ ) {
        this->p[i].y = - ( this->p[i].y );
    }

    reDraw();
}


void CHaoYuView::OnHyClr() {
    reDraw();
}

void CHaoYuView::OnHyCud() {
    reDraw();
}


void CHaoYuView::OnHyScaleDown() {
    if ( this->scale - 1 == 1 ) {
        return;
    }

    this->scale--;

    for ( int i = 0; i < UPLIMIT; i++ ) {
        this->p[i].x = ( this->p[i].x ) >> 1;
        this->p[i].y = ( this->p[i].y ) >> 1;
    }

    reDraw();
}

void CHaoYuView::OnHyScaleUp() {
    if ( this->scale + 1 == 5 ) {
        return;
    }

    this->scale++;

    for ( int i = 0; i < UPLIMIT; i++ ) {
        this->p[i].x = ( this->p[i].x ) << 1;
        this->p[i].y = ( this->p[i].y ) << 1;
    }

    reDraw();
}



