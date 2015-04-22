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
    this->HY_FIN = point;
    CDC *pDC = GetDC();

    if ( this->HY_STA.x > this->HY_FIN.x ) {
        CPoint t = this->HY_STA;
        this->HY_STA = this->HY_FIN;
        this->HY_FIN = t;
    }

    double x, y, k, tx, ty;
    int dx, dy, i, j, stax, stay, finx, finy, templow, temphigh;
    stax = this->HY_STA.x;
    stay = this->HY_STA.y;
    finx = this->HY_FIN.x;
    finy = this->HY_FIN.y;
    dx = this->HY_FIN.x - this->HY_STA.x;
    dy = this->HY_FIN.y - this->HY_STA.y;

    if ( ( dx == 0 ) || ( dy == 0 ) ) {
        if ( dx == 0 ) {
            templow = min ( stay, finy );
            temphigh = max ( stay, finy ) ;

            for ( y = templow; y < temphigh; y++ ) {
                pDC->SetPixelV ( stax, ( int ) y, RGB ( 0, 0, 0 ) );
            }

            return;
        }

        if ( dy == 0 ) {
            templow = min ( stax, finx );
            temphigh = max ( stax, finx ) ;

            for ( x = templow; x < temphigh; x++ ) {
                pDC->SetPixelV ( ( int ) x, stay, RGB ( 0, 0, 0 ) );
            }

            return;
        }
    } else {
        if ( abs ( dx ) > abs ( dy ) ) {
            k = ( double ) dy / ( double ) dx;
            ty = stay;

            for ( x = stax; x < finx; x = x + 1 ) {
                pDC->SetPixelV ( ( int ) x, ( int ) ty, RGB ( 0, 0, 0 ) );
                ty = ty + k;
            }

            return;
        } else {
            if ( dy > 0 ) {
                k = ( double ) dx / ( double ) dy;
                tx = stax;

                for ( y = stay; y < finy; y = y + 1 ) {
                    pDC->SetPixelV ( ( int ) tx, ( int ) y, RGB ( 0, 0, 0 ) );
                    tx = tx + k;
                }
            } else {
                k = ( double ) dx / ( double ) dy;
                tx = stax;

                for ( y = stay; y > finy; y = y - 1 ) {
                    pDC->SetPixelV ( ( int ) tx, ( int ) y, RGB ( 0, 0, 0 ) );
                    tx = tx + k;
                }
            }
        }
    }

    ReleaseDC ( pDC );
}
