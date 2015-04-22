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
    GetClientRect ( &rect );
    pDC->SetMapMode ( MM_ANISOTROPIC );
    pDC->SetWindowExt ( rect.Width(), rect.Height() );
    pDC->SetViewportExt ( rect.Width(), -rect.Height() );
    pDC->SetViewportOrg ( rect.Width() / 2, rect.Height() / 2 );
    // 改变坐标系
    this->HY_STA.x = this->HY_STA.x - rect.Width() / 2;
    this->HY_STA.y = rect.Height() / 2 - this->HY_STA.y;
    //this->HY_FIN.x=this->HY_FIN.x-rect.Width()/2;
    //this->HY_FIN.y=rect.Height()/2-this->HY_FIN.y;
    double R1 = abs ( this->HY_STA.x );
    double R2 = abs ( this->HY_STA.y );

    if ( R1 == 0 || R2 == 0 ) {
        return;
    }

    int x = 0, y = ( int ) R2, i, j, k;
    double d;
    d = R2 * R2 + R1 * R1 * ( -R2 + 0.25 );

    while ( R2 * R2 * ( x + 1.0 ) < R1 * R1 * ( y - 0.5 ) ) {
        DrawPoint ( pDC, x, y, 0 );
        DrawPoint ( pDC, x, -y, 0 );
        DrawPoint ( pDC, -x, y, 0 );
        DrawPoint ( pDC, -x, -y, 0 );

        if ( d >= 0 ) {
            d = d + R2 * R2 * ( 2.0 * x + 3 ) + R1 * R1 * ( -2.0 * y + 2 );
            y--;
        } else {
            d = d + R2 * R2 * ( 2.0 * x + 3 );
        }

        x++;
    }

    d = R2 * R2 *  ( x + 0.5 )*( x + 0.5 ) + R1 * R1 * ( y - 1 )* ( y - 1 ) - R1 * R1 * R2 * R2;

    while ( y >= 0 ) {
        DrawPoint ( pDC, x, y, 0 );
        DrawPoint ( pDC, x, -y, 0 );
        DrawPoint ( pDC, -x, y, 0 );
        DrawPoint ( pDC, -x, -y, 0 );

        if ( d >= 0 ) {
            d = d + R1 * R1 * ( -2.0 * y + 3 );
        } else {
            d = d + 2 * R2 * R2 * ( x + 1.0 ) - R1 * R1 * ( 2.0 * y - 3 );
            x++;
        }

        y--;
    }

    ReleaseDC ( pDC );
}


void CHaoYuView::DrawPoint ( CDC* pDC, int x, int y, double gray ) {
    pDC->SetPixelV ( x, y, RGB ( 255 * gray, 255 * gray, 255 * gray ) );
}
