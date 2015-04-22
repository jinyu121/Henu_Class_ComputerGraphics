// HaoyuView.cpp : implementation of the CHaoyuView class
//

#include "stdafx.h"
#include "Haoyu.h"

#include "HaoyuDoc.h"
#include "HaoyuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHaoyuView

IMPLEMENT_DYNCREATE ( CHaoyuView, CView )

BEGIN_MESSAGE_MAP ( CHaoyuView, CView )
    //{{AFX_MSG_MAP(CHaoyuView)
    ON_WM_LBUTTONDOWN()
    ON_WM_LBUTTONUP()
    //}}AFX_MSG_MAP
    // Standard printing commands
    ON_COMMAND ( ID_FILE_PRINT, CView::OnFilePrint )
    ON_COMMAND ( ID_FILE_PRINT_DIRECT, CView::OnFilePrint )
    ON_COMMAND ( ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview )
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHaoyuView construction/destruction

CHaoyuView::CHaoyuView() {
    // TODO: add construction code here

}

CHaoyuView::~CHaoyuView() {
}

BOOL CHaoyuView::PreCreateWindow ( CREATESTRUCT& cs ) {
    // TODO: Modify the Window class or styles here by modifying
    //  the CREATESTRUCT cs

    return CView::PreCreateWindow ( cs );
}

/////////////////////////////////////////////////////////////////////////////
// CHaoyuView drawing

void CHaoyuView::OnDraw ( CDC* pDC ) {
    CHaoyuDoc* pDoc = GetDocument();
    ASSERT_VALID ( pDoc );
    // TODO: add draw code for native data here
	/*
    ////////// 通用准备工作 //////////
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
	*/
}

/////////////////////////////////////////////////////////////////////////////
// CHaoyuView printing

BOOL CHaoyuView::OnPreparePrinting ( CPrintInfo* pInfo ) {
    // default preparation
    return DoPreparePrinting ( pInfo );
}

void CHaoyuView::OnBeginPrinting ( CDC* /*pDC*/, CPrintInfo* /*pInfo*/ ) {
    // TODO: add extra initialization before printing
}

void CHaoyuView::OnEndPrinting ( CDC* /*pDC*/, CPrintInfo* /*pInfo*/ ) {
    // TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CHaoyuView diagnostics

#ifdef _DEBUG
void CHaoyuView::AssertValid() const {
    CView::AssertValid();
}

void CHaoyuView::Dump ( CDumpContext& dc ) const {
    CView::Dump ( dc );
}

CHaoyuDoc* CHaoyuView::GetDocument() { // non-debug version is inline
    ASSERT ( m_pDocument->IsKindOf ( RUNTIME_CLASS ( CHaoyuDoc ) ) );
    return ( CHaoyuDoc* ) m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHaoyuView message handlers

void CHaoyuView::OnLButtonDown ( UINT nFlags, CPoint point ) {
    // TODO: Add your message handler code here and/or call default

    CView::OnLButtonDown ( nFlags, point );
    this->FIN = point;
	CDC* pDC = GetDC();
	pDC->SetPixelV ( point, RGB ( 0, 0, 0 ) );

}

void CHaoyuView::OnLButtonUp ( UINT nFlags, CPoint point ) {
    // TODO: Add your message handler code here and/or call default

    CView::OnLButtonUp ( nFlags, point );
    this->STA = point;
    CDC* pDC = GetDC();

    int i, j;
    int tx, ty, tsta, tfin, dx, dy;
    double k = 0, d;
	double co=0,coDel=0;
    if ( this->STA.x > this->FIN.x ) {
        CPoint tpoint;
        tpoint = this->STA;
        this->STA = this->FIN;
        this->FIN = tpoint;
    }
    if ( ( this->STA.x == this->FIN.x ) || ( this->STA.y == this->FIN.y ) ) {
        if ( this->STA.x == this->FIN.x ) {
            tsta = min ( this->STA.y, this->FIN.y );
            tfin = max ( this->STA.y, this->FIN.y );
            tx = this->STA.x;
			coDel=1.0/(this->STA.y, this->FIN.y);
            for ( j = tsta; j < tfin; j++ ) {
                pDC->SetPixelV ( tx, j, RGB ( 255*co, 0, 255*(1-co) ) );
				co=co+coDel;
            }
        }

        if ( this->STA.y == this->FIN.y ) {
            tsta = this->STA.x;
            tfin = this->FIN.x;
            ty = this->STA.y;
			coDel=1.0/(this->STA.x, this->FIN.x);
            for ( i = tsta; i < tfin; i++ ) {
                pDC->SetPixelV ( i, ty, RGB ( 255*co, 0, 255*(1-co) ) );
				co=co+coDel;
            }
        }
    } else {
        dx = this->FIN.x - this->STA.x;
        dy = this->FIN.y - this->STA.y;
        k = ( double ) dy / ( double ) dx;

        if ( abs ( dx ) >= abs ( dy ) ) {
            tsta = this->STA.x;
            tfin = this->FIN.x;
            ty = this->STA.y;
			coDel=1.0/abs(dx);
            if ( dy >= 0 ) {
				d=0.5-k;
                for ( i = tsta; i < tfin; i++ ) {

                    pDC->SetPixelV ( i, ty, RGB (  255*co, 0, 255*(1-co)  ) );
					co=co+coDel;
                    if ( d < 0 ) {
                        ty++;
                        d = d + 1.0 - k;
                    } else {
                        d = d - k;
                    }
                }
            } else {
				d=-0.5-k;
                for ( i = tsta; i < tfin; i++ ) {
                    pDC->SetPixelV ( i, ty, RGB ( 255*co, 0, 255*(1-co) ) );
					co=co+coDel;
					if (d>0){
						ty--;
						d=d-1.0-k;
					}else{
						d=d-k;
					}
                }
            }
        } else {
			tsta = this->STA.y;
            tfin = this->FIN.y;
            tx = this->STA.x;
			coDel=1.0/abs(dy);
			if ( dy >= 0 ) {
				d=1-0.5*k;
                for ( i = tsta; i < tfin; i++ ) {

                    pDC->SetPixelV ( tx, i, RGB (255*co, 0, 255*(1-co) ) );
					co=co+coDel;
                    if ( d<0 ) {
                        d = d +1.0;
                    } else {
						d = d + 1.0-k;
						tx++;
                    }
                }
            } else {
				d=-1-0.5*k;
                for ( i = tsta; i > tfin; i-- ) {
                    pDC->SetPixelV ( tx, i, RGB (255*co, 0, 255*(1-co) ) );
					co=co+coDel;
					if (d>=0){
						d=d-1;
					}else{
						d=d-1-k;
						tx++;
					}
                }
            }
        }

    }

    ReleaseDC ( pDC );
}
